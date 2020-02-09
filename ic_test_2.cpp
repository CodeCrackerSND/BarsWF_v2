#include <iostream>
using namespace std;
#include <mmintrin.h>
#include <emmintrin.h>

#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21

#define set32(var, val) var = _mm_set_epi32(val,val,val,val);
#define ROTATE_LEFT_SSE(x, n) {__m128i tmp;tmp = _mm_srli_epi32(x, 32-n);x = _mm_slli_epi32(x, n);x = _mm_or_si128(x, tmp);};

#define F_SSE(x, y, z) (_mm_or_si128(_mm_and_si128(x,y), _mm_andnot_si128(x, z)))
#define G_SSE(x, y, z) (_mm_or_si128(_mm_and_si128(x,z), _mm_andnot_si128(z, y)))
#define H_SSE(x, y, z) (_mm_xor_si128(_mm_xor_si128(x,y), z))
#define I_SSE(x, y, z) (_mm_xor_si128(y, _mm_or_si128(x,_mm_andnot_si128(z, CONST_MAX128))))

#define DO_SSE(step, a, b, c, d, x, s, ac, id) { \
	a=_mm_add_epi32(_mm_add_epi32(a,_mm_add_epi32(x,ac)),step##_SSE ((b), (c), (d))); \
	ROTATE_LEFT_SSE (a, s); \
	a = _mm_add_epi32(a,b); \
}
#define DO_SSE_UNROLL(step, a, b, c, d, x, s, ac, id) { \
	a = _mm_sub_epi32(a,b); \
	ROTATE_LEFT_SSE (a, (32-(s))&31); \
	a=_mm_sub_epi32(a,_mm_add_epi32(_mm_add_epi32(x,step##_SSE ((b), (c), (d))),ac)); \
}

#define no_data 1000
#define len_data 333
#define get_data(thread,pos) ((pos==no_data)?sse2_nodata:(pos==len_data)?sse2_lendata:data[pos])

#define FF2_SSE2(a, b, c, d, x, s, ac, ic,id) { DO_SSE(F,a##s1,b##s1,c##s1,d##s1,get_data(0,x),s,md5_const_sse2[ic], id);}//DO_SSE(F,a##s2,b##s2,c##s2,d##s2,get_data(1,x),s,md5_const_sse2[ic], id);DO_SSE(F,a##s3,b##s3,c##s3,d##s3,get_data(2,x),s,md5_const_sse2[ic], id);}//DO_SSE(F,a##s4,b##s4,c##s4,d##s4,data.xs[id],s,md5_const_sse2[ic], id);}
#define GG2_SSE2(a, b, c, d, x, s, ac, ic,id) { DO_SSE(G,a##s1,b##s1,c##s1,d##s1,get_data(0,x),s,md5_const_sse2[ic], id);}//DO_SSE(G,a##s2,b##s2,c##s2,d##s2,get_data(1,x),s,md5_const_sse2[ic], id);DO_SSE(G,a##s3,b##s3,c##s3,d##s3,get_data(2,x),s,md5_const_sse2[ic], id);}//DO_SSE(G,a##s4,b##s4,c##s4,d##s4,data.xs[id],s,md5_const_sse2[ic], id);}
#define HH2_SSE2(a, b, c, d, x, s, ac, ic,id) { DO_SSE(H,a##s1,b##s1,c##s1,d##s1,get_data(0,x),s,md5_const_sse2[ic], id);}//DO_SSE(H,a##s2,b##s2,c##s2,d##s2,get_data(1,x),s,md5_const_sse2[ic], id);DO_SSE(H,a##s3,b##s3,c##s3,d##s3,get_data(2,x),s,md5_const_sse2[ic], id);}//DO_SSE(H,a##s4,b##s4,c##s4,d##s4,data.xs[id],s,md5_const_sse2[ic], id);}
#define II2_SSE2(a, b, c, d, x, s, ac, ic,id) { DO_SSE(I,a##s1,b##s1,c##s1,d##s1,get_data(0,x),s,md5_const_sse2[ic], id);}//DO_SSE(I,a##s2,b##s2,c##s2,d##s2,get_data(1,x),s,md5_const_sse2[ic], id);DO_SSE(I,a##s3,b##s3,c##s3,d##s3,get_data(2,x),s,md5_const_sse2[ic], id);}//DO_SSE(I,a##s4,b##s4,c##s4,d##s4,data.xs[id],s,md5_const_sse2[ic], id);}

#define unrollII_SSE2(a, b, c, d, x, s, ac, ic,id) {DO_SSE_UNROLL(I,a##s1,b##s1,c##s1,d##s1,get_data(0,x),s,md5_const_sse2[ic], id);}


__m128i target_sse[4];


class algo
{
public:
	virtual void a(){};
	virtual void check_block_sse2(unsigned int *data_d, unsigned int pwd_len, int charset_len, int keys_per_thread, int* result){};
};

class algo_md5 : public algo
{
public:
	__m128i gpu_mask_2_128;
	__m128i CONST_MAX128,sse2_nodata,sse2_lendata,target_sse[4];
	__m128i md5_const_sse2[64];

	void a()
	{
		cout << "derived a";
	};

	void check_block_sse2(unsigned int *data_d, unsigned int pwd_len, int charset_len, int keys_per_thread, int* result)
	{
	unsigned long int a1 = 0x67452301, b1 = 0xefcdab89, c1 = 0x98badcfe, d1 = 0x10325476;
	__m128i data[4], key;
	unsigned int value;//this is common part of key

	int sse2_thread = 0;

	{
//#pragma loop_count min=10, max=26616, avg=30000
//		cout << keys_per_thread<<endl;
//		keys_per_thread = 26616;
//		keys_per_thread = 100;
#pragma unroll(3)
		for(int key_pos=0;key_pos<keys_per_thread;key_pos++)
		{
//#pragma nounroll
//TODO if I uncomment this, it hangs 
			for(int i=0;i<4;i++)
				//for(int sse2_thread=0;sse2_thread<3;sse2_thread++)
			{
				data[i] = _mm_set_epi32(
					data_d[(key_pos*4+0)*4+i],
					data_d[(key_pos*4+1)*4+i],
					data_d[(key_pos*4+2)*4+i],
					data_d[(key_pos*4+3)*4+i]);
			}

			//Unroll known steps
			__m128i tas1,tbs1,tcs1,tds1;//init values are the same

			tas1=target_sse[0];tbs1=target_sse[1];tcs1=target_sse[2];tds1=target_sse[3];

			unrollII_SSE2(tc, td, ta, tb, 2      , S43, 0x2ad7d2bb,62,2); /* 63 */




			/*			dump_sse2("0", sse2_nodata);
			dump_sse2("0", md5_const_sse2[61]);
			dump_sse2("a", tas1);
			dump_sse2("b", tbs1);
			dump_sse2("c", tcs1);
			dump_sse2("d", tds1);*/

			/*	tds1 = _mm_sub_epi32(tds1,tas1); 
			ROTATE_LEFT_SSE (tds1, (32-(S42))&31); 
			dump_sse2("d", md5_const_sse2[61]);
			tds1=_mm_sub_epi32(tds1,_mm_add_epi32(_mm_add_epi32(sse2_nodata,I_SSE ((tas1), (tbs1), (tcs1))),md5_const_sse2[61])); */

			unrollII_SSE2(td, ta, tb, tc, no_data, S42, 0xbd3af235,61,15); /* 62 */
			/*			dump_sse2("d", tds1);
			getch();*/
			unrollII_SSE2(ta, tb, tc, td, no_data, S41, 0xf7537e82,60,15); /* 61 */


			unrollII_SSE2(tb, tc, td, ta, no_data, S44, 0x4e0811a1,59,15); /* 60 */
			unrollII_SSE2(tc, td, ta, tb, no_data, S43, 0xa3014314,58,15); /* 59 */
			unrollII_SSE2(td, ta, tb, tc, no_data, S42, 0xfe2ce6e0,57,15); /* 58 */
			unrollII_SSE2(ta, tb, tc, td, no_data, S41, 0x6fa87e4f,56,15); /* 57 */
			unrollII_SSE2(tb, tc, td, ta, 1      , S44, 0x85845dd1,55,1); /* 56 */
			unrollII_SSE2(tc, td, ta, tb, no_data, S43, 0xffeff47d,54,15); /* 55 */
			unrollII_SSE2(td, ta, tb, tc, 3      , S42, 0x8f0ccc92,53,3); /* 54 */
			unrollII_SSE2(ta, tb, tc, td, no_data, S41, 0x655b59c3,52,15); /* 53 */
			//			result[key_pos] = _mm_movemask_epi8(tas1);
			unrollII_SSE2(tb, tc, td, ta, no_data, S44, 0xfc93a039,51,15); /* 52 */
			unrollII_SSE2(tc, td, ta, tb, len_data, S43, 0xab9423a7,50,14); /* 51 */
			unrollII_SSE2(td, ta, tb, tc, no_data, S42, 0x432aff97,49,15); /* 50 */

			/*data[i][sse2_thread] = _mm_set_epi32(
			data_d[(key_pos+sse2_thread*4+0)*4+i],
			data_d[(key_pos+sse2_thread*4+1)*4+i],
			data_d[(key_pos+sse2_thread*4+2)*4+i],
			data_d[(key_pos+sse2_thread*4+3)*4+i]);*/

			//		for(int i=0;i<4;i++)data[i]=data_d[(ix*keys_per_thread+key_pos)*4+i];//
#pragma nounroll
			for(int s2=0;s2<charset_len;s2++)
			{
				value=('a'+s2)<<8;
#pragma nounroll
				for(int s1=0;s1<charset_len;s1++)
				{
					value=(value&0x0000ff00)+('a'+s1);
					set32(key, value);
					//set all keys to the lower 16 bits of every data part
					data[0]=_mm_or_si128(_mm_and_si128(data[0], gpu_mask_2_128), key);

					__m128i as1,bs1,cs1,ds1;//init values are the same
					set32(as1, a1);set32(bs1, b1);set32(cs1, c1);set32(ds1, d1);

					/* Round 1 */
					FF2_SSE2 (a, b, c, d, 0, S11, 0xd76aa478,0,0); /* 1 */
					FF2_SSE2 (d, a, b, c, 1, S12, 0xe8c7b756,1,1); /* 2 */
					//cout<<"b: "<<_mm_cvtsi128_si32(bs1)<<endl;
					FF2_SSE2 (c, d, a, b, 2, S13, 0x242070db,2,2); /* 3 */
					//cout<<"c: "<<_mm_cvtsi128_si32(cs1)<<endl;
					FF2_SSE2 (b, c, d, a, 3, S14, 0xc1bdceee,3,3); /* 4 */
					//cout<<"d: "<<_mm_cvtsi128_si32(ds1)<<endl;
					FF2_SSE2 (a, b, c, d, no_data, S11, 0xf57c0faf,4,15); /* 5 */ //5th and so forth is 0
					//cout<<"a: "<<_mm_cvtsi128_si32(as1)<<endl;
					FF2_SSE2 (d, a, b, c, no_data, S12, 0x4787c62a,5,15); /* 6 */
					FF2_SSE2 (c, d, a, b, no_data, S13, 0xa8304613,6,15); /* 7 */
					FF2_SSE2 (b, c, d, a, no_data, S14, 0xfd469501,7,15); /* 8 */
					FF2_SSE2 (a, b, c, d, no_data, S11, 0x698098d8,8,15); /* 9 */
					FF2_SSE2 (d, a, b, c, no_data, S12, 0x8b44f7af,9,15); /* 10 */
					FF2_SSE2 (c, d, a, b, no_data, S13, 0xffff5bb1,10,15); /* 11 */
					FF2_SSE2 (b, c, d, a, no_data, S14, 0x895cd7be,11,15); /* 12 */
					FF2_SSE2 (a, b, c, d, no_data, S11, 0x6b901122,12,15); /* 13 */
					FF2_SSE2 (d, a, b, c, no_data, S12, 0xfd987193,13,15); /* 14 */
					//cout<<"d: "<<_mm_cvtsi128_si32(ds1)<<endl;
					FF2_SSE2 (c, d, a, b, len_data, S13, 0xa679438e,14,14); /* 15 */
					//cout<<"c: "<<_mm_cvtsi128_si32(cs1)<<endl;
					FF2_SSE2 (b, c, d, a, no_data, S14, 0x49b40821,15,15); /* 16 */

					/* Round 2 */
					GG2_SSE2 (a, b, c, d, 1, S21, 0xf61e2562,16,1); /* 17 */
					GG2_SSE2 (d, a, b, c, no_data, S22, 0xc040b340,17,15); /* 18 */
					GG2_SSE2 (c, d, a, b, no_data, S23, 0x265e5a51,18,15); /* 19 */
					GG2_SSE2 (b, c, d, a, 0, S24, 0xe9b6c7aa,19,0); /* 20 */
					GG2_SSE2 (a, b, c, d, no_data, S21, 0xd62f105d,20,15); /* 21 */
					GG2_SSE2 (d, a, b, c, no_data, S22,  0x2441453,21,15); /* 22 */
					GG2_SSE2 (c, d, a, b, no_data, S23, 0xd8a1e681,22,15); /* 23 */
					GG2_SSE2 (b, c, d, a, no_data, S24, 0xe7d3fbc8,23,15); /* 24 */
					GG2_SSE2 (a, b, c, d, no_data, S21, 0x21e1cde6,24,15); /* 25 */
					GG2_SSE2 (d, a, b, c, len_data, S22, 0xc33707d6,25,14); /* 26 */
					GG2_SSE2 (c, d, a, b, 3, S23, 0xf4d50d87,26,3); /* 27 */
					GG2_SSE2 (b, c, d, a, no_data, S24, 0x455a14ed,27,15); /* 28 */
					GG2_SSE2 (a, b, c, d, no_data, S21, 0xa9e3e905,28,15); /* 29 */
					GG2_SSE2 (d, a, b, c, 2, S22, 0xfcefa3f8,29,2); /* 30 */
					GG2_SSE2 (c, d, a, b, no_data, S23, 0x676f02d9,30,15); /* 31 */
					GG2_SSE2 (b, c, d, a, no_data, S24, 0x8d2a4c8a,31,15); /* 32 */

					/* Round 3 */
					HH2_SSE2 (a, b, c, d, no_data, S31, 0xfffa3942,32,15); /* 33 */
					HH2_SSE2 (d, a, b, c, no_data, S32, 0x8771f681,33,15); /* 34 */
					HH2_SSE2 (c, d, a, b, no_data, S33, 0x6d9d6122,34,15); /* 35 */
					HH2_SSE2 (b, c, d, a, len_data, S34, 0xfde5380c,35,14); /* 36 */
					HH2_SSE2 (a, b, c, d, 1, S31, 0xa4beea44,36,1); /* 37 */

					HH2_SSE2 (d, a, b, c, no_data, S32, 0x4bdecfa9,37,15); /* 38 */
					HH2_SSE2 (c, d, a, b, no_data, S33, 0xf6bb4b60,38,15); /* 39 */
					HH2_SSE2 (b, c, d, a, no_data, S34, 0xbebfbc70,39,15); /* 40 */
					HH2_SSE2 (a, b, c, d, no_data, S31, 0x289b7ec6,40,15); /* 41 */
					HH2_SSE2 (d, a, b, c, 0, S32, 0xeaa127fa,41,0); /* 42 */
					HH2_SSE2 (c, d, a, b, 3, S33, 0xd4ef3085,42,3); /* 43 */
					HH2_SSE2 (b, c, d, a, no_data, S34,  0x4881d05,43,15); /* 44 */
					HH2_SSE2 (a, b, c, d, no_data, S31, 0xd9d4d039,44,15); /* 45 */
					HH2_SSE2 (d, a, b, c, no_data, S32, 0xe6db99e5,45,15); /* 46 */

					if( _mm_movemask_epi8(_mm_cmpeq_epi32(ds1,tds1))
						==0)continue;//early check


					HH2_SSE2 (c, d, a, b, no_data, S33, 0x1fa27cf8,46,15); /* 47 */
					HH2_SSE2 (b, c, d, a, 2, S34, 0xc4ac5665,47,2); /* 48 */

					/* Round 4 */
					II2_SSE2 (a, b, c, d, 0, S41, 0xf4292244,48,0); /* 49 */

					int result_mask;
					result_mask =  _mm_movemask_epi8(		   
						_mm_and_si128(_mm_cmpeq_epi32(as1,tas1),
						_mm_and_si128(_mm_cmpeq_epi32(bs1,tbs1),
						_mm_and_si128(_mm_cmpeq_epi32(cs1,tcs1),_mm_cmpeq_epi32(ds1,tds1)))));

					if(result_mask&1)      {result[key_pos+3]=1;}
					if(result_mask&(1<<4)) {result[key_pos+2]=1;}
					if(result_mask&(1<<8)) {result[key_pos+1]=1;}
					if(result_mask&(1<<12)){result[key_pos+0]=1;}
				}
			}
		}
	}
	}
};


int main()
{
	algo *tmp = new algo_md5();
	unsigned int data1[1000];
	int data2[1000];

	((algo_md5*)tmp)->check_block_sse2(data1, 123, 124, 12*10, data2);
	((algo_md5*)tmp)->a();
}