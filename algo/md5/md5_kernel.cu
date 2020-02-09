#include <stdio.h>
//we obviously using CUDA :-D
#define CUDA

//#define DebugValues  // if debug values print values!

#include <cuda.h>
#include "md5_kernel.h"
#include "md5.h"
#include <stdio.h>
#include "cuPrintf.cu"

//__constant__
//__device__ __constant__ unsigned int charset_c[256];// = {0xb182b498, 0xf4d2ac41, 0x1f636569, 0xaf4caf00};
//__device__ __constant__ unsigned int target_hash[4];// = {0xb182b498, 0xf4d2ac41, 0x1f636569, 0xaf4caf00};

 __shared__ unsigned int charset_c[256];
 __shared__ unsigned int target_hash[4];

void CCU2()
{
	cudaError_t result = cudaGetLastError();
	if(result != cudaSuccess)
	{
		char msg[512];msg[0]=0;
		strcpy_s(msg, 512, "CUDA kernel error: ");
		strcat_s(msg, 512, cudaGetErrorString(result));
		printf(msg);
		return;
	}
}

extern "C" void cuda_get_mem(gpu_data_xyz* data)
{
	//get memory for data transfers

	// Alocate only once
	//cudaMalloc( (void**)&charset_c, 256*sizeof(unsigned int));
	//cudaMalloc( (void**)&target_hash, 4*sizeof(unsigned int));
	//CCU2();

//	cudaMalloc    ((void **) &target_hash , sizeof(int)*4);
	//CCU2();
	cudaMalloc    ((void **) &data->data_d      , sizeof(int)*4*data->thread_n*data->grid_n);
	CCU2();
	cudaMallocHost((void **) &data->data_h, sizeof(int)*4*data->thread_n*data->grid_n);
	CCU2();

	cudaMalloc    ((void **) &data->result_d    , sizeof(int)*data->thread_n*data->grid_n);   
	CCU2();
	cudaMallocHost((void **) &data->result, sizeof(int)*data->thread_n*data->grid_n);
	CCU2();
}

__global__ void initShared(int* hash_i, unsigned char *charset, int charset_len)
{

    int tid = blockDim.x * blockIdx.x + threadIdx.x;

    // load to shared memory array
    // assumes Mystruct has correct copy assignment semantics
    //d_s[threadIdx.x] = theStructArray[tid]

	for(int i=0;i<charset_len;i++)
		charset_c[threadIdx.x+i] = charset[tid+i];

	for(int i=0;i<4;i++)
		target_hash[threadIdx.x+i] = hash_i[tid+i];

    __syncthreads();

    // Each thread has now loaded one value to the block scoped shared value
}


extern "C" void init_md5_cuda(gpu_data_xyz* data, int* hash_i, unsigned char *charset, int charset_len)
{

	initShared<<<data->grid_n, 1>>>(hash_i, charset, charset_len);

    //cudaMemcpy( cuda_x, &x, sizeof( float ), cudaMemcpyHostToDevice );

	//int charset_int[256];
	//memset(charset_int, 0, sizeof(charset_int));
	//for(int i=0;i<charset_len;i++)
	//	charset_int[i] = charset[i];
/*
	for(int i=0;i<4;i++)
		charset_int[100+i] = hash_i[i];*/
	
	memset(data->result, 0, sizeof(int)*data->thread_n*data->grid_n);
	cudaMemcpy(data->result_d, data->result, sizeof(int)*data->thread_n*data->grid_n, cudaMemcpyHostToDevice);
	CCU2();
	
	//cudaMemcpy( charset_c, &charset_int, sizeof(unsigned int)*charset_len, cudaMemcpyHostToDevice );

	//cudaMemcpyToSymbol(charset_c, &charset_int, sizeof(unsigned int)*charset_len);
	//cudaMemcpyToSymbol("charset_c", charset_int, sizeof(int)*charset_len);//
	//CCU2();

	//cudaMemcpyToSymbol(target_hash, &hash_i, sizeof(int)*4);
	//cudaMemcpy(target_hash, hash_i, sizeof(unsigned int)*4, cudaMemcpyHostToDevice);
	//CCU2();
	//	cudaMemcpyToSymbol(md5_const, md5_const_host, sizeof(md5_const));
}

extern "C" void cuda_free_mem(gpu_data_xyz* data)
{
	//cudaFree(target_hash);  
	cudaFree(data->data_d);  
	cudaFree(data->result_d);  

	cudaFreeHost(data->data_h); 
	cudaFreeHost(data->result); 
}

__global__ void md5_gpu_bruteforce_thread(unsigned int *data_d, unsigned int *result_d, unsigned int pwd_len, int charset_len)
{

	const int ix = blockDim.x * blockIdx.x + threadIdx.x;
	//unsigned int data[4];
	unsigned int data0, data1, data2, data3;
	int a,b,c,d;
	const int len = pwd_len*8;//code_len[0];//
	int ta,tb,tc,td;

	data0=data_d[ix*4+0];
	data1=data_d[ix*4+1];
	data2=data_d[ix*4+2];
	data3=data_d[ix*4+3];

	//for(int i=0;i<4;i++)data[i]=data_d[ix*4+i];//
	//		if(s3_limit==26)data[0]=(data[0]&0xff00ffff)+(('a'+s3)<<16);//only if 3 symbols to brute force
		
	int res = KEY_NOT_FOUND;
	ta = target_hash[0];
	tb = target_hash[1];
	tc = target_hash[2];
	td = target_hash[3];



	// Unroll known steps:
	unrollII (tc, td, ta, tb, data2, S43, 0x2ad7d2bb); /* 63 */
	unrollII (td, ta, tb, tc, 0, S42, 0xbd3af235); /* 62 */
	unrollII (ta, tb, tc, td, 0, S41, 0xf7537e82); /* 61 */
	unrollII (tb, tc, td, ta, 0, S44, 0x4e0811a1); /* 60 */
	unrollII (tc, td, ta, tb, 0, S43, 0xa3014314); /* 59 */
	unrollII (td, ta, tb, tc, 0, S42, 0xfe2ce6e0); /* 58 */
	unrollII (ta, tb, tc, td, 0, S41, 0x6fa87e4f); /* 57 */
	unrollII (tb, tc, td, ta, data1, S44, 0x85845dd1); /* 56 */
	unrollII (tc, td, ta, tb, 0, S43, 0xffeff47d); /* 55 */
	unrollII (td, ta, tb, tc, data3, S42, 0x8f0ccc92); /* 54 */
	unrollII (ta, tb, tc, td, 0, S41, 0x655b59c3); /* 53 */
	unrollII (tb, tc, td, ta, 0, S44, 0xfc93a039); /* 52 */
	unrollII (tc, td, ta, tb, len, S43, 0xab9423a7); /* 51 */
	unrollII (td, ta, tb, tc, 0, S42, 0x432aff97); /* 50 */

	for(int s2=0;s2<charset_len;s2++)
	{
		data0=(data0&0xffff00ff)+((charset_c[s2])<<8);

		for(int s1=0;s1<charset_len;s1++)
		{
			data0=(data0&0xffffff00)+(charset_c[s1]);

			a=0x67452301;b=0xefcdab89;c=0x98badcfe;d=0x10325476;

			/* Round 1 */

			FF2_first (a, b, c, d, data0, S11, 0xd76aa478,0,0); /* 1 */
			FF2 (d, a, b, c, data1, S12, 0xe8c7b756,1,1); /* 2 */
			FF2 (c, d, a, b, data2, S13, 0x242070db,2,2); /* 3 */
			FF2 (b, c, d, a, data3, S14, 0xc1bdceee,3,3); /* 4 */


			FF2_NoData (a, b, c, d, 0, S11, 0xf57c0faf,4,15); /* 5 */ //5th and so forth is 0
			FF2_NoData (d, a, b, c, 0, S12, 0x4787c62a,5,15); /* 6 */
			FF2_NoData (c, d, a, b, 0, S13, 0xa8304613,6,15); /* 7 */
			FF2_NoData (b, c, d, a, 0, S14, 0xfd469501,7,15); /* 8 */
			FF2_NoData (a, b, c, d, 0, S11, 0x698098d8,8,15); /* 9 */
			FF2_NoData (d, a, b, c, 0, S12, 0x8b44f7af,9,15); /* 10 */
			FF2_NoData (c, d, a, b, 0, S13, 0xffff5bb1,10,15); /* 11 */
			FF2_NoData (b, c, d, a, 0, S14, 0x895cd7be,11,15); /* 12 */
			FF2_NoData (a, b, c, d, 0, S11, 0x6b901122,12,15); /* 13 */
			FF2_NoData (d, a, b, c, 0, S12, 0xfd987193,13,15); /* 14 */
			FF2 (c, d, a, b, len, S13, 0xa679438e,14,14); /* 15 */
			FF2_NoData (b, c, d, a, 0, S14, 0x49b40821,15,15); /* 16 */

			/* Round 2 */
			GG2 (a, b, c, d, data1, S21, 0xf61e2562,16,1); /* 17 */
			GG2_NoData (d, a, b, c, 0, S22, 0xc040b340,17,15); /* 18 */
			GG2_NoData (c, d, a, b, 0, S23, 0x265e5a51,18,15); /* 19 */
			GG2 (b, c, d, a, data0, S24, 0xe9b6c7aa,19,0); /* 20 */
			GG2_NoData (a, b, c, d, 0, S21, 0xd62f105d,20,15); /* 21 */
			GG2_NoData (d, a, b, c, 0, S22,  0x2441453,21,15); /* 22 */
			GG2_NoData (c, d, a, b, 0, S23, 0xd8a1e681,22,15); /* 23 */
			GG2_NoData (b, c, d, a, 0, S24, 0xe7d3fbc8,23,15); /* 24 */
			GG2_NoData (a, b, c, d, 0, S21, 0x21e1cde6,24,15); /* 25 */
			GG2 (d, a, b, c, len, S22, 0xc33707d6,25,14); /* 26 */
			GG2 (c, d, a, b, data3, S23, 0xf4d50d87,26,3); /* 27 */
			GG2_NoData (b, c, d, a, 0, S24, 0x455a14ed,27,15); /* 28 */
			GG2_NoData (a, b, c, d, 0, S21, 0xa9e3e905,28,15); /* 29 */
			GG2 (d, a, b, c, data2, S22, 0xfcefa3f8,29,2); /* 30 */
			GG2_NoData (c, d, a, b, 0, S23, 0x676f02d9,30,15); /* 31 */
			GG2_NoData (b, c, d, a, 0, S24, 0x8d2a4c8a,31,15); /* 32 */

			/* Round 3 */
			HH2_NoData (a, b, c, d, 0, S31, 0xfffa3942,32,15); /* 33 */
			HH2_NoData (d, a, b, c, 0, S32, 0x8771f681,33,15); /* 34 */
			HH2_NoData (c, d, a, b, 0, S33, 0x6d9d6122,34,15); /* 35 */
			HH2 (b, c, d, a, len, S34, 0xfde5380c,35,14); /* 36 */
			HH2 (a, b, c, d, data1, S31, 0xa4beea44,36,1); /* 37 */
			HH2_NoData (d, a, b, c, 0, S32, 0x4bdecfa9,37,15); /* 38 */
			HH2_NoData (c, d, a, b, 0, S33, 0xf6bb4b60,38,15); /* 39 */
			HH2_NoData (b, c, d, a, 0, S34, 0xbebfbc70,39,15); /* 40 */
			HH2_NoData (a, b, c, d, 0, S31, 0x289b7ec6,40,15); /* 41 */
			HH2 (d, a, b, c, data0, S32, 0xeaa127fa,41,0); /* 42 */
			HH2 (c, d, a, b, data3, S33, 0xd4ef3085,42,3); /* 43 */
			HH2_NoData (b, c, d, a, 0, S34,  0x4881d05,43,15); /* 44 */
			HH2_NoData (a, b, c, d, 0, S31, 0xd9d4d039,44,15); /* 45 */
			HH2_NoData (d, a, b, c, 0, S32, 0xe6db99e5,45,15); /* 46 */
			if(d!=td)continue;
			HH2_NoData (c, d, a, b, 0, S33, 0x1fa27cf8,46,15); /* 47 */
			HH2 (b, c, d, a, data2, S34, 0xc4ac5665,47,2); /* 48 */

			/* Round 4 */
			II2 (a, b, c, d, data0, S41, 0xf4292244,48,0); /* 49 */

			if(a==ta && b==tb && c==tc)
			{
				res = KEY_FOUND;

				#ifdef DebugValues  // finnaly print values
				//cuPrintf("a = %X, b = %X, c = %X, d = %X\n", a, b, c, d);
				//cuPrintf("ta = %X, tb = %X, tc = %X, td = %X\n", ta, tb, tc, td);

				//cuPrintf("th0 = %X, th1 = %X, th2 = %X, th3 = %X\n", target_hash[0], target_hash[1], target_hash[2], target_hash[3]);
	
	// For value unrolling:	
	cuPrintf("ta = %X, tb = %X, tc = %X, td = %X\n", ta_old, tb_old, tc_old, td_old);

				#endif

			};
		}
	}

	result_d[ix] = res;
}

// The host CPU Mandebrot thread spawner
// 0: OK
// 1: Error while calculation
extern "C" int do_123(gpu_data_xyz* data, int pwd_len, int charset_len)
{
	dim3 threads(data->thread_n);
	dim3 grid(data->grid_n);

	//copy combinations to device
/*	cudaEvent_t stop;
	CUDA_SAFE_CALL( cudaEventCreate(&stop)  );
	CCU2();*/

//	cudaMemcpyAsync(data_d, data->data_h, sizeof(int)*4*data->thread_n*data->grid_n, cudaMemcpyHostToDevice,0);  
	cudaMemcpy(data->data_d, data->data_h, sizeof(int)*4*data->thread_n*data->grid_n, cudaMemcpyHostToDevice);  
	CCU2();

#ifdef DebugValues
cudaPrintfInit();  // init print - first step of cuPrintf
#endif

	
	md5_gpu_bruteforce_thread<<<grid, threads>>>(data->data_d, data->result_d, pwd_len, charset_len);
	CCU2();

//	cudaMemcpyAsync(data->result, result_d, sizeof(int)*data->thread_n*data->grid_n, cudaMemcpyDeviceToHost, NULL);  
	cudaMemcpy(data->result, data->result_d, sizeof(int)*data->thread_n*data->grid_n, cudaMemcpyDeviceToHost);  
	CCU2();

#ifdef DebugValues
    cudaPrintfDisplay(stdout, true);  // part two of cuPrintf
    cudaPrintfEnd();
#endif

	cudaError_t result = cudaGetLastError();
	if(result != cudaSuccess)
	{
		char msg[512];msg[0]=0;
		strcpy_s(msg, 512, "CUDA kernel error: ");
		strcat_s(msg, 512, cudaGetErrorString(result));
		printf(msg);
		return 1;
	}

/*	cudaEventRecord(stop, 0);
	while( cudaEventQuery(stop) == cudaErrorNotReady )
	{
		Sleep(3);
	}
	CUDA_SAFE_CALL( cudaEventDestroy(stop));*/

	return 0;
}
