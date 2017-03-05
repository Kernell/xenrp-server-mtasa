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

class World;

#ifndef __WORLD_H
#define __WORLD_H

#include "Element.h"

using namespace Math;
using namespace SharedUtil;

class World
{
public:
	static bool          GetTime                         ( uchar& hour, uchar& minute );
	static bool          GetWeather                      ( uchar& weather, uchar& weatherBlendingTo );
	static string        GetZoneName                     ( const Vector3& position, bool citiesOnly = false );
	static float         GetGravity                      ();
	static float         GetGameSpeed                    ();
	static float         GetWaveHeight                   ();
	static ushort        GetFPSLimit                     ();
	static ulong         GetMinuteDuration               ();
	static bool          IsGarageOpen                    ( uchar garageID );
	static uchar         GetTrafficLightState            ();
	static bool          GetTrafficLightsLocked          ();
	static float         GetJetpackMaxHeight             ();
	static float         GetAircraftMaxVelocity          ();
	static bool          GetInteriorSoundsEnabled        ();
	static float         GetRainLevel                    ();
	static float         GetSunSize                      ();
	static bool          GetSunColor                     ( Color& core, Color& corona );
	static Vector3       GetWindVelocity                 ();
	static float         GetFarClipDistance              ();
	static float         GetFogDistance                  ();
	static float         GetAircraftMaxHeight            ();
	static bool          GetOcclusionsEnabled            ();
	static int           GetMoonSize                     ();

	static bool          SetTime                         ( uchar hour, uchar minute );
	static bool          SetWeather                      ( uchar weather );
	static bool          SetWeatherBlended               ( uchar weather );
	static bool          SetGravity                      ( float gravity );
	static bool          SetGameSpeed				     ( float speed );
	static bool          SetWaveHeight                   ( float height );
	static bool          GetSkyGradient                  ( Color& top, Color& bottom );
	static bool          SetSkyGradient                  ( const Color& top, const Color& bottom );
	static bool          ResetSkyGradient                ();
	static bool          GetHeatHaze                     ( HeatHazeSettings& heatHazeSettings );
	static bool          SetHeatHaze                     ( const HeatHazeSettings& heatHazeSettings );
	static bool          ResetHeatHaze                   ();
	static bool          SetFPSLimit                     ( ushort limit, bool save );
	static bool          SetMinuteDuration               ( ulong duration );
	static bool          SetGarageOpen                   ( uchar garageID, bool isOpen );
	static bool          SetGlitchEnabled                ( const string& glitchName, bool enabled );
	static bool          IsGlitchEnabled                 ( const string& glitchName );
	static bool          GetJetpackWeaponEnabled         ( WeaponType weaponType );
	static bool          SetJetpackWeaponEnabled         ( WeaponType weaponType, bool enabled );
	static bool          SetCloudsEnabled                ( bool enabled );
	static bool          GetCloudsEnabled                ();
	static bool          SetTrafficLightState            ( uchar state, bool forced = false );
	static bool          SetTrafficLightsLocked          ( bool locked );
	static bool          SetJetpackMaxHeight             ( float maxHeight );
	static bool          SetInteriorSoundsEnabled        ( bool enable );
	static bool          SetRainLevel                    ( float rainLevel );
	static bool          SetSunSize                      ( float sunSize );
	static bool          SetSunColor                     ( const Color& core, const Color& corona );
	static bool          SetWindVelocity                 ( const Vector3& velocity );
	static bool          SetFarClipDistance              ( float farClip );
	static bool          SetFogDistance                  ( float fogDist );
	static bool          SetAircraftMaxHeight            ( float maxHeight );
	static bool          SetAircraftMaxVelocity          ( float velocity );
	static bool          SetOcclusionsEnabled            ( bool enabled );
	static bool          ResetRainLevel                  ();
	static bool          ResetSunSize                    ();
	static bool          ResetSunColor                   ();
	static bool          ResetWindVelocity               ();
	static bool          ResetFarClipDistance            ();
	static bool          ResetFogDistance                ();
	static bool          RemoveWorldModel                ( ushort model, float radius, const Vector3& position, char interior );
	static bool          RestoreWorldModel               ( ushort model, float radius, const Vector3& position, char interior );
	static bool          RestoreAllWorldModels           ();
	static bool          SendSyncIntervals               ( Player* player = nullptr );
	static bool          SetPedTargetingMarkerEnabled    ( bool enabled );
	static bool          IsPedTargetingMarkerEnabled     ();
	static bool          SetMoonSize                     ( int moonSize );
	static bool          ResetMoonSize                   ();
};

#endif
