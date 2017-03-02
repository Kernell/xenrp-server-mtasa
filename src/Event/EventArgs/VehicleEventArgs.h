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

class VehicleEventArgs;

#ifndef __VEHICLEEVENTARGS_H
#define __VEHICLEEVENTARGS_H

class VehicleEventArgs : public EventArgs
{
public:
	VehicleEventArgs( Element* sender, Element* _this, Vehicle* vehicle )
		: EventArgs( sender, _this )
	{
		this->Vehicle = vehicle;
	}

	Vehicle* Vehicle;
};

#endif
