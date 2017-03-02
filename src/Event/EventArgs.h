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

class EventArgs;

#ifndef __EVENTARGS_H
#define __EVENTARGS_H

#include "Entity/Element.h"

class EventArgs
{
public:
	EventArgs( Element* sender, Element* _this )
	{
		this->Sender = sender;
		this->This   = _this;
	}

	void Cancel( const string& reason = "" )
	{
	}

	Element* Sender;
	Element* This;
};

#endif
