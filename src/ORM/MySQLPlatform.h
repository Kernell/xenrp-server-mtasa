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

#include "AbstractPlatform.h"

class MySQLPlatform : public AbstractPlatform
{
public:
	/**
	* Adds MySQL-specific LIMIT clause to the query
	* 18446744073709551615 is 2^64-1 maximum of unsigned BIGINT the biggest limit possible
	*/
	virtual string DoModifyLimitQuery( const string& query, int limit = -1, int offset = -1 ) override;

	virtual string GetIdentifierQuoteCharacter() override;
	virtual string GetRegexpExpression() override;
	virtual string GetGuidExpression() override;
	virtual string GetLocateExpression( const string& str, const string& substr, int startPos = 0 ) override;
	virtual string GetConcatExpression( const vector< string >& args ) override;
	virtual string GetDateArithmeticIntervalExpression( const string& date, const string& op, int interval, const string& unit ) override;
	virtual string GetDateDiffExpression( const string& date1, const string& date2 ) override;
	virtual string GetListDatabasesSQL() override;
	virtual string GetListTableConstraintsSQL( const string& table ) override;

	/**
	* Two approaches to listing the table indexes. The information_schema is
	* preferred, because it doesn"t cause problems with SQL keywords such as "order" or "table" + 
	*/
	virtual string GetListTableIndexesSQL( const string& table, const string& currentDatabase = string() ) override;
	virtual string GetListViewsSQL( const string& database ) override;
	virtual string GetListTableForeignKeysSQL( const string& table, const string& database = string() ) override;
	virtual string GetCreateViewSQL( const string& name, const string& sql ) override;
	virtual string GetDropViewSQL( const string& name ) override;
	virtual string GetVarcharTypeDeclarationSQLSnippet( size_t length = 255, bool fixed = false ) override;
	virtual string GetBinaryTypeDeclarationSQLSnippet( size_t length = 255, bool fixed = false ) override;

	/**
	* Gets the SQL snippet used to declare a CLOB column type.
	*     TINYTEXT   : 2 ^  8 - 1 = 255
	*     TEXT       : 2 ^ 16 - 1 = 65535
	*     MEDIUMTEXT : 2 ^ 24 - 1 = 16777215
	*     LONGTEXT   : 2 ^ 32 - 1 = 4294967295
	*/
	virtual string GetClobTypeDeclarationSQL( Column* field ) override;
	virtual string GetDateTimeTypeDeclarationSQL( Column* fieldDeclaration ) override;
	virtual string GetDateTypeDeclarationSQL( Column* fieldDeclaration ) override;
	virtual string GetTimeTypeDeclarationSQL( Column* fieldDeclaration ) override;
	virtual string GetBooleanTypeDeclarationSQL( Column* columnDef ) override;
	virtual string GetCollationFieldDeclaration( const string& collation );

	/**
	* MySql prefers "autoincrement" identity columns since sequences can only
	* be emulated with a table.
	*/
	virtual bool PrefersIdentityColumns() override;

	/**
	* MySql supports this through AUTO_INCREMENT columns.
	*/
	virtual bool                    SupportsIdentityColumns() override;
	virtual bool                    SupportsInlineColumnComments() override;
	virtual bool                    SupportsColumnCollation() override;
	virtual string                  GetListTablesSQL() override;
	virtual string                  GetListTableColumnsSQL( const string& _table, const string& _database = string() ) override;
	virtual string                  GetCreateDatabaseSQL( const string& name ) override;
	virtual string                  GetDropDatabaseSQL( const string& name ) override;
	virtual StringArray             _getCreateTableSQL( const string& tableName, const vector< Column* >& columns, const TableOptions& options = TableOptions() ) override;
	virtual string                  GetDefaultValueDeclarationSQL( Column* field ) override;
	virtual string                  BuildTableOptions( TableOptions options );
	virtual string                  BuildPartitionOptions( const TableOptions& options );
	virtual StringArray             GetAlterTableSQL( TableDiff* diff ) override;
	virtual StringArray             GetPreAlterTableIndexForeignKeySQL( TableDiff* diff ) override;
	virtual StringArray             GetPreAlterTableAlterPrimaryKeySQL( TableDiff* diff, Index* index );
	virtual StringArray             GetPreAlterTableAlterIndexForeignKeySQL( TableDiff* diff );
	virtual StringArray             GetPreAlterTableRenameIndexForeignKeySQL( TableDiff* diff );
	vector< ForeignKeyConstraint* > GetRemainingForeignKeyConstraintsRequiringRenamedIndexes( TableDiff* diff );
	virtual StringArray             GetPostAlterTableIndexForeignKeySQL( TableDiff* diff ) override;
	virtual StringArray             GetPostAlterTableRenameIndexForeignKeySQL( TableDiff* diff );
	virtual string                  GetCreateIndexSQLFlags( Index* index ) override;
	virtual string                  GetIntegerTypeDeclarationSQL( Column* columnDef ) override;
	virtual string                  GetBigIntTypeDeclarationSQL( Column* columnDef ) override;
	virtual string                  GetSmallIntTypeDeclarationSQL( Column* columnDef ) override;
	virtual string                  _getCommonIntegerTypeDeclarationSQL( Column* columnDef ) override;
	virtual string                  GetAdvancedForeignKeyOptionsSQL( ForeignKeyConstraint* foreignKey ) override;
	virtual string                  GetDropIndexSQL( Index* index, Table* table = nullptr ) override;
	virtual string                  GetDropIndexSQL( const string& index, const string& tableName = string() ) override;
	virtual string                  GetDropPrimaryKeySQL( const string& table );
	virtual string                  GetSetTransactionIsolationSQL( int level ) override;
	virtual string                  GetReadLockSQL() override;
	virtual size_t                  GetVarcharMaxLength() override;
	virtual size_t                  GetBinaryMaxLength() override;

	/**
	* MySQL commits a transaction implicitly when DROP TABLE is executed, however not
	* if DROP TEMPORARY TABLE is executed.
	*/
	virtual string GetDropTemporaryTableSQL( Table* table ) override;

	/**
	* Gets the SQL Snippet used to declare a BLOB column type.
	*     TINYBLOB   : 2 ^  8 - 1 = 255
	*     BLOB       : 2 ^ 16 - 1 = 65535
	*     MEDIUMBLOB : 2 ^ 24 - 1 = 16777215
	*     LONGBLOB   : 2 ^ 32 - 1 = 4294967295
	*
	* @param array field
	*
	* @return string
	*/
	virtual string GetBlobTypeDeclarationSQL( Column* field ) override;
	virtual string QuoteStringLiteral( const string& str ) override;

protected:
	virtual void InitializeTypeMappings() override;

public:
	static const size_t LENGTH_LIMIT_TINYTEXT   = 255;
    static const size_t LENGTH_LIMIT_TEXT       = 65535;
    static const size_t LENGTH_LIMIT_MEDIUMTEXT = 16777215;

    static const size_t LENGTH_LIMIT_TINYBLOB   = 255;
    static const size_t LENGTH_LIMIT_BLOB       = 65535;
    static const size_t LENGTH_LIMIT_MEDIUMBLOB = 16777215;
};
