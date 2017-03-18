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

#pragma once

class CRC32;

#ifndef __CRC32_H
#define __CRC32_H

class CRC32
{
public:
	static uint32_t Calc( const LPBYTE pdata, const uint32_t size, DWORD crc = 0xFFFF );
};

#endif
