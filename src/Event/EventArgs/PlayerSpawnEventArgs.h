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

class PlayerSpawnEventArgs;

#ifndef __PLAYERSPAWNEVENTARGS_H
#define __PLAYERSPAWNEVENTARGS_H

class PlayerSpawnEventArgs : public EventArgs
{
public:
	PlayerSpawnEventArgs( Element* sender, Element* _this, Math::Vector3 position, float rotation, Team* team, int skin, int interior, int dimension )
		: EventArgs( sender, _this )
	{
		this->Position  = position;
		this->Rotation  = rotation;
		this->Team      = team;
		this->SkinID    = skin;
		this->Interior  = interior;
		this->Dimension = dimension;
	}

	Math::Vector3 Position;
	float Rotation;
	Team* Team;
	int SkinID;
	int Interior;
	int Dimension;
};

#endif
