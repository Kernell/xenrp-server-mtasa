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

class PedWeaponSwitchEventArgs;

#ifndef __PEDWEAPONSWITCHEVENTARGS_H
#define __PEDWEAPONSWITCHEVENTARGS_H

class PedWeaponSwitchEventArgs : public EventArgs
{
public:
	PedWeaponSwitchEventArgs( Element* sender, Element* _this, int previousWeaponID, int currentWeaponID )
		: EventArgs( sender, _this )
	{
		this->PreviousWeaponID = previousWeaponID;
		this->CurrentWeaponID  = currentWeaponID;
	}

	int PreviousWeaponID;
	int CurrentWeaponID;
};

#endif
