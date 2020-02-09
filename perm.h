#pragma once
#include "Poco/Mutex.h"
#include "Poco/ScopedLock.h"

typedef union
	{
		unsigned char variant[64];
		int pass_i[16];
	} my_data;


void ChangeColour(__int16 theColour);

class perm
{
public: 
	static unsigned char charset[256];
	static unsigned char SpecialChars[256];
	static int charset_len;
	static int index[256];
	static int pwd_len, pwd_len8, gpu_len;
	static bool end_of_calc;
	static long double keys_checked;
	static __int64 timer;

	static my_data data;

	static Poco::FastMutex mutex;


	static void lock();
	static void unlock();
	static void init_thread();
	static void init(int pwd_len);
	static void init(bool * charset, int pwd_len, int * combination = NULL);
	static void init_len(int new_len);
	static void gen_data(unsigned int &d1, unsigned int &d2, unsigned int &d3, unsigned int &d4);
	static void gen(unsigned int * data, int num);
	static void update_keys_done(long double keys_just_checked);
	static long double avg_speed();

	static long double total_keys();
	static long double progress();//0-1
};
