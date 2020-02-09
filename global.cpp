//we define common things here
#include "global.h"
#include "perm.h"

#include <iostream>
#include <sstream>
#include <math.h>
#include <assert.h>
#include "algo/algo.h"
using namespace std;

global_data *g = NULL;

__m128i gpu_mask_2_128;
__m128i CONST_MAX128,sse2_nodata,sse2_lendata,target_sse[4];
__m128i md5_const_sse2[64];


void thread_launcher_brook::run()
{
	g->a->run_brook(data);
};

#ifdef CUDA
void thread_launcher_cuda::run()
{
	g->log->information("CUDA thread start GPU#"+i2a(data->gpu.device_id));
	g->a->init_cuda_once(data);
	data->avg->reset();//so that we ignore inter-length wait time
	g->a->run_cuda(data);
	cudaThreadExit();
	thread_count_dec();
	g->log->information("CUDA thread stop GPU#"+i2a(data->gpu.device_id));
};
#endif CUDA

void thread_count_dec()
{
	Poco::ScopedLock<Poco::FastMutex> lock(g->thread_count_mutex);
	g->threads_running--;
}

void thread_count_inc()
{
	Poco::ScopedLock<Poco::FastMutex> lock(g->thread_count_mutex);
	g->threads_running++;
}

string f2a(double value)
{
	std::stringstream tmp;
	tmp.precision(3);
	tmp << fixed << value;
	return tmp.str();
}

string i2a(int value)
{
	std::stringstream tmp;
	tmp << value;
	return tmp.str();
}

#ifdef CUDA
void CCU()
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
#endif
