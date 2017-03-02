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

class PlayerLoginEventArgs;

#ifndef __PLAYERLOGINEVENTARGS_H
#define __PLAYERLOGINEVENTARGS_H

class PlayerLoginEventArgs : public EventArgs
{
public:
	PlayerLoginEventArgs( Element* sender, Element* _this, Account* previousAccount, Account* currentAccount, bool autoLogin )
		: EventArgs( sender, _this )
	{
		this->PreviousAccount = previousAccount;
		this->CurrentAccount  = currentAccount;
		this->AutoLogin       = autoLogin;
	}

	Account* PreviousAccount;
	Account* CurrentAccount;
	bool     AutoLogin;
};

#endif
