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
#include "Player.h"

#include "Core/Module.h"

Player::Player( PVOID luaUserdata ) :
	Ped( luaUserdata )
{
}

Player::~Player()
{
}

uint Player::GetPing() const
{
	uint value;

	Lua::Bindings::GetPlayerPing( LuaVM, LuaUserdata, value );

	return value;
}

long Player::GetMoney() const
{
	long value;

	Lua::Bindings::GetPlayerMoney( LuaVM, LuaUserdata, value );

	return value;
}

bool Player::IsMuted() const
{
	bool value;

	Lua::Bindings::IsPlayerMuted( LuaVM, LuaUserdata, value );

	return value;
}

Team* Player::GetTeam() const
{
	return dynamic_cast< Team* >( this->ElementManager->FindOrCreate( Lua::Bindings::GetPlayerTeam( LuaVM, LuaUserdata ) ) );
}

uint Player::GetWantedLevel() const
{
	uint value;

	Lua::Bindings::GetPlayerWantedLevel( LuaVM, LuaUserdata, value );

	return value;
}

uint Player::GetIdleTime() const
{
	uint value;

	Lua::Bindings::GetPlayerIdleTime( LuaVM, LuaUserdata, value );

	return value;
}

bool Player::IsMapForced() const
{
	bool value;

	Lua::Bindings::IsPlayerMapForced( LuaVM, LuaUserdata, value );

	return value;
}

string Player::GetNametagText() const
{
	string value;

	Lua::Bindings::GetPlayerNametagText( LuaVM, LuaUserdata, value );

	return value;
}

Color Player::GetNametagColor() const
{
	Color color;

	Lua::Bindings::GetPlayerNametagColor( LuaVM, LuaUserdata, color.R, color.G, color.B );

	return color;
}

bool Player::IsNametagShowing() const
{
	bool value;

	Lua::Bindings::IsPlayerNametagShowing( LuaVM, LuaUserdata, value );

	return value;
}

string Player::GetSerial() const
{
	return Lua::Bindings::GetPlayerSerial( LuaVM, LuaUserdata );
}

string Player::GetUserName() const
{
	return Lua::Bindings::GetPlayerUserName( LuaVM, LuaUserdata );
}

uchar Player::GetBlurLevel() const
{
	uchar value;

	Lua::Bindings::GetPlayerBlurLevel( LuaVM, LuaUserdata, value );

	return value;
}

string Player::GetName() const
{
	string value;

	Lua::Bindings::GetPlayerName( LuaVM, LuaUserdata, value );

	return value;
}

string Player::GetIP() const
{
	string value;

	Lua::Bindings::GetPlayerIP( LuaVM, LuaUserdata, value );

	return value;
}

Account* Player::GetAccount() const
{
	return dynamic_cast< Account* >( this->ElementManager->FindOrCreate( Lua::Bindings::GetPlayerAccount( LuaVM, LuaUserdata ) ) );
}

string Player::GetVersion() const
{
	return Lua::Bindings::GetPlayerVersion( LuaVM, LuaUserdata );
}

ArgumentsMap Player::GetACInfo() const
{
	return Lua::Bindings::GetPlayerACInfo( LuaVM, LuaUserdata );
}

bool Player::SetMoney( int amount, bool instant )
{
	return Lua::Bindings::SetPlayerMoney( LuaVM, LuaUserdata, amount, instant );
}

bool Player::GiveMoney( int amount )
{
	return Lua::Bindings::GivePlayerMoney( LuaVM, LuaUserdata, amount );
}

bool Player::TakeMoney( int amount )
{
	return Lua::Bindings::TakePlayerMoney( LuaVM, LuaUserdata, amount );
}

bool Player::Spawn( const Math::Vector3& position, int rotation, int skinID, int interior, int dimension, Team* team )
{
	return Lua::Bindings::SpawnPlayer( LuaVM, LuaUserdata, position, rotation, skinID, interior, dimension, team );
}

bool Player::ShowHudComponent( const string& component, bool show )
{
	return Lua::Bindings::ShowPlayerHudComponent( LuaVM, LuaUserdata, component, show );
}

bool Player::SetWantedLevel( int level )
{
	return Lua::Bindings::SetPlayerWantedLevel( LuaVM, LuaUserdata, level );
}

bool Player::ForceMap( bool forceOn )
{
	return Lua::Bindings::ForcePlayerMap( LuaVM, LuaUserdata, forceOn );
}

bool Player::SetNametagText( const string& text )
{
	return Lua::Bindings::SetPlayerNametagText( LuaVM, LuaUserdata, text );
}

bool Player::SetNametagColor( const Color& color )
{
	return Lua::Bindings::SetPlayerNametagColor( LuaVM, LuaUserdata, color.R, color.G, color.B );
}

bool Player::SetNametagShowing( bool showing )
{
	return Lua::Bindings::SetPlayerNametagShowing( LuaVM, LuaUserdata, showing );
}

bool Player::SetMuted( bool muted )
{
	return Lua::Bindings::SetPlayerMuted( LuaVM, LuaUserdata, muted );
}

bool Player::SetBlurLevel( int level )
{
	return Lua::Bindings::SetPlayerBlurLevel( LuaVM, LuaUserdata, level );
}

bool Player::Redirect( const char* serverIP, int serverPort, const char* serverPassword )
{
	return Lua::Bindings::RedirectPlayer( LuaVM, LuaUserdata, serverIP, serverPort, serverPassword );
}

bool Player::SetName( const string& name )
{
	return Lua::Bindings::SetPlayerName( LuaVM, LuaUserdata, name );
}

bool Player::DetonateSatchels()
{
	return Lua::Bindings::DetonateSatchels( LuaVM, LuaUserdata );
}

bool Player::TakeScreenShot( int width, int height, const string& tag, int quality, int maxBandwith )
{
	return Lua::Bindings::TakePlayerScreenShot( LuaVM, LuaUserdata, width, height, tag, quality, maxBandwith );
}
