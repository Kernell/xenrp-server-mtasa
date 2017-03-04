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

#include "StdInc.h"
#include "Ban.h"

#include "Core/Module.h"

Ban::Ban( PVOID luaUserdata ) :
	Element( luaUserdata )
{
}

Ban::Ban( string IP, string username, string serial, Element* responsible, string reason, time_t unban ) :
	Element( nullptr )
{
	this->LuaUserdata = Lua::Bindings::AddBan( LuaVM, IP, username, serial, responsible, reason, unban );
}

Ban::~Ban()
{
}

bool Ban::Remove( Element* responsible )
{
	if( Lua::Bindings::RemoveBan( LuaVM, LuaUserdata, responsible ) )
	{
		delete this;

		return true;
	}

	return false;
}

string Ban::GetIP() const
{
	string value;

	Lua::Bindings::GetBanIP( LuaVM, LuaUserdata, value );

	return value;
}

string Ban::GetSerial() const
{
	string value;

	Lua::Bindings::GetBanSerial( LuaVM, LuaUserdata, value );

	return value;
}

string Ban::GetUsername() const
{
	string value;

	Lua::Bindings::GetBanUsername( LuaVM, LuaUserdata, value );

	return value;
}

string Ban::GetNick() const
{
	string value;

	Lua::Bindings::GetBanNick( LuaVM, LuaUserdata, value );

	return value;
}

string Ban::GetReason() const
{
	string value;

	Lua::Bindings::GetBanReason( LuaVM, LuaUserdata, value );

	return value;
}

string Ban::GetAdmin() const
{
	string value;

	Lua::Bindings::GetBanAdmin( LuaVM, LuaUserdata, value );

	return value;
}

time_t Ban::GetTime() const
{
	time_t value;

	Lua::Bindings::GetBanTime( LuaVM, LuaUserdata, value );

	return value;
}

time_t Ban::GetUnbanTime() const
{
	time_t value;

	Lua::Bindings::GetUnbanTime( LuaVM, LuaUserdata, value );

	return value;
}

bool Ban::SetUnbanTime( time_t time )
{
	return Lua::Bindings::SetUnbanTime( LuaVM, LuaUserdata, time );
}

bool Ban::SetReason( const string& reason )
{
	return Lua::Bindings::SetBanReason( LuaVM, LuaUserdata, reason );
}

bool Ban::SetAdmin( const string& adminName )
{
	return Lua::Bindings::SetBanAdmin( LuaVM, LuaUserdata, adminName );
}
