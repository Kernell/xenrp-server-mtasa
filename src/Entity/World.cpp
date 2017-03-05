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
#include "World.h"

#include "Core/Module.h"

extern Module* g_Module;

bool World::GetTime( uchar& hour, uchar& minute )
{
	return Lua::Bindings::GetTime( g_Module->GetLua(), hour, minute );
}

bool World::GetWeather( uchar& weather, uchar& weatherBlendingTo )
{
	return Lua::Bindings::GetWeather( g_Module->GetLua(), weather, weatherBlendingTo );
}

string World::GetZoneName( const Vector3& position, bool citiesOnly )
{
	string value;

	Lua::Bindings::GetZoneName( g_Module->GetLua(), position, value, citiesOnly );

	return value;
}

float World::GetGravity()
{
	float value;

	Lua::Bindings::GetGravity( g_Module->GetLua(), value );

	return value;
}

float World::GetGameSpeed()
{
	float value;

	Lua::Bindings::GetGameSpeed( g_Module->GetLua(), value );

	return value;
}

float World::GetWaveHeight()
{
	float value;

	Lua::Bindings::GetWaveHeight( g_Module->GetLua(), value );

	return value;
}

ushort World::GetFPSLimit()
{
	ushort value;

	Lua::Bindings::GetFPSLimit( g_Module->GetLua(), value );

	return value;
}

ulong World::GetMinuteDuration()
{
	ulong value;

	Lua::Bindings::GetMinuteDuration( g_Module->GetLua(), value );

	return value;
}

bool World::IsGarageOpen( uchar garageID )
{
	bool value;

	Lua::Bindings::IsGarageOpen( g_Module->GetLua(), garageID, value );

	return value;
}

uchar World::GetTrafficLightState()
{
	uchar value;

	Lua::Bindings::GetTrafficLightState( g_Module->GetLua(), value );

	return value;
}

bool World::GetTrafficLightsLocked()
{
	bool value;

	Lua::Bindings::GetTrafficLightsLocked( g_Module->GetLua(), value );

	return value;
}

float World::GetJetpackMaxHeight()
{
	float value;

	Lua::Bindings::GetJetpackMaxHeight( g_Module->GetLua(), value );

	return value;
}

float World::GetAircraftMaxVelocity()
{
	float value;

	Lua::Bindings::GetAircraftMaxVelocity( g_Module->GetLua(), value );

	return value;
}

bool World::GetInteriorSoundsEnabled()
{
	bool value;

	Lua::Bindings::GetInteriorSoundsEnabled( g_Module->GetLua(), value );

	return value;
}

float World::GetRainLevel()
{
	float value;

	Lua::Bindings::GetRainLevel( g_Module->GetLua(), value );

	return value;
}

float World::GetSunSize()
{
	float value;

	Lua::Bindings::GetSunSize( g_Module->GetLua(), value );

	return value;
}

bool World::GetSunColor( Color& core, Color& corona )
{
	return Lua::Bindings::GetSunColor( g_Module->GetLua(), core.R, core.G, core.B, corona.R, corona.G, corona.B );
}

Vector3 World::GetWindVelocity()
{
	Vector3 value;

	Lua::Bindings::GetWindVelocity( g_Module->GetLua(), value.X, value.Y, value.Z );

	return value;
}

float World::GetFarClipDistance()
{
	float value;

	Lua::Bindings::GetFarClipDistance( g_Module->GetLua(), value );

	return value;
}

float World::GetFogDistance()
{
	float value;

	Lua::Bindings::GetFogDistance( g_Module->GetLua(), value );

	return value;
}

float World::GetAircraftMaxHeight()
{
	float value;

	Lua::Bindings::GetAircraftMaxHeight( g_Module->GetLua(), value );

	return value;
}

bool World::GetOcclusionsEnabled()
{
	bool value;

	Lua::Bindings::GetOcclusionsEnabled( g_Module->GetLua(), value );

	return value;
}

int World::GetMoonSize()
{
	int value;

	Lua::Bindings::GetMoonSize( g_Module->GetLua(), value );

	return value;
}

bool World::SetTime( uchar hour, uchar minute )
{
	return Lua::Bindings::SetTime( g_Module->GetLua(), hour, minute );
}

bool World::SetWeather( uchar weather )
{
	return Lua::Bindings::SetWeather( g_Module->GetLua(), weather );
}

bool World::SetWeatherBlended( uchar weather )
{
	return Lua::Bindings::SetWeatherBlended( g_Module->GetLua(), weather );
}

bool World::SetGravity( float gravity )
{
	return Lua::Bindings::SetGravity( g_Module->GetLua(), gravity );
}

bool World::SetGameSpeed( float speed )
{
	return Lua::Bindings::SetGameSpeed( g_Module->GetLua(), speed );
}

bool World::SetWaveHeight( float height )
{
	return Lua::Bindings::SetWaveHeight( g_Module->GetLua(), height );
}

bool World::GetSkyGradient( Color& top, Color& bottom )
{
	return Lua::Bindings::GetSkyGradient( g_Module->GetLua(), top.R, top.G, top.B, bottom.R, bottom.G, bottom.B );
}

bool World::SetSkyGradient( const Color& top, const Color& bottom )
{
	return Lua::Bindings::SetSkyGradient( g_Module->GetLua(), top.R, top.G, top.B, bottom.R, bottom.G, bottom.B );
}

bool World::ResetSkyGradient()
{
	return Lua::Bindings::ResetSkyGradient( g_Module->GetLua() );
}

bool World::GetHeatHaze( HeatHazeSettings& heatHazeSettings )
{
	return Lua::Bindings::GetHeatHaze( g_Module->GetLua(), heatHazeSettings );
}

bool World::SetHeatHaze( const HeatHazeSettings& heatHazeSettings )
{
	return Lua::Bindings::SetHeatHaze( g_Module->GetLua(), heatHazeSettings );
}

bool World::ResetHeatHaze()
{
	return Lua::Bindings::ResetHeatHaze( g_Module->GetLua() );
}

bool World::SetFPSLimit( ushort limit, bool save )
{
	return Lua::Bindings::SetFPSLimit( g_Module->GetLua(), limit, save );
}

bool World::SetMinuteDuration( ulong duration )
{
	return Lua::Bindings::SetMinuteDuration( g_Module->GetLua(), duration );
}

bool World::SetGarageOpen( uchar garageID, bool isOpen )
{
	return Lua::Bindings::SetGarageOpen( g_Module->GetLua(), garageID, isOpen );
}

bool World::SetGlitchEnabled( const string& glitchName, bool enabled )
{
	return Lua::Bindings::SetGlitchEnabled( g_Module->GetLua(), glitchName, enabled );
}

bool World::IsGlitchEnabled( const string& glitchName )
{
	return Lua::Bindings::IsGlitchEnabled( g_Module->GetLua(), glitchName );
}

bool World::GetJetpackWeaponEnabled( WeaponType weaponType )
{
	return Lua::Bindings::GetJetpackWeaponEnabled( g_Module->GetLua(), weaponType );
}

bool World::SetJetpackWeaponEnabled( WeaponType weaponType, bool enabled )
{
	return Lua::Bindings::SetJetpackWeaponEnabled( g_Module->GetLua(), weaponType, enabled );
}

bool World::SetCloudsEnabled( bool enabled )
{
	return Lua::Bindings::SetCloudsEnabled( g_Module->GetLua(), enabled );
}

bool World::GetCloudsEnabled()
{
	return Lua::Bindings::GetCloudsEnabled( g_Module->GetLua() );
}

bool World::SetTrafficLightState( uchar state, bool forced )
{
	return Lua::Bindings::SetTrafficLightState( g_Module->GetLua(), state, forced );
}

bool World::SetTrafficLightsLocked( bool locked )
{
	return Lua::Bindings::SetTrafficLightsLocked( g_Module->GetLua(), locked );
}

bool World::SetJetpackMaxHeight( float maxHeight )
{
	return Lua::Bindings::SetJetpackMaxHeight( g_Module->GetLua(), maxHeight );
}

bool World::SetInteriorSoundsEnabled( bool enable )
{
	return Lua::Bindings::SetInteriorSoundsEnabled( g_Module->GetLua(), enable );
}

bool World::SetRainLevel( float rainLevel )
{
	return Lua::Bindings::SetRainLevel( g_Module->GetLua(), rainLevel );
}

bool World::SetSunSize( float sunSize )
{
	return Lua::Bindings::SetSunSize( g_Module->GetLua(), sunSize );
}

bool World::SetSunColor( const Color& core, const Color& corona )
{
	return Lua::Bindings::SetSunColor( g_Module->GetLua(), core.R, core.G, core.B, corona.R, corona.G, corona.B );
}

bool World::SetWindVelocity( const Vector3& velocity )
{
	return Lua::Bindings::SetWindVelocity( g_Module->GetLua(), velocity.X, velocity.Y, velocity.Z );
}

bool World::SetFarClipDistance( float farClip )
{
	return Lua::Bindings::SetFarClipDistance( g_Module->GetLua(), farClip );
}

bool World::SetFogDistance( float fogDist )
{
	return Lua::Bindings::SetFogDistance( g_Module->GetLua(), fogDist );
}

bool World::SetAircraftMaxHeight( float maxHeight )
{
	return Lua::Bindings::SetAircraftMaxHeight( g_Module->GetLua(), maxHeight );
}

bool World::SetAircraftMaxVelocity( float velocity )
{
	return Lua::Bindings::SetAircraftMaxVelocity( g_Module->GetLua(), velocity );
}

bool World::SetOcclusionsEnabled( bool enabled )
{
	return Lua::Bindings::SetOcclusionsEnabled( g_Module->GetLua(), enabled );
}

bool World::ResetRainLevel()
{
	return Lua::Bindings::ResetRainLevel( g_Module->GetLua() );
}

bool World::ResetSunSize()
{
	return Lua::Bindings::ResetSunSize( g_Module->GetLua() );
}

bool World::ResetSunColor()
{
	return Lua::Bindings::ResetSunColor( g_Module->GetLua() );
}

bool World::ResetWindVelocity()
{
	return Lua::Bindings::ResetWindVelocity( g_Module->GetLua() );
}

bool World::ResetFarClipDistance()
{
	return Lua::Bindings::ResetFarClipDistance( g_Module->GetLua() );
}

bool World::ResetFogDistance()
{
	return Lua::Bindings::ResetFogDistance( g_Module->GetLua() );
}

bool World::RemoveWorldModel( ushort model, float radius, const Vector3& position, char interior )
{
	return Lua::Bindings::RemoveWorldModel( g_Module->GetLua(), model, radius, position, interior );
}

bool World::RestoreWorldModel( ushort model, float radius, const Vector3& position, char interior )
{
	return Lua::Bindings::RestoreWorldModel( g_Module->GetLua(), model, radius, position, interior );
}

bool World::RestoreAllWorldModels()
{
	return Lua::Bindings::RestoreAllWorldModels( g_Module->GetLua() );
}

bool World::SendSyncIntervals( Player* player )
{
	return Lua::Bindings::SendSyncIntervals( g_Module->GetLua(), player );
}

bool World::SetPedTargetingMarkerEnabled( bool enabled )
{
	return Lua::Bindings::SetPedTargetingMarkerEnabled( g_Module->GetLua(), enabled );
}

bool World::IsPedTargetingMarkerEnabled()
{
	return Lua::Bindings::IsPedTargetingMarkerEnabled( g_Module->GetLua() );
}

bool World::SetMoonSize( int moonSize )
{
	return Lua::Bindings::SetMoonSize( g_Module->GetLua(), moonSize );
}

bool World::ResetMoonSize()
{
	return Lua::Bindings::ResetMoonSize( g_Module->GetLua() );
}
