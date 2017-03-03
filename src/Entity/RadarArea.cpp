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
#include "RadarArea.h"

#include "Core/Module.h"

RadarArea::RadarArea( PVOID luaUserdata ) :
	Element( luaUserdata )
{
}

RadarArea::RadarArea( const Vector2& position, const Vector2& size, const Color& color, Element* visibleTo ) :
	Element( nullptr )
{
	this->LuaUserdata = Lua::Bindings::CreateRadarArea( LuaVM, position, size, color, visibleTo ? visibleTo->GetLuaUserdata() : nullptr );
}

RadarArea::~RadarArea()
{
}

Vector2 RadarArea::GetSize() const
{
	Vector2 value;

	Lua::Bindings::GetRadarAreaSize( LuaVM, LuaUserdata, value );

	return value;
}

Color RadarArea::GetColor() const
{
	Color value;

	Lua::Bindings::GetRadarAreaColor( LuaVM, LuaUserdata, value );

	return value;
}

bool RadarArea::IsFlashing() const
{
	return Lua::Bindings::IsRadarAreaFlashing( LuaVM, LuaUserdata );
}

bool RadarArea::IsInside( const Vector2& position ) const
{
	bool value;

	Lua::Bindings::IsInsideRadarArea( LuaVM, LuaUserdata, position, value );

	return value;
}

bool RadarArea::SetSize( const Vector2& vecSize )
{
	return Lua::Bindings::SetRadarAreaSize( LuaVM, LuaUserdata, vecSize );
}

bool RadarArea::SetColor( const Color& color )
{
	return Lua::Bindings::SetRadarAreaColor( LuaVM, LuaUserdata, color );
}

bool RadarArea::SetFlashing( bool flashing )
{
	return Lua::Bindings::SetRadarAreaFlashing( LuaVM, LuaUserdata, flashing );
}
