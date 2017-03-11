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
	class IConsoleCommand;
};

#ifndef __ICONSOLECOMMAND_H
#define __ICONSOLECOMMAND_H

class CommandManager;
class Element;

namespace Command
{
	class IConsoleCommand
	{
	public:
		                                    IConsoleCommand( CommandManager* manager )
											    : Restricted( false ), CaseSensitive( true ), Manager( manager ) {}

		virtual                             ~IConsoleCommand() {};

		virtual bool                        Execute        ( Element* player, const vector< string >& arguments ) { return false; }
		virtual string                      GetName        () const { return this->Name; }
		virtual CommandManager*             GetManager     () const { return this->Manager; }
		virtual bool                        Info           () const { return false; }
		virtual bool                        IsRestricted   () const { return this->Restricted; }
		virtual bool                        IsCaseSensitive() const { return this->CaseSensitive; }

	protected:
		CommandManager*                     Manager;
		string                              Name;
		bool                                Restricted;
		bool                                CaseSensitive;
	};
};

#endif

