#include "algo.h"
#include "../perm.h"
#include <assert.h>

algo::algo()
{

}

algo::~algo()
{

}

void algo::prepare_keys(int *data, int num)
{
	//default is asci key preparation
	prepare_keys_asci(data, num);
}

void algo::prepare_keys_asci(int *data, int num)
{
	perm::lock();//enter critical section
	perm::gen((unsigned int*)data, num);
	perm::unlock();//done
}

void algo::prepare_keys_unicode(int *data, int num)
{
	assert(false);//not implemented
}