#line 1 "c:/my/work/BarsWF/algo/md5/md5_kernel.cu"
#line 156 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\crtdefs.h"
#pragma pack ( push, 8 )
#line 32 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\vadefs.h"
#pragma pack ( push, 8 )
#line 50 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\vadefs.h"
extern "C" { typedef unsigned __int64 uintptr_t; }
#line 61 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\vadefs.h"
extern "C" { typedef char *va_list; }
#line 125 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\vadefs.h"
extern "C" { extern void __cdecl __va_start(va_list *, ...); } 
#line 151 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\vadefs.h"
#pragma pack ( pop )
#line 476 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\crtdefs.h"
typedef unsigned __int64 size_t; 
#include "crt/host_runtime.h"
#line 485 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\crtdefs.h"
extern "C" { typedef size_t rsize_t; }
#line 492 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\crtdefs.h"
extern "C" { typedef __int64 intptr_t; }
#line 510 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\crtdefs.h"
extern "C" { typedef __int64 ptrdiff_t; }
#line 523 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\crtdefs.h"
extern "C" { typedef unsigned short wint_t; }
extern "C" { typedef unsigned short wctype_t; }
#line 548 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\crtdefs.h"
extern "C" { typedef int errcode; }
#line 553 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\crtdefs.h"
extern "C" { typedef int errno_t; }
#line 557 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\crtdefs.h"
extern "C" { typedef long __time32_t; }
#line 562 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\crtdefs.h"
extern "C" { typedef __int64 __time64_t; }
#line 570 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\crtdefs.h"
extern "C" { typedef __time64_t time_t; }
#line 2025 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\crtdefs.h"
struct threadlocaleinfostruct; 
struct threadmbcinfostruct; 
extern "C" { typedef threadlocaleinfostruct *pthreadlocinfo; }
extern "C" { typedef threadmbcinfostruct *pthreadmbcinfo; }
struct __lc_time_data; 
#line 2035
extern "C" { typedef 
#line 2031
struct localeinfo_struct { 

pthreadlocinfo locinfo; 
pthreadmbcinfo mbcinfo; 
} _locale_tstruct; }extern "C" { typedef localeinfo_struct *_locale_t; }
#line 2042
extern "C" { typedef 
#line 2038
struct tagLC_ID { 
unsigned short wLanguage; 
unsigned short wCountry; 
unsigned short wCodePage; 
} LC_ID; }extern "C" { typedef tagLC_ID *LPLC_ID; }
#line 2071 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\crtdefs.h"
extern "C" { typedef 
#line 2047
struct threadlocaleinfostruct { 
int refcount; 
unsigned lc_codepage; 
unsigned lc_collate_cp; 
unsigned long lc_handle[6]; 
LC_ID lc_id[6]; 
struct { 
char *locale; 
__wchar_t *wlocale; 
int *refcount; 
int *wrefcount; 
} lc_category[6]; 
int lc_clike; 
int mb_cur_max; 
int *lconv_intl_refcount; 
int *lconv_num_refcount; 
int *lconv_mon_refcount; 
struct lconv *lconv; 
int *ctype1_refcount; 
unsigned short *ctype1; 
const unsigned short *pctype; 
const unsigned char *pclmap; 
const unsigned char *pcumap; 
__lc_time_data *lc_time_curr; 
} threadlocinfo; }
#line 2109 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\crtdefs.h"
#pragma pack ( pop )
#line 46 "d:\\my\\work\\cuda\\64\\tk\\include\\device_types.h"
#if 0
#line 46
enum cudaRoundMode { 

cudaRoundNearest, 
cudaRoundZero, 
cudaRoundPosInf, 
cudaRoundMinInf
}; 
#endif
#line 41 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stddef.h"
extern "C" { extern int *__cdecl _errno(); } 


extern "C" { extern errno_t __cdecl _set_errno(int); } 
extern "C" { extern errno_t __cdecl _get_errno(int *); } 
#line 68 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stddef.h"
extern "C" { extern unsigned long __cdecl __threadid(); } 

extern "C" { extern uintptr_t __cdecl __threadhandle(); } 
#line 91 "d:\\my\\work\\cuda\\64\\tk\\include\\driver_types.h"
#if 0
#line 91
enum cudaError { 

cudaSuccess, 
cudaErrorMissingConfiguration, 
cudaErrorMemoryAllocation, 
cudaErrorInitializationError, 
cudaErrorLaunchFailure, 
cudaErrorPriorLaunchFailure, 
cudaErrorLaunchTimeout, 
cudaErrorLaunchOutOfResources, 
cudaErrorInvalidDeviceFunction, 
cudaErrorInvalidConfiguration, 
cudaErrorInvalidDevice, 
cudaErrorInvalidValue, 
cudaErrorInvalidPitchValue, 
cudaErrorInvalidSymbol, 
cudaErrorMapBufferObjectFailed, 
cudaErrorUnmapBufferObjectFailed, 
cudaErrorInvalidHostPointer, 
cudaErrorInvalidDevicePointer, 
cudaErrorInvalidTexture, 
cudaErrorInvalidTextureBinding, 
cudaErrorInvalidChannelDescriptor, 
cudaErrorInvalidMemcpyDirection, 
cudaErrorAddressOfConstant, 
cudaErrorTextureFetchFailed, 
cudaErrorTextureNotBound, 
cudaErrorSynchronizationError, 
cudaErrorInvalidFilterSetting, 
cudaErrorInvalidNormSetting, 
cudaErrorMixedDeviceExecution, 
cudaErrorCudartUnloading, 
cudaErrorUnknown, 
cudaErrorNotYetImplemented, 
cudaErrorMemoryValueTooLarge, 
cudaErrorInvalidResourceHandle, 
cudaErrorNotReady, 
cudaErrorInsufficientDriver, 
cudaErrorSetOnActiveProcess, 
cudaErrorNoDevice = 38, 
cudaErrorStartupFailure = 127, 
cudaErrorApiFailureBase = 10000
}; 
#endif
#line 139 "d:\\my\\work\\cuda\\64\\tk\\include\\driver_types.h"
#if 0
#line 139
enum cudaChannelFormatKind { 

cudaChannelFormatKindSigned, 
cudaChannelFormatKindUnsigned, 
cudaChannelFormatKindFloat, 
cudaChannelFormatKindNone
}; 
#endif
#line 151 "d:\\my\\work\\cuda\\64\\tk\\include\\driver_types.h"
#if 0
#line 151
struct cudaChannelFormatDesc { 

int x; 
int y; 
int z; 
int w; 
cudaChannelFormatKind f; 
}; 
#endif
#line 164 "d:\\my\\work\\cuda\\64\\tk\\include\\driver_types.h"
#if 0
struct cudaArray; 
#endif
#line 170 "d:\\my\\work\\cuda\\64\\tk\\include\\driver_types.h"
#if 0
#line 170
enum cudaMemcpyKind { 

cudaMemcpyHostToHost, 
cudaMemcpyHostToDevice, 
cudaMemcpyDeviceToHost, 
cudaMemcpyDeviceToDevice
}; 
#endif
#line 182 "d:\\my\\work\\cuda\\64\\tk\\include\\driver_types.h"
#if 0
#line 182
struct cudaPitchedPtr { 

void *ptr; 
size_t pitch; 
size_t xsize; 
size_t ysize; 
}; 
#endif
#line 194 "d:\\my\\work\\cuda\\64\\tk\\include\\driver_types.h"
#if 0
#line 194
struct cudaExtent { 

size_t width; 
size_t height; 
size_t depth; 
}; 
#endif
#line 205 "d:\\my\\work\\cuda\\64\\tk\\include\\driver_types.h"
#if 0
#line 205
struct cudaPos { 

size_t x; 
size_t y; 
size_t z; 
}; 
#endif
#line 216 "d:\\my\\work\\cuda\\64\\tk\\include\\driver_types.h"
#if 0
#line 216
struct cudaMemcpy3DParms { 

cudaArray *srcArray; 
cudaPos srcPos; 
cudaPitchedPtr srcPtr; 

cudaArray *dstArray; 
cudaPos dstPos; 
cudaPitchedPtr dstPtr; 

cudaExtent extent; 
cudaMemcpyKind kind; 
}; 
#endif
#line 234 "d:\\my\\work\\cuda\\64\\tk\\include\\driver_types.h"
#if 0
#line 234
struct cudaFuncAttributes { 

size_t sharedSizeBytes; 
size_t constSizeBytes; 
size_t localSizeBytes; 
int maxThreadsPerBlock; 
int numRegs; 
int __cudaReserved[8]; 
}; 
#endif
#line 248 "d:\\my\\work\\cuda\\64\\tk\\include\\driver_types.h"
#if 0
#line 248
enum cudaComputeMode { 

cudaComputeModeDefault, 
cudaComputeModeExclusive, 
cudaComputeModeProhibited
}; 
#endif
#line 260 "d:\\my\\work\\cuda\\64\\tk\\include\\driver_types.h"
#if 0
#line 260
struct cudaDeviceProp { 

char name[256]; 
size_t totalGlobalMem; 
size_t sharedMemPerBlock; 
int regsPerBlock; 
int warpSize; 
size_t memPitch; 
int maxThreadsPerBlock; 
int maxThreadsDim[3]; 
int maxGridSize[3]; 
int clockRate; 
size_t totalConstMem; 
int major; 
int minor; 
size_t textureAlignment; 
int deviceOverlap; 
int multiProcessorCount; 
int kernelExecTimeoutEnabled; 
int integrated; 
int canMapHostMemory; 
int computeMode; 
int __cudaReserved[36]; 
}; 
#endif
#line 319 "d:\\my\\work\\cuda\\64\\tk\\include\\driver_types.h"
#if 0
typedef cudaError 
#line 319
cudaError_t; 
#endif
#line 325 "d:\\my\\work\\cuda\\64\\tk\\include\\driver_types.h"
#if 0
typedef int 
#line 325
cudaStream_t; 
#endif
#line 331 "d:\\my\\work\\cuda\\64\\tk\\include\\driver_types.h"
#if 0
typedef int 
#line 331
cudaEvent_t; 
#endif
#line 54 "d:\\my\\work\\cuda\\64\\tk\\include\\texture_types.h"
#if 0
#line 54
enum cudaTextureAddressMode { 

cudaAddressModeWrap, 
cudaAddressModeClamp
}; 
#endif
#line 61 "d:\\my\\work\\cuda\\64\\tk\\include\\texture_types.h"
#if 0
#line 61
enum cudaTextureFilterMode { 

cudaFilterModePoint, 
cudaFilterModeLinear
}; 
#endif
#line 68 "d:\\my\\work\\cuda\\64\\tk\\include\\texture_types.h"
#if 0
#line 68
enum cudaTextureReadMode { 

cudaReadModeElementType, 
cudaReadModeNormalizedFloat
}; 
#endif
#line 75 "d:\\my\\work\\cuda\\64\\tk\\include\\texture_types.h"
#if 0
#line 75
struct textureReference { 

int normalized; 
cudaTextureFilterMode filterMode; 
cudaTextureAddressMode addressMode[3]; 
cudaChannelFormatDesc channelDesc; 
int __cudaReserved[16]; 
}; 
#endif
#line 82 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 82
struct char1 { 

signed char x; 

}; 
#endif
#line 89 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 89
struct uchar1 { 

unsigned char x; 

}; 
#endif
#line 96 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 96
struct __declspec(align(2)) char2 { 

signed char x; signed char y; 

}; 
#endif
#line 103 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 103
struct __declspec(align(2)) uchar2 { 

unsigned char x; unsigned char y; 

}; 
#endif
#line 110 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 110
struct char3 { 

signed char x; signed char y; signed char z; 

}; 
#endif
#line 117 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 117
struct uchar3 { 

unsigned char x; unsigned char y; unsigned char z; 

}; 
#endif
#line 124 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 124
struct __declspec(align(4)) char4 { 

signed char x; signed char y; signed char z; signed char w; 

}; 
#endif
#line 131 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 131
struct __declspec(align(4)) uchar4 { 

unsigned char x; unsigned char y; unsigned char z; unsigned char w; 

}; 
#endif
#line 138 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 138
struct short1 { 

short x; 

}; 
#endif
#line 145 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 145
struct ushort1 { 

unsigned short x; 

}; 
#endif
#line 152 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 152
struct __declspec(align(4)) short2 { 

short x; short y; 

}; 
#endif
#line 159 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 159
struct __declspec(align(4)) ushort2 { 

unsigned short x; unsigned short y; 

}; 
#endif
#line 166 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 166
struct short3 { 

short x; short y; short z; 

}; 
#endif
#line 173 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 173
struct ushort3 { 

unsigned short x; unsigned short y; unsigned short z; 

}; 
#endif
#line 180 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 180
struct __declspec(align(8)) short4 { short x; short y; short z; short w; }; 
#endif
#line 183 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 183
struct __declspec(align(8)) ushort4 { unsigned short x; unsigned short y; unsigned short z; unsigned short w; }; 
#endif
#line 186 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 186
struct int1 { 

int x; 

}; 
#endif
#line 193 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 193
struct uint1 { 

unsigned x; 

}; 
#endif
#line 200 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 200
struct __declspec(align(8)) int2 { int x; int y; }; 
#endif
#line 203 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 203
struct __declspec(align(8)) uint2 { unsigned x; unsigned y; }; 
#endif
#line 206 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 206
struct int3 { 

int x; int y; int z; 

}; 
#endif
#line 213 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 213
struct uint3 { 

unsigned x; unsigned y; unsigned z; 

}; 
#endif
#line 220 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 220
struct __declspec(align(16)) int4 { 

int x; int y; int z; int w; 

}; 
#endif
#line 227 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 227
struct __declspec(align(16)) uint4 { 

unsigned x; unsigned y; unsigned z; unsigned w; 

}; 
#endif
#line 234 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 234
struct long1 { 

long x; 

}; 
#endif
#line 241 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 241
struct ulong1 { 

unsigned long x; 

}; 
#endif
#line 250 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 250
struct __declspec(align(8)) long2 { long x; long y; }; 
#endif
#line 253 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 253
struct __declspec(align(8)) ulong2 { unsigned long x; unsigned long y; }; 
#endif
#line 276 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 276
struct long3 { 

long x; long y; long z; 

}; 
#endif
#line 283 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 283
struct ulong3 { 

unsigned long x; unsigned long y; unsigned long z; 

}; 
#endif
#line 290 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 290
struct __declspec(align(16)) long4 { 

long x; long y; long z; long w; 

}; 
#endif
#line 297 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 297
struct __declspec(align(16)) ulong4 { 

unsigned long x; unsigned long y; unsigned long z; unsigned long w; 

}; 
#endif
#line 306 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 306
struct float1 { 

float x; 

}; 
#endif
#line 313 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 313
struct __declspec(align(8)) float2 { float x; float y; }; 
#endif
#line 316 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 316
struct float3 { 

float x; float y; float z; 

}; 
#endif
#line 323 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 323
struct __declspec(align(16)) float4 { 

float x; float y; float z; float w; 

}; 
#endif
#line 330 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 330
struct longlong1 { 

__int64 x; 

}; 
#endif
#line 337 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 337
struct ulonglong1 { 

unsigned __int64 x; 

}; 
#endif
#line 344 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 344
struct __declspec(align(16)) longlong2 { 

__int64 x; __int64 y; 

}; 
#endif
#line 351 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 351
struct __declspec(align(16)) ulonglong2 { 

unsigned __int64 x; unsigned __int64 y; 

}; 
#endif
#line 358 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 358
struct double1 { 

double x; 

}; 
#endif
#line 365 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 365
struct __declspec(align(16)) double2 { 

double x; double y; 

}; 
#endif
#line 378 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef char1 
#line 378
char1; 
#endif
#line 380 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef uchar1 
#line 380
uchar1; 
#endif
#line 382 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef char2 
#line 382
char2; 
#endif
#line 384 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef uchar2 
#line 384
uchar2; 
#endif
#line 386 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef char3 
#line 386
char3; 
#endif
#line 388 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef uchar3 
#line 388
uchar3; 
#endif
#line 390 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef char4 
#line 390
char4; 
#endif
#line 392 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef uchar4 
#line 392
uchar4; 
#endif
#line 394 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef short1 
#line 394
short1; 
#endif
#line 396 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef ushort1 
#line 396
ushort1; 
#endif
#line 398 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef short2 
#line 398
short2; 
#endif
#line 400 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef ushort2 
#line 400
ushort2; 
#endif
#line 402 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef short3 
#line 402
short3; 
#endif
#line 404 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef ushort3 
#line 404
ushort3; 
#endif
#line 406 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef short4 
#line 406
short4; 
#endif
#line 408 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef ushort4 
#line 408
ushort4; 
#endif
#line 410 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef int1 
#line 410
int1; 
#endif
#line 412 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef uint1 
#line 412
uint1; 
#endif
#line 414 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef int2 
#line 414
int2; 
#endif
#line 416 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef uint2 
#line 416
uint2; 
#endif
#line 418 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef int3 
#line 418
int3; 
#endif
#line 420 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef uint3 
#line 420
uint3; 
#endif
#line 422 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef int4 
#line 422
int4; 
#endif
#line 424 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef uint4 
#line 424
uint4; 
#endif
#line 426 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef long1 
#line 426
long1; 
#endif
#line 428 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef ulong1 
#line 428
ulong1; 
#endif
#line 430 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef long2 
#line 430
long2; 
#endif
#line 432 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef ulong2 
#line 432
ulong2; 
#endif
#line 434 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef long3 
#line 434
long3; 
#endif
#line 436 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef ulong3 
#line 436
ulong3; 
#endif
#line 438 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef long4 
#line 438
long4; 
#endif
#line 440 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef ulong4 
#line 440
ulong4; 
#endif
#line 442 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef float1 
#line 442
float1; 
#endif
#line 444 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef float2 
#line 444
float2; 
#endif
#line 446 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef float3 
#line 446
float3; 
#endif
#line 448 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef float4 
#line 448
float4; 
#endif
#line 450 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef longlong1 
#line 450
longlong1; 
#endif
#line 452 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef ulonglong1 
#line 452
ulonglong1; 
#endif
#line 454 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef longlong2 
#line 454
longlong2; 
#endif
#line 456 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef ulonglong2 
#line 456
ulonglong2; 
#endif
#line 458 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef double1 
#line 458
double1; 
#endif
#line 460 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef double2 
#line 460
double2; 
#endif
#line 469 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
#line 469
struct dim3 { 

unsigned x; unsigned y; unsigned z; 
#line 477 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
}; 
#endif
#line 480 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_types.h"
#if 0
typedef dim3 
#line 480
dim3; 
#endif
#line 89 "d:\\my\\work\\cuda\\64\\tk\\include\\cuda_runtime_api.h"
extern "C" { extern cudaError_t __stdcall cudaMalloc3D(cudaPitchedPtr *, cudaExtent); } 
extern "C" { extern cudaError_t __stdcall cudaMalloc3DArray(cudaArray **, const cudaChannelFormatDesc *, cudaExtent); } 
extern "C" { extern cudaError_t __stdcall cudaMemset3D(cudaPitchedPtr, int, cudaExtent); } 
extern "C" { extern cudaError_t __stdcall cudaMemcpy3D(const cudaMemcpy3DParms *); } 
extern "C" { extern cudaError_t __stdcall cudaMemcpy3DAsync(const cudaMemcpy3DParms *, cudaStream_t); } 
#line 102
extern "C" { extern cudaError_t __stdcall cudaMalloc(void **, size_t); } 
extern "C" { extern cudaError_t __stdcall cudaMallocHost(void **, size_t); } 
extern "C" { extern cudaError_t __stdcall cudaMallocPitch(void **, size_t *, size_t, size_t); } 
extern "C" { extern cudaError_t __stdcall cudaMallocArray(cudaArray **, const cudaChannelFormatDesc *, size_t, size_t = (1)); } 
extern "C" { extern cudaError_t __stdcall cudaFree(void *); } 
extern "C" { extern cudaError_t __stdcall cudaFreeHost(void *); } 
extern "C" { extern cudaError_t __stdcall cudaFreeArray(cudaArray *); } 

extern "C" { extern cudaError_t __stdcall cudaHostAlloc(void **, size_t, unsigned); } 
extern "C" { extern cudaError_t __stdcall cudaHostGetDevicePointer(void **, void *, unsigned); } 
extern "C" { extern cudaError_t __stdcall cudaHostGetFlags(unsigned *, void *); } 
#line 121
extern "C" { extern cudaError_t __stdcall cudaMemcpy(void *, const void *, size_t, cudaMemcpyKind); } 
extern "C" { extern cudaError_t __stdcall cudaMemcpyToArray(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind); } 
extern "C" { extern cudaError_t __stdcall cudaMemcpyFromArray(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind); } 
extern "C" { extern cudaError_t __stdcall cudaMemcpyArrayToArray(cudaArray *, size_t, size_t, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind = cudaMemcpyDeviceToDevice); } 
extern "C" { extern cudaError_t __stdcall cudaMemcpy2D(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind); } 
extern "C" { extern cudaError_t __stdcall cudaMemcpy2DToArray(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind); } 
extern "C" { extern cudaError_t __stdcall cudaMemcpy2DFromArray(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind); } 
extern "C" { extern cudaError_t __stdcall cudaMemcpy2DArrayToArray(cudaArray *, size_t, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind = cudaMemcpyDeviceToDevice); } 
extern "C" { extern cudaError_t __stdcall cudaMemcpyToSymbol(const char *, const void *, size_t, size_t = (0), cudaMemcpyKind = cudaMemcpyHostToDevice); } 
extern "C" { extern cudaError_t __stdcall cudaMemcpyFromSymbol(void *, const char *, size_t, size_t = (0), cudaMemcpyKind = cudaMemcpyDeviceToHost); } 
#line 138
extern "C" { extern cudaError_t __stdcall cudaMemcpyAsync(void *, const void *, size_t, cudaMemcpyKind, cudaStream_t); } 
extern "C" { extern cudaError_t __stdcall cudaMemcpyToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, cudaMemcpyKind, cudaStream_t); } 
extern "C" { extern cudaError_t __stdcall cudaMemcpyFromArrayAsync(void *, const cudaArray *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t); } 
extern "C" { extern cudaError_t __stdcall cudaMemcpy2DAsync(void *, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t); } 
extern "C" { extern cudaError_t __stdcall cudaMemcpy2DToArrayAsync(cudaArray *, size_t, size_t, const void *, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t); } 
extern "C" { extern cudaError_t __stdcall cudaMemcpy2DFromArrayAsync(void *, size_t, const cudaArray *, size_t, size_t, size_t, size_t, cudaMemcpyKind, cudaStream_t); } 
extern "C" { extern cudaError_t __stdcall cudaMemcpyToSymbolAsync(const char *, const void *, size_t, size_t, cudaMemcpyKind, cudaStream_t); } 
extern "C" { extern cudaError_t __stdcall cudaMemcpyFromSymbolAsync(void *, const char *, size_t, size_t, cudaMemcpyKind, cudaStream_t); } 
#line 153
extern "C" { extern cudaError_t __stdcall cudaMemset(void *, int, size_t); } 
extern "C" { extern cudaError_t __stdcall cudaMemset2D(void *, size_t, int, size_t, size_t); } 
#line 162
extern "C" { extern cudaError_t __stdcall cudaGetSymbolAddress(void **, const char *); } 
extern "C" { extern cudaError_t __stdcall cudaGetSymbolSize(size_t *, const char *); } 
#line 171
extern "C" { extern cudaError_t __stdcall cudaGetDeviceCount(int *); } 
extern "C" { extern cudaError_t __stdcall cudaGetDeviceProperties(cudaDeviceProp *, int); } 
extern "C" { extern cudaError_t __stdcall cudaChooseDevice(int *, const cudaDeviceProp *); } 
extern "C" { extern cudaError_t __stdcall cudaSetDevice(int); } 
extern "C" { extern cudaError_t __stdcall cudaGetDevice(int *); } 
extern "C" { extern cudaError_t __stdcall cudaSetValidDevices(int *, int); } 
extern "C" { extern cudaError_t __stdcall cudaSetDeviceFlags(int); } 
#line 185
extern "C" { extern cudaError_t __stdcall cudaBindTexture(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t = (4294967295U)); } 
extern "C" { extern cudaError_t __stdcall cudaBindTexture2D(size_t *, const textureReference *, const void *, const cudaChannelFormatDesc *, size_t, size_t, size_t); } 
extern "C" { extern cudaError_t __stdcall cudaBindTextureToArray(const textureReference *, const cudaArray *, const cudaChannelFormatDesc *); } 
extern "C" { extern cudaError_t __stdcall cudaUnbindTexture(const textureReference *); } 
extern "C" { extern cudaError_t __stdcall cudaGetTextureAlignmentOffset(size_t *, const textureReference *); } 
extern "C" { extern cudaError_t __stdcall cudaGetTextureReference(const textureReference **, const char *); } 
#line 198
extern "C" { extern cudaError_t __stdcall cudaGetChannelDesc(cudaChannelFormatDesc *, const cudaArray *); } 
extern "C" { extern cudaChannelFormatDesc __stdcall cudaCreateChannelDesc(int, int, int, int, cudaChannelFormatKind); } 
#line 207
extern "C" { extern cudaError_t __stdcall cudaGetLastError(); } 
extern "C" { extern const char *__stdcall cudaGetErrorString(cudaError_t); } 
#line 216
extern "C" { extern cudaError_t __stdcall cudaConfigureCall(dim3, dim3, size_t = (0), cudaStream_t = (0)); } 
extern "C" { extern cudaError_t __stdcall cudaSetupArgument(const void *, size_t, size_t); } 
extern "C" { extern cudaError_t __stdcall cudaLaunch(const char *); } 
extern "C" { extern cudaError_t __stdcall cudaFuncGetAttributes(cudaFuncAttributes *, const char *); } 
#line 227
extern "C" { extern cudaError_t __stdcall cudaStreamCreate(cudaStream_t *); } 
extern "C" { extern cudaError_t __stdcall cudaStreamDestroy(cudaStream_t); } 
extern "C" { extern cudaError_t __stdcall cudaStreamSynchronize(cudaStream_t); } 
extern "C" { extern cudaError_t __stdcall cudaStreamQuery(cudaStream_t); } 
#line 238
extern "C" { extern cudaError_t __stdcall cudaEventCreate(cudaEvent_t *); } 
extern "C" { extern cudaError_t __stdcall cudaEventCreateWithFlags(cudaEvent_t *, int); } 
extern "C" { extern cudaError_t __stdcall cudaEventRecord(cudaEvent_t, cudaStream_t); } 
extern "C" { extern cudaError_t __stdcall cudaEventQuery(cudaEvent_t); } 
extern "C" { extern cudaError_t __stdcall cudaEventSynchronize(cudaEvent_t); } 
extern "C" { extern cudaError_t __stdcall cudaEventDestroy(cudaEvent_t); } 
extern "C" { extern cudaError_t __stdcall cudaEventElapsedTime(float *, cudaEvent_t, cudaEvent_t); } 
#line 252
extern "C" { extern cudaError_t __stdcall cudaSetDoubleForDevice(double *); } 
extern "C" { extern cudaError_t __stdcall cudaSetDoubleForHost(double *); } 
#line 261
extern "C" { extern cudaError_t __stdcall cudaThreadExit(); } 
extern "C" { extern cudaError_t __stdcall cudaThreadSynchronize(); } 
#line 270
extern "C" { extern cudaError_t __stdcall cudaDriverGetVersion(int *); } 
extern "C" { extern cudaError_t __stdcall cudaRuntimeGetVersion(int *); } 
#line 93 "d:\\my\\work\\cuda\\64\\tk\\include\\channel_descriptor.h"
template<class T> __inline cudaChannelFormatDesc cudaCreateChannelDesc() 
{ 
return cudaCreateChannelDesc(0, 0, 0, 0, cudaChannelFormatKindNone); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< char> () 
{ 
auto int e = (((int)sizeof(char)) * 8); 
#line 105 "d:\\my\\work\\cuda\\64\\tk\\include\\channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
#line 107 "d:\\my\\work\\cuda\\64\\tk\\include\\channel_descriptor.h"
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< signed char> () 
{ 
auto int e = (((int)sizeof(signed char)) * 8); 

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned char> () 
{ 
auto int e = (((int)sizeof(unsigned char)) * 8); 

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< char1> () 
{ 
auto int e = (((int)sizeof(signed char)) * 8); 

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar1> () 
{ 
auto int e = (((int)sizeof(unsigned char)) * 8); 

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< char2> () 
{ 
auto int e = (((int)sizeof(signed char)) * 8); 

return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar2> () 
{ 
auto int e = (((int)sizeof(unsigned char)) * 8); 

return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< char4> () 
{ 
auto int e = (((int)sizeof(signed char)) * 8); 

return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar4> () 
{ 
auto int e = (((int)sizeof(unsigned char)) * 8); 

return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< short> () 
{ 
auto int e = (((int)sizeof(short)) * 8); 

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned short> () 
{ 
auto int e = (((int)sizeof(unsigned short)) * 8); 

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< short1> () 
{ 
auto int e = (((int)sizeof(short)) * 8); 

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort1> () 
{ 
auto int e = (((int)sizeof(unsigned short)) * 8); 

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< short2> () 
{ 
auto int e = (((int)sizeof(short)) * 8); 

return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort2> () 
{ 
auto int e = (((int)sizeof(unsigned short)) * 8); 

return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< short4> () 
{ 
auto int e = (((int)sizeof(short)) * 8); 

return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort4> () 
{ 
auto int e = (((int)sizeof(unsigned short)) * 8); 

return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< int> () 
{ 
auto int e = (((int)sizeof(int)) * 8); 

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned> () 
{ 
auto int e = (((int)sizeof(unsigned)) * 8); 

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< int1> () 
{ 
auto int e = (((int)sizeof(int)) * 8); 

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< uint1> () 
{ 
auto int e = (((int)sizeof(unsigned)) * 8); 

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< int2> () 
{ 
auto int e = (((int)sizeof(int)) * 8); 

return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< uint2> () 
{ 
auto int e = (((int)sizeof(unsigned)) * 8); 

return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< int4> () 
{ 
auto int e = (((int)sizeof(int)) * 8); 

return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< uint4> () 
{ 
auto int e = (((int)sizeof(unsigned)) * 8); 

return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned); 
} 



template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< long> () 
{ 
auto int e = (((int)sizeof(long)) * 8); 

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned long> () 
{ 
auto int e = (((int)sizeof(unsigned long)) * 8); 

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< long1> () 
{ 
auto int e = (((int)sizeof(long)) * 8); 

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< ulong1> () 
{ 
auto int e = (((int)sizeof(unsigned long)) * 8); 

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< long2> () 
{ 
auto int e = (((int)sizeof(long)) * 8); 

return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< ulong2> () 
{ 
auto int e = (((int)sizeof(unsigned long)) * 8); 

return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< long4> () 
{ 
auto int e = (((int)sizeof(long)) * 8); 

return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< ulong4> () 
{ 
auto int e = (((int)sizeof(unsigned long)) * 8); 

return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned); 
} 
#line 337 "d:\\my\\work\\cuda\\64\\tk\\include\\channel_descriptor.h"
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< float> () 
{ 
auto int e = (((int)sizeof(float)) * 8); 

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< float1> () 
{ 
auto int e = (((int)sizeof(float)) * 8); 

return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< float2> () 
{ 
auto int e = (((int)sizeof(float)) * 8); 

return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat); 
} 

template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< float4> () 
{ 
auto int e = (((int)sizeof(float)) * 8); 

return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat); 
} 
#line 54 "d:\\my\\work\\cuda\\64\\tk\\include\\driver_functions.h"
static __inline cudaPitchedPtr make_cudaPitchedPtr(void *d, size_t p, size_t xsz, size_t ysz) 
{ 
auto cudaPitchedPtr s; 

(s.ptr) = d; 
(s.pitch) = p; 
(s.xsize) = xsz; 
(s.ysize) = ysz; 

return s; 
} 

static __inline cudaPos make_cudaPos(size_t x, size_t y, size_t z) 
{ 
auto cudaPos p; 

(p.x) = x; 
(p.y) = y; 
(p.z) = z; 

return p; 
} 

static __inline cudaExtent make_cudaExtent(size_t w, size_t h, size_t d) 
{ 
auto cudaExtent e; 

(e.width) = w; 
(e.height) = h; 
(e.depth) = d; 

return e; 
} 
#line 54 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_functions.h"
static __inline char1 make_char1(signed char x) 
{ 
auto char1 t; (t.x) = x; return t; 
} 

static __inline uchar1 make_uchar1(unsigned char x) 
{ 
auto uchar1 t; (t.x) = x; return t; 
} 

static __inline char2 make_char2(signed char x, signed char y) 
{ 
auto char2 t; (t.x) = x; (t.y) = y; return t; 
} 

static __inline uchar2 make_uchar2(unsigned char x, unsigned char y) 
{ 
auto uchar2 t; (t.x) = x; (t.y) = y; return t; 
} 

static __inline char3 make_char3(signed char x, signed char y, signed char z) 
{ 
auto char3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
} 

static __inline uchar3 make_uchar3(unsigned char x, unsigned char y, unsigned char z) 
{ 
auto uchar3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
} 

static __inline char4 make_char4(signed char x, signed char y, signed char z, signed char w) 
{ 
auto char4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
} 

static __inline uchar4 make_uchar4(unsigned char x, unsigned char y, unsigned char z, unsigned char w) 
{ 
auto uchar4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
} 

static __inline short1 make_short1(short x) 
{ 
auto short1 t; (t.x) = x; return t; 
} 

static __inline ushort1 make_ushort1(unsigned short x) 
{ 
auto ushort1 t; (t.x) = x; return t; 
} 

static __inline short2 make_short2(short x, short y) 
{ 
auto short2 t; (t.x) = x; (t.y) = y; return t; 
} 

static __inline ushort2 make_ushort2(unsigned short x, unsigned short y) 
{ 
auto ushort2 t; (t.x) = x; (t.y) = y; return t; 
} 

static __inline short3 make_short3(short x, short y, short z) 
{ 
auto short3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
} 

static __inline ushort3 make_ushort3(unsigned short x, unsigned short y, unsigned short z) 
{ 
auto ushort3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
} 

static __inline short4 make_short4(short x, short y, short z, short w) 
{ 
auto short4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
} 

static __inline ushort4 make_ushort4(unsigned short x, unsigned short y, unsigned short z, unsigned short w) 
{ 
auto ushort4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
} 

static __inline int1 make_int1(int x) 
{ 
auto int1 t; (t.x) = x; return t; 
} 

static __inline uint1 make_uint1(unsigned x) 
{ 
auto uint1 t; (t.x) = x; return t; 
} 

static __inline int2 make_int2(int x, int y) 
{ 
auto int2 t; (t.x) = x; (t.y) = y; return t; 
} 

static __inline uint2 make_uint2(unsigned x, unsigned y) 
{ 
auto uint2 t; (t.x) = x; (t.y) = y; return t; 
} 

static __inline int3 make_int3(int x, int y, int z) 
{ 
auto int3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
} 

static __inline uint3 make_uint3(unsigned x, unsigned y, unsigned z) 
{ 
auto uint3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
} 

static __inline int4 make_int4(int x, int y, int z, int w) 
{ 
auto int4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
} 

static __inline uint4 make_uint4(unsigned x, unsigned y, unsigned z, unsigned w) 
{ 
auto uint4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
} 

static __inline long1 make_long1(long x) 
{ 
auto long1 t; (t.x) = x; return t; 
} 

static __inline ulong1 make_ulong1(unsigned long x) 
{ 
auto ulong1 t; (t.x) = x; return t; 
} 

static __inline long2 make_long2(long x, long y) 
{ 
auto long2 t; (t.x) = x; (t.y) = y; return t; 
} 

static __inline ulong2 make_ulong2(unsigned long x, unsigned long y) 
{ 
auto ulong2 t; (t.x) = x; (t.y) = y; return t; 
} 



static __inline long3 make_long3(long x, long y, long z) 
{ 
auto long3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
} 

static __inline ulong3 make_ulong3(unsigned long x, unsigned long y, unsigned long z) 
{ 
auto ulong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
} 

static __inline long4 make_long4(long x, long y, long z, long w) 
{ 
auto long4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
} 

static __inline ulong4 make_ulong4(unsigned long x, unsigned long y, unsigned long z, unsigned long w) 
{ 
auto ulong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
} 
#line 218 "d:\\my\\work\\cuda\\64\\tk\\include\\vector_functions.h"
static __inline float1 make_float1(float x) 
{ 
auto float1 t; (t.x) = x; return t; 
} 

static __inline float2 make_float2(float x, float y) 
{ 
auto float2 t; (t.x) = x; (t.y) = y; return t; 
} 

static __inline float3 make_float3(float x, float y, float z) 
{ 
auto float3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
} 

static __inline float4 make_float4(float x, float y, float z, float w) 
{ 
auto float4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
} 

static __inline longlong1 make_longlong1(__int64 x) 
{ 
auto longlong1 t; (t.x) = x; return t; 
} 

static __inline ulonglong1 make_ulonglong1(unsigned __int64 x) 
{ 
auto ulonglong1 t; (t.x) = x; return t; 
} 

static __inline longlong2 make_longlong2(__int64 x, __int64 y) 
{ 
auto longlong2 t; (t.x) = x; (t.y) = y; return t; 
} 

static __inline ulonglong2 make_ulonglong2(unsigned __int64 x, unsigned __int64 y) 
{ 
auto ulonglong2 t; (t.x) = x; (t.y) = y; return t; 
} 

static __inline double1 make_double1(double x) 
{ 
auto double1 t; (t.x) = x; return t; 
} 

static __inline double2 make_double2(double x, double y) 
{ 
auto double2 t; (t.x) = x; (t.y) = y; return t; 
} 
#line 35 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\time.h"
#pragma pack ( push, 8 )
#line 93 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\time.h"
extern "C" { typedef long clock_t; }
#line 117 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\time.h"
extern "C" { struct tm { 
int tm_sec; 
int tm_min; 
int tm_hour; 
int tm_mday; 
int tm_mon; 
int tm_year; 
int tm_wday; 
int tm_yday; 
int tm_isdst; 
}; }
#line 142 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\time.h"
extern "C" { extern int *__cdecl __daylight(); } 



extern "C" { extern long *__cdecl __dstbias(); } 



extern "C" { extern long *__cdecl __timezone(); } 



extern "C" { extern char **__cdecl __tzname(); } 


extern "C" { extern errno_t __cdecl _get_daylight(int *); } 
extern "C" { extern errno_t __cdecl _get_dstbias(long *); } 
extern "C" { extern errno_t __cdecl _get_timezone(long *); } 
extern "C" { extern errno_t __cdecl _get_tzname(size_t *, char *, size_t, int); } 



extern "C" { extern char *__cdecl asctime(const tm *); } 

extern "C" { extern errno_t __cdecl asctime_s(char *, size_t, const tm *); } 
#line 168 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\time.h"
template < size_t _Size > inline errno_t __cdecl asctime_s ( char ( & _Buffer ) [ _Size ], const struct tm * _Time ) { return asctime_s ( _Buffer, _Size, _Time ); }

extern "C" { extern char *__cdecl _ctime32(const __time32_t *); } 
extern "C" { extern errno_t __cdecl _ctime32_s(char *, size_t, const __time32_t *); } 
template < size_t _Size > inline errno_t __cdecl _ctime32_s ( char ( & _Buffer ) [ _Size ], const __time32_t * _Time ) { return _ctime32_s ( _Buffer, _Size, _Time ); }

extern "C" { extern clock_t __cdecl clock(); } 
extern "C" { extern double __cdecl _difftime32(__time32_t, __time32_t); } 

extern "C" { extern tm *__cdecl _gmtime32(const __time32_t *); } 
extern "C" { extern errno_t __cdecl _gmtime32_s(tm *, const __time32_t *); } 

extern "C" { extern tm *__cdecl _localtime32(const __time32_t *); } 
extern "C" { extern errno_t __cdecl _localtime32_s(tm *, const __time32_t *); } 

extern "C" { extern size_t __cdecl strftime(char *, size_t, const char *, const tm *); } 
extern "C" { extern size_t __cdecl _strftime_l(char *, size_t, const char *, const tm *, _locale_t); } 

extern "C" { extern errno_t __cdecl _strdate_s(char *, size_t); } 
template < size_t _Size > inline errno_t __cdecl _strdate_s ( char ( & _Buffer ) [ _Size ] ) { return _strdate_s ( _Buffer, _Size ); }
extern "C" { extern char *__cdecl _strdate(char *); } 

extern "C" { extern errno_t __cdecl _strtime_s(char *, size_t); } 
template < size_t _Size > inline errno_t __cdecl _strtime_s ( char ( & _Buffer ) [ _Size ] ) { return _strtime_s ( _Buffer, _Size ); }
extern "C" { extern char *__cdecl _strtime(char *); } 

extern "C" { extern __time32_t __cdecl _time32(__time32_t *); } 
extern "C" { extern __time32_t __cdecl _mktime32(tm *); } 
extern "C" { extern __time32_t __cdecl _mkgmtime32(tm *); } 




extern "C" { extern void __cdecl _tzset(); } 
#line 204 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\time.h"
extern "C" { extern double __cdecl _difftime64(__time64_t, __time64_t); } 
extern "C" { extern char *__cdecl _ctime64(const __time64_t *); } 
extern "C" { extern errno_t __cdecl _ctime64_s(char *, size_t, const __time64_t *); } 
template < size_t _Size > inline errno_t __cdecl _ctime64_s ( char ( & _Buffer ) [ _Size ], const __time64_t * _Time ) { return _ctime64_s ( _Buffer, _Size, _Time ); }

extern "C" { extern tm *__cdecl _gmtime64(const __time64_t *); } 
extern "C" { extern errno_t __cdecl _gmtime64_s(tm *, const __time64_t *); } 

extern "C" { extern tm *__cdecl _localtime64(const __time64_t *); } 
extern "C" { extern errno_t __cdecl _localtime64_s(tm *, const __time64_t *); } 

extern "C" { extern __time64_t __cdecl _mktime64(tm *); } 
extern "C" { extern __time64_t __cdecl _mkgmtime64(tm *); } 
extern "C" { extern __time64_t __cdecl _time64(__time64_t *); } 


extern "C" { extern __declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using GetLocalTime instead. See online help for details.")) unsigned __cdecl _getsystime(tm *); } 
extern "C" { extern __declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using SetLocalTime instead. See online help for details.")) unsigned __cdecl _setsystime(tm *, unsigned); } 
#line 233
extern "C" { extern __wchar_t *__cdecl _wasctime(const tm *); } 
extern "C" { extern errno_t __cdecl _wasctime_s(__wchar_t *, size_t, const tm *); } 
template < size_t _Size > inline errno_t __cdecl _wasctime_s ( wchar_t ( & _Buffer ) [ _Size ], const struct tm * _Time ) { return _wasctime_s ( _Buffer, _Size, _Time ); }

extern "C" { extern __wchar_t *__cdecl _wctime32(const __time32_t *); } 
extern "C" { extern errno_t __cdecl _wctime32_s(__wchar_t *, size_t, const __time32_t *); } 
template < size_t _Size > inline errno_t __cdecl _wctime32_s ( wchar_t ( & _Buffer ) [ _Size ], const __time32_t * _Time ) { return _wctime32_s ( _Buffer, _Size, _Time ); }

extern "C" { extern size_t __cdecl wcsftime(__wchar_t *, size_t, const __wchar_t *, const tm *); } 
extern "C" { extern size_t __cdecl _wcsftime_l(__wchar_t *, size_t, const __wchar_t *, const tm *, _locale_t); } 

extern "C" { extern errno_t __cdecl _wstrdate_s(__wchar_t *, size_t); } 
template < size_t _Size > inline errno_t __cdecl _wstrdate_s ( wchar_t ( & _Buffer ) [ _Size ] ) { return _wstrdate_s ( _Buffer, _Size ); }
extern "C" { extern __wchar_t *__cdecl _wstrdate(__wchar_t *); } 

extern "C" { extern errno_t __cdecl _wstrtime_s(__wchar_t *, size_t); } 
template < size_t _Size > inline errno_t __cdecl _wstrtime_s ( wchar_t ( & _Buffer ) [ _Size ] ) { return _wstrtime_s ( _Buffer, _Size ); }
extern "C" { extern __wchar_t *__cdecl _wstrtime(__wchar_t *); } 

extern "C" { extern __wchar_t *__cdecl _wctime64(const __time64_t *); } 
extern "C" { extern errno_t __cdecl _wctime64_s(__wchar_t *, size_t, const __time64_t *); } 
template < size_t _Size > inline errno_t __cdecl _wctime64_s ( wchar_t ( & _Buffer ) [ _Size ], const __time64_t * _Time ) { return _wctime64_s ( _Buffer, _Size, _Time ); }
#line 29 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\wtime.inl"
#pragma warning(push)
#pragma warning(disable:4996)
#line 46
extern "C" { static __inline __wchar_t *__cdecl _wctime(const time_t *_Time) 
{ 
#pragma warning( push )
#pragma warning( disable : 4996 )
return _wctime64(_Time); 
#pragma warning( pop )
} } 

extern "C" { static __inline errno_t __cdecl _wctime_s(__wchar_t *_Buffer, size_t _SizeInWords, const time_t *_Time) 
{ 
return _wctime64_s(_Buffer, _SizeInWords, _Time); 
} } 
#line 60 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\wtime.inl"
#pragma warning(pop)
#line 84 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\time.inl"
extern "C" { static __inline double __cdecl difftime(time_t _Time1, time_t _Time2) 
{ 
return _difftime64(_Time1, _Time2); 
} } 
extern "C" { static __inline char *__cdecl ctime(const time_t *_Time) 
{ 
#pragma warning( push )
#pragma warning( disable : 4996 )
return _ctime64(_Time); 
#pragma warning( pop )
} } 

extern "C" { static __inline errno_t __cdecl ctime_s(char *_Buffer, size_t _SizeInBytes, const time_t *_Time) 
{ 
return _ctime64_s(_Buffer, _SizeInBytes, _Time); 
} } 
#line 101 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\time.inl"
extern "C" { static __inline tm *__cdecl gmtime(const time_t *_Time) 
{ 
#pragma warning( push )
#pragma warning( disable : 4996 )
return _gmtime64(_Time); 
#pragma warning( pop )
} } 

extern "C" { static __inline errno_t __cdecl gmtime_s(tm *_Tm, const time_t *_Time) 
{ 
return _gmtime64_s(_Tm, _Time); 
} } 
#line 114 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\time.inl"
extern "C" { static __inline tm *__cdecl localtime(const time_t *_Time) 
{ 
#pragma warning( push )
#pragma warning( disable : 4996 )
return _localtime64(_Time); 
#pragma warning( pop )
} } 
extern "C" { static __inline errno_t __cdecl localtime_s(tm *_Tm, const time_t *_Time) 
{ 
return _localtime64_s(_Tm, _Time); 
} } 
extern "C" { static __inline time_t __cdecl mktime(tm *_Tm) 
{ 
return _mktime64(_Tm); 
} } 
extern "C" { static __inline time_t __cdecl _mkgmtime(tm *_Tm) 
{ 
return _mkgmtime64(_Tm); 
} } 
extern "C" { static __inline time_t __cdecl time(time_t *_Time) 
{ 
return _time64(_Time); 
} } 
#line 279 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\time.h"
extern "C" int daylight; 
extern "C" long timezone; 
extern "C" char *tzname[2]; 
#line 284 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\time.h"
extern "C" { extern void __cdecl tzset(); } 
#line 294 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\time.h"
#pragma pack ( pop )
#line 48 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
extern "C" { extern void *__cdecl _memccpy(void *, const void *, int, size_t); } 
extern "C" { extern const void *__cdecl memchr(const void *, int, size_t); } 
extern "C" { extern int __cdecl _memicmp(const void *, const void *, size_t); } 
extern "C" { extern int __cdecl _memicmp_l(const void *, const void *, size_t, _locale_t); } 
extern "C" { extern int __cdecl memcmp(const void *, const void *, size_t); } 
extern "C" { extern void *__cdecl memcpy(void *, const void *, size_t); } 

extern "C" { extern errno_t __cdecl memcpy_s(void *, rsize_t, const void *, rsize_t); } 
#line 57 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
extern "C" { extern void *__cdecl memset(void *, int, size_t); } 



extern "C" { extern void *__cdecl memccpy(void *, const void *, int, size_t); } 
extern "C" { extern int __cdecl memicmp(const void *, const void *, size_t); } 
#line 67 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
extern "C" { extern errno_t __cdecl _strset_s(char *, size_t, int); } 
template < size_t _Size > inline errno_t __cdecl _strset_s ( char ( & _Dest ) [ _Size ], int _Value ) { return _strset_s ( _Dest, _Size, _Value ); }
extern "C" { extern char *__cdecl _strset(char *, int); } 

extern "C" { extern errno_t __cdecl strcpy_s(char *, rsize_t, const char *); } 
#line 73 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
template < size_t _Size > inline errno_t __cdecl strcpy_s ( char ( & _Dest ) [ _Size ], const char * _Source ) { return strcpy_s ( _Dest, _Size, _Source ); }
extern "C" { extern char *__cdecl strcpy(char *, const char *); } 

extern "C" { extern errno_t __cdecl strcat_s(char *, rsize_t, const char *); } 
#line 78 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
template < size_t _Size > inline errno_t __cdecl strcat_s ( char ( & _Dest ) [ _Size ], const char * _Source ) { return strcat_s ( _Dest, _Size, _Source ); }
extern "C" { extern char *__cdecl strcat(char *, const char *); } 
extern "C" { extern int __cdecl strcmp(const char *, const char *); } 
extern "C" { extern size_t __cdecl strlen(const char *); } 
extern "C" { extern size_t __cdecl strnlen(const char *, size_t); } 

extern "C" { static __inline size_t __cdecl strnlen_s(const char *_Str, size_t _MaxCount) 
{ 
return (_Str == (0)) ? (0) : strnlen(_Str, _MaxCount); 
} } 
#line 90 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
extern "C" { extern errno_t __cdecl memmove_s(void *, rsize_t, const void *, rsize_t); } 
#line 96 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
extern "C" { extern void *__cdecl memmove(void *, const void *, size_t); } 
#line 104 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
extern "C" { extern char *__cdecl _strdup(const char *); } 
#line 110 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
extern "C" { extern const char *__cdecl strchr(const char *, int); } 
extern "C" { extern int __cdecl _stricmp(const char *, const char *); } 
extern "C" { extern int __cdecl _strcmpi(const char *, const char *); } 
extern "C" { extern int __cdecl _stricmp_l(const char *, const char *, _locale_t); } 
extern "C" { extern int __cdecl strcoll(const char *, const char *); } 
extern "C" { extern int __cdecl _strcoll_l(const char *, const char *, _locale_t); } 
extern "C" { extern int __cdecl _stricoll(const char *, const char *); } 
extern "C" { extern int __cdecl _stricoll_l(const char *, const char *, _locale_t); } 
extern "C" { extern int __cdecl _strncoll(const char *, const char *, size_t); } 
extern "C" { extern int __cdecl _strncoll_l(const char *, const char *, size_t, _locale_t); } 
extern "C" { extern int __cdecl _strnicoll(const char *, const char *, size_t); } 
extern "C" { extern int __cdecl _strnicoll_l(const char *, const char *, size_t, _locale_t); } 
extern "C" { extern size_t __cdecl strcspn(const char *, const char *); } 
extern "C" { extern char *__cdecl _strerror(const char *); } 
extern "C" { extern errno_t __cdecl _strerror_s(char *, size_t, const char *); } 
template < size_t _Size > inline errno_t __cdecl _strerror_s ( char ( & _Buffer ) [ _Size ], const char * _ErrorMessage ) { return _strerror_s ( _Buffer, _Size, _ErrorMessage ); }
extern "C" { extern char *__cdecl strerror(int); } 

extern "C" { extern errno_t __cdecl strerror_s(char *, size_t, int); } 
#line 130 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
template < size_t _Size > inline errno_t __cdecl strerror_s ( char ( & _Buffer ) [ _Size ], int _ErrorMessage ) { return strerror_s ( _Buffer, _Size, _ErrorMessage ); }
extern "C" { extern errno_t __cdecl _strlwr_s(char *, size_t); } 
template < size_t _Size > inline errno_t __cdecl _strlwr_s ( char ( & _String ) [ _Size ] ) { return _strlwr_s ( _String, _Size ); }
extern "C" { extern char *__cdecl _strlwr(char *); } 
extern "C" { extern errno_t __cdecl _strlwr_s_l(char *, size_t, _locale_t); } 
template < size_t _Size > inline errno_t __cdecl _strlwr_s_l ( char ( & _String ) [ _Size ], _locale_t _Locale ) { return _strlwr_s_l ( _String, _Size, _Locale ); }
extern "C" { extern char *__cdecl _strlwr_l(char *, _locale_t); } 

extern "C" { extern errno_t __cdecl strncat_s(char *, rsize_t, const char *, rsize_t); } 
#line 140 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
template < size_t _Size > inline errno_t __cdecl strncat_s ( char ( & _Dest ) [ _Size ], const char * _Source, size_t _Count ) { return strncat_s ( _Dest, _Size, _Source, _Count ); }
#pragma warning(push)
#pragma warning(disable:6059)

extern "C" { extern char *__cdecl strncat(char *, const char *, size_t); } 
#pragma warning(pop)
#line 149 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
extern "C" { extern int __cdecl strncmp(const char *, const char *, size_t); } 
#line 151 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
extern "C" { extern int __cdecl _strnicmp(const char *, const char *, size_t); } 
extern "C" { extern int __cdecl _strnicmp_l(const char *, const char *, size_t, _locale_t); } 

extern "C" { extern errno_t __cdecl strncpy_s(char *, rsize_t, const char *, rsize_t); } 
#line 156 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
template < size_t _Size > inline errno_t __cdecl strncpy_s ( char ( & _Dest ) [ _Size ], const char * _Source, size_t _Count ) { return strncpy_s ( _Dest, _Size, _Source, _Count ); }
extern "C" { extern char *__cdecl strncpy(char *, const char *, size_t); } 
extern "C" { extern errno_t __cdecl _strnset_s(char *, size_t, int, size_t); } 
template < size_t _Size > inline errno_t __cdecl _strnset_s ( char ( & _Dest ) [ _Size ], int _Val, size_t _Count ) { return _strnset_s ( _Dest, _Size, _Val, _Count ); }
extern "C" { extern char *__cdecl _strnset(char *, int, size_t); } 
extern "C" { extern const char *__cdecl strpbrk(const char *, const char *); } 
extern "C" { extern const char *__cdecl strrchr(const char *, int); } 
extern "C" { extern char *__cdecl _strrev(char *); } 
extern "C" { extern size_t __cdecl strspn(const char *, const char *); } 
extern "C" { extern const char *__cdecl strstr(const char *, const char *); } 
extern "C" { extern char *__cdecl strtok(char *, const char *); } 

extern "C" { extern char *__cdecl strtok_s(char *, const char *, char **); } 
#line 170 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
extern "C" { extern errno_t __cdecl _strupr_s(char *, size_t); } 
template < size_t _Size > inline errno_t __cdecl _strupr_s ( char ( & _String ) [ _Size ] ) { return _strupr_s ( _String, _Size ); }
extern "C" { extern char *__cdecl _strupr(char *); } 
extern "C" { extern errno_t __cdecl _strupr_s_l(char *, size_t, _locale_t); } 
template < size_t _Size > inline errno_t __cdecl _strupr_s_l ( char ( & _String ) [ _Size ], _locale_t _Locale ) { return _strupr_s_l ( _String, _Size, _Locale ); }
extern "C" { extern char *__cdecl _strupr_l(char *, _locale_t); } 
extern "C" { extern size_t __cdecl strxfrm(char *, const char *, size_t); } 
extern "C" { extern size_t __cdecl _strxfrm_l(char *, const char *, size_t, _locale_t); } 
#line 183
inline char *__cdecl strchr(char *_Str, int _Ch) 
{ return (char *)strchr((const char *)_Str, _Ch); } 
inline char *__cdecl strpbrk(char *_Str, const char *_Control) 
{ return (char *)strpbrk((const char *)_Str, _Control); } 
inline char *__cdecl strrchr(char *_Str, int _Ch) 
{ return (char *)strrchr((const char *)_Str, _Ch); } 
inline char *__cdecl strstr(char *_Str, const char *_SubStr) 
{ return (char *)strstr((const char *)_Str, _SubStr); } 
#line 194 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
inline void *__cdecl memchr(void *_Pv, int _C, size_t _N) 
{ return (void *)memchr((const void *)_Pv, _C, _N); } 
#line 207 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
extern "C" { extern char *__cdecl strdup(const char *); } 
#line 214 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
extern "C" { extern int __cdecl strcmpi(const char *, const char *); } 
extern "C" { extern int __cdecl stricmp(const char *, const char *); } 
extern "C" { extern char *__cdecl strlwr(char *); } 
extern "C" { extern int __cdecl strnicmp(const char *, const char *, size_t); } 
extern "C" { extern char *__cdecl strnset(char *, int, size_t); } 
extern "C" { extern char *__cdecl strrev(char *); } 
extern "C" { extern char *__cdecl strset(char *, int); } 
extern "C" { extern char *__cdecl strupr(char *); } 
#line 235 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
extern "C" { extern __wchar_t *__cdecl _wcsdup(const __wchar_t *); } 
#line 242 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
extern "C" { extern errno_t __cdecl wcscat_s(__wchar_t *, rsize_t, const __wchar_t *); } 
#line 244 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
template < size_t _Size > inline errno_t __cdecl wcscat_s ( wchar_t ( & _Dest ) [ _Size ], const wchar_t * _Source ) { return wcscat_s ( _Dest, _Size, _Source ); }
extern "C" { extern __wchar_t *__cdecl wcscat(__wchar_t *, const __wchar_t *); } 
extern "C" { extern const __wchar_t *__cdecl wcschr(const __wchar_t *, __wchar_t); } 
extern "C" { extern int __cdecl wcscmp(const __wchar_t *, const __wchar_t *); } 

extern "C" { extern errno_t __cdecl wcscpy_s(__wchar_t *, rsize_t, const __wchar_t *); } 
#line 251 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
template < size_t _Size > inline errno_t __cdecl wcscpy_s ( wchar_t ( & _Dest ) [ _Size ], const wchar_t * _Source ) { return wcscpy_s ( _Dest, _Size, _Source ); }
extern "C" { extern __wchar_t *__cdecl wcscpy(__wchar_t *, const __wchar_t *); } 
extern "C" { extern size_t __cdecl wcscspn(const __wchar_t *, const __wchar_t *); } 
extern "C" { extern size_t __cdecl wcslen(const __wchar_t *); } 
extern "C" { extern size_t __cdecl wcsnlen(const __wchar_t *, size_t); } 

extern "C" { static __inline size_t __cdecl wcsnlen_s(const __wchar_t *_Src, size_t _MaxCount) 
{ 
return (_Src == (0)) ? (0) : wcsnlen(_Src, _MaxCount); 
} } 
#line 263 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
extern "C" { extern errno_t __cdecl wcsncat_s(__wchar_t *, rsize_t, const __wchar_t *, rsize_t); } 
#line 265 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
template < size_t _Size > inline errno_t __cdecl wcsncat_s ( wchar_t ( & _Dest ) [ _Size ], const wchar_t * _Source, size_t _Count ) { return wcsncat_s ( _Dest, _Size, _Source, _Count ); }
#pragma warning(push)
#pragma warning(disable:6059)
extern "C" { extern __wchar_t *__cdecl wcsncat(__wchar_t *, const __wchar_t *, size_t); } 
#pragma warning(pop)
extern "C" { extern int __cdecl wcsncmp(const __wchar_t *, const __wchar_t *, size_t); } 

extern "C" { extern errno_t __cdecl wcsncpy_s(__wchar_t *, rsize_t, const __wchar_t *, rsize_t); } 
#line 274 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
template < size_t _Size > inline errno_t __cdecl wcsncpy_s ( wchar_t ( & _Dest ) [ _Size ], const wchar_t * _Source, size_t _Count ) { return wcsncpy_s ( _Dest, _Size, _Source, _Count ); }
extern "C" { extern __wchar_t *__cdecl wcsncpy(__wchar_t *, const __wchar_t *, size_t); } 
extern "C" { extern const __wchar_t *__cdecl wcspbrk(const __wchar_t *, const __wchar_t *); } 
extern "C" { extern const __wchar_t *__cdecl wcsrchr(const __wchar_t *, __wchar_t); } 
extern "C" { extern size_t __cdecl wcsspn(const __wchar_t *, const __wchar_t *); } 
extern "C" { extern const __wchar_t *__cdecl wcsstr(const __wchar_t *, const __wchar_t *); } 
extern "C" { extern __wchar_t *__cdecl wcstok(__wchar_t *, const __wchar_t *); } 

extern "C" { extern __wchar_t *__cdecl wcstok_s(__wchar_t *, const __wchar_t *, __wchar_t **); } 
#line 284 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
extern "C" { extern __wchar_t *__cdecl _wcserror(int); } 
extern "C" { extern errno_t __cdecl _wcserror_s(__wchar_t *, size_t, int); } 
template < size_t _Size > inline errno_t __cdecl _wcserror_s ( wchar_t ( & _Buffer ) [ _Size ], int _Error ) { return _wcserror_s ( _Buffer, _Size, _Error ); }
extern "C" { extern __wchar_t *__cdecl __wcserror(const __wchar_t *); } 
extern "C" { extern errno_t __cdecl __wcserror_s(__wchar_t *, size_t, const __wchar_t *); } 
template < size_t _Size > inline errno_t __cdecl __wcserror_s ( wchar_t ( & _Buffer ) [ _Size ], const wchar_t * _ErrorMessage ) { return __wcserror_s ( _Buffer, _Size, _ErrorMessage ); }

extern "C" { extern int __cdecl _wcsicmp(const __wchar_t *, const __wchar_t *); } 
extern "C" { extern int __cdecl _wcsicmp_l(const __wchar_t *, const __wchar_t *, _locale_t); } 
extern "C" { extern int __cdecl _wcsnicmp(const __wchar_t *, const __wchar_t *, size_t); } 
extern "C" { extern int __cdecl _wcsnicmp_l(const __wchar_t *, const __wchar_t *, size_t, _locale_t); } 
extern "C" { extern errno_t __cdecl _wcsnset_s(__wchar_t *, size_t, __wchar_t, size_t); } 
template < size_t _Size > inline errno_t __cdecl _wcsnset_s ( wchar_t ( & _Dst ) [ _Size ], wchar_t _Val, size_t _MaxCount ) { return _wcsnset_s ( _Dst, _Size, _Val, _MaxCount ); }
extern "C" { extern __wchar_t *__cdecl _wcsnset(__wchar_t *, __wchar_t, size_t); } 
extern "C" { extern __wchar_t *__cdecl _wcsrev(__wchar_t *); } 
extern "C" { extern errno_t __cdecl _wcsset_s(__wchar_t *, size_t, __wchar_t); } 
template < size_t _Size > inline errno_t __cdecl _wcsset_s ( wchar_t ( & _Str ) [ _Size ], wchar_t _Val ) { return _wcsset_s ( _Str, _Size, _Val ); }
extern "C" { extern __wchar_t *__cdecl _wcsset(__wchar_t *, __wchar_t); } 

extern "C" { extern errno_t __cdecl _wcslwr_s(__wchar_t *, size_t); } 
template < size_t _Size > inline errno_t __cdecl _wcslwr_s ( wchar_t ( & _String ) [ _Size ] ) { return _wcslwr_s ( _String, _Size ); }
extern "C" { extern __wchar_t *__cdecl _wcslwr(__wchar_t *); } 
extern "C" { extern errno_t __cdecl _wcslwr_s_l(__wchar_t *, size_t, _locale_t); } 
template < size_t _Size > inline errno_t __cdecl _wcslwr_s_l ( wchar_t ( & _String ) [ _Size ], _locale_t _Locale ) { return _wcslwr_s_l ( _String, _Size, _Locale ); }
extern "C" { extern __wchar_t *__cdecl _wcslwr_l(__wchar_t *, _locale_t); } 
extern "C" { extern errno_t __cdecl _wcsupr_s(__wchar_t *, size_t); } 
template < size_t _Size > inline errno_t __cdecl _wcsupr_s ( wchar_t ( & _String ) [ _Size ] ) { return _wcsupr_s ( _String, _Size ); }
extern "C" { extern __wchar_t *__cdecl _wcsupr(__wchar_t *); } 
extern "C" { extern errno_t __cdecl _wcsupr_s_l(__wchar_t *, size_t, _locale_t); } 
template < size_t _Size > inline errno_t __cdecl _wcsupr_s_l ( wchar_t ( & _String ) [ _Size ], _locale_t _Locale ) { return _wcsupr_s_l ( _String, _Size, _Locale ); }
extern "C" { extern __wchar_t *__cdecl _wcsupr_l(__wchar_t *, _locale_t); } 
extern "C" { extern size_t __cdecl wcsxfrm(__wchar_t *, const __wchar_t *, size_t); } 
extern "C" { extern size_t __cdecl _wcsxfrm_l(__wchar_t *, const __wchar_t *, size_t, _locale_t); } 
extern "C" { extern int __cdecl wcscoll(const __wchar_t *, const __wchar_t *); } 
extern "C" { extern int __cdecl _wcscoll_l(const __wchar_t *, const __wchar_t *, _locale_t); } 
extern "C" { extern int __cdecl _wcsicoll(const __wchar_t *, const __wchar_t *); } 
extern "C" { extern int __cdecl _wcsicoll_l(const __wchar_t *, const __wchar_t *, _locale_t); } 
extern "C" { extern int __cdecl _wcsncoll(const __wchar_t *, const __wchar_t *, size_t); } 
extern "C" { extern int __cdecl _wcsncoll_l(const __wchar_t *, const __wchar_t *, size_t, _locale_t); } 
extern "C" { extern int __cdecl _wcsnicoll(const __wchar_t *, const __wchar_t *, size_t); } 
extern "C" { extern int __cdecl _wcsnicoll_l(const __wchar_t *, const __wchar_t *, size_t, _locale_t); } 
#line 330
inline __wchar_t *__cdecl wcschr(__wchar_t *_Str, __wchar_t _Ch) 
{ return (__wchar_t *)wcschr((const __wchar_t *)_Str, _Ch); } 
inline __wchar_t *__cdecl wcspbrk(__wchar_t *_Str, const __wchar_t *_Control) 
{ return (__wchar_t *)wcspbrk((const __wchar_t *)_Str, _Control); } 
inline __wchar_t *__cdecl wcsrchr(__wchar_t *_Str, __wchar_t _Ch) 
{ return (__wchar_t *)wcsrchr((const __wchar_t *)_Str, _Ch); } 
inline __wchar_t *__cdecl wcsstr(__wchar_t *_Str, const __wchar_t *_SubStr) 
{ return (__wchar_t *)wcsstr((const __wchar_t *)_Str, _SubStr); } 
#line 349 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
extern "C" { extern __wchar_t *__cdecl wcsdup(const __wchar_t *); } 
#line 359 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\string.h"
extern "C" { extern int __cdecl wcsicmp(const __wchar_t *, const __wchar_t *); } 
extern "C" { extern int __cdecl wcsnicmp(const __wchar_t *, const __wchar_t *, size_t); } 
extern "C" { extern __wchar_t *__cdecl wcsnset(__wchar_t *, __wchar_t, size_t); } 
extern "C" { extern __wchar_t *__cdecl wcsrev(__wchar_t *); } 
extern "C" { extern __wchar_t *__cdecl wcsset(__wchar_t *, __wchar_t); } 
extern "C" { extern __wchar_t *__cdecl wcslwr(__wchar_t *); } 
extern "C" { extern __wchar_t *__cdecl wcsupr(__wchar_t *); } 
extern "C" { extern int __cdecl wcsicoll(const __wchar_t *, const __wchar_t *); } 
#line 56 "d:\\my\\work\\cuda\\64\\tk\\include\\common_functions.h"
extern "C" { extern clock_t clock(); } 


extern "C" { extern void *memset(void *, int, size_t); } 


extern "C" { extern void *memcpy(void *, const void *, size_t); } 
#line 65 "d:\\my\\work\\cuda\\64\\tk\\include\\math_functions.h"
extern "C" { extern int abs(int); } 

extern "C" { extern long labs(long); } 

extern "C" { extern __int64 llabs(__int64); } 

extern "C" { extern double fabs(double); } 

extern "C" { inline float fabsf(float); } 


extern "C" { extern int min(int, int); } 

extern "C" { extern unsigned umin(unsigned, unsigned); } 

extern "C" { extern __int64 llmin(__int64, __int64); } 

extern "C" { extern unsigned __int64 ullmin(unsigned __int64, unsigned __int64); } 

extern "C" { extern float fminf(float, float); } 

extern "C" { extern double fmin(double, double); } 


extern "C" { extern int max(int, int); } 

extern "C" { extern unsigned umax(unsigned, unsigned); } 

extern "C" { extern __int64 llmax(__int64, __int64); } 

extern "C" { extern unsigned __int64 ullmax(unsigned __int64, unsigned __int64); } 

extern "C" { extern float fmaxf(float, float); } 

extern "C" { extern double fmax(double, double); } 


extern "C" { extern double sin(double); } 

extern "C" { extern float sinf(float); } 


extern "C" { extern double cos(double); } 

extern "C" { extern float cosf(float); } 


extern "C" { extern void sincos(double, double *, double *); } 

extern "C" { extern void sincosf(float, float *, float *); } 


extern "C" { extern double tan(double); } 

extern "C" { extern float tanf(float); } 


extern "C" { extern double sqrt(double); } 

extern "C" { extern float sqrtf(float); } 


extern "C" { extern double rsqrt(double); } 

extern "C" { extern float rsqrtf(float); } 


extern "C" { extern double exp2(double); } 

extern "C" { extern float exp2f(float); } 


extern "C" { extern double exp10(double); } 

extern "C" { extern float exp10f(float); } 


extern "C" { extern double expm1(double); } 

extern "C" { extern float expm1f(float); } 


extern "C" { extern double log2(double); } 

extern "C" { extern float log2f(float); } 


extern "C" { extern double log10(double); } 

extern "C" { extern float log10f(float); } 


extern "C" { extern double log(double); } 

extern "C" { extern float logf(float); } 


extern "C" { extern double log1p(double); } 

extern "C" { extern float log1pf(float); } 


extern "C" { extern double floor(double); } 

extern "C" { extern float floorf(float); } 


extern "C" { extern double exp(double); } 

extern "C" { extern float expf(float); } 


extern "C" { extern double cosh(double); } 

extern "C" { extern float coshf(float); } 


extern "C" { extern double sinh(double); } 

extern "C" { extern float sinhf(float); } 


extern "C" { extern double tanh(double); } 

extern "C" { extern float tanhf(float); } 


extern "C" { extern double acosh(double); } 

extern "C" { extern float acoshf(float); } 


extern "C" { extern double asinh(double); } 

extern "C" { extern float asinhf(float); } 


extern "C" { extern double atanh(double); } 

extern "C" { extern float atanhf(float); } 


extern "C" { extern double ldexp(double, int); } 

extern "C" { inline float ldexpf(float, int); } 


extern "C" { extern double logb(double); } 

extern "C" { extern float logbf(float); } 


extern "C" { extern int ilogb(double); } 

extern "C" { extern int ilogbf(float); } 


extern "C" { extern double scalbn(double, int); } 

extern "C" { extern float scalbnf(float, int); } 


extern "C" { extern double scalbln(double, long); } 

extern "C" { extern float scalblnf(float, long); } 


extern "C" { extern double frexp(double, int *); } 

extern "C" { inline float frexpf(float, int *); } 


extern "C" { extern double round(double); } 

extern "C" { extern float roundf(float); } 


extern "C" { extern long lround(double); } 

extern "C" { extern long lroundf(float); } 


extern "C" { extern __int64 llround(double); } 

extern "C" { extern __int64 llroundf(float); } 


extern "C" { extern double rint(double); } 

extern "C" { extern float rintf(float); } 


extern "C" { extern long lrint(double); } 

extern "C" { extern long lrintf(float); } 


extern "C" { extern __int64 llrint(double); } 

extern "C" { extern __int64 llrintf(float); } 


extern "C" { extern double nearbyint(double); } 

extern "C" { extern float nearbyintf(float); } 


extern "C" { extern double ceil(double); } 

extern "C" { extern float ceilf(float); } 


extern "C" { extern double trunc(double); } 

extern "C" { extern float truncf(float); } 


extern "C" { extern double fdim(double, double); } 

extern "C" { extern float fdimf(float, float); } 


extern "C" { extern double atan2(double, double); } 

extern "C" { extern float atan2f(float, float); } 


extern "C" { extern double atan(double); } 

extern "C" { extern float atanf(float); } 


extern "C" { extern double asin(double); } 

extern "C" { extern float asinf(float); } 


extern "C" { extern double acos(double); } 

extern "C" { extern float acosf(float); } 


extern "C" { extern double hypot(double, double); } 

extern "C" { extern float hypotf(float, float); } 


extern "C" { extern double cbrt(double); } 

extern "C" { extern float cbrtf(float); } 


extern "C" { extern double pow(double, double); } 

extern "C" { extern float powf(float, float); } 


extern "C" { extern double modf(double, double *); } 

extern "C" { extern float modff(float, float *); } 


extern "C" { extern double fmod(double, double); } 

extern "C" { extern float fmodf(float, float); } 


extern "C" { extern double remainder(double, double); } 

extern "C" { extern float remainderf(float, float); } 


extern "C" { extern double remquo(double, double, int *); } 

extern "C" { extern float remquof(float, float, int *); } 


extern "C" { extern double erf(double); } 

extern "C" { extern float erff(float); } 


extern "C" { extern double erfinv(double); } 

extern "C" { extern float erfinvf(float); } 


extern "C" { extern double erfc(double); } 

extern "C" { extern float erfcf(float); } 


extern "C" { extern double erfcinv(double); } 

extern "C" { extern float erfcinvf(float); } 


extern "C" { extern double lgamma(double); } 

extern "C" { extern float lgammaf(float); } 


extern "C" { extern double tgamma(double); } 

extern "C" { extern float tgammaf(float); } 


extern "C" { extern double copysign(double, double); } 

extern "C" { extern float copysignf(float, float); } 


extern "C" { extern double nextafter(double, double); } 

extern "C" { extern float nextafterf(float, float); } 


extern "C" { extern double nan(const char *); } 

extern "C" { extern float nanf(const char *); } 


extern "C" { extern int __isinf(double); } 

extern "C" { extern int __isinff(float); } 


extern "C" { extern int __isnan(double); } 

extern "C" { extern int __isnanf(float); } 
#line 408
extern "C" { extern int __finite(double); } 

extern "C" { extern int __finitef(float); } 

extern "C" { extern int __signbit(double); } 
#line 417 "d:\\my\\work\\cuda\\64\\tk\\include\\math_functions.h"
extern "C" { extern int __signbitf(float); } 


extern "C" { extern double fma(double, double, double); } 

extern "C" { extern float fmaf(float, float, float); } 
#line 25 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\math.h"
#pragma pack ( push, 8 )
#line 39 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\math.h"
extern "C" { struct _exception { 
int type; 
char *name; 
double arg1; 
double arg2; 
double retval; 
}; }
#line 56 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\math.h"
extern "C" { struct _complex { 
double x; double y; 
}; }
#line 90 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\math.h"
extern "C" double _HUGE; 
#line 103 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\math.h"
extern "C" { extern int __cdecl abs(int); } 
extern "C" { extern long __cdecl labs(long); } 
#line 107 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\math.h"
extern "C" { extern double __cdecl acos(double); } 
extern "C" { extern double __cdecl asin(double); } 
extern "C" { extern double __cdecl atan(double); } 
extern "C" { extern double __cdecl atan2(double, double); } 

extern "C" { extern double __cdecl _copysign(double, double); } 
extern "C" { extern double __cdecl _chgsign(double); } 
#line 116 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\math.h"
extern "C" { extern double __cdecl cos(double); } 
extern "C" { extern double __cdecl cosh(double); } 
extern "C" { extern double __cdecl exp(double); } 
extern "C" { extern double __cdecl fabs(double); } 
extern "C" { extern double __cdecl fmod(double, double); } 
extern "C" { extern double __cdecl log(double); } 
extern "C" { extern double __cdecl log10(double); } 
extern "C" { extern double __cdecl pow(double, double); } 
extern "C" { extern double __cdecl sin(double); } 
extern "C" { extern double __cdecl sinh(double); } 
extern "C" { extern double __cdecl tan(double); } 
extern "C" { extern double __cdecl tanh(double); } 
extern "C" { extern double __cdecl sqrt(double); } 


extern "C" { extern double __cdecl atof(const char *); } 
extern "C" { extern double __cdecl _atof_l(const char *, _locale_t); } 
#line 135 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\math.h"
extern "C" { extern double __cdecl _cabs(_complex); } 
extern "C" { extern double __cdecl ceil(double); } 
extern "C" { extern double __cdecl floor(double); } 
extern "C" { extern double __cdecl frexp(double, int *); } 
extern "C" { extern double __cdecl _hypot(double, double); } 
extern "C" { extern double __cdecl _j0(double); } 
extern "C" { extern double __cdecl _j1(double); } 
extern "C" { extern double __cdecl _jn(int, double); } 
extern "C" { extern double __cdecl ldexp(double, int); } 
#line 149 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\math.h"
extern "C" { extern int __cdecl _matherr(_exception *); } 
#line 152 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\math.h"
extern "C" { extern double __cdecl modf(double, double *); } 

extern "C" { extern double __cdecl _y0(double); } 
extern "C" { extern double __cdecl _y1(double); } 
extern "C" { extern double __cdecl _yn(int, double); } 
#line 212 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\math.h"
extern "C" { extern float __cdecl acosf(float); } 
extern "C" { extern float __cdecl asinf(float); } 
extern "C" { extern float __cdecl atanf(float); } 
extern "C" { extern float __cdecl atan2f(float, float); } 
extern "C" { extern float __cdecl cosf(float); } 
extern "C" { extern float __cdecl sinf(float); } 
extern "C" { extern float __cdecl tanf(float); } 


extern "C" { extern float __cdecl coshf(float); } 
extern "C" { extern float __cdecl sinhf(float); } 
extern "C" { extern float __cdecl tanhf(float); } 


extern "C" { extern float __cdecl expf(float); } 
extern "C" { extern float __cdecl logf(float); } 
extern "C" { extern float __cdecl log10f(float); } 
extern "C" { extern float __cdecl modff(float, float *); } 


extern "C" { extern float __cdecl powf(float, float); } 
extern "C" { extern float __cdecl sqrtf(float); } 


extern "C" { extern float __cdecl ceilf(float); } 
extern "C" { extern float __cdecl floorf(float); } 
extern "C" { extern float __cdecl fmodf(float, float); } 

extern "C" { extern float __cdecl _hypotf(float, float); } 

extern "C" { extern float __cdecl _copysignf(float, float); } 
extern "C" { extern float __cdecl _chgsignf(float); } 
extern "C" { extern float __cdecl _logbf(float); } 
extern "C" { extern float __cdecl _nextafterf(float, float); } 
extern "C" { extern int __cdecl _finitef(float); } 
extern "C" { extern int __cdecl _isnanf(float); } 
extern "C" { extern int __cdecl _fpclassf(float); } 
#line 317 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\math.h"
extern "C" { inline long double acosl(long double _X) 
{ return acos((double)_X); } } 
extern "C" { inline long double asinl(long double _X) 
{ return asin((double)_X); } } 
extern "C" { inline long double atanl(long double _X) 
{ return atan((double)_X); } } 
extern "C" { inline long double atan2l(long double _Y, long double _X) 
{ return atan2((double)_Y, (double)_X); } } 
extern "C" { inline long double ceill(long double _X) 
{ return ceil((double)_X); } } 
extern "C" { inline long double cosl(long double _X) 
{ return cos((double)_X); } } 
extern "C" { inline long double coshl(long double _X) 
{ return cosh((double)_X); } } 
extern "C" { inline long double expl(long double _X) 
{ return exp((double)_X); } } 
extern "C" { inline long double fabsl(long double _X) 
{ return fabs((double)_X); } } 
extern "C" { inline long double floorl(long double _X) 
{ return floor((double)_X); } } 
extern "C" { inline long double fmodl(long double _X, long double _Y) 
{ return fmod((double)_X, (double)_Y); } } 
extern "C" { inline long double frexpl(long double _X, int *_Y) 
{ return frexp((double)_X, _Y); } } 
extern "C" { inline long double ldexpl(long double _X, int _Y) 
{ return ldexp((double)_X, _Y); } } 
extern "C" { inline long double logl(long double _X) 
{ return log((double)_X); } } 
extern "C" { inline long double log10l(long double _X) 
{ return log10((double)_X); } } 
extern "C" { inline long double modfl(long double _X, long double *_Y) 
{ auto double _Di; auto double _Df = modf((double)_X, &_Di); 
(*_Y) = (long double)_Di; 
return _Df; } } 
extern "C" { inline long double powl(long double _X, long double _Y) 
{ return pow((double)_X, (double)_Y); } } 
extern "C" { inline long double sinl(long double _X) 
{ return sin((double)_X); } } 
extern "C" { inline long double sinhl(long double _X) 
{ return sinh((double)_X); } } 
extern "C" { inline long double sqrtl(long double _X) 
{ return sqrt((double)_X); } } 

extern "C" { inline long double tanl(long double _X) 
{ return tan((double)_X); } } 
#line 366 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\math.h"
extern "C" { inline long double tanhl(long double _X) 
{ return tanh((double)_X); } } 

extern "C" { inline long double _chgsignl(long double _Number) 
{ 
return _chgsign(static_cast< double>(_Number)); 
} } 

extern "C" { inline long double _copysignl(long double _Number, long double _Sign) 
{ 
return _copysign(static_cast< double>(_Number), static_cast< double>(_Sign)); 
} } 

extern "C" { inline float frexpf(float _X, int *_Y) 
{ return (float)frexp((double)_X, _Y); } } 


extern "C" { inline float fabsf(float _X) 
{ return (float)fabs((double)_X); } } 
extern "C" { inline float ldexpf(float _X, int _Y) 
{ return (float)ldexp((double)_X, _Y); } } 
#line 449 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\math.h"
extern "C" double HUGE; 
#line 454 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\math.h"
extern "C" { extern double __cdecl cabs(_complex); } 
extern "C" { extern double __cdecl hypot(double, double); } 
extern "C" { extern double __cdecl j0(double); } 
extern "C" { extern double __cdecl j1(double); } 
extern "C" { extern double __cdecl jn(int, double); } 
extern "C" { extern double __cdecl y0(double); } 
extern "C" { extern double __cdecl y1(double); } 
extern "C" { extern double __cdecl yn(int, double); } 
#line 472 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\math.h"
template < class _Ty > inline
        _Ty _Pow_int ( _Ty _X, int _Y )
        { unsigned int _N;
        if ( _Y >= 0 )
                _N = ( unsigned int ) _Y;
        else
                _N = ( unsigned int ) ( - _Y );
        for ( _Ty _Z = _Ty ( 1 );; _X *= _X )
                { if ( ( _N & 1 ) != 0 )
                        _Z *= _X;
                if ( ( _N >>= 1 ) == 0 )
                        return ( _Y < 0 ? _Ty ( 1 ) / _Z : _Z ); } }

inline long __cdecl abs(long _X) 
{ return labs(_X); } 
inline double __cdecl abs(double _X) 
{ return fabs(_X); } 
inline double __cdecl pow(double _X, int _Y) 
{ return _Pow_int(_X, _Y); } 
inline float __cdecl abs(float _X) 
{ return fabsf(_X); } 
inline float __cdecl acos(float _X) 
{ return acosf(_X); } 
inline float __cdecl asin(float _X) 
{ return asinf(_X); } 
inline float __cdecl atan(float _X) 
{ return atanf(_X); } 
inline float __cdecl atan2(float _Y, float _X) 
{ return atan2f(_Y, _X); } 
inline float __cdecl ceil(float _X) 
{ return ceilf(_X); } 
inline float __cdecl cos(float _X) 
{ return cosf(_X); } 
inline float __cdecl cosh(float _X) 
{ return coshf(_X); } 
inline float __cdecl exp(float _X) 
{ return expf(_X); } 
inline float __cdecl fabs(float _X) 
{ return fabsf(_X); } 
inline float __cdecl floor(float _X) 
{ return floorf(_X); } 
inline float __cdecl fmod(float _X, float _Y) 
{ return fmodf(_X, _Y); } 
inline float __cdecl frexp(float _X, int *_Y) 
{ return frexpf(_X, _Y); } 
inline float __cdecl ldexp(float _X, int _Y) 
{ return ldexpf(_X, _Y); } 
inline float __cdecl log(float _X) 
{ return logf(_X); } 
inline float __cdecl log10(float _X) 
{ return log10f(_X); } 
inline float __cdecl modf(float _X, float *_Y) 
{ return modff(_X, _Y); } 
inline float __cdecl pow(float _X, float _Y) 
{ return powf(_X, _Y); } 
inline float __cdecl pow(float _X, int _Y) 
{ return _Pow_int(_X, _Y); } 
inline float __cdecl sin(float _X) 
{ return sinf(_X); } 
inline float __cdecl sinh(float _X) 
{ return sinhf(_X); } 
inline float __cdecl sqrt(float _X) 
{ return sqrtf(_X); } 
inline float __cdecl tan(float _X) 
{ return tanf(_X); } 
inline float __cdecl tanh(float _X) 
{ return tanhf(_X); } 
inline long double __cdecl abs(long double _X) 
{ return fabsl(_X); } 
inline long double __cdecl acos(long double _X) 
{ return acosl(_X); } 
inline long double __cdecl asin(long double _X) 
{ return asinl(_X); } 
inline long double __cdecl atan(long double _X) 
{ return atanl(_X); } 
inline long double __cdecl atan2(long double _Y, long double _X) 
{ return atan2l(_Y, _X); } 
inline long double __cdecl ceil(long double _X) 
{ return ceill(_X); } 
inline long double __cdecl cos(long double _X) 
{ return cosl(_X); } 
inline long double __cdecl cosh(long double _X) 
{ return coshl(_X); } 
inline long double __cdecl exp(long double _X) 
{ return expl(_X); } 
inline long double __cdecl fabs(long double _X) 
{ return fabsl(_X); } 
inline long double __cdecl floor(long double _X) 
{ return floorl(_X); } 
inline long double __cdecl fmod(long double _X, long double _Y) 
{ return fmodl(_X, _Y); } 
inline long double __cdecl frexp(long double _X, int *_Y) 
{ return frexpl(_X, _Y); } 
inline long double __cdecl ldexp(long double _X, int _Y) 
{ return ldexpl(_X, _Y); } 
inline long double __cdecl log(long double _X) 
{ return logl(_X); } 
inline long double __cdecl log10(long double _X) 
{ return log10l(_X); } 
inline long double __cdecl modf(long double _X, long double *_Y) 
{ return modfl(_X, _Y); } 
inline long double __cdecl pow(long double _X, long double _Y) 
{ return powl(_X, _Y); } 
inline long double __cdecl pow(long double _X, int _Y) 
{ return _Pow_int(_X, _Y); } 
inline long double __cdecl sin(long double _X) 
{ return sinl(_X); } 
inline long double __cdecl sinh(long double _X) 
{ return sinhl(_X); } 
inline long double __cdecl sqrt(long double _X) 
{ return sqrtl(_X); } 
inline long double __cdecl tan(long double _X) 
{ return tanl(_X); } 
inline long double __cdecl tanh(long double _X) 
{ return tanhl(_X); } 
#line 592 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\math.h"
#pragma pack ( pop )
#line 31 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
#pragma pack ( push, 8 )
#line 56 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { typedef int (__cdecl *_onexit_t)(void); }
#line 82 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { typedef 
#line 79
struct _div_t { 
int quot; 
int rem; 
} div_t; }




extern "C" { typedef 
#line 84
struct _ldiv_t { 
long quot; 
long rem; 
} ldiv_t; }
#line 101 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
#pragma pack ( 4 )


extern "C" { typedef 
#line 102
struct _LDOUBLE { 
unsigned char ld[10]; 
} _LDOUBLE; }
#pragma pack ( )
#line 123 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { typedef 
#line 121
struct _CRT_DOUBLE { 
double x; 
} _CRT_DOUBLE; }



extern "C" { typedef 
#line 125
struct _CRT_FLOAT { 
float f; 
} _CRT_FLOAT; }
#line 138
extern "C" { typedef 
#line 133
struct _LONGDOUBLE { 



long double x; 
} _LONGDOUBLE; }



#pragma pack ( 4 )


extern "C" { typedef 
#line 143
struct _LDBL12 { 
unsigned char ld12[12]; 
} _LDBL12; }
#pragma pack ( )
#line 166 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" int __mb_cur_max; 
#line 171 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern int __cdecl ___mb_cur_max_func(); } 
extern "C" { extern int __cdecl ___mb_cur_max_l_func(_locale_t); } 
#line 211 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { typedef void (__cdecl *_purecall_handler)(void); }


extern "C" { extern _purecall_handler __cdecl _set_purecall_handler(_purecall_handler); } 
extern "C" { extern _purecall_handler __cdecl _get_purecall_handler(); } 
#line 239 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { typedef void (__cdecl *_invalid_parameter_handler)(const __wchar_t *, const __wchar_t *, const __wchar_t *, unsigned, uintptr_t); }


extern "C" { extern _invalid_parameter_handler __cdecl _set_invalid_parameter_handler(_invalid_parameter_handler); } 
extern "C" { extern _invalid_parameter_handler __cdecl _get_invalid_parameter_handler(); } 
#line 274 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern unsigned long *__cdecl __doserrno(); } 


extern "C" { extern errno_t __cdecl _set_doserrno(unsigned long); } 
extern "C" { extern errno_t __cdecl _get_doserrno(unsigned long *); } 


extern "C" { extern char **__cdecl __sys_errlist(); } 


extern "C" { extern int *__cdecl __sys_nerr(); } 
#line 301 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" int __argc; 
extern "C" char **__argv; 
extern "C" __wchar_t **__wargv; 
#line 317 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" char **_environ; 
extern "C" __wchar_t **_wenviron; 
#line 321 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" char *_pgmptr; 
extern "C" __wchar_t *_wpgmptr; 
#line 339 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern errno_t __cdecl _get_pgmptr(char **); } 
extern "C" { extern errno_t __cdecl _get_wpgmptr(__wchar_t **); } 



extern "C" int _fmode; 
#line 350 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern errno_t __cdecl _set_fmode(int); } 
extern "C" { extern errno_t __cdecl _get_fmode(int *); } 
#line 360 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
template<class _CountofType, size_t _SizeOfArray> extern char (*__countof_helper(__unaligned _CountofType (&)[_SizeOfArray]))[_SizeOfArray]; 
#line 371 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern __declspec( noreturn ) void __cdecl exit(int); } 
extern "C" { extern __declspec( noreturn ) void __cdecl _exit(int); } 
extern "C" { extern void __cdecl abort(); } 
#line 376 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern unsigned __cdecl _set_abort_behavior(unsigned, unsigned); } 
#line 384
extern "C" { extern __int64 __cdecl _abs64(__int64); } 
#line 412 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern int __cdecl atexit(void (__cdecl *)(void)); } 
#line 419 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern int __cdecl atoi(const char *); } 
extern "C" { extern int __cdecl _atoi_l(const char *, _locale_t); } 
extern "C" { extern long __cdecl atol(const char *); } 
extern "C" { extern long __cdecl _atol_l(const char *, _locale_t); } 



extern "C" { extern void *__cdecl bsearch_s(const void *, const void *, rsize_t, rsize_t, int (__cdecl *)(void *, const void *, const void *), void *); } 
#line 430 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern void *__cdecl bsearch(const void *, const void *, size_t, size_t, int (__cdecl *)(const void *, const void *)); } 




extern "C" { extern void __cdecl qsort_s(void *, rsize_t, rsize_t, int (__cdecl *)(void *, const void *, const void *), void *); } 
#line 439 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern void __cdecl qsort(void *, size_t, size_t, int (__cdecl *)(const void *, const void *)); } 
#line 443 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern unsigned short __cdecl _byteswap_ushort(unsigned short); } 
extern "C" { extern unsigned long __cdecl _byteswap_ulong(unsigned long); } 
extern "C" { extern unsigned __int64 __cdecl _byteswap_uint64(unsigned __int64); } 
extern "C" { extern div_t __cdecl div(int, int); } 
extern "C" { extern char *__cdecl getenv(const char *); } 

extern "C" { extern errno_t __cdecl getenv_s(size_t *, char *, rsize_t, const char *); } 
#line 451 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
template < size_t _Size > inline errno_t __cdecl getenv_s ( size_t * _ReturnSize, char ( & _Dest ) [ _Size ], const char * _VarName ) { return getenv_s ( _ReturnSize, _Dest, _Size, _VarName ); }
#line 457 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern errno_t __cdecl _dupenv_s(char **, size_t *, const char *); } 
#line 463 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern errno_t __cdecl _itoa_s(int, char *, size_t, int); } 
template < size_t _Size > inline errno_t __cdecl _itoa_s ( int _Value, char ( & _Dest ) [ _Size ], int _Radix ) { return _itoa_s ( _Value, _Dest, _Size, _Radix ); }
extern "C" { extern char *__cdecl _itoa(int, char *, int); } 
extern "C" { extern errno_t __cdecl _i64toa_s(__int64, char *, size_t, int); } 
extern "C" { extern char *__cdecl _i64toa(__int64, char *, int); } 
extern "C" { extern errno_t __cdecl _ui64toa_s(unsigned __int64, char *, size_t, int); } 
extern "C" { extern char *__cdecl _ui64toa(unsigned __int64, char *, int); } 
extern "C" { extern __int64 __cdecl _atoi64(const char *); } 
extern "C" { extern __int64 __cdecl _atoi64_l(const char *, _locale_t); } 
extern "C" { extern __int64 __cdecl _strtoi64(const char *, char **, int); } 
extern "C" { extern __int64 __cdecl _strtoi64_l(const char *, char **, int, _locale_t); } 
extern "C" { extern unsigned __int64 __cdecl _strtoui64(const char *, char **, int); } 
extern "C" { extern unsigned __int64 __cdecl _strtoui64_l(const char *, char **, int, _locale_t); } 
extern "C" { extern ldiv_t __cdecl ldiv(long, long); } 



inline ldiv_t div(long _A1, long _A2) 
{ 
return ldiv(_A1, _A2); 
} 
#line 486 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern errno_t __cdecl _ltoa_s(long, char *, size_t, int); } 
template < size_t _Size > inline errno_t __cdecl _ltoa_s ( long _Value, char ( & _Dest ) [ _Size ], int _Radix ) { return _ltoa_s ( _Value, _Dest, _Size, _Radix ); }
extern "C" { extern char *__cdecl _ltoa(long, char *, int); } 
extern "C" { extern int __cdecl mblen(const char *, size_t); } 
extern "C" { extern int __cdecl _mblen_l(const char *, size_t, _locale_t); } 
extern "C" { extern size_t __cdecl _mbstrlen(const char *); } 
extern "C" { extern size_t __cdecl _mbstrlen_l(const char *, _locale_t); } 
extern "C" { extern size_t __cdecl _mbstrnlen(const char *, size_t); } 
extern "C" { extern size_t __cdecl _mbstrnlen_l(const char *, size_t, _locale_t); } 
extern "C" { extern int __cdecl mbtowc(__wchar_t *, const char *, size_t); } 
extern "C" { extern int __cdecl _mbtowc_l(__wchar_t *, const char *, size_t, _locale_t); } 
extern "C" { extern errno_t __cdecl mbstowcs_s(size_t *, __wchar_t *, size_t, const char *, size_t); } 
template < size_t _Size > inline errno_t __cdecl mbstowcs_s ( size_t * _PtNumOfCharConverted, wchar_t ( & _Dest ) [ _Size ], const char * _Source, size_t _MaxCount ) { return mbstowcs_s ( _PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount ); }
extern "C" { extern size_t __cdecl mbstowcs(__wchar_t *, const char *, size_t); } 

extern "C" { extern errno_t __cdecl _mbstowcs_s_l(size_t *, __wchar_t *, size_t, const char *, size_t, _locale_t); } 
template < size_t _Size > inline errno_t __cdecl _mbstowcs_s_l ( size_t * _PtNumOfCharConverted, wchar_t ( & _Dest ) [ _Size ], const char * _Source, size_t _MaxCount, _locale_t _Locale ) { return _mbstowcs_s_l ( _PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount, _Locale ); }
extern "C" { extern size_t __cdecl _mbstowcs_l(__wchar_t *, const char *, size_t, _locale_t); } 

extern "C" { extern int __cdecl rand(); } 
#line 510 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern int __cdecl _set_error_mode(int); } 

extern "C" { extern void __cdecl srand(unsigned); } 
extern "C" { extern double __cdecl strtod(const char *, char **); } 
extern "C" { extern double __cdecl _strtod_l(const char *, char **, _locale_t); } 
extern "C" { extern long __cdecl strtol(const char *, char **, int); } 
extern "C" { extern long __cdecl _strtol_l(const char *, char **, int, _locale_t); } 
extern "C" { extern unsigned long __cdecl strtoul(const char *, char **, int); } 
extern "C" { extern unsigned long __cdecl _strtoul_l(const char *, char **, int, _locale_t); } 


extern "C" { extern int __cdecl system(const char *); } 
#line 523 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern errno_t __cdecl _ultoa_s(unsigned long, char *, size_t, int); } 
template < size_t _Size > inline errno_t __cdecl _ultoa_s ( unsigned long _Value, char ( & _Dest ) [ _Size ], int _Radix ) { return _ultoa_s ( _Value, _Dest, _Size, _Radix ); }
extern "C" { extern char *__cdecl _ultoa(unsigned long, char *, int); } 
extern "C" { extern int __cdecl wctomb(char *, __wchar_t); } 
extern "C" { extern int __cdecl _wctomb_l(char *, __wchar_t, _locale_t); } 

extern "C" { extern errno_t __cdecl wctomb_s(int *, char *, rsize_t, __wchar_t); } 
#line 531 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern errno_t __cdecl _wctomb_s_l(int *, char *, size_t, __wchar_t, _locale_t); } 
extern "C" { extern errno_t __cdecl wcstombs_s(size_t *, char *, size_t, const __wchar_t *, size_t); } 
template < size_t _Size > inline errno_t __cdecl wcstombs_s ( size_t * _PtNumOfCharConverted, char ( & _Dest ) [ _Size ], const wchar_t * _Source, size_t _MaxCount ) { return wcstombs_s ( _PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount ); }
extern "C" { extern size_t __cdecl wcstombs(char *, const __wchar_t *, size_t); } 
extern "C" { extern errno_t __cdecl _wcstombs_s_l(size_t *, char *, size_t, const __wchar_t *, size_t, _locale_t); } 
template < size_t _Size > inline errno_t __cdecl _wcstombs_s_l ( size_t * _PtNumOfCharConverted, char ( & _Dest ) [ _Size ], const wchar_t * _Source, size_t _MaxCount, _locale_t _Locale ) { return _wcstombs_s_l ( _PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount, _Locale ); }
extern "C" { extern size_t __cdecl _wcstombs_l(char *, const __wchar_t *, size_t, _locale_t); } 
#line 599 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern void *__cdecl calloc(size_t, size_t); } 
extern "C" { extern void __cdecl free(void *); } 
extern "C" { extern void *__cdecl malloc(size_t); } 
extern "C" { extern void *__cdecl realloc(void *, size_t); } 
extern "C" { extern void *__cdecl _recalloc(void *, size_t, size_t); } 
extern "C" { extern void __cdecl _aligned_free(void *); } 
extern "C" { extern void *__cdecl _aligned_malloc(size_t, size_t); } 
extern "C" { extern void *__cdecl _aligned_offset_malloc(size_t, size_t, size_t); } 
extern "C" { extern void *__cdecl _aligned_realloc(void *, size_t, size_t); } 
extern "C" { extern void *__cdecl _aligned_recalloc(void *, size_t, size_t, size_t); } 
extern "C" { extern void *__cdecl _aligned_offset_realloc(void *, size_t, size_t, size_t); } 
extern "C" { extern void *__cdecl _aligned_offset_recalloc(void *, size_t, size_t, size_t, size_t); } 
extern "C" { extern size_t __cdecl _aligned_msize(void *, size_t, size_t); } 
#line 638 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern errno_t __cdecl _itow_s(int, __wchar_t *, size_t, int); } 
template < size_t _Size > inline errno_t __cdecl _itow_s ( int _Value, wchar_t ( & _Dest ) [ _Size ], int _Radix ) { return _itow_s ( _Value, _Dest, _Size, _Radix ); }
extern "C" { extern __wchar_t *__cdecl _itow(int, __wchar_t *, int); } 
extern "C" { extern errno_t __cdecl _ltow_s(long, __wchar_t *, size_t, int); } 
template < size_t _Size > inline errno_t __cdecl _ltow_s ( long _Value, wchar_t ( & _Dest ) [ _Size ], int _Radix ) { return _ltow_s ( _Value, _Dest, _Size, _Radix ); }
extern "C" { extern __wchar_t *__cdecl _ltow(long, __wchar_t *, int); } 
extern "C" { extern errno_t __cdecl _ultow_s(unsigned long, __wchar_t *, size_t, int); } 
template < size_t _Size > inline errno_t __cdecl _ultow_s ( unsigned long _Value, wchar_t ( & _Dest ) [ _Size ], int _Radix ) { return _ultow_s ( _Value, _Dest, _Size, _Radix ); }
extern "C" { extern __wchar_t *__cdecl _ultow(unsigned long, __wchar_t *, int); } 
extern "C" { extern double __cdecl wcstod(const __wchar_t *, __wchar_t **); } 
extern "C" { extern double __cdecl _wcstod_l(const __wchar_t *, __wchar_t **, _locale_t); } 
extern "C" { extern long __cdecl wcstol(const __wchar_t *, __wchar_t **, int); } 
extern "C" { extern long __cdecl _wcstol_l(const __wchar_t *, __wchar_t **, int, _locale_t); } 
extern "C" { extern unsigned long __cdecl wcstoul(const __wchar_t *, __wchar_t **, int); } 
extern "C" { extern unsigned long __cdecl _wcstoul_l(const __wchar_t *, __wchar_t **, int, _locale_t); } 
extern "C" { extern __wchar_t *__cdecl _wgetenv(const __wchar_t *); } 
extern "C" { extern errno_t __cdecl _wgetenv_s(size_t *, __wchar_t *, size_t, const __wchar_t *); } 
template < size_t _Size > inline errno_t __cdecl _wgetenv_s ( size_t * _ReturnSize, wchar_t ( & _Dest ) [ _Size ], const wchar_t * _VarName ) { return _wgetenv_s ( _ReturnSize, _Dest, _Size, _VarName ); }
#line 662 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern errno_t __cdecl _wdupenv_s(__wchar_t **, size_t *, const __wchar_t *); } 
#line 670 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern int __cdecl _wsystem(const __wchar_t *); } 
#line 672 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern double __cdecl _wtof(const __wchar_t *); } 
extern "C" { extern double __cdecl _wtof_l(const __wchar_t *, _locale_t); } 
extern "C" { extern int __cdecl _wtoi(const __wchar_t *); } 
extern "C" { extern int __cdecl _wtoi_l(const __wchar_t *, _locale_t); } 
extern "C" { extern long __cdecl _wtol(const __wchar_t *); } 
extern "C" { extern long __cdecl _wtol_l(const __wchar_t *, _locale_t); } 

extern "C" { extern errno_t __cdecl _i64tow_s(__int64, __wchar_t *, size_t, int); } 
extern "C" { extern __wchar_t *__cdecl _i64tow(__int64, __wchar_t *, int); } 
extern "C" { extern errno_t __cdecl _ui64tow_s(unsigned __int64, __wchar_t *, size_t, int); } 
extern "C" { extern __wchar_t *__cdecl _ui64tow(unsigned __int64, __wchar_t *, int); } 
extern "C" { extern __int64 __cdecl _wtoi64(const __wchar_t *); } 
extern "C" { extern __int64 __cdecl _wtoi64_l(const __wchar_t *, _locale_t); } 
extern "C" { extern __int64 __cdecl _wcstoi64(const __wchar_t *, __wchar_t **, int); } 
extern "C" { extern __int64 __cdecl _wcstoi64_l(const __wchar_t *, __wchar_t **, int, _locale_t); } 
extern "C" { extern unsigned __int64 __cdecl _wcstoui64(const __wchar_t *, __wchar_t **, int); } 
extern "C" { extern unsigned __int64 __cdecl _wcstoui64_l(const __wchar_t *, __wchar_t **, int, _locale_t); } 
#line 708 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern char *__cdecl _fullpath(char *, const char *, size_t); } 
#line 716 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern errno_t __cdecl _ecvt_s(char *, size_t, double, int, int *, int *); } 
template < size_t _Size > inline errno_t __cdecl _ecvt_s ( char ( & _Dest ) [ _Size ], double _Value, int _NumOfDigits, int * _PtDec, int * _PtSign ) { return _ecvt_s ( _Dest, _Size, _Value, _NumOfDigits, _PtDec, _PtSign ); }
extern "C" { extern char *__cdecl _ecvt(double, int, int *, int *); } 
extern "C" { extern errno_t __cdecl _fcvt_s(char *, size_t, double, int, int *, int *); } 
template < size_t _Size > inline errno_t __cdecl _fcvt_s ( char ( & _Dest ) [ _Size ], double _Value, int _NumOfDigits, int * _PtDec, int * _PtSign ) { return _fcvt_s ( _Dest, _Size, _Value, _NumOfDigits, _PtDec, _PtSign ); }
extern "C" { extern char *__cdecl _fcvt(double, int, int *, int *); } 
extern "C" { extern errno_t __cdecl _gcvt_s(char *, size_t, double, int); } 
template < size_t _Size > inline errno_t __cdecl _gcvt_s ( char ( & _Dest ) [ _Size ], double _Value, int _NumOfDigits ) { return _gcvt_s ( _Dest, _Size, _Value, _NumOfDigits ); }
extern "C" { extern char *__cdecl _gcvt(double, int, char *); } 

extern "C" { extern int __cdecl _atodbl(_CRT_DOUBLE *, char *); } 
extern "C" { extern int __cdecl _atoldbl(_LDOUBLE *, char *); } 
extern "C" { extern int __cdecl _atoflt(_CRT_FLOAT *, char *); } 
extern "C" { extern int __cdecl _atodbl_l(_CRT_DOUBLE *, char *, _locale_t); } 
extern "C" { extern int __cdecl _atoldbl_l(_LDOUBLE *, char *, _locale_t); } 
extern "C" { extern int __cdecl _atoflt_l(_CRT_FLOAT *, char *, _locale_t); } 
extern "C" { extern unsigned long __cdecl _lrotl(unsigned long, int); } 
extern "C" { extern unsigned long __cdecl _lrotr(unsigned long, int); } 
extern "C" { extern errno_t __cdecl _makepath_s(char *, size_t, const char *, const char *, const char *, const char *); } 

template < size_t _Size > inline errno_t __cdecl _makepath_s ( char ( & _Path ) [ _Size ], const char * _Drive, const char * _Dir, const char * _Filename, const char * _Ext ) { return _makepath_s ( _Path, _Size, _Drive, _Dir, _Filename, _Ext ); }
extern "C" { extern void __cdecl _makepath(char *, const char *, const char *, const char *, const char *); } 
#line 764 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern _onexit_t __cdecl _onexit(_onexit_t); } 
#line 769 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern void __cdecl perror(const char *); } 
#line 772 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
#pragma warning (push)
#pragma warning (disable:6540)
extern "C" { extern int __cdecl _putenv(const char *); } 
extern "C" { extern errno_t __cdecl _putenv_s(const char *, const char *); } 
extern "C" { extern unsigned __cdecl _rotl(unsigned, int); } 
extern "C" { extern unsigned __int64 __cdecl _rotl64(unsigned __int64, int); } 
extern "C" { extern unsigned __cdecl _rotr(unsigned, int); } 
extern "C" { extern unsigned __int64 __cdecl _rotr64(unsigned __int64, int); } 
#pragma warning (pop)

extern "C" { extern errno_t __cdecl _searchenv_s(const char *, const char *, char *, size_t); } 
template < size_t _Size > inline errno_t __cdecl _searchenv_s ( const char * _Filename, const char * _EnvVar, char ( & _ResultPath ) [ _Size ] ) { return _searchenv_s ( _Filename, _EnvVar, _ResultPath, _Size ); }
extern "C" { extern void __cdecl _searchenv(const char *, const char *, char *); } 

extern "C" { extern void __cdecl _splitpath(const char *, char *, char *, char *, char *); } 
extern "C" { extern errno_t __cdecl _splitpath_s(const char *, char *, size_t, char *, size_t, char *, size_t, char *, size_t); } 




template < size_t _DriveSize, size_t _DirSize, size_t _NameSize, size_t _ExtSize > inline errno_t __cdecl _splitpath_s ( const char * _Dest, char ( & _Drive ) [ _DriveSize ], char ( & _Dir ) [ _DirSize ], char ( & _Name ) [ _NameSize ], char ( & _Ext ) [ _ExtSize ] ) { return _splitpath_s ( _Dest, _Drive, _DriveSize, _Dir, _DirSize, _Name, _NameSize, _Ext, _ExtSize ); }

extern "C" { extern void __cdecl _swab(char *, char *, int); } 
#line 805 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern __wchar_t *__cdecl _wfullpath(__wchar_t *, const __wchar_t *, size_t); } 
#line 811 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern errno_t __cdecl _wmakepath_s(__wchar_t *, size_t, const __wchar_t *, const __wchar_t *, const __wchar_t *, const __wchar_t *); } 

template < size_t _Size > inline errno_t __cdecl _wmakepath_s ( wchar_t ( & _ResultPath ) [ _Size ], const wchar_t * _Drive, const wchar_t * _Dir, const wchar_t * _Filename, const wchar_t * _Ext ) { return _wmakepath_s ( _ResultPath, _Size, _Drive, _Dir, _Filename, _Ext ); }
extern "C" { extern void __cdecl _wmakepath(__wchar_t *, const __wchar_t *, const __wchar_t *, const __wchar_t *, const __wchar_t *); } 


extern "C" { extern void __cdecl _wperror(const __wchar_t *); } 
#line 819 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern int __cdecl _wputenv(const __wchar_t *); } 
extern "C" { extern errno_t __cdecl _wputenv_s(const __wchar_t *, const __wchar_t *); } 
extern "C" { extern errno_t __cdecl _wsearchenv_s(const __wchar_t *, const __wchar_t *, __wchar_t *, size_t); } 
template < size_t _Size > inline errno_t __cdecl _wsearchenv_s ( const wchar_t * _Filename, const wchar_t * _EnvVar, wchar_t ( & _ResultPath ) [ _Size ] ) { return _wsearchenv_s ( _Filename, _EnvVar, _ResultPath, _Size ); }
extern "C" { extern void __cdecl _wsearchenv(const __wchar_t *, const __wchar_t *, __wchar_t *); } 
extern "C" { extern void __cdecl _wsplitpath(const __wchar_t *, __wchar_t *, __wchar_t *, __wchar_t *, __wchar_t *); } 
extern "C" { extern errno_t __cdecl _wsplitpath_s(const __wchar_t *, __wchar_t *, size_t, __wchar_t *, size_t, __wchar_t *, size_t, __wchar_t *, size_t); } 




template < size_t _DriveSize, size_t _DirSize, size_t _NameSize, size_t _ExtSize > inline errno_t __cdecl _wsplitpath_s ( const wchar_t * _Path, wchar_t ( & _Drive ) [ _DriveSize ], wchar_t ( & _Dir ) [ _DirSize ], wchar_t ( & _Name ) [ _NameSize ], wchar_t ( & _Ext ) [ _ExtSize ] ) { return _wsplitpath_s ( _Path, _Drive, _DriveSize, _Dir, _DirSize, _Name, _NameSize, _Ext, _ExtSize ); }
#line 836 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
extern "C" { extern __declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using SetErrorMode instead. See online help for details.")) void __cdecl _seterrormode(int); } 
extern "C" { extern __declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using Beep instead. See online help for details.")) void __cdecl _beep(unsigned, unsigned); } 
extern "C" { extern __declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using Sleep instead. See online help for details.")) void __cdecl _sleep(unsigned long); } 
#line 857 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
#pragma warning(push)
#pragma warning(disable: 4141)
extern "C" { extern char *__cdecl ecvt(double, int, int *, int *); } 
extern "C" { extern char *__cdecl fcvt(double, int, int *, int *); } 
extern "C" { extern char *__cdecl gcvt(double, int, char *); } 
extern "C" { extern char *__cdecl itoa(int, char *, int); } 
extern "C" { extern char *__cdecl ltoa(long, char *, int); } 
extern "C" { extern int __cdecl putenv(const char *); } 
extern "C" { extern void __cdecl swab(char *, char *, int); } 
extern "C" { extern char *__cdecl ultoa(unsigned long, char *, int); } 
#pragma warning(pop)
extern "C" { extern _onexit_t __cdecl onexit(_onexit_t); } 
#line 114 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\use_ansi.h"
#pragma comment(lib,"libcpmt")
#line 880 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdlib.h"
#pragma pack ( pop )
#line 9 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\yvals.h"
#pragma pack ( push, 8 )
#line 524 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\yvals.h"
namespace std { 
typedef bool _Bool; 
}
#line 542 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\yvals.h"
typedef __int64 _Longlong; 
typedef unsigned __int64 _ULonglong; 
#line 565 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\yvals.h"
namespace std { 



#pragma warning(push)
#pragma warning(disable:4412)
class _Lockit { 
#line 591 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\yvals.h"
public: explicit __thiscall _Lockit(); 
explicit __thiscall _Lockit(int); 
__thiscall ~_Lockit(); 
#line 596 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\yvals.h"
static void __cdecl _Lockit_ctor(int); 
static void __cdecl _Lockit_dtor(int); 


private: static void __cdecl _Lockit_ctor(_Lockit *); 
static void __cdecl _Lockit_ctor(_Lockit *, int); 
static void __cdecl _Lockit_dtor(_Lockit *); 

_Lockit(const _Lockit &); 
_Lockit &operator=(const _Lockit &); 

int _Locktype; 
#line 624 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\yvals.h"
}; 
#line 718 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\yvals.h"
class _Mutex { 
#line 742 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\yvals.h"
public: __thiscall _Mutex(); 
__thiscall ~_Mutex(); 
void __thiscall _Lock(); 
void __thiscall _Unlock(); 
#line 749 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\yvals.h"
private: static void __cdecl _Mutex_ctor(_Mutex *); 
static void __cdecl _Mutex_dtor(_Mutex *); 
static void __cdecl _Mutex_Lock(_Mutex *); 
static void __cdecl _Mutex_Unlock(_Mutex *); 

_Mutex(const _Mutex &); 
_Mutex &operator=(const _Mutex &); 
void *_Mtx; 
#line 768 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\yvals.h"
}; 

class _Init_locks { 
#line 786 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\yvals.h"
public: __thiscall _Init_locks(); 
__thiscall ~_Init_locks(); 
#line 791 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\yvals.h"
private: static void __cdecl _Init_locks_ctor(_Init_locks *); 
static void __cdecl _Init_locks_dtor(_Init_locks *); 
#line 804 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\yvals.h"
}; 
#pragma warning(pop)
}
#line 815 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\yvals.h"
extern void __cdecl _Atexit(void (__cdecl *)(void)); 

typedef int _Mbstatet; 
#line 826
#pragma pack ( pop )
#line 20 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\cmath"
namespace std { 
using ::acosf;using ::asinf;
using ::atanf;using ::atan2f;using ::ceilf;
using ::cosf;using ::coshf;using ::expf;
using ::fabsf;using ::floorf;using ::fmodf;
using ::frexpf;using ::ldexpf;using ::logf;
using ::log10f;using ::modff;using ::powf;
using ::sinf;using ::sinhf;using ::sqrtf;
using ::tanf;using ::tanhf;

using ::acosl;using ::asinl;
using ::atanl;using ::atan2l;using ::ceill;
using ::cosl;using ::coshl;using ::expl;
using ::fabsl;using ::floorl;using ::fmodl;
using ::frexpl;using ::ldexpl;using ::logl;
using ::log10l;using ::modfl;using ::powl;
using ::sinl;using ::sinhl;using ::sqrtl;
using ::tanl;using ::tanhl;

using ::abs;

using ::acos;using ::asin;
using ::atan;using ::atan2;using ::ceil;
using ::cos;using ::cosh;using ::exp;
using ::fabs;using ::floor;using ::fmod;
using ::frexp;using ::ldexp;using ::log;
using ::log10;using ::modf;using ::pow;
using ::sin;using ::sinh;using ::sqrt;
using ::tan;using ::tanh;


}
#line 19 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\cstdlib"
namespace std { 

using ::size_t;using ::div_t;using ::ldiv_t;

using ::abort;using ::atexit;
using ::atof;using ::atoi;using ::atol;
using ::bsearch;using ::calloc;using ::div;
using ::exit;using ::free;using ::getenv;
using ::labs;using ::ldiv;using ::malloc;
using ::mblen;using ::mbstowcs;using ::mbtowc;
using ::qsort;using ::rand;using ::realloc;
using ::srand;using ::strtod;using ::strtol;
using ::strtoul;using ::system;
using ::wcstombs;using ::wctomb;


}
#line 518 "d:\\my\\work\\cuda\\64\\tk\\include\\math_functions.h"
static __inline __int64 abs(__int64 a) 
{ 
return llabs(a); 
} 

static __inline int signbit(double a) 
{ 
return __signbit(a); 
} 

static __inline int signbit(float a) 
{ 
return __signbitf(a); 
} 

static __inline int isinf(double a) 
{ 
return __isinf(a); 
} 

static __inline int isinf(float a) 
{ 
return __isinff(a); 
} 

static __inline int isnan(double a) 
{ 
return __isnan(a); 
} 

static __inline int isnan(float a) 
{ 
return __isnanf(a); 
} 

static __inline int isfinite(double a) 
{ 
return __finite(a); 
} 

static __inline int isfinite(float a) 
{ 
return __finitef(a); 
} 

template<class T> inline T _Pow_int(T, int); 
#line 571 "d:\\my\\work\\cuda\\64\\tk\\include\\math_functions.h"
inline long abs(long); 
inline float abs(float); 
inline double abs(double); 
inline float fabs(float); 
inline float ceil(float); 
inline float floor(float); 
inline float sqrt(float); 
inline float pow(float, float); 
inline float pow(float, int); 
inline double pow(double, int); 
inline float log(float); 
inline float log10(float); 
inline float fmod(float, float); 
inline float modf(float, float *); 
inline float exp(float); 
inline float frexp(float, int *); 
inline float ldexp(float, int); 
inline float asin(float); 
inline float sin(float); 
inline float sinh(float); 
inline float acos(float); 
inline float cos(float); 
inline float cosh(float); 
inline float atan(float); 
inline float atan2(float, float); 
inline float tan(float); 
inline float tanh(float); 
#line 603 "d:\\my\\work\\cuda\\64\\tk\\include\\math_functions.h"
static __inline float logb(float a) 
{ 
return logbf(a); 
} 

static __inline int ilogb(float a) 
{ 
return ilogbf(a); 
} 

static __inline float scalbn(float a, int b) 
{ 
return scalbnf(a, b); 
} 

static __inline float scalbln(float a, long b) 
{ 
return scalblnf(a, b); 
} 

static __inline float exp2(float a) 
{ 
return exp2f(a); 
} 

static __inline float exp10(float a) 
{ 
return exp10f(a); 
} 

static __inline float expm1(float a) 
{ 
return expm1f(a); 
} 

static __inline float log2(float a) 
{ 
return log2f(a); 
} 

static __inline float log1p(float a) 
{ 
return log1pf(a); 
} 

static __inline float rsqrt(float a) 
{ 
return rsqrtf(a); 
} 

static __inline float acosh(float a) 
{ 
return acoshf(a); 
} 

static __inline float asinh(float a) 
{ 
return asinhf(a); 
} 

static __inline float atanh(float a) 
{ 
return atanhf(a); 
} 

static __inline float hypot(float a, float b) 
{ 
return hypotf(a, b); 
} 

static __inline float cbrt(float a) 
{ 
return cbrtf(a); 
} 

static __inline void sincos(float a, float *sptr, float *cptr) 
{ 
sincosf(a, sptr, cptr); 
} 

static __inline float erf(float a) 
{ 
return erff(a); 
} 

static __inline float erfinv(float a) 
{ 
return erfinvf(a); 
} 

static __inline float erfc(float a) 
{ 
return erfcf(a); 
} 

static __inline float erfcinv(float a) 
{ 
return erfcinvf(a); 
} 

static __inline float lgamma(float a) 
{ 
return lgammaf(a); 
} 

static __inline float tgamma(float a) 
{ 
return tgammaf(a); 
} 

static __inline float copysign(float a, float b) 
{ 
return copysignf(a, b); 
} 

static __inline double copysign(double a, float b) 
{ 
return copysign(a, (double)b); 
} 

static __inline float copysign(float a, double b) 
{ 
return copysignf(a, (float)b); 
} 

static __inline float nextafter(float a, float b) 
{ 
return nextafterf(a, b); 
} 

static __inline float remainder(float a, float b) 
{ 
return remainderf(a, b); 
} 

static __inline float remquo(float a, float b, int *quo) 
{ 
return remquof(a, b, quo); 
} 

static __inline float round(float a) 
{ 
return roundf(a); 
} 

static __inline long lround(float a) 
{ 
return lroundf(a); 
} 

static __inline __int64 llround(float a) 
{ 
return llroundf(a); 
} 

static __inline float trunc(float a) 
{ 
return truncf(a); 
} 

static __inline float rint(float a) 
{ 
return rintf(a); 
} 

static __inline long lrint(float a) 
{ 
return lrintf(a); 
} 

static __inline __int64 llrint(float a) 
{ 
return llrintf(a); 
} 

static __inline float nearbyint(float a) 
{ 
return nearbyintf(a); 
} 

static __inline float fdim(float a, float b) 
{ 
return fdimf(a, b); 
} 

static __inline float fma(float a, float b, float c) 
{ 
return fmaf(a, b, c); 
} 

static __inline unsigned min(unsigned a, unsigned b) 
{ 
return umin(a, b); 
} 

static __inline unsigned min(int a, unsigned b) 
{ 
return umin((unsigned)a, b); 
} 

static __inline unsigned min(unsigned a, int b) 
{ 
return umin(a, (unsigned)b); 
} 

static __inline __int64 min(__int64 a, __int64 b) 
{ 
return llmin(a, b); 
} 

static __inline unsigned __int64 min(unsigned __int64 a, unsigned __int64 b) 
{ 
return ullmin(a, b); 
} 

static __inline unsigned __int64 min(__int64 a, unsigned __int64 b) 
{ 
return ullmin((unsigned __int64)a, b); 
} 

static __inline unsigned __int64 min(unsigned __int64 a, __int64 b) 
{ 
return ullmin(a, (unsigned __int64)b); 
} 

static __inline float min(float a, float b) 
{ 
return fminf(a, b); 
} 

static __inline double min(double a, double b) 
{ 
return fmin(a, b); 
} 

static __inline double min(float a, double b) 
{ 
return fmin((double)a, b); 
} 

static __inline double min(double a, float b) 
{ 
return fmin(a, (double)b); 
} 

static __inline unsigned max(unsigned a, unsigned b) 
{ 
return umax(a, b); 
} 

static __inline unsigned max(int a, unsigned b) 
{ 
return umax((unsigned)a, b); 
} 

static __inline unsigned max(unsigned a, int b) 
{ 
return umax(a, (unsigned)b); 
} 

static __inline __int64 max(__int64 a, __int64 b) 
{ 
return llmax(a, b); 
} 

static __inline unsigned __int64 max(unsigned __int64 a, unsigned __int64 b) 
{ 
return ullmax(a, b); 
} 

static __inline unsigned __int64 max(__int64 a, unsigned __int64 b) 
{ 
return ullmax((unsigned __int64)a, b); 
} 

static __inline unsigned __int64 max(unsigned __int64 a, __int64 b) 
{ 
return ullmax(a, (unsigned __int64)b); 
} 

static __inline float max(float a, float b) 
{ 
return fmaxf(a, b); 
} 

static __inline double max(double a, double b) 
{ 
return fmax(a, b); 
} 

static __inline double max(float a, double b) 
{ 
return fmax((double)a, b); 
} 

static __inline double max(double a, float b) 
{ 
return fmax(a, (double)b); 
} 
#line 59 "d:\\my\\work\\cuda\\64\\tk\\include\\cuda_texture_types.h"
template<class T, int dim = 1, cudaTextureReadMode mode = cudaReadModeElementType> 
struct texture : public textureReference { 

texture(int norm = 0, cudaTextureFilterMode 
fMode = cudaFilterModePoint, cudaTextureAddressMode 
aMode = cudaAddressModeClamp) 
{ 
(this->normalized) = norm; 
(this->filterMode) = fMode; 
((this->addressMode)[0]) = aMode; 
((this->addressMode)[1]) = aMode; 
((this->addressMode)[2]) = aMode; 
(this->channelDesc) = cudaCreateChannelDesc< T> (); 
} 

texture(int norm, cudaTextureFilterMode 
fMode, cudaTextureAddressMode 
aMode, cudaChannelFormatDesc 
desc) 
{ 
(this->normalized) = norm; 
(this->filterMode) = fMode; 
((this->addressMode)[0]) = aMode; 
((this->addressMode)[1]) = aMode; 
((this->addressMode)[2]) = aMode; 
(this->channelDesc) = desc; 
} 
}; 
#if 0
#endif
#if 0
#endif
#if 0
#endif
#if 0
#endif
#if 0
#endif
#if 0
#endif
#line 53 "d:\\my\\work\\cuda\\64\\tk\\include\\device_launch_parameters.h"
#if 0
extern "C" const uint3 
#line 53
threadIdx; 
#endif
#line 55 "d:\\my\\work\\cuda\\64\\tk\\include\\device_launch_parameters.h"
#if 0
extern "C" const uint3 
#line 55
blockIdx; 
#endif
#line 57 "d:\\my\\work\\cuda\\64\\tk\\include\\device_launch_parameters.h"
#if 0
extern "C" const dim3 
#line 57
blockDim; 
#endif
#line 59 "d:\\my\\work\\cuda\\64\\tk\\include\\device_launch_parameters.h"
#if 0
extern "C" const dim3 
#line 59
gridDim; 
#endif
#line 61 "d:\\my\\work\\cuda\\64\\tk\\include\\device_launch_parameters.h"
#if 0
extern "C" const int 
#line 61
warpSize; 
#endif
#line 101 "D:\\my\\work\\cuda\\64\\tk\\include\\cuda_runtime.h"
template<class T> __inline cudaError_t 
cudaSetupArgument(T 
arg, size_t 
offset) 

{ 
return cudaSetupArgument((const void *)(&arg), sizeof(T), offset); 
} 

template<class T> __inline cudaError_t 
cudaHostAlloc(T **
ptr, size_t 
size, unsigned 
flags) 

{ 
return cudaHostAlloc((void **)((void *)ptr), size, flags); 
} 

template<class T> __inline cudaError_t 
cudaHostGetDevicePointer(T **
pDevice, void *
pHost, unsigned 
flags) 

{ 
return cudaHostGetDevicePointer((void **)((void *)pDevice), pHost, flags); 
} 

template<class T> __inline cudaError_t 
cudaMalloc(T **
devPtr, size_t 
size) 

{ 
return cudaMalloc((void **)((void *)devPtr), size); 
} 

template<class T> __inline cudaError_t 
cudaMallocHost(T **
ptr, size_t 
size) 

{ 
return cudaMallocHost((void **)((void *)ptr), size); 
} 

template<class T> __inline cudaError_t 
cudaMallocPitch(T **
devPtr, size_t *
pitch, size_t 
width, size_t 
height) 

{ 
return cudaMallocPitch((void **)((void *)devPtr), pitch, width, height); 
} 
#line 172
static __inline cudaError_t cudaMemcpyToSymbol(char *
symbol, const void *
src, size_t 
count, size_t 
offset = (0), cudaMemcpyKind 
kind = cudaMemcpyHostToDevice) 

{ 
return cudaMemcpyToSymbol((const char *)symbol, src, count, offset, kind); 
} 

template<class T> __inline cudaError_t 
cudaMemcpyToSymbol(const T &
symbol, const void *
src, size_t 
count, size_t 
offset = (0), cudaMemcpyKind 
kind = cudaMemcpyHostToDevice) 

{ 
return cudaMemcpyToSymbol((const char *)(&symbol), src, count, offset, kind); 
} 

static __inline cudaError_t cudaMemcpyToSymbolAsync(char *
symbol, const void *
src, size_t 
count, size_t 
offset, cudaMemcpyKind 
kind, cudaStream_t 
stream) 

{ 
return cudaMemcpyToSymbolAsync((const char *)symbol, src, count, offset, kind, stream); 
} 

template<class T> __inline cudaError_t 
cudaMemcpyToSymbolAsync(const T &
symbol, const void *
src, size_t 
count, size_t 
offset, cudaMemcpyKind 
kind, cudaStream_t 
stream) 

{ 
return cudaMemcpyToSymbolAsync((const char *)(&symbol), src, count, offset, kind, stream); 
} 
#line 226
static __inline cudaError_t cudaMemcpyFromSymbol(void *
dst, char *
symbol, size_t 
count, size_t 
offset = (0), cudaMemcpyKind 
kind = cudaMemcpyDeviceToHost) 

{ 
return cudaMemcpyFromSymbol(dst, (const char *)symbol, count, offset, kind); 
} 

template<class T> __inline cudaError_t 
cudaMemcpyFromSymbol(void *
dst, const T &
symbol, size_t 
count, size_t 
offset = (0), cudaMemcpyKind 
kind = cudaMemcpyDeviceToHost) 

{ 
return cudaMemcpyFromSymbol(dst, (const char *)(&symbol), count, offset, kind); 
} 

static __inline cudaError_t cudaMemcpyFromSymbolAsync(void *
dst, char *
symbol, size_t 
count, size_t 
offset, cudaMemcpyKind 
kind, cudaStream_t 
stream) 

{ 
return cudaMemcpyFromSymbolAsync(dst, (const char *)symbol, count, offset, kind, stream); 
} 

template<class T> __inline cudaError_t 
cudaMemcpyFromSymbolAsync(void *
dst, const T &
symbol, size_t 
count, size_t 
offset, cudaMemcpyKind 
kind, cudaStream_t 
stream) 

{ 
return cudaMemcpyFromSymbolAsync(dst, (const char *)(&symbol), count, offset, kind, stream); 
} 

static __inline cudaError_t cudaGetSymbolAddress(void **
devPtr, char *
symbol) 

{ 
return cudaGetSymbolAddress(devPtr, (const char *)symbol); 
} 
#line 304
template<class T> __inline cudaError_t 
cudaGetSymbolAddress(void **
devPtr, const T &
symbol) 

{ 
return cudaGetSymbolAddress(devPtr, (const char *)(&symbol)); 
} 
#line 319
static __inline cudaError_t cudaGetSymbolSize(size_t *
size, char *
symbol) 

{ 
return cudaGetSymbolSize(size, (const char *)symbol); 
} 
#line 348
template<class T> __inline cudaError_t 
cudaGetSymbolSize(size_t *
size, const T &
symbol) 

{ 
return cudaGetSymbolSize(size, (const char *)(&symbol)); 
} 
#line 404
template<class T, int dim, cudaTextureReadMode readMode> __inline cudaError_t 
cudaBindTexture(size_t *
offset, const texture< T, dim, readMode>  &
tex, const void *
devPtr, const cudaChannelFormatDesc &
desc, size_t 
size = (4294967295U)) 

{ 
return cudaBindTexture(offset, &tex, devPtr, (&desc), size); 
} 
#line 448
template<class T, int dim, cudaTextureReadMode readMode> __inline cudaError_t 
cudaBindTexture(size_t *
offset, const texture< T, dim, readMode>  &
tex, const void *
devPtr, size_t 
size = (4294967295U)) 

{ 
return cudaBindTexture(offset, tex, devPtr, (tex.channelDesc), size); 
} 
#line 503
template<class T, int dim, cudaTextureReadMode readMode> __inline cudaError_t 
cudaBindTexture2D(size_t *
offset, const texture< T, dim, readMode>  &
tex, const void *
devPtr, const cudaChannelFormatDesc &
desc, size_t 
width, size_t 
height, size_t 
pitch) 

{ 
return cudaBindTexture2D(offset, &tex, devPtr, (&desc), width, height, pitch); 
} 
#line 545
template<class T, int dim, cudaTextureReadMode readMode> __inline cudaError_t 
cudaBindTextureToArray(const texture< T, dim, readMode>  &
tex, const cudaArray *
array, const cudaChannelFormatDesc &
desc) 

{ 
return cudaBindTextureToArray(&tex, array, (&desc)); 
} 
#line 582
template<class T, int dim, cudaTextureReadMode readMode> __inline cudaError_t 
cudaBindTextureToArray(const texture< T, dim, readMode>  &
tex, const cudaArray *
array) 

{ 
auto cudaChannelFormatDesc desc; 
auto cudaError_t err = cudaGetChannelDesc(&desc, array); 

return (err == (cudaSuccess)) ? (cudaBindTextureToArray(tex, array, desc)) : err; 
} 
#line 620
template<class T, int dim, cudaTextureReadMode readMode> __inline cudaError_t 
cudaUnbindTexture(const texture< T, dim, readMode>  &
tex) 

{ 
return cudaUnbindTexture(&tex); 
} 
#line 659
template<class T, int dim, cudaTextureReadMode readMode> __inline cudaError_t 
cudaGetTextureAlignmentOffset(size_t *
offset, const texture< T, dim, readMode>  &
tex) 

{ 
return cudaGetTextureAlignmentOffset(offset, &tex); 
} 
#line 708
template<class T> __inline cudaError_t 
cudaLaunch(T *
entry) 

{ 
return cudaLaunch((const char *)entry); 
} 
#line 744
template<class T> __inline cudaError_t 
cudaFuncGetAttributes(cudaFuncAttributes *
attr, T *
entry) 

{ 
return cudaFuncGetAttributes(attr, (const char *)entry); 
} 
#line 28 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
#pragma pack ( push, 8 )
#line 59 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { struct _iobuf { 
char *_ptr; 
int _cnt; 
char *_base; 
int _flag; 
int _file; 
int _charbuf; 
int _bufsiz; 
char *_tmpfname; 
}; }
extern "C" { typedef _iobuf FILE; }
#line 132 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern FILE *__cdecl __iob_func(); } 
#line 148 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { typedef __int64 fpos_t; }
#line 189 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern int __cdecl _filbuf(FILE *); } 
extern "C" { extern int __cdecl _flsbuf(int, FILE *); } 




extern "C" { extern FILE *__cdecl _fsopen(const char *, const char *, int); } 
#line 198 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern void __cdecl clearerr(FILE *); } 

extern "C" { extern errno_t __cdecl clearerr_s(FILE *); } 
#line 202 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern int __cdecl fclose(FILE *); } 
extern "C" { extern int __cdecl _fcloseall(); } 




extern "C" { extern FILE *__cdecl _fdopen(int, const char *); } 
#line 211 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern int __cdecl feof(FILE *); } 
extern "C" { extern int __cdecl ferror(FILE *); } 
extern "C" { extern int __cdecl fflush(FILE *); } 
extern "C" { extern int __cdecl fgetc(FILE *); } 
extern "C" { extern int __cdecl _fgetchar(); } 
extern "C" { extern int __cdecl fgetpos(FILE *, fpos_t *); } 
extern "C" { extern char *__cdecl fgets(char *, int, FILE *); } 




extern "C" { extern int __cdecl _fileno(FILE *); } 
#line 230 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern char *__cdecl _tempnam(const char *, const char *); } 
#line 236 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern int __cdecl _flushall(); } 
extern "C" { extern FILE *__cdecl fopen(const char *, const char *); } 

extern "C" { extern errno_t __cdecl fopen_s(FILE **, const char *, const char *); } 
#line 241 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern int __cdecl fprintf(FILE *, const char *, ...); } 

extern "C" { extern int __cdecl fprintf_s(FILE *, const char *, ...); } 
#line 245 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern int __cdecl fputc(int, FILE *); } 
extern "C" { extern int __cdecl _fputchar(int); } 
extern "C" { extern int __cdecl fputs(const char *, FILE *); } 
extern "C" { extern size_t __cdecl fread(void *, size_t, size_t, FILE *); } 

extern "C" { extern size_t __cdecl fread_s(void *, size_t, size_t, size_t, FILE *); } 
#line 252 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern FILE *__cdecl freopen(const char *, const char *, FILE *); } 

extern "C" { extern errno_t __cdecl freopen_s(FILE **, const char *, const char *, FILE *); } 
#line 256 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern int __cdecl fscanf(FILE *, const char *, ...); } 
extern "C" { extern int __cdecl _fscanf_l(FILE *, const char *, _locale_t, ...); } 
#pragma warning(push)
#pragma warning(disable:6530)

extern "C" { extern int __cdecl fscanf_s(FILE *, const char *, ...); } 
#line 263 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern int __cdecl _fscanf_s_l(FILE *, const char *, _locale_t, ...); } 
extern "C" { extern int __cdecl fsetpos(FILE *, const fpos_t *); } 
extern "C" { extern int __cdecl fseek(FILE *, long, int); } 
extern "C" { extern long __cdecl ftell(FILE *); } 

extern "C" { extern int __cdecl _fseeki64(FILE *, __int64, int); } 
extern "C" { extern __int64 __cdecl _ftelli64(FILE *); } 

extern "C" { extern size_t __cdecl fwrite(const void *, size_t, size_t, FILE *); } 
extern "C" { extern int __cdecl getc(FILE *); } 
extern "C" { extern int __cdecl getchar(); } 
extern "C" { extern int __cdecl _getmaxstdio(); } 

extern "C" { extern char *__cdecl gets_s(char *, rsize_t); } 
#line 278 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
template < size_t _Size > inline char * __cdecl gets_s ( char ( & _Buffer ) [ _Size ] ) { return gets_s ( _Buffer, _Size ); }
extern "C" { extern char *__cdecl gets(char *); } 
extern "C" { extern int __cdecl _getw(FILE *); } 




extern "C" { extern int __cdecl _pclose(FILE *); } 
extern "C" { extern FILE *__cdecl _popen(const char *, const char *); } 
extern "C" { extern int __cdecl printf(const char *, ...); } 

extern "C" { extern int __cdecl printf_s(const char *, ...); } 
#line 291 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern int __cdecl putc(int, FILE *); } 
extern "C" { extern int __cdecl putchar(int); } 
extern "C" { extern int __cdecl puts(const char *); } 
extern "C" { extern int __cdecl _putw(int, FILE *); } 


extern "C" { extern int __cdecl remove(const char *); } 
extern "C" { extern int __cdecl rename(const char *, const char *); } 
extern "C" { extern int __cdecl _unlink(const char *); } 

extern "C" { extern int __cdecl unlink(const char *); } 
#line 304 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern void __cdecl rewind(FILE *); } 
extern "C" { extern int __cdecl _rmtmp(); } 
extern "C" { extern int __cdecl scanf(const char *, ...); } 
extern "C" { extern int __cdecl _scanf_l(const char *, _locale_t, ...); } 

extern "C" { extern int __cdecl scanf_s(const char *, ...); } 
#line 311 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern int __cdecl _scanf_s_l(const char *, _locale_t, ...); } 
extern "C" { extern void __cdecl setbuf(FILE *, char *); } 
extern "C" { extern int __cdecl _setmaxstdio(int); } 
extern "C" { extern unsigned __cdecl _set_output_format(unsigned); } 
extern "C" { extern unsigned __cdecl _get_output_format(); } 
extern "C" { extern int __cdecl setvbuf(FILE *, char *, int, size_t); } 
extern "C" { extern int __cdecl _snprintf_s(char *, size_t, size_t, const char *, ...); } 
__pragma( warning(push)) __pragma( warning(disable: 4793)) template < size_t _Size > inline int __cdecl _snprintf_s ( char ( & _Dest ) [ _Size ], size_t _MaxCount, const char * _Format, ... ) { va_list _ArgList; ( __va_start ( & _ArgList, _Format ) ); return _vsnprintf_s ( _Dest, _Size, _MaxCount, _Format, _ArgList ); }__pragma( warning(pop)) 

extern "C" { extern int __cdecl sprintf_s(char *, size_t, const char *, ...); } 
#line 322 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
__pragma( warning(push)) __pragma( warning(disable: 4793)) template < size_t _Size > inline int __cdecl sprintf_s ( char ( & _Dest ) [ _Size ], const char * _Format, ... ) { va_list _ArgList; ( __va_start ( & _ArgList, _Format ) ); return vsprintf_s ( _Dest, _Size, _Format, _ArgList ); }__pragma( warning(pop)) 
extern "C" { extern int __cdecl _scprintf(const char *, ...); } 
extern "C" { extern int __cdecl sscanf(const char *, const char *, ...); } 
extern "C" { extern int __cdecl _sscanf_l(const char *, const char *, _locale_t, ...); } 

extern "C" { extern int __cdecl sscanf_s(const char *, const char *, ...); } 
#line 329 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern int __cdecl _sscanf_s_l(const char *, const char *, _locale_t, ...); } 
extern "C" { extern int __cdecl _snscanf(const char *, size_t, const char *, ...); } 
extern "C" { extern int __cdecl _snscanf_l(const char *, size_t, const char *, _locale_t, ...); } 
extern "C" { extern int __cdecl _snscanf_s(const char *, size_t, const char *, ...); } 
extern "C" { extern int __cdecl _snscanf_s_l(const char *, size_t, const char *, _locale_t, ...); } 
extern "C" { extern FILE *__cdecl tmpfile(); } 

extern "C" { extern errno_t __cdecl tmpfile_s(FILE **); } 
extern "C" { extern errno_t __cdecl tmpnam_s(char *, rsize_t); } 
#line 339 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
template < size_t _Size > inline errno_t __cdecl tmpnam_s ( char ( & _Buf ) [ _Size ] ) { return tmpnam_s ( _Buf, _Size ); }
extern "C" { extern char *__cdecl tmpnam(char *); } 
extern "C" { extern int __cdecl ungetc(int, FILE *); } 
extern "C" { extern int __cdecl vfprintf(FILE *, const char *, va_list); } 

extern "C" { extern int __cdecl vfprintf_s(FILE *, const char *, va_list); } 
#line 346 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern int __cdecl vprintf(const char *, va_list); } 

extern "C" { extern int __cdecl vprintf_s(const char *, va_list); } 
#line 350 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern int __cdecl vsnprintf(char *, size_t, const char *, va_list); } 

extern "C" { extern int __cdecl vsnprintf_s(char *, size_t, size_t, const char *, va_list); } 
#line 354 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern int __cdecl _vsnprintf_s(char *, size_t, size_t, const char *, va_list); } 
template < size_t _Size > inline int __cdecl _vsnprintf_s ( char ( & _Dest ) [ _Size ], size_t _MaxCount, const char * _Format, va_list _Args ) { return _vsnprintf_s ( _Dest, _Size, _MaxCount, _Format, _Args ); }
#pragma warning(push)
#pragma warning(disable:4793)
extern "C" { extern int __cdecl _snprintf(char *, size_t, const char *, ...); } extern "C" { extern int __cdecl _vsnprintf(char *, size_t, const char *, va_list); } 
#pragma warning(pop)

extern "C" { extern int __cdecl vsprintf_s(char *, size_t, const char *, va_list); } 
#line 363 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
template < size_t _Size > inline int __cdecl vsprintf_s ( char ( & _Dest ) [ _Size ], const char * _Format, va_list _Args ) { return vsprintf_s ( _Dest, _Size, _Format, _Args ); }
#pragma warning(push)
#pragma warning(disable:4793)
extern "C" { extern int __cdecl sprintf(char *, const char *, ...); } extern "C" { extern int __cdecl vsprintf(char *, const char *, va_list); } 
#pragma warning(pop)
extern "C" { extern int __cdecl _vscprintf(const char *, va_list); } 
extern "C" { extern int __cdecl _snprintf_c(char *, size_t, const char *, ...); } 
extern "C" { extern int __cdecl _vsnprintf_c(char *, size_t, const char *, va_list); } 

extern "C" { extern int __cdecl _fprintf_p(FILE *, const char *, ...); } 
extern "C" { extern int __cdecl _printf_p(const char *, ...); } 
extern "C" { extern int __cdecl _sprintf_p(char *, size_t, const char *, ...); } 
extern "C" { extern int __cdecl _vfprintf_p(FILE *, const char *, va_list); } 
extern "C" { extern int __cdecl _vprintf_p(const char *, va_list); } 
extern "C" { extern int __cdecl _vsprintf_p(char *, size_t, const char *, va_list); } 
extern "C" { extern int __cdecl _scprintf_p(const char *, ...); } 
extern "C" { extern int __cdecl _vscprintf_p(const char *, va_list); } 
extern "C" { extern int __cdecl _set_printf_count_output(int); } 
extern "C" { extern int __cdecl _get_printf_count_output(); } 

extern "C" { extern int __cdecl _printf_l(const char *, _locale_t, ...); } 
extern "C" { extern int __cdecl _printf_p_l(const char *, _locale_t, ...); } 
extern "C" { extern int __cdecl _printf_s_l(const char *, _locale_t, ...); } 
extern "C" { extern int __cdecl _vprintf_l(const char *, _locale_t, va_list); } 
extern "C" { extern int __cdecl _vprintf_p_l(const char *, _locale_t, va_list); } 
extern "C" { extern int __cdecl _vprintf_s_l(const char *, _locale_t, va_list); } 

extern "C" { extern int __cdecl _fprintf_l(FILE *, const char *, _locale_t, ...); } 
extern "C" { extern int __cdecl _fprintf_p_l(FILE *, const char *, _locale_t, ...); } 
extern "C" { extern int __cdecl _fprintf_s_l(FILE *, const char *, _locale_t, ...); } 
extern "C" { extern int __cdecl _vfprintf_l(FILE *, const char *, _locale_t, va_list); } 
extern "C" { extern int __cdecl _vfprintf_p_l(FILE *, const char *, _locale_t, va_list); } 
extern "C" { extern int __cdecl _vfprintf_s_l(FILE *, const char *, _locale_t, va_list); } 

extern "C" { extern int __cdecl _sprintf_l(char *, const char *, _locale_t, ...); } 
extern "C" { extern int __cdecl _sprintf_p_l(char *, size_t, const char *, _locale_t, ...); } 
extern "C" { extern int __cdecl _sprintf_s_l(char *, size_t, const char *, _locale_t, ...); } 
extern "C" { extern int __cdecl _vsprintf_l(char *, const char *, _locale_t, va_list); } 
extern "C" { extern int __cdecl _vsprintf_p_l(char *, size_t, const char *, _locale_t, va_list); } 
extern "C" { extern int __cdecl _vsprintf_s_l(char *, size_t, const char *, _locale_t, va_list); } 

extern "C" { extern int __cdecl _scprintf_l(const char *, _locale_t, ...); } 
extern "C" { extern int __cdecl _scprintf_p_l(const char *, _locale_t, ...); } 
extern "C" { extern int __cdecl _vscprintf_l(const char *, _locale_t, va_list); } 
extern "C" { extern int __cdecl _vscprintf_p_l(const char *, _locale_t, va_list); } 

extern "C" { extern int __cdecl _snprintf_l(char *, size_t, const char *, _locale_t, ...); } 
extern "C" { extern int __cdecl _snprintf_c_l(char *, size_t, const char *, _locale_t, ...); } 
extern "C" { extern int __cdecl _snprintf_s_l(char *, size_t, size_t, const char *, _locale_t, ...); } 
extern "C" { extern int __cdecl _vsnprintf_l(char *, size_t, const char *, _locale_t, va_list); } 
extern "C" { extern int __cdecl _vsnprintf_c_l(char *, size_t, const char *, _locale_t, va_list); } 
extern "C" { extern int __cdecl _vsnprintf_s_l(char *, size_t, size_t, const char *, _locale_t, va_list); } 
#line 427 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern FILE *__cdecl _wfsopen(const __wchar_t *, const __wchar_t *, int); } 
#line 430 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern wint_t __cdecl fgetwc(FILE *); } 
extern "C" { extern wint_t __cdecl _fgetwchar(); } 
extern "C" { extern wint_t __cdecl fputwc(__wchar_t, FILE *); } 
extern "C" { extern wint_t __cdecl _fputwchar(__wchar_t); } 
extern "C" { extern wint_t __cdecl getwc(FILE *); } 
extern "C" { inline wint_t __cdecl getwchar(); } 
extern "C" { extern wint_t __cdecl putwc(__wchar_t, FILE *); } 
extern "C" { inline wint_t __cdecl putwchar(__wchar_t); } 
extern "C" { extern wint_t __cdecl ungetwc(wint_t, FILE *); } 

extern "C" { extern __wchar_t *__cdecl fgetws(__wchar_t *, int, FILE *); } 
extern "C" { extern int __cdecl fputws(const __wchar_t *, FILE *); } 
extern "C" { extern __wchar_t *__cdecl _getws_s(__wchar_t *, size_t); } 
template < size_t _Size > inline wchar_t * __cdecl _getws_s ( wchar_t ( & _String ) [ _Size ] ) { return _getws_s ( _String, _Size ); }
extern "C" { extern __wchar_t *__cdecl _getws(__wchar_t *); } 
extern "C" { extern int __cdecl _putws(const __wchar_t *); } 

extern "C" { extern int __cdecl fwprintf(FILE *, const __wchar_t *, ...); } 

extern "C" { extern int __cdecl fwprintf_s(FILE *, const __wchar_t *, ...); } 
#line 451 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern int __cdecl wprintf(const __wchar_t *, ...); } 

extern "C" { extern int __cdecl wprintf_s(const __wchar_t *, ...); } 
#line 455 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern int __cdecl _scwprintf(const __wchar_t *, ...); } 
extern "C" { extern int __cdecl vfwprintf(FILE *, const __wchar_t *, va_list); } 

extern "C" { extern int __cdecl vfwprintf_s(FILE *, const __wchar_t *, va_list); } 
#line 460 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern int __cdecl vwprintf(const __wchar_t *, va_list); } 

extern "C" { extern int __cdecl vwprintf_s(const __wchar_t *, va_list); } 
#line 466 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern int __cdecl swprintf_s(__wchar_t *, size_t, const __wchar_t *, ...); } 
#line 468 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
__pragma( warning(push)) __pragma( warning(disable: 4793)) template < size_t _Size > inline int __cdecl swprintf_s ( wchar_t ( & _Dest ) [ _Size ], const wchar_t * _Format, ... ) { va_list _ArgList; ( __va_start ( & _ArgList, _Format ) ); return vswprintf_s ( _Dest, _Size, _Format, _ArgList ); }__pragma( warning(pop)) 

extern "C" { extern int __cdecl vswprintf_s(__wchar_t *, size_t, const __wchar_t *, va_list); } 
#line 472 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
template < size_t _Size > inline int __cdecl vswprintf_s ( wchar_t ( & _Dest ) [ _Size ], const wchar_t * _Format, va_list _Args ) { return vswprintf_s ( _Dest, _Size, _Format, _Args ); }

extern "C" { extern int __cdecl _swprintf_c(__wchar_t *, size_t, const __wchar_t *, ...); } 
extern "C" { extern int __cdecl _vswprintf_c(__wchar_t *, size_t, const __wchar_t *, va_list); } 

extern "C" { extern int __cdecl _snwprintf_s(__wchar_t *, size_t, size_t, const __wchar_t *, ...); } 
__pragma( warning(push)) __pragma( warning(disable: 4793)) template < size_t _Size > inline int __cdecl _snwprintf_s ( wchar_t ( & _Dest ) [ _Size ], size_t _Count, const wchar_t * _Format, ... ) { va_list _ArgList; ( __va_start ( & _ArgList, _Format ) ); return _vsnwprintf_s ( _Dest, _Size, _Count, _Format, _ArgList ); }__pragma( warning(pop)) 
extern "C" { extern int __cdecl _vsnwprintf_s(__wchar_t *, size_t, size_t, const __wchar_t *, va_list); } 
template < size_t _Size > inline int __cdecl _vsnwprintf_s ( wchar_t ( & _Dest ) [ _Size ], size_t _Count, const wchar_t * _Format, va_list _Args ) { return _vsnwprintf_s ( _Dest, _Size, _Count, _Format, _Args ); }
#pragma warning(push)
#pragma warning(disable:4793)
extern "C" { extern int __cdecl _snwprintf(__wchar_t *, size_t, const __wchar_t *, ...); } extern "C" { extern int __cdecl _vsnwprintf(__wchar_t *, size_t, const __wchar_t *, va_list); } 
#pragma warning(pop)

extern "C" { extern int __cdecl _fwprintf_p(FILE *, const __wchar_t *, ...); } 
extern "C" { extern int __cdecl _wprintf_p(const __wchar_t *, ...); } 
extern "C" { extern int __cdecl _vfwprintf_p(FILE *, const __wchar_t *, va_list); } 
extern "C" { extern int __cdecl _vwprintf_p(const __wchar_t *, va_list); } 
extern "C" { extern int __cdecl _swprintf_p(__wchar_t *, size_t, const __wchar_t *, ...); } 
extern "C" { extern int __cdecl _vswprintf_p(__wchar_t *, size_t, const __wchar_t *, va_list); } 
extern "C" { extern int __cdecl _scwprintf_p(const __wchar_t *, ...); } 
extern "C" { extern int __cdecl _vscwprintf_p(const __wchar_t *, va_list); } 

extern "C" { extern int __cdecl _wprintf_l(const __wchar_t *, _locale_t, ...); } 
extern "C" { extern int __cdecl _wprintf_p_l(const __wchar_t *, _locale_t, ...); } 
extern "C" { extern int __cdecl _wprintf_s_l(const __wchar_t *, _locale_t, ...); } 
extern "C" { extern int __cdecl _vwprintf_l(const __wchar_t *, _locale_t, va_list); } 
extern "C" { extern int __cdecl _vwprintf_p_l(const __wchar_t *, _locale_t, va_list); } 
extern "C" { extern int __cdecl _vwprintf_s_l(const __wchar_t *, _locale_t, va_list); } 

extern "C" { extern int __cdecl _fwprintf_l(FILE *, const __wchar_t *, _locale_t, ...); } 
extern "C" { extern int __cdecl _fwprintf_p_l(FILE *, const __wchar_t *, _locale_t, ...); } 
extern "C" { extern int __cdecl _fwprintf_s_l(FILE *, const __wchar_t *, _locale_t, ...); } 
extern "C" { extern int __cdecl _vfwprintf_l(FILE *, const __wchar_t *, _locale_t, va_list); } 
extern "C" { extern int __cdecl _vfwprintf_p_l(FILE *, const __wchar_t *, _locale_t, va_list); } 
extern "C" { extern int __cdecl _vfwprintf_s_l(FILE *, const __wchar_t *, _locale_t, va_list); } 

extern "C" { extern int __cdecl _swprintf_c_l(__wchar_t *, size_t, const __wchar_t *, _locale_t, ...); } 
extern "C" { extern int __cdecl _swprintf_p_l(__wchar_t *, size_t, const __wchar_t *, _locale_t, ...); } 
extern "C" { extern int __cdecl _swprintf_s_l(__wchar_t *, size_t, const __wchar_t *, _locale_t, ...); } 
extern "C" { extern int __cdecl _vswprintf_c_l(__wchar_t *, size_t, const __wchar_t *, _locale_t, va_list); } 
extern "C" { extern int __cdecl _vswprintf_p_l(__wchar_t *, size_t, const __wchar_t *, _locale_t, va_list); } 
extern "C" { extern int __cdecl _vswprintf_s_l(__wchar_t *, size_t, const __wchar_t *, _locale_t, va_list); } 

extern "C" { extern int __cdecl _scwprintf_l(const __wchar_t *, _locale_t, ...); } 
extern "C" { extern int __cdecl _scwprintf_p_l(const __wchar_t *, _locale_t, ...); } 
extern "C" { extern int __cdecl _vscwprintf_p_l(const __wchar_t *, _locale_t, va_list); } 

extern "C" { extern int __cdecl _snwprintf_l(__wchar_t *, size_t, const __wchar_t *, _locale_t, ...); } 
extern "C" { extern int __cdecl _snwprintf_s_l(__wchar_t *, size_t, size_t, const __wchar_t *, _locale_t, ...); } 
extern "C" { extern int __cdecl _vsnwprintf_l(__wchar_t *, size_t, const __wchar_t *, _locale_t, va_list); } 
extern "C" { extern int __cdecl _vsnwprintf_s_l(__wchar_t *, size_t, size_t, const __wchar_t *, _locale_t, va_list); } 
#line 537 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
#pragma warning(push)
#pragma warning(disable:4141 4996 4793)
extern "C" { extern __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS.")) int __cdecl _swprintf(__wchar_t *, const __wchar_t *, ...); } extern "C" { extern __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS.")) int __cdecl _vswprintf(__wchar_t *, const __wchar_t *, va_list); } 
extern "C" { extern __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS.")) int __cdecl __swprintf_l(__wchar_t *, const __wchar_t *, _locale_t, ...); } extern "C" { extern __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS.")) int __cdecl __vswprintf_l(__wchar_t *, const __wchar_t *, _locale_t, va_list); } 
#pragma warning(pop)
#line 34 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\swprintf.inl"
#pragma warning( push )
#pragma warning( disable : 4793 4412 )
extern "C" { static __inline int swprintf(__wchar_t *_String, size_t _Count, const __wchar_t *_Format, ...) 
{ 
auto va_list _Arglist; 
auto int _Ret; 
__va_start(&_Arglist, _Format); 
_Ret = _vswprintf_c_l(_String, _Count, _Format, 0, _Arglist); 
_Arglist = ((va_list)0); 
return _Ret; 
} } 
#pragma warning( pop )

#pragma warning( push )
#pragma warning( disable : 4412 )
extern "C" { static __inline int __cdecl vswprintf(__wchar_t *_String, size_t _Count, const __wchar_t *_Format, va_list _Ap) 
{ 
return _vswprintf_c_l(_String, _Count, _Format, 0, _Ap); 
} } 
#pragma warning( pop )
#line 58 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\swprintf.inl"
#pragma warning( push )
#pragma warning( disable : 4793 4412 )
extern "C" { static __inline int _swprintf_l(__wchar_t *_String, size_t _Count, const __wchar_t *_Format, _locale_t _Plocinfo, ...) 
{ 
auto va_list _Arglist; 
auto int _Ret; 
__va_start(&_Arglist, _Plocinfo); 
_Ret = _vswprintf_c_l(_String, _Count, _Format, _Plocinfo, _Arglist); 
_Arglist = ((va_list)0); 
return _Ret; 
} } 
#pragma warning( pop )

#pragma warning( push )
#pragma warning( disable : 4412 )
extern "C" { static __inline int __cdecl _vswprintf_l(__wchar_t *_String, size_t _Count, const __wchar_t *_Format, _locale_t _Plocinfo, va_list _Ap) 
{ 
return _vswprintf_c_l(_String, _Count, _Format, _Plocinfo, _Ap); 
} } 
#pragma warning( pop )


#pragma warning( push )
#pragma warning( disable : 4996 )

#pragma warning( push )
#pragma warning( disable : 4793 4141 )
__inline __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS.")) int swprintf(__wchar_t *_String, const __wchar_t *_Format, ...) 
{ 
auto va_list _Arglist; 
__va_start(&_Arglist, _Format); 
auto int _Ret = _vswprintf(_String, _Format, _Arglist); 
_Arglist = ((va_list)0); 
return _Ret; 
} 
#pragma warning( pop )

#pragma warning( push )
#pragma warning( disable : 4141 )
__inline __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS.")) int __cdecl vswprintf(__wchar_t *_String, const __wchar_t *_Format, va_list _Ap) 
{ 
return _vswprintf(_String, _Format, _Ap); 
} 
#pragma warning( pop )

#pragma warning( push )
#pragma warning( disable : 4793 4141 )
__inline __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS.")) int _swprintf_l(__wchar_t *_String, const __wchar_t *_Format, _locale_t _Plocinfo, ...) 
{ 
auto va_list _Arglist; 
__va_start(&_Arglist, _Plocinfo); 
auto int _Ret = __vswprintf_l(_String, _Format, _Plocinfo, _Arglist); 
_Arglist = ((va_list)0); 
return _Ret; 
} 
#pragma warning( pop )

#pragma warning( push )
#pragma warning( disable : 4141 )
__inline __declspec(deprecated("swprintf has been changed to conform with the ISO C standard, adding an extra character count parameter. To use traditional Microsoft swprintf, set _CRT_NON_CONFORMING_SWPRINTFS.")) int __cdecl _vswprintf_l(__wchar_t *_String, const __wchar_t *_Format, _locale_t _Plocinfo, va_list _Ap) 
{ 
return __vswprintf_l(_String, _Format, _Plocinfo, _Ap); 
} 
#pragma warning( pop )

#pragma warning( pop )
#line 561 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern __wchar_t *__cdecl _wtempnam(const __wchar_t *, const __wchar_t *); } 
#line 567 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern int __cdecl _vscwprintf(const __wchar_t *, va_list); } 
extern "C" { extern int __cdecl _vscwprintf_l(const __wchar_t *, _locale_t, va_list); } 
extern "C" { extern int __cdecl fwscanf(FILE *, const __wchar_t *, ...); } 
extern "C" { extern int __cdecl _fwscanf_l(FILE *, const __wchar_t *, _locale_t, ...); } 

extern "C" { extern int __cdecl fwscanf_s(FILE *, const __wchar_t *, ...); } 
#line 574 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern int __cdecl _fwscanf_s_l(FILE *, const __wchar_t *, _locale_t, ...); } 
extern "C" { extern int __cdecl swscanf(const __wchar_t *, const __wchar_t *, ...); } 
extern "C" { extern int __cdecl _swscanf_l(const __wchar_t *, const __wchar_t *, _locale_t, ...); } 

extern "C" { extern int __cdecl swscanf_s(const __wchar_t *, const __wchar_t *, ...); } 
#line 580 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern int __cdecl _swscanf_s_l(const __wchar_t *, const __wchar_t *, _locale_t, ...); } 
extern "C" { extern int __cdecl _snwscanf(const __wchar_t *, size_t, const __wchar_t *, ...); } 
extern "C" { extern int __cdecl _snwscanf_l(const __wchar_t *, size_t, const __wchar_t *, _locale_t, ...); } 
extern "C" { extern int __cdecl _snwscanf_s(const __wchar_t *, size_t, const __wchar_t *, ...); } 
extern "C" { extern int __cdecl _snwscanf_s_l(const __wchar_t *, size_t, const __wchar_t *, _locale_t, ...); } 
extern "C" { extern int __cdecl wscanf(const __wchar_t *, ...); } 
extern "C" { extern int __cdecl _wscanf_l(const __wchar_t *, _locale_t, ...); } 

extern "C" { extern int __cdecl wscanf_s(const __wchar_t *, ...); } 
#line 590 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern int __cdecl _wscanf_s_l(const __wchar_t *, _locale_t, ...); } 
#pragma warning(pop)

extern "C" { extern FILE *__cdecl _wfdopen(int, const __wchar_t *); } 
extern "C" { extern FILE *__cdecl _wfopen(const __wchar_t *, const __wchar_t *); } 
extern "C" { extern errno_t __cdecl _wfopen_s(FILE **, const __wchar_t *, const __wchar_t *); } 
extern "C" { extern FILE *__cdecl _wfreopen(const __wchar_t *, const __wchar_t *, FILE *); } 
extern "C" { extern errno_t __cdecl _wfreopen_s(FILE **, const __wchar_t *, const __wchar_t *, FILE *); } 
#line 603
extern "C" { extern FILE *__cdecl _wpopen(const __wchar_t *, const __wchar_t *); } 
extern "C" { extern int __cdecl _wremove(const __wchar_t *); } 
extern "C" { extern errno_t __cdecl _wtmpnam_s(__wchar_t *, size_t); } 
template < size_t _Size > inline errno_t __cdecl _wtmpnam_s ( wchar_t ( & _Buffer ) [ _Size ] ) { return _wtmpnam_s ( _Buffer, _Size ); }
extern "C" { extern __wchar_t *__cdecl _wtmpnam(__wchar_t *); } 

extern "C" { extern wint_t __cdecl _fgetwc_nolock(FILE *); } 
extern "C" { extern wint_t __cdecl _fputwc_nolock(__wchar_t, FILE *); } 
extern "C" { extern wint_t __cdecl _ungetwc_nolock(wint_t, FILE *); } 
#line 619 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { inline wint_t __cdecl getwchar() 
{ return fgetwc(__iob_func() + 0); } } 
extern "C" { inline wint_t __cdecl putwchar(__wchar_t _C) 
{ return fputwc(_C, __iob_func() + 1); } } 
#line 669 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern void __cdecl _lock_file(FILE *); } 
extern "C" { extern void __cdecl _unlock_file(FILE *); } 
#line 677 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern int __cdecl _fclose_nolock(FILE *); } 
extern "C" { extern int __cdecl _fflush_nolock(FILE *); } 
extern "C" { extern size_t __cdecl _fread_nolock(void *, size_t, size_t, FILE *); } 
extern "C" { extern size_t __cdecl _fread_nolock_s(void *, size_t, size_t, size_t, FILE *); } 
extern "C" { extern int __cdecl _fseek_nolock(FILE *, long, int); } 
extern "C" { extern long __cdecl _ftell_nolock(FILE *); } 
extern "C" { extern int __cdecl _fseeki64_nolock(FILE *, __int64, int); } 
extern "C" { extern __int64 __cdecl _ftelli64_nolock(FILE *); } 
extern "C" { extern size_t __cdecl _fwrite_nolock(const void *, size_t, size_t, FILE *); } 
extern "C" { extern int __cdecl _ungetc_nolock(int, FILE *); } 
#line 713 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern char *__cdecl tempnam(const char *, const char *); } 
#line 719 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
extern "C" { extern int __cdecl fcloseall(); } 
extern "C" { extern FILE *__cdecl fdopen(int, const char *); } 
extern "C" { extern int __cdecl fgetchar(); } 
extern "C" { extern int __cdecl fileno(FILE *); } 
extern "C" { extern int __cdecl flushall(); } 
extern "C" { extern int __cdecl fputchar(int); } 
extern "C" { extern int __cdecl getw(FILE *); } 
extern "C" { extern int __cdecl putw(int, FILE *); } 
extern "C" { extern int __cdecl rmtmp(); } 
#line 37 "C:\\my\\work\\BarsWF\\cutil.h"
#pragma warning( disable : 4996 )
#line 736 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\stdio.h"
#pragma pack ( pop )
#line 65 "C:\\my\\work\\BarsWF\\cutil.h"
enum CUTBoolean { 

CUTFalse, 
CUTTrue
}; 
#line 77
extern "C" { extern __declspec( dllimport ) void __stdcall cutFree(void *); } 
#line 95
extern "C" { extern __declspec( dllimport ) void __stdcall cutCheckBankAccess(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, const char *, const int, const char *, const int); } 
#line 108
extern "C" { extern __declspec( dllimport ) char *__stdcall cutFindFilePath(const char *, const char *); } 
#line 123
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutReadFilef(const char *, float **, unsigned *, bool = false); } 
#line 139
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutReadFiled(const char *, double **, unsigned *, bool = false); } 
#line 155
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutReadFilei(const char *, int **, unsigned *, bool = false); } 
#line 170
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutReadFileui(const char *, unsigned **, unsigned *, bool = false); } 
#line 186
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutReadFileb(const char *, char **, unsigned *, bool = false); } 
#line 202
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutReadFileub(const char *, unsigned char **, unsigned *, bool = false); } 
#line 216
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutWriteFilef(const char *, const float *, unsigned, const float, bool = false); } 
#line 230
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutWriteFiled(const char *, const float *, unsigned, const double, bool = false); } 
#line 242
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutWriteFilei(const char *, const int *, unsigned, bool = false); } 
#line 254
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutWriteFileui(const char *, const unsigned *, unsigned, bool = false); } 
#line 266
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutWriteFileb(const char *, const char *, unsigned, bool = false); } 
#line 278
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutWriteFileub(const char *, const unsigned char *, unsigned, bool = false); } 
#line 294
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutLoadPGMub(const char *, unsigned char **, unsigned *, unsigned *); } 
#line 307
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutLoadPPMub(const char *, unsigned char **, unsigned *, unsigned *); } 
#line 321
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutLoadPPM4ub(const char *, unsigned char **, unsigned *, unsigned *); } 
#line 337
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutLoadPGMi(const char *, unsigned **, unsigned *, unsigned *); } 
#line 353
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutLoadPGMs(const char *, unsigned short **, unsigned *, unsigned *); } 
#line 368
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutLoadPGMf(const char *, float **, unsigned *, unsigned *); } 
#line 380
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutSavePGMub(const char *, unsigned char *, unsigned, unsigned); } 
#line 392
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutSavePPMub(const char *, unsigned char *, unsigned, unsigned); } 
#line 405
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutSavePPM4ub(const char *, unsigned char *, unsigned, unsigned); } 
#line 417
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutSavePGMi(const char *, unsigned *, unsigned, unsigned); } 
#line 429
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutSavePGMs(const char *, unsigned short *, unsigned, unsigned); } 
#line 441
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutSavePGMf(const char *, float *, unsigned, unsigned); } 
#line 462
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutCheckCmdLineFlag(const int, const char **, const char *); } 
#line 476
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutGetCmdLineArgumenti(const int, const char **, const char *, int *); } 
#line 490
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutGetCmdLineArgumentf(const int, const char **, const char *, float *); } 
#line 504
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutGetCmdLineArgumentstr(const int, const char **, const char *, char **); } 
#line 519
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutGetCmdLineArgumentListstr(const int, const char **, const char *, char **, unsigned *); } 
#line 533
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutCheckCondition(int, const char *, const int); } 
#line 545
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutComparef(const float *, const float *, const unsigned); } 
#line 558
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutComparei(const int *, const int *, const unsigned); } 
#line 571
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutCompareub(const unsigned char *, const unsigned char *, const unsigned); } 
#line 585
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutComparefe(const float *, const float *, const unsigned, const float); } 
#line 600
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutCompareL2fe(const float *, const float *, const unsigned, const float); } 
#line 613
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutCreateTimer(unsigned *); } 
#line 622
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutDeleteTimer(unsigned); } 
#line 630
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutStartTimer(const unsigned); } 
#line 638
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutStopTimer(const unsigned); } 
#line 646
extern "C" { extern __declspec( dllimport ) CUTBoolean __stdcall cutResetTimer(const unsigned); } 
#line 655
extern "C" { extern __declspec( dllimport ) float __stdcall cutGetTimerValue(const unsigned); } 
#line 666
extern "C" { extern __declspec( dllimport ) float __stdcall cutGetAverageTimerValue(const unsigned); } 
#line 8 "c:\\my\\work\\barswf\\algo\\md5\\..\\..\\global_c.h"
struct md5_data { 
int res[4]; 
}; 

struct gpu_data_xyz { 

gpu_data_xyz() : is_speed_detected(0) { } 
int is_speed_detected; 
int device_id; 
int last_len; 
int grid_n; int thread_n; 
int keys_per_thread; 
unsigned *data_h; 
int *result; 
#line 30
md5_data *common_h; 
#line 32 "c:\\my\\work\\barswf\\algo\\md5\\..\\..\\global_c.h"
}; 
#line 10 "c:\\my\\work\\barswf\\algo\\md5\\md5_kernel.h"
extern "C" int do_123(gpu_data_xyz *, int, int); 
extern "C" void cuda_done_md5(); 
extern "C" void cuda_get_mem(gpu_data_xyz *); 
extern "C" void cuda_free_mem(gpu_data_xyz *); 
extern "C" void init_md5_cuda(gpu_data_xyz *, int *, unsigned char *, int); 
#line 22 "c:/my/work/BarsWF/algo/md5/md5_kernel.cu"
__loc_sc__(__constant__,,) unsigned __shadow_var(,charset_c)[256]; 
__loc_sc__(__constant__,,) unsigned __shadow_var(,target_hash)[4]; 

__loc_sc__(__device__,,) unsigned *__shadow_var(,result_d); 
__loc_sc__(__device__,,) unsigned *__shadow_var(,data_d); 

void CCU2() 
{ 
auto cudaError_t result = cudaGetLastError(); 
if (result != (cudaSuccess)) 
{ 
auto char msg[512]; ((msg)[0]) = (0); 
strcpy_s(msg, 512, "CUDA kernel error: "); 
strcat_s(msg, 512, cudaGetErrorString(result)); 
printf(msg); 
return; 
}  
} 

extern "C" void cuda_get_mem(gpu_data_xyz *data) 
{ 



cudaMalloc((void **)(&__shadow_var(,data_d)), ((sizeof(int) * (4)) * data->thread_n) * data->grid_n); 
CCU2(); 
cudaMallocHost((void **)(&(data->data_h)), ((sizeof(int) * (4)) * data->thread_n) * data->grid_n); 
CCU2(); 

cudaMalloc((void **)(&__shadow_var(,result_d)), (sizeof(int) * data->thread_n) * data->grid_n); 
CCU2(); 
cudaMallocHost((void **)(&(data->result)), (sizeof(int) * data->thread_n) * data->grid_n); 
CCU2(); 
} 

extern "C" void init_md5_cuda(gpu_data_xyz *data, int *hash_i, unsigned char *charset, int charset_len) 
{ 
auto int charset_int[256]; 
memset(charset_int, 0, sizeof(charset_int)); 
for (int i = 0; i < charset_len; i++) { 
((charset_int)[i]) = charset[i]; }  
#line 68
memset(data->result, 0, (sizeof(int) * data->thread_n) * data->grid_n); 
cudaMemcpy(__shadow_var(,result_d), data->result, (sizeof(int) * data->thread_n) * data->grid_n, cudaMemcpyHostToDevice); 
CCU2(); 
cudaMemcpyToSymbol("charset_c", charset_int, sizeof(int) * charset_len); 
CCU2(); 
cudaMemcpyToSymbol("target_hash", hash_i, sizeof(int) * (4)); 

CCU2(); 

} 

extern "C" void cuda_free_mem(gpu_data_xyz *data) 
{ 

cudaFree(__shadow_var(,data_d)); 
cudaFree(__shadow_var(,result_d)); 

cudaFreeHost(data->data_h); 
cudaFreeHost(data->result); 
} 
void md5_gpu_bruteforce_thread__entry(unsigned *data_d, unsigned *result_d, unsigned pwd_len, int charset_len);
#if 0
 
#line 89
{ 
auto const int ix = (blockDim.x * blockIdx.x + threadIdx.x); 
auto unsigned data[4]; 
auto int a; auto int b; auto int c; auto int d; 
auto const int len = (pwd_len * (8)); 
auto int ta; auto int tb; auto int tc; auto int td; 

for (int i = 0; i < 4; i++) { ((data)[i]) = data_d[ix * 4 + i]; }  

auto int res = 479376260; 
ta = (__shadow_var(,target_hash))[0]; 
tb = (__shadow_var(,target_hash))[1]; 
tc = (__shadow_var(,target_hash))[2]; 
td = (__shadow_var(,target_hash))[3]; 
tc -= td; tc = (((unsigned)tc) << ((unsigned)(32 - 15))) | (((unsigned)tc) >> ((unsigned)(32 - (32 - 15)))); tc -= ((ta ^ (td | (~tb))) + (data)[2]) + (718787259); ; 
td -= ta; td = (((unsigned)td) << ((unsigned)(32 - 10))) | (((unsigned)td) >> ((unsigned)(32 - (32 - 10)))); td -= ((tb ^ (ta | (~tc))) + 0) + 3174756917U; ; 
ta -= tb; ta = (((unsigned)ta) << ((unsigned)(32 - 6))) | (((unsigned)ta) >> ((unsigned)(32 - (32 - 6)))); ta -= ((tc ^ (tb | (~td))) + 0) + 4149444226U; ; 
tb -= tc; tb = (((unsigned)tb) << ((unsigned)(32 - 21))) | (((unsigned)tb) >> ((unsigned)(32 - (32 - 21)))); tb -= ((td ^ (tc | (~ta))) + 0) + 1309151649; ; 
tc -= td; tc = (((unsigned)tc) << ((unsigned)(32 - 15))) | (((unsigned)tc) >> ((unsigned)(32 - (32 - 15)))); tc -= ((ta ^ (td | (~tb))) + 0) + 2734768916U; ; 
td -= ta; td = (((unsigned)td) << ((unsigned)(32 - 10))) | (((unsigned)td) >> ((unsigned)(32 - (32 - 10)))); td -= ((tb ^ (ta | (~tc))) + 0) + 4264355552U; ; 
ta -= tb; ta = (((unsigned)ta) << ((unsigned)(32 - 6))) | (((unsigned)ta) >> ((unsigned)(32 - (32 - 6)))); ta -= ((tc ^ (tb | (~td))) + 0) + 1873313359; ; 
tb -= tc; tb = (((unsigned)tb) << ((unsigned)(32 - 21))) | (((unsigned)tb) >> ((unsigned)(32 - (32 - 21)))); tb -= ((td ^ (tc | (~ta))) + (data)[1]) + 2240044497U; ; 
tc -= td; tc = (((unsigned)tc) << ((unsigned)(32 - 15))) | (((unsigned)tc) >> ((unsigned)(32 - (32 - 15)))); tc -= ((ta ^ (td | (~tb))) + 0) + 4293915773U; ; 
td -= ta; td = (((unsigned)td) << ((unsigned)(32 - 10))) | (((unsigned)td) >> ((unsigned)(32 - (32 - 10)))); td -= ((tb ^ (ta | (~tc))) + (data)[3]) + 2399980690U; ; 
ta -= tb; ta = (((unsigned)ta) << ((unsigned)(32 - 6))) | (((unsigned)ta) >> ((unsigned)(32 - (32 - 6)))); ta -= ((tc ^ (tb | (~td))) + 0) + 1700485571; ; 
tb -= tc; tb = (((unsigned)tb) << ((unsigned)(32 - 21))) | (((unsigned)tb) >> ((unsigned)(32 - (32 - 21)))); tb -= ((td ^ (tc | (~ta))) + 0) + 4237533241U; ; 
tc -= td; tc = (((unsigned)tc) << ((unsigned)(32 - 15))) | (((unsigned)tc) >> ((unsigned)(32 - (32 - 15)))); tc -= ((ta ^ (td | (~tb))) + len) + 2878612391U; ; 
td -= ta; td = (((unsigned)td) << ((unsigned)(32 - 10))) | (((unsigned)td) >> ((unsigned)(32 - (32 - 10)))); td -= ((tb ^ (ta | (~tc))) + 0) + 1126891415; ; 


for (int s2 = 0; s2 < charset_len; s2++) 
{ 
((data)[0]) = (((data)[0]) & 4294902015U) + (((__shadow_var(,charset_c))[s2]) << 8); 
for (int s1 = 0; s1 < charset_len; s1++) 
{ 
((data)[0]) = (((data)[0]) & 4294967040U) + (__shadow_var(,charset_c))[s1]; 

a = 1732584193; b = (4023233417U); c = (2562383102U); d = 271733878; 


{ a += ((data)[0] + 3614090360U) + ((b & c) | ((~b) & d)); a = ((((unsigned)a) << ((unsigned)7)) | (((unsigned)a) >> ((unsigned)(32 - 7)))) + (unsigned)b; ; } ; 
{ d += ((data)[1] + 3905402710U) + ((a & b) | ((~a) & c)); d = ((((unsigned)d) << ((unsigned)12)) | (((unsigned)d) >> ((unsigned)(32 - 12)))) + (unsigned)a; ; } ; 
{ c += ((data)[2] + (606105819)) + ((d & a) | ((~d) & b)); c = ((((unsigned)c) << ((unsigned)17)) | (((unsigned)c) >> ((unsigned)(32 - 17)))) + (unsigned)d; ; } ; 
{ b += ((data)[3] + 3250441966U) + ((c & d) | ((~c) & a)); b = ((((unsigned)b) << ((unsigned)22)) | (((unsigned)b) >> ((unsigned)(32 - 22)))) + (unsigned)c; ; } ; 


{ a += ((0) + 4118548399U) + ((b & c) | ((~b) & d)); a = ((((unsigned)a) << ((unsigned)7)) | (((unsigned)a) >> ((unsigned)(32 - 7)))) + (unsigned)b; ; } ; 
{ d += (0 + 1200080426) + ((a & b) | ((~a) & c)); d = ((((unsigned)d) << ((unsigned)12)) | (((unsigned)d) >> ((unsigned)(32 - 12)))) + (unsigned)a; ; } ; 
{ c += ((0) + 2821735955U) + ((d & a) | ((~d) & b)); c = ((((unsigned)c) << ((unsigned)17)) | (((unsigned)c) >> ((unsigned)(32 - 17)))) + (unsigned)d; ; } ; 
{ b += ((0) + 4249261313U) + ((c & d) | ((~c) & a)); b = ((((unsigned)b) << ((unsigned)22)) | (((unsigned)b) >> ((unsigned)(32 - 22)))) + (unsigned)c; ; } ; 
{ a += (0 + 1770035416) + ((b & c) | ((~b) & d)); a = ((((unsigned)a) << ((unsigned)7)) | (((unsigned)a) >> ((unsigned)(32 - 7)))) + (unsigned)b; ; } ; 
{ d += ((0) + 2336552879U) + ((a & b) | ((~a) & c)); d = ((((unsigned)d) << ((unsigned)12)) | (((unsigned)d) >> ((unsigned)(32 - 12)))) + (unsigned)a; ; } ; 
{ c += ((0) + 4294925233U) + ((d & a) | ((~d) & b)); c = ((((unsigned)c) << ((unsigned)17)) | (((unsigned)c) >> ((unsigned)(32 - 17)))) + (unsigned)d; ; } ; 
{ b += ((0) + 2304563134U) + ((c & d) | ((~c) & a)); b = ((((unsigned)b) << ((unsigned)22)) | (((unsigned)b) >> ((unsigned)(32 - 22)))) + (unsigned)c; ; } ; 
{ a += (0 + 1804603682) + ((b & c) | ((~b) & d)); a = ((((unsigned)a) << ((unsigned)7)) | (((unsigned)a) >> ((unsigned)(32 - 7)))) + (unsigned)b; ; } ; 
{ d += ((0) + 4254626195U) + ((a & b) | ((~a) & c)); d = ((((unsigned)d) << ((unsigned)12)) | (((unsigned)d) >> ((unsigned)(32 - 12)))) + (unsigned)a; ; } ; 
{ c += (len + 2792965006U) + ((d & a) | ((~d) & b)); c = ((((unsigned)c) << ((unsigned)17)) | (((unsigned)c) >> ((unsigned)(32 - 17)))) + (unsigned)d; ; } ; 
{ b += (0 + 1236535329) + ((c & d) | ((~c) & a)); b = ((((unsigned)b) << ((unsigned)22)) | (((unsigned)b) >> ((unsigned)(32 - 22)))) + (unsigned)c; ; } ; 


{ a += ((data)[1] + 4129170786U) + ((b & d) | (c & (~d))); a = ((((unsigned)a) << ((unsigned)5)) | (((unsigned)a) >> ((unsigned)(32 - 5)))) + (unsigned)b; ; } ; 
{ d += ((0) + 3225465664U) + ((a & c) | (b & (~c))); d = ((((unsigned)d) << ((unsigned)9)) | (((unsigned)d) >> ((unsigned)(32 - 9)))) + (unsigned)a; ; } ; 
{ c += (0 + 643717713) + ((d & b) | (a & (~b))); c = ((((unsigned)c) << ((unsigned)14)) | (((unsigned)c) >> ((unsigned)(32 - 14)))) + (unsigned)d; ; } ; 
{ b += ((data)[0] + 3921069994U) + ((c & a) | (d & (~a))); b = ((((unsigned)b) << ((unsigned)20)) | (((unsigned)b) >> ((unsigned)(32 - 20)))) + (unsigned)c; ; } ; 
{ a += ((0) + 3593408605U) + ((b & d) | (c & (~d))); a = ((((unsigned)a) << ((unsigned)5)) | (((unsigned)a) >> ((unsigned)(32 - 5)))) + (unsigned)b; ; } ; 
{ d += (0 + 38016083) + ((a & c) | (b & (~c))); d = ((((unsigned)d) << ((unsigned)9)) | (((unsigned)d) >> ((unsigned)(32 - 9)))) + (unsigned)a; ; } ; 
{ c += ((0) + 3634488961U) + ((d & b) | (a & (~b))); c = ((((unsigned)c) << ((unsigned)14)) | (((unsigned)c) >> ((unsigned)(32 - 14)))) + (unsigned)d; ; } ; 
{ b += ((0) + 3889429448U) + ((c & a) | (d & (~a))); b = ((((unsigned)b) << ((unsigned)20)) | (((unsigned)b) >> ((unsigned)(32 - 20)))) + (unsigned)c; ; } ; 
{ a += (0 + 568446438) + ((b & d) | (c & (~d))); a = ((((unsigned)a) << ((unsigned)5)) | (((unsigned)a) >> ((unsigned)(32 - 5)))) + (unsigned)b; ; } ; 
{ d += (len + 3275163606U) + ((a & c) | (b & (~c))); d = ((((unsigned)d) << ((unsigned)9)) | (((unsigned)d) >> ((unsigned)(32 - 9)))) + (unsigned)a; ; } ; 
{ c += ((data)[3] + 4107603335U) + ((d & b) | (a & (~b))); c = ((((unsigned)c) << ((unsigned)14)) | (((unsigned)c) >> ((unsigned)(32 - 14)))) + (unsigned)d; ; } ; 
{ b += (0 + 1163531501) + ((c & a) | (d & (~a))); b = ((((unsigned)b) << ((unsigned)20)) | (((unsigned)b) >> ((unsigned)(32 - 20)))) + (unsigned)c; ; } ; 
{ a += ((0) + 2850285829U) + ((b & d) | (c & (~d))); a = ((((unsigned)a) << ((unsigned)5)) | (((unsigned)a) >> ((unsigned)(32 - 5)))) + (unsigned)b; ; } ; 
{ d += ((data)[2] + 4243563512U) + ((a & c) | (b & (~c))); d = ((((unsigned)d) << ((unsigned)9)) | (((unsigned)d) >> ((unsigned)(32 - 9)))) + (unsigned)a; ; } ; 
{ c += (0 + 1735328473) + ((d & b) | (a & (~b))); c = ((((unsigned)c) << ((unsigned)14)) | (((unsigned)c) >> ((unsigned)(32 - 14)))) + (unsigned)d; ; } ; 
{ b += ((0) + 2368359562U) + ((c & a) | (d & (~a))); b = ((((unsigned)b) << ((unsigned)20)) | (((unsigned)b) >> ((unsigned)(32 - 20)))) + (unsigned)c; ; } ; 


{ a += ((0) + 4294588738U) + ((b ^ c) ^ d); a = ((((unsigned)a) << ((unsigned)4)) | (((unsigned)a) >> ((unsigned)(32 - 4)))) + (unsigned)b; ; } ; 
{ d += ((0) + 2272392833U) + ((a ^ b) ^ c); d = ((((unsigned)d) << ((unsigned)11)) | (((unsigned)d) >> ((unsigned)(32 - 11)))) + (unsigned)a; ; } ; 
{ c += (0 + 1839030562) + ((d ^ a) ^ b); c = ((((unsigned)c) << ((unsigned)16)) | (((unsigned)c) >> ((unsigned)(32 - 16)))) + (unsigned)d; ; } ; 
{ b += (len + 4259657740U) + ((c ^ d) ^ a); b = ((((unsigned)b) << ((unsigned)23)) | (((unsigned)b) >> ((unsigned)(32 - 23)))) + (unsigned)c; ; } ; 
{ a += ((data)[1] + 2763975236U) + ((b ^ c) ^ d); a = ((((unsigned)a) << ((unsigned)4)) | (((unsigned)a) >> ((unsigned)(32 - 4)))) + (unsigned)b; ; } ; 
{ d += (0 + 1272893353) + ((a ^ b) ^ c); d = ((((unsigned)d) << ((unsigned)11)) | (((unsigned)d) >> ((unsigned)(32 - 11)))) + (unsigned)a; ; } ; 
{ c += ((0) + 4139469664U) + ((d ^ a) ^ b); c = ((((unsigned)c) << ((unsigned)16)) | (((unsigned)c) >> ((unsigned)(32 - 16)))) + (unsigned)d; ; } ; 
{ b += ((0) + 3200236656U) + ((c ^ d) ^ a); b = ((((unsigned)b) << ((unsigned)23)) | (((unsigned)b) >> ((unsigned)(32 - 23)))) + (unsigned)c; ; } ; 
{ a += (0 + 681279174) + ((b ^ c) ^ d); a = ((((unsigned)a) << ((unsigned)4)) | (((unsigned)a) >> ((unsigned)(32 - 4)))) + (unsigned)b; ; } ; 
{ d += ((data)[0] + 3936430074U) + ((a ^ b) ^ c); d = ((((unsigned)d) << ((unsigned)11)) | (((unsigned)d) >> ((unsigned)(32 - 11)))) + (unsigned)a; ; } ; 
{ c += ((data)[3] + 3572445317U) + ((d ^ a) ^ b); c = ((((unsigned)c) << ((unsigned)16)) | (((unsigned)c) >> ((unsigned)(32 - 16)))) + (unsigned)d; ; } ; 
{ b += (0 + 76029189) + ((c ^ d) ^ a); b = ((((unsigned)b) << ((unsigned)23)) | (((unsigned)b) >> ((unsigned)(32 - 23)))) + (unsigned)c; ; } ; 
{ a += ((0) + 3654602809U) + ((b ^ c) ^ d); a = ((((unsigned)a) << ((unsigned)4)) | (((unsigned)a) >> ((unsigned)(32 - 4)))) + (unsigned)b; ; } ; 
{ d += ((0) + 3873151461U) + ((a ^ b) ^ c); d = ((((unsigned)d) << ((unsigned)11)) | (((unsigned)d) >> ((unsigned)(32 - 11)))) + (unsigned)a; ; } ; 
if (d != td) { continue; }  
{ c += (0 + 530742520) + ((d ^ a) ^ b); c = ((((unsigned)c) << ((unsigned)16)) | (((unsigned)c) >> ((unsigned)(32 - 16)))) + (unsigned)d; ; } ; 
{ b += ((data)[2] + 3299628645U) + ((c ^ d) ^ a); b = ((((unsigned)b) << ((unsigned)23)) | (((unsigned)b) >> ((unsigned)(32 - 23)))) + (unsigned)c; ; } ; 


{ a += ((data)[0] + 4096336452U) + (c ^ (b | (~d))); a = ((((unsigned)a) << ((unsigned)6)) | (((unsigned)a) >> ((unsigned)(32 - 6)))) + (unsigned)b; ; } ; 

if (((a == ta) && (b == tb)) && (c == tc)) 
{ 
res = 1334931688; 
}  ; 
}  
}  

(result_d[ix]) = res; 
} 
#endif
#line 201 "c:/my/work/BarsWF/algo/md5/md5_kernel.cu"
extern "C" int do_123(gpu_data_xyz *data, int pwd_len, int charset_len) 
{ 
auto dim3 threads(data->thread_n); 
auto dim3 grid(data->grid_n); 
#line 212
cudaMemcpy(__shadow_var(,data_d), data->data_h, ((sizeof(int) * (4)) * data->thread_n) * data->grid_n, cudaMemcpyHostToDevice); 
cudaConfigureCall(grid, threads) ? ((void)0) : md5_gpu_bruteforce_thread__entry(__shadow_var(,data_d), __shadow_var(,result_d), pwd_len, charset_len); 

cudaMemcpy(data->result, __shadow_var(,result_d), (sizeof(int) * data->thread_n) * data->grid_n, cudaMemcpyDeviceToHost); 
CCU2(); 

auto cudaError_t result = cudaGetLastError(); 
if (result != (cudaSuccess)) 
{ 
auto char msg[512]; ((msg)[0]) = (0); 
strcpy_s(msg, 512, "CUDA kernel error: "); 
strcat_s(msg, 512, cudaGetErrorString(result)); 
printf(msg); 
return 1; 
}  
#line 235
return 0; 
} 

#include "md5_kernel.cudafe1.stub.c"
