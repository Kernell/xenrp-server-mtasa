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

class PedEventArgs;

#ifndef __PEDEVENTARGS_H
#define __PEDEVENTARGS_H

class PedEventArgs : public EventArgs
{
public:
	PedEventArgs( Element* sender, Element* _this, Ped* ped )
		: EventArgs( sender, _this )
	{
		this->Ped = ped;
	}

	Ped* Ped;
};

#endif
