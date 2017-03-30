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
#include "ColumnDiff.h"

ColumnDiff::ColumnDiff( AbstractAsset* parent, const string & oldColumnName, ::Column* column, const vector< string >& changedProperties, ::Column* fromColumn ) :
	AbstractAsset( parent )
{
	this->OldColumnName     = oldColumnName;
	this->Column            = column;
	this->ChangedProperties = changedProperties;
	this->FromColumn        = fromColumn;
}

bool ColumnDiff::HasChanged( const string & propertyName ) const
{
	for( const string& str : this->ChangedProperties )
	{
		if( str == propertyName )
		{
			return true;
		}
	}

	return false;
}

string ColumnDiff::GetOldColumnName() const
{
	return this->OldColumnName;
}
