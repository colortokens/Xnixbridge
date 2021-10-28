#pragma once

#if !defined(RtlZeroMemory)
#define RtlZeroMemory(destination, length) memset(destination, 0, length)
#endif

#if !defined(RtlCopyMemory)
#define RtlCopyMemory(destination, source, length) memcpy(destination, source, length)
#endif

#if !defined(UNREFERENCED_PARAMETER)
#define UNREFERENCED_PARAMETER(parameter)
#endif

#if defined(__APPLE__)

#if !defined(ExAllocatePoolWithTag)
#define ExAllocatePoolWithTag(pool_type, number_of_bytes, tag) _MALLOC(number_of_bytes, M_TEMP, M_ZERO | M_WAITOK)
#endif

#if !defined(ExAllocatePool)
#define ExAllocatePool(pool_type, number_of_bytes) _MALLOC(number_of_bytes, M_TEMP, M_ZERO | M_WAITOK)
#endif

#if !defined(ExFreePool)
#define ExFreePool(p) _FREE(p, M_TEMP)
#endif

#else

#include <linux/vmalloc.h>

#if !defined(ExAllocatePoolWithTag)
#define ExAllocatePoolWithTag(pool_type, number_of_bytes, tag) vmalloc(number_of_bytes)
#endif

#if !defined(ExAllocatePool)
#define ExAllocatePool(pool_type, number_of_bytes) vmalloc(number_of_bytes)
#endif

#if !defined(ExFreePool)
#define ExFreePool(p) vfree(p)
#endif

#endif
