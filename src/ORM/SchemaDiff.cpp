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
#include "SchemaDiff.h"

SchemaDiff::SchemaDiff( AbstractAsset* parent, const map<string, Table*>& newTables, const map<string, TableDiff*>& changedTables, const map<string, Table*>& removedTables, Schema * fromSchema ) :
	AbstractAsset( parent )
{
	this->NewTables     = newTables;
	this->ChangedTables = changedTables;
	this->RemovedTables = removedTables;
	this->FromSchema    = fromSchema;
}

vector< string > SchemaDiff::ToSQL( AbstractPlatform* platform, bool saveMode )
{
	vector< string > sql;

	if( platform->SupportsForeignKeyConstraints() && saveMode == false )
	{
		for( const auto& orphanedForeignKey : this->OrphanedForeignKeys )
		{
			sql.push_back( platform->GetDropForeignKeySQL( orphanedForeignKey, orphanedForeignKey->GetLocalTable() ) );
		}
	}

	for( const auto& iter : this->NewTables )
	{
		Table* table = iter.second;

		vector< string > sql2 = platform->GetCreateTableSQL( table, AbstractPlatform::CREATE_INDEXES );

		sql.insert( sql.end(), sql2.begin(), sql2.end() );

		if( platform->SupportsForeignKeyConstraints() )
		{
			for( const auto& iter : table->GetForeignKeys() )
			{
				sql.push_back( platform->GetCreateForeignKeySQL( iter, table ) );
			}
		}
	}

	if( saveMode == false )
	{
		for( const auto& iter : this->RemovedTables )
		{
			sql.push_back( platform->GetDropTableSQL( iter.second ) );
		}
	}

	for( const auto& iter : this->ChangedTables )
	{
		vector< string > sql2 = platform->GetAlterTableSQL( iter.second );

		sql.insert( sql.end(), sql2.begin(), sql2.end() );
	}

	return sql;
}
