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

class Blip;

#ifndef __BLIP_H
#define __BLIP_H

#include "Element.h"

enum BlipIcon
{
	None = 0,
	Border,
	Centre,
	MapHere,
	North,

	AirYard,
	Gun,
	Barbers,
	BigSmoke,
	BoatYard,
	Burgershot,
	Bulldozer,
	CatPink,
	Cesar,
	Chicken,
	CJ,
	Crash1,
	Diner,
	EmmetGun,
	EnemyAttack,
	Fire,
	Girlfriend,
	Hospital,
	Coco,
	Maddog,
	Mafia,
	Mcstrap,
	ModGarage,
	Ogloc,
	Pizza,
	Police,
	PropertyGreen,
	PropertyRed,
	Race,
	Ryder,
	SaveHouse,
	School,
	Mystery,
	Sweet,
	Tattoo,
	Truth,
	Waypoint,
	TorenoRanch,
	Triads,
	TriadsCasino,
	Tshirt,
	Woozie,
	Zero,
	DateDisco,
	DateDrink,
	DateFood,
	Truck,
	Cash,
	Flag,
	Gym,
	Impound,
	RunwayLight,
	Runway,
	GangB,
	GangP,
	GangY,
	GangN,
	GangG,
	Spray
};

class Blip : public Element
{
public:
									Blip                     ( PVOID luaUserdata );
	                                Blip                     ( const Vector3& position, BlipIcon icon = BlipIcon::None, uchar size = 2, Color color = Color(), short ordering = 0, ushort visibleDistance = 9999, Element* visibleTo = nullptr );
	                                Blip                     ( Element* target, BlipIcon icon = BlipIcon::None, uchar size = 2, Color color = Color(), short ordering = 0, ushort visibleDistance = 9999, Element* visibleTo = nullptr );
	virtual                         ~Blip                    ();

    
	virtual BlipIcon                GetIcon                  () const;
	virtual uchar                   GetSize                  () const;
	virtual Color                   GetColor                 () const;
	virtual short                   GetOrdering              () const;
	virtual ushort                  GetVisibleDistance       () const;

	virtual bool                    SetIcon                  ( BlipIcon icon );
	virtual bool                    SetSize                  ( uchar size );
	virtual bool                    SetColor                 ( const Color& color );
	virtual bool                    SetOrdering              ( short ordering );
	virtual bool                    SetVisibleDistance       ( ushort visibleDistance );
};

#endif