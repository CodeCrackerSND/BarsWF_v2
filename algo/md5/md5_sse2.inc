#define N_SSE2_THREADS 3
// originaly was 3, 4 seems to work a bit better but only on one machine

// Get ride of not instructions source http://www.zorinaq.com/papers/md5-amd64.html
//#define F_SSE(x, y, z) (_mm_or_si128(_mm_and_si128(x,y), _mm_andnot_si128(x, z)))
#define F_SSE(x, y, z) (_mm_xor_si128(_mm_and_si128(_mm_xor_si128((y), (z)),x), z))

#define G_SSE(x, y, z) (_mm_or_si128(_mm_and_si128(x,z), _mm_andnot_si128(z, y)))
//#define G_SSE(x, y, z) (_mm_xor_si128(_mm_and_si128(_mm_xor_si128((x), (y)),z), y))

#define H_SSE(x, y, z) (_mm_xor_si128(_mm_xor_si128(x,y), z))
#define I_SSE(x, y, z) (_mm_xor_si128(y, _mm_or_si128(x,_mm_andnot_si128(z, CONST_MAX128))))

//#define FF(b, c, d) (d ^ (b & (c ^ d)))
//#define FG(b, c, d) FF (d, b, c)

// OLD CODE:
//#define ROTATE_LEFT_SSE(x, n) {__m128i tmp;tmp = _mm_srli_epi32(x, 32-n);x = _mm_slli_epi32(x, n);x = _mm_or_si128(x, tmp);};

//Optimization source code:
//https://github.com/krisprice/simd_md5/blob/master/simd_md5/md5_sse.h

// the left rotate n is an int
#define ROTATE_LEFT_SSE(x, n) (_mm_or_si128(_mm_slli_epi32(x, n), _mm_srli_epi32(x, 32-n)))

// _mm_roti_epi32 	XOP [1] 	ammintrin.h 	__m128i _mm_rot_epi32(__m128i, int)
// Better: __m128i _mm_roti_epi32(__m128i, int);
// Speed inprovement from 80 MH/s to 100 MH/s
// https://scc.ustc.edu.cn/zlsc/tc4600/intel/2015.1.133/compiler_c/GUID-2BE305F0-428A-4614-8D31-2ECD69518C9A.htm

// This will work only if rotate value n is divisible to 8
// Optimization source: https://hashcat.net/forum/thread-153.html
// rotate each 32 bit quantity by 16 bits
// 0xB1 = 10110001 = 2,3,0,1
#define ROTATE_LEFT_SHORT(x) (_mm_shufflehi_epi16(_mm_shufflelo_epi16(x, 0xB1), 0xB1))

#define set32(var, val) var = _mm_set_epi32(val,val,val,val);

// Visual Studio 2010 doesn't allow variable declaration in the middle of code:
#define DO_SSEOpt(step, a, b, c, d, x, s, ac) { \
int threadindx;for(threadindx=0;threadindx<N_SSE2_THREADS;threadindx++){ \
a[threadindx]=_mm_add_epi32(_mm_add_epi32(a[threadindx],_mm_add_epi32(get_data(threadindx, x),ac)),step##_SSE ((b[threadindx]), (c[threadindx]), (d[threadindx]))); \
	a[threadindx] = _mm_add_epi32(ROTATE_LEFT_SHORT(a[threadindx]),b[threadindx]);} \
}

#define DO_SSE(step, a, b, c, d, x, s, ac) { \
int threadindx;__m128i a_reg;for(threadindx=0;threadindx<N_SSE2_THREADS;threadindx++){ \
	a_reg = a[threadindx]; \
	a_reg=_mm_add_epi32(_mm_add_epi32(a_reg,_mm_add_epi32(get_data(threadindx, x),ac)),step##_SSE ((b[threadindx]), (c[threadindx]), (d[threadindx]))); \
	a[threadindx] = _mm_add_epi32(ROTATE_LEFT_SSE(a_reg, s),b[threadindx]);} \
}


#define DO_SSENoData(step, a, b, c, d, x, s, ac) { \
int threadindx;for(threadindx=0;threadindx<N_SSE2_THREADS;threadindx++){ \
a[threadindx]=_mm_add_epi32(a[threadindx],_mm_add_epi32(step##_SSE ((b[threadindx]), (c[threadindx]), (d[threadindx])),ac)); \
	a[threadindx] = _mm_add_epi32(ROTATE_LEFT_SSE(a[threadindx], s),b[threadindx]);} \
}


// #define S33 16
// Visual Studio 2010 doesn't allow variable declaration in the middle of code:
#define DO_SSE_UNROLL(step, a, b, c, d, x, s, ac) { \
int threadindx;for(threadindx=0;threadindx<N_SSE2_THREADS;threadindx++){a[threadindx] = _mm_sub_epi32(a[threadindx],b[threadindx]); \
	a[threadindx] = ROTATE_LEFT_SSE (a[threadindx], (32-(s))&31); \
	a[threadindx]=_mm_sub_epi32(a[threadindx],_mm_add_epi32(_mm_add_epi32(get_data(threadindx, x),step##_SSE ((b[threadindx]), (c[threadindx]), (d[threadindx]))),ac));} \
}

#define no_data 1000
#define len_data 333
//#define get_data(thread,pos) ((pos==no_data)?sse2_nodata:(pos==len_data)?sse2_lendata:(pos==0)?data[pos][thread]:data[pos][0])
#define get_data(thread,pos) ((pos==no_data)?sse2_nodata:(pos==len_data)?sse2_lendata:data[pos][thread])


// optimization 2 https://hashcat.net/events/p13/js-ocohaaaa.pdf

#define FF2_SSE2_first(a, b, c, d, x, s, ac, ic) { \
__m128i Const1; \
set32(Const1, 0xd76aa477); \
int threadindx;for(threadindx=0;threadindx<N_SSE2_THREADS;threadindx++){ \
	a[threadindx] = _mm_add_epi32(get_data(threadindx, x), Const1); \
	a[threadindx] = _mm_add_epi32(ROTATE_LEFT_SSE(a[threadindx], s),b[threadindx]);} \
}



//n pipe
#define FF2_SSE2(a, b, c, d, x, s, ac, ic) { DO_SSE(F,a,b,c,d,x,s,md5_const_sse2[ic]);}
#define GG2_SSE2(a, b, c, d, x, s, ac, ic) { DO_SSE(G,a,b,c,d,x,s,md5_const_sse2[ic]);}
#define HH2_SSE2(a, b, c, d, x, s, ac, ic) { DO_SSE(H,a,b,c,d,x,s,md5_const_sse2[ic]);}
#define II2_SSE2(a, b, c, d, x, s, ac, ic) { DO_SSE(I,a,b,c,d,x,s,md5_const_sse2[ic]);}
#define unrollII_SSE2(a, b, c, d, x, s, ac, ic) {DO_SSE_UNROLL(I,a,b,c,d,x,s,md5_const_sse2[ic]);}

#define HH2Opt_SSE2(a, b, c, d, x, s, ac, ic) { DO_SSEOpt(H,a,b,c,d,x,s,md5_const_sse2[ic]);}

#define FF2_SSE2NoData(a, b, c, d, x, s, ac, ic) { DO_SSENoData(F,a,b,c,d,x,s,md5_const_sse2[ic]);}

//1 pipe
//#define FF2_SSE2(a, b, c, d, x, s, ac, ic,id) { DO_SSE(F,a##s1,b##s1,c##s1,d##s1,get_data(0,x),s,md5_const_sse2[ic], id);}//DO_SSE(F,a##s2,b##s2,c##s2,d##s2,get_data(1,x),s,md5_const_sse2[ic], id);DO_SSE(F,a##s3,b##s3,c##s3,d##s3,get_data(2,x),s,md5_const_sse2[ic], id);}//DO_SSE(F,a##s4,b##s4,c##s4,d##s4,data.xs[id],s,md5_const_sse2[ic], id);}
//#define GG2_SSE2(a, b, c, d, x, s, ac, ic,id) { DO_SSE(G,a##s1,b##s1,c##s1,d##s1,get_data(0,x),s,md5_const_sse2[ic], id);}//DO_SSE(G,a##s2,b##s2,c##s2,d##s2,get_data(1,x),s,md5_const_sse2[ic], id);DO_SSE(G,a##s3,b##s3,c##s3,d##s3,get_data(2,x),s,md5_const_sse2[ic], id);}//DO_SSE(G,a##s4,b##s4,c##s4,d##s4,data.xs[id],s,md5_const_sse2[ic], id);}
//#define HH2_SSE2(a, b, c, d, x, s, ac, ic,id) { DO_SSE(H,a##s1,b##s1,c##s1,d##s1,get_data(0,x),s,md5_const_sse2[ic], id);}//DO_SSE(H,a##s2,b##s2,c##s2,d##s2,get_data(1,x),s,md5_const_sse2[ic], id);DO_SSE(H,a##s3,b##s3,c##s3,d##s3,get_data(2,x),s,md5_const_sse2[ic], id);}//DO_SSE(H,a##s4,b##s4,c##s4,d##s4,data.xs[id],s,md5_const_sse2[ic], id);}
//#define II2_SSE2(a, b, c, d, x, s, ac, ic,id) { DO_SSE(I,a##s1,b##s1,c##s1,d##s1,get_data(0,x),s,md5_const_sse2[ic], id);}//DO_SSE(I,a##s2,b##s2,c##s2,d##s2,get_data(1,x),s,md5_const_sse2[ic], id);DO_SSE(I,a##s3,b##s3,c##s3,d##s3,get_data(2,x),s,md5_const_sse2[ic], id);}//DO_SSE(I,a##s4,b##s4,c##s4,d##s4,data.xs[id],s,md5_const_sse2[ic], id);}
//#define unrollII_SSE2(a, b, c, d, x, s, ac, ic,id) {DO_SSE_UNROLL(I,a##s1,b##s1,c##s1,d##s1,get_data(0,x),s,md5_const_sse2[ic], id);}

//3 pipe
//#define FF2_SSE2(a, b, c, d, x, s, ac, ic,id) { DO_SSE(F,a##s1,b##s1,c##s1,d##s1,get_data(0,x),s,md5_const_sse2[ic], id);DO_SSE(F,a##s2,b##s2,c##s2,d##s2,get_data(1,x),s,md5_const_sse2[ic], id);DO_SSE(F,a##s3,b##s3,c##s3,d##s3,get_data(2,x),s,md5_const_sse2[ic], id);}//DO_SSE(F,a##s4,b##s4,c##s4,d##s4,data.xs[id],s,md5_const_sse2[ic], id);}
//#define GG2_SSE2(a, b, c, d, x, s, ac, ic,id) { DO_SSE(G,a##s1,b##s1,c##s1,d##s1,get_data(0,x),s,md5_const_sse2[ic], id);DO_SSE(G,a##s2,b##s2,c##s2,d##s2,get_data(1,x),s,md5_const_sse2[ic], id);DO_SSE(G,a##s3,b##s3,c##s3,d##s3,get_data(2,x),s,md5_const_sse2[ic], id);}//DO_SSE(G,a##s4,b##s4,c##s4,d##s4,data.xs[id],s,md5_const_sse2[ic], id);}
//#define HH2_SSE2(a, b, c, d, x, s, ac, ic,id) { DO_SSE(H,a##s1,b##s1,c##s1,d##s1,get_data(0,x),s,md5_const_sse2[ic], id);DO_SSE(H,a##s2,b##s2,c##s2,d##s2,get_data(1,x),s,md5_const_sse2[ic], id);DO_SSE(H,a##s3,b##s3,c##s3,d##s3,get_data(2,x),s,md5_const_sse2[ic], id);}//DO_SSE(H,a##s4,b##s4,c##s4,d##s4,data.xs[id],s,md5_const_sse2[ic], id);}
//#define II2_SSE2(a, b, c, d, x, s, ac, ic,id) { DO_SSE(I,a##s1,b##s1,c##s1,d##s1,get_data(0,x),s,md5_const_sse2[ic], id);DO_SSE(I,a##s2,b##s2,c##s2,d##s2,get_data(1,x),s,md5_const_sse2[ic], id);DO_SSE(I,a##s3,b##s3,c##s3,d##s3,get_data(2,x),s,md5_const_sse2[ic], id);}//DO_SSE(I,a##s4,b##s4,c##s4,d##s4,data.xs[id],s,md5_const_sse2[ic], id);}

//#define unrollII_SSE2(a, b, c, d, x, s, ac, ic,id) {DO_SSE_UNROLL(I,a##s1,b##s1,c##s1,d##s1,get_data(0,x),s,md5_const_sse2[ic], id);DO_SSE_UNROLL(I,a##s2,b##s2,c##s2,d##s2,get_data(1,x),s,md5_const_sse2[ic], id);DO_SSE_UNROLL(I,a##s3,b##s3,c##s3,d##s3,get_data(2,x),s,md5_const_sse2[ic], id);}

//#define UNROLL_TRICK_1(a, b, c, d, x, s, ac, ic,id){b=ROTATE_LEFT_SSE(b-c, 32-s)-x-ac;}
//#define UNROLL_TRICK_2(a, b, c, d, x, s, ac, ic,id){c=ROTATE_LEFT_SSE(c-d, 32-s)-x-ac;}
//#define DO_3_SSE2()(op,a, b, c, d, x, s, ac, ic,id) { op(a##s1,b##s1,c##s1,d##s1,get_data(0,x),s,md5_const_sse2[ic], id);op(a##s2,b##s2,c##s2,d##s2,get_data(1,x),s,md5_const_sse2[ic], id);op(a##s3,b##s3,c##s3,d##s3,get_data(2,x),s,md5_const_sse2[ic], id);}

inline void sse2_check_keys(unsigned int *data_d, int key_pos, int sse2_thread, int value)
{
	for(int sse2_key=0;sse2_key<4;sse2_key++)	
		md5_simple((data_d[(key_pos+sse2_thread*4+sse2_key)*4+0])&0xffff0000|value,
		data_d[(key_pos+sse2_thread*4+sse2_key)*4+1],
		data_d[(key_pos+sse2_thread*4+sse2_key)*4+2],
		data_d[(key_pos+sse2_thread*4+sse2_key)*4+3],
		perm::pwd_len8);
}

// MS Visual Studio decl-spec to force (necessary) alignment in memory
#define CACHE_LINE  64
#define CACHE_ALIGN __declspec(align(CACHE_LINE))
#define CNT 1000000

// Visual Studio 2010 doesn't allow variable declaration in the middle of code:
// NOT EVEN ON FOR LOOPS
__forceinline void check_block_sse2_inline(int key_pos, unsigned int *data_d, unsigned int pwd_len, int charset_len, int keys_per_thread, int* result)
{	

		//dump_sse2("MD5_Constants", md5_const_sse2[0]);

		// initial values:
		unsigned long int a1 = 0x67452301, b1 = 0xefcdab89, c1 = 0x98badcfe, d1 = 0x10325476;
		__m128i data[20][3], key;
		unsigned int value;//this is common part of key
		__m128i ta[20],tb[20],tc[20],td[20]; //init values are the same
		int sse2_thread;
		int i;
		int s4,s3,s2,s1;
		int res;
		__m128i tmp;
		int result_mask;
		__m128i a[20],b[20],c[20],d[20];//init values are the same

		for(sse2_thread=0;sse2_thread<N_SSE2_THREADS;sse2_thread++)
		{

			ta[sse2_thread]=target_sse[0];
			tb[sse2_thread]=target_sse[1];
			tc[sse2_thread]=target_sse[2];
			td[sse2_thread]=target_sse[3];

			for(i=0;i<4;i++)
			{
				data[i][sse2_thread] = _mm_set_epi32(
					data_d[(key_pos+sse2_thread*4+0)*4+i],
					data_d[(key_pos+sse2_thread*4+1)*4+i],
					data_d[(key_pos+sse2_thread*4+2)*4+i],
					data_d[(key_pos+sse2_thread*4+3)*4+i]);
			}
		}

		//dump_sse2("data0_t0", data[0][0]);
		//dump_sse2("data0_t1", data[0][1]);
			//Unroll known steps
/*			__m128i part_tas1,part_tbs1,part_tcs1,part_tds1,part_tas2,part_tbs2,part_tcs2,part_tds2,part_tas3,part_tbs3,part_tcs3,part_tds3;//init values are the same*/

/*			tas2=target_sse[0];tbs2=target_sse[1];tcs2=target_sse[2];tds2=target_sse[3];
			tas3=target_sse[0];tbs3=target_sse[1];tcs3=target_sse[2];tds3=target_sse[3];*/

			/*dump_sse2("a", target_sse[0]);
			dump_sse2("b", target_sse[1]);
			dump_sse2("c", target_sse[2]);
			dump_sse2("d", target_sse[3]);*/

			unrollII_SSE2(tc, td, ta, tb, 2      , S43, 0x2ad7d2bb,62); /* 63 */

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

			unrollII_SSE2(td, ta, tb, tc, no_data, S42, 0xbd3af235,61); /* 62 */
/*			dump_sse2("d", tds1);
			getch();*/

			unrollII_SSE2(ta, tb, tc, td, no_data, S41, 0xf7537e82,60); /* 61 */
			unrollII_SSE2(tb, tc, td, ta, no_data, S44, 0x4e0811a1,59); /* 60 */
			unrollII_SSE2(tc, td, ta, tb, no_data, S43, 0xa3014314,58); /* 59 */
			unrollII_SSE2(td, ta, tb, tc, no_data, S42, 0xfe2ce6e0,57); /* 58 */
			unrollII_SSE2(ta, tb, tc, td, no_data, S41, 0x6fa87e4f,56); /* 57 */
			unrollII_SSE2(tb, tc, td, ta, 1      , S44, 0x85845dd1,55); /* 56 */
			unrollII_SSE2(tc, td, ta, tb, no_data, S43, 0xffeff47d,54); /* 55 */
			unrollII_SSE2(td, ta, tb, tc, 3      , S42, 0x8f0ccc92,53); /* 54 */
			unrollII_SSE2(ta, tb, tc, td, no_data, S41, 0x655b59c3,52); /* 53 */
			unrollII_SSE2(tb, tc, td, ta, no_data, S44, 0xfc93a039,51); /* 52 */
			unrollII_SSE2(tc, td, ta, tb, len_data, S43, 0xab9423a7,50); /* 51 */
			unrollII_SSE2(td, ta, tb, tc, no_data, S42, 0x432aff97,49); /* 50 */

			//unrollII_SSE2(ta, tb, tc, td, no_data, S41, 0xf4292244,48); /* 49 partial, 0 data*/

			//do partial reverse
/*			part_tas1=tas1;
			part_tbs1=tbs1;
			part_tcs1=tcs1;
			part_tds1=tds1;
			part_tas2=tas2;
			part_tbs2=tbs2;
			part_tcs2=tcs2;
			part_tds2=tds2;
			part_tas3=tas3;
			part_tbs3=tbs3;
			part_tcs3=tcs3;
			part_tds3=tds3;

			unrollII_SSE2(part_ta, part_tb, part_tc, part_td, no_data, 6, 0xf4292244,49,15); 
			DO_3_SSE2(UNROLL_TRICK_1,part_ta, part_tb, part_tc, part_td, 2, 23,0,48,15);
			DO_3_SSE2(UNROLL_TRICK_2,part_ta, part_tb, part_tc, part_td, no_data, 16,0,47,15);*/

			for(s2=0;s2<charset_len;s2++)
			{
				value=(perm::charset[s2])<<8;
				for(s1=0;s1<charset_len;s1++)
				{
					value=(value&0x0000ff00)+(perm::charset[s1]);
					set32(key, value);

					// __m128i a[20],b[20],c[20],d[20];//init values are the same
					//set all keys to the lower 16 bits of every data part
					for(sse2_thread=0;sse2_thread<N_SSE2_THREADS;sse2_thread++)
					{
						data[0][sse2_thread]=_mm_or_si128(_mm_and_si128(data[0][sse2_thread], gpu_mask_2_128), key);
						set32(a[sse2_thread], a1);set32(b[sse2_thread], b1);set32(c[sse2_thread], c1);set32(d[sse2_thread], d1);
					}

					/* Round 1 */
					FF2_SSE2_first (a, b, c, d, 0, S11, 0xd76aa478,0); /* 1 */
					FF2_SSE2 (d, a, b, c, 1, S12, 0xe8c7b756,1); /* 2 */
					//cout<<"b: "<<_mm_cvtsi128_si32(bs1)<<endl;
					FF2_SSE2 (c, d, a, b, 2, S13, 0x242070db,2); /* 3 */
					//cout<<"c: "<<_mm_cvtsi128_si32(cs1)<<endl;
					FF2_SSE2 (b, c, d, a, 3, S14, 0xc1bdceee,3); /* 4 */


					//cout<<"d: "<<_mm_cvtsi128_si32(ds1)<<endl;
					FF2_SSE2 (a, b, c, d, no_data, S11, 0xf57c0faf,4); /* 5 */ //5th and so forth is 0
					//cout<<"a: "<<_mm_cvtsi128_si32(as1)<<endl;
					FF2_SSE2 (d, a, b, c, no_data, S12, 0x4787c62a,5); /* 6 */
					FF2_SSE2 (c, d, a, b, no_data, S13, 0xa8304613,6); /* 7 */
					FF2_SSE2 (b, c, d, a, no_data, S14, 0xfd469501,7); /* 8 */
					FF2_SSE2 (a, b, c, d, no_data, S11, 0x698098d8,8); /* 9 */
					FF2_SSE2 (d, a, b, c, no_data, S12, 0x8b44f7af,9); /* 10 */
					FF2_SSE2 (c, d, a, b, no_data, S13, 0xffff5bb1,10); /* 11 */
					FF2_SSE2 (b, c, d, a, no_data, S14, 0x895cd7be,11); /* 12 */
					FF2_SSE2 (a, b, c, d, no_data, S11, 0x6b901122,12); /* 13 */
					FF2_SSE2 (d, a, b, c, no_data, S12, 0xfd987193,13); /* 14 */
					//cout<<"d: "<<_mm_cvtsi128_si32(ds1)<<endl;
					FF2_SSE2 (c, d, a, b, len_data, S13, 0xa679438e,14); /* 15 */
					//cout<<"c: "<<_mm_cvtsi128_si32(cs1)<<endl;
					FF2_SSE2 (b, c, d, a, no_data, S14, 0x49b40821,15); /* 16 */

					/* Round 2 */
					GG2_SSE2 (a, b, c, d, 1, S21, 0xf61e2562,16); /* 17 */
					GG2_SSE2 (d, a, b, c, no_data, S22, 0xc040b340,17); /* 18 */
					GG2_SSE2 (c, d, a, b, no_data, S23, 0x265e5a51,18); /* 19 */
					GG2_SSE2 (b, c, d, a, 0, S24, 0xe9b6c7aa,19); /* 20 */
					GG2_SSE2 (a, b, c, d, no_data, S21, 0xd62f105d,20); /* 21 */
					GG2_SSE2 (d, a, b, c, no_data, S22,  0x2441453,21); /* 22 */
					GG2_SSE2 (c, d, a, b, no_data, S23, 0xd8a1e681,22); /* 23 */
					GG2_SSE2 (b, c, d, a, no_data, S24, 0xe7d3fbc8,23); /* 24 */
					GG2_SSE2 (a, b, c, d, no_data, S21, 0x21e1cde6,24); /* 25 */
					GG2_SSE2 (d, a, b, c, len_data, S22, 0xc33707d6,25); /* 26 */
					GG2_SSE2 (c, d, a, b, 3, S23, 0xf4d50d87,26); /* 27 */
					GG2_SSE2 (b, c, d, a, no_data, S24, 0x455a14ed,27); /* 28 */
					GG2_SSE2 (a, b, c, d, no_data, S21, 0xa9e3e905,28); /* 29 */
					GG2_SSE2 (d, a, b, c, 2, S22, 0xfcefa3f8,29); /* 30 */
					GG2_SSE2 (c, d, a, b, no_data, S23, 0x676f02d9,30); /* 31 */
					GG2_SSE2 (b, c, d, a, no_data, S24, 0x8d2a4c8a,31); /* 32 */

					/* Round 3 */
					HH2_SSE2 (a, b, c, d, no_data, S31, 0xfffa3942,32); /* 33 */
					HH2_SSE2 (d, a, b, c, no_data, S32, 0x8771f681,33); /* 34 */
					HH2Opt_SSE2 (c, d, a, b, no_data, S33, 0x6d9d6122,34); /* 35 */
					HH2_SSE2 (b, c, d, a, len_data, S34, 0xfde5380c,35); /* 36 */
					HH2_SSE2 (a, b, c, d, 1, S31, 0xa4beea44,36); /* 37 */
					HH2_SSE2 (d, a, b, c, no_data, S32, 0x4bdecfa9,37); /* 38 */
					HH2Opt_SSE2 (c, d, a, b, no_data, S33, 0xf6bb4b60,38); /* 39 */
					HH2_SSE2 (b, c, d, a, no_data, S34, 0xbebfbc70,39); /* 40 */
					HH2_SSE2 (a, b, c, d, no_data, S31, 0x289b7ec6,40); /* 41 */
					HH2_SSE2 (d, a, b, c, 0, S32, 0xeaa127fa,41); /* 42 */
					HH2Opt_SSE2 (c, d, a, b, 3, S33, 0xd4ef3085,42); /* 43 */
					HH2_SSE2 (b, c, d, a, no_data, S34,  0x4881d05,43); /* 44 */
					HH2_SSE2 (a, b, c, d, no_data, S31, 0xd9d4d039,44); /* 45 */
					HH2_SSE2 (d, a, b, c, no_data, S32, 0xe6db99e5,45); /* 46 */

					res = 0;
					tmp = _mm_cmpeq_epi32(d[0],td[0]);
					for(i=1;i<N_SSE2_THREADS;i++)
						tmp = _mm_or_si128(tmp, _mm_cmpeq_epi32(d[i],td[i]));
					if(_mm_movemask_epi8(tmp)==0)continue;//early check, nothing found
						
					/*if( _mm_movemask_epi8(
						_mm_or_si128(_mm_cmpeq_epi32(ds1,tds1),
						_mm_or_si128(_mm_cmpeq_epi32(ds2,tds2),
						_mm_cmpeq_epi32(ds3,tds3))))==0)continue;//early check
					*/	

					HH2Opt_SSE2 (c, d, a, b, no_data, S33, 0x1fa27cf8,46); /* 47 */
					HH2_SSE2 (b, c, d, a, 2, S34, 0xc4ac5665,47); /* 48 */

					/* Round 4 */
					II2_SSE2 (a, b, c, d, 0, S41, 0xf4292244,48); /* 49 */

					for(i=0;i<N_SSE2_THREADS;i++)
					{

						result_mask =  _mm_movemask_epi8(		   
							_mm_and_si128(_mm_cmpeq_epi32(a[i],ta[i]),//reva
							_mm_and_si128(_mm_cmpeq_epi32(b[i],tb[i]),
							_mm_and_si128(_mm_cmpeq_epi32(c[i],tc[i]),_mm_cmpeq_epi32(d[i],td[i])))));

						if(result_mask&1)      {result[key_pos+3+4*i]=KEY_FOUND;}
						if(result_mask&(1<<4)) {result[key_pos+2+4*i]=KEY_FOUND;}
						if(result_mask&(1<<8)) {result[key_pos+1+4*i]=KEY_FOUND;}
						if(result_mask&(1<<12)){result[key_pos+0+4*i]=KEY_FOUND;}
					}

				}
			}
}

__inline void check_block_sse2(unsigned int *data_d, unsigned int pwd_len, int charset_len, int keys_per_thread, int* result)
{

//#pragma unroll (3)
//#pragma distribute point
	for(int key_pos=0;key_pos<keys_per_thread;key_pos+=N_SSE2_THREADS*4)
	{
		check_block_sse2_inline(key_pos, data_d, pwd_len, charset_len, keys_per_thread, result);
	}
}