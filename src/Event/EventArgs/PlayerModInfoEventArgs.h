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

class PlayerModInfoEventArgs;

#ifndef __PLAYERMODINFOEVENTARGS_H
#define __PLAYERMODINFOEVENTARGS_H

class PlayerModInfoEventArgs : public EventArgs
{
public:
	PlayerModInfoEventArgs( Element* sender, Element* _this, string filename, list< PlayerModInfo > list )
		: EventArgs( sender, _this )
	{
		this->FileName	= filename;
		this->List		= list;
	}

	list< PlayerModInfo > List;
	string FileName;
};

#endif