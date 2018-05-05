#pragma once

#if defined(__GNUC__) || defined(__INTEL_COMPILER)
#define LIKELY(x)       __builtin_expect((x),1)
#define UNLIKELY(x)     __builtin_expect((x),0)
#define EXPECT(x, val)  __builtin_expect((x),val)
#else
#define LIKELY(x)       (x)
#define UNLIKELY(x)     (x)
#define EXPECT(x, val)  (x)
#endif

#ifndef _MSC_VER
#include <cstring>
#include <stdio.h>
#define _stricmp strcasecmp
#define _strnicmp strncasecmp
#endif

#ifndef _WIN32
#include <stdlib.h>
#define __forceinline inline
#ifndef __cdecl
#define __cdecl
#endif
#define _InterlockedCompareExchangePointer(a,b,c) __sync_val_compare_and_swap(a,c,b)

static inline void* _aligned_malloc(size_t size, size_t alignment)
{
    void *tmp;
    if (posix_memalign(&tmp, alignment, size))
    {
        tmp = 0;
    }
    return tmp;
}
#define _aligned_free free
#else
#include <intrin.h>
#endif


#define ALIGNED_ARRAY(type, decl, alignment) alignas(alignment) type decl
