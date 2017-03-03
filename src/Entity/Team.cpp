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
#include "Team.h"

#include "Core/Module.h"

Team::Team( PVOID luaUserdata ) :
	Element( luaUserdata )
{
}

Team::Team( const string& teamName, const Color& color ) :
	Element( nullptr )
{
	this->LuaUserdata = Lua::Bindings::CreateTeam( LuaVM, teamName.c_str(), color.R, color.G, color.B );
}

Team::~Team()
{
}

string Team::GetName() const
{
	string value;

	Lua::Bindings::GetTeamName( LuaVM, LuaUserdata, value );

	return value;
}

Color Team::GetColor() const
{
	Color value;

	Lua::Bindings::GetTeamColor( LuaVM, LuaUserdata, value.R, value.G, value.B );

	return value;
}

uint Team::CountPlayers() const
{
	uint value;

	Lua::Bindings::CountPlayersInTeam( LuaVM, LuaUserdata, value );

	return value;
}

bool Team::GetFriendlyFire() const
{
	bool value;

	Lua::Bindings::GetTeamFriendlyFire( LuaVM, LuaUserdata, value );

	return value;
}

bool Team::SetName( const string& teamName )
{
	return Lua::Bindings::SetTeamName( LuaVM, LuaUserdata, teamName.c_str() );
}

bool Team::SetColor( const Color& color )
{
	return Lua::Bindings::SetTeamColor( LuaVM, LuaUserdata, color.R, color.B, color.G );
}

bool Team::SetFriendlyFire( bool friendlyFire )
{
	return Lua::Bindings::SetTeamFriendlyFire( LuaVM, LuaUserdata, friendlyFire );
}
