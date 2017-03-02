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

class VehicleRespawnEventArgs;

#ifndef __VEHICLERESPAWNEVENTARGS_H
#define __VEHICLERESPAWNEVENTARGS_H

class VehicleRespawnEventArgs : public EventArgs
{
public:
	VehicleRespawnEventArgs( Element* sender, Element* _this, bool exploded )
		: EventArgs( sender, _this )
	{
		this->Exploded = exploded;
	}

	bool Exploded;
};

#endif
