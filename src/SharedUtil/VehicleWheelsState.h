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

class VehicleWheelsState;

#ifndef __VEHICLEWHEELSSTATE_H
#define __VEHICLEWHEELSSTATE_H

class VehicleWheelsState
{
public:
	byte FrontLeft;
	byte RearLeft;
	byte FrontRight;
	byte RearRight;

	VehicleWheelsState() :
		FrontLeft( 0 ), RearLeft( 0 ), FrontRight( 0 ), RearRight( 0 )
	{
	}

	VehicleWheelsState( byte frontLeft, byte rearLeft, byte frontRight, byte rearRight ) :
		FrontLeft( frontLeft ), RearLeft( rearLeft ), FrontRight( frontRight ), RearRight( rearRight )
	{
	}
};

#endif
