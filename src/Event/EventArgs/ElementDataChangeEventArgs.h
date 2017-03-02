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

class ElementDataChangeEventArgs;

#ifndef __ELEMENTDATACHANGEEVENTARGS_H
#define __ELEMENTDATACHANGEEVENTARGS_H

class ElementDataChangeEventArgs : public EventArgs
{
public:
	ElementDataChangeEventArgs( Element* sender, Element* _this, Player* client, string name, LuaArgument oldValue )
		: EventArgs( sender, _this )
	{
		this->Client    = client;
		this->Name      = name;
		this->OldValue  = oldValue;
	}

	Player*       Client;
	string        Name;
	LuaArgument OldValue;
};

#endif
