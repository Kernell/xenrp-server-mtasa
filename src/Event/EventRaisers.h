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

#ifndef __EVENTRAISERS_H
#define __EVENTRAISERS_H

#include "Lua/LuaArgument.h"
#include "Lua/LuaArguments.h"

#include "Entity/Element.h"

class EventRaisers
{
private:
	static int ReadArgument( list< LuaArgument* >::value_type iter, bool* arg );
	static int ReadArgument( list< LuaArgument* >::value_type iter, double* arg );
	static int ReadArgument( list< LuaArgument* >::value_type iter, float* arg );
	static int ReadArgument( list< LuaArgument* >::value_type iter, int* arg );
	static int ReadArgument( list< LuaArgument* >::value_type iter, Math::Vector2* arg );
	static int ReadArgument( list< LuaArgument* >::value_type iter, Math::Vector3* arg );
	static int ReadArgument( list< LuaArgument* >::value_type iter, string* arg );
	static int ReadArgument( list< LuaArgument* >::value_type iter, Element* arg );
	static int ReadArgument( list< LuaArgument* >::value_type iter, LuaArgument* arg );

	template< class ... Args >
	static void ReadArguments( list< LuaArgument* > arguments, Args ... args )
	{
		list< LuaArgument* >::value_type iter = *arguments.begin();

		int tmp[] = { ReadArgument( iter, args ) ... };
	}

public:
	// Client events

	static void OnConsole( Element* source, Element* _this, list< LuaArgument* > arguments );

	// Colshape events

	static void OnColShapeHit( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnColShapeLeave( Element* source, Element* _this, list< LuaArgument* > arguments );

	// Element events

	static void OnElementDestroy( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnElementDataChange( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnElementColShapeHit( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnElementColShapeLeave( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnElementClicked( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnElementStartSync( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnElementStopSync( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnElementModelChange( Element* source, Element* _this, list< LuaArgument* > arguments );

	// Marker events

	static void OnMarkerHit( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnMarkerLeave( Element* source, Element* _this, list< LuaArgument* > arguments );

	// Pickup events

	static void OnPickupSpawn( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPickupHit( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPickupUse( Element* source, Element* _this, list< LuaArgument* > arguments );

	// Player events

	static void OnPlayerBan( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerChat( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerPrivateMessage( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerConnect( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerChangeNick( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerLogin( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerLogout( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerDamage( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerJoin( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerQuit( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerSpawn( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerWasted( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerTarget( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerVehicleEnter( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerVehicleExit( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerWeaponSwitch( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerMarkerHit( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerMarkerLeave( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerPickupHit( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerPickupUse( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerClick( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerContact( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerStealthKill( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerMute( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerUnmute( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerCommand( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerModInfo( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerVoiceStart( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerVoiceStop( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPlayerScreenShot( Element* source, Element* _this, list< LuaArgument* > arguments );

	// Ped events

	static void OnPedWasted( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnPedWeaponSwitch( Element* source, Element* _this, list< LuaArgument* > arguments );

	// Resource events

	static void OnResourceStart( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnResourcePreStart( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnResourceStop( Element* source, Element* _this, list< LuaArgument* > arguments );

	// Server events

	static void OnBan( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnDebugMessage( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnSettingChange( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnAccountDataChange( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnUnban( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnChatMessage( Element* source, Element* _this, list< LuaArgument* > arguments );

	// Vehicle events

	static void OnTrailerAttach( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnTrailerDetach( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnVehicleDamage( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnVehicleRespawn( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnVehicleStartEnter( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnVehicleStartExit( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnVehicleEnter( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnVehicleExit( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnVehicleExplode( Element* source, Element* _this, list< LuaArgument* > arguments );
	static void OnWeaponFire( Element* source, Element* _this, list< LuaArgument* > arguments );
};

#endif
