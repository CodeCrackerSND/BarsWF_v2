#ifndef _MD5_PP_AUTO_GENERATED_H_
#define _MD5_PP_AUTO_GENERATED_H_

/**************************************************************************** 
                                                                              
Copyright (c) 2003, Stanford University                                       
All rights reserved.                                                          
                                                                              
Copyright (c) 2008, Advanced Micro Devices, Inc.                              
All rights reserved.                                                          
                                                                              
                                                                              
The BRCC portion of BrookGPU is derived from the cTool project                
(http://ctool.sourceforge.net) and distributed under the GNU Public License.  
                                                                              
Additionally, see LICENSE.ctool for information on redistributing the         
contents of this directory.                                                   
                                                                              
****************************************************************************/ 

#include "brook/Stream.h" 
#include "brook/KernelInterface.h" 

//! Kernel declarations
class __hello_brook_check
{
    public:
        void operator()(const int  k1, const int  k2, const int  k3, const int  k4, const int  len, const int  _ta, const int  _tb, const int  _tc, const int  _td, const ::brook::Stream< int >& charset, const int  charset_len, const ::brook::Stream<  int >& output);
        EXTENDCLASS();
};
extern __THREAD__ __hello_brook_check hello_brook_check;

#endif // _MD5_PP_AUTO_GENERATED_H_

