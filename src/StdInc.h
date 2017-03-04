/*********************************************************
*
*  Copyright © 2017, Xen Roleplay.
*
*  All Rights Reserved.
*
*  Redistribution and use in source and binary forms,
*  with or without modification,
*  is permitted only for authors.
*
*********************************************************/

extern "C"
{
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>
}

#ifdef WIN32
#define DLL_EXPORT extern "C" __declspec(dllexport)
#else
#define DLL_EXPORT extern "C"
#endif

using namespace std;

#include <algorithm>
#include <list>
#include <vector>
#include <map>
#include <string.h>
#include <sys/stat.h>
#include <assert.h>

#ifndef stricmp
#ifdef _MSC_VER
#define stricmp _stricmp
#else
#define stricmp strcasecmp
#endif
#endif

#define SAFE_DELETE(p)	{ if(p) { delete (p); (p)=nullptr; } }
#define SAFE_RELEASE(p)	{ if(p) { (p)->Release(); (p)=nullptr; } }

#ifdef _DEBUG
#define ASSERT(_Expression) (void)( (!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression), _CRT_WIDE(__FILE__), __LINE__), 0) )
#define ASSERT_MSG(_Expression, _Message) (void)( (!!(_Expression)) || (_wassert(_CRT_WIDE(_Message), _CRT_WIDE(__FILE__), __LINE__), 0) )
#else
#define ASSERT(_Expression) ((void)0)
#define ASSERT_MSG(_Expression, _Message) ((void)0)
#endif

#ifndef NUMELMS
#define NUMELMS(aa) (sizeof(aa)/sizeof((aa)[0]))
#endif

#define MAX_ARGUMENTS 10

//                                                  VS      GCC
//                      Actual sizes:      32bit   64bit   64bit
typedef	unsigned long	    ulong;      //  32      32      64
typedef unsigned int	    uint;       //  32
typedef unsigned short	    ushort;     //  16  
typedef unsigned char	    uchar;      //  8

typedef unsigned long long  uint64;     //  64
typedef unsigned int        uint32;     //  32
typedef unsigned short      uint16;     //  16
typedef unsigned char       uint8;      //  8

// signed types
typedef signed long long    int64;      //  64
typedef signed int          int32;      //  32
typedef signed short        int16;      //  16
typedef signed char         int8;       //  8

// Windowsesq types
typedef unsigned char       BYTE;       //  8
typedef unsigned short      WORD;       //  16
typedef unsigned long       DWORD;      //  32      32      64
typedef float               FLOAT;      //  32

typedef void*               PVOID;

#define MODULE_NAME             "Xen Roleplay"
#define MODULE_AUTHOR           "Dmitry Korolev <kernell@mtaroleplay.ru>"
#define MODULE_VERSION          1.0f
#define MODULE_SERVER_RESOURCE  "XRServer"
#define MODULE_CLIENT_RESOURCE  "XRClient"

#include "Math/Vector2.h"
#include "Math/Vector3.h"

#include "SharedUtil/Color.h"
#include "SharedUtil/VehicleColor.h"
#include "SharedUtil/WeaponType.h"
#include "SharedUtil/SharedUtil.h"
