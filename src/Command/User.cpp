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

#include "StdInc.h"
#include "User.h"

using namespace Command;

User::User( CommandManager* manager ) : IConsoleCommand( manager )
{
	this->Name = "user";
}

bool User::Execute( Element* player, vector< string > arguments )
{
	this->GetManager()->GetModule()->Printf( "User::Execute - Test\n" );

	return false;
}
