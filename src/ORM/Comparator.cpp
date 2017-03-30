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
#include "Comparator.h"

Comparator::Comparator() :
	Diff( nullptr )
{
	Diff = new SchemaDiff( nullptr );
}

Comparator::~Comparator()
{
	SAFE_DELETE( Diff );
}

SchemaDiff* Comparator::Compare( Schema* fromSchema, Schema* toSchema )
{
	Diff->FromSchema = fromSchema;

	map< string, vector< ForeignKeyConstraint* > > foreignKeysToTable;

	for( const auto& iter : toSchema->GetTables() )
	{
		Table* table = iter.second;

		string tableName = table->GetName();

		if( !fromSchema->HasTable( tableName ) )
		{
			Diff->NewTables[ tableName ] = toSchema->GetTable( tableName );
		}
		else
		{
			TableDiff* tableDifferences = DiffTable( Diff, fromSchema->GetTable( tableName ), toSchema->GetTable( tableName ) );

			if( tableDifferences != nullptr )
			{
				Diff->ChangedTables[ tableName ] = tableDifferences;
			}
		}
	}

	for( const auto& iter : fromSchema->GetTables() )
	{
		Table* table = iter.second;

		string tableName = table->GetName();

		table = fromSchema->GetTable( tableName );

		if( !toSchema->HasTable( tableName ) )
		{
			Diff->RemovedTables[ tableName ] = table;
		}

		for( ForeignKeyConstraint* key : table->GetForeignKeys() )
		{
			string foreignTable = strtolower( key->GetForeignTableName() );

			foreignKeysToTable[ foreignTable ].push_back( key );
		}
	}

	for( const auto& iter : Diff->RemovedTables )
	{
		const string& tableName = iter.first;
		Table* table = iter.second;

		if( foreignKeysToTable.count( tableName ) > 0 )
		{
			Diff->OrphanedForeignKeys.insert( Diff->OrphanedForeignKeys.end(), foreignKeysToTable[ tableName ].begin(), foreignKeysToTable[ tableName ].end() );

			for( const auto& iter : foreignKeysToTable[ tableName ] )
			{
				const string& localTableName = strtolower( iter->GetLocalTableName() );

				if( Diff->ChangedTables.count( localTableName ) > 0 )
				{
					auto iter = Diff->ChangedTables[ localTableName ]->RemovedForeignKeys.begin();

					for( ; iter != Diff->ChangedTables[ localTableName ]->RemovedForeignKeys.end(); ++iter )
					{
						ForeignKeyConstraint* removedForeignKey = *iter;

						if( tableName != strtolower( removedForeignKey->GetForeignTableName() ) )
						{
							continue;
						}

						Diff->ChangedTables[ localTableName ]->RemovedForeignKeys.erase( iter );
					}
				}
			}
		}
	}

	return Diff;
}

TableDiff* Comparator::DiffTable( SchemaDiff* schemaDiff, Table* table1, Table* table2 )
{
	uint32_t changes = 0;

	TableDiff* tableDifferences = new TableDiff( schemaDiff, table1->GetName() );

	tableDifferences->SetFromTable( table1 );

	auto table1Columns = table1->GetColumns();
	auto table2Columns = table2->GetColumns();

	for( Column* col : table2Columns )
	{
		if( !table1->HasColumn( col ) )
		{
			tableDifferences->AddedColumns.push_back( col );

			++changes;
		}
	}
	for( Column* col : table1Columns )
	{
		if( !table2->HasColumn( col ) )
		{
			tableDifferences->RemovedColumns.push_back( col );

			++changes;

			continue;
		}

		const vector< string >& changedProperties = DiffColumn( col, table2->GetColumn( col->GetName() ) );

		if( !changedProperties.empty() )
		{
			ColumnDiff* columnDiff = new ColumnDiff( tableDifferences, col->GetName(), table2->GetColumn( col->GetName() ), changedProperties );

			columnDiff->FromColumn = col;

			tableDifferences->ChangedColumns.push_back( columnDiff );

			++changes;
		}
	}

	DetectColumnRenamings( tableDifferences );

	auto table1Indexes = table1->GetIndexes();
	auto table2Indexes = table2->GetIndexes();

	for( Index* index : table2Indexes )
	{
		if( ( index->IsPrimary() && table1->HasPrimaryKey() ) || table1->HasIndex( index ) )
		{
			continue;
		}

		tableDifferences->AddedIndexes.push_back( index );

		++changes;
	}

	for( Index* index : table1Indexes )
	{
		const string& indexName = index->GetName();

		if( ( index->IsPrimary() && !table2->HasPrimaryKey() ) || !index->IsPrimary() && !table2->HasIndex( indexName ) )
		{
			tableDifferences->RemovedIndexes.push_back( index );

			++changes;
			
			continue;
		}

		Index* table2Index = index->IsPrimary() ? table2->GetPrimaryKey() : table2->GetIndex( indexName );

		if( DiffIndex( index, table2Index ) )
		{
			tableDifferences->ChangedIndexes.push_back( table2Index );

			++changes;
		}
	}

	auto fromFkeys = table1->GetForeignKeys();
	auto toFkeys   = table2->GetForeignKeys();

	auto erase = []( vector< ForeignKeyConstraint* >& keys, ForeignKeyConstraint* key ) -> void
	{
		for( auto iter = keys.begin(); iter != keys.end(); ++iter )
		{
			if( ( *iter ) == key )
			{
				keys.erase( iter );

				break;
			}
		}
	};

	for( ForeignKeyConstraint* constraint1 : fromFkeys )
	{
		for( ForeignKeyConstraint* constraint2 : toFkeys )
		{
			if( !DiffForeignKey( constraint1, constraint2 ) )
			{
				erase( fromFkeys, constraint1 );
				erase( toFkeys, constraint2 );
			}
			else
			{
				if( strtolower( constraint1->GetName() ) == strtolower( constraint2->GetName() ) )
				{
					tableDifferences->ChangedForeignKeys.push_back( constraint2 );

					erase( fromFkeys, constraint1 );
					erase( toFkeys, constraint2 );

					++changes;
				}
			}
		}
	}

	for( ForeignKeyConstraint* key : fromFkeys )
	{
		tableDifferences->RemovedForeignKeys.push_back( key );

		++changes;
	}

	for( ForeignKeyConstraint* key : toFkeys )
	{
		tableDifferences->AddedForeignKeys.push_back( key );

		++changes;
	}

	return changes ? tableDifferences : false;
}

void Comparator::DetectColumnRenamings( TableDiff* tableDifferences )
{
	struct RenameCandidate
	{
		Column* Removed;
		Column* Added;
		string  AddedName;
	};

	map< string, vector< RenameCandidate > > renameCandidates;

	for( Column* addedColumn : tableDifferences->AddedColumns )
	{
		const string& addedColumnName = addedColumn->GetName();

		for( Column* col : tableDifferences->RemovedColumns )
		{
			const vector< string >& diff = DiffColumn( addedColumn, col );

			if( diff.size() == 0 )
			{
				renameCandidates[ addedColumn->GetName() ].push_back( { col, addedColumn, addedColumnName } );
			}
		}
	}

	for( const auto& iter : renameCandidates )
	{
		const auto& candidateColumns = iter.second;

		if( candidateColumns.size() == 1 )
		{
			Column* removedColumn = candidateColumns.at( 0 ).Removed;
			Column* addedColumn   = candidateColumns.at( 0 ).Added;

			if( find( tableDifferences->RenamedColumns.begin(), tableDifferences->RenamedColumns.end(), removedColumn ) != tableDifferences->RenamedColumns.end() )
			{
				tableDifferences->RenamedColumns.push_back( addedColumn );

				for( auto iter = tableDifferences->RemovedColumns.begin(); iter != tableDifferences->RemovedColumns.end(); ++iter )
				{
					if( ( *iter ) == removedColumn )
					{
						tableDifferences->RemovedColumns.erase( iter );

						break;
					}
				}

				for( auto iter = tableDifferences->AddedColumns.begin(); iter != tableDifferences->AddedColumns.end(); ++iter )
				{
					if( ( *iter ) == addedColumn )
					{
						tableDifferences->AddedColumns.erase( iter );

						break;
					}
				}
			}
		}
	}
}

bool Comparator::DiffForeignKey( ForeignKeyConstraint* key1, ForeignKeyConstraint* key2 )
{
	auto array_diff = []( const vector< string >& arr1, const vector< string >& arr2 ) -> bool
	{
		if( arr1.size() != arr2.size() )
		{
			return true;
		}

		auto iter1 = arr1.begin();
		auto iter2 = arr2.begin();

		for( ; iter1 != arr1.end() || iter2 != arr2.end(); ++iter1, ++iter2 )
		{
			if( strtolower( *iter1 ) != strtolower( *iter2 ) )
			{
				return true;
			}
		}

		return false;
	};

	if( array_diff( key1->GetUnquotedLocalColumns(), key2->GetUnquotedLocalColumns() ) )
	{
		return true;
	}

	if( array_diff( key1->GetUnquotedForeignColumns(), key2->GetUnquotedForeignColumns() ) )
	{
		return true;
	}

	if( key1->GetUnqualifiedForeignTableName() != key2->GetUnqualifiedForeignTableName() )
	{
		return true;
	}

	//if( key1->OnUpdate() != key2->OnUpdate() )
	//{
	//	return true;
	//}

	//if( key1->OnDelete() != key2->OnDelete() )
	//{
	//	return true;
	//}

	return false;
}

vector< string > Comparator::DiffColumn( Column* column1, Column* column2 )
{
#define CHECK_PROPERTY(x) if(column1->x != column2->x) changedProperties.push_back(#x)

	vector< string > changedProperties;

	CHECK_PROPERTY( Type );
	CHECK_PROPERTY( NotNull );
	CHECK_PROPERTY( Unsigned );
	CHECK_PROPERTY( AutoIncrement );

	if( column1->Default != column2->Default ||
		( column1->Default.empty() && !column2->Default.empty() ) || 
		( column2->Default.empty() && !column1->Default.empty() )
		)
	{
		changedProperties.push_back( "Default" );
	}

	if( ( column1->Type->GetID() == ColumnType::STRING && column1->Type->GetID() != ColumnType::GUID ) || column1->Type->GetID() == ColumnType::BINARY )
	{
		size_t length1 = column1->Length > 0 ? column1->Length : 255;
		size_t length2 = column2->Length > 0 ? column2->Length : 255;

		if( length1 != length2 )
		{
			changedProperties.push_back( "Length" );
		}

		if( column1->Fixed != column2->Fixed )
		{
			changedProperties.push_back( "Fixed" );
		}
	}
	else if( column1->Type->GetID() == ColumnType::DECIMAL )
	{
		if( ( column1->Precision > 0 ? column1->Precision : 10 ) != ( column2->Precision > 0 ? column2->Precision : 10 ) )
		{
			changedProperties.push_back( "Precision" );
		}

		CHECK_PROPERTY( Scale );
	}

	CHECK_PROPERTY( Comment );

	return changedProperties;
}

bool Comparator::DiffIndex( Index* index1, Index* index2 )
{
	return !( index1->IsFullfilledBy( index2 ) && index2->IsFullfilledBy( index1 ) );
}
