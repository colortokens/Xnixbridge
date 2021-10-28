/**
 * @file   xnx/bridge/types.h
 * @author Ramesh Nagireddy
 * @date   July 18, 2020
 * @brief  Includes typedefs to be able to build Windows centric OSAC.
 *
 * This file contains the defines Windows' equivalent types to be able to build
 * Operating System Agnostic Code (OSAC).  The purpose of the xnx bridge series
 * header files is to compile Windows compilable OSAC without changing a single
 * line of code when it is built in *nix systems.
 */

#pragma once

#if defined(__APPLE__)
#include <stddef.h>
#include <stdbool.h>
typedef wchar_t WCHAR;
#else
#include <linux/types.h>
typedef int32_t WCHAR;
typedef WCHAR ct_wchar_t;
#endif

#if !defined(FALSE)
#define FALSE false
#endif

#if !defined(TRUE)
#define TRUE  true
#endif


typedef WCHAR const * PCWSTR;
typedef WCHAR * PWCHAR;
typedef WCHAR * PWSTR;

typedef bool * PBOOLEAN;
typedef bool BOOLEAN;
typedef char * PCHAR;
typedef char CHAR;
typedef const char * PCSTR;
typedef int KPROCESSOR_MODE;
typedef long NTSTATUS;
typedef size_t SIZE_T;
typedef unsigned long DWORD;
typedef unsigned char UCHAR;
typedef unsigned long ULONG;
typedef unsigned short USHORT;
typedef void * HANDLE;
typedef void * PDEVICE_OBJECT;
typedef void * PVOID;
typedef void VOID;

