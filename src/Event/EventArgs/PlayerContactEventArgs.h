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

class PlayerContactEventArgs;

#ifndef __PLAYERCONTACTEVENTARGS_H
#define __PLAYERCONTACTEVENTARGS_H

class PlayerContactEventArgs : public EventArgs
{
public:
	PlayerContactEventArgs( Element* sender, Element* _this, Element* previous, Element* current )
		: EventArgs( sender, _this )
	{
		this->Previous = previous;
		this->Current  = current;
	}

	Element* Previous;
	Element* Current;
};

#endif
