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

class VehicleEnterEventArgs;

#ifndef __VEHICLEENTEREVENTARGS_H
#define __VEHICLEENTEREVENTARGS_H

class VehicleEnterEventArgs : public EventArgs
{
public:
	VehicleEnterEventArgs( Element* sender, Element* _this, Player* player, int seat, Player* jacked )
		: EventArgs( sender, _this )
	{
		this->Player = player;
		this->Seat   = seat;
		this->Jacked = jacked;
	}

	Player* Jacked;
	Player* Player;
	int     Seat;
};

#endif