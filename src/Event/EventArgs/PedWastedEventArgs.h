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

class PedWastedEventArgs;

#ifndef __PEDWASTEDEVENTARGS_H
#define __PEDWASTEDEVENTARGS_H

class PedWastedEventArgs : public EventArgs
{
public:
	PedWastedEventArgs( Element* sender, Element* _this, int totalAmmo, Element* killer, int killerWeapon, int bodypart, bool stealth )
		: EventArgs( sender, _this )
	{
		this->TotalAmmo    = totalAmmo;
		this->Killer       = killer;
		this->KillerWeapon = killerWeapon;
		this->Bodypart     = bodypart;
		this->Stealth      = stealth;
	}

	int      TotalAmmo;
	Element* Killer;
	int      KillerWeapon;
	int      Bodypart;
	bool     Stealth;
};

#endif