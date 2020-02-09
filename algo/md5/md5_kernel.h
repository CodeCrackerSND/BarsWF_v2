#ifndef _MANDELBROT_KERNAL_h_
#define _MANDELBROT_KERNAL_h_

#ifdef CUDA
#include <vector_types.h>
#endif

#include "..\..\global_c.h"

extern "C" int  do_123(gpu_data_xyz* data, int pwd_len, int charset_len);
extern "C" void cuda_done_md5();
extern "C" void cuda_get_mem(gpu_data_xyz* data);//This should be run in thread context
extern "C" void cuda_free_mem(gpu_data_xyz* data);
extern "C" void init_md5_cuda(gpu_data_xyz* data, int* hash_i, unsigned char *charset, int charset_len);

#endif
