/*********************************************************
*
*  Copyright � 2017, Xen Roleplay. 
*
*  All Rights Reserved.
*
*  Redistribution and use in source and binary forms,
*  with or without modification,
*  is permitted only for authors.
*
*********************************************************/

#ifndef __BINDINGS_H
#define __BINDINGS_H

#include "Lua/LuaArgument.h"
#include "Lua/LuaArguments.h"

namespace Lua
{
	class Bindings
	{
	public:
		// All-Seeing Eye related Functions
		static bool					    SetGameType							( lua_State* pLuaVM, const char* szGameType );
		static bool					    SetMapName							( lua_State* pLuaVM, const char* szMapName );
		static string				    GetRuleValue						( lua_State* pLuaVM, const char* szKey );
		static bool					    SetRuleValue						( lua_State* pLuaVM, const char* szKey, const char* szValue );
		static bool					    RemoveRuleValue						( lua_State* pLuaVM, const char* szKey );
		static string				    GetPlayerAnnounceValue				( lua_State* pLuaVM, PVOID pElement, const char* szKey );
		static bool					    SetPlayerAnnounceValue				( lua_State* pLuaVM, PVOID pElement, const char* szKey, const char* szValue );

		static string				    Get									( lua_State* pLuaVM, const char* szKey );
		static bool					    Set									( lua_State* pLuaVM, const char* szKey, const char* szValue );
		static string				    GetGameType							( lua_State* pLuaVM );
		static string				    GetMapName							( lua_State* pLuaVM );

		static bool					    AddCommandHandler					( lua_State* pLuaVM, const char* szCommand, lua_CFunction iLuaFunction, bool bRestricted = false, bool bCaseSensitive = true );
		static bool					    ExecuteCommandHandler				( lua_State* pLuaVM, const char* szCommand, PVOID pUserData, const char* szArgs );
		static bool					    RemoveCommandHandler				( lua_State* pLuaVM, const char* szCommand, lua_CFunction iLuaFunction );

	//	static int					    CallRemote                          ( lua_State* luaVM );
	//	static int					    FetchRemote                         ( lua_State* luaVM );

		// Event functions
		static bool					    AddEvent							( lua_State* pLuaVM, const char* szName, bool bAllowRemoteTrigger );
		static bool					    AddEventHandler						( lua_State* pLuaVM, const char* szName, PVOID pUserData, lua_CFunction iLuaFunction, bool bPropagated, const char* szEventPriority );
		static bool					    RemoveEventHandler					( lua_State* pLuaVM, const char* szName, PVOID pUserData, lua_CFunction iLuaFunction );
	//	static bool					    GetEventHandlers					( lua_State* pLuaVM, const char* szName );
		static bool					    TriggerEvent						( lua_State* pLuaVM, const char* szName, PVOID pUserData, LuaArguments& Arguments );
		static bool					    CancelEvent							( lua_State* pLuaVM, bool bCancel, const char* szReason );
		static bool					    WasEventCancelled					( lua_State* pLuaVM );
		static string				    GetCancelReason						( lua_State* pLuaVM );

		static bool					    TriggerClientEvent					( lua_State* pLuaVM, PVOID pSendTo, const char* szName, PVOID pSource, LuaArguments& Arguments );
	//	static int					    TriggerLatentClientEvent			( lua_State* pLuaVM );
	//	static int					    GetLatentEventHandles				( lua_State* pLuaVM );
	//	static int					    GetLatentEventStatus				( lua_State* pLuaVM );
	//	static int					    CancelLatentEvent					( lua_State* pLuaVM );

		// Element create/destroy
		static PVOID				    CreateElement						( lua_State* pLuaVM, const char* szTypeName, const char* szID );
		static bool					    DestroyElement						( lua_State* pLuaVM, PVOID pUserData );
		static PVOID				    CloneElement						( lua_State* pLuaVM, PVOID pUserData, const Math::Vector3& vecPosition, bool bCloneElement );

		// Element get funcs
		static ArgumentsVector	        GetElementsByType					( lua_State* pLuaVM, const char* szTypeName, PVOID pUserData = nullptr );
		static bool					    IsElement							( lua_State* pLuaVM, PVOID pUserData );
		static string				    GetElementType						( lua_State* pLuaVM, PVOID pUserData );
		static PVOID				    GetElementByID						( lua_State* pLuaVM, const char* szID, unsigned int uiIndex );
		static PVOID				    GetElementByIndex					( lua_State* pLuaVM, int iIndex );
		static PVOID				    GetElementChild						( lua_State* pLuaVM, PVOID pUserData, int iIndex );
		static int					    GetElementChildrenCount				( lua_State* pLuaVM, PVOID pUserData );
		static string				    GetElementID						( lua_State* pLuaVM, PVOID pUserData );
		static LuaArgument			    GetElementData						( lua_State* pLuaVM, PVOID pUserData, string sKey, bool bInherit = true );
		static LuaArguments		        GetAllElementData					( lua_State* pLuaVM, PVOID pUserData );
		static PVOID				    GetElementParent					( lua_State* pLuaVM, PVOID pUserData );
		static bool					    GetElementPosition					( lua_State* pLuaVM, PVOID pUserData, Math::Vector3& vecPosition );
		static bool					    GetElementRotation					( lua_State* pLuaVM, PVOID pUserData, Math::Vector3& vecRotation );
		static bool					    GetElementVelocity					( lua_State* pLuaVM, PVOID pUserData, Math::Vector3& vecVelocity );
		static bool					    GetElementInterior					( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucInterior );
		static bool					    IsElementWithinColShape				( lua_State* pLuaVM, PVOID pUserData, bool& bWithin );
		static bool					    IsElementWithinMarker				( lua_State* pLuaVM, PVOID pUserData, bool& bWithin );
		static bool					    GetElementDimension					( lua_State* pLuaVM, PVOID pUserData, unsigned short& usDimension );
		static bool					    GetElementZoneName					( lua_State* pLuaVM, PVOID pUserData, string& strOutName, bool bCitiesOnly = false );
		static bool					    IsElementAttached					( lua_State* pLuaVM, PVOID pUserData );
		static PVOID				    GetElementAttachedTo				( lua_State* pLuaVM, PVOID pUserData );
		static PVOID				    GetElementColShape					( lua_State* pLuaVM, PVOID pUserData );
		static bool					    GetElementAlpha						( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucAlpha );
		static bool					    IsElementDoubleSided				( lua_State* pLuaVM, PVOID pUserData, bool& bDoubleSided );
		static bool					    GetElementHealth					( lua_State* pLuaVM, PVOID pUserData, float& fHealth );
		static bool					    GetElementModel						( lua_State* pLuaVM, PVOID pUserData, unsigned short& usModel );
		static bool					    IsElementInWater					( lua_State* pLuaVM, PVOID pUserData, bool& bInWater );
		static bool					    GetElementAttachedOffsets			( lua_State* pLuaVM, PVOID pUserData, Math::Vector3& vecPosition, Math::Vector3& vecRotation );
		static PVOID				    GetElementSyncer					( lua_State* pLuaVM, PVOID pUserData );
		static bool					    GetElementCollisionsEnabled			( lua_State* pLuaVM, PVOID pUserData );
		static bool					    IsElementFrozen						( lua_State* pLuaVM, PVOID pUserData, bool& bFrozen );
		static bool					    GetLowLodElement					( lua_State* pLuaVM, PVOID pUserData, PVOID& pOutLowLodElement );
		static bool					    IsElementLowLod						( lua_State* pLuaVM, PVOID pUserData, bool& bOutLowLod );

		// Element set funcs
		static bool                     ClearElementVisibleTo               ( lua_State* pLuaVM, PVOID pUserData );
		static bool                     SetElementID                        ( lua_State* pLuaVM, PVOID pUserData, string sID );
		static bool                     SetElementData                      ( lua_State* pLuaVM, PVOID pUserData, string sKey, const LuaArgument& Variable );
		static bool                     RemoveElementData                   ( lua_State* pLuaVM, PVOID pUserData, string sKey );
		static bool                     SetElementParent                    ( lua_State* pLuaVM, PVOID pUserData, PVOID pTarget );
		static bool                     SetElementPosition                  ( lua_State* pLuaVM, PVOID pUserData, const Math::Vector3& vecPosition, bool bWarp = true );
		static bool                     SetElementRotation                  ( lua_State* pLuaVM, PVOID pUserData, const Math::Vector3& vecRotation, const char* szRotationOrder = "default", bool bNewWay = false );
		static bool                     SetElementVelocity                  ( lua_State* pLuaVM, PVOID pUserData, const Math::Vector3& vecVelocity );
		static bool                     SetElementVisibleTo                 ( lua_State* pLuaVM, PVOID pUserData, PVOID pTarget, bool bVisible );
		static bool                     SetElementInterior                  ( lua_State* pLuaVM, PVOID pUserData, int iInterior );
		static bool                     SetElementDimension                 ( lua_State* pLuaVM, PVOID pUserData, int iDimension );
		static bool                     AttachElements                      ( lua_State* pLuaVM, PVOID pUserData, PVOID pTarget, Math::Vector3& vecPosition, Math::Vector3& vecRotation );
		static bool                     DetachElements                      ( lua_State* pLuaVM, PVOID pUserData, PVOID pTarget = NULL );
		static bool                     SetElementAlpha                     ( lua_State* pLuaVM, PVOID pUserData, int iAlpha );
		static bool                     SetElementDoubleSided               ( lua_State* pLuaVM, PVOID pUserData, bool bDoubleSided );
		static bool                     SetElementHealth                    ( lua_State* pLuaVM, PVOID pUserData, float fHealth );
		static bool                     SetElementModel                     ( lua_State* pLuaVM, PVOID pUserData, int iModel );
		static bool                     SetElementAttachedOffsets           ( lua_State* pLuaVM, PVOID pUserData, Math::Vector3& vecPosition, Math::Vector3& vecRotation );
		static bool                     SetElementSyncer                    ( lua_State* pLuaVM, PVOID pUserData, PVOID pPlayer );
		static bool                     SetElementCollisionsEnabled         ( lua_State* pLuaVM, PVOID pUserData, bool bEnabled );
		static bool                     SetElementFrozen                    ( lua_State* pLuaVM, PVOID pUserData, bool bFrozen );
		static bool                     SetLowLodElement                    ( lua_State* pLuaVM, PVOID pUserData, bool bEnabled );

		// Player get functions
		static unsigned int			    GetPlayerCount                      ( lua_State* pLuaVM );
		static PVOID                    GetPlayerFromName                   ( lua_State* pLuaVM, const char* szNick );
		static bool					    GetPlayerPing                       ( lua_State* pLuaVM, PVOID pUserData, unsigned int& uiPing );
		static bool					    GetPlayerMoney                      ( lua_State* pLuaVM, PVOID pUserData, long& lMoney );
		static PVOID                    GetRandomPlayer                     ( lua_State* pLuaVM );
		static bool                     IsPlayerMuted                       ( lua_State* pLuaVM, PVOID pUserData, bool& bMuted );
		static PVOID                    GetPlayerTeam                       ( lua_State* pLuaVM, PVOID pUserData );
		static bool					    GetPlayerWantedLevel                ( lua_State* pLuaVM, PVOID pUserData, unsigned int& uiWantedLevel );
		static ArgumentsVector	        GetAlivePlayers                     ( lua_State* pLuaVM );
		static ArgumentsVector	        GetDeadPlayers                      ( lua_State* pLuaVM );
		static bool					    GetPlayerIdleTime                   ( lua_State* pLuaVM, PVOID pUserData, unsigned int& uiIdleTime );
		static bool					    IsPlayerMapForced                   ( lua_State* pLuaVM, PVOID pUserData, bool& bForced );
		static bool					    GetPlayerNametagText                ( lua_State* pLuaVM, PVOID pUserData, string& strOutText );
		static bool					    GetPlayerNametagColor               ( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucR, unsigned char& ucG, unsigned char& ucB );
		static bool					    IsPlayerNametagShowing              ( lua_State* pLuaVM, PVOID pUserData, bool& bShowing );
		static string                   GetPlayerSerial                     ( lua_State* pLuaVM, PVOID pUserData );
		static string                   GetPlayerUserName                   ( lua_State* pLuaVM, PVOID pUserData );
		static bool					    GetPlayerBlurLevel                  ( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucLevel );
		static bool					    GetPlayerName                       ( lua_State* pLuaVM, PVOID pUserData, string& strOutName );
		static bool					    GetPlayerIP                         ( lua_State* pLuaVM, PVOID pUserData, string& strOutIP );
		static PVOID                    GetPlayerAccount                    ( lua_State* pLuaVM, PVOID pUserData );
		static string                   GetPlayerVersion                    ( lua_State* pLuaVM, PVOID pUserData );
		static ArgumentsMap		        GetPlayerACInfo						( lua_State* pLuaVM, PVOID pUserData );

		// Player set functions
		static bool					    SetPlayerMoney                      ( lua_State* pLuaVM, PVOID pUserData, int iAmount, bool bInstant = false );
		static bool					    GivePlayerMoney                     ( lua_State* pLuaVM, PVOID pUserData, int iAmount );
		static bool					    TakePlayerMoney                     ( lua_State* pLuaVM, PVOID pUserData, int iAmount );
		static bool					    SpawnPlayer                         ( lua_State* pLuaVM, PVOID pUserData, Math::Vector3& vecPosition, int iRotation = 0, int iSkinID = 0, int iInterior = 0, int iDimension = 0, PVOID theTeam = NULL );
		static bool					    ShowPlayerHudComponent              ( lua_State* pLuaVM, PVOID pUserData, string sComponent, bool bShow );
		static bool					    SetPlayerWantedLevel                ( lua_State* pLuaVM, PVOID pUserData, int iLevel );
		static bool					    ForcePlayerMap                      ( lua_State* pLuaVM, PVOID pUserData, bool bForceOn );
		static bool					    SetPlayerNametagText                ( lua_State* pLuaVM, PVOID pUserData, string sText );
		static bool					    SetPlayerNametagColor               ( lua_State* pLuaVM, PVOID pUserData, int iRed = 0, int iGreen = 0, int iBlue = 0 );
		static bool					    SetPlayerNametagShowing             ( lua_State* pLuaVM, PVOID pUserData, bool bShowing );
		static bool					    SetPlayerMuted                      ( lua_State* pLuaVM, PVOID pUserData, bool bMuted );
		static bool					    SetPlayerBlurLevel                  ( lua_State* pLuaVM, PVOID pUserData, int iLevel );
		static bool					    RedirectPlayer                      ( lua_State* pLuaVM, PVOID pUserData, const char* szServerIP, int iServerPort, const char* szServerPassword );
		static bool					    SetPlayerName                       ( lua_State* pLuaVM, PVOID pUserData, string sName );
		static bool					    DetonateSatchels                    ( lua_State* pLuaVM, PVOID pUserData );
		static bool					    TakePlayerScreenShot                ( lua_State* pLuaVM, PVOID pUserData, int iWidth, int iHeight, string sTag = "", int iQuality = 30, int iMaxBandwith = 5000 );

		// Ped get functions
		static PVOID				    CreatePed                           ( lua_State* pLuaVM, int iModelid, const Math::Vector3& vecPosition, float fRot = 0.0, bool bSynced = true );
		static bool					    GetPedArmor                         ( lua_State* pLuaVM, PVOID pUserData, float& fArmor );    
		static bool					    IsPedChoking                        ( lua_State* pLuaVM, PVOID pUserData, bool& bIsChoking );
		static bool					    IsPedDead                           ( lua_State* pLuaVM, PVOID pUserData, bool& bDead );
		static bool					    IsPedDucked                         ( lua_State* pLuaVM, PVOID pUserData, bool& bDucked );    
		static bool					    GetPedStat                          ( lua_State* pLuaVM, PVOID pUserData, unsigned short usStat, float& fValue );
		static PVOID				    GetPedTarget                        ( lua_State* pLuaVM, PVOID pUserData );    
		static int					    GetPedWeapon                        ( lua_State* pLuaVM, PVOID pUserData, int iWeaponSlot = -1 );
		static bool					    GetPedClothes                       ( lua_State* pLuaVM, PVOID pUserData, unsigned char ucType, string& strOutTexture, string& strOutModel );
		static bool					    DoesPedHaveJetPack                  ( lua_State* pLuaVM, PVOID pUserData, bool& bHasJetPack );
		static bool					    IsPedOnGround                       ( lua_State* pLuaVM, PVOID pUserData, bool& bOnGround );    
		static bool					    GetPedFightingStyle                 ( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucStyle );
		static bool					    GetPedMoveAnim                      ( lua_State* pLuaVM, PVOID pUserData, unsigned int& iMoveAnim );
		static bool					    GetPedGravity                       ( lua_State* pLuaVM, PVOID pUserData, float& fGravity );    
		static PVOID				    GetPedContactElement                ( lua_State* pLuaVM, PVOID pUserData );
		static bool					    GetPedWeaponSlot                    ( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucWeaponSlot );
		static bool					    IsPedDoingGangDriveby               ( lua_State* pLuaVM, PVOID pUserData, bool & bDoingGangDriveby );
		static bool					    IsPedOnFire                         ( lua_State* pLuaVM, PVOID pUserData, bool & bIsOnFire );
		static bool					    IsPedHeadless                       ( lua_State* pLuaVM, PVOID pUserData, bool & bIsHeadless );
		static bool					    IsPedFrozen                         ( lua_State* pLuaVM, PVOID pUserData, bool & bIsFrozen );
		static PVOID				    GetPedOccupiedVehicle               ( lua_State* pLuaVM, PVOID pUserData );
		static bool					    GetPedOccupiedVehicleSeat           ( lua_State* pLuaVM, PVOID pUserData, unsigned int& uiSeat );
		static bool					    IsPedInVehicle                      ( lua_State* pLuaVM, PVOID pUserData, bool & bIsInVehicle );
		static bool					    GetWeaponProperty                   ( lua_State* pLuaVM, unsigned char ucWeaponID, const char* szWeaponSkill, const char* szProperty, short& uData );
		static bool					    GetOriginalWeaponProperty           ( lua_State* pLuaVM, unsigned char ucWeaponID, const char *szWeaponSkill, const char* szProperty, short& uData );

		// Ped set functions
		static bool                     SetPedArmor                         ( lua_State* pLuaVM, PVOID pUserData, float fArmor );
		static bool                     KillPed                             ( lua_State* pLuaVM, PVOID pUserData, PVOID pKiller = NULL, unsigned char ucKillerWeapon = 0xFF, unsigned char ucBodyPart = 0xFF, bool bStealth = false );
		static bool                     SetPedStat                          ( lua_State* pLuaVM, PVOID pUserData, unsigned short usStat, float fValue );
		static bool                     AddPedClothes                       ( lua_State* pLuaVM, PVOID pUserData, const char* szTexture, const char* szModel, unsigned char ucType );
		static bool                     RemovePedClothes                    ( lua_State* pLuaVM, PVOID pUserData, unsigned char ucType, const char* szTexture = NULL, const char* szModel = NULL );
		static bool                     GivePedJetPack                      ( lua_State* pLuaVM, PVOID pUserData );
		static bool                     RemovePedJetPack                    ( lua_State* pLuaVM, PVOID pUserData );
		static bool                     SetPedFightingStyle                 ( lua_State* pLuaVM, PVOID pUserData, unsigned char ucStyle );
		static bool                     SetPedMoveAnim                      ( lua_State* pLuaVM, PVOID pUserData, unsigned int iMoveAnim );
		static bool                     SetPedGravity                       ( lua_State* pLuaVM, PVOID pUserData, float fGravity );
		static bool                     SetPedChoking                       ( lua_State* pLuaVM, PVOID pUserData, bool bChoking );
		static bool                     SetPedWeaponSlot                    ( lua_State* pLuaVM, PVOID pUserData, unsigned char ucWeaponSlot );
		static bool                     WarpPedIntoVehicle                  ( lua_State* pLuaVM, PVOID pUserData, PVOID pVehicle, unsigned int uiSeat = 0 );
		static bool                     RemovePedFromVehicle                ( lua_State* pLuaVM, PVOID pUserData );
		static bool                     SetPedDoingGangDriveby              ( lua_State* pLuaVM, PVOID pUserData, bool bGangDriveby );
		static bool                     SetPedAnimation                     ( lua_State* pLuaVM, PVOID pUserData, const char * szBlockName, const char * szAnimName, int iTime, bool bLoop, bool bUpdatePosition, bool bInterruptable, bool bFreezeLastFrame );
		static bool                     SetPedAnimationProgress             ( lua_State* pLuaVM, PVOID pUserData, const char * szAnimName, float fProgress );
		static bool                     SetPedOnFire                        ( lua_State* pLuaVM, PVOID pUserData, bool bIsOnFire );
		static bool                     SetPedHeadless                      ( lua_State* pLuaVM, PVOID pUserData, bool bIsHeadless );
		static bool                     SetPedFrozen                        ( lua_State* pLuaVM, PVOID pUserData, bool bIsFrozen );
		static bool                     ReloadPedWeapon                     ( lua_State* pLuaVM, PVOID pUserData );
		static bool					    SetWeaponProperty                   ( lua_State* pLuaVM, unsigned char ucWeaponID, const char *szWeaponSkill, const char* szProperty, short uData );

		// Weapon give/take functions
	 // static int                      GiveWeapon                          ( lua_State* pLuaVM );
	 // static int                      TakeWeapon                          ( lua_State* pLuaVM );
	 // static int                      TakeAllWeapons                      ( lua_State* pLuaVM );
	 // static int                      SetWeaponAmmo                       ( lua_State* pLuaVM );
	 // static int                      GetSlotFromWeapon                   ( lua_State* pLuaVM );

		// Vehicle create/destroy functions
		static PVOID					CreateVehicle					( lua_State* pLuaVM, int model, float fX, float fY, float fZ, float fRX, float fRY, float fRZ, string numberplate, bool direction = false, int variant1 = 255, int variant2 = 255 );

		// Vehicle get functions
		static bool						GetVehicleType					( lua_State* pLuaVM, PVOID pUserData, string& strType );
		static bool						GetVehicleVariant               ( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucVariant, unsigned char& ucVariant2 );
		static bool						GetVehicleColor					( lua_State* pLuaVM, PVOID pUserData, SharedUtil::VehicleColor& color );
		static bool						GetVehicleModelFromName			( lua_State* pLuaVM, const char* szName, unsigned short& usID );
		static bool						GetVehicleLandingGearDown		( lua_State* pLuaVM, PVOID pUserData, bool& bGearDown );
		static bool						GetVehicleMaxPassengers			( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucMaxPassengers );
		static bool						GetVehicleName                  ( lua_State* pLuaVM, PVOID pUserData, string& strOutName );
		static bool						GetVehicleNameFromModel         ( lua_State* pLuaVM, unsigned short usModel, string& strOutName );
		static PVOID					GetVehicleOccupant              ( lua_State* pLuaVM, PVOID pUserData, unsigned int uiSeat );
		static ArgumentsVector		    GetVehicleOccupants             ( lua_State* pLuaVM, PVOID pUserData );
		static PVOID					GetVehicleController            ( lua_State* pLuaVM, PVOID pUserData );
		static bool						GetVehicleSirensOn              ( lua_State* pLuaVM, PVOID pUserData, bool& bSirensOn );
		static bool						GetVehicleTurnVelocity          ( lua_State* pLuaVM, PVOID pUserData, Math::Vector3& vecTurnVelocity );
		static bool						GetVehicleTurretPosition        ( lua_State* pLuaVM, PVOID pUserData, Math::Vector2& vecPosition );
		static bool						IsVehicleLocked                 ( lua_State* pLuaVM, PVOID pUserData, bool& bLocked );
		static ArgumentsVector		    GetVehiclesOfType               ( lua_State* pLuaVM, unsigned int uiModel );       
		static bool						GetVehicleUpgradeOnSlot         ( lua_State* pLuaVM, PVOID pUserData, unsigned char ucSlot, unsigned short& usUpgrade );
		static ArgumentsVector		    GetVehicleUpgrades              ( lua_State* pLuaVM, PVOID pUserData );
		static bool						GetVehicleUpgradeSlotName       ( lua_State* pLuaVM, unsigned char ucSlot, string& strOutName );
		static bool						GetVehicleUpgradeSlotName       ( lua_State* pLuaVM, unsigned short usUpgrade, string& strOutName );
		static ArgumentsVector		    GetVehicleCompatibleUpgrades    ( lua_State* pLuaVM, PVOID pUserData );
		static bool						GetVehicleDoorState             ( lua_State* pLuaVM, PVOID pUserData, unsigned char ucDoor, unsigned char& ucState );
		static bool						GetVehicleWheelStates           ( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucFrontLeft, unsigned char& ucRearLeft, unsigned char& ucFrontRight, unsigned char& ucRearRight );
		static bool						GetVehicleLightState            ( lua_State* pLuaVM, PVOID pUserData, unsigned char ucLight, unsigned char& ucState );
		static bool						GetVehiclePanelState            ( lua_State* pLuaVM, PVOID pUserData, unsigned char ucPanel, unsigned char& ucState );
		static bool						GetVehicleOverrideLights        ( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucLights );
		static PVOID					GetVehicleTowedByVehicle        ( lua_State* pLuaVM, PVOID pUserData );
		static PVOID					GetVehicleTowingVehicle         ( lua_State* pLuaVM, PVOID pUserData );
		static bool						GetVehiclePaintjob              ( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucPaintjob );
		static bool						GetVehiclePlateText             ( lua_State* pLuaVM, PVOID pUserData, char* szPlateText );
		static bool						IsVehicleDamageProof            ( lua_State* pLuaVM, PVOID pUserData, bool& bDamageProof );
		static bool						IsVehicleFuelTankExplodable     ( lua_State* pLuaVM, PVOID pUserData, bool& bExplodable );
		static bool						IsVehicleFrozen                 ( lua_State* pLuaVM, PVOID pUserData, bool& bFrozen );
		static bool						IsVehicleOnGround               ( lua_State* pLuaVM, PVOID pUserData, bool& bOnGround );
		static bool						GetVehicleEngineState           ( lua_State* pLuaVM, PVOID pUserData, bool& bState );
		static bool						IsTrainDerailed                 ( lua_State* pLuaVM, PVOID pUserData, bool& bDerailed );
		static bool						IsTrainDerailable               ( lua_State* pLuaVM, PVOID pUserData, bool& bDerailable );
		static bool						GetTrainDirection               ( lua_State* pLuaVM, PVOID pUserData, bool& bDirection );
		static bool						GetTrainSpeed                   ( lua_State* pLuaVM, PVOID pUserData, float& fSpeed );
		static bool						IsVehicleBlown                  ( lua_State* pLuaVM, PVOID pUserData );
		static bool						GetVehicleHeadLightColor        ( lua_State* pLuaVM, PVOID pUserData, SharedUtil::Color& outColor );
		static bool						GetVehicleDoorOpenRatio         ( lua_State* pLuaVM, PVOID pUserData, unsigned char ucDoor, float& fRatio );
		static bool						IsVehicleTaxiLightOn            ( lua_State* pLuaVM, PVOID pUserData, bool& bLightOn );

		// Vehicle set functions
		static bool						FixVehicle						( lua_State* pLuaVM, PVOID pUserData );
		static bool						BlowVehicle						( lua_State* pLuaVM, PVOID pUserData, bool bExplode );
		static bool						SetVehicleTurnVelocity			( lua_State* pLuaVM, PVOID pUserData, float fX, float fY, float fZ );
		static bool						SetVehicleColor					( lua_State* pLuaVM, PVOID pUserData, unsigned char ucRed, unsigned char ucGreen, unsigned char ucBlue, unsigned char ucRed2, unsigned char ucGreen2, unsigned char ucBlue2, unsigned char ucRed3, unsigned char ucGreen3, unsigned char ucBlue3, unsigned char ucRed4, unsigned char ucGreen4, unsigned char ucBlue4 );
		static bool						SetVehicleLandingGearDown       ( lua_State* pLuaVM, PVOID pUserData, bool bLandingGearDown );
		static bool						SetVehicleLocked                ( lua_State* pLuaVM, PVOID pUserData, bool bLocked );
		static bool						SetVehicleDoorsUndamageable     ( lua_State* pLuaVM, PVOID pUserData, bool bDoorsUndamageable );
		static bool						SetVehicleSirensOn              ( lua_State* pLuaVM, PVOID pUserData, bool bSirensOn );
		static bool						SetVehicleTaxiLightOn           ( lua_State* pLuaVM, PVOID pUserData, bool bTaxiLightState );
		static bool						AddVehicleUpgrade               ( lua_State* pLuaVM, PVOID pUserData, unsigned short usUpgrade );
		static bool						RemoveVehicleUpgrade            ( lua_State* pLuaVM, PVOID pUserData, unsigned short usUpgrade );
		static bool						SetVehicleDoorState             ( lua_State* pLuaVM, PVOID pUserData, unsigned char ucDoor, unsigned char ucState );
		static bool						SetVehicleWheelStates           ( lua_State* pLuaVM, PVOID pUserData, int iFrontLeft, int iRearLeft = -1, int iFrontRight = -1, int iRearRight = -1 );
		static bool						SetVehicleLightState            ( lua_State* pLuaVM, PVOID pUserData, unsigned char ucLight, unsigned char ucState );
		static bool						SetVehiclePanelState            ( lua_State* pLuaVM, PVOID pUserData, unsigned char ucPanel, unsigned char ucState );
		static bool						SetVehicleIdleRespawnDelay      ( lua_State* pLuaVM, PVOID pUserData, unsigned long ulTime );
		static bool						SetVehicleRespawnDelay          ( lua_State* pLuaVM, PVOID pUserData, unsigned long ulTime );
		static bool						SetVehicleRespawnPosition       ( lua_State* pLuaVM, PVOID pUserData, float fX, float fY, float fZ, float fRX, float fRY, float fRZ );
		static bool						ToggleVehicleRespawn            ( lua_State* pLuaVM, PVOID pUserData, bool bRespawn );
		static bool						ResetVehicleExplosionTime       ( lua_State* pLuaVM, PVOID pUserData );
		static bool						ResetVehicleIdleTime            ( lua_State* pLuaVM, PVOID pUserData );
		static bool						SpawnVehicle                    ( lua_State* pLuaVM, PVOID pUserData, float fX, float fY, float fZ, float fRX, float fRY, float fRZ );
		static bool						RespawnVehicle                  ( lua_State* pLuaVM, PVOID pUserData );
		static bool						SetVehicleOverrideLights        ( lua_State* pLuaVM, PVOID pUserData, unsigned char ucLights );
		static bool						AttachTrailerToVehicle          ( lua_State* pLuaVM, PVOID pUserData, PVOID pTrailer );
		static bool						DetachTrailerFromVehicle        ( lua_State* pLuaVM, PVOID pUserData, PVOID pTrailer = NULL );
		static bool						SetVehicleEngineState           ( lua_State* pLuaVM, PVOID pUserData, bool bState );
		static bool						SetVehicleDirtLevel             ( lua_State* pLuaVM, PVOID pUserData, float fDirtLevel );
		static bool						SetVehicleDamageProof           ( lua_State* pLuaVM, PVOID pUserData, bool bDamageProof );
		static bool						SetVehiclePaintjob              ( lua_State* pLuaVM, PVOID pUserData, unsigned char ucPaintjob );
		static bool						SetVehicleFuelTankExplodable    ( lua_State* pLuaVM, PVOID pUserData, bool bExplodable );
		static bool						SetVehicleFrozen                ( lua_State* pLuaVM, PVOID pUserData, bool bFrozen );
		static bool						SetTrainDerailed                ( lua_State* pLuaVM, PVOID pUserData, bool bDerailed );
		static bool						SetTrainDerailable              ( lua_State* pLuaVM, PVOID pUserData, bool bDerailable );
		static bool						SetTrainDirection               ( lua_State* pLuaVM, PVOID pUserData, bool bDireciton );
		static bool						SetTrainSpeed                   ( lua_State* pLuaVM, PVOID pUserData, float fSpeed );
		static bool						SetVehicleHeadLightColor        ( lua_State* pLuaVM, PVOID pUserData, unsigned char ucRed, unsigned char ucGreen, unsigned char ucBlue );
		static bool						SetVehicleTurretPosition        ( lua_State* pLuaVM, PVOID pUserData, float fHorizontal, float fVertical );
		static bool						SetVehicleDoorOpenRatio         ( lua_State* pLuaVM, PVOID pUserData, unsigned char ucDoor, float fRatio, unsigned long ulTime = 0 );
		static bool						SetVehicleVariant               ( lua_State* pLuaVM, PVOID pUserData, unsigned char ucVariant, unsigned char ucVariant2 );
		static bool						GiveVehicleSirens               ( lua_State* pLuaVM, PVOID pUserData, unsigned char ucSirenType, unsigned char ucSirenCount, bool bFlag360 = false, bool bCheckLosFlag = true, bool bUseRandomiserFlag = true, bool bSilentFlag = false );
		static bool						RemoveVehicleSirens             ( lua_State* pLuaVM, PVOID pUserData );
		static bool						SetVehicleSirens                ( lua_State* pLuaVM, PVOID pUserData, unsigned char ucSirenID, float fX, float fY, float fZ, float fRed, float fGreen, float fBlue, float fAlpha = 255, float fMinAlpha = 0.0 );
	//	static bool						GetVehicleSirens                ( lua_State* pLuaVM, PVOID pUserData );
	//	static bool						GetVehicleSirenParams           ( lua_State* pLuaVM, PVOID pUserData );
		static bool						SetVehiclePlateText             ( lua_State* pLuaVM, PVOID pUserData, const char* szName );

		// Marker create/destroy functions
		static PVOID					CreateMarker					( lua_State* pLuaVM, const Math::Vector3& vecPosition, const char* szType, float fSize, const SharedUtil::Color color, PVOID pVisibleTo );

		// Marker get functions
		static bool						GetMarkerCount					( lua_State* pLuaVM, unsigned int& uiCount );
		static bool						GetMarkerType					( lua_State* pLuaVM, PVOID pUserData, char* szType );
		static bool						GetMarkerSize					( lua_State* pLuaVM, PVOID pUserData, float& fSize );
		static bool						GetMarkerColor					( lua_State* pLuaVM, PVOID pUserData, SharedUtil::Color& outColor );
		static bool						GetMarkerTarget					( lua_State* pLuaVM, PVOID pUserData, Math::Vector3& vecTarget );
		static bool						GetMarkerIcon					( lua_State* pLuaVM, PVOID pUserData, char* szIcon );

		// Marker set functions
		static bool						SetMarkerType					( lua_State* pLuaVM, PVOID pUserData, const char* szType );
		static bool						SetMarkerSize					( lua_State* pLuaVM, PVOID pUserData, float fSize );
		static bool						SetMarkerColor					( lua_State* pLuaVM, PVOID pUserData, const SharedUtil::Color color );
		static bool						SetMarkerTarget					( lua_State* pLuaVM, PVOID pUserData, const Math::Vector3& pTarget );
		static bool						SetMarkerIcon					( lua_State* pLuaVM, PVOID pUserData, const char* szIcon );

		// Blip create/destroy functions
		static PVOID					CreateBlip						( lua_State* pLuaVM, const Math::Vector3& vecPosition, unsigned char ucIcon, unsigned char ucSize, const SharedUtil::Color color, short sOrdering, unsigned short usVisibleDistance, PVOID pVisibleTo = NULL );
		static PVOID					CreateBlipAttachedTo			( lua_State* pLuaVM, PVOID pTarget, unsigned char ucIcon, unsigned char ucSize, const SharedUtil::Color color, short sOrdering, unsigned short usVisibleDistance, PVOID pVisibleTo = NULL );
    
		// Blip get functions
		static bool						GetBlipIcon						( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucIcon );
		static bool						GetBlipSize						( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucSize );
		static bool						GetBlipColor					( lua_State* pLuaVM, PVOID pUserData, SharedUtil::Color& outColor );
		static bool						GetBlipOrdering					( lua_State* pLuaVM, PVOID pUserData, short& sOrdering );
		static bool						GetBlipVisibleDistance			( lua_State* pLuaVM, PVOID pUserData, unsigned short& usVisibleDistance );

		// Blip set functions
		static bool						SetBlipIcon						( lua_State* pLuaVM, PVOID pUserData, unsigned char ucIcon );
		static bool						SetBlipSize						( lua_State* pLuaVM, PVOID pUserData, unsigned char ucSize );
		static bool						SetBlipColor					( lua_State* pLuaVM, PVOID pUserData, const SharedUtil::Color color );
		static bool						SetBlipOrdering					( lua_State* pLuaVM, PVOID pUserData, short sOrdering );
		static bool						SetBlipVisibleDistance			( lua_State* pLuaVM, PVOID pUserData, unsigned short usVisibleDistance );

		// Object create/destroy functions
		static PVOID					CreateObject					( lua_State* pLuaVM, unsigned short usModelID, const Math::Vector3& vecPosition, const Math::Vector3& vecRotation, bool bIsLowLod );

		// Object get functions
		static bool						GetObjectScale					( lua_State* pLuaVM, PVOID pUserData, Math::Vector3& vecScale );

		// Object set functions
		static bool						SetObjectScale					( lua_State* pLuaVM, PVOID pUserData, const Math::Vector3& vecScale );
		static bool						MoveObject						( lua_State* pLuaVM, PVOID pUserData, unsigned long ulTime, const Math::Vector3& vecPosition, const Math::Vector3& vecRotation, const char* szEasingType, float fEasingPeriod, float fEasingAmplitude, float fEasingOvershoot );
		static bool						StopObject						( lua_State* pLuaVM, PVOID pUserData );

		// Radar area create/destroy funcs
		static PVOID					CreateRadarArea					( lua_State* pLuaVM, const Math::Vector2& vecPosition, const Math::Vector2& vecSize, const SharedUtil::Color color, PVOID pVisibleTo = NULL );

		// Radar area get funcs
		static bool						GetRadarAreaSize				( lua_State* pLuaVM, PVOID pUserData, Math::Vector2& vecSize );
		static bool						GetRadarAreaColor				( lua_State* pLuaVM, PVOID pUserData, SharedUtil::Color& outColor );
		static bool						IsRadarAreaFlashing				( lua_State* pLuaVM, PVOID pUserData );
		static bool						IsInsideRadarArea				( lua_State* pLuaVM, PVOID pUserData, const Math::Vector2& vecPosition, bool& bInside );

		// Radar area set funcs
		static bool						SetRadarAreaSize				( lua_State* pLuaVM, PVOID pUserData, const Math::Vector2& vecSize );
		static bool						SetRadarAreaColor				( lua_State* pLuaVM, PVOID pUserData, const SharedUtil::Color color );
		static bool						SetRadarAreaFlashing			( lua_State* pLuaVM, PVOID pUserData, bool bFlashing );
	
		// Pickup create/destroy funcs
		static PVOID					CreatePickup					( lua_State* pLuaVM, const Math::Vector3& vecPosition, unsigned char ucType, double dFive, unsigned long ulRespawnInterval = 30000, double dSix = 50 );

		// Pickup get funcs
		static bool						GetPickupType					( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucType );
		static bool						GetPickupWeapon					( lua_State* pLuaVM, PVOID pUserData, unsigned char& ucWeapon );
		static bool						GetPickupAmount					( lua_State* pLuaVM, PVOID pUserData, float& fAmount );
		static bool						GetPickupAmmo					( lua_State* pLuaVM, PVOID pUserData, unsigned short& ucAmmo );
		static bool						GetPickupRespawnInterval		( lua_State* pLuaVM, PVOID pUserData, unsigned long& ulInterval );
		static bool						IsPickupSpawned					( lua_State* pLuaVM, PVOID pUserData, bool& bSpawned );

		// Pickup set funcs
		static bool						SetPickupType					( lua_State* pLuaVM, PVOID pUserData, unsigned char ucType, double dThree, double dFour );
		static bool						SetPickupRespawnInterval		( lua_State* pLuaVM, PVOID pUserData, unsigned long ulInterval );
		static bool						UsePickup						( lua_State* pLuaVM, PVOID pUserData, PVOID pPlayer );

		// Shape create funcs
		static PVOID					CreateColCircle                 ( lua_State* pLuaVM, const Math::Vector2& vecPosition, float fRadius );
		static PVOID					CreateColCuboid                 ( lua_State* pLuaVM, const Math::Vector3& vecPosition, const Math::Vector3& vecSize );
		static PVOID					CreateColSphere                 ( lua_State* pLuaVM, const Math::Vector3& vecPosition, float fRadius );
		static PVOID					CreateColRectangle              ( lua_State* pLuaVM, const Math::Vector2& vecPosition, const Math::Vector2& vecSize );
		static PVOID					CreateColPolygon                ( lua_State* pLuaVM, const vector< Math::Vector2 >& vecPointList );
		static PVOID					CreateColTube                   ( lua_State* pLuaVM, const Math::Vector3& vecPosition, float fRadius, float fHeight );

		// Explosion funcs
		static bool						CreateExplosion					( lua_State* pLuaVM, const Math::Vector3& vecPosition, unsigned char ucType, PVOID pCreator = NULL );

		// Fire funcs
	//	static int						CreateFire						( lua_State* pLuaVM );

		// Audio funcs
		static bool						PlaySoundFrontEnd				( lua_State* pLuaVM, PVOID pElement, unsigned char ucSound );
		static bool						PlayMissionAudio				( lua_State* pLuaVM, PVOID pElement, Math::Vector3& vecPosition, unsigned short usSlot );

		// Ped body?
		static bool						GetBodyPartName					( lua_State* pLuaVM, unsigned char ucID, char* szName );
		static bool						GetClothesByTypeIndex			( lua_State* pLuaVM, unsigned char ucType, unsigned char ucIndex, char* szTextureReturn, char* szModelReturn );
		static bool						GetTypeIndexFromClothes			( lua_State* pLuaVM, const char* szTexture, const char* szModel, unsigned char& ucTypeReturn, unsigned char& ucIndexReturn );
		static bool						GetClothesTypeName				( lua_State* pLuaVM, unsigned char ucType, char* szNameReturn );

		// Input funcs
	//	static bool						BindKey							( lua_State* pLuaVM, PVOID pPlayer, const char* szKey, const char* szHitState, const CLuaFunctionRef& iLuaFunction, CLuaArguments& Arguments );
		static bool						BindKey							( lua_State* pLuaVM, PVOID pPlayer, const char* szKey, const char* szHitState, const char* szCommandName, const char* szArguments );
	//	static bool						UnbindKey						( lua_State* pLuaVM, PVOID pPlayer, const char* szKey, const char* szHitState = NULL, const CLuaFunctionRef& iLuaFunction = CLuaFunctionRef() );
		static bool						UnbindKey						( lua_State* pLuaVM, PVOID pPlayer, const char* szKey, const char* szHitState, const char* szCommandName );
	//	static bool						IsKeyBound						( lua_State* pLuaVM, PVOID pPlayer, const char* szKey, const char* szHitState, const CLuaFunctionRef& iLuaFunction, bool& bBound );
		static bool						GetControlState					( lua_State* pLuaVM, PVOID pPlayer, const char* szControl, bool& bState );
		static bool						IsControlEnabled				( lua_State* pLuaVM, PVOID pPlayer, const char* szControl, bool& bEnabled );

		static bool						SetControlState					( lua_State* pLuaVM, PVOID pPlayer, const char* szControl, bool bState );
		static bool						ToggleControl					( lua_State* pLuaVM, PVOID pPlayer, const char* szControl, bool bEnabled );
		static bool						ToggleAllControls				( lua_State* pLuaVM, PVOID pPlayer, bool bGTAControls, bool bMTAControls, bool bEnabled );

		// Team get funcs
		static PVOID					CreateTeam						( lua_State* pLuaVM, const char* szTeamName, unsigned char ucRed, unsigned char ucGreen, unsigned char ucBlue );
		static PVOID					GetTeamFromName					( lua_State* pLuaVM, const char* szTeamName );
		static bool						GetTeamName						( lua_State* pLuaVM, PVOID pTeam, string& strOutName );
		static bool						GetTeamColor					( lua_State* pLuaVM, PVOID pTeam, unsigned char& ucRed, unsigned char& ucGreen, unsigned char& ucBlue );
		static bool						CountPlayersInTeam				( lua_State* pLuaVM, PVOID pTeam, unsigned int& uiCount );
		static bool						GetTeamFriendlyFire				( lua_State* pLuaVM, PVOID pTeam, bool& bFriendlyFire );

		// Team set funcs
		static bool						SetTeamName						( lua_State* pLuaVM, PVOID pTeam, const char* szTeamName );
		static bool						SetTeamColor					( lua_State* pLuaVM, PVOID pTeam, unsigned char ucRed, unsigned char ucGreen, unsigned char ucBlue );
		static bool						SetPlayerTeam					( lua_State* pLuaVM, PVOID pPlayer, PVOID pTeam );
		static bool						SetTeamFriendlyFire				( lua_State* pLuaVM, PVOID pTeam, bool bFriendlyFire );

		// Water funcs
		static PVOID					CreateWater						( lua_State* pLuaVM, Math::Vector3* pV1, Math::Vector3* pV2, Math::Vector3* pV3, Math::Vector3* pV4, bool bShallow );
		static bool						SetElementWaterLevel			( lua_State* pLuaVM, PVOID pWater, float fLevel );
		static bool						SetAllElementWaterLevel			( lua_State* pLuaVM, float fLevel );
		static bool						SetWorldWaterLevel				( lua_State* pLuaVM, float fLevel, bool bIncludeWorldNonSeaLevel );
		static bool						ResetWorldWaterLevel			( lua_State* pLuaVM );
		static bool						GetWaterVertexPosition			( lua_State* pLuaVM, PVOID pWater, int iVertexIndex, Math::Vector3& vecPosition );
		static bool						SetWaterVertexPosition			( lua_State* pLuaVM, PVOID pWater, int iVertexIndex, Math::Vector3& vecPosition );
		static bool						GetWaterColor					( lua_State* pLuaVM, unsigned char& ucRed, unsigned char& ucGreen, unsigned char& ucBlue, unsigned char& ucAlpha );
		static bool						SetWaterColor					( lua_State* pLuaVM, unsigned char ucRed, unsigned char ucGreen, unsigned char ucBlue, unsigned char ucAlpha );
		static bool						ResetWaterColor					( lua_State* pLuaVM );

		// Standard server functions
		static unsigned int				GetMaxPlayers                   ( lua_State* pLuaVM );
		static bool						SetMaxPlayers                   ( lua_State* pLuaVM, unsigned int uiMax );
		static bool						OutputChatBox                   ( lua_State* pLuaVM, const char* szText, PVOID pElement, unsigned char ucRed, unsigned char ucGreen, unsigned char ucBlue, bool bColorCoded );
		static bool						OutputConsole                   ( lua_State* pLuaVM, const char* szText, PVOID pElement );
		static bool						SetServerPassword               ( lua_State* pLuaVM, const string& strPassword, bool bSave );

		// General world get funcs
		static bool						GetTime                         ( lua_State* pLuaVM, unsigned char& ucHour, unsigned char& ucMinute );
		static bool						GetWeather                      ( lua_State* pLuaVM, unsigned char& ucWeather, unsigned char& ucWeatherBlendingTo );
		static bool						GetZoneName                     ( lua_State* pLuaVM, Math::Vector3& vecPosition, string& strOutName, bool bCitiesOnly = false );
		static bool						GetGravity                      ( lua_State* pLuaVM, float& fGravity );
		static bool						GetGameSpeed                    ( lua_State* pLuaVM, float& fSpeed );
		static bool						GetWaveHeight                   ( lua_State* pLuaVM, float& fHeight );
		static bool						GetFPSLimit                     ( lua_State* pLuaVM, unsigned short& usLimit );
		static bool						GetMinuteDuration               ( lua_State* pLuaVM, unsigned long& ulDuration );
		static bool						IsGarageOpen                    ( lua_State* pLuaVM, unsigned char ucGarageID, bool& bIsOpen );
		static bool						GetTrafficLightState            ( lua_State* pLuaVM, unsigned char& ucState );
		static bool						GetTrafficLightsLocked          ( lua_State* pLuaVM, bool& bLocked );
		static bool						GetJetpackMaxHeight             ( lua_State* pLuaVM, float& fMaxHeight );
		static bool						GetAircraftMaxVelocity          ( lua_State* pLuaVM, float& fVelocity );
		static bool						GetInteriorSoundsEnabled        ( lua_State* pLuaVM, bool& bEnabled );
		static bool						GetRainLevel                    ( lua_State* pLuaVM, float& fRainLevel );
		static bool						GetSunSize                      ( lua_State* pLuaVM, float& fSunSize );
		static bool						GetSunColor                     ( lua_State* pLuaVM, unsigned char& ucCoreR, unsigned char& ucCoreG, unsigned char& ucCoreB, unsigned char& ucCoronaR, unsigned char& ucCoronaG, unsigned char& ucCoronaB );
		static bool						GetWindVelocity                 ( lua_State* pLuaVM, float& fVelX, float& fVelY, float& fVelZ );
		static bool						GetFarClipDistance              ( lua_State* pLuaVM, float& fFarClip );
		static bool						GetFogDistance                  ( lua_State* pLuaVM, float& fFogDist );
		static bool						GetAircraftMaxHeight            ( lua_State* pLuaVM, float& fMaxHeight );
		static bool						GetOcclusionsEnabled            ( lua_State* pLuaVM, bool& bEnabled );
		static bool						GetMoonSize                     ( lua_State* pLuaVM, int& iSize );

		// General world set funcs
		static bool						SetTime                         ( lua_State* pLuaVM, unsigned char ucHour, unsigned char ucMinute );
		static bool						SetWeather                      ( lua_State* pLuaVM, unsigned char ucWeather );
		static bool						SetWeatherBlended               ( lua_State* pLuaVM, unsigned char ucWeather );
		static bool						SetGravity                      ( lua_State* pLuaVM, float fGravity );
		static bool						SetGameSpeed				    ( lua_State* pLuaVM, float fSpeed );
		static bool						SetWaveHeight                   ( lua_State* pLuaVM, float fHeight );
		static bool						GetSkyGradient                  ( lua_State* pLuaVM, unsigned char& ucTopRed, unsigned char& ucTopGreen, unsigned char& ucTopBlue, unsigned char& ucBottomRed, unsigned char& ucBottomGreen, unsigned char& ucBottomBlue );
		static bool						SetSkyGradient                  ( lua_State* pLuaVM, unsigned char ucTopRed, unsigned char ucTopGreen, unsigned char ucTopBlue, unsigned char ucBottomRed, unsigned char ucBottomGreen, unsigned char ucBottomBlue );
		static bool						ResetSkyGradient                ( lua_State* pLuaVM );
		static bool						GetHeatHaze                     ( lua_State* pLuaVM, SharedUtil::HeatHazeSettings& heatHazeSettings );
		static bool						SetHeatHaze                     ( lua_State* pLuaVM, const SharedUtil::HeatHazeSettings& heatHazeSettings );
		static bool						ResetHeatHaze                   ( lua_State* pLuaVM );
		static bool						SetFPSLimit                     ( lua_State* pLuaVM, unsigned short usLimit, bool bSave );
		static bool						SetMinuteDuration               ( lua_State* pLuaVM, unsigned long ulDuration );
		static bool						SetGarageOpen                   ( lua_State* pLuaVM, unsigned char ucGarageID, bool bIsOpen );
		static bool						SetGlitchEnabled                ( lua_State* pLuaVM, const string& strGlitchName, bool bEnabled );
		static bool						IsGlitchEnabled                 ( lua_State* pLuaVM, const string& strGlitchName );
		static bool						GetJetpackWeaponEnabled         ( lua_State* pLuaVM, SharedUtil::WeaponType weaponType );
		static bool						SetJetpackWeaponEnabled         ( lua_State* pLuaVM, SharedUtil::WeaponType weaponType, bool bEnabled );
		static bool						SetCloudsEnabled                ( lua_State* pLuaVM, bool bEnabled );
		static bool						GetCloudsEnabled                ( lua_State* pLuaVM );
		static bool						SetTrafficLightState            ( lua_State* pLuaVM, unsigned char ucState, bool bForced = false );
		static bool						SetTrafficLightsLocked          ( lua_State* pLuaVM, bool bLocked );
		static bool						SetJetpackMaxHeight             ( lua_State* pLuaVM, float fMaxHeight );
		static bool						SetInteriorSoundsEnabled        ( lua_State* pLuaVM, bool bEnable );
		static bool						SetRainLevel                    ( lua_State* pLuaVM, float fRainLevel );
		static bool						SetSunSize                      ( lua_State* pLuaVM, float fSunSize );
		static bool						SetSunColor                     ( lua_State* pLuaVM, unsigned char ucCoreR, unsigned char ucCoreG, unsigned char ucCoreB, unsigned char ucCoronaR, unsigned char ucCoronaG, unsigned char ucCoronaB );
		static bool						SetWindVelocity                 ( lua_State* pLuaVM, float fVelX, float fVelY, float fVelZ );
		static bool						SetFarClipDistance              ( lua_State* pLuaVM, float fFarClip );
		static bool						SetFogDistance                  ( lua_State* pLuaVM, float fFogDist );
		static bool						SetAircraftMaxHeight            ( lua_State* pLuaVM, float fMaxHeight );
		static bool						SetAircraftMaxVelocity          ( lua_State* pLuaVM, float fVelocity );
		static bool						SetOcclusionsEnabled            ( lua_State* pLuaVM, bool bEnabled );
		static bool						ResetRainLevel                  ( lua_State* pLuaVM );
		static bool						ResetSunSize                    ( lua_State* pLuaVM );
		static bool						ResetSunColor                   ( lua_State* pLuaVM );
		static bool						ResetWindVelocity               ( lua_State* pLuaVM );
		static bool						ResetFarClipDistance            ( lua_State* pLuaVM );
		static bool						ResetFogDistance                ( lua_State* pLuaVM );
		static bool						RemoveWorldModel                ( lua_State* pLuaVM, unsigned short usModel, float fRadius, const Math::Vector3& vecPosition, char cInterior );
		static bool						RestoreWorldModel               ( lua_State* pLuaVM, unsigned short usModel, float fRadius, const Math::Vector3& vecPosition, char cInterior );
		static bool						RestoreAllWorldModels           ( lua_State* pLuaVM );
		static bool						SendSyncIntervals               ( lua_State* pLuaVM, PVOID pPlayer = NULL );
		static bool						SetPedTargetingMarkerEnabled    ( lua_State* pLuaVM, bool bEnabled );
		static bool						IsPedTargetingMarkerEnabled     ( lua_State* pLuaVM );
		static bool						SetMoonSize                     ( lua_State* pLuaVM, int iMoonSize );
		static bool						ResetMoonSize                   ( lua_State* pLuaVM );

		// Loaded Map Functions
		static PVOID					GetRootElement					( lua_State* pLuaVM );
	//	static PVOID					LoadMapData                     ( lua_State* pLuaVM, PVOID pParent, CXMLNode* pNode );
	//	static PVOID					SaveMapData                     ( lua_State* pLuaVM, PVOID pElement, CXMLNode* pNode, bool bChildren );
	
		// Account get funcs
		static PVOID					GetAccount						( lua_State* pLuaVM, const char* szName, const char* szPassword );
		static ArgumentsVector			GetAccounts						( lua_State* pLuaVM );
		static PVOID					GetAccountPlayer				( lua_State* pLuaVM, PVOID pAccount );
		static bool						IsGuestAccount					( lua_State* pLuaVM, PVOID pAccount, bool& bGuest );
		static LuaArgument			    GetAccountData					( lua_State* pLuaVM, PVOID pAccount, const char* szKey );
		static bool						GetAllAccountData				( lua_State* pLuaVM, PVOID pAccount );
		static bool						GetAccountSerial				( lua_State* pLuaVM, PVOID pAccount, string& strSerial );
		static ArgumentsVector			GetAccountsBySerial				( lua_State* pLuaVM, const string& strSerial );

		// Account set funcs
		static PVOID					AddAccount						( lua_State* pLuaVM, const char* szName, const char* szPassword );
		static bool						RemoveAccount					( lua_State* pLuaVM, PVOID pAccount );
		static bool						SetAccountPassword				( lua_State* pLuaVM, PVOID pAccount, const char* szPassword );
		static bool						SetAccountData					( lua_State* pLuaVM, PVOID pAccount, const char* szKey, LuaArgument* pArgument );
		static bool						CopyAccountData					( lua_State* pLuaVM, PVOID pAccount, PVOID pFromAccount );

		// Log in/out funcs
		static bool						LogIn							( lua_State* pLuaVM, PVOID pPlayer, PVOID pAccount, const char* szPassword );
		static bool						LogOut							( lua_State* pLuaVM, PVOID pPlayer );

		// Admin funcs
		static bool						KickPlayer						( lua_State* pLuaVM, PVOID pPlayer, string strResponsible = "Console", string strReason = "" );
		static PVOID					BanPlayer						( lua_State* pLuaVM, PVOID pPlayer, bool bIP, bool bUsername, bool bSerial, PVOID pResponsible = NULL, string strResponsible = "Console", string strReason = "", time_t tUnban = 0 );

		static PVOID					AddBan							( lua_State* pLuaVM, string strIP, string strUsername, string strSerial, PVOID pResponsible = nullptr, string strReason = "", time_t tUnban = 0 );
		static bool						RemoveBan						( lua_State* pLuaVM, PVOID pBan, PVOID pResponsible = NULL );

		static ArgumentsVector			GetBans							( lua_State* pLuaVM );
		static bool						ReloadBanList					( lua_State* pLuaVM );

		static bool						GetBanIP						( lua_State* pLuaVM, PVOID pBan, string& strOutIP );
		static bool						GetBanSerial					( lua_State* pLuaVM, PVOID pBan, string& strOutSerial );
		static bool						GetBanUsername					( lua_State* pLuaVM, PVOID pBan, string& strOutUsername );
		static bool						GetBanNick						( lua_State* pLuaVM, PVOID pBan, string& strOutNick );
		static bool						GetBanReason					( lua_State* pLuaVM, PVOID pBan, string& strOutReason );
		static bool						GetBanAdmin						( lua_State* pLuaVM, PVOID pBan, string& strOutAdmin );

		static bool						GetBanTime						( lua_State* pLuaVM, PVOID pBan, time_t& time );
		static bool						GetUnbanTime					( lua_State* pLuaVM, PVOID pBan, time_t& time );

		static bool						SetUnbanTime					( lua_State* pLuaVM, PVOID pBan, time_t time);
		static bool						SetBanReason					( lua_State* pLuaVM, PVOID pBan, const string& strReason );
		static bool						SetBanAdmin						( lua_State* pLuaVM, PVOID pBan, const string& strAdminName );

		// Cursor get funcs
		static bool						IsCursorShowing					( lua_State* pLuaVM, PVOID pPlayer, bool& bShowing );

		// Cursor set funcs
		static bool						ShowCursor						( lua_State* pLuaVM, PVOID pElement, bool bShow, bool bToggleControls );

		// Chat funcs
		static bool						ShowChat						( lua_State* pLuaVM, PVOID pElement, bool bShow );

		// Misc funcs
		static bool						ResetMapInfo					( lua_State* pLuaVM, PVOID pElement );

		// Resource funcs
		static PVOID					CreateResource					( lua_State* pLuaVM, const char* szResourceName, const char* szOrganizationalDir );
		static PVOID					CopyResource					( lua_State* pLuaVM, PVOID pResource, const char* szNewResourceName, const char* szOrganizationalDir );
		static PVOID					GetResourceRootElement			( lua_State* pLuaVM, PVOID pResource = NULL );
		static PVOID					GetResourceMapRootElement		( lua_State* pLuaVM, PVOID pResource, const char* szMap );
		static PVOID					GetResourceDynamicElementRoot	( lua_State* pLuaVM, PVOID pResource );
	//	static CXMLNode*				AddResourceMap					( lua_State* pLuaVM, const string& strFilePath, const std::string& strMapName, int iDimension );
	//	static CXMLNode*				AddResourceConfig				( lua_State* pLuaVM, const string& strFilePath, const std::string& strConfigName, int iType );
		static bool						RemoveResourceFile				( lua_State* pLuaVM, PVOID pResource, const char* szFilename );
	//	static CXMLNode					AddResourceConfig				( lua_State* pLuaVM, const char* szFilePath, const char* szFileType = "server" );
	//	static CXMLNode					AddResourceMap					( lua_State* pLuaVM, const char* szFilePath, unsigned int uiDimension = 0 );
	//	static CXMLNode					GetResourceConfig				( lua_State* pLuaVM, const char* szFilePath );
		static ArgumentsVector			GetResourceExportedFunctions	( lua_State* pLuaVM, PVOID pResource );
		static PVOID					GetResourceFromName				( lua_State* pLuaVM, const char* szResourceName );
		static bool						GetResourceInfo					( lua_State* pLuaVM, PVOID pResource, const char* szAttribute, string& strInfo );
		static bool						GetResourceLastStartTime		( lua_State* pLuaVM, PVOID pResource, unsigned int& uiTime );
		static bool						GetResourceLoadFailureReason	( lua_State* pLuaVM, PVOID pResource, string& strReason );
		static bool						GetResourceLoadTime				( lua_State* pLuaVM, PVOID pResource, unsigned int& uiTime );
		static bool						GetResourceName					( lua_State* pLuaVM, PVOID pResource, string& strName );
		static ArgumentsVector			GetResources					( lua_State* pLuaVM );
		static bool						GetResourceState				( lua_State* pLuaVM, PVOID pResource, string& strState );
		static PVOID					GetThisResource					( lua_State* pLuaVM );
		static bool						RefreshResources				( lua_State* pLuaVM, bool refreshAll = false );
		static bool						RemoveResourceDefaultSetting	( lua_State* pLuaVM, PVOID pResource, const char* szSettingName );
		static bool						StartResource					( lua_State* pLuaVM, PVOID pResource, bool persistent = false, bool startIncludedResources = true, bool loadServerConfigs = true, bool loadMaps = true, bool loadServerScripts = true, bool loadHTML = true, bool loadClientConfigs = true, bool loadClientScripts = true, bool loadFiles = true );
		static bool						RestartResource					( lua_State* pLuaVM, PVOID pResource );
		static bool						StopResource					( lua_State* pLuaVM, PVOID pResource );
		static bool						SetResourceDefaultSetting		( lua_State* pLuaVM, PVOID pResource, const char* szSettingName, const char* szSettingValue );
		static bool						SetResourceDefaultSetting		( lua_State* pLuaVM, PVOID pResource, const char* szSettingName, int iSettingValue );
		static bool						SetResourceDefaultSetting		( lua_State* pLuaVM, PVOID pResource, const char* szSettingName, float fSettingValue );
		static bool						SetResourceInfo					( lua_State* pLuaVM, PVOID pResource, const char* szAttribute, const char* szValue );
		static bool						RenameResource					( lua_State* pLuaVM, const char* szResourceName, const char* szNewResourceName, const char* szOrganizationalPath );
		static bool						DeleteResource					( lua_State* pLuaVM, const char* szResourceName );
	//	static CLuaArguments*			GetResourceACLRequests			( lua_State* pLuaVM, PVOID pResource );
		static bool						UpdateResourceACLRequest		( lua_State* pLuaVM, PVOID pResource, const char* szRightName, bool bAccess, const char* szByWho = NULL );

		// Version funcs
		static ArgumentsMap				GetVersion						( lua_State* pLuaVM );

		// Camera get functions
		static bool						GetCameraMatrix					( lua_State* pLuaVM, PVOID pPlayer, Math::Vector3& vecPosition, Math::Vector3& vecLookAt, float& fRoll, float& fFOV );
		static PVOID					GetCameraTarget					( lua_State* pLuaVM, PVOID pPlayer );
		static bool						GetCameraInterior				( lua_State* pLuaVM, PVOID pPlayer, unsigned char & ucInterior );

		// Camera set functions
		static bool						SetCameraMatrix					( lua_State* pLuaVM, PVOID pPlayer, const Math::Vector3& vecPosition, Math::Vector3& pvecLookAt, float fRoll, float fFOV );
		static bool						SetCameraTarget					( lua_State* pLuaVM, PVOID pPlayer, PVOID pTarget );
		static bool						SetCameraInterior				( lua_State* pLuaVM, PVOID pPlayer, unsigned char ucInterior );
		static bool						FadeCamera						( lua_State* pLuaVM, PVOID pPlayer, bool bFadeIn, float fFadeTime, unsigned char ucRed, unsigned char ucGreen, unsigned char ucBlue );

		// Weapon give/take functions
		static bool						GiveWeapon						( lua_State* pLuaVM, PVOID pPed, unsigned char ucWeaponID, unsigned short usAmmo, bool bSetAsCurrent = false );
		static bool						TakeWeapon						( lua_State* pLuaVM, PVOID pPed, unsigned char ucWeaponID, unsigned short usAmmo = 9999 );
		static bool						TakeAllWeapons					( lua_State* pLuaVM, PVOID pPed );
		static bool						SetWeaponAmmo					( lua_State* pLuaVM, PVOID pPed, unsigned char ucWeaponID, unsigned short usAmmo, unsigned short usAmmoInClip );
	};
};
#endif