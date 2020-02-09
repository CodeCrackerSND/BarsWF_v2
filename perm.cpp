#include <string.h>
#include "perm.h"
#include <assert.h>
#include <iostream>
#include "global.h"
#include "algo/algo.h"
#include <math.h>

using namespace std;

unsigned char perm::charset[256];
unsigned char perm::SpecialChars[256];
int perm::charset_len;
bool perm::end_of_calc = false;
my_data perm::data;
int perm::index[256];
int perm::pwd_len, perm::pwd_len8, perm::gpu_len;
Poco::FastMutex perm::mutex;
long double perm::keys_checked;
__int64 perm::timer;

static void init(int pwd_len, int gpu_len);
static void gen();

void perm::init_thread()
{
}

void perm::init(bool * charset, int pwd_len, int * combination)
{
	charset_len = 0;
	for(unsigned int i=0;i<256;i++)
		if(charset[i])
		{
			perm::charset[charset_len++]=(unsigned char)i;	
		}

	perm::init(pwd_len);	

	if(combination != NULL)
	{
		for(int i=0;i<pwd_len;i++)
		{
			index[i]=combination[i];
			data.variant[i]=perm::charset[index[i]];
		}		
	}


//SpecialChars[0] = perm::charset[0];  // the first char will be first allowed char

// SpecialChars[i] will point to next char like this:
// SpecialChars['a'] = 'b';
// SpecialChars['b'] = 'c';
// SpecialChars['c'] = 00;  // the end of a loop
//for (int i=0;i<charset_len-1;i++)
//SpecialChars[perm::charset[i]] = perm::charset[i+1];

}

void perm::init(int pwd_len)
{
	// access the resource

	perm::pwd_len = pwd_len;
	end_of_calc = true;

	//	if(charset_len<=36)perm::gpu_len = 3;else perm::gpu_len = 2;
	if(pwd_len<4)gpu_len = 0;

	init_len(pwd_len);
}

void perm::gen_data(unsigned int &d1, unsigned int &d2, unsigned int &d3, unsigned int &d4)
{
//char NextChar;

	//store things
	d1 = data.pass_i[0];
	d2 = data.pass_i[1];
	d3 = data.pass_i[2];
	d4 = data.pass_i[3];
	//generate new perm
	int pos = pwd_len-1;

/* NEW WAY - NO IMPROVEMENT

while (1)
{

LoopStart:
NextChar = SpecialChars[data.variant[pos]];
if (NextChar!=0)
{
data.variant[pos] = NextChar;
break;
}
else
{

data.variant[pos] = SpecialChars[0];  // we start again
pos--;

if(pos<gpu_len)
{
end_of_calc = true;
break;
}

goto LoopStart;
}

}

*/

	// OLD CODE:
	while(1)
	{
		index[pos]++;
		data.variant[pos] = charset[index[pos]];
		if(index[pos]==charset_len)
		{
			index[pos]=0;
			data.variant[pos]=charset[0];
			pos--;
			if(pos<gpu_len)
			{
				end_of_calc = true;
				break;

			}
			continue;
		} else
			break;
	}
	
}

// in the down method there was a mistake: perm::gen called itself!
// I have to rename to perm::gen_data
void perm::gen(unsigned int * data, int num)
{
	int pos = 0;
	for(int i=0;i<num;i++)
	{
		perm::gen_data(data[i*4+0],data[i*4+1],data[i*4+2],data[i*4+3]);//Up to 15 symbols length

	}
	//check for the end
	if(perm::end_of_calc)
	{
		g->is_finished = true; //this is the end.
	}
}

void perm::update_keys_done(long double keys_just_checked)
{
	keys_checked += keys_just_checked*charset_len*charset_len;
}


long double perm::total_keys()
{
	return powl(charset_len, pwd_len);//charset_len should not be 0, that should be checked somewhere
}

long double perm::progress()
{
	if(g->is_finished && !g->is_key_pressed)
		return 1;

	long double progress = 0;
	long double scale = 1;
	for(int i=gpu_len;i<pwd_len;i++)
	{
		scale/=charset_len;
		progress += scale*index[i];
	}
	return progress;
}

void perm::init_len(int new_len)
{
	perm::pwd_len = new_len;
	perm::pwd_len8 = 8*new_len;

	data.variant[pwd_len]=0x80;
	for(int i=pwd_len+1;i<64;i++)data.variant[i]=0;

	for(int i=0;i<pwd_len;i++)
	{
		index[i]=0;
		data.variant[i]=charset[index[i]];
	}
	end_of_calc=false;
	if(new_len>3)gpu_len=2;
	
	/*for(int i=0;i<gpu_len;i++)
		data.variant[i]=0;//for GPU speedup, to avoid mask
	//not used now
	*/
	//reinit common algorithm stuff
 	g->a->init_len(new_len);
	//reinit avg speed calculator
	QueryPerformanceCounter((LARGE_INTEGER*)&timer);
	keys_checked = 0;
}

void perm::lock()
{
	mutex.lock();
}

void perm::unlock()
{
	mutex.unlock();
}

long double perm::avg_speed()
{
	__int64 curr_time;
	QueryPerformanceCounter((LARGE_INTEGER*)&curr_time);
	if(curr_time==timer)
		return 0;
	else
		return ((long double)keys_checked)/(((long double)(curr_time-timer))/g->performance_freq*1000.0L*1000.0L);
	
}