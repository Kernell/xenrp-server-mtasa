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
#include "CommandManager.h"

CommandManager::CommandManager( ::Module* module )
{
	this->Module = module;

	this->Add( new Command::User( this ) );
}

CommandManager::~CommandManager()
{
	this->ClearCommands();

	this->Module = nullptr;
}

bool CommandManager::Add( Command::IConsoleCommand* command )
{
	if( command == this->GetCommand( command->GetName() ) )
	{
		return false;
	}

	Lua::Bindings::AddCommandHandler( this->Module->GetLua(), command->GetName().c_str(), Lua::Functions::XRCommandHandler, command->IsRestricted(), command->IsCaseSensitive() );

	this->Commands.push_back( command );

	return true;
}

bool CommandManager::Execute( Element* player, const string& commandName, vector< string > argv )
{
	Command::IConsoleCommand* command = this->GetCommand( commandName );

	if( command )
	{
		command->Execute( player, argv );

		return true;
	}

	return false;
}

bool CommandManager::Remove( const string& commandName, Command::IConsoleCommand* command )
{
	bool bFound = false;

	iterator iter = this->Commands.begin();

	int compareResult;

	while( iter != this->Commands.end() )
	{
		if( ( *iter )->IsCaseSensitive() )
		{
			compareResult = strcmp( ( *iter )->GetName().c_str(), commandName.c_str() );
		}
		else
		{
			compareResult = stricmp( ( *iter )->GetName().c_str(), commandName.c_str() );
		}

		if( compareResult == 0 )
		{
			if( *iter != command )
			{
				iter++;

				continue;
			}

			delete *iter;

			iter = this->Commands.erase( iter );

			bFound = true;
		}
		else
		{
			iter++;
		}
	}

	return bFound;
}

void CommandManager::ClearCommands( void )
{
	const_iterator iter = this->Commands.begin();

	for( ; iter != this->Commands.end(); iter++ )
	{
		delete *iter;
	}

	this->Commands.clear();
}

Command::IConsoleCommand* CommandManager::GetCommand( const string& commandName )
{
	for( const auto& command : this->Commands )
	{
		if( command->IsCaseSensitive() )
		{
			if( command->GetName() == commandName )
			{
				return command;
			}
		}
		else if( stricmp( command->GetName().c_str(), commandName.c_str() ) )
		{
			return command;
		}
	}

	return nullptr;
}

