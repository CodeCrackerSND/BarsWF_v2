#ifdef _WIN32
#pragma warning(disable:4164 4003)
#endif 
#line 1 "md5_kernel.cudafe1.gpu"
#line 476 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\crtdefs.h"
typedef unsigned __int64 size_t;
#include "crt/host_runtime.h"
#line 93 "D:\\Program Files (x86)\\Microsoft Visual Studio 9.0\\VC\\include\\time.h"
typedef long clock_t;
void *memcpy(void*, const void*, size_t); void *memset(void*, int, size_t);
#include "md5_kernel.cudafe2.stub.h"
#line 22 "c:/my/work/BarsWF/algo/md5/md5_kernel.cu"
__loc_sc__(__constant__,,) unsigned __shadow_var(charset_c,charset_c)[256];
#line 23 "c:/my/work/BarsWF/algo/md5/md5_kernel.cu"
__loc_sc__(__constant__,,) unsigned __shadow_var(target_hash,target_hash)[4];
#line 25 "c:/my/work/BarsWF/algo/md5/md5_kernel.cu"
__loc_sc__(__device__,,) unsigned *__shadow_var(result_d,result_d);
#line 26 "c:/my/work/BarsWF/algo/md5/md5_kernel.cu"
__loc_sc__(__device__,,) unsigned *__shadow_var(data_d,data_d);

#include "md5_kernel.cudafe2.stub.c"
