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

class AbstractAsset;

#ifndef __ABSTRACTASSET_H
#define __ABSTRACTASSET_H

#include "SchemaException.h"

class AbstractAsset
{
public:
	typedef vector< string >       Flags;
	typedef map< string, string >  Options;
	typedef vector< string >       StringArray;

	const int MaxIdentifierLength = 63;

public:
	AbstractAsset( AbstractAsset* parent );
	virtual ~AbstractAsset();

	virtual void    SetName     ( const string& name );
	virtual string  GetName     () const;
	virtual string  GetQuotedName() const;
	virtual string  TrimQuotes  ( const string& identifier ) const;

	virtual string _generateIdentifierName( const StringArray& columnNames, const string& prefix = string(), size_t maxSize = 30 );

public:
	AbstractAsset*           Parent;
	vector< AbstractAsset* > Childs;

protected:
	string Name;
};

#endif
