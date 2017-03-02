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
#include "EventManager.h"
#include "ElementManager.h"

EventManager::EventManager( ::Module* module )
{
	this->Module = module;

	this->Connect( "onConsole",              "resourceRoot", EventRaisers::OnConsole );
					
	this->Connect( "onColShapeHit",          "resourceRoot", EventRaisers::OnColShapeHit );
	this->Connect( "onColShapeLeave",        "resourceRoot", EventRaisers::OnColShapeLeave );
					
	this->Connect( "onElementDestroy",       "resourceRoot", EventRaisers::OnElementDestroy );
	this->Connect( "onElementDataChange",    "resourceRoot", EventRaisers::OnElementDataChange );
	this->Connect( "onElementColShapeHit",   "resourceRoot", EventRaisers::OnElementColShapeHit );
	this->Connect( "onElementColShapeLeave", "resourceRoot", EventRaisers::OnElementColShapeLeave );
	this->Connect( "onElementClicked",       "resourceRoot", EventRaisers::OnElementClicked );
	this->Connect( "onElementStartSync",     "resourceRoot", EventRaisers::OnElementStartSync );
	this->Connect( "onElementStopSync",      "resourceRoot", EventRaisers::OnElementStopSync );
	this->Connect( "onElementModelChange",   "resourceRoot", EventRaisers::OnElementModelChange );
					
	this->Connect( "onMarkerHit",            "resourceRoot", EventRaisers::OnMarkerHit );
	this->Connect( "onMarkerLeave",          "resourceRoot", EventRaisers::OnMarkerLeave );
					
	this->Connect( "onPickupSpawn",          "resourceRoot", EventRaisers::OnPickupSpawn );
	this->Connect( "onPickupHit",            "resourceRoot", EventRaisers::OnPickupHit );
	this->Connect( "onPickupUse",            "resourceRoot", EventRaisers::OnPickupUse );
					
	this->Connect( "onPlayerBan",            "root",         EventRaisers::OnPlayerBan );
	this->Connect( "onPlayerChat",           "root",         EventRaisers::OnPlayerChat );
	this->Connect( "onPlayerPrivateMessage", "root",         EventRaisers::OnPlayerPrivateMessage );
	this->Connect( "onPlayerConnect",        "root",         EventRaisers::OnPlayerConnect );
	this->Connect( "onPlayerChangeNick",     "root",         EventRaisers::OnPlayerChangeNick );
	this->Connect( "onPlayerLogin",          "root",         EventRaisers::OnPlayerLogin );
	this->Connect( "onPlayerLogout",         "root",         EventRaisers::OnPlayerLogout );
	this->Connect( "onPlayerDamage",         "root",         EventRaisers::OnPlayerDamage );
	this->Connect( "onPlayerJoin",           "root",         EventRaisers::OnPlayerJoin );
	this->Connect( "onPlayerQuit",           "root",         EventRaisers::OnPlayerQuit );
	this->Connect( "onPlayerSpawn",          "root",         EventRaisers::OnPlayerSpawn );
	this->Connect( "onPlayerWasted",         "root",         EventRaisers::OnPlayerWasted );
	this->Connect( "onPlayerTarget",         "root",         EventRaisers::OnPlayerTarget );
	this->Connect( "onPlayerVehicleEnter",   "root",         EventRaisers::OnPlayerVehicleEnter );
	this->Connect( "onPlayerVehicleExit",    "root",         EventRaisers::OnPlayerVehicleExit );
	this->Connect( "onPlayerWeaponSwitch",   "root",         EventRaisers::OnPlayerWeaponSwitch );
	this->Connect( "onPlayerMarkerHit",      "root",         EventRaisers::OnPlayerMarkerHit );
	this->Connect( "onPlayerMarkerLeave",    "root",         EventRaisers::OnPlayerMarkerLeave );
	this->Connect( "onPlayerPickupHit",      "root",         EventRaisers::OnPlayerPickupHit );
	this->Connect( "onPlayerPickupUse",      "root",         EventRaisers::OnPlayerPickupUse );
	this->Connect( "onPlayerClick",          "root",         EventRaisers::OnPlayerClick );
	this->Connect( "onPlayerContact",        "root",         EventRaisers::OnPlayerContact );
	this->Connect( "onPlayerStealthKill",    "root",         EventRaisers::OnPlayerStealthKill );
	this->Connect( "onPlayerMute",           "root",         EventRaisers::OnPlayerMute );
	this->Connect( "onPlayerUnmute",         "root",         EventRaisers::OnPlayerUnmute );
	this->Connect( "onPlayerCommand",        "root",         EventRaisers::OnPlayerCommand );
	this->Connect( "onPlayerModInfo",        "root",         EventRaisers::OnPlayerModInfo );
	this->Connect( "onPlayerVoiceStart",     "root",         EventRaisers::OnPlayerVoiceStart );
	this->Connect( "onPlayerVoiceStop",      "root",         EventRaisers::OnPlayerVoiceStop );
	this->Connect( "onPlayerScreenShot",     "root",         EventRaisers::OnPlayerScreenShot );
										     
	this->Connect( "onPedWasted",            "resourceRoot", EventRaisers::OnPedWasted );
	this->Connect( "onPedWeaponSwitch",      "resourceRoot", EventRaisers::OnPedWeaponSwitch );
										     
	this->Connect( "onResourceStart",        "resourceRoot", EventRaisers::OnResourceStart );
	this->Connect( "onResourcePreStart",     "resourceRoot", EventRaisers::OnResourcePreStart );
	this->Connect( "onResourceStop",         "resourceRoot", EventRaisers::OnResourceStop );
										     
	this->Connect( "onBan",                  "root",         EventRaisers::OnBan );
	this->Connect( "onDebugMessage",         "root",         EventRaisers::OnDebugMessage );
	this->Connect( "onSettingChange",        "root",         EventRaisers::OnSettingChange );
	this->Connect( "onAccountDataChange",    "root",         EventRaisers::OnAccountDataChange );
	this->Connect( "onUnban",                "root",         EventRaisers::OnUnban );
	this->Connect( "onChatMessage",          "root",         EventRaisers::OnChatMessage );
										     
	this->Connect( "onTrailerAttach",        "resourceRoot", EventRaisers::OnTrailerAttach );
	this->Connect( "onTrailerDetach",        "resourceRoot", EventRaisers::OnTrailerDetach );
	this->Connect( "onVehicleDamage",        "resourceRoot", EventRaisers::OnVehicleDamage );
	this->Connect( "onVehicleRespawn",       "resourceRoot", EventRaisers::OnVehicleRespawn );
	this->Connect( "onVehicleStartEnter",    "resourceRoot", EventRaisers::OnVehicleStartEnter );
	this->Connect( "onVehicleStartExit",     "resourceRoot", EventRaisers::OnVehicleStartExit );
	this->Connect( "onVehicleEnter",         "resourceRoot", EventRaisers::OnVehicleEnter );
	this->Connect( "onVehicleExit",          "resourceRoot", EventRaisers::OnVehicleExit );
	this->Connect( "onVehicleExplode",       "resourceRoot", EventRaisers::OnVehicleExplode );
										     
	this->Connect( "onWeaponFire",           "resourceRoot", EventRaisers::OnWeaponFire );
}

EventManager::~EventManager()
{
	this->Events.clear();

	this->Module = nullptr;
}

void EventManager::Connect( const string& name, const string& handlerElement, RaiseMethod method )
{
	if( Events.count( name ) > 0 )
		return;

	this->Module->AddEvent( name, handlerElement );

	Events[ name ] = method;
}

void EventManager::Disconnect( const string& name, const string& handlerElement, RaiseMethod method )
{
	this->Module->RemoveEvent( name, handlerElement );

	for( auto iter = this->Events.begin(); iter != this->Events.end(); ++iter )
	{
		RaiseMethod _method = iter->second;

		if( iter->first == name && _method == method )
		{
			this->Events.erase( iter );
		}
	}
}

bool EventManager::Call( const string& name, Element* _this, list< LuaArgument* > arguments )
{
	ElementManager* pElementManager = this->Module->GetElementManager();

	Element* source = nullptr;

	const auto& iter = *arguments.begin();

	if( iter->GetType() == LuaType::LightUserdata )
	{
		source = pElementManager->FindOrCreate( iter->GetLightUserData() );
	}

	for( const auto& iter : this->Events )
	{
		if( iter.first == name )
		{
			RaiseMethod method = iter.second;

			(*method)( source, _this, arguments );

			return true;
		}
	}

	return false;
}

