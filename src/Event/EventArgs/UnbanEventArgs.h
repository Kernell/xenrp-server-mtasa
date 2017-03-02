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

class UnbanEventArgs;

#ifndef __UNBANEVENTARGS_H
#define __UNBANEVENTARGS_H

class UnbanEventArgs : public EventArgs
{
public:
	UnbanEventArgs( Element* sender, Element* _this, Ban* ban, Player* responsibleElement )
		: EventArgs( sender, _this )
	{
		this->Ban = ban;
		this->ResponsibleElement = responsibleElement;
	}

	Ban*    Ban;
	Player* ResponsibleElement;
};

#endif