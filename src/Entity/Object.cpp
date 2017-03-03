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
#include "Object.h"

#include "Core/Module.h"

Object::Object( PVOID luaUserdata ) :
	Element( luaUserdata )
{
}

Object::Object( ushort modelID, const Vector3& position, const Vector3& rotation, bool isLowLod ) :
	Element( nullptr )
{
	this->LuaUserdata = Lua::Bindings::CreateObject( LuaVM, modelID, position, rotation, isLowLod );
}

Object::~Object()
{
}

Vector3 Object::GetScale()
{
	Vector3 value;

	Lua::Bindings::GetObjectScale( LuaVM, LuaUserdata, value );

	return value;
}

bool Object::SetScale( const Vector3& scale )
{
	return Lua::Bindings::SetObjectScale( LuaVM, LuaUserdata, scale );
}

bool Object::Move( ulong time, const Vector3& position, const Vector3& rotation, const string& easingType, float easingPeriod, float easingAmplitude, float easingOvershoot )
{
	return Lua::Bindings::MoveObject( LuaVM, LuaUserdata, time, position, rotation, easingType.c_str(), easingPeriod, easingAmplitude, easingOvershoot );
}

bool Object::Stop()
{
	return Lua::Bindings::StopObject( LuaVM, LuaUserdata );
}
