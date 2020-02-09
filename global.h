#pragma once

//#undef CUDA
//#define CUDA
#undef CPU
#define CPU - set in options->preprocessor definition

#ifdef CUDA
#define GPU
#endif

#ifdef BROOK
#define GPU
#endif

#define VERSION "0.C"

//32-bit int
typedef unsigned __int32 ui;

//#include <windows.h>
#include <mmintrin.h>
#include <emmintrin.h>
//#include <smmintrin.h>

#include "Poco/Mutex.h"
#include "Poco/Timestamp.h"
#include "Poco/Stopwatch.h"
#include "Poco/ScopedLock.h"
#include "Poco/Thread.h"

#include "Poco/Logger.h"
#include "Poco/PatternFormatter.h"
#include "Poco/FormattingChannel.h"
#include "Poco/FileChannel.h"
#include "Poco/Message.h"

using Poco::Logger;
using Poco::PatternFormatter;
using Poco::FormattingChannel;
using Poco::FileChannel;
using Poco::Message;

//#include <boost/cstdint.hpp>
#include <iostream>
#include <vector>

#include "global_c.h"

#ifdef BROOK
#include "algo/md5/md5_pp.h"
#endif

#ifdef CUDA
#include <cuda_runtime_api.h>
#endif
//#include <boost/timer.hpp>

using namespace std;

#define MAX_CPU 128
#define MAX_GPU 128

class avg_counter;
class global_data;
class thread_launcher;

// Global Variables:
extern global_data *g;

//:-[ Not reliable as class member
extern __m128i gpu_mask_2_128;
extern __m128i CONST_MAX128,sse2_nodata,sse2_lendata,target_sse[4];
extern __m128i md5_const_sse2[64];


struct thread_data
{
	HANDLE id;
	Poco::Thread thrd;
	thread_launcher *launcher;//this is proxy class to launch thread
	avg_counter *avg;

	gpu_data_xyz gpu;

#ifdef BROOK
	::brook::Stream<int> *streams[20];
	::brook::Stream<int> *output;
	::brook::Stream<int> *charset;
	int *stream_buffer[20];
#endif 
};

class algo;
class global_data
{
public:
	global_data() : min_len(1), grid_n(-1), cpu_n(-1), gpu_mask(-1), thread_n(-1), gpu_time(100), heart(0), 
		is_finished(false), is_corrupted(false), is_key_found(false), is_key_pressed(false), is_error_detected(false), 
		threads_running(0), final_len(-1), a(NULL), update_screen_needed(true)
	{
		timer.start();
	
		//POCO Logging
		pFCFile = new FormattingChannel(new PatternFormatter("%Y-%m-%d %H:%M:%S.%c %N[%P]:%s:%q:%t"));
		pFCFile->setChannel(new FileChannel("barswf.log"));
		pFCFile->open();
		Logger::create("BarsWF", pFCFile, Message::PRIO_DEBUG);
		log = Logger::has("BarsWF");
	}

	~global_data()
	{
//		delete log; cannot delete that for some reason
		pFCFile->close();
	}

	Poco::FastMutex console_mutex, perm_mutex, thread_count_mutex; 

	bool update_screen_needed;//True while we need to update screen
	bool is_finished;//Finished != Key found
	bool is_corrupted;//If true = calc error, may be driver problem or overclock
	bool is_key_found;
	bool is_key_pressed;
	bool is_error_detected;


	//POCO Logging
	FormattingChannel* pFCFile;
	Logger* log;

	unsigned int final_len;
	unsigned int final_key[4];

	Poco::Thread result_thread;

	thread_data gpu[MAX_GPU];
	thread_data cpu[MAX_CPU];
	int gpu_count;
	int cpu_count;
	int threads_running;
	__int64 performance_freq;
	HANDLE result_thread_id;
	string hash;

	unsigned int update_timer;

	int ui_total_y;

	int hash_i[4];//processed value
	int hash_ref[4];//original value
	int heart;

//values from command line parameters
	int cpu_n;//number of CPUs to use
	int gpu_mask;//GPU mask
	int grid_n;
	int thread_n;
	int gpu_time;
	int min_len;

	algo *a;

	Poco::Stopwatch timer;
};//1 instance of that class is created.

extern global_data *g;

#define ELAPSED ((double)g->timer.elapsed()*0.000001L)

//this should count avg speed of anything is keys/sec
class avg_counter
{
public:
	int num_avg, num_recorded, write_to, last_pos;
	vector<double> record_time; 
	Poco::FastMutex avg_mutex;
	double keys_per_block,//This should be set ASAP, millions 
		   last_non_zero;//This is to avoid 0's during speed detection

	avg_counter(int num_avg) : num_avg(num_avg), num_recorded(0),write_to(0),last_pos(0), keys_per_block(0), last_non_zero(0)
	{
		record_time.resize(num_avg);
	}

	//reset statistics, in case of keys_per_block change
	void reset()
	{
		num_recorded = 0;
		write_to = 0;
		last_pos = 0;
		push();//first point before first itteration to get first results faster
	}

	void push()
	{
		Poco::ScopedLock<Poco::FastMutex> lock(avg_mutex);
		
		record_time[(num_recorded++)%num_avg] = ELAPSED;
	}

	double get_avg()
	{
		Poco::ScopedLock<Poco::FastMutex> lock(avg_mutex);
		double start_time, end_time;
		
		if(num_recorded==0)return last_non_zero;
		
		if(num_recorded<=num_avg)
		{
			start_time = record_time[0];
			end_time = record_time[num_recorded-1];
			if((end_time-start_time)<0.0001)return last_non_zero;
			last_non_zero = (num_recorded-1)*keys_per_block/(end_time-start_time);//keys_per_block
		} else
		{
			start_time = record_time[(num_recorded)%num_avg];
			end_time = record_time[(num_recorded-1)%num_avg];
			if((end_time-start_time)<0.0001)return last_non_zero;
			last_non_zero = (num_avg-1)*keys_per_block/(end_time-start_time);
		}
		return last_non_zero;
	}
};

//wrapper for boost thread execution
class thread_launcher : public Poco::Runnable
{
public:
	thread_data *data;
	thread_launcher(){};
	thread_launcher(thread_data *data)
	{ 
		this->data = data;
	};
	virtual void run() {
	};
};

class thread_launcher_brook : public thread_launcher
{
public:
	thread_launcher_brook(thread_data *data)
	{ 
		this->data = data;
	};
	void run();
};

class thread_launcher_cuda : public thread_launcher
{
public:
	thread_launcher_cuda(thread_data *data)
	{ 
		this->data = data;
	};
	void run();
};

void CCU();

void thread_count_dec();
void thread_count_inc();

string f2a(double value);
string i2a(int value);
