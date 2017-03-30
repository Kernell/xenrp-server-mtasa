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
#include "AbstractAsset.h"

#include "SharedUtil/CRC32.h"

AbstractAsset::AbstractAsset( AbstractAsset* parent ) :
	Parent( parent )
{
	if( parent )
	{
		parent->Childs.push_back( this );
	}
}

AbstractAsset::~AbstractAsset()
{
	for( auto iter = this->Childs.begin(); iter != this->Childs.end(); ++iter )
	{
		delete *iter;
	}

	this->Childs.clear();
}

void AbstractAsset::SetName( const string & name )
{
	this->Name = name;
}

string AbstractAsset::GetName() const
{
	return this->Name;
}

string AbstractAsset::GetQuotedName() const
{
	return "`" + this->Name + "`";
}

string AbstractAsset::TrimQuotes( const string& identifier ) const
{
	string result;

	for( size_t i = 0; i < identifier.size(); ++i )
	{
		char c = identifier[ i ];

		if( c != '`' &&
			c != '"' &&
			c != '[' &&
			c != ']' )
		{
			result.push_back( c );
		}
	}

	return result;
}

string AbstractAsset::_generateIdentifierName( const StringArray& columnNames, const string& prefix, size_t maxSize )
{
	stringstream hash;

	for( const auto& column : columnNames )
	{
		hash << hex << CRC32::Calc( (LPBYTE)column.c_str(), column.length() );
	}

	return strtoupper( prefix + "_" + hash.str() ).substr( 0, maxSize );
}
