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
#include "Blip.h"

#include "Core/Module.h"

Blip::Blip( PVOID luaUserdata ) :
	Element( luaUserdata )
{
}

Blip::Blip( const Vector3& position, BlipIcon icon, uchar size, Color color, short ordering, ushort visibleDistance, Element* visibleTo ) :
	Element( nullptr )
{
	this->LuaUserdata = Lua::Bindings::CreateBlip( LuaVM, position, icon, size, color, ordering, visibleDistance, visibleTo ? visibleTo->GetLuaUserdata() : nullptr );
}

Blip::Blip( Element* target, BlipIcon icon, uchar size, Color color, short ordering, ushort visibleDistance, Element* visibleTo ) :
	Element( nullptr )
{
	this->LuaUserdata = Lua::Bindings::CreateBlipAttachedTo( LuaVM, target->GetLuaUserdata(), icon, size, color, ordering, visibleDistance, visibleTo ? visibleTo->GetLuaUserdata() : nullptr );
}

Blip::~Blip()
{
}

BlipIcon Blip::GetIcon() const
{
	uchar value;

	Lua::Bindings::GetBlipIcon( LuaVM, LuaUserdata, value );

	return (BlipIcon)value;
}

uchar Blip::GetSize() const
{
	uchar value;

	Lua::Bindings::GetBlipSize( LuaVM, LuaUserdata, value );

	return value;
}

Color Blip::GetColor() const
{
	Color value;

	Lua::Bindings::GetBlipColor( LuaVM, LuaUserdata, value );

	return value;
}

short Blip::GetOrdering() const
{
	short value;

	Lua::Bindings::GetBlipOrdering( LuaVM, LuaUserdata, value );

	return value;
}

ushort Blip::GetVisibleDistance() const
{
	ushort value;

	Lua::Bindings::GetBlipVisibleDistance( LuaVM, LuaUserdata, value );

	return value;
}

bool Blip::SetIcon( BlipIcon icon )
{
	return Lua::Bindings::SetBlipIcon( LuaVM, LuaUserdata, (uchar)icon );
}

bool Blip::SetSize( uchar size )
{
	return Lua::Bindings::SetBlipSize( LuaVM, LuaUserdata, size );
}

bool Blip::SetColor( const Color& color )
{
	return Lua::Bindings::SetBlipColor( LuaVM, LuaUserdata, color );
}

bool Blip::SetOrdering( short ordering )
{
	return Lua::Bindings::SetBlipOrdering( LuaVM, LuaUserdata, ordering );
}

bool Blip::SetVisibleDistance( ushort visibleDistance )
{
	return Lua::Bindings::SetBlipVisibleDistance( LuaVM, LuaUserdata, visibleDistance );
}
