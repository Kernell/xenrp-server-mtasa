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
#include "Ped.h"

#include "Core/Module.h"

Ped::Ped( PVOID luaUserdata ) :
	Element( luaUserdata )
{
}

Ped::Ped( int modelid, const Math::Vector3& position, float rot, bool synced ) :
	Element( nullptr )
{
	this->LuaUserdata = Lua::Bindings::CreatePed( LuaVM, modelid, position, rot, synced );
}

Ped::~Ped()
{
}

float Ped::GetArmor() const
{
	float value;

	Lua::Bindings::GetPedArmor( LuaVM, LuaUserdata, value );

	return value;
}

bool Ped::IsChoking() const
{
	bool value;

	Lua::Bindings::IsPedChoking( LuaVM, LuaUserdata, value );

	return value;
}

bool Ped::IsDead() const
{
	bool value;

	Lua::Bindings::IsPedDead( LuaVM, LuaUserdata, value );

	return value;
}

bool Ped::IsDucked() const
{
	bool value;

	Lua::Bindings::IsPedDucked( LuaVM, LuaUserdata, value );

	return value;
}

float Ped::GetStat( ushort usStat ) const
{
	float value;

	Lua::Bindings::GetPedStat( LuaVM, LuaUserdata, usStat, value );

	return value;
}

Element* Ped::GetTarget() const
{
	return this->ElementManager->FindOrCreate( Lua::Bindings::GetPedTarget( LuaVM, LuaUserdata ) );
}

int Ped::GetWeapon( int weaponSlot ) const
{
	return Lua::Bindings::GetPedWeapon( LuaVM, LuaUserdata, weaponSlot );
}

bool Ped::GetClothes( uchar type, string& outTexture, string& outModel ) const
{
	return Lua::Bindings::GetPedClothes( LuaVM, LuaUserdata, type, outTexture, outModel );
}

bool Ped::DoesHaveJetPack() const
{
	bool value;

	Lua::Bindings::DoesPedHaveJetPack( LuaVM, LuaUserdata, value );

	return value;
}

bool Ped::IsOnGround() const
{
	bool value;

	Lua::Bindings::IsPedOnGround( LuaVM, LuaUserdata, value );

	return value;
}

uchar Ped::GetFightingStyle() const
{
	uchar value;

	Lua::Bindings::GetPedFightingStyle( LuaVM, LuaUserdata, value );

	return value;
}

uint Ped::GetMoveAnim() const
{
	uint value;

	Lua::Bindings::GetPedMoveAnim( LuaVM, LuaUserdata, value );

	return value;
}

float Ped::GetGravity() const
{
	float value;

	Lua::Bindings::GetPedGravity( LuaVM, LuaUserdata, value );

	return value;
}

Element* Ped::GetContactElement() const
{
	return this->ElementManager->FindOrCreate( Lua::Bindings::GetPedContactElement( LuaVM, LuaUserdata ) );
}

uchar Ped::GetWeaponSlot() const
{
	uchar value;

	Lua::Bindings::GetPedWeaponSlot( LuaVM, LuaUserdata, value );

	return value;
}

bool Ped::IsDoingGangDriveby() const
{
	bool value;

	Lua::Bindings::IsPedDoingGangDriveby( LuaVM, LuaUserdata, value );

	return value;
}

bool Ped::IsOnFire() const
{
	bool value;

	Lua::Bindings::IsPedOnFire( LuaVM, LuaUserdata, value );

	return value;
}

bool Ped::IsHeadless() const
{
	bool value;

	Lua::Bindings::IsPedHeadless( LuaVM, LuaUserdata, value );

	return value;
}

bool Ped::IsFrozen() const
{
	bool value;

	Lua::Bindings::IsPedFrozen( LuaVM, LuaUserdata, value );

	return value;
}

Vehicle* Ped::GetOccupiedVehicle() const
{
	return this->ElementManager->FindOrCreate< Vehicle* >( Lua::Bindings::GetPedOccupiedVehicle( LuaVM, LuaUserdata ) );
}

uint Ped::GetOccupiedVehicleSeat() const
{
	uint value;

	Lua::Bindings::GetPedOccupiedVehicleSeat( LuaVM, LuaUserdata, value );

	return value;
}

bool Ped::IsInVehicle() const
{
	bool value;

	Lua::Bindings::IsPedInVehicle( LuaVM, LuaUserdata, value );

	return value;
}

bool Ped::SetArmor( float armor )
{
	return Lua::Bindings::SetPedArmor( LuaVM, LuaUserdata, armor );
}

bool Ped::Kill( Ped* killer, uchar killerWeapon, uchar bodyPart, bool stealth )
{
	return Lua::Bindings::KillPed( LuaVM, LuaUserdata, killer->GetLuaUserdata(), killerWeapon, bodyPart, stealth );
}

bool Ped::SetStat( ushort stat, float value )
{
	return Lua::Bindings::SetPedStat( LuaVM, LuaUserdata, stat, value );
}

bool Ped::AddClothes( const string& texture, const string& model, uchar type )
{
	return Lua::Bindings::AddPedClothes( LuaVM, LuaUserdata, texture.c_str(), model.c_str(), type );
}

bool Ped::RemoveClothes( uchar type, const char* texture, const char* model )
{
	return Lua::Bindings::RemovePedClothes( LuaVM, LuaUserdata, type, texture, model );
}

bool Ped::GiveJetPack()
{
	return Lua::Bindings::GivePedJetPack( LuaVM, LuaUserdata );
}

bool Ped::RemoveJetPack()
{
	return Lua::Bindings::RemovePedJetPack( LuaVM, LuaUserdata );
}

bool Ped::SetFightingStyle( uchar style )
{
	return Lua::Bindings::SetPedFightingStyle( LuaVM, LuaUserdata, style );
}

bool Ped::SetMoveAnim( uint moveAnim )
{
	return Lua::Bindings::SetPedMoveAnim( LuaVM, LuaUserdata, moveAnim );
}

bool Ped::SetGravity( float gravity )
{
	return Lua::Bindings::SetPedGravity( LuaVM, LuaUserdata, gravity );
}

bool Ped::SetChoking( bool choking )
{
	return Lua::Bindings::SetPedChoking( LuaVM, LuaUserdata, choking );
}

bool Ped::SetWeaponSlot( uchar weaponSlot )
{
	return Lua::Bindings::SetPedWeaponSlot( LuaVM, LuaUserdata, weaponSlot );
}

bool Ped::WarpIntoVehicle( Vehicle* vehicle, uint seat )
{
	return Lua::Bindings::WarpPedIntoVehicle( LuaVM, LuaUserdata, vehicle->GetLuaUserdata(), seat );
}

bool Ped::RemoveFromVehicle()
{
	return Lua::Bindings::RemovePedFromVehicle( LuaVM, LuaUserdata );
}

bool Ped::SetDoingGangDriveby( bool gangDriveby )
{
	return Lua::Bindings::SetPedDoingGangDriveby( LuaVM, LuaUserdata, gangDriveby );
}

bool Ped::SetAnimation( const string& blockName, const string& animName, int time, bool loop, bool updatePosition, bool interruptable, bool freezeLastFrame )
{
	return Lua::Bindings::SetPedAnimation( LuaVM, LuaUserdata, blockName.c_str(), animName.c_str(), time, loop, updatePosition, interruptable, freezeLastFrame );
}

bool Ped::SetAnimationProgress( const string& animName, float progress )
{
	return Lua::Bindings::SetPedAnimationProgress( LuaVM, LuaUserdata, animName.c_str(), progress );
}

bool Ped::SetOnFire( bool isOnFire )
{
	return Lua::Bindings::SetPedOnFire( LuaVM, LuaUserdata, isOnFire );
}

bool Ped::SetHeadless( bool isHeadless )
{
	return Lua::Bindings::SetPedHeadless( LuaVM, LuaUserdata, isHeadless );
}

bool Ped::SetFrozen( bool isFrozen )
{
	return Lua::Bindings::SetPedFrozen( LuaVM, LuaUserdata, isFrozen );
}

bool Ped::ReloadWeapon()
{
	return Lua::Bindings::ReloadPedWeapon( LuaVM, LuaUserdata );
}
