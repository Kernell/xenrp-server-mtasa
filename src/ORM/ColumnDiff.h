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

class ColumnDiff;

#ifndef __COLUMNDIFF_H
#define __COLUMNDIFF_H

#include "Column.h"

class ColumnDiff : public AbstractAsset
{
public:
	ColumnDiff( AbstractAsset* parent, const string& oldColumnName, ::Column* column, const vector< string >& changedProperties = vector< string >(), ::Column* fromColumn = nullptr );

	bool HasChanged( const string& propertyName ) const;

	string GetOldColumnName() const;

protected:
	string           OldColumnName;

public:
	::Column*        Column;
	::Column*        FromColumn;
	vector< string > ChangedProperties;
};

#endif
