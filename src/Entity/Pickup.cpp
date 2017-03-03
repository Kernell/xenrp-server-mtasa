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
#include "Pickup.h"

#include "Core/Module.h"

Pickup::Pickup( PVOID luaUserdata ) :
	Element( luaUserdata )
{
}

Pickup::Pickup( const Vector3& position, PickupType type, double amount_weapon_model, ulong respawnInterval, double ammo ) :
	Element( nullptr )
{
	this->LuaUserdata = Lua::Bindings::CreatePickup( LuaVM, position, type, amount_weapon_model, respawnInterval, ammo );
}

Pickup::~Pickup()
{
}

PickupType Pickup::GetType() const
{
	uchar value;

	Lua::Bindings::GetPickupType( LuaVM, LuaUserdata, value );

	return (PickupType)value;
}

uchar Pickup::GetWeapon() const
{
	uchar value;

	Lua::Bindings::GetPickupWeapon( LuaVM, LuaUserdata, value );

	return value;
}

float Pickup::GetAmount() const
{
	float value;

	Lua::Bindings::GetPickupAmount( LuaVM, LuaUserdata, value );

	return value;
}

ushort Pickup::GetAmmo() const
{
	ushort value;

	Lua::Bindings::GetPickupAmmo( LuaVM, LuaUserdata, value );

	return value;
}

ulong Pickup::GetRespawnInterval() const
{
	ulong value;

	Lua::Bindings::GetPickupRespawnInterval( LuaVM, LuaUserdata, value );

	return value;
}

bool Pickup::IsSpawned() const
{
	bool value;

	Lua::Bindings::IsPickupSpawned( LuaVM, LuaUserdata, value );

	return value;
}

bool Pickup::SetType( PickupType type, double amount_weapon_model, double ammo )
{
	return Lua::Bindings::SetPickupType( LuaVM, LuaUserdata, type, amount_weapon_model, ammo );
}

bool Pickup::SetRespawnInterval( ulong interval )
{
	return Lua::Bindings::SetPickupRespawnInterval( LuaVM, LuaUserdata, interval );
}

bool Pickup::Use( Player* player )
{
	return Lua::Bindings::UsePickup( LuaVM, LuaUserdata, player );
}
