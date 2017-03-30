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

class Index;

#ifndef __INDEX_H
#define __INDEX_H

#include "AbstractAsset.h"

class Index : public AbstractAsset
{
public:
	Index( AbstractAsset* parent, const string& indexName, const StringArray& columns, bool isUnique = false, bool isPrimary = false, Flags flags = Flags(), Options options = Options() );

	void        _addColumn          ( const string& column );

	StringArray GetColumns          () const;
	StringArray GetQuotedColumns    () const;
	StringArray GetUnquotedColumns  () const;

	bool        IsSimpleIndex       () const;
	bool        IsUnique            () const;
	bool        IsPrimary           () const;
	bool        HasColumnAtPosition ( const string& _columnName, size_t pos = 0 );
	bool        SpansColumns        ( const StringArray& columnNames ) const;
	bool        IsFullfilledBy      ( Index* other ) const;
	bool        Overrules           ( Index* other ) const;

	StringArray GetFlags            () const;

	void        AddFlag             ( const string& flag );
	bool        HasFlag             ( const string& flag ) const;
	void        RemoveFlag          ( const string& flag );
	bool        HasOption           ( const string& name ) const;
	string      GetOption           ( const string& name ) const;

	Options     GetOptions          () const;

	bool        SamePartialIndex    ( Index* other ) const;

protected:
	bool        _isUnique;
	bool        _isPrimary;

	StringArray           _columns;
	map< string, bool >   _flags;
	map< string, string > options;
};

#endif;
