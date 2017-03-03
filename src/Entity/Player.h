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
										Player                             ( PVOID luaUserdata );
	virtual                             ~Player                            ();

public:
	virtual uint                        GetPing                            () const;
	virtual long                        GetMoney                           () const;
	virtual bool                        IsMuted                            () const;
	virtual Team*                       GetTeam                            () const;
	virtual uint                        GetWantedLevel                     () const;
	virtual uint                        GetIdleTime                        () const;
	virtual bool					    IsMapForced                        () const;
	virtual string                      GetNametagText                     () const;
	virtual Color                       GetNametagColor                    () const;
	virtual bool                        IsNametagShowing                   () const;
	virtual string                      GetSerial                          () const;
	virtual string                      GetUserName                        () const;
	virtual uchar                       GetBlurLevel                       () const;
	virtual string                      GetName                            () const;
	virtual string                      GetIP                              () const;
	virtual Account*                    GetAccount                         () const;
	virtual string                      GetVersion                         () const;
	virtual ArgumentsMap		        GetACInfo				           () const;

	virtual bool                        SetMoney                           ( int amount, bool instant = false );
	virtual bool                        GiveMoney                          ( int amount );
	virtual bool                        TakeMoney                          ( int amount );
	virtual bool                        Spawn                              ( const Math::Vector3& position, int rotation = 0, int skinID = 0, int interior = 0, int dimension = 0, Team* team = nullptr );
	virtual bool                        ShowHudComponent                   ( const string& component, bool show );
	virtual bool                        SetWantedLevel                     ( int level );
	virtual bool                        ForceMap                           ( bool forceOn );
	virtual bool                        SetNametagText                     ( const string& text );
	virtual bool                        SetNametagColor                    ( const Color& color );
	virtual bool                        SetNametagShowing                  ( bool showing );
	virtual bool                        SetMuted                           ( bool muted );
	virtual bool                        SetBlurLevel                       ( int level );
	virtual bool                        Redirect                           ( const char* serverIP, int serverPort, const char* serverPassword );
	virtual bool                        SetName                            ( const string& name );
	virtual bool                        DetonateSatchels                   ();
	virtual bool                        TakeScreenShot                     ( int width, int height, const string& tag = "", int quality = 30, int maxBandwith = 5000 );
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