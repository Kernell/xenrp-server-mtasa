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

class BanEventArgs;

#ifndef __BANEVENTARGS_H
#define __BANEVENTARGS_H

class BanEventArgs : public EventArgs
{
public:
	BanEventArgs( Element* sender, Element* _this, Ban* ban )
		: EventArgs( sender, _this )
	{
		this->Ban = ban;
	}

	Ban* Ban;
};

#endif
