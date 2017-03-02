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

class PlayerDamageEventArgs;

#ifndef __PLAYERDAMAGEEVENTARGS_H
#define __PLAYERDAMAGEEVENTARGS_H

class PlayerDamageEventArgs : public EventArgs
{
public:
	PlayerDamageEventArgs( Element* sender, Element* _this, Player* attacker, int attackerweapon, int bodypart, float loss )
		: EventArgs( sender, _this )
	{
		this->Attacker		 = attacker;
		this->AttackerWeapon = attackerweapon;
		this->Bodypart		 = bodypart;
		this->Loss			 = loss;
	}

	Player* Attacker;
	int     AttackerWeapon;
	int     Bodypart;
	float   Loss;
};

#endif