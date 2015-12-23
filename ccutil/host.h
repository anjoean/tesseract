/******************************************************************************
 **  Filename:       Host.h
 **  Purpose:        This is the system independent typedefs and defines
 **  Author:         MN, JG, MD
 **  Version:        5.4.1
 **  History:        11/7/94 MCD received the modification that Lennart made
 **                  to port to 32 bit world and modify this file so that it
 **                  will be shared between platform.
 **                  11/9/94 MCD Make MSW32 subset of MSW. Now MSW means
 **                  MicroSoft Window and MSW32 means the 32 bit worlds
 **                  of MicroSoft Window. Therefore you want the environment
 **                  to be MicroSoft Window and in the 32 bit world -
 **                  _WIN32 must be defined by your compiler.
 **                  11/30/94 MCD Incorporated comments received for more
 **                  readability and the missing typedef for FLOAT.
 **                  12/1/94 MCD Added PFVOID typedef
 **                  5/1/95 MCD. Made many changes based on the inputs.
 **                  Changes:
 **                  1) Rearrange the #ifdef so that there're definitions for
 **                  particular platforms.
 **                  2) Took out the #define for computer and environment
 **                  that developer can uncomment
 **                  3) Added __OLDCODE__ where the defines will be
 **                  obsoleted in the next version and advise not to use.
 **                  4) Added the definitions for the following:
 **                  FILE_HANDLE, MEMORY_HANDLE, BOOL8,
 **                  MAX_INT8, MAX_INT16, MAX_INT32, MAX_UINT8
 **                  MAX_UINT16, MAX_UINT32, MAX_FLOAT32
 **                 06/19/96 MCD. Took out MAX_FLOAT32
 **                 07/15/96 MCD. Fixed the comments error
 **                 Add back BOOL8.
 **
 **  (c) Copyright Hewlett-Packard Company, 1988-1996.
 ** Licensed under the Apache License, Version 2.0 (the "License");
 ** you may not use this file except in compliance with the License.
 ** You may obtain a copy of the License at
 ** http://www.apache.org/licenses/LICENSE-2.0
 ** Unless required by applicable law or agreed to in writing, software
 ** distributed under the License is distributed on an "AS IS" BASIS,
 ** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 ** See the License for the specific language governing permissions and
 ** limitations under the License.
 */

#ifndef TESSERACT_CCUTIL_HOST_H_
#define TESSERACT_CCUTIL_HOST_H_

/******************************************************************************
 **                                IMPORTANT!!!                                                                                                                 **
 **                                                                                                                                                                              **
 ** Defines either _WIN32, __MAC__, __UNIX__, __OS2__, __PM__ to
 ** use the specified definitions indicated below in the preprocessor settings.                                                        **
 **                                                                                                                                                                              **
 ** Also define either  __FarProc__ or  __FarData__  and __MOTO__ to use the
 ** specified definitions indicated below in the preprocessor settings.                                                                        **
 **                                                                                                                                                                             **
 ** If a preprocessor settings is not allow in the compiler that is being use,
 ** then it is recommended that a "platform.h" is created with the definition
 ** of the computer and/or operating system.
 ******************************************************************************/

#include <limits>
#include "platform.h"
/* _WIN32 */
#ifdef _WIN32
#include <windows.h>
#undef min
#undef max
#endif

#include <inttypes.h>            // PRId32, ...
#include <stdint.h>              // int32_t, ...

/********************************************************/
/* __MAC__ */
#ifdef __MAC__
#include <Types.h>
/*----------------------------*/
/*----------------------------*/
#endif
/********************************************************/
#if defined(__UNIX__) || defined( __DOS__ ) || defined(__OS2__) || defined(__PM__)
/*----------------------------*/
/* FarProc and FarData */
/*----------------------------*/
/*----------------------------*/
#endif
/*****************************************************************************
 **
 **                      Standard GHC Definitions
 **
 *****************************************************************************/

#ifdef __MOTO__
#define __NATIVE__   MOTO
#else
#define __NATIVE__   INTEL
#endif

//typedef HANDLE FD*  PHANDLE;

// definitions of portable data types (numbers and characters)
typedef int8_t inT8;
typedef uint8_t uinT8;
typedef int16_t inT16;
typedef uint16_t uinT16;
typedef int32_t inT32;
typedef uint32_t uinT32;
typedef int64_t inT64;
typedef uint64_t uinT64;
typedef float FLOAT32;
typedef double FLOAT64;
typedef unsigned char BOOL8;

#if defined(_WIN32)

/* MinGW defines the standard PRI... macros, but MSVS doesn't. */

#if !defined(PRId32)
# define PRId32 "d"
#endif

#if !defined(PRId64)
# define PRId64 "I64d"
#endif

#endif /* _WIN32 */

#define INT32FORMAT "%" PRId32
#define INT64FORMAT "%" PRId64

#define MAX_INT8  0x7f
#define MAX_INT16 0x7fff
#define MAX_INT32 0x7fffffff
#define MAX_UINT8 0xff
#define MAX_UINT16  0xffff
#define MAX_UINT32  0xffffffff
#define MAX_FLOAT32 std::numeric_limits<float>::max()

#define MIN_INT8 static_cast<inT8>(0x80)
#define MIN_INT16 static_cast<inT16>(0x8000)
#define MIN_INT32 static_cast<inT32>(0x80000000)
#define MIN_UINT8 0x00
#define MIN_UINT16  0x0000
#define MIN_UINT32  0x00000000
// Minimum positive value ie 1e-37ish.
#define MIN_FLOAT32 std::numeric_limits<float>::min()

// Defines
#ifndef TRUE
#define TRUE            1
#endif

#ifndef FALSE
#define FALSE           0
#endif

// Return true if x is within tolerance of y
template<class T> bool NearlyEqual(T x, T y, T tolerance) {
  T diff = x - y;
  return diff <= tolerance && -diff <= tolerance;
}

#endif  // TESSERACT_CCUTIL_HOST_H_
