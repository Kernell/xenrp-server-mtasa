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

class CommandManager;

#ifndef __COMMANDMANAGER_H
#define __COMMANDMANAGER_H

#include "Core/Module.h"

#include "Command/IConsoleCommand.h"
#include "Command/User.h"

class CommandManager
{
public:
								CommandManager                      ( Module* module );
								~CommandManager                     ();

	bool                        Add                                 ( Command::IConsoleCommand* command );
	bool                        Execute                             ( Element* player, const string& commandName, const vector< string > argv );
	bool                        Remove                              ( const string& commandName, Command::IConsoleCommand* command = nullptr );

	void                        ClearCommands                       ();

	Module*                     GetModule                           () const { return this->Module; }

private:
	Command::IConsoleCommand*   GetCommand                          ( const string& commandName );

private:
	typedef list< Command::IConsoleCommand* >::iterator             iterator;
	typedef list< Command::IConsoleCommand* >::const_iterator       const_iterator;

	Module*                                                         Module;
	list< Command::IConsoleCommand* >                               Commands;
};

#endif
