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

class Ped;

#ifndef __PED_H
#define __PED_H

#include "Element.h"

class Ped : public Element
{
public:
									    Ped                             ( PVOID luaUserdata );
									    Ped                             ( int modelid, const Math::Vector3& position, float rot = 0.0f, bool synced = true );
	virtual                             ~Ped                            ();

	virtual float                       GetArmor                        () const;    
	virtual bool                        IsChoking                       () const;
	virtual bool                        IsDead                          () const;
	virtual bool                        IsDucked                        () const;    
	virtual float                       GetStat                         ( ushort usStat ) const;
	virtual Element*                    GetTarget                       () const;
	virtual int                         GetWeapon                       ( int weaponSlot = -1 ) const;
	virtual bool                        GetClothes                      ( uchar type, string& outTexture, string& outModel ) const;
	virtual bool                        DoesHaveJetPack                 () const;
	virtual bool                        IsOnGround                      () const;    
	virtual uchar                       GetFightingStyle                () const;
	virtual uint                        GetMoveAnim                     () const;
	virtual float                       GetGravity                      () const;    
	virtual Element*                    GetContactElement               () const;
	virtual uchar                       GetWeaponSlot                   () const;
	virtual bool                        IsDoingGangDriveby              () const;
	virtual bool                        IsOnFire                        () const;
	virtual bool                        IsHeadless                      () const;
	virtual bool                        IsFrozen                        () const;
	virtual Vehicle*                    GetOccupiedVehicle              () const;
	virtual uint                        GetOccupiedVehicleSeat          () const;
	virtual bool                        IsInVehicle                     () const;

	virtual bool                        SetArmor                        ( float armor );
	virtual bool                        Kill                            ( Ped* killer = nullptr, uchar killerWeapon = 0xFF, uchar bodyPart = 0xFF, bool stealth = false );
	virtual bool                        SetStat                         ( ushort stat, float value );
	virtual bool                        AddClothes                      ( const string& texture, const string& model, uchar type );
	virtual bool                        RemoveClothes                   ( uchar type, const char* texture = nullptr, const char* model = nullptr );
	virtual bool                        GiveJetPack                     ();
	virtual bool                        RemoveJetPack                   ();
	virtual bool                        SetFightingStyle                ( uchar style );
	virtual bool                        SetMoveAnim                     ( uint moveAnim );
	virtual bool                        SetGravity                      ( float gravity );
	virtual bool                        SetChoking                      ( bool choking );
	virtual bool                        SetWeaponSlot                   ( uchar weaponSlot );
	virtual bool                        WarpIntoVehicle                 ( Vehicle* vehicle, uint seat = 0 );
	virtual bool                        RemoveFromVehicle               ();
	virtual bool                        SetDoingGangDriveby             ( bool gangDriveby );
	virtual bool                        SetAnimation                    ( const string& blockName, const string& animName, int time, bool loop, bool updatePosition, bool interruptable, bool freezeLastFrame );
	virtual bool                        SetAnimationProgress            ( const string& animName, float progress );
	virtual bool                        SetOnFire                       ( bool isOnFire );
	virtual bool                        SetHeadless                     ( bool isHeadless );
	virtual bool                        SetFrozen                       ( bool isFrozen );
	virtual bool                        ReloadWeapon                    ();

	virtual bool                        GiveWeapon                      ( WeaponType weapon, ushort ammo, bool setAsCurrent = false );
	virtual bool                        TakeWeapon                      ( WeaponType weapon, ushort ammo = 9999 );
	virtual bool                        TakeAllWeapons                  ();
	virtual bool                        SetWeaponAmmo                   ( WeaponType weapon, ushort ammo, ushort ammoInClip );
};

#endif
