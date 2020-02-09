//do all algorithm dependant stuff, like initialization & key generation
//this one is general class, we have a specialization class per algorithm
#pragma once
#include "../global.h"
#include <iostream>
#include <string>
using namespace std;
#include "../sse2_helpers.h"

class algo
{
public:
	int dword_per_key;//size of key in low-level implementation, set in constructor specialization
	algo();


	virtual ~algo();

	virtual void init_sse2_once(thread_data *data){};
	virtual void init_brook(thread_data *data){};
	virtual void init_cuda(thread_data *data){};
	virtual void init_cuda_once(thread_data *data){};


	virtual void prepare_keys(int *data, int num);
	virtual void check_result(unsigned int *data, int *result, int num_of_packets){};//this will go through results and check for exact keys if any
	virtual void init_len(int len){};//initialize stuff for new key length
	virtual void check_block_sse2(unsigned int *data_d, unsigned int pwd_len, int charset_len, int keys_per_thread, int* result){};

	virtual void run_brook(thread_data *data, bool is_benchmark = false){};
	virtual void run_cuda(thread_data *data, bool is_benchmark = false){};
	virtual void detect_keys_brook(thread_data *data){};

	//default implementations
	void prepare_keys_asci(int *data, int num);
	void prepare_keys_unicode(int *data, int num);
};