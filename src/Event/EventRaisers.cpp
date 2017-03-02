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
#include "EventRaisers.h"
#include "Core/Module.h"

extern Module* g_Module;

int EventRaisers::ReadArgument( list< LuaArgument* >::value_type iter, bool* arg )
{
	( *arg ) = iter->GetBoolean();

	++iter;

	return 0;
}

int EventRaisers::ReadArgument( list< LuaArgument* >::value_type iter, double* arg )
{
	( *arg ) = iter->GetNumber();

	++iter;

	return 0;
}

int EventRaisers::ReadArgument( list< LuaArgument* >::value_type iter, float* arg )
{
	( *arg ) = iter->GetNumber< float >();

	++iter;

	return 0;
}

int EventRaisers::ReadArgument( list< LuaArgument* >::value_type iter, int* arg )
{
	( *arg ) = iter->GetNumber< int >();

	++iter;

	return 0;
}

int EventRaisers::ReadArgument( list< LuaArgument* >::value_type iter, Math::Vector2* arg )
{
	float x = iter->GetNumber< float >();

	++iter;

	float y = iter->GetNumber< float >();

	( *arg ) = Math::Vector2( x, y );

	++iter;

	return 0;
}

int EventRaisers::ReadArgument( list< LuaArgument* >::value_type iter, Math::Vector3* arg )
{
	float x = iter->GetNumber< float >();

	++iter;

	float y = iter->GetNumber< float >();

	++iter;

	float z = iter->GetNumber< float >();

	( *arg ) = Math::Vector3( x, y, z );

	++iter;

	return 0;
}

int EventRaisers::ReadArgument( list< LuaArgument* >::value_type iter, string* arg )
{
	( *arg ) = string( iter->GetString() );

	++iter;

	return 0;
}

int EventRaisers::ReadArgument( list< LuaArgument* >::value_type iter, Element* arg )
{
	ElementManager* em = g_Module->GetElementManager();

	arg = em->FindOrCreate( iter->GetLightUserData() );

	++iter;

	return 0;
}

int EventRaisers::ReadArgument( list< LuaArgument* >::value_type iter, LuaArgument* arg )
{
	arg = iter;

	++iter;

	return 0;
}

// Client events

void EventRaisers::OnConsole( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	string message;

	ReadArguments( arguments, &message );

	ElementManager::OnConsole( new ConsoleEventArgs( source, _this, message ) );
}

// Colshape events

void EventRaisers::OnColShapeHit( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Element* hitElement = nullptr;
	bool matchingDimension;

	ReadArguments( arguments, hitElement, &matchingDimension );

	ElementManager::OnColShapeHit( new ColShapeEventArgs( source, _this, hitElement, matchingDimension ) );
}

void EventRaisers::OnColShapeLeave( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Element* hitElement = nullptr;
	bool matchingDimension;

	ReadArguments( arguments, hitElement, &matchingDimension );

	ElementManager::OnColShapeLeave( new ColShapeEventArgs( source, _this, hitElement, matchingDimension ) );
}

// Element events

void EventRaisers::OnElementDestroy( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	ElementManager::OnElementDestroy( new EventArgs( source, _this ) );
}

void EventRaisers::OnElementDataChange( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Player* client = nullptr;
	string name;
	LuaArgument oldValue;

	ReadArguments( arguments, client, &name, &oldValue );

	ElementManager::OnElementDataChange( new ElementDataChangeEventArgs( source, _this, client, name, oldValue ) );
}

void EventRaisers::OnElementColShapeHit( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	ColShape* colShape = nullptr;
	bool matchingDimension;

	ReadArguments( arguments, colShape, &matchingDimension );

	ElementManager::OnElementColShapeHit( new ElementColShapeEventArgs( source, _this, colShape, matchingDimension ) );
}

void EventRaisers::OnElementColShapeLeave( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	ColShape* colShape = nullptr;
	bool matchingDimension;

	ReadArguments( arguments, colShape, &matchingDimension );

	ElementManager::OnElementColShapeLeave( new ElementColShapeEventArgs( source, _this, colShape, matchingDimension ) );
}

void EventRaisers::OnElementClicked( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	string mouseButton;
	string buttonState;

	Player* whoClicked = nullptr;

	Math::Vector3 clickPos;

	ReadArguments( arguments, &mouseButton, &buttonState, whoClicked, &clickPos );

	ElementManager::OnElementClicked( new ElementClickedEventArgs( source, _this, mouseButton, buttonState, whoClicked, clickPos ) );
}

void EventRaisers::OnElementStartSync( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Player* newSyncer = nullptr;

	ReadArguments( arguments, newSyncer );

	ElementManager::OnElementStartSync( new PlayerEventArgs( source, _this, newSyncer ) );
}

void EventRaisers::OnElementStopSync( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Player* player = nullptr;

	ReadArguments( arguments, player );

	ElementManager::OnElementStopSync( new PlayerEventArgs( source, _this, player ) );
}

void EventRaisers::OnElementModelChange( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	int oldModel;
	int newModel;

	ReadArguments( arguments, &oldModel, &newModel );

	ElementManager::OnElementModelChange( new ElementModelChangeEventArgs( source, _this, oldModel, newModel ) );
}

// Marker events

void EventRaisers::OnMarkerHit( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Element* element = nullptr;
	bool matchingDimension;

	ReadArguments( arguments, element, &matchingDimension );

	ElementManager::OnMarkerHit( new MarkerEventArgs( source, _this, element, matchingDimension ) );
}

void EventRaisers::OnMarkerLeave( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Element* element = nullptr;
	bool matchingDimension;

	ReadArguments( arguments, element, &matchingDimension );

	ElementManager::OnMarkerLeave( new MarkerEventArgs( source, _this, element, matchingDimension ) );
}

// Pickup events

void EventRaisers::OnPickupSpawn( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	ElementManager::OnPickupSpawn( new EventArgs( source, _this ) );
}

void EventRaisers::OnPickupHit( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Player* player = nullptr;

	ReadArguments( arguments, player );

	ElementManager::OnPickupHit( new PlayerEventArgs( source, _this, player ) );
}

void EventRaisers::OnPickupUse( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Player* player = nullptr;

	ReadArguments( arguments, player );

	ElementManager::OnPickupUse( new PlayerEventArgs( source, _this, player ) );
}

// Player events

void EventRaisers::OnPlayerBan( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Ban*    banPointer = nullptr;
	Player* responsibleElement = nullptr;

	ReadArguments( arguments, banPointer, responsibleElement );

	ElementManager::OnPlayerBan( new PlayerBanEventArgs( source, _this, banPointer, responsibleElement ) );
}

void EventRaisers::OnPlayerChat( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	string message;
	int messageType;

	ReadArguments( arguments, &message, &messageType );

	ElementManager::OnPlayerChat( new PlayerChatEventArgs( source, _this, message, messageType ) );
}

void EventRaisers::OnPlayerPrivateMessage( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	string message;
	Player* recipient = nullptr;

	ReadArguments( arguments, &message, recipient );

	ElementManager::OnPlayerPrivateMessage( new PlayerPrivateMessageEventArgs( source, _this, message, recipient ) );
}

void EventRaisers::OnPlayerConnect( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	string nick;
	string ip;
	string username;
	string serial;
	int versionNumber;
	string versionString;

	ReadArguments( arguments, &nick, &ip, &username, &serial, &versionNumber, &versionString );

	ElementManager::OnPlayerConnect( new PlayerConnectEventArgs( source, _this, nick, ip, username, serial, versionNumber, versionString ) );
}

void EventRaisers::OnPlayerChangeNick( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	string oldNick;
	string newNick;

	ReadArguments( arguments, &oldNick, &newNick );

	ElementManager::OnPlayerChangeNick( new PlayerChangeNickEventArgs( source, _this, oldNick, newNick ) );
}

void EventRaisers::OnPlayerLogin( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Account* previousAccount = nullptr;
	Account* currentAccount  = nullptr;
	bool autoLogin;

	ReadArguments( arguments, previousAccount, currentAccount, &autoLogin );

	ElementManager::OnPlayerLogin( new PlayerLoginEventArgs( source, _this, previousAccount, currentAccount, autoLogin ) );
}

void EventRaisers::OnPlayerLogout( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Account* previousAccount = nullptr;
	Account* currentAccount  = nullptr;

	ReadArguments( arguments, previousAccount, currentAccount );

	ElementManager::OnPlayerLogout( new PlayerLogoutEventArgs( source, _this, previousAccount, currentAccount ) );
}

void EventRaisers::OnPlayerDamage( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Player* attacker = nullptr;
	int attackerweapon;
	int bodypart;
	float loss;

	ReadArguments( arguments, attacker, &attackerweapon, &bodypart, &loss );

	ElementManager::OnPlayerDamage( new PlayerDamageEventArgs( source, _this, attacker, attackerweapon, bodypart, loss ) );
}

void EventRaisers::OnPlayerJoin( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	ElementManager::OnPlayerJoin( new EventArgs( source, _this ) );
}

void EventRaisers::OnPlayerQuit( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	string type;
	string reason;
	Player* responsePlayer = nullptr;

	ReadArguments( arguments, &type, &reason, responsePlayer );

	ElementManager::OnPlayerQuit( new PlayerQuitEventArgs( source, _this, type, reason, responsePlayer ) );
}

void EventRaisers::OnPlayerSpawn( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	float x;
	float y;
	float z;
	float rotation;
	Team* team = nullptr;
	int skin;
	int interior;
	int dimension;

	ReadArguments( arguments, &x, &y, &z, &rotation, team, &skin, &interior, &dimension );

	Math::Vector3 position( x, y, z );

	ElementManager::OnPlayerSpawn( new PlayerSpawnEventArgs( source, _this, position, rotation, team, skin, interior, dimension ) );
}

void EventRaisers::OnPlayerWasted( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	int totalAmmo;
	Element* killer = nullptr;
	int killerWeapon;
	int bodypart;
	bool stealth;

	ReadArguments( arguments, &totalAmmo, killer, &killerWeapon, &bodypart, &stealth );

	ElementManager::OnPlayerWasted( new PedWastedEventArgs( source, _this, totalAmmo, killer, killerWeapon, bodypart, stealth ) );
}

void EventRaisers::OnPlayerTarget( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Element* targettedElement = nullptr;

	ReadArguments( arguments, targettedElement );

	ElementManager::OnPlayerTarget( new PlayerTargetEventArgs( source, _this, targettedElement ) );
}

void EventRaisers::OnPlayerVehicleEnter( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Vehicle* vehicle = nullptr;
	int seat;
	Player* jacker = nullptr;

	ReadArguments( arguments, vehicle, &seat, jacker );

	ElementManager::OnPlayerVehicleEnter( new PlayerVehicleEnterEventArgs( source, _this, vehicle, seat, jacker ) );
}

void EventRaisers::OnPlayerVehicleExit( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Vehicle* vehicle = nullptr;
	int seat;
	Player* jacker = nullptr;

	ReadArguments( arguments, vehicle, &seat, jacker );

	ElementManager::OnPlayerVehicleExit( new PlayerVehicleEnterEventArgs( source, _this, vehicle, seat, jacker ) );
}

void EventRaisers::OnPlayerWeaponSwitch( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	int previousWeaponID;
	int currentWeaponID;

	ReadArguments( arguments, &previousWeaponID, &currentWeaponID );

	ElementManager::OnPlayerWeaponSwitch( new PedWeaponSwitchEventArgs( source, _this, previousWeaponID, currentWeaponID ) );
}

void EventRaisers::OnPlayerMarkerHit( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Marker* marker = nullptr;
	bool matchingDimension;

	ReadArguments( arguments, marker, &matchingDimension );

	ElementManager::OnPlayerMarkerHit( new PlayerMarkerEventArgs( source, _this, marker, matchingDimension ) );
}

void EventRaisers::OnPlayerMarkerLeave( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Marker* marker = nullptr;
	bool matchingDimension;

	ReadArguments( arguments, marker, &matchingDimension );

	ElementManager::OnPlayerMarkerLeave( new PlayerMarkerEventArgs( source, _this, marker, matchingDimension ) );
}

void EventRaisers::OnPlayerPickupHit( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Pickup* pickup = nullptr;
	bool matchingDimension;

	ReadArguments( arguments, pickup, &matchingDimension );

	ElementManager::OnPlayerPickupHit( new PlayerPickupHitEventArgs( source, _this, pickup, matchingDimension ) );
}

void EventRaisers::OnPlayerPickupUse( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Pickup* pickup = nullptr;

	ReadArguments( arguments, pickup );

	ElementManager::OnPlayerPickupUse( new PlayerPickupUseEventArgs( source, _this, pickup ) );
}

void EventRaisers::OnPlayerClick( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	string mouseButton;
	string buttonState;
	Element* clickedElement = nullptr;
	Math::Vector3 world;
	Math::Vector2 screen;

	ReadArguments( arguments, &mouseButton, &buttonState, clickedElement, &world, &screen );

	ElementManager::OnPlayerClick( new PlayerClickEventArgs( source, _this, mouseButton, buttonState, clickedElement, world, screen ) );
}

void EventRaisers::OnPlayerContact( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Element* previous = nullptr;
	Element* current  = nullptr;

	ReadArguments( arguments, previous, current );

	ElementManager::OnPlayerContact( new PlayerContactEventArgs( source, _this, previous, current ) );
}

void EventRaisers::OnPlayerStealthKill( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Ped* ped = nullptr;

	ReadArguments( arguments, ped );

	ElementManager::OnPlayerStealthKill( new PedEventArgs( source, _this, ped ) );
}

void EventRaisers::OnPlayerMute( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	ElementManager::OnPlayerMute( new EventArgs( source, _this ) );
}

void EventRaisers::OnPlayerUnmute( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	ElementManager::OnPlayerUnmute( new EventArgs( source, _this ) );
}

void EventRaisers::OnPlayerCommand( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	string command;

	ReadArguments( arguments, &command );

	ElementManager::OnPlayerCommand( new PlayerCommandEventArgs( source, _this, command ) );
}

void EventRaisers::OnPlayerModInfo( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	string filename;

	list< PlayerModInfo > list;

	ElementManager::OnPlayerModInfo( new PlayerModInfoEventArgs( source, _this, filename, list ) );
}

void EventRaisers::OnPlayerVoiceStart( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	ElementManager::OnPlayerVoiceStart( new EventArgs( source, _this ) );
}

void EventRaisers::OnPlayerVoiceStop( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	ElementManager::OnPlayerVoiceStop( new EventArgs( source, _this ) );
}

void EventRaisers::OnPlayerScreenShot( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Resource* resource = nullptr;
	string status;
	string imageData;
	int timestamp;
	string tag;

	ReadArguments( arguments, resource, &status, &imageData, &timestamp, &tag );

	ElementManager::OnPlayerScreenShot( new PlayerScreenShotEventArgs( source, _this, resource, status, imageData, timestamp, tag ) );
}

// Ped events

void EventRaisers::OnPedWasted( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	int totalAmmo;
	Element* killer = nullptr;
	int killerWeapon;
	int bodypart;
	bool stealth;

	ReadArguments( arguments, &totalAmmo, killer, &killerWeapon, &bodypart, &stealth );

	ElementManager::OnPedWasted( new PedWastedEventArgs( source, _this, totalAmmo, killer, killerWeapon, bodypart, stealth ) );
}

void EventRaisers::OnPedWeaponSwitch( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	int previousWeaponID;
	int currentWeaponID;

	ReadArguments( arguments, &previousWeaponID, &currentWeaponID );

	ElementManager::OnPedWeaponSwitch( new PedWeaponSwitchEventArgs( source, _this, previousWeaponID, currentWeaponID ) );
}

// Resource events

void EventRaisers::OnResourceStart( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Resource* resource = nullptr;

	ReadArguments( arguments, resource );

	ElementManager::OnResourceStart( new ResourceEventArgs( source, _this, resource ) );
}

void EventRaisers::OnResourcePreStart( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Resource* resource = nullptr;

	ReadArguments( arguments, resource );

	ElementManager::OnResourcePreStart( new ResourceEventArgs( source, _this, resource ) );
}

void EventRaisers::OnResourceStop( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Resource* resource = nullptr;

	ReadArguments( arguments, resource );

	ElementManager::OnResourceStop( new ResourceEventArgs( source, _this, resource ) );
}

// Server events

void EventRaisers::OnBan( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Ban* ban = nullptr;

	ReadArguments( arguments, ban );

	ElementManager::OnBan( new BanEventArgs( source, _this, ban ) );
}

void EventRaisers::OnDebugMessage( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	string message;
	int level;
	string file;
	int line;

	ReadArguments( arguments, &message, &level, &file, &line );

	ElementManager::OnDebugMessage( new DebugMessageEventArgs( source, _this, message, level, file, line ) );
}

void EventRaisers::OnSettingChange( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	string setting;
	string oldValue;
	string newValue;

	ReadArguments( arguments, &setting, &oldValue, &newValue );

	ElementManager::OnSettingChange( new SettingChangeEventArgs( source, _this, setting, oldValue, newValue ) );
}

void EventRaisers::OnAccountDataChange( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Account* account = nullptr;
	string key;
	LuaArgument value;

	ReadArguments( arguments, account, &key, &value );

	ElementManager::OnAccountDataChange( new AccountDataChangeEventArgs( source, _this, account, key, value ) );
}

void EventRaisers::OnUnban( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Ban* ban = nullptr;
	Player* responsibleElement = nullptr;

	ReadArguments( arguments, ban, responsibleElement );

	ElementManager::OnUnban( new UnbanEventArgs( source, _this, ban, responsibleElement ) );
}

void EventRaisers::OnChatMessage( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	string message;
	Element* element = nullptr;

	ReadArguments( arguments, &message, element );

	ElementManager::OnChatMessage( new ChatMessageEventArgs( source, _this, message, element ) );
}

// Vehicle events

void EventRaisers::OnTrailerAttach( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Vehicle* vehicle = nullptr;

	ReadArguments( arguments, vehicle );

	ElementManager::OnTrailerAttach( new VehicleEventArgs( source, _this, vehicle ) );
}

void EventRaisers::OnTrailerDetach( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Vehicle* vehicle = nullptr;

	ReadArguments( arguments, vehicle );

	ElementManager::OnTrailerDetach( new VehicleEventArgs( source, _this, vehicle ) );
}

void EventRaisers::OnVehicleDamage( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	float loss;

	ReadArguments( arguments, &loss );

	ElementManager::OnVehicleDamage( new VehicleDamageEventArgs( source, _this, loss ) );
}

void EventRaisers::OnVehicleRespawn( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	bool exploded;

	ReadArguments( arguments, &exploded );

	ElementManager::OnVehicleRespawn( new VehicleRespawnEventArgs( source, _this, exploded ) );
}

void EventRaisers::OnVehicleStartEnter( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Player* player = nullptr;
	int seat;
	Player* jacked = nullptr;
	int door;

	ReadArguments( arguments, player, &seat, jacked, &door );

	ElementManager::OnVehicleStartEnter( new VehicleStartEnterEventArgs( source, _this, player, seat, jacked, door ) );
}

void EventRaisers::OnVehicleStartExit( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Player* player = nullptr;
	int seat;
	Player* jacked = nullptr;
	int door;

	ReadArguments( arguments, player, &seat, jacked, &door );

	ElementManager::OnVehicleStartExit( new VehicleStartEnterEventArgs( source, _this, player, seat, jacked, door ) );
}

void EventRaisers::OnVehicleEnter( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Player* player = nullptr;
	int seat;
	Player* jacked = nullptr;

	ReadArguments( arguments, player, &seat, jacked );

	ElementManager::OnVehicleEnter( new VehicleEnterEventArgs( source, _this, player, seat, jacked ) );
}

void EventRaisers::OnVehicleExit( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	Player* player = nullptr;
	int seat;
	Player* jacked = nullptr;

	ReadArguments( arguments, player, &seat, jacked );

	ElementManager::OnVehicleExit( new VehicleEnterEventArgs( source, _this, player, seat, jacked ) );
}

void EventRaisers::OnVehicleExplode( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	ElementManager::OnVehicleExplode( new EventArgs( source, _this ) );
}

void EventRaisers::OnWeaponFire( Element* source, Element* _this, list< LuaArgument* > arguments )
{
	ElementManager::OnWeaponFire( new EventArgs( source, _this ) );
}