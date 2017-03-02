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

class PlayerBanEventArgs;

#ifndef __PLAYERBANEVENTARGS_H
#define __PLAYERBANEVENTARGS_H

class PlayerBanEventArgs : public EventArgs
{
public:
	PlayerBanEventArgs( Element* sender, Element* _this, Ban* banPointer, Player* responsibleElement )
		: EventArgs( sender, _this )
	{
		this->Ban         = banPointer;
		this->Responsible = responsibleElement;
	}

	Ban*    Ban;
	Player* Responsible;
};

#endif
