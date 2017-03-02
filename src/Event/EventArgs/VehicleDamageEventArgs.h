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

class VehicleDamageEventArgs;

#ifndef __VEHICLEDAMAGEEVENTARGS_H
#define __VEHICLEDAMAGEEVENTARGS_H

class VehicleDamageEventArgs : public EventArgs
{
public:
	VehicleDamageEventArgs( Element* sender, Element* _this, float loss )
		: EventArgs( sender, _this )
	{
		this->Loss = loss;
	}

	float Loss;
};

#endif