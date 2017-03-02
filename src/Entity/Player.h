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

class Player;

#ifndef __PLAYER_H
#define __PLAYER_H

#include "Ped.h"

class Player : public Ped
{
public:
												Player                     ( PVOID luaUserdata );
	virtual                                     ~Player                    ();
};

struct PlayerModInfo
{
	// GTA model or texture id
	int ID;

	// GTA name
	string Name;

	// The modified model size (If the item is a DFF)
	Math::Vector3 Size;

	// The unmodified model size (If the item is a DFF)
	Math::Vector3 OriginalSize;

	// Length in bytes of the item
	uint Length;

	// md5 of the item bytes
	string MD5;

	// sha256 of the item bytes
	string SHA256;

	// Length in bytes of the item padded to 2048 byte boundary
	string PaddedLength;

	// md5 of the item bytes padded to 2048 byte boundary
	string PaddedMD5;

	// sha256 of the item bytes padded to 2048 byte boundary
	string PaddedSHA256;

	PlayerModInfo( int id, string name, Math::Vector3 size, Math::Vector3 originalSize, uint length, string md5, string sha256, string paddedLength, string paddedMd5, string paddedSha256 )
	{
		this->ID           = id;
		this->Name         = name;
		this->Size         = size;
		this->OriginalSize = originalSize;
		this->Length       = length;
		this->MD5          = md5;
		this->SHA256       = sha256;
		this->PaddedLength = paddedLength;
		this->PaddedMD5    = paddedMd5;
		this->PaddedSHA256 = paddedSha256;
	}
};

#endif