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

class PlayerTargetEventArgs;

#ifndef __PLAYERTARGETEVENTARGS_H
#define __PLAYERTARGETEVENTARGS_H

class PlayerTargetEventArgs : public EventArgs
{
public:
	PlayerTargetEventArgs( Element* sender, Element* _this, Element* targettedElement )
		: EventArgs( sender, _this )
	{
		this->Target = targettedElement;
	}

	Element* Target;
};

#endif