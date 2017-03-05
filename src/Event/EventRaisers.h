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

#define EVENT_RAISER(x)\
	static void x( Element* source, Element* _this, vector< LuaArgument* > arguments )

class EventRaisers
{
public:
	// Client events

	EVENT_RAISER( OnConsole );

	// Colshape events

	EVENT_RAISER( OnColShapeHit );
	EVENT_RAISER( OnColShapeLeave );

	// Element events

	EVENT_RAISER( OnElementDestroy );
	EVENT_RAISER( OnElementDataChange );
	EVENT_RAISER( OnElementColShapeHit );
	EVENT_RAISER( OnElementColShapeLeave );
	EVENT_RAISER( OnElementClicked );
	EVENT_RAISER( OnElementStartSync );
	EVENT_RAISER( OnElementStopSync );
	EVENT_RAISER( OnElementModelChange );

	// Marker events

	EVENT_RAISER( OnMarkerHit );
	EVENT_RAISER( OnMarkerLeave );

	// Pickup events

	EVENT_RAISER( OnPickupSpawn );
	EVENT_RAISER( OnPickupHit );
	EVENT_RAISER( OnPickupUse );

	// Player events

	EVENT_RAISER( OnPlayerBan );
	EVENT_RAISER( OnPlayerChat );
	EVENT_RAISER( OnPlayerPrivateMessage );
	EVENT_RAISER( OnPlayerConnect );
	EVENT_RAISER( OnPlayerChangeNick );
	EVENT_RAISER( OnPlayerLogin );
	EVENT_RAISER( OnPlayerLogout );
	EVENT_RAISER( OnPlayerDamage );
	EVENT_RAISER( OnPlayerJoin );
	EVENT_RAISER( OnPlayerQuit );
	EVENT_RAISER( OnPlayerSpawn );
	EVENT_RAISER( OnPlayerWasted );
	EVENT_RAISER( OnPlayerTarget );
	EVENT_RAISER( OnPlayerVehicleEnter );
	EVENT_RAISER( OnPlayerVehicleExit );
	EVENT_RAISER( OnPlayerWeaponSwitch );
	EVENT_RAISER( OnPlayerMarkerHit );
	EVENT_RAISER( OnPlayerMarkerLeave );
	EVENT_RAISER( OnPlayerPickupHit );
	EVENT_RAISER( OnPlayerPickupUse );
	EVENT_RAISER( OnPlayerClick );
	EVENT_RAISER( OnPlayerContact );
	EVENT_RAISER( OnPlayerStealthKill );
	EVENT_RAISER( OnPlayerMute );
	EVENT_RAISER( OnPlayerUnmute );
	EVENT_RAISER( OnPlayerCommand );
	EVENT_RAISER( OnPlayerModInfo );
	EVENT_RAISER( OnPlayerVoiceStart );
	EVENT_RAISER( OnPlayerVoiceStop );
	EVENT_RAISER( OnPlayerScreenShot );

	// Ped events

	EVENT_RAISER( OnPedWasted );
	EVENT_RAISER( OnPedWeaponSwitch );

	// Resource events

	EVENT_RAISER( OnResourceStart );
	EVENT_RAISER( OnResourcePreStart );
	EVENT_RAISER( OnResourceStop );

	// Server events

	EVENT_RAISER( OnBan );
	EVENT_RAISER( OnDebugMessage );
	EVENT_RAISER( OnSettingChange );
	EVENT_RAISER( OnAccountDataChange );
	EVENT_RAISER( OnUnban );
	EVENT_RAISER( OnChatMessage );

	// Vehicle events

	EVENT_RAISER( OnTrailerAttach );
	EVENT_RAISER( OnTrailerDetach );
	EVENT_RAISER( OnVehicleDamage );
	EVENT_RAISER( OnVehicleRespawn );
	EVENT_RAISER( OnVehicleStartEnter );
	EVENT_RAISER( OnVehicleStartExit );
	EVENT_RAISER( OnVehicleEnter );
	EVENT_RAISER( OnVehicleExit );
	EVENT_RAISER( OnVehicleExplode );
	EVENT_RAISER( OnWeaponFire );
};

#endif
