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

class Table;
struct TableOptions;

#ifndef __TABLE_H
#define __TABLE_H

#include "AbstractAsset.h"
#include "Index.h"
#include "Column.h"
#include "ForeignKeyConstraint.h"

struct TableOptions
{
	TableOptions() :
		PrimaryIndex( nullptr ),
		Temporary( false ),
		Engine( "InnoDB" ),
		Charset( "utf8mb4" ),
		Collate( "utf8mb4_unicode_ci" )
	{
	}

	map< string, Index* >           Indexes;
	map< string, Index* >           UniqueConstraints;
	vector< ForeignKeyConstraint* > ForeignKeys;
	vector< string >                Primary;
	Index*                          PrimaryIndex;
	bool                            Temporary;
	string                          Engine;
	string                          Charset;
	string                          Collate;
	string                          AutoIncrement;
	string                          Comment;
	string                          RowFormat;
	string                          PartitionOptions;
};

class Table : public AbstractAsset
{
public:
	Table( AbstractAsset* parent, const string& tableName );

	void			    SetPrimaryKey                  ( const StringArray& columns, const string& indexName = string( "primary" ) );
	void			    AddIndex                       ( const StringArray& columnNames, string indexName = string(), const Flags& flags = Flags(), const Options& options = Options() );
	void			    DropPrimaryKey                 ();
	void			    DropIndex                      ( string indexName );
	void			    AddUniqueIndex                 ( const StringArray& columnNames, string indexName = string(), const Options& options = Options() );
	void			    RenameIndex                    ( const string& _oldIndexName, const string& _newIndexName = string() );
	bool			    ColumnsAreIndexed              ( const StringArray& columnsNames );
	
	Index*              _createIndex                   ( const StringArray& columnNames, const string& indexName, bool isUnique, bool isPrimary, const Index::Flags& flags = Index::Flags(), const Index::Options& options = Index::Options() );
	Column*             AddColumn                      ( const string& columnName, const string& typeName, const Index::Options& options = Index::Options() );

	void                DropColumn                     ( const string& _columnName );
	void                AddForeignKeyConstraint        ( Table* foreignTable, const StringArray& localColumnNames, const StringArray& foreignColumnNames, const Options& options = Options(), const string& constraintName = string() );
	void                AddUnnamedForeignKeyConstraint ( Table* foreignTable, const StringArray& localColumnNames, const StringArray& foreignColumnNames, const Options& options = Options() );
	void                AddNamedForeignKeyConstraint   ( const string& name, Table* foreignTable, const StringArray& localColumnNames, const StringArray& foreignColumnNames, Options options = Options() );
	void                AddForeignKeyConstraint        ( ForeignKeyConstraint* constraint );
	void                AddColumn                      ( Column* column );
	void                AddIndex                       ( Index* indexCandidate );

	vector< Column* >                    GetColumns           () const;
	bool                                 HasColumn            ( Column* column ) const;
	bool                                 HasColumn            ( const string& columnName ) const;
	Column*                              GetColumn            ( const string& _columnName ) const;

	Index*                               GetPrimaryKey        () const;
	StringArray                          GetPrimaryKeyColumns () const;
	bool                                 HasPrimaryKey        () const;
	bool                                 HasIndex             ( const Index* index ) const;
	bool                                 HasIndex             ( const string& indexName ) const;
	Index*                               GetIndex             ( const string& indexName ) const;
	vector< Index* >                     GetIndexes           () const;
	vector< ForeignKeyConstraint* >      GetForeignKeys       () const;
	TableOptions*                        GetOptions           ();

protected:
	string NormalizeIdentifier( const string& identifier ) const;

protected:
	string _primaryKeyName;

	vector< Column* >                    _columns;
	vector< Index* >                     _indexes;
	vector< ForeignKeyConstraint* >      _fkConstraints;
	TableOptions                         _options;
	map< string, Index* >                implicitIndexes;
};

#endif
