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

class ElementManager;

#ifndef __ELEMENTMANAGER_H
#define __ELEMENTMANAGER_H

#include "Event/Event.h"
#include "Event/EventArgs.h"

enum class ElementType
{
	Dummy,
	Player,
	Vehicle,
	Object,
	Marker,
	Blip,
	Pickup,
	RadarArea,
	SpawnpointDeprecated,
	RemoteclientDeprecated,
	Console,
	PathNodeUnused,
	WorldMeshUnused,
	Team,
	Ped,
	ColShape,
	ScriptFile,
	Water,
	Weapon,
	DatabaseConnection,
	Resource,
	Root,
	Unknown,
};

class ElementManager
{
public:
	static Event< ConsoleEventArgs >              OnConsole;

	static Event< ColShapeEventArgs >             OnColShapeHit;
	static Event< ColShapeEventArgs >             OnColShapeLeave;

	static Event< EventArgs >                     OnElementDestroy;
	static Event< ElementDataChangeEventArgs >    OnElementDataChange;
	static Event< ElementColShapeEventArgs >      OnElementColShapeHit;
	static Event< ElementColShapeEventArgs >      OnElementColShapeLeave;
	static Event< ElementClickedEventArgs >       OnElementClicked;
	static Event< PlayerEventArgs >               OnElementStartSync;
	static Event< PlayerEventArgs >               OnElementStopSync;
	static Event< ElementModelChangeEventArgs >   OnElementModelChange;

	static Event< MarkerEventArgs >               OnMarkerHit;
	static Event< MarkerEventArgs >               OnMarkerLeave;

	static Event< EventArgs >                     OnPickupSpawn;
	static Event< PlayerEventArgs >               OnPickupHit;
	static Event< PlayerEventArgs >               OnPickupUse;

	static Event< PlayerBanEventArgs >            OnPlayerBan;
	static Event< PlayerChatEventArgs >           OnPlayerChat;
	static Event< PlayerPrivateMessageEventArgs > OnPlayerPrivateMessage;
	static Event< PlayerConnectEventArgs >        OnPlayerConnect;
	static Event< PlayerChangeNickEventArgs >     OnPlayerChangeNick;
	static Event< PlayerLoginEventArgs >          OnPlayerLogin;
	static Event< PlayerLogoutEventArgs >         OnPlayerLogout;
	static Event< PlayerDamageEventArgs >         OnPlayerDamage;
	static Event< EventArgs >                     OnPlayerJoin;
	static Event< PlayerQuitEventArgs >           OnPlayerQuit;
	static Event< PlayerSpawnEventArgs >          OnPlayerSpawn;
	static Event< PedWastedEventArgs >            OnPlayerWasted;
	static Event< PlayerTargetEventArgs >         OnPlayerTarget;
	static Event< PlayerVehicleEnterEventArgs >   OnPlayerVehicleEnter;
	static Event< PlayerVehicleEnterEventArgs >   OnPlayerVehicleExit;
	static Event< PedWeaponSwitchEventArgs >      OnPlayerWeaponSwitch;
	static Event< PlayerMarkerEventArgs >         OnPlayerMarkerHit;
	static Event< PlayerMarkerEventArgs >         OnPlayerMarkerLeave;
	static Event< PlayerPickupHitEventArgs >      OnPlayerPickupHit;
	static Event< PlayerPickupUseEventArgs >      OnPlayerPickupUse;
	static Event< PlayerClickEventArgs >          OnPlayerClick;
	static Event< PlayerContactEventArgs >        OnPlayerContact;
	static Event< PedEventArgs >                  OnPlayerStealthKill;
	static Event< EventArgs >                     OnPlayerMute;
	static Event< EventArgs >                     OnPlayerUnmute;
	static Event< PlayerCommandEventArgs >        OnPlayerCommand;
	static Event< PlayerModInfoEventArgs >        OnPlayerModInfo;
	static Event< EventArgs >                     OnPlayerVoiceStart;
	static Event< EventArgs >                     OnPlayerVoiceStop;
	static Event< PlayerScreenShotEventArgs >     OnPlayerScreenShot;
		
	static Event< PedWastedEventArgs >            OnPedWasted;
	static Event< PedWeaponSwitchEventArgs >      OnPedWeaponSwitch;

	static Event< ResourceEventArgs >             OnResourceStart;
	static Event< ResourceEventArgs >             OnResourcePreStart;
	static Event< ResourceEventArgs >             OnResourceStop;

	static Event< BanEventArgs >                  OnBan;
	static Event< DebugMessageEventArgs >         OnDebugMessage;
	static Event< SettingChangeEventArgs >        OnSettingChange;
	static Event< AccountDataChangeEventArgs >    OnAccountDataChange;
	static Event< UnbanEventArgs >                OnUnban;
	static Event< ChatMessageEventArgs >          OnChatMessage;

	static Event< VehicleEventArgs >              OnTrailerAttach;
	static Event< VehicleEventArgs >              OnTrailerDetach;
	static Event< VehicleDamageEventArgs >        OnVehicleDamage;
	static Event< VehicleRespawnEventArgs >       OnVehicleRespawn;
	static Event< VehicleStartEnterEventArgs >    OnVehicleStartEnter;
	static Event< VehicleStartEnterEventArgs >    OnVehicleStartExit;
	static Event< VehicleEnterEventArgs >         OnVehicleEnter;
	static Event< VehicleEnterEventArgs >         OnVehicleExit;
	static Event< EventArgs >                     OnVehicleExplode;

	static Event< EventArgs >                     OnWeaponFire;

public:
									ElementManager      ( Module* module );
									~ElementManager     ();

	void                            DoPulse             ();
	void                            DeleteAll			();

	Element*                        Create              ( PVOID userdata );
	Element*                        FindOrCreate        ( PVOID userdata );
							        
	Element*                        GetFromList         ( PVOID userdata );

	void							AddToList           ( Element* element );
	void							RemoveFromList      ( Element* element );

public:
	void ElementDestroy             ( EventArgs* event );

public:
	static const map< ElementType, pair< string, string > > _ElementType;

	inline static const string GetTypeName( ElementType iType )
	{
		for( const auto& iter : _ElementType )
		{
			if( iter.first == iType )
			{
				return iter.second.first;
			}
		}

		return "unknown";
	}

	inline static const ElementType GetTypeByName( const string& strName )
	{
		for( const auto& iter : _ElementType )
		{
			if( iter.second.first == strName )
			{
				return iter.first;
			}
		}

		return ElementType::Unknown;
	}

	inline static const char* GetTypeClassName( ElementType iType )
	{
		for( const auto& iter : _ElementType )
		{
			if( iter.first == iType )
			{
				return iter.second.second.c_str();
			}
		}

		return nullptr;
	}

	inline static const char* GetTypeClassName( const string& strType )
	{
		for( const auto& iter : _ElementType )
		{
			if( iter.second.first == strType )
			{
				return iter.second.second.c_str();
			}
		}

		return nullptr;
	}

private:
	Module*                         Module;
	list< Element* >                List;
};

#endif
