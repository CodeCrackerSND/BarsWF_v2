#pragma once
#include <string>
#include <iostream>
#include <mmintrin.h>
#include <emmintrin.h>
//#include <boost/cstdint.hpp>
using namespace std;

#define set32(var, val) var = _mm_set_epi32(val,val,val,val);
//#define ROTATE_LEFT_SSE(x, n) {__m128i tmp;tmp = _mm_srli_epi32(x, 32-n);x = _mm_slli_epi32(x, n);x = _mm_or_si128(x, tmp);};

//Optimization source code:
//https://github.com/krisprice/simd_md5/blob/master/simd_md5/md5_sse.h
//#define ROTATE_LEFT_SSE(x, n) {x = _mm_or_si128(_mm_slli_epi32(x, n), _mm_srli_epi32(x, 32-n));};

void dump_sse2(string title, __m128i &val);
