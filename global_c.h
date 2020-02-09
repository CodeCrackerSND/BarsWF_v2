#pragma once
//this file might be shared with C brook compiler

#define KEY_FOUND 0x4f9170e8
#define KEY_NOT_FOUND 0x1c92b384

//1 piece of data for CUDA
struct md5_data { 
	int res[4]; 
}; 

struct gpu_data_xyz
{
	int is_speed_detected;//there are 2 speed detect attempts, TODO set to 0 on init
	int device_id;
	int last_len;
	int grid_n, thread_n;
	int keys_per_thread;//only for CPU
	unsigned int *data_h;//keys
	int *result;//result - if there was a key found, 1 = found, 0 = not found

#ifdef CUDA
	unsigned int *result_d;  //h - host, d - device
	unsigned int *data_d;  //h - host, d - device
#endif
};
