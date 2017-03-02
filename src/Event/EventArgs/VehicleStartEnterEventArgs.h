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

class VehicleStartEnterEventArgs;

#ifndef __VEHICLESTARTENTEREVENTARGS_H
#define __VEHICLESTARTENTEREVENTARGS_H

class VehicleStartEnterEventArgs : public EventArgs
{
public:
	VehicleStartEnterEventArgs( Element* sender, Element* _this, Player* player, int seat, Player* jacked, int door )
		: EventArgs( sender, _this )
	{
		this->Player = player;
		this->Seat	 = seat;
		this->Jacked = jacked;
		this->Door	 = door;
	}

	Player* Jacked;
	Player* Player;
	int     Seat;
	int     Door;
};

#endif
