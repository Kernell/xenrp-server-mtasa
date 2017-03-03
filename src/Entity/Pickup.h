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

class Pickup;

#ifndef __PICKUP_H
#define __PICKUP_H

#include "Element.h"

enum PickupType
{
	Health,
	Armour,
	Weapon,
	Custom,
};

class Pickup : public Element
{
public:
									Pickup               ( PVOID luaUserdata );
	                                Pickup               ( const Vector3& position, PickupType type, double amount_weapon_model, ulong respawnInterval = 30000, double ammo = 50 );
	virtual                         ~Pickup              ();

	virtual PickupType              GetType              () const;
	virtual uchar                   GetWeapon            () const;
	virtual float                   GetAmount            () const;
	virtual ushort                  GetAmmo              () const;
	virtual ulong                   GetRespawnInterval   () const;
	virtual bool                    IsSpawned            () const;

	virtual bool                    SetType              ( PickupType type, double amount_weapon_model, double ammo );
	virtual bool                    SetRespawnInterval   ( ulong interval );
	virtual bool                    Use                  ( Player* player );
};

#endif