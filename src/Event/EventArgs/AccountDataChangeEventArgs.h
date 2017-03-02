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

class AccountDataChangeEventArgs;

#ifndef __ACCOUNTDATACHANGEEVENTARGS_H
#define __ACCOUNTDATACHANGEEVENTARGS_H

#include "Core/Module.h"

#include "Entity/Element.h"
#include "Entity/Account.h"

class AccountDataChangeEventArgs : public EventArgs
{
public:
	AccountDataChangeEventArgs( Element* sender, Element* _this, Account* account, string key, const LuaArgument& value )
		: EventArgs( sender, _this )
	{
		this->Account = account;
		this->Key     = key;
		this->Value   = value;
	}

	Account*      Account;
	string        Key;
	LuaArgument   Value;
};

#endif;
