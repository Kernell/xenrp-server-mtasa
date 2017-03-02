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

class PlayerLogoutEventArgs;

#ifndef __PLAYERLOGOUTEVENTARGS_H
#define __PLAYERLOGOUTEVENTARGS_H

class PlayerLogoutEventArgs : public EventArgs
{
public:
	PlayerLogoutEventArgs( Element* sender, Element* _this, Account* previousAccount, Account* currentAccount )
		: EventArgs( sender, _this )
	{
		this->PreviousAccount = previousAccount;
		this->CurrentAccount  = currentAccount;
	}

	Account* PreviousAccount;
	Account* CurrentAccount;
};

#endif