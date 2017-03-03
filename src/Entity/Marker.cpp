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
#include "Marker.h"

#include "Core/Module.h"

const string Marker::MARKER_TYPE_CHECKPOINT = "checkpoint";
const string Marker::MARKER_TYPE_RING       = "ring";
const string Marker::MARKER_TYPE_CYLINDER   = "cylinder";
const string Marker::MARKER_TYPE_ARROW      = "arrow";
const string Marker::MARKER_TYPE_CORONA     = "corona";

Marker::Marker( PVOID luaUserdata ) :
	Element( luaUserdata )
{
}

Marker::Marker( const Vector3& position, const string& type, float size, const Color& color, Element* visibleTo ) :
	Element( nullptr )
{
	this->LuaUserdata = Lua::Bindings::CreateMarker( LuaVM, position, type.c_str(), size, color, visibleTo ? visibleTo->GetLuaUserdata() : nullptr );
}

Marker::~Marker()
{
}

string Marker::GetType() const
{
	char* value = new char[ 32 ];

	Lua::Bindings::GetMarkerType( LuaVM, LuaUserdata, value );

	string str( value );

	delete [] value;

	return str;
}

float Marker::GetSize() const
{
	float value;

	Lua::Bindings::GetMarkerSize( LuaVM, LuaUserdata, value );

	return value;
}

Color Marker::GetColor() const
{
	Color value;

	Lua::Bindings::GetMarkerColor( LuaVM, LuaUserdata, value );

	return value;
}

Vector3 Marker::GetTarget() const
{
	Vector3 value;

	Lua::Bindings::GetMarkerTarget( LuaVM, LuaUserdata, value );

	return value;
}

string Marker::GetIcon() const
{
	char* value = new char[ 32 ];

	Lua::Bindings::GetMarkerIcon( LuaVM, LuaUserdata, value );

	string str( value );

	delete[] value;

	return str;
}

bool Marker::SetType( const string& type )
{
	return Lua::Bindings::SetMarkerType( LuaVM, LuaUserdata, type.c_str() );
}

bool Marker::SetSize( float size )
{
	return Lua::Bindings::SetMarkerSize( LuaVM, LuaUserdata, size );
}

bool Marker::SetColor( const Color& color )
{
	return Lua::Bindings::SetMarkerColor( LuaVM, LuaUserdata, color );
}

bool Marker::SetTarget( const Vector3& target )
{
	return Lua::Bindings::SetMarkerTarget( LuaVM, LuaUserdata, target );
}

bool Marker::SetIcon( const string& icon )
{
	return Lua::Bindings::SetMarkerIcon( LuaVM, LuaUserdata, icon.c_str() );
}
