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

class Ban;

#ifndef __BAN_H
#define __BAN_H

#include "Element.h"

class Ban : public Element
{
public:
									Ban                     ( PVOID luaUserdata );
	                                Ban                     ( string IP, string username, string serial, Element* responsible = nullptr, string reason = "", time_t unban = 0 );
	virtual                         ~Ban                    ();

	virtual bool					Remove                  ( Element* responsible = nullptr );

///	static  vector< Ban* >          GetBans                 ( lua_State* pLuaVM );
///	static  bool                    ReloadBanList           ( lua_State* pLuaVM );

	virtual string                  GetIP                   () const;
	virtual string                  GetSerial               () const;
	virtual string                  GetUsername             () const;
	virtual string                  GetNick                 () const;
	virtual string                  GetReason               () const;
	virtual string                  GetAdmin                () const;

	virtual time_t                  GetTime                 () const;
	virtual time_t                  GetUnbanTime            () const;

	virtual bool                    SetUnbanTime            ( time_t time );
	virtual bool                    SetReason               ( const string& reason );
	virtual bool                    SetAdmin                ( const string& adminName );
};

#endif