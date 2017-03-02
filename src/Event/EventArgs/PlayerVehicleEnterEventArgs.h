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

class PlayerVehicleEnterEventArgs;

#ifndef __PLAYERVEHICLEENTEREVENTARGS_H
#define __PLAYERVEHICLEENTEREVENTARGS_H

class PlayerVehicleEnterEventArgs : public EventArgs
{
public:
	PlayerVehicleEnterEventArgs( Element* sender, Element* _this, Vehicle* vehicle, int seat, Player* jacker )
		: EventArgs( sender, _this )
	{
		this->Vehicle = vehicle;
		this->Seat    = seat;
		this->Jacker  = jacker;
	}

	Vehicle* Vehicle;
	int      Seat;
	Player*  Jacker;
};

#endif
