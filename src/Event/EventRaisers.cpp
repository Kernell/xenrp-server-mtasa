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

#ifdef EVENT_RAISER
#undef EVENT_RAISER
#endif

#define EVENT_RAISER(x)\
	void EventRaisers::x( Element* source, Element* _this, vector< LuaArgument* > arguments )

extern Module* g_Module;

template< class ... Args >
static void ReadArguments( vector< LuaArgument* > arguments, Args ... args )
{
	vector< LuaArgument* >::value_type iter = *arguments.begin();

	int tmp[] = { ReadArgument( iter, args ) ... };
}

int ReadArgument( vector< LuaArgument* >::value_type iter, bool* arg )
{
	( *arg ) = iter->GetBoolean();

	++iter;

	return 0;
}

int ReadArgument( vector< LuaArgument* >::value_type iter, double* arg )
{
	( *arg ) = iter->GetNumber();

	++iter;

	return 0;
}

int ReadArgument( vector< LuaArgument* >::value_type iter, float* arg )
{
	( *arg ) = iter->GetNumber< float >();

	++iter;

	return 0;
}

int ReadArgument( vector< LuaArgument* >::value_type iter, int* arg )
{
	( *arg ) = iter->GetNumber< int >();

	++iter;

	return 0;
}

int ReadArgument( vector< LuaArgument* >::value_type iter, Math::Vector2* arg )
{
	float x = iter->GetNumber< float >();

	++iter;

	float y = iter->GetNumber< float >();

	( *arg ) = Math::Vector2( x, y );

	++iter;

	return 0;
}

int ReadArgument( vector< LuaArgument* >::value_type iter, Math::Vector3* arg )
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

int ReadArgument( vector< LuaArgument* >::value_type iter, string* arg )
{
	( *arg ) = string( iter->GetString() );

	++iter;

	return 0;
}

int ReadArgument( vector< LuaArgument* >::value_type iter, Element* arg )
{
	ElementManager* em = g_Module->GetElementManager();

	arg = em->FindOrCreate( iter->GetLightUserData() );

	++iter;

	return 0;
}

int ReadArgument( vector< LuaArgument* >::value_type iter, LuaArgument* arg )
{
	arg = iter;

	++iter;

	return 0;
}

// Client events

EVENT_RAISER( OnConsole )
{
	string message;

	ReadArguments( arguments, &message );

	ElementManager::OnConsole( new ConsoleEventArgs( source, _this, message ) );
}

// Colshape events

EVENT_RAISER( OnColShapeHit )
{
	Element* hitElement = nullptr;
	bool matchingDimension;

	ReadArguments( arguments, hitElement, &matchingDimension );

	ElementManager::OnColShapeHit( new ColShapeEventArgs( source, _this, hitElement, matchingDimension ) );
}

EVENT_RAISER( OnColShapeLeave )
{
	Element* hitElement = nullptr;
	bool matchingDimension;

	ReadArguments( arguments, hitElement, &matchingDimension );

	ElementManager::OnColShapeLeave( new ColShapeEventArgs( source, _this, hitElement, matchingDimension ) );
}

// Element events

EVENT_RAISER( OnElementDestroy )
{
	ElementManager::OnElementDestroy( new EventArgs( source, _this ) );
}

EVENT_RAISER( OnElementDataChange )
{
	Player* client = nullptr;
	string name;
	LuaArgument oldValue;

	ReadArguments( arguments, client, &name, &oldValue );

	ElementManager::OnElementDataChange( new ElementDataChangeEventArgs( source, _this, client, name, oldValue ) );
}

EVENT_RAISER( OnElementColShapeHit )
{
	ColShape* colShape = nullptr;
	bool matchingDimension;

	ReadArguments( arguments, colShape, &matchingDimension );

	ElementManager::OnElementColShapeHit( new ElementColShapeEventArgs( source, _this, colShape, matchingDimension ) );
}

EVENT_RAISER( OnElementColShapeLeave )
{
	ColShape* colShape = nullptr;
	bool matchingDimension;

	ReadArguments( arguments, colShape, &matchingDimension );

	ElementManager::OnElementColShapeLeave( new ElementColShapeEventArgs( source, _this, colShape, matchingDimension ) );
}

EVENT_RAISER( OnElementClicked )
{
	string mouseButton;
	string buttonState;

	Player* whoClicked = nullptr;

	Math::Vector3 clickPos;

	ReadArguments( arguments, &mouseButton, &buttonState, whoClicked, &clickPos );

	ElementManager::OnElementClicked( new ElementClickedEventArgs( source, _this, mouseButton, buttonState, whoClicked, clickPos ) );
}

EVENT_RAISER( OnElementStartSync )
{
	Player* newSyncer = nullptr;

	ReadArguments( arguments, newSyncer );

	ElementManager::OnElementStartSync( new PlayerEventArgs( source, _this, newSyncer ) );
}

EVENT_RAISER( OnElementStopSync )
{
	Player* player = nullptr;

	ReadArguments( arguments, player );

	ElementManager::OnElementStopSync( new PlayerEventArgs( source, _this, player ) );
}

EVENT_RAISER( OnElementModelChange )
{
	int oldModel;
	int newModel;

	ReadArguments( arguments, &oldModel, &newModel );

	ElementManager::OnElementModelChange( new ElementModelChangeEventArgs( source, _this, oldModel, newModel ) );
}

// Marker events

EVENT_RAISER( OnMarkerHit )
{
	Element* element = nullptr;
	bool matchingDimension;

	ReadArguments( arguments, element, &matchingDimension );

	ElementManager::OnMarkerHit( new MarkerEventArgs( source, _this, element, matchingDimension ) );
}

EVENT_RAISER( OnMarkerLeave )
{
	Element* element = nullptr;
	bool matchingDimension;

	ReadArguments( arguments, element, &matchingDimension );

	ElementManager::OnMarkerLeave( new MarkerEventArgs( source, _this, element, matchingDimension ) );
}

// Pickup events

EVENT_RAISER( OnPickupSpawn )
{
	ElementManager::OnPickupSpawn( new EventArgs( source, _this ) );
}

EVENT_RAISER( OnPickupHit )
{
	Player* player = nullptr;

	ReadArguments( arguments, player );

	ElementManager::OnPickupHit( new PlayerEventArgs( source, _this, player ) );
}

EVENT_RAISER( OnPickupUse )
{
	Player* player = nullptr;

	ReadArguments( arguments, player );

	ElementManager::OnPickupUse( new PlayerEventArgs( source, _this, player ) );
}

// Player events

EVENT_RAISER( OnPlayerBan )
{
	Ban*    banPointer = nullptr;
	Player* responsibleElement = nullptr;

	ReadArguments( arguments, banPointer, responsibleElement );

	ElementManager::OnPlayerBan( new PlayerBanEventArgs( source, _this, banPointer, responsibleElement ) );
}

EVENT_RAISER( OnPlayerChat )
{
	string message;
	int messageType;

	ReadArguments( arguments, &message, &messageType );

	ElementManager::OnPlayerChat( new PlayerChatEventArgs( source, _this, message, messageType ) );
}

EVENT_RAISER( OnPlayerPrivateMessage )
{
	string message;
	Player* recipient = nullptr;

	ReadArguments( arguments, &message, recipient );

	ElementManager::OnPlayerPrivateMessage( new PlayerPrivateMessageEventArgs( source, _this, message, recipient ) );
}

EVENT_RAISER( OnPlayerConnect )
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

EVENT_RAISER( OnPlayerChangeNick )
{
	string oldNick;
	string newNick;

	ReadArguments( arguments, &oldNick, &newNick );

	ElementManager::OnPlayerChangeNick( new PlayerChangeNickEventArgs( source, _this, oldNick, newNick ) );
}

EVENT_RAISER( OnPlayerLogin )
{
	Account* previousAccount = nullptr;
	Account* currentAccount  = nullptr;
	bool autoLogin;

	ReadArguments( arguments, previousAccount, currentAccount, &autoLogin );

	ElementManager::OnPlayerLogin( new PlayerLoginEventArgs( source, _this, previousAccount, currentAccount, autoLogin ) );
}

EVENT_RAISER( OnPlayerLogout )
{
	Account* previousAccount = nullptr;
	Account* currentAccount  = nullptr;

	ReadArguments( arguments, previousAccount, currentAccount );

	ElementManager::OnPlayerLogout( new PlayerLogoutEventArgs( source, _this, previousAccount, currentAccount ) );
}

EVENT_RAISER( OnPlayerDamage )
{
	Player* attacker = nullptr;
	int attackerweapon;
	int bodypart;
	float loss;

	ReadArguments( arguments, attacker, &attackerweapon, &bodypart, &loss );

	ElementManager::OnPlayerDamage( new PlayerDamageEventArgs( source, _this, attacker, attackerweapon, bodypart, loss ) );
}

EVENT_RAISER( OnPlayerJoin )
{
	ElementManager::OnPlayerJoin( new EventArgs( source, _this ) );
}

EVENT_RAISER( OnPlayerQuit )
{
	string type;
	string reason;
	Player* responsePlayer = nullptr;

	ReadArguments( arguments, &type, &reason, responsePlayer );

	ElementManager::OnPlayerQuit( new PlayerQuitEventArgs( source, _this, type, reason, responsePlayer ) );
}

EVENT_RAISER( OnPlayerSpawn )
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

EVENT_RAISER( OnPlayerWasted )
{
	int totalAmmo;
	Element* killer = nullptr;
	int killerWeapon;
	int bodypart;
	bool stealth;

	ReadArguments( arguments, &totalAmmo, killer, &killerWeapon, &bodypart, &stealth );

	ElementManager::OnPlayerWasted( new PedWastedEventArgs( source, _this, totalAmmo, killer, killerWeapon, bodypart, stealth ) );
}

EVENT_RAISER( OnPlayerTarget )
{
	Element* targettedElement = nullptr;

	ReadArguments( arguments, targettedElement );

	ElementManager::OnPlayerTarget( new PlayerTargetEventArgs( source, _this, targettedElement ) );
}

EVENT_RAISER( OnPlayerVehicleEnter )
{
	Vehicle* vehicle = nullptr;
	int seat;
	Player* jacker = nullptr;

	ReadArguments( arguments, vehicle, &seat, jacker );

	ElementManager::OnPlayerVehicleEnter( new PlayerVehicleEnterEventArgs( source, _this, vehicle, seat, jacker ) );
}

EVENT_RAISER( OnPlayerVehicleExit )
{
	Vehicle* vehicle = nullptr;
	int seat;
	Player* jacker = nullptr;

	ReadArguments( arguments, vehicle, &seat, jacker );

	ElementManager::OnPlayerVehicleExit( new PlayerVehicleEnterEventArgs( source, _this, vehicle, seat, jacker ) );
}

EVENT_RAISER( OnPlayerWeaponSwitch )
{
	int previousWeaponID;
	int currentWeaponID;

	ReadArguments( arguments, &previousWeaponID, &currentWeaponID );

	ElementManager::OnPlayerWeaponSwitch( new PedWeaponSwitchEventArgs( source, _this, previousWeaponID, currentWeaponID ) );
}

EVENT_RAISER( OnPlayerMarkerHit )
{
	Marker* marker = nullptr;
	bool matchingDimension;

	ReadArguments( arguments, marker, &matchingDimension );

	ElementManager::OnPlayerMarkerHit( new PlayerMarkerEventArgs( source, _this, marker, matchingDimension ) );
}

EVENT_RAISER( OnPlayerMarkerLeave )
{
	Marker* marker = nullptr;
	bool matchingDimension;

	ReadArguments( arguments, marker, &matchingDimension );

	ElementManager::OnPlayerMarkerLeave( new PlayerMarkerEventArgs( source, _this, marker, matchingDimension ) );
}

EVENT_RAISER( OnPlayerPickupHit )
{
	Pickup* pickup = nullptr;
	bool matchingDimension;

	ReadArguments( arguments, pickup, &matchingDimension );

	ElementManager::OnPlayerPickupHit( new PlayerPickupHitEventArgs( source, _this, pickup, matchingDimension ) );
}

EVENT_RAISER( OnPlayerPickupUse )
{
	Pickup* pickup = nullptr;

	ReadArguments( arguments, pickup );

	ElementManager::OnPlayerPickupUse( new PlayerPickupUseEventArgs( source, _this, pickup ) );
}

EVENT_RAISER( OnPlayerClick )
{
	string mouseButton;
	string buttonState;
	Element* clickedElement = nullptr;
	Math::Vector3 world;
	Math::Vector2 screen;

	ReadArguments( arguments, &mouseButton, &buttonState, clickedElement, &world, &screen );

	ElementManager::OnPlayerClick( new PlayerClickEventArgs( source, _this, mouseButton, buttonState, clickedElement, world, screen ) );
}

EVENT_RAISER( OnPlayerContact )
{
	Element* previous = nullptr;
	Element* current  = nullptr;

	ReadArguments( arguments, previous, current );

	ElementManager::OnPlayerContact( new PlayerContactEventArgs( source, _this, previous, current ) );
}

EVENT_RAISER( OnPlayerStealthKill )
{
	Ped* ped = nullptr;

	ReadArguments( arguments, ped );

	ElementManager::OnPlayerStealthKill( new PedEventArgs( source, _this, ped ) );
}

EVENT_RAISER( OnPlayerMute )
{
	ElementManager::OnPlayerMute( new EventArgs( source, _this ) );
}

EVENT_RAISER( OnPlayerUnmute )
{
	ElementManager::OnPlayerUnmute( new EventArgs( source, _this ) );
}

EVENT_RAISER( OnPlayerCommand )
{
	string command;

	ReadArguments( arguments, &command );

	ElementManager::OnPlayerCommand( new PlayerCommandEventArgs( source, _this, command ) );
}

EVENT_RAISER( OnPlayerModInfo )
{
	string filename;

	list< PlayerModInfo > list;

	ElementManager::OnPlayerModInfo( new PlayerModInfoEventArgs( source, _this, filename, list ) );
}

EVENT_RAISER( OnPlayerVoiceStart )
{
	ElementManager::OnPlayerVoiceStart( new EventArgs( source, _this ) );
}

EVENT_RAISER( OnPlayerVoiceStop )
{
	ElementManager::OnPlayerVoiceStop( new EventArgs( source, _this ) );
}

EVENT_RAISER( OnPlayerScreenShot )
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

EVENT_RAISER( OnPedWasted )
{
	int totalAmmo;
	Element* killer = nullptr;
	int killerWeapon;
	int bodypart;
	bool stealth;

	ReadArguments( arguments, &totalAmmo, killer, &killerWeapon, &bodypart, &stealth );

	ElementManager::OnPedWasted( new PedWastedEventArgs( source, _this, totalAmmo, killer, killerWeapon, bodypart, stealth ) );
}

EVENT_RAISER( OnPedWeaponSwitch )
{
	int previousWeaponID;
	int currentWeaponID;

	ReadArguments( arguments, &previousWeaponID, &currentWeaponID );

	ElementManager::OnPedWeaponSwitch( new PedWeaponSwitchEventArgs( source, _this, previousWeaponID, currentWeaponID ) );
}

// Resource events

EVENT_RAISER( OnResourceStart )
{
	Resource* resource = nullptr;

	ReadArguments( arguments, resource );

	ElementManager::OnResourceStart( new ResourceEventArgs( source, _this, resource ) );
}

EVENT_RAISER( OnResourcePreStart )
{
	Resource* resource = nullptr;

	ReadArguments( arguments, resource );

	ElementManager::OnResourcePreStart( new ResourceEventArgs( source, _this, resource ) );
}

EVENT_RAISER( OnResourceStop )
{
	Resource* resource = nullptr;

	ReadArguments( arguments, resource );

	ElementManager::OnResourceStop( new ResourceEventArgs( source, _this, resource ) );
}

// Server events

EVENT_RAISER( OnBan )
{
	Ban* ban = nullptr;

	ReadArguments( arguments, ban );

	ElementManager::OnBan( new BanEventArgs( source, _this, ban ) );
}

EVENT_RAISER( OnDebugMessage )
{
	string message;
	int level;
	string file;
	int line;

	ReadArguments( arguments, &message, &level, &file, &line );

	ElementManager::OnDebugMessage( new DebugMessageEventArgs( source, _this, message, level, file, line ) );
}

EVENT_RAISER( OnSettingChange )
{
	string setting;
	string oldValue;
	string newValue;

	ReadArguments( arguments, &setting, &oldValue, &newValue );

	ElementManager::OnSettingChange( new SettingChangeEventArgs( source, _this, setting, oldValue, newValue ) );
}

EVENT_RAISER( OnAccountDataChange )
{
	Account* account = nullptr;
	string key;
	LuaArgument value;

	ReadArguments( arguments, account, &key, &value );

	ElementManager::OnAccountDataChange( new AccountDataChangeEventArgs( source, _this, account, key, value ) );
}

EVENT_RAISER( OnUnban )
{
	Ban* ban = nullptr;
	Player* responsibleElement = nullptr;

	ReadArguments( arguments, ban, responsibleElement );

	ElementManager::OnUnban( new UnbanEventArgs( source, _this, ban, responsibleElement ) );
}

EVENT_RAISER( OnChatMessage )
{
	string message;
	Element* element = nullptr;

	ReadArguments( arguments, &message, element );

	ElementManager::OnChatMessage( new ChatMessageEventArgs( source, _this, message, element ) );
}

// Vehicle events

EVENT_RAISER( OnTrailerAttach )
{
	Vehicle* vehicle = nullptr;

	ReadArguments( arguments, vehicle );

	ElementManager::OnTrailerAttach( new VehicleEventArgs( source, _this, vehicle ) );
}

EVENT_RAISER( OnTrailerDetach )
{
	Vehicle* vehicle = nullptr;

	ReadArguments( arguments, vehicle );

	ElementManager::OnTrailerDetach( new VehicleEventArgs( source, _this, vehicle ) );
}

EVENT_RAISER( OnVehicleDamage )
{
	float loss;

	ReadArguments( arguments, &loss );

	ElementManager::OnVehicleDamage( new VehicleDamageEventArgs( source, _this, loss ) );
}

EVENT_RAISER( OnVehicleRespawn )
{
	bool exploded;

	ReadArguments( arguments, &exploded );

	ElementManager::OnVehicleRespawn( new VehicleRespawnEventArgs( source, _this, exploded ) );
}

EVENT_RAISER( OnVehicleStartEnter )
{
	Player* player = nullptr;
	int seat;
	Player* jacked = nullptr;
	int door;

	ReadArguments( arguments, player, &seat, jacked, &door );

	ElementManager::OnVehicleStartEnter( new VehicleStartEnterEventArgs( source, _this, player, seat, jacked, door ) );
}

EVENT_RAISER( OnVehicleStartExit )
{
	Player* player = nullptr;
	int seat;
	Player* jacked = nullptr;
	int door;

	ReadArguments( arguments, player, &seat, jacked, &door );

	ElementManager::OnVehicleStartExit( new VehicleStartEnterEventArgs( source, _this, player, seat, jacked, door ) );
}

EVENT_RAISER( OnVehicleEnter )
{
	Player* player = nullptr;
	int seat;
	Player* jacked = nullptr;

	ReadArguments( arguments, player, &seat, jacked );

	ElementManager::OnVehicleEnter( new VehicleEnterEventArgs( source, _this, player, seat, jacked ) );
}

EVENT_RAISER( OnVehicleExit )
{
	Player* player = nullptr;
	int seat;
	Player* jacked = nullptr;

	ReadArguments( arguments, player, &seat, jacked );

	ElementManager::OnVehicleExit( new VehicleEnterEventArgs( source, _this, player, seat, jacked ) );
}

EVENT_RAISER( OnVehicleExplode )
{
	ElementManager::OnVehicleExplode( new EventArgs( source, _this ) );
}

EVENT_RAISER( OnWeaponFire )
{
	ElementManager::OnWeaponFire( new EventArgs( source, _this ) );
}