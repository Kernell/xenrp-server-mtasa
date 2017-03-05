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
#include "ElementManager.h"

Event< ConsoleEventArgs >              ElementManager::OnConsole;
Event< ColShapeEventArgs >             ElementManager::OnColShapeHit;
Event< ColShapeEventArgs >             ElementManager::OnColShapeLeave;
Event< EventArgs >                     ElementManager::OnElementDestroy;
Event< ElementDataChangeEventArgs >    ElementManager::OnElementDataChange;
Event< ElementColShapeEventArgs >      ElementManager::OnElementColShapeHit;
Event< ElementColShapeEventArgs >      ElementManager::OnElementColShapeLeave;
Event< ElementClickedEventArgs >       ElementManager::OnElementClicked;
Event< PlayerEventArgs >               ElementManager::OnElementStartSync;
Event< PlayerEventArgs >               ElementManager::OnElementStopSync;
Event< ElementModelChangeEventArgs >   ElementManager::OnElementModelChange;
Event< MarkerEventArgs >               ElementManager::OnMarkerHit;
Event< MarkerEventArgs >               ElementManager::OnMarkerLeave;
Event< EventArgs >                     ElementManager::OnPickupSpawn;
Event< PlayerEventArgs >               ElementManager::OnPickupHit;
Event< PlayerEventArgs >               ElementManager::OnPickupUse;
Event< PlayerBanEventArgs >            ElementManager::OnPlayerBan;
Event< PlayerChatEventArgs >           ElementManager::OnPlayerChat;
Event< PlayerPrivateMessageEventArgs > ElementManager::OnPlayerPrivateMessage;
Event< PlayerConnectEventArgs >        ElementManager::OnPlayerConnect;
Event< PlayerChangeNickEventArgs >     ElementManager::OnPlayerChangeNick;
Event< PlayerLoginEventArgs >          ElementManager::OnPlayerLogin;
Event< PlayerLogoutEventArgs >         ElementManager::OnPlayerLogout;
Event< PlayerDamageEventArgs >         ElementManager::OnPlayerDamage;
Event< EventArgs >                     ElementManager::OnPlayerJoin;
Event< PlayerQuitEventArgs >           ElementManager::OnPlayerQuit;
Event< PlayerSpawnEventArgs >          ElementManager::OnPlayerSpawn;
Event< PedWastedEventArgs >            ElementManager::OnPlayerWasted;
Event< PlayerTargetEventArgs >         ElementManager::OnPlayerTarget;
Event< PlayerVehicleEnterEventArgs >   ElementManager::OnPlayerVehicleEnter;
Event< PlayerVehicleEnterEventArgs >   ElementManager::OnPlayerVehicleExit;
Event< PedWeaponSwitchEventArgs >      ElementManager::OnPlayerWeaponSwitch;
Event< PlayerMarkerEventArgs >         ElementManager::OnPlayerMarkerHit;
Event< PlayerMarkerEventArgs >         ElementManager::OnPlayerMarkerLeave;
Event< PlayerPickupHitEventArgs >      ElementManager::OnPlayerPickupHit;
Event< PlayerPickupUseEventArgs >      ElementManager::OnPlayerPickupUse;
Event< PlayerClickEventArgs >          ElementManager::OnPlayerClick;
Event< PlayerContactEventArgs >        ElementManager::OnPlayerContact;
Event< PedEventArgs >                  ElementManager::OnPlayerStealthKill;
Event< EventArgs >                     ElementManager::OnPlayerMute;
Event< EventArgs >                     ElementManager::OnPlayerUnmute;
Event< PlayerCommandEventArgs >        ElementManager::OnPlayerCommand;
Event< PlayerModInfoEventArgs >        ElementManager::OnPlayerModInfo;
Event< EventArgs >                     ElementManager::OnPlayerVoiceStart;
Event< EventArgs >                     ElementManager::OnPlayerVoiceStop;
Event< PlayerScreenShotEventArgs >     ElementManager::OnPlayerScreenShot;
Event< PedWastedEventArgs >            ElementManager::OnPedWasted;
Event< PedWeaponSwitchEventArgs >      ElementManager::OnPedWeaponSwitch;
Event< ResourceEventArgs >             ElementManager::OnResourceStart;
Event< ResourceEventArgs >             ElementManager::OnResourcePreStart;
Event< ResourceEventArgs >             ElementManager::OnResourceStop;
Event< BanEventArgs >                  ElementManager::OnBan;
Event< DebugMessageEventArgs >         ElementManager::OnDebugMessage;
Event< SettingChangeEventArgs >        ElementManager::OnSettingChange;
Event< AccountDataChangeEventArgs >    ElementManager::OnAccountDataChange;
Event< UnbanEventArgs >                ElementManager::OnUnban;
Event< ChatMessageEventArgs >          ElementManager::OnChatMessage;
Event< VehicleEventArgs >              ElementManager::OnTrailerAttach;
Event< VehicleEventArgs >              ElementManager::OnTrailerDetach;
Event< VehicleDamageEventArgs >        ElementManager::OnVehicleDamage;
Event< VehicleRespawnEventArgs >       ElementManager::OnVehicleRespawn;
Event< VehicleStartEnterEventArgs >    ElementManager::OnVehicleStartEnter;
Event< VehicleStartEnterEventArgs >    ElementManager::OnVehicleStartExit;
Event< VehicleEnterEventArgs >         ElementManager::OnVehicleEnter;
Event< VehicleEnterEventArgs >         ElementManager::OnVehicleExit;
Event< EventArgs >                     ElementManager::OnVehicleExplode;
Event< EventArgs >                     ElementManager::OnWeaponFire;

const map< ElementType, pair< string, string > > ElementManager::_ElementType =
{
	{ ElementType::Dummy,					{ "dummy",			"Element" } },
	{ ElementType::Player,					{ "player",			"Player" } },
	{ ElementType::Vehicle,					{ "vehicle",		"Vehicle" } },
	{ ElementType::Object,					{ "object",			"Object" } },
	{ ElementType::Marker,					{ "marker",			"Marker" } },
	{ ElementType::Blip,					{ "blip",			"Blip" } },
	{ ElementType::Pickup,					{ "pickup",			"Pickup" } },
	{ ElementType::RadarArea,				{ "radararea",		"RadarArea" } },
	{ ElementType::Console,					{ "console",		"Console" } },
	{ ElementType::Team,					{ "team",			"Team" } },
	{ ElementType::Ped,						{ "ped",			"Ped" } },
	{ ElementType::ColShape,				{ "colshape",		"ColShape" } },
	{ ElementType::ScriptFile,				{ "scriptfile",		"ScriptFile" } },
	{ ElementType::Water,					{ "water",			"Water" } },
	{ ElementType::Weapon,					{ "weapon",			"Weapon" } },
	{ ElementType::DatabaseConnection,		{ "db-connection",	"DbConnection" } },
	{ ElementType::Resource,				{ "resource",		"Resource" } },
	{ ElementType::Root,					{ "root",			"Element" } },
	{ ElementType::Unknown,					{ "unknown",		"Element" } },
};

ElementManager::ElementManager( ::Module* module )
{
	this->Module = module;

	OnElementDestroy += new EventHandler< ElementManager >( &ElementManager::ElementDestroy, this );
}

ElementManager::~ElementManager( void )
{
	this->DeleteAll();

	this->Module = nullptr;
}

void ElementManager::DoPulse()
{
	for( const auto& element : this->List )
	{
		element->DoPulse();
	}
}

void ElementManager::DeleteAll( void )
{
	auto clonedList = this->List;

	this->List.clear();

	for( const auto iter: clonedList )
	{
		delete iter;
	}
}

Element* ElementManager::Create( PVOID userdata )
{
	if( userdata == nullptr )
	{
		return nullptr;
	}

	const string& userdataType = Lua::Bindings::GetUserdataType( this->Module->GetLua(), userdata );

	string typeName = "element";

	if( userdataType == "element" )
	{
		typeName = Lua::Bindings::GetElementType( this->Module->GetLua(), userdata );
	}
	else if( userdataType == "resource-data" )
	{
		typeName = "resource";
	}
	
	Element* element = nullptr;

	ElementType type = GetTypeByName( typeName );

	switch( type )
	{
		case ElementType::Player:
		{
			element = new Player( userdata );

			break;
		}
		case ElementType::Vehicle:
		{
			element = new Vehicle( userdata );

			break;
		}
		case ElementType::Object:
		{
			element = new Object( userdata );

			break;
		}
		case ElementType::Marker:
		{
			element = new Marker( userdata );

			break;
		}
		case ElementType::Blip:
		{
			element = new Blip( userdata );

			break;
		}
		case ElementType::Pickup:
		{
			element = new Pickup( userdata );

			break;
		}
		case ElementType::RadarArea:
		{
			element = new RadarArea( userdata );

			break;
		}
		case ElementType::Console:
		{
			element = new Console( userdata );

			break;
		}
		case ElementType::Team:
		{
			element = new Team( userdata );

			break;
		}
		case ElementType::Ped:
		{
			element = new Ped( userdata );

			break;
		}
		case ElementType::ColShape:
		{
			element = new ColShape( userdata );

			break;
		}
		case ElementType::Water:
		{
			element = new Water( userdata );

			break;
		}
		case ElementType::Resource:
		{
			element = new Resource( userdata );

			break;
		}
		case ElementType::ScriptFile:
		case ElementType::Weapon:
		case ElementType::DatabaseConnection:
		case ElementType::Root:
		case ElementType::Unknown:
		case ElementType::Dummy:
		{
			element = new Element( userdata );

			break;
		}
	}

	return element;
}

Element* ElementManager::FindOrCreate( PVOID userdata )
{
	if( userdata == nullptr )
	{
		return nullptr;
	}

	Element* element = this->GetFromList( userdata );

	if( !element )
	{
		element = this->Create( userdata );
	}

	return element;
}

void ElementManager::AddToList( Element* element )
{
	this->List.push_back( element );
}

void ElementManager::RemoveFromList( Element* element )
{
	vector< Element* >::iterator iter = this->List.begin();

	for( ; iter != this->List.end(); ++iter )
	{
		if( (*iter) == element )
		{
			this->List.erase( iter );

			break;
		}
	}
}

void ElementManager::ElementDestroy( EventArgs* event )
{
	delete event->Sender;
}

Element* ElementManager::GetFromList( PVOID userdata )
{
	for( const auto& element : this->List )
	{
		if( element->GetLuaUserdata() == userdata )
		{
			return element;
		}
	}

	return nullptr;
}
