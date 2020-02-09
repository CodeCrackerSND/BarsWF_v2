#pragma once

//#define BROOK


#include "../algo.h"
#include "md5.h"


#include <math.h>
#include <assert.h>
#include "../../md5_simple.h"
#include <iostream>
#include "../../perm.h"
#include <conio.h>
#include "../../sse2_helpers.h"

#ifdef BROOK
#include "md5_pp.h"
#endif

#ifdef CUDA
#include "md5_kernel.h"
#endif

#define getGPU g->gpu[data->device_id]

class algo_md5 : public algo
{
public:
	//key generation is default

	void init_sse2_once(thread_data *data)
	{
		set32(CONST_MAX128, -1);
		set32(sse2_nodata, 0);
		set32(gpu_mask_2_128, 0xffff0000);

		//sse2_lendata
		for(int i=0;i<64;i++)
		{
			int tmp = (int)(__int64)floorl(fabsl(sinl(i + 1))*(powl(2.0,32)));
			set32(md5_const_sse2[i],tmp);
		}
	};

#ifdef BROOK
	//we need to do init when we know number of keys per thread
	void init_brook(thread_data *data)
	{
		g->log->information("Init BROOK thread #"+i2a(data->gpu.device_id));

		unsigned int md5_dim[] = {data->gpu.keys_per_thread};
		unsigned int charset_dim[] = {perm::charset_len};
		int charset_h[256];
		
		for(int i=0;i<perm::charset_len;i++)
			charset_h[i] = perm::charset[i];//converting to int for brook


		for(int i=0;i<20;i++)
		{
			data->stream_buffer[i] = new int[data->gpu.keys_per_thread];
			data->streams[i] = new ::brook::Stream<int>(1,md5_dim);
		}

		data->output = new ::brook::Stream<int>(1,md5_dim);
		data->charset = new ::brook::Stream<int>(1,charset_dim);
		data->charset->read(charset_h);

		data->gpu.data_h = new unsigned int [4*5*data->gpu.keys_per_thread];
		data->gpu.result = new int[4*data->gpu.keys_per_thread];
	};

	void done_brook(thread_data *data)
	{
		for(int i=0;i<20;i++)
		{
			delete data->stream_buffer[i];
			delete data->streams[i];
		}
		delete data->output;
		delete data->charset;

		delete[] data->gpu.data_h;
		delete[] data->gpu.result;
	}
#endif
#ifdef CUDA
	//This is called right after thread creation
	void init_cuda_once(thread_data *data)
	{
		g->log->information("Init CUDA thread #"+i2a(data->gpu.device_id));
		//do common part
		cudaSetDevice(data->gpu.device_id);
		cudaDeviceReset();  // reset is needed for avoiding above error
		cudaSetDeviceFlags(cudaDeviceBlockingSync);  // this one fails
		
		CCU();  // with +		msg	0x0307f908 "CUDA kernel error: cannot set while device is active in this process"	char [512]
		
		//get Number of SP and other info
		cudaDeviceProp deviceProp;
		cudaGetDeviceProperties(&deviceProp, data->gpu.device_id);
		CCU();

		if(!data->gpu.is_speed_detected)
		{
			data->gpu.grid_n = deviceProp.multiProcessorCount;
			data->gpu.thread_n = min(deviceProp.maxThreadsPerBlock, ((deviceProp.regsPerBlock/32) & 0xfffffff0));

			if(g->grid_n>0) data->gpu.grid_n=g->grid_n;
			if(g->thread_n>0) data->gpu.thread_n=g->thread_n;
		}
		//init host part
//		data->data_h = new unsigned int [4*5*data->gpu.keys_per_thread];

/*		unsigned int md5_dim[] = {data->gpu.keys_per_thread};
		unsigned int charset_dim[] = {perm::charset_len};
		int charset_h[256];
		
		for(int i=0;i<perm::charset_len;i++)
			charset_h[i] = perm::charset[i];//converting to int for brook

		//get memory for data transfers
		cudaMalloc((void **) &data->data_d, sizeof(int)*4*data->thread_n*data->grid_n);
		cudaMalloc((void **) &data->common_d, sizeof(md5_data));   

		//store common data
		cudaMemcpyToSymbol(data->target, g->hash_i, sizeof(g->hash_i));
		data->common_h->res[0] = -1;//key not found
		cudaMemcpyToSymbol(charset_c, perm::charset, perm::charset_len+1);*/
	}

	//we need to do init when we know number of keys per thread
	void init_cuda(thread_data *data)
	{
		cuda_get_mem(&(data->gpu));
		init_md5_cuda(&(data->gpu), g->hash_i, perm::charset, perm::charset_len);
	};

	void done_cuda(thread_data *data)
	{
		cuda_free_mem(&data->gpu);
	}

	//short speed benchmark for brook
	void detect_keys_cuda(thread_data *data)
	{
		if(data->gpu.is_speed_detected==1)return;
		data->gpu.is_speed_detected++;

		g->log->information("Detecting CUDA performance for GPU#"+i2a(data->gpu.device_id));
		run_cuda(data, true);//benchmark
		double start = ELAPSED;
		run_cuda(data, true);//benchmark

		double time_spent = (ELAPSED-start)*1000.0;//milliseconds
		g->log->information("GPU#" + i2a(data->gpu.device_id) + " Time spent: " + f2a(time_spent));
		
		int multiplicator = (int)(g->gpu_time/(time_spent));
		if(multiplicator==0)multiplicator = 1;
		
		int new_keys = data->gpu.grid_n*multiplicator;
		if(new_keys>1024)
			data->gpu.grid_n = 1024;else
			data->gpu.grid_n = new_keys;
		
		/////////////////

		
		data->avg->keys_per_block = data->gpu.grid_n*data->gpu.thread_n*perm::charset_len*perm::charset_len/1000000.0;//millions
		data->avg->reset();

		g->log->information("GPU#" + i2a(data->gpu.device_id) + " New amount of work per kernel: " + i2a(data->gpu.grid_n) + " : " + i2a(data->gpu.thread_n));
		//and finally, initialize brook
		if(data->gpu.is_speed_detected==1)//second detect needed to more precise speed test
			detect_keys_cuda(data);
	}

	void run_cuda(thread_data *data, bool is_benchmark = false)//TODO move loop code to algo
	{
		detect_keys_cuda(data);
		init_cuda(data);//init it here

		//detect_keys_brook(data);

	
		while(!g->is_finished || is_benchmark)
		{
			perm::lock();//enter critical section
			perm::gen(data->gpu.data_h, data->gpu.thread_n*data->gpu.grid_n);
			perm::unlock();//done

			//memset(data->result, 0, 4*data->gpu.keys_per_thread);
			int error = do_123(&data->gpu, perm::pwd_len, perm::charset_len);
			if(error)
			{
				g->is_finished = true;
				g->is_error_detected = true;
				break;
			}


			//check keys
			((algo_md5*)(g->a))->check_result(data->gpu.data_h, data->gpu.result, data->gpu.thread_n*data->gpu.grid_n);

			data->avg->push();//update timing
			perm::update_keys_done(data->gpu.thread_n*data->gpu.grid_n);//update progress
			if(is_benchmark)break;
		}

		done_cuda(data);
	}
#endif


	algo_md5()
	{
		dword_per_key=4;//15 chars max, not including last 0x80
		//everything else is default
	}

	void init_len(int len)
	{
		//unroll last addition
		g->hash_i[0]=g->hash_ref[0]-0x67452301;
		g->hash_i[1]=g->hash_ref[1]-0xefcdab89;
		g->hash_i[2]=g->hash_ref[2]-0x98badcfe;
		g->hash_i[3]=g->hash_ref[3]-0x10325476;
		//unroll step 64
		unrollII (g->hash_i[1], g->hash_i[2], g->hash_i[3], g->hash_i[0], 0, S44, 0xeb86d391); /* 64 */
#ifdef CPU
		//sse2
		set32(sse2_lendata, len*8);
		for(int i=0;i<4;i++)
		{
			set32(target_sse[i], g->hash_i[i]);



		}
#endif
	}

	void check_result(unsigned int *data, int *result, int num_of_packets)
	{

		for(int q=0;q<num_of_packets;q++)
			if(result[q]==KEY_FOUND)
			{
				for(int b1=0;b1<perm::charset_len;b1++)
					for(int b2=0;b2<perm::charset_len;b2++)
					{
						md5_simple(perm::charset[b1]+(perm::charset[b2]<<8)+(data[q*4+0]&((-1)^65535)),data[q*4+1],data[q*4+2],data[q*4+3],perm::pwd_len8);
					}
			} else
				if(result[q]!=KEY_NOT_FOUND)
				{
					g->is_finished = true;
					g->is_corrupted = true;
					break;
				}
	};

#ifdef BROOK
	void check_result_brook(unsigned int *data, int *result, int num_of_packets)
	{
		for(int q=0;q<num_of_packets;q++)
			if(result[q]==KEY_FOUND)
			{
				for(int w=0;w<5;w++)//check for 5 threads
				for(int b1=0;b1<perm::charset_len;b1++)
					for(int b2=0;b2<perm::charset_len;b2++)
					{
						md5_simple(perm::charset[b1]+(perm::charset[b2]<<8)+(data[(q*5+w)*4+0]&((-1)^65535)),data[(q*5+w)*4+1],data[(q*5+w)*4+2],data[(q*5+w)*4+3],perm::pwd_len8);
					}
			} else
				if(result[q]!=KEY_NOT_FOUND)
				{
					g->is_finished = true;
					g->is_corrupted = true;
					break;
				}
	};

	//short speed benchmark for brook
	void detect_keys_brook(thread_data *data)
	{
		if(data->gpu.is_speed_detected==3)return;
		data->gpu.is_speed_detected++;

		g->log->information("Detecting Brook performance...");
		thread_count_inc();//Well, actually that's fake one
		run_brook(data, true);//benchmark
		double start = ELAPSED;
		thread_count_inc();//Well, actually that's fake one
		run_brook(data, true);//benchmark

		double time_spent = (ELAPSED-start)*1000.0;//milliseconds
		g->log->information("Time spent: " + f2a(time_spent));
		double multiplicator = (g->gpu_time/(time_spent));
		
		double new_keys = data->gpu.keys_per_thread*multiplicator;
		if(new_keys>2000000000.0)
			data->gpu.keys_per_thread = 2000000000;else
			data->gpu.keys_per_thread = new_keys;
		
		if(data->gpu.keys_per_thread<160)data->gpu.keys_per_thread = 160;
		if(data->gpu.keys_per_thread>800*200)data->gpu.keys_per_thread = 800*200;
		
		data->gpu.keys_per_thread = 800*2; //test
		
		data->gpu.keys_per_thread = (data->gpu.keys_per_thread/160)*160;
		data->avg->keys_per_block = (data->gpu.keys_per_thread*5.0)*perm::charset_len*perm::charset_len/1000000.0;//millions
		data->avg->reset();

		g->log->information("New amount of work per kernel: " + i2a(data->gpu.keys_per_thread));
		//and finally, initialize brook
		done_brook(data);//free memory for structures of old size
		init_brook(data);
		if(data->gpu.is_speed_detected==1 || data->gpu.is_speed_detected==2)//second detect needed to more precise speed test
			detect_keys_brook(data);
	}

	void run_brook(thread_data *data, bool is_benchmark = false)//TODO move loop code to algo
	{
		g->log->information("Run BROOK thread #"+i2a(data->gpu.device_id));
		detect_keys_brook(data);

	
		while(!g->is_finished || is_benchmark)
		{
			perm::lock();//enter critical section
			perm::gen(data->gpu.data_h, 1/*data->gpu.keys_per_thread*5*/);
			perm::unlock();//done
/*			for(int i=0;i<data->gpu.keys_per_thread;i++)
				for(int thread=0;thread<5;thread++)
					for(int q=0;q<4;q++)
						data->stream_buffer[thread*4+q][i] = data->data_h[(i*5+thread)*4+q];

			for(int thread=0;thread<5;thread++)
				for(int q=0;q<4;q++)
					data->streams[thread*4+q]->read(data->stream_buffer[thread*4+q]);*/
			
			//pass first key only

			memset(data->gpu.result, 0, 4*data->gpu.keys_per_thread);
			//brook stuff here
	
			hello_brook_check(data->gpu.data_h[0], data->gpu.data_h[1],data->gpu.data_h[2],data->gpu.data_h[3],
							/*data->streams[4][0],data->streams[5][0],data->streams[6][0],data->streams[7][0],
							  data->streams[0][0],data->streams[1][0],data->streams[2][0],data->streams[3][0],
							  data->streams[8][0],data->streams[9][0],data->streams[10][0],data->streams[11][0],
							  data->streams[12][0],data->streams[13][0],data->streams[14][0],data->streams[15][0],
							  data->streams[16][0],data->streams[17][0],data->streams[18][0],data->streams[19][0],*/
							  perm::pwd_len8,
							  g->hash_i[0],g->hash_i[1],g->hash_i[2],g->hash_i[3],
							  data->charset[0], perm::charset_len,
							  data->output[0]);

			data->output->write(data->gpu.result);//, "async"
/*			while(!data->output->isSync())
			{
				Sleep(1);
			}*/
			//check keys
			((algo_md5*)(g->a))->check_result_brook(data->gpu.data_h, data->gpu.result, data->gpu.keys_per_thread);

			data->avg->push();//update timing
			perm::update_keys_done(data->gpu.keys_per_thread*5);//update progress
			if(is_benchmark)break;
		}

		thread_count_dec();
		g->log->information("Stop BROOK thread #"+i2a(data->gpu.device_id));
	}
#endif

#include "md5_sse2.inc"
};