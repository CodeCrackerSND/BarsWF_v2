// md5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <assert.h>
#include <iostream>
#include <sstream>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;


typedef unsigned char 		hl_uint8;
typedef unsigned short int 	hl_uint16;
typedef unsigned long int 	hl_uint32;
typedef unsigned long long int	hl_uint64;

typedef hl_uint8 *POINTER;

/** state (ABCD) */
unsigned long int state[4];   	      
int target[4] = {0xb182b498, 0xf4d2ac41, 0x1f636569, 0xaf4caf00};
unsigned long int num_ok = 0;

/** number of bits, modulo 2^64 (lsb first) */
unsigned long int bit_count;

/** input buffer */
union encode_data
{
	unsigned char c_buffer[64];
	unsigned int x[16];

} data;

// Constants for MD5Transform routine.
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

/* F, G, H and I are basic MD5 functions. */
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

/*
 * ROTATE_LEFT rotates x left n bits. 
 * cast to unsigned int to guarantee support for 64Bit System
 */
#define ROTATE_LEFT(x, n) (((x) << (n)) | (( (unsigned int) x) >> (32-(n))))

/*
FF, GG, HH, and II transformations for rounds 1, 2, 3, and 4.
Rotation is separate from addition to prevent recomputation.
*/
#define FF(a, b, c, d, x, s, ac) { \
 (a) += F ((b), (c), (d)) + (x) + (unsigned long int)(ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
  }

#define GG(a, b, c, d, x, s, ac) { \
 (a) += G ((b), (c), (d)) + (x) + (unsigned long int)(ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
  }
#define HH(a, b, c, d, x, s, ac) { \
 (a) += H ((b), (c), (d)) + (x) + (unsigned long int)(ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
  }
#define II(a, b, c, d, x, s, ac) { \
 (a) += I ((b), (c), (d)) + (x) + (unsigned long int)(ac); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) += (b); \
  }
#define unrollII(a, b, c, d, x, s, ac) { \
 (a) -= (b); \
 (a) = ROTATE_LEFT ((a), (s)); \
 (a) -= I ((b), (c), (d)) + (x) + (unsigned long int)(ac); \
  }

//----------------------------------------------------------------------	
//private member-functions

/**
 *  @brief 	Basic transformation. Transforms state based on block.
 *  @param	state	state to transform
 *  @param	block	block to transform
 */  
inline bool MD5Transform ()
{
	unsigned long int a = 0x67452301, b = 0xefcdab89, c = 0x98badcfe, d = 0x10325476;

	/* Round 1 */
	FF (a, b, c, d, data.x[ 0], S11, 0xd76aa478); /* 1 */
	FF (d, a, b, c, data.x[ 1], S12, 0xe8c7b756); /* 2 */
	FF (c, d, a, b, data.x[ 2], S13, 0x242070db); /* 3 */
	FF (b, c, d, a, data.x[ 3], S14, 0xc1bdceee); /* 4 */
	
	FF (a, b, c, d, 0, S11, 0xf57c0faf); /* 5 */
	FF (d, a, b, c, 0, S12, 0x4787c62a); /* 6 */
	
	FF (c, d, a, b, 0, S13, 0xa8304613); /* 7 */
	FF (b, c, d, a, 0, S14, 0xfd469501); /* 8 */
	FF (a, b, c, d, 0, S11, 0x698098d8); /* 9 */
	FF (d, a, b, c, 0, S12, 0x8b44f7af); /* 10 */
	FF (c, d, a, b, 0, S13, 0xffff5bb1); /* 11 */
	FF (b, c, d, a, 0, S14, 0x895cd7be); /* 12 */
	FF (a, b, c, d, 0, S11, 0x6b901122); /* 13 */
	FF (d, a, b, c, 0, S12, 0xfd987193); /* 14 */
	FF (c, d, a, b, 96, S13, 0xa679438e); /* 15 */
	FF (b, c, d, a, 0, S14, 0x49b40821); /* 16 */

	/* Round 2 */
	GG (a, b, c, d, data.x[ 1], S21, 0xf61e2562); /* 17 */
	GG (d, a, b, c, 0, S22, 0xc040b340); /* 18 */
	GG (c, d, a, b, 0, S23, 0x265e5a51); /* 19 */
	GG (b, c, d, a, data.x[ 0], S24, 0xe9b6c7aa); /* 20 */
	GG (a, b, c, d, 0, S21, 0xd62f105d); /* 21 */
	GG (d, a, b, c, 0, S22,  0x2441453); /* 22 */
	GG (c, d, a, b, 0, S23, 0xd8a1e681); /* 23 */
	GG (b, c, d, a, 0, S24, 0xe7d3fbc8); /* 24 */
	GG (a, b, c, d, 0, S21, 0x21e1cde6); /* 25 */
	GG (d, a, b, c, 96, S22, 0xc33707d6); /* 26 */
	GG (c, d, a, b, data.x[ 3], S23, 0xf4d50d87); /* 27 */

	GG (b, c, d, a, 0, S24, 0x455a14ed); /* 28 */
	GG (a, b, c, d, 0, S21, 0xa9e3e905); /* 29 */
	GG (d, a, b, c, data.x[ 2], S22, 0xfcefa3f8); /* 30 */
	GG (c, d, a, b, 0, S23, 0x676f02d9); /* 31 */
	GG (b, c, d, a, 0, S24, 0x8d2a4c8a); /* 32 */

	/* Round 3 */
	HH (a, b, c, d, 0, S31, 0xfffa3942); /* 33 */
	HH (d, a, b, c, 0, S32, 0x8771f681); /* 34 */
	HH (c, d, a, b, 0, S33, 0x6d9d6122); /* 35 */
	HH (b, c, d, a, 96, S34, 0xfde5380c); /* 36 */
	HH (a, b, c, d, data.x[ 1], S31, 0xa4beea44); /* 37 */
	HH (d, a, b, c, 0, S32, 0x4bdecfa9); /* 38 */
	HH (c, d, a, b, 0, S33, 0xf6bb4b60); /* 39 */
	HH (b, c, d, a, 0, S34, 0xbebfbc70); /* 40 */
	HH (a, b, c, d, 0, S31, 0x289b7ec6); /* 41 */
	HH (d, a, b, c, data.x[ 0], S32, 0xeaa127fa); /* 42 */
	HH (c, d, a, b, data.x[ 3], S33, 0xd4ef3085); /* 43 */
	HH (b, c, d, a, 0, S34,  0x4881d05); /* 44 */
	HH (a, b, c, d, 0, S31, 0xd9d4d039); /* 45 */
	HH (d, a, b, c, 0, S32, 0xe6db99e5); /* 46 */
	HH (c, d, a, b, 0, S33, 0x1fa27cf8); /* 47 */
	HH (b, c, d, a, data.x[ 2], S34, 0xc4ac5665); /* 48 */

	/* Round 4 */
	II (a, b, c, d, data.x[ 0], S41, 0xf4292244); /* 49 */
	II (d, a, b, c, 0, S42, 0x432aff97); /* 50 */
	II (c, d, a, b, 96, S43, 0xab9423a7); /* 51 */
	II (b, c, d, a, 0, S44, 0xfc93a039); /* 52 */
	II (a, b, c, d, 0, S41, 0x655b59c3); /* 53 */
	II (d, a, b, c, data.x[ 3], S42, 0x8f0ccc92); /* 54 */
	II (c, d, a, b, 0, S43, 0xffeff47d); /* 55 */
	II (b, c, d, a, data.x[ 1], S44, 0x85845dd1); /* 56 */
	II (a, b, c, d, 0, S41, 0x6fa87e4f); /* 57 */
	II (d, a, b, c, 0, S42, 0xfe2ce6e0); /* 58 */
	II (c, d, a, b, 0, S43, 0xa3014314); /* 59 */
	II (b, c, d, a, 0, S44, 0x4e0811a1); /* 60 */
	II (a, b, c, d, 0, S41, 0xf7537e82); /* 61 */
	//early a check, as a is finalized here
	if(a != target[0])return false;//hash incorrect
	II (d, a, b, c, 0, S42, 0xbd3af235); /* 62 */
	II (c, d, a, b, data.x[ 2], S43, 0x2ad7d2bb); /* 63 */
//	II (b, c, d, a, 0, S44, 0xeb86d391); /* 64 */ - this step was unrolled

	if( b == target[1] &&
	    c == target[2] &&
	    d == target[3]
	   )num_ok++;

}

std::string printHash(unsigned char *bytes)
{
	std::ostringstream os;
	for(int i=0; i<16; ++i)
	{
		os.width(2);
		os.fill('0');
		os << std::hex << static_cast<unsigned int>(bytes[i]);
	}
	return os.str();
}



int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int time = GetTickCount();
	unsigned char pass[] = "Testpasswor";
	unsigned char buff[16] = "";	
	strcpy((char*)data.c_buffer, (char*)pass);
	data.c_buffer[strlen((char*)pass)]=0x80;
	data.c_buffer[56]=strlen((char*)pass)*8;
	//unroll last addition
	target[0]-=0x67452301;
	target[1]-=0xefcdab89;
	target[2]-=0x98badcfe;
	target[3]-=0x10325476;
	//unroll step 64
	unrollII (target[1], target[2], target[3], target[0], 0, 32-S44, 0xeb86d391); /* 64 */

	//do the math

	for(int i=0;i<50000000;i++)
	{
		MD5Transform ();
	}
	printf("Speed: %3.3f Mh/s", 50000000.0/(GetTickCount()-time)/1000.0);
	string res = printHash((unsigned char *)state);
/*	if(res == "98b482b141acd2f46965631f00af4caf")
		cout<<"Hash correct!";else cout<<"Hash incorrect :-[";*/
	cout<<endl<<"Num of correct hashes: "<<num_ok<<endl;
	getch();
	return 0;
}

