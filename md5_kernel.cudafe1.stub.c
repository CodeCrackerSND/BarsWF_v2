#if defined(__cplusplus)
extern "C" {
#endif
#include "md5_kernel.fatbin.c"
#include "crt/host_runtime.h"
#if defined(__device_emulation) && defined(__cplusplus)
namespace __cuda_emu {struct __T20 {unsigned *__par0;unsigned *__par1;unsigned __par2;int __par3;int __dummy_field;__pad__(volatile char __dummy[4];)};
}
#endif
struct __T20 {unsigned *__par0;unsigned *__par1;unsigned __par2;int __par3;int __dummy_field;__pad__(volatile char __dummy[4];)};
static void __sti____cudaRegisterAll_18_md5_kernel_cpp1_ii__Z4CCU2v(void);
#pragma section(".CRT$XCU",read)
__declspec(allocate(".CRT$XCU"))static void (__cdecl *__dummy_static_init__sti____cudaRegisterAll_18_md5_kernel_cpp1_ii__Z4CCU2v[])(void) = {__sti____cudaRegisterAll_18_md5_kernel_cpp1_ii__Z4CCU2v};
void __device_stub__Z25md5_gpu_bruteforce_threadPjS_ji(unsigned *__par0, unsigned *__par1, unsigned __par2, int __par3){auto struct __T20 *__T21;
__cudaInitArgBlock(__T21);__cudaSetupArg(__par0, __T21);__cudaSetupArg(__par1, __T21);__cudaSetupArg(__par2, __T21);__cudaSetupArg(__par3, __T21);__cudaLaunch(((char *)__device_stub_name(__device_stub__Z25md5_gpu_bruteforce_threadPjS_ji,((void ( *)(unsigned *, unsigned *, unsigned, int))md5_gpu_bruteforce_thread__entry))));}
#if defined(__cplusplus)
}
void md5_gpu_bruteforce_thread__entry( unsigned *__cuda_0,unsigned *__cuda_1,unsigned __cuda_2,int __cuda_3)
{__device_stub__Z25md5_gpu_bruteforce_threadPjS_ji( __cuda_0,__cuda_1,__cuda_2,__cuda_3);}
extern "C"{
#endif
#if defined(__device_emulation)
#if defined(__cplusplus)
namespace __cuda_emu {
#endif
static void __device_wrapper__Z25md5_gpu_bruteforce_threadPjS_ji(char *__T25){_Z25md5_gpu_bruteforce_threadPjS_ji((((*((struct __T20 *)__T25)).__par0)), (((*((struct __T20 *)__T25)).__par1)), (((*((struct __T20 *)__T25)).__par2)), (((*((struct __T20 *)__T25)).__par3)));}
#if defined(__cplusplus)
}
#endif
#endif
static void __sti____cudaRegisterAll_18_md5_kernel_cpp1_ii__Z4CCU2v(void){__cudaRegisterBinary();__cudaRegisterEntry(__device_stub_name(__device_stub__Z25md5_gpu_bruteforce_threadPjS_ji,((void ( *)(unsigned *, unsigned *, unsigned, int))md5_gpu_bruteforce_thread__entry)), _Z25md5_gpu_bruteforce_threadPjS_ji, (-1));__cudaRegisterVariable(__shadow_var(charset_c,charset_c), 0, 1024, 1, 0);__cudaRegisterVariable(__shadow_var(target_hash,target_hash), 0, 16, 1, 0);__cudaRegisterVariable(__shadow_var(result_d,result_d), 0, 8, 0, 0);__cudaRegisterVariable(__shadow_var(data_d,data_d), 0, 8, 0, 0);}
#if defined(__cplusplus)
}
#endif
