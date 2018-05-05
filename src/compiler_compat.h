#pragma once

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
#else
#include <intrin.h>
#endif
