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

class Account;

#ifndef __ACCOUNT_H
#define __ACCOUNT_H

#include "Element.h"

class Account : public Element
{
public:
												Account                     ( PVOID luaUserdata );
	virtual                                     ~Account                    ();
};

#endif