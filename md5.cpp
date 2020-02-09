#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//#include <multithreading.h>
#include "perm.h"
#include <math.h>
#include "cutil.h"
#include <fstream>
#include <iostream>
#include <process.h>
//#include <windows.h>
#include "algo/md5/md5_kernel.h"

#include "global.h"
//#include "md5_simple.h"

#include "console_stuff.h"

//include algorithm classes
#include "algo/md5/algo_md5.h"

//d41d8cd98f00b204e9800998ecf8427e empty
//9dd4e461268c8034f5c8564e155c67a6 x
//e6c760b3216a51c656c5861d72d5bf62 zx
//84b5f9386cdb436ccac2a4428e6557d7 |z8
//fd2cc6c54239c40495a0d3a93b6380eb zxcv
//21685d282d79098b89bdf5a916b66c90 superq
//74b87337454200d4d33f80c4663dc5e5 aaaa
//ed901cfb4e37beb63f7a1a27724a419a testtes
//1b0e9fd3086d90a159a1d6cb86f11b4c verylongpwd

//using namespace std;

//#include "md5_kernel.h"

#include "program_options.hpp"
using namespace program_options;
using Poco::Message;


//#include <boost/program_options.hpp>
//using namespace boost::program_options;

////////////////////////////////////////////////////////////////////////////////
// Main program
////////////////////////////////////////////////////////////////////////////////

void saveState()
{
	g->log->information("State saved.");
	ofstream outf("barswf.save");
	if(g->is_key_found)
	{
		outf<< 1 << endl;
		//print hash and password
		outf<< g->hash << endl;
		char buffer[256];
		extract_key(buffer);
		outf<< buffer << endl;
	} else
	{
		outf<< 0 << endl;//key not found
		outf<< g->hash << endl;
		outf<< "md5" << endl;
		outf<< perm::pwd_len << endl;//password len
		for(int i=0;i<perm::pwd_len;i++)
			outf<< perm::index[i] << " ";//password len
		outf<< endl;
		outf<< perm::charset_len << endl;//charset len
		for(int i=0;i<perm::charset_len;i++)
			outf<< (unsigned int)(perm::charset[i]) << " ";//password len
		outf<< endl;
	}
}

bool exists(const char * filename)
{
	return GetFileAttributes(filename) != 0xFFFFFFFF;
}

int hex2int_8(unsigned char* data)
{
	unsigned char tmp[3];
	tmp[2]=0;//just one 8bit value in hex
	strncpy_s((char*)tmp,3,(char*)data,2);
	return strtol((char*)tmp, NULL, 16);
}

void parse_hash(const unsigned char *hash)
{
	int pos = 0;
	for(int b=0;b<4;b++)
	{
		int shift = -8;int res = 0;
		for(int c=0;c<4;c++)
		{

			res |= (hex2int_8((unsigned char *)hash+pos))<<(shift+=8);
			pos+=2;
		}
		g->hash_ref[b] = res;
	}
}

#ifdef BROOK
void init_multi_gpu()
{
	g->gpu_count = 1;//TODO fixit
	if(g->gpu_count > MAX_GPU) g->gpu_count = MAX_GPU;

	for(int i=0;i<g->gpu_count;i++)
	{
		g->gpu[i].gpu.device_id=i;
		g->gpu[i].gpu.is_speed_detected = 0;
		g->gpu[i].avg = new avg_counter(10);
		g->gpu[i].gpu.keys_per_thread = 800;//40;
		g->gpu[i].avg->keys_per_block = (g->gpu[i].gpu.keys_per_thread*5.0)*perm::charset_len*perm::charset_len/1000000.0;//millions

		g->log->information("Main BROOK init #"+i2a(i));
		g->gpu[i].launcher = new thread_launcher_brook(&(g->gpu[i]));
		g->a->init_brook(&(g->gpu[i]));
	}
}
#endif

#ifdef CUDA
void init_multi_gpu()
{
	CUDA_SAFE_CALL(cudaGetDeviceCount(&g->gpu_count));
	if(g->gpu_count > MAX_GPU) g->gpu_count = MAX_GPU;

	for(int i=0;i<g->gpu_count;i++)
	{
		g->gpu[i].gpu.device_id=i;
		g->gpu[i].gpu.is_speed_detected = 0;
		g->gpu[i].avg = new avg_counter(20);

		g->log->information("Main CUDA init #"+i2a(i));
		g->gpu[i].launcher = new thread_launcher_cuda(&(g->gpu[i]));
		//		gpu[i].data_h = (unsigned int *)malloc(sizeof(int)*data_d_size);        
	}
}
#endif

void run_gpu_threads()
{
	//start threads
	for(int i=0;i<g->gpu_count;i++)
		if(i>32 || (g->gpu_mask&(1<<i)))//checking for allowed GPUs
		{
			g->log->information("Starting GPU thread #"+i2a(i));
			thread_count_inc();
			g->gpu[i].thrd.join();
			g->gpu[i].thrd.start((g->gpu[i].launcher)[0]);
		}
}


	void md5_result_thread(void *dummy)
	{
		int itt=0;
		static long double last_progress;
		while(g->update_screen_needed)//true till the end
		{
			Sleep(250);
			if(!g->update_screen_needed)break;//Just in case something changed during this Sleep
			{
				Poco::ScopedLock<Poco::FastMutex> lock(g->console_mutex);

				if(itt++%1200==0)saveState();//Save every 5 minutes
				//		update_timer = GetTickCount();
				//print current key
				
				if(last_progress!=perm::progress())
				{
					last_progress = perm::progress();
					console_xy(7, g->ui_total_y+2);
					console_color(10);
					for(int i=0;i<perm::gpu_len;i++)cout << perm::charset[rand()%perm::charset_len];//hehe
					for(int i=perm::gpu_len;i<perm::pwd_len;i++)cout << perm::data.variant[i];
				}


				//calc total for this thing
				double cpu_total = 0, gpu_total = 0;
				for(int i=0;i<g->gpu_count;i++)
				{
					gpu_total+=g->gpu[i].avg->get_avg();
					//update all
					console_xy(10+(1-1)*28, 4+i);console_color(10);
					cout.width(8);
					cout << g->gpu[i].avg->get_avg();
				}
				console_xy(10+(1-1)*28, g->ui_total_y);console_color(10);
				cout.width(8);
				cout << gpu_total;

				for(int i=0;i<g->cpu_count;i++)
				{
					cpu_total+=g->cpu[i].avg->get_avg();
					//update all
					console_xy(10+(1-0)*28, 4+i);console_color(10);
					cout.width(8);
					cout << g->cpu[i].avg->get_avg();
				}	//
				console_xy(10+(1-0)*28, g->ui_total_y);console_color(10);
				cout.width(8);
				cout << cpu_total;

				console_xy(38, g->ui_total_y+2);console_color(10);
				cout.width(8);
				double total_speed = gpu_total+cpu_total;
				cout << total_speed;

				//heart
				console_xy(30, 1);console_color(4);
				g->heart=246-g->heart;
				cout<<unsigned char('\x03'+g->heart);
				//Progress
				console_xy(11, g->ui_total_y+4);console_color(10);
				cout.width(6);
				cout<< perm::progress()*100;
				//Draw progress in console
				set_title(f2a(perm::progress()*100)+"%");
				//ETC
				if(total_speed>0)
				{
					long double time = ((1-perm::progress())*perm::total_keys())/(1000000*total_speed);//as speed is in millions
					int sec = (int)floorl(fmodl(time, 60));time/=60;
					int minute = (int)floorl(fmodl(time, 60));time/=60;
					int hour = (int)floorl(fmodl(time, 24));time/=24;
					int day = (int)floorl(time);

					cout.width(5);console_xy(23, g->ui_total_y+4);cout << day;
					cout.width(2);console_xy(34, g->ui_total_y+4);cout << hour;
					cout.width(2);console_xy(43, g->ui_total_y+4);cout << minute;
					cout.width(2);console_xy(50, g->ui_total_y+4);cout << sec;
				}
			}
		}

//		thread_count_dec();
	}

void run_result_thread()
{
	g->result_thread.setPriority(Poco::Thread::PRIO_LOW);
	g->result_thread.join();
	g->result_thread.start(md5_result_thread, g);
}


void init_multi_cpu()
{
	SYSTEM_INFO info;
	GetSystemInfo(&info);

	g->cpu_count = info.dwNumberOfProcessors;
#ifdef BROOK
	g->cpu_count--;//todo further versions might be better
#endif
	if(g->cpu_n!=-1)
		g->cpu_count = g->cpu_n;//User wants to change it

	for(int i=0;i<g->cpu_count;i++)
	{
		g->cpu[i].gpu.device_id=i;
		g->cpu[i].gpu.keys_per_thread = 12*((int)(1*1500000/(perm::charset_len*perm::charset_len)));
		g->cpu[i].gpu.data_h = (unsigned int *)malloc(sizeof(int)*4*(g->cpu[i].gpu.keys_per_thread));
		g->cpu[i].gpu.result = (int *)malloc(sizeof(int)*4*(g->cpu[i].gpu.keys_per_thread));//TODO data is not being freed
		g->cpu[i].avg = new avg_counter(100);
		g->cpu[i].avg->keys_per_block = (g->cpu[i].gpu.keys_per_thread)/1000000.0*perm::charset_len*perm::charset_len;//millions

	}
}



#ifdef CPU
void md5_cpu_thread(void *_data)
{
	//Sleep(1000);

	thread_data *data;
	data = (thread_data*)_data;

	// quite sure that here we should init SSE2 here!
	algo_md5 *algo = new algo_md5();
	algo->init_sse2_once(data);

		SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_BELOW_NORMAL);

		__int64 hTimer;
		QueryPerformanceCounter((LARGE_INTEGER *)&hTimer);

		int KeyPerThread = data->gpu.keys_per_thread;

		#pragma ivdep
		for(int i=0;i<KeyPerThread;i++)
			data->gpu.result[i] = KEY_NOT_FOUND;
//			memset(data->result, 0, 4*data->keys_per_thread);

		while(!g->is_finished)
		{
			perm::lock();//enter critical section
			perm::gen(data->gpu.data_h, data->gpu.keys_per_thread);
			perm::unlock();//done
			
			((algo_md5*)(g->a))->check_block_sse2(data->gpu.data_h, perm::pwd_len, perm::charset_len, data->gpu.keys_per_thread, data->gpu.result);
			((algo_md5*)(g->a))->check_result(data->gpu.data_h, data->gpu.result, data->gpu.keys_per_thread);//check result is common for all styles of calculation

			data->avg->push();
			perm::update_keys_done(data->gpu.keys_per_thread);
			// printf("Key:%s Speed: %f Mhash/sec \x0D", perm::data.variant, );
			
		}

		thread_count_dec();
};

void run_cpu_threads()
{
	//start threads
	for(int i=0;i<g->cpu_count;i++)
	{
		thread_count_inc();//increase that right away, we are not waiting till OS would start executing thread

		//todo
		//Poco::Thread thrd;
		//md5_cpu_thread runnable(g->cpu+i);
		
		//thrd.setPriority(Poco::Thread::PRIO_LOW);
//		thrd.start(runnable);
		g->cpu[i].thrd.setPriority(Poco::Thread::PRIO_LOW);
		g->cpu[i].thrd.join();
		g->cpu[i].thrd.start(md5_cpu_thread, g->cpu+i);

		//SetProcessAffinityMask(cpu[i].id,1);//1<<i
	}

}
#endif


void check_short_psw()
{
	g->a->init_len(1);//initial init_len was done when target was unknown

	if(g->hash_i[0]==0xd98c1dd4 && 
		g->hash_i[1]==0x04b2008f && 
		g->hash_i[2]==0x980980e9 && 
		g->hash_i[3]==0x7e42f8ec)
	{
		cout<<"Key is empty string. ROFL :-]"<<endl;exit(0);	
	}

	if(perm::pwd_len<=3)
	{

		for(int b1=0;b1<perm::charset_len;b1++)
		{
			md5_simple(perm::charset[b1]+(0x80<<8),0,0,0,8);
			for(int b2=0;b2<perm::charset_len;b2++)
			{
				md5_simple(perm::charset[b1]+(perm::charset[b2]<<8)+(0x80<<16),0,0,0,16);
				for(int b3=0;b3<perm::charset_len;b3++)
				{
					md5_simple(perm::charset[b1]+(perm::charset[b2]<<8)+(perm::charset[b3]<<16)+(0x80<<24),0,0,0,24);
				}
			}
		}
		perm::init_len(4);
	}
	if(g->is_finished)
	{
		print_result();
		exit(0);
	}
}

void init()
{
	//	cout.width(8);this have to be set before every cout<<
	g = new global_data();
	g->a = new algo_md5();//fixed MD5 now. TODO make configurable

	cout.precision(2);
	cout.fill(' ');
	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::right, ios::adjustfield);

	perm::init_thread();
	perm::init_len(1);

	g->threads_running = 0;

	g->is_key_found = false;
	g->is_finished = false;
	g->is_key_pressed = false;

	QueryPerformanceFrequency((LARGE_INTEGER *)&g->performance_freq);
}

void done()
{
	delete g;
}

void idle()
{
	//wait till all threads would finish
	while(g->threads_running!=0){
		Sleep(100);
		if(_kbhit()){
			_getch();

			print_status(" Stopping threads... ", 13);

			g->is_key_pressed = true;
			g->is_finished = true;
		}
	}
}

void addToCharset(bool *data, unsigned char *symbols)
{
	//Mark characters in charset table
	while(symbols[0]){data[symbols[0]]=true;symbols++;};
}

int compare( const void *arg1, const void *arg2 )
{
	return (*(unsigned char*)arg1)-(*(unsigned char*)arg2);
}

bool parse_command_line(int argc, char **argv)//return true if there anything to do
{
//	namespace po = boost::program_options;
	namespace po = program_options;
    try {
	po::options_description desc("Allowed options");
	string charset_class, add_charset, add_hexcharset, set_charset;

	desc.add_options()
	    ("help,?", "Display this help screen")
		("restore,r", "Continue interrupted work")
		("hash,h", po::value<string>(&g->hash), "Hash to attack")
		("cpu_n", po::value<int>(&g->cpu_n)->default_value(-1), "Number of CPU cores")
		("gpu_mask", po::value<int>(&g->gpu_mask)->default_value(-1), "1 enables first GPU, 2 - second, 15 - first 4, e.t.c")
		("grid_n", po::value<int>(&g->grid_n)->default_value(-1), "Grid count for nVidia")
		("thread_n", po::value<int>(&g->thread_n)->default_value(-1), "Thread count for nVidia")
		("gpu_time", po::value<int>(&g->gpu_time)->default_value(100), "How long GPU core is allowed to run")
		("min_len", po::value<int>(&g->min_len)->default_value(1), "Minimal password length")
		("charset,c", po::value<string>(&charset_class)->default_value(""), "Set charset. 0 - digits, a - small chars, A - capitals, ~ - special symbols (special symbols are ~`'!@#$%^&*()_+=- /?.,\\|\")")
		("set_charset,s", po::value<string>(&set_charset)->default_value(""), "Set charset - fallowed by characters string")
		("custom_characters,C", po::value<string>(&add_charset)->default_value(""), "Extra characters")
		("hex_characters,X", po::value<string>(&add_hexcharset)->default_value(""), "Extra characters in hex");

     variables_map vm;
     store(parse_command_line(argc, argv, desc), vm);
	 store(parse_config_file(ifstream("barswf.cfg") ,desc), vm);
	 notify(vm);

	 if (vm.size()==0 || vm.count("help")) {  
		cout << desc << "\n";
        return false;
    }

	 if (vm.count("restore"))
	{
		if(!exists("barswf.save"))
		{
			cout << "ERROR: Unable to open barswf.save" << endl;
			return false;
		}

		//Load charset, last combination
		ifstream inf("barswf.save");
		int mode;
		inf >> mode;//0 - not finished, 1 - finished
		if(mode==1)
		{
			cout << "Unable to bruteforce as password was already found ;-). Check barswf.save." << endl;
			return false;
		}
		char buffer[256];
		inf.getline(buffer, 256);//just to skip EOL
		char algorithm[256];
		inf.getline(buffer, 256);//just md5 for now
		g->hash = buffer;

		inf.getline((char *)algorithm, 256);
		parse_hash((unsigned char*)g->hash.c_str());

		int len;//combination
		int combination[256];
		inf >> len;
		for(int i=0;i<len;i++)
			inf >> combination[i];

		int charset_len, tmp;
		bool charset[256];
		memset(charset, 0, sizeof(charset));

		inf >> charset_len;
		for(int i=0;i<charset_len;i++)
		{
			inf >> tmp;
			charset[tmp] = true;
		}

		perm::init(charset, len, combination);
		return true;
	}

	//Bruteforce mode, require hash and charset 
	if(vm.count("hash"))
	{
		if(g->hash.length()!=32)
		{
			cout << g->hash << "Wrong MD5 hash. It should be 32 hex characters."<<endl;
			return false;
		}
	} else
	{
			cout << "You have to specify hash!"<<endl;
			return false;
	}

	bool charset[256];
	memset(charset, 0, sizeof(charset));
	//Do the charset dirty job
	if( vm.count("charset"))
	{
		char * ptr = (char *)charset_class.c_str();
		while(ptr[0])
		{
			switch(ptr[0])
			{
			case '0':for(unsigned char c='0';c<='9';c++)charset[c]=true;break;
			case 'a':for(unsigned char c='a';c<='z';c++)charset[c]=true;break;
			case 'A':for(unsigned char c='A';c<='Z';c++)charset[c]=true;break;
			case '~':addToCharset(charset, (unsigned char*)"~`'!@#$%^&*()_+=- /?.,\\|\"");break;
			default:
				cout << "Incorrect symbol '"<< ptr[0] <<"' in charset definition (-c parameter)"<<endl;
				return false;
			}
			ptr++;
		}
	}

	if( vm.count("set_charset"))
	{
		addToCharset(charset, (unsigned char *)set_charset.c_str());
	}

	if(vm.count("custom_characters"))
	{
		addToCharset(charset, (unsigned char *)add_charset.c_str());
	}

	if(vm.count("hex_characters"))
	{
		unsigned char *pos = (unsigned char*)add_hexcharset.c_str();
		while(1)
		{
			if(pos[0]==0||pos[1]==0)break;
			charset[hex2int_8(pos)]=true;
			pos+=2;
		}
	}

	//calc num of characters in charset
	int count = 0;
	for(int i=0;i<256;i++)
		if(charset[i])count++;

	if(count==0)
	{
		cout << "Please, specify charset: -c and/or -C command line options."<<endl;
		return false;
	}

	perm::init(charset, g->min_len);
	parse_hash((unsigned char*)g->hash.c_str());
    }
    catch(exception& e) {
        cerr << e.what() << "\n";
		return false;
    }

	return true;
}

int main(int argc, char **argv)
{	
	//char cresult[100];
	//int Size1 = sizeof(gpu_mask_2_128);
	//sprintf(cresult, "__m128i size = %d", Size1);

	init();

	g->log->information("------------------------------");
	g->log->information("BarsWF started");

	if(!parse_command_line(argc, argv))
	{
		return 0;
	}

#ifdef CUDA
	g->log->information("Init CUDA");
//	init_md5_cuda(&(g->gpu[0].gpu), g->hash_i, perm::charset, perm::charset_len);
	init_multi_gpu();
#endif
#ifdef BROOK
	g->log->information("Init BROOK");
	init_multi_gpu();
#endif
	g->log->information("Init SSE2");
	init_multi_cpu();
	draw_header();
	clrscr();draw_header();draw_stat();
	check_short_psw();
	g->log->information("Init Display");
	run_result_thread();//Result thread works always

	while(1)
	{
#ifdef CUDA
		run_gpu_threads();
//		int test[4];
//		cudaMemcpyToSymbol("target_hash", test/*hash_i*/, 4*4, 0, cudaMemcpyHostToDevice);
		//CCU();

//		init_md5_cuda(0/*&g->gpu[0].gpu*/, 0, 0, 0);
		//g->a->run_cuda(&g->gpu[0]);
#endif
#ifdef BROOK
		run_gpu_threads();
#endif
#ifdef CPU
		run_cpu_threads();  // for testing purposes I've disabled CPU
#endif

		idle();//this runs in a loop while worker threads are working
		if(g->is_corrupted)
			break;
		if(g->is_key_pressed)
			break;
		if(g->is_finished && perm::end_of_calc && !g->is_key_found)
		{
			perm::init_len(perm::pwd_len+1);
			g->is_finished = false;		
		}
		if(g->is_key_found)
			break;
	}
	g->update_screen_needed = false;

	print_result();
	saveState();
	Sleep(260);//Long enough to have result thread finish
	done();
}
