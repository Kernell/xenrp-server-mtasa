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

#pragma once

#include "IConsoleCommand.h"

namespace Command
{
	class DB : public IConsoleCommand
	{
	public:
		DB( class CommandManager* manager );

		virtual bool Execute( Element* player, const vector< string >& arguments ) override;
	};
};
