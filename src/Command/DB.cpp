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
#include "DB.h"
#include "Manager/CommandManager.h"

using namespace Command;

DB::DB( CommandManager* manager ) : IConsoleCommand( manager )
{
	this->Name = "db";
}

bool DB::Execute( Element* player, const vector< string >& arguments )
{
	this->GetManager()->GetModule()->Printf( "DB::Execute - Test\n" );

	return false;
}