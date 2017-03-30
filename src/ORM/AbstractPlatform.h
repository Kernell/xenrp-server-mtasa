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

#include "AbstractAsset.h"
#include "Table.h"
#include "Index.h"
#include "Column.h"
#include "TableDiff.h"

class AbstractPlatform
{
public:
	typedef vector< string >       StringArray;

public:
	AbstractPlatform();

	virtual string GetBooleanTypeDeclarationSQL        ( Column* columnDef ) = 0;
	virtual string GetIntegerTypeDeclarationSQL        ( Column* columnDef ) = 0;
	virtual string GetBigIntTypeDeclarationSQL         ( Column* columnDef ) = 0;
	virtual string GetSmallIntTypeDeclarationSQL       ( Column* columnDef ) = 0;
	virtual string _getCommonIntegerTypeDeclarationSQL ( Column* columnDef ) = 0;

	virtual string GetVarcharTypeDeclarationSQL        ( Column* field ); // CHAR/VARCHAR
	virtual string GetBinaryTypeDeclarationSQL         ( Column* field ); // BINARY/VARBINARY
	virtual string GetGuidTypeDeclarationSQL           ( Column* field ); // GUID/UUID
	virtual string GetJsonTypeDeclarationSQL           ( Column* field ); // JSON

	virtual string GetVarcharTypeDeclarationSQLSnippet ( size_t length = 255, bool fixed = false );
	virtual string GetBinaryTypeDeclarationSQLSnippet  ( size_t length = 255, bool fixed = false ); // BINARY / VARBINARY

public:
	virtual string      GetClobTypeDeclarationSQL( Column* field ) = 0;
	virtual string      GetBlobTypeDeclarationSQL( Column* field ) = 0;

	virtual string      GetIdentifierQuoteCharacter();
	virtual string      GetSqlCommentStartString();
	virtual string      GetSqlCommentEndString();
	virtual size_t      GetVarcharMaxLength();
	virtual size_t      GetVarcharDefaultLength();
	virtual size_t      GetBinaryMaxLength();
	virtual size_t      GetBinaryDefaultLength();
	virtual StringArray GetWildcards();
	virtual string      GetRegexpExpression();
	virtual string      GetGuidExpression();
	virtual string      GetAvgExpression( const string& column );
	virtual string      GetCountExpression( const string& column );
	virtual string      GetMaxExpression( const string& column );
	virtual string      GetMinExpression( const string& column );
	virtual string      GetSumExpression( const string& column );
	virtual string      GetMd5Expression( const string& column );
	virtual string      GetLengthExpression( const string& column );
	virtual string      GetSqrtExpression( const string& column );
	virtual string      GetRoundExpression( const string& column, int decimals = 0 );
	virtual string      GetModExpression( const string& expression1, const string& expression2 );
	virtual string      GetTrimExpression( const string& str, int pos = TRIM_UNSPECIFIED, const string& _char = string() );
	virtual string      GetRtrimExpression( const string& str );
	virtual string      GetLtrimExpression( const string& str );
	virtual string      GetUpperExpression( const string& str );
	virtual string      GetLowerExpression( const string& str );
	virtual string      GetLocateExpression( const string& str, const string& substr, int startPos = 0 );
	virtual string      GetNowExpression();
	virtual string      GetSubstringExpression( const string& value, const string& from, size_t length = 0 );
	virtual string      GetConcatExpression( const vector< string >& args );
	virtual string      GetNotExpression( const string& expression );
	virtual string      GetIsNullExpression( const string& expression );
	virtual string      GetIsNotNullExpression( const string& expression );
	virtual string      GetBetweenExpression( const string& expression, const string& value1, const string& value2 );
	virtual string      GetAcosExpression( const string& value );
	virtual string      GetSinExpression( const string& value );
	virtual string      GetPiExpression();
	virtual string      GetCosExpression( const string& value );
	virtual string      GetDateDiffExpression( const string& date1, const string& date2 );
	virtual string      GetDateAddSecondsExpression( const string& date, int seconds );
	virtual string      GetDateSubSecondsExpression( const string& date, int seconds );
	virtual string      GetDateAddMinutesExpression( const string& date, int minutes );
	virtual string      GetDateSubMinutesExpression( const string& date, int minutes );
	virtual string      GetDateAddHourExpression( const string& date, int hours );
	virtual string      GetDateSubHourExpression( const string& date, int hours );
	virtual string      GetDateAddDaysExpression( const string& date, int days );
	virtual string      GetDateSubDaysExpression( const string& date, int days );
	virtual string      GetDateAddWeeksExpression( const string& date, int weeks );
	virtual string      GetDateSubWeeksExpression( const string& date, int weeks );
	virtual string      GetDateAddMonthExpression( const string& date, int months );
	virtual string      GetDateSubMonthExpression( const string& date, int months );
	virtual string      GetDateAddQuartersExpression( const string& date, int quarters );
	virtual string      GetDateSubQuartersExpression( const string& date, int quarters );
	virtual string      GetDateAddYearsExpression( const string& date, int years );
	virtual string      GetDateSubYearsExpression( const string& date, int years );
	virtual string      GetDateArithmeticIntervalExpression( const string& date, const string& op, int interval, const string& unit );
	virtual string      GetBitAndComparisonExpression( const string& value1, const string& value2 );
	virtual string      GetBitOrComparisonExpression( const string& value1, const string& value2 );
	virtual string      GetForUpdateSQL();
	virtual string      AppendLockHint( const string& fromClause, int lockMode );
	virtual string      GetReadLockSQL();
	virtual string      GetWriteLockSQL();
	virtual string      GetDropDatabaseSQL( const string& database );
	virtual string      GetDropTableSQL( Table* table );
	virtual string      GetDropTableSQL( const string& table );
	virtual string      GetDropTemporaryTableSQL( Table* table );
	virtual string      GetDropIndexSQL( Index* index, Table* table = nullptr );
	virtual string      GetDropIndexSQL( const string& index, const string& tableName = string() );
	virtual string      GetDropConstraintSQL( const string& constraint, const string& table );
	virtual string      GetDropForeignKeySQL( ForeignKeyConstraint* foreignKey, Table* table );
	virtual string      GetDropForeignKeySQL( const string& foreignKey, const string& table );
	virtual StringArray GetCreateTableSQL( Table* table, int createFlags = CREATE_INDEXES );
	virtual string      GetCommentOnColumnSQL( const string& tableName, const string& columnName, const string& comment );

	virtual string      GetCreateTemporaryTableSnippetSQL();
	virtual string      GetCreateConstraintSQL( Index* constraint, Table* table );
	virtual string      GetCreateConstraintSQL( ForeignKeyConstraint* constraint, Table* table );
	virtual string      GetCreateIndexSQL( Index* index, Table* table );
	virtual string      GetCreateIndexSQL( Index* index, const string& tableName );
	virtual string      GetPartialIndexSQL( Index* index );
	virtual string      GetCreateIndexSQLFlags( Index* index );
	virtual string      GetCreatePrimaryKeySQL( Index* index, Table* table );
	virtual string      GetCreatePrimaryKeySQL( Index* index, const string& table );
	virtual string      GetCreateSchemaSQL( const string& schemaName );
	virtual string      QuoteIdentifier( const string& str );
	virtual string      QuoteSingleIdentifier( const string& str );
	virtual string      GetCreateForeignKeySQL( ForeignKeyConstraint* foreignKey, Table* table );
	virtual string      GetCreateForeignKeySQL( ForeignKeyConstraint* foreignKey, const string& table );
	virtual StringArray GetAlterTableSQL( TableDiff* diff );

	virtual StringArray GetPreAlterTableIndexForeignKeySQL( TableDiff* diff );
	virtual StringArray GetPostAlterTableIndexForeignKeySQL( TableDiff* diff );
	StringArray         GetRenameIndexSQL( const string& oldIndexName, Index* index, const string& tableName );

public:
	virtual string GetColumnDeclarationListSQL( const vector< Column* >& fields );
	virtual string GetColumnDeclarationSQL( Column* field );
	virtual string GetDecimalTypeDeclarationSQL( Column* columnDef );
	virtual string GetDefaultValueDeclarationSQL( Column* field );
	virtual string GetCheckDeclarationSQL( const vector< Column* >& definition );
	virtual string GetUniqueConstraintDeclarationSQL( const string& name, Index* index );
	virtual string GetIndexDeclarationSQL( const string& name, Index* index );
	virtual string GetCustomTypeDeclarationSQL( Column* columnDef );
	virtual string GetIndexFieldDeclarationListSQL( const map< string, Column* >& fields );
	virtual string GetIndexFieldDeclarationListSQL( const vector< string >& fields );
	virtual string GetTemporaryTableSQL();
	virtual string GetTemporaryTableName( const string& tableName );
	virtual string GetForeignKeyDeclarationSQL( ForeignKeyConstraint* foreignKey );
	virtual string GetAdvancedForeignKeyOptionsSQL( ForeignKeyConstraint* foreignKey );
	virtual string GetForeignKeyReferentialActionSQL( const string& action );
	virtual string GetForeignKeyBaseDeclarationSQL( ForeignKeyConstraint* foreignKey );
	virtual string GetUniqueFieldDeclarationSQL();
	virtual string GetColumnCharsetDeclarationSQL( const string& charset );
	virtual string GetColumnCollationDeclarationSQL( const string& collation );
	virtual bool   PrefersSequences();
	virtual bool   PrefersIdentityColumns();
	virtual string ConvertBooleans( bool item );
	virtual string ConvertBooleans( const string& item );
	virtual bool   ConvertFromBoolean( const string& item );
	virtual string ConvertBooleansToDatabaseValue( bool item );
	virtual string GetCurrentDateSQL();
	virtual string GetCurrentTimeSQL();
	virtual string GetCurrentTimestampSQL();
	string         _getTransactionIsolationLevelSQL( int level );
	virtual string GetListDatabasesSQL();
	virtual string GetListNamespacesSQL();
	virtual string GetListSequencesSQL( const string& database );
	virtual string GetListTableConstraintsSQL( const string& table );
	virtual string GetListTableColumnsSQL( const string& table, const string& database = string() );
	virtual string GetListTablesSQL();
	virtual string GetListUsersSQL();
	virtual string GetListViewsSQL( const string& database );
	virtual string GetListTableIndexesSQL( const string& table, const string& currentDatabase = string() );
	virtual string GetListTableForeignKeysSQL( const string& table, const string& database = string() );
	virtual string GetCreateViewSQL( const string& name, const string& sql );
	virtual string GetDropViewSQL( const string& name );
	virtual string GetDropSequenceSQL( const string& sequence );
	virtual string GetSequenceNextValSQL( const string& sequenceName );
	virtual string GetCreateDatabaseSQL( const string& database );
	virtual string GetSetTransactionIsolationSQL( int level );
	virtual string GetDateTimeTypeDeclarationSQL( Column* fieldDeclaration );
	virtual string GetDateTimeTzTypeDeclarationSQL( Column* fieldDeclaration );
	virtual string GetDateTypeDeclarationSQL( Column* fieldDeclaration );
	virtual string GetTimeTypeDeclarationSQL( Column* fieldDeclaration );
	virtual string GetFloatTypeDeclarationSQL( Column* fieldDeclaration );
	virtual int GetDefaultTransactionIsolationLevel();
	virtual bool SupportsSequences();
	virtual bool SupportsIdentityColumns();
	virtual bool UsesSequenceEmulatedIdentityColumns();
	virtual string GetIdentitySequenceName( const string& tableName, const string& columnName );
	virtual bool SupportsIndexes();
	virtual bool SupportsPartialIndexes();
	virtual bool SupportsAlterTable();
	virtual bool SupportsTransactions();
	virtual bool SupportsSavepoints();
	virtual bool SupportsReleaseSavepoints();
	virtual bool SupportsPrimaryConstraints();
	virtual bool SupportsForeignKeyConstraints();
	virtual bool SupportsForeignKeyOnUpdate();
	virtual bool SupportsSchemas();
	virtual bool CanEmulateSchemas();
	virtual string GetDefaultSchemaName();
	virtual bool SupportsCreateDropDatabase();
	virtual bool SupportsGettingAffectedRows();
	virtual bool SupportsInlineColumnComments();
	virtual bool SupportsCommentOnStatement();
	virtual bool HasNativeGuidType();
	virtual bool HasNativeJsonType();
	virtual bool SupportsViews();
	virtual bool SupportsColumnCollation();
	virtual string GetDateTimeFormatString();
	virtual string GetDateTimeTzFormatString();
	virtual string GetDateFormatString();
	virtual string GetTimeFormatString();
	virtual string ModifyLimitQuery( const string& query, int limit = -1, int offset = -1 );
	virtual string DoModifyLimitQuery( const string& _query, int limit = -1, int offset = -1 );
	virtual bool SupportsLimitOffset();
	virtual string GetSQLResultCasing( const string& column );
	virtual string FixSchemaElementName( const string& schemaElementName );
	virtual int GetMaxIdentifierLength();
	virtual string GetEmptyIdentityInsertSQL( const string& tableName, const string& identifierColumnName );
	virtual string GetTruncateTableSQL( const string& tableName, bool cascade = false );
	virtual string GetDummySelectSQL();
	virtual string CreateSavePoint( const string& savepoint );
	virtual string ReleaseSavePoint( const string& savepoint );
	virtual string RollbackSavePoint( const string& savepoint );
	virtual string QuoteStringLiteral( const string& str );
	virtual string GetStringLiteralQuoteCharacter();
	virtual string GetDoctrineTypeMapping( const string& dbType );

protected:
	virtual void        InitializeTypeMappings() = 0;
	virtual StringArray _getCreateTableSQL( const string& tableName, const vector< Column* >& columns, const TableOptions& options );
	StringArray         _getAlterTableIndexForeignKeySQL( TableDiff* diff );

public:
	static const int CREATE_INDEXES               = 1;
	static const int CREATE_FOREIGNKEYS           = 2;

	static const string DATE_INTERVAL_UNIT_SECOND;
	static const string DATE_INTERVAL_UNIT_MINUTE;
	static const string DATE_INTERVAL_UNIT_HOUR;  
	static const string DATE_INTERVAL_UNIT_DAY;   
	static const string DATE_INTERVAL_UNIT_WEEK;  
	static const string DATE_INTERVAL_UNIT_MONTH; 
	static const string DATE_INTERVAL_UNIT_QUARTER;
	static const string DATE_INTERVAL_UNIT_YEAR;
	
	static const int TRIM_UNSPECIFIED              = 0;
	static const int TRIM_LEADING                  = 1;
	static const int TRIM_TRAILING                 = 2;
	static const int TRIM_BOTH                     = 3;

	static const int TRANSACTION_READ_UNCOMMITTED  = 1;
	static const int TRANSACTION_READ_COMMITTED    = 2;
	static const int TRANSACTION_REPEATABLE_READ   = 3;
	static const int TRANSACTION_SERIALIZABLE      = 4;

protected:
	map< string, string > TypeMapping;
};

