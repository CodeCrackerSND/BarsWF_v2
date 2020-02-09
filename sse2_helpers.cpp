#include "global.h"
#include "sse2_helpers.h"

void dump_sse2(string title, __m128i &val)
{
	Poco::ScopedLock<Poco::FastMutex> lock(g->console_mutex);

	cout<<title<<" : ";
	cout<<std::hex<<_mm_cvtsi128_si32(_mm_srli_si128(val,0))<<",";
	cout<<std::hex<<_mm_cvtsi128_si32(_mm_srli_si128(val,4))<<",";
	cout<<std::hex<<_mm_cvtsi128_si32(_mm_srli_si128(val,8))<<",";
	cout<<std::hex<<_mm_cvtsi128_si32(_mm_srli_si128(val,12))<<endl;
}
