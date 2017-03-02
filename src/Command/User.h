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

namespace Command
{
	class User;
};

#ifndef __COMMAND_USER
#define __COMMAND_USER

#include "IConsoleCommand.h"
#include "Manager/CommandManager.h"

namespace Command
{
	class User : public IConsoleCommand
	{
	public:
		User( CommandManager* manager );

		virtual bool Execute( Element* player, vector< string > arguments ) override;
	};
};

#endif
