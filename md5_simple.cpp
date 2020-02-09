//this code checks for 1 key only. Dumb and simple
#include "global.h"
#include "algo/md5/md5.h"


bool md5_simple(unsigned int k0,unsigned int k1,unsigned int k2,unsigned int k3,unsigned int len)
{
	unsigned int a,b,c,d;
	a=0x67452301;b=0xefcdab89;c=0x98badcfe;d=0x10325476;

	/* Round 1 */
	FF2 (a, b, c, d, k0, S11, 0xd76aa478,0,0); /* 1 */

	FF2 (d, a, b, c, k1, S12, 0xe8c7b756,1,1); /* 2 */
	FF2 (c, d, a, b, k2, S13, 0x242070db,2,2); /* 3 */
	FF2 (b, c, d, a, k3, S14, 0xc1bdceee,3,3); /* 4 */


	FF2 (a, b, c, d, 0, S11, 0xf57c0faf,4,15); /* 5 */ //5th and so forth is 0
	FF2 (d, a, b, c, 0, S12, 0x4787c62a,5,15); /* 6 */
	FF2 (c, d, a, b, 0, S13, 0xa8304613,6,15); /* 7 */
	FF2 (b, c, d, a, 0, S14, 0xfd469501,7,15); /* 8 */
	FF2 (a, b, c, d, 0, S11, 0x698098d8,8,15); /* 9 */
	FF2 (d, a, b, c, 0, S12, 0x8b44f7af,9,15); /* 10 */
	FF2 (c, d, a, b, 0, S13, 0xffff5bb1,10,15); /* 11 */
	FF2 (b, c, d, a, 0, S14, 0x895cd7be,11,15); /* 12 */
	FF2 (a, b, c, d, 0, S11, 0x6b901122,12,15); /* 13 */
	FF2 (d, a, b, c, 0, S12, 0xfd987193,13,15); /* 14 */
	FF2 (c, d, a, b, len, S13, 0xa679438e,14,14); /* 15 */
	FF2 (b, c, d, a, 0, S14, 0x49b40821,15,15); /* 16 */

	/* Round 2 */
	GG2 (a, b, c, d, k1, S21, 0xf61e2562,16,1); /* 17 */
	GG2 (d, a, b, c, 0, S22, 0xc040b340,17,15); /* 18 */
	GG2 (c, d, a, b, 0, S23, 0x265e5a51,18,15); /* 19 */
	GG2 (b, c, d, a, k0, S24, 0xe9b6c7aa,19,0); /* 20 */
	GG2 (a, b, c, d, 0, S21, 0xd62f105d,20,15); /* 21 */
	GG2 (d, a, b, c, 0, S22,  0x2441453,21,15); /* 22 */
	GG2 (c, d, a, b, 0, S23, 0xd8a1e681,22,15); /* 23 */
	GG2 (b, c, d, a, 0, S24, 0xe7d3fbc8,23,15); /* 24 */
	GG2 (a, b, c, d, 0, S21, 0x21e1cde6,24,15); /* 25 */
	GG2 (d, a, b, c, len, S22, 0xc33707d6,25,14); /* 26 */
	GG2 (c, d, a, b, k3, S23, 0xf4d50d87,26,3); /* 27 */
	GG2 (b, c, d, a, 0, S24, 0x455a14ed,27,15); /* 28 */
	GG2 (a, b, c, d, 0, S21, 0xa9e3e905,28,15); /* 29 */
	GG2 (d, a, b, c, k2, S22, 0xfcefa3f8,29,2); /* 30 */
	GG2 (c, d, a, b, 0, S23, 0x676f02d9,30,15); /* 31 */
	GG2 (b, c, d, a, 0, S24, 0x8d2a4c8a,31,15); /* 32 */

	/* Round 3 */
	HH2 (a, b, c, d, 0, S31, 0xfffa3942,32,15); /* 33 */
	HH2 (d, a, b, c, 0, S32, 0x8771f681,33,15); /* 34 */
	HH2 (c, d, a, b, 0, S33, 0x6d9d6122,34,15); /* 35 */
	HH2 (b, c, d, a, len, S34, 0xfde5380c,35,14); /* 36 */
	HH2 (a, b, c, d, k1, S31, 0xa4beea44,36,1); /* 37 */
	HH2 (d, a, b, c, 0, S32, 0x4bdecfa9,37,15); /* 38 */
	HH2 (c, d, a, b, 0, S33, 0xf6bb4b60,38,15); /* 39 */
	HH2 (b, c, d, a, 0, S34, 0xbebfbc70,39,15); /* 40 */
	HH2 (a, b, c, d, 0, S31, 0x289b7ec6,40,15); /* 41 */
	HH2 (d, a, b, c, k0, S32, 0xeaa127fa,41,0); /* 42 */
	HH2 (c, d, a, b, k3, S33, 0xd4ef3085,42,3); /* 43 */
	HH2 (b, c, d, a, 0, S34,  0x4881d05,43,15); /* 44 */
	HH2 (a, b, c, d, 0, S31, 0xd9d4d039,44,15); /* 45 */
	HH2 (d, a, b, c, 0, S32, 0xe6db99e5,45,15); /* 46 */
	HH2 (c, d, a, b, 0, S33, 0x1fa27cf8,46,15); /* 47 */
	HH2 (b, c, d, a, k2, S34, 0xc4ac5665,47,2); /* 48 */

	/* Round 4 */
	II2 (a, b, c, d, k0, S41, 0xf4292244,48,0); /* 49 */
	II2 (d, a, b, c, 0, S42, 0x432aff97,49,15); /* 50 */
	II2 (c, d, a, b, len, S43, 0xab9423a7,50,14); /* 51 */
	II2 (b, c, d, a, 0, S44, 0xfc93a039,51,15); /* 52 */
	II2 (a, b, c, d, 0, S41, 0x655b59c3,52,15); /* 53 */
	II2 (d, a, b, c, k3, S42, 0x8f0ccc92,53,3); /* 54 */
	II2 (c, d, a, b, 0, S43, 0xffeff47d,54,15); /* 55 */
	II2 (b, c, d, a, k1, S44, 0x85845dd1,55,1); /* 56 */
	II2 (a, b, c, d, 0, S41, 0x6fa87e4f,56,15); /* 57 */
	II2 (d, a, b, c, 0, S42, 0xfe2ce6e0,57,15); /* 58 */
	II2 (c, d, a, b, 0, S43, 0xa3014314,58,15); /* 59 */
	II2 (b, c, d, a, 0, S44, 0x4e0811a1,59,15); /* 60 */
	if(b!=g->hash_i[1])return false;
	II2 (a, b, c, d, 0, S41, 0xf7537e82,60,15); /* 61 */
	II2 (d, a, b, c, 0, S42, 0xbd3af235,61,15); /* 62 */
	II2 (c, d, a, b, k2, S43, 0x2ad7d2bb,62,2); /* 63 */

	if(a==g->hash_i[0] && c==g->hash_i[2] && d==g->hash_i[3])
	{
		g->final_key[0] = k0;
		g->final_key[1] = k1;
		g->final_key[2] = k2;
		g->final_key[3] = k3;
		g->final_len = len;
		g->is_finished = true;
		g->is_key_found = true;
		return true;
	};
	return false;
}