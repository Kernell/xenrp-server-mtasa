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

class ForeignKeyConstraint;

#ifndef __FOREIGNKEYCONSTRAINT_H
#define __FOREIGNKEYCONSTRAINT_H

#include "AbstractAsset.h"
#include "Table.h"

class ForeignKeyConstraint : public AbstractAsset
{
public:
	ForeignKeyConstraint( AbstractAsset* parent, const StringArray& localColumnNames, Table* foreignTable, const StringArray& foreignColumnNames, const string& name = string(), const Options& options = Options() );

	string      GetLocalTableName              () const;
	void        SetLocalTable                  ( Table* table );
	Table*      GetLocalTable                  () const;

	StringArray GetLocalColumns                () const;
	StringArray GetQuotedLocalColumns          () const;
	StringArray GetUnquotedLocalColumns        () const;
	StringArray GetUnquotedForeignColumns      () const;
	StringArray GetColumns                     () const;
	StringArray GetQuotedColumns               () const;

	string      GetForeignTableName            () const;
	string      GetUnqualifiedForeignTableName () const;
	string      GetQuotedForeignTableName      () const;

	StringArray GetForeignColumns              () const;
	StringArray GetQuotedForeignColumns        () const;

	bool        HasOption                      ( const string& name ) const;
	string      GetOption                      ( const string& name ) const;

	Options     GetOptions                     () const;
	bool        IntersectsIndexColumns         ( Index* index ) const;

protected:
	map< string, string > _localColumnNames;
	map< string, string > _foreignColumnNames;
	Table*                _foreignTable;
	Table*                _localTable;
	Options               _options;
};

#endif
