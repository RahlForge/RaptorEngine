/*
 *  PlatformSpecific.h
 */

#pragma once

#ifdef WIN32
#define _USE_MATH_DEFINES
#define __STDC_WANT_LIB_EXT1__ 1
#ifndef _MSC_VER
#define UNICODE
#define _UNICODE
#endif
#if !defined(WINVER) || (WINVER < 0x502)
#undef WINVER
#define WINVER 0x502
#endif
#include <windows.h>
#ifdef _MSC_VER
#define snprintf(...) (sprintf_s(__VA_ARGS__))
#define strcasecmp(...) (_stricmp(__VA_ARGS__))
#define strncasecmp(...) (_strnicmp(__VA_ARGS__))
#define strtok_r(...) (strtok_s(__VA_ARGS__))
#endif
#undef GetObject
#undef DrawText
#undef SearchPath
#include <cfloat>
#define Z_NEAR (0.25)
#define GLEW_STATIC true
#else
#define Z_NEAR (1.)
#endif

#define Z_FAR (1099511627776.)

#if defined(__APPLE__) && ( defined(_ppc_) || defined(_ppc64_) || defined(__ppc__) || defined(__ppc64__) || defined(__POWERPC__) || defined(_M_PPC) )
#define APPLE_POWERPC true
#endif

#if defined(APPLE_POWERPC) && ! defined(APPLE_POWERPC_GLEW)
#define NO_GLEW true
#endif
