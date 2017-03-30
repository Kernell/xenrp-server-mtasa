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
#include "AbstractPlatform.h"

const string AbstractPlatform::DATE_INTERVAL_UNIT_SECOND  = "SECOND";
const string AbstractPlatform::DATE_INTERVAL_UNIT_MINUTE  = "MINUTE";
const string AbstractPlatform::DATE_INTERVAL_UNIT_HOUR    = "HOUR";
const string AbstractPlatform::DATE_INTERVAL_UNIT_DAY     = "DAY";
const string AbstractPlatform::DATE_INTERVAL_UNIT_WEEK    = "WEEK";
const string AbstractPlatform::DATE_INTERVAL_UNIT_MONTH   = "MONTH";
const string AbstractPlatform::DATE_INTERVAL_UNIT_QUARTER = "QUARTER";
const string AbstractPlatform::DATE_INTERVAL_UNIT_YEAR    = "YEAR";

AbstractPlatform::AbstractPlatform()
{
}

string AbstractPlatform::GetVarcharTypeDeclarationSQL( Column* field )
{
	if( field->Length == 0 )
	{
		field->Length = this->GetVarcharDefaultLength();
	}

	if( field->Length > this->GetVarcharMaxLength() )
	{
		return this->GetClobTypeDeclarationSQL( field );
	}

	return this->GetVarcharTypeDeclarationSQLSnippet( field->Length, field->Fixed );
}

string AbstractPlatform::GetBinaryTypeDeclarationSQL( Column* field )
{
	if( field->Length == 0 )
	{
		field->Length = this->GetBinaryDefaultLength();
	}

	if( field->Length > this->GetBinaryMaxLength() )
	{
		return this->GetBlobTypeDeclarationSQL( field );
	}

	return this->GetBinaryTypeDeclarationSQLSnippet( field->Length, field->Fixed );
}

string AbstractPlatform::GetGuidTypeDeclarationSQL( Column* field )
{
	field->Length = 36;
	field->Fixed  = true;

	return this->GetVarcharTypeDeclarationSQL( field );
}

string AbstractPlatform::GetJsonTypeDeclarationSQL( Column* field )
{
	return this->GetClobTypeDeclarationSQL( field );
}

string AbstractPlatform::GetVarcharTypeDeclarationSQLSnippet( size_t length, bool fixed )
{
	throw new exception( "VARCHARs not supported by Platform" );
}

string AbstractPlatform::GetBinaryTypeDeclarationSQLSnippet( size_t length, bool fixed )
{
	throw new exception( "BINARY/VARBINARY column types are not supported by this platform" );
}

string AbstractPlatform::GetIdentifierQuoteCharacter()
{
	return "\"";
}

string AbstractPlatform::GetSqlCommentStartString()
{
	return "--";
}

string AbstractPlatform::GetSqlCommentEndString()
{
	return "\n"; 
}

size_t AbstractPlatform::GetVarcharMaxLength()
{
	return 4000;
}

size_t AbstractPlatform::GetVarcharDefaultLength()
{
	return 255;
}

size_t AbstractPlatform::GetBinaryMaxLength()
{
	return 4000;
}

size_t AbstractPlatform::GetBinaryDefaultLength()
{
	return 255;
}

vector< string > AbstractPlatform::GetWildcards()
{
	return { "%", "_" };
}

string AbstractPlatform::GetRegexpExpression()
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

string AbstractPlatform::GetGuidExpression()
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

string AbstractPlatform::GetAvgExpression( const string& column )
{
	return "AVG(" + column + ")";
}

string AbstractPlatform::GetCountExpression( const string& column )
{
	return "COUNT(" + column + ")";
}

string AbstractPlatform::GetMaxExpression( const string& column )
{
	return "MAX(" + column + ")";
}

string AbstractPlatform::GetMinExpression( const string& column )
{
	return "MIN(" + column + ")";
}

string AbstractPlatform::GetSumExpression( const string& column )
{
	return "SUM(" + column + ")";
}

string AbstractPlatform::GetMd5Expression( const string& column )
{
	return "MD5("+ column + ")";
}

string AbstractPlatform::GetLengthExpression( const string& column )
{
	return "LENGTH(" + column + ")";
}

string AbstractPlatform::GetSqrtExpression( const string& column )
{
	return "SQRT(" + column + ")";
}

string AbstractPlatform::GetRoundExpression( const string& column, int decimals )
{
	stringstream stream;

	stream << "ROUND(" << column << ", " << decimals << ")";

	return stream.str();
}

string AbstractPlatform::GetModExpression( const string& expression1, const string& expression2 )
{
	return "MOD(" + expression1 + ", " + expression2 + ")";
}

string AbstractPlatform::GetTrimExpression( const string& str, int pos, const string& _char )
{
	string expression;

	switch( pos )
	{
		case TRIM_LEADING:
		{
			expression = "LEADING ";

			break;
		}
		case TRIM_TRAILING:
		{
			expression = "TRAILING ";

			break;
		}
		case TRIM_BOTH:
		{
			expression = "BOTH ";

			break;
		}
	}

	if( !_char.empty() )
	{
		expression += _char + " ";
	}

	if( pos || !_char.empty() )
	{
		expression += "FROM ";
	}

	return "TRIM(" + expression + str + ")";
}

string AbstractPlatform::GetRtrimExpression( const string& str )
{
	return "RTRIM(" + str + ")";
}

string AbstractPlatform::GetLtrimExpression( const string& str )
{
	return "LTRIM(" + str + ")";
}

string AbstractPlatform::GetUpperExpression( const string& str )
{
	return "UPPER(" + str + ")";
}

string AbstractPlatform::GetLowerExpression( const string& str )
{
	return "LOWER(" + str + ")";
}

string AbstractPlatform::GetLocateExpression( const string& str, const string& substr, int startPos )
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

string AbstractPlatform::GetNowExpression()
{
	return "NOW()";
}

string AbstractPlatform::GetSubstringExpression( const string& value, const string& from, size_t length )
{
	if( length == 0 )
	{
		return "SUBSTRING(" + value + " FROM " + from + ")";
	}

	stringstream stream;

	stream << "SUBSTRING(" << value << " FROM " << from << " FOR " << length << ")";

	return stream.str();
}

string AbstractPlatform::GetConcatExpression( const vector< string >& args )
{
	return VectorJoin( args, "||" );
}

string AbstractPlatform::GetNotExpression( const string& expression )
{
	return "NOT(" + expression + ")";
}

string AbstractPlatform::GetIsNullExpression( const string& expression )
{
	return expression + " IS NULL";
}

string AbstractPlatform::GetIsNotNullExpression( const string& expression )
{
	return expression + " IS NOT NULL";
}

string AbstractPlatform::GetBetweenExpression( const string& expression, const string& value1, const string& value2 )
{
	return expression + " BETWEEN " + value1 + " AND " + value2;
}

string AbstractPlatform::GetAcosExpression( const string& value )
{
	return "ACOS(" + value + ")";
}

string AbstractPlatform::GetSinExpression( const string& value )
{
	return "SIN(" + value + ")";
}

string AbstractPlatform::GetPiExpression()
{
	return "PI()";
}

string AbstractPlatform::GetCosExpression( const string& value )
{
	return "COS(" + value + ")";
}

string AbstractPlatform::GetDateDiffExpression( const string& date1, const string& date2 )
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

string AbstractPlatform::GetDateAddSecondsExpression( const string& date, int seconds )
{
	return this->GetDateArithmeticIntervalExpression( date, "+", seconds, DATE_INTERVAL_UNIT_SECOND );
}

string AbstractPlatform::GetDateSubSecondsExpression( const string& date, int seconds )
{
	return this->GetDateArithmeticIntervalExpression( date, "-", seconds, DATE_INTERVAL_UNIT_SECOND );
}

string AbstractPlatform::GetDateAddMinutesExpression( const string& date, int minutes )
{
	return this->GetDateArithmeticIntervalExpression( date, "+", minutes, DATE_INTERVAL_UNIT_MINUTE );
}

string AbstractPlatform::GetDateSubMinutesExpression( const string& date, int minutes )
{
	return this->GetDateArithmeticIntervalExpression( date, "-", minutes, DATE_INTERVAL_UNIT_MINUTE );
}

string AbstractPlatform::GetDateAddHourExpression( const string& date, int hours )
{
	return this->GetDateArithmeticIntervalExpression( date, "+", hours, DATE_INTERVAL_UNIT_HOUR );
}

string AbstractPlatform::GetDateSubHourExpression( const string& date, int hours )
{
	return this->GetDateArithmeticIntervalExpression( date, "-", hours, DATE_INTERVAL_UNIT_HOUR );
}

string AbstractPlatform::GetDateAddDaysExpression( const string& date, int days )
{
	return this->GetDateArithmeticIntervalExpression( date, "+", days, DATE_INTERVAL_UNIT_DAY );
}

string AbstractPlatform::GetDateSubDaysExpression( const string& date, int days )
{
	return this->GetDateArithmeticIntervalExpression( date, "-", days, DATE_INTERVAL_UNIT_DAY );
}

string AbstractPlatform::GetDateAddWeeksExpression( const string& date, int weeks )
{
	return this->GetDateArithmeticIntervalExpression( date, "+", weeks, DATE_INTERVAL_UNIT_WEEK );
}

string AbstractPlatform::GetDateSubWeeksExpression( const string& date, int weeks )
{
	return this->GetDateArithmeticIntervalExpression( date, "-", weeks, DATE_INTERVAL_UNIT_WEEK );
}

string AbstractPlatform::GetDateAddMonthExpression( const string& date, int months )
{
	return this->GetDateArithmeticIntervalExpression( date, "+", months, DATE_INTERVAL_UNIT_MONTH );
}

string AbstractPlatform::GetDateSubMonthExpression( const string& date, int months )
{
	return this->GetDateArithmeticIntervalExpression( date, "-", months, DATE_INTERVAL_UNIT_MONTH );
}

string AbstractPlatform::GetDateAddQuartersExpression( const string& date, int quarters )
{
	return this->GetDateArithmeticIntervalExpression( date, "+", quarters, DATE_INTERVAL_UNIT_QUARTER );
}

string AbstractPlatform::GetDateSubQuartersExpression( const string& date, int quarters )
{
	return this->GetDateArithmeticIntervalExpression( date, "-", quarters, DATE_INTERVAL_UNIT_QUARTER );
}

string AbstractPlatform::GetDateAddYearsExpression( const string& date, int years )
{
	return this->GetDateArithmeticIntervalExpression( date, "+", years, DATE_INTERVAL_UNIT_YEAR );
}

string AbstractPlatform::GetDateSubYearsExpression( const string& date, int years )
{
	return this->GetDateArithmeticIntervalExpression( date, "-", years, DATE_INTERVAL_UNIT_YEAR );
}

string AbstractPlatform::GetDateArithmeticIntervalExpression( const string& date, const string& op, int interval, const string& unit )
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

string AbstractPlatform::GetBitAndComparisonExpression( const string& value1, const string& value2 )
{
	return "(" + value1 + " & " + value2 + ")";
}

string AbstractPlatform::GetBitOrComparisonExpression( const string& value1, const string& value2 )
{
	return "(" + value1 + " | " + value2 + ")";
}

string AbstractPlatform::GetForUpdateSQL()
{
	return "FOR UPDATE";
}

string AbstractPlatform::AppendLockHint( const string& fromClause, int lockMode )
{
	return fromClause;
}

string AbstractPlatform::GetReadLockSQL()
{
	return this->GetForUpdateSQL();
}

string AbstractPlatform::GetWriteLockSQL()
{
	return this->GetForUpdateSQL();
}

string AbstractPlatform::GetDropDatabaseSQL( const string& database )
{
	return "DROP DATABASE `" + database + "`";
}

string AbstractPlatform::GetDropTableSQL( Table* table )
{
	return "DROP DATABASE " + table->GetQuotedName();
}

string AbstractPlatform::GetDropTableSQL( const string& table )
{
	return "DROP TABLE `" + table + "`";
}

string AbstractPlatform::GetDropTemporaryTableSQL( Table* table )
{
	return "DROP TABLE `" + table->GetQuotedName() + "`";
}

string AbstractPlatform::GetDropIndexSQL( Index* index, Table* table )
{
	return "DROP INDEX " + index->GetQuotedName();
}

string AbstractPlatform::GetDropIndexSQL( const string& index, const string& tableName )
{
	return "DROP INDEX `" + index + "`";
}

string AbstractPlatform::GetDropConstraintSQL( const string& constraint, const string& table )
{
	return "ALTER TABLE `" + table + "` DROP CONSTRAINT `" + constraint + "`";
}

string AbstractPlatform::GetDropForeignKeySQL( ForeignKeyConstraint* foreignKey, Table* table )
{
	return "ALTER TABLE " + table->GetQuotedName() + " DROP FOREIGN KEY " + foreignKey->GetQuotedName();
}

string AbstractPlatform::GetDropForeignKeySQL( const string& foreignKey, const string& table )
{
	return "ALTER TABLE `" + table + "` DROP FOREIGN KEY `" + foreignKey + "`";
}

vector< string > AbstractPlatform::GetCreateTableSQL( Table* table, int createFlags )
{
	if( table->GetColumns().size() == 0 )
	{
		throw new exception( ( "DBALException::noColumnsSpecifiedForTable( " + table->GetName() + " )" ).c_str() );
	}

	string tableName = table->GetQuotedName();
	TableOptions options = TableOptions( *table->GetOptions() );

	options.UniqueConstraints.clear();
	options.Indexes.clear();
	options.Primary.clear();

	if( createFlags & CREATE_INDEXES )
	{
		for( const auto& index : table->GetIndexes() )
		{
			if( index->IsPrimary() )
			{
				options.Primary      = index->GetQuotedColumns();
				options.PrimaryIndex = index;
			}
			else
			{
				options.Indexes[ index->GetQuotedName() ] = index;
			}
		}
	}

	vector< Column* > columns;

	for( Column* column : table->GetColumns() )
	{
		if( column->Type->GetID() == ColumnType::STRING && column->Length == 0 )
		{
			column->Length = 255;
		}

		for( const string& s : options.Primary )
		{
			if( column->GetName() == s )
			{
				column->Primary = true;

				break;
			}
		}

		columns.push_back( column );
	}

	if( createFlags & CREATE_FOREIGNKEYS )
	{
		options.ForeignKeys.clear();

		for( const auto& iter : table->GetForeignKeys() )
		{
			options.ForeignKeys.push_back( iter );
		}
	}

	vector< string > sql = this->_getCreateTableSQL( tableName, columns, options );

	if( this->SupportsCommentOnStatement() )
	{
		for( Column* column : table->GetColumns() )
		{
			string comment = column->GetComment();

			if( !comment.empty() )
			{
				sql.push_back( this->GetCommentOnColumnSQL( tableName, column->GetQuotedName(), comment ) );
			}
		}
	}

	return sql;
}

string AbstractPlatform::GetCommentOnColumnSQL( const string& tableName, const string& columnName, const string& comment )
{
	return "COMMENT ON COLUMN `" + tableName + "` + `" + columnName + "` IS " + this->QuoteStringLiteral( comment );
}

string AbstractPlatform::GetDoctrineTypeMapping( const string& _dbType )
{
	if( this->TypeMapping.size() == 0 )
	{
		this->InitializeTypeMappings();
	}

	string dbType = strtolower( _dbType );

	if( this->TypeMapping.count( dbType ) == 0 )
	{
		throw new exception( ( "Unknown database type " + dbType + " requested" ).c_str() );
	}

	return this->TypeMapping.at( dbType );
}

vector< string > AbstractPlatform::_getCreateTableSQL( const string& tableName, const vector< Column* >& columns, const TableOptions& options )
{
	string columnListSql = this->GetColumnDeclarationListSQL( columns );

	if( options.UniqueConstraints.size() > 0 )
	{
		for( const auto& iter : options.UniqueConstraints )
		{
			columnListSql += ", " + this->GetUniqueConstraintDeclarationSQL( iter.first, iter.second );
		}
	}

	if( options.Primary.size() > 0 )
	{
		columnListSql += ", PRIMARY KEY(" + VectorJoin( options.Primary, ", " ) + ")";
	}

	if( options.Indexes.size() > 0 )
	{
		for( const auto& iter : options.Indexes )
		{
			columnListSql += ", " + this->GetIndexDeclarationSQL( iter.first, iter.second );
		}
	}

	string query = "CREATE TABLE " + tableName + " (" + columnListSql;

	string check = this->GetCheckDeclarationSQL( columns );

	if( !check.empty() )
	{
		query += ", " + check;
	}

	query += ")";

	AbstractPlatform::StringArray sql;

	sql.push_back( query );

	if( options.ForeignKeys.size() > 0 )
	{
		for( const auto& definition : options.ForeignKeys )
		{
			sql.push_back( this->GetCreateForeignKeySQL( definition, tableName ) );
		}
	}

	return sql;
}

string AbstractPlatform::GetCreateTemporaryTableSnippetSQL()
{
	return "CREATE TEMPORARY TABLE";
}

string AbstractPlatform::GetCreateConstraintSQL( Index* constraint, Table* table )
{
	string tableName  = table->GetQuotedName();
	string query      = "ALTER TABLE " + tableName + " ADD CONSTRAINT " + constraint->GetQuotedName();
	string columnList = "(" + VectorJoin( constraint->GetQuotedColumns(), ", " ) + ")";

	string referencesClause = "";

	if( constraint->IsPrimary() )
	{
		query += " PRIMARY KEY";
	}
	else if( constraint->IsUnique() )
	{
		query += " UNIQUE";
	}
	else
	{
		throw new exception( "Can only create primary or unique constraints, no common Index*es with getCreateConstraintSQL()." );
	}

	query += " " + columnList + referencesClause;

	return query;
}

string AbstractPlatform::GetCreateConstraintSQL( ForeignKeyConstraint* constraint, Table* table )
{
	string tableName  = table->GetQuotedName();
	string query      = "ALTER TABLE " + tableName + " ADD CONSTRAINT " + constraint->GetQuotedName();
	string columnList = "(" + VectorJoin( constraint->GetQuotedColumns(), ", " ) + ")";

	string referencesClause = "";

	query += " FOREIGN KEY";

	referencesClause = " REFERENCES " + constraint->GetQuotedForeignTableName() + " (" + VectorJoin( constraint->GetQuotedForeignColumns(), ", " ) + ")";

	query += " " + columnList + referencesClause;

	return query;
}

string AbstractPlatform::GetCreateIndexSQL( Index* index, Table* table )
{
	string           tableName = table->GetQuotedName();
	string           name      = index->GetQuotedName();
	vector< string > columns   = index->GetQuotedColumns();

	if( columns.size() == 0 )
	{
		throw new exception( "Incomplete definition 'columns' required" );
	}

	if( index->IsPrimary() )
	{
		return this->GetCreatePrimaryKeySQL( index, table );
	}

	string query = "CREATE " + this->GetCreateIndexSQLFlags( index ) + "INDEX " + name + " ON " + table->GetQuotedName();

	query += " (" + this->GetIndexFieldDeclarationListSQL( columns ) + ")" + this->GetPartialIndexSQL( index );

	return query;
}

string AbstractPlatform::GetCreateIndexSQL( Index* index, const string& tableName )
{
	string           name    = index->GetQuotedName();
	vector< string > columns = index->GetQuotedColumns();

	if( columns.size() == 0 )
	{
		throw new exception( "Incomplete definition 'columns' required" );
	}

	if( index->IsPrimary() )
	{
		return this->GetCreatePrimaryKeySQL( index, tableName );
	}

	string query = "CREATE " + this->GetCreateIndexSQLFlags( index ) + "INDEX " + name + " ON `" + tableName + "`";

	query += " (" + this->GetIndexFieldDeclarationListSQL( columns ) + ")" + this->GetPartialIndexSQL( index );

	return query;
}

string AbstractPlatform::GetPartialIndexSQL( Index* index )
{
	if( this->SupportsPartialIndexes() && index->HasOption( "where" ) )
	{
		return " WHERE " + index->GetOption( "where" );
	}

	return "";
}

string AbstractPlatform::GetCreateIndexSQLFlags( Index* index )
{
	return index->IsUnique() ? "UNIQUE " : "";
}

string AbstractPlatform::GetCreatePrimaryKeySQL( Index* index, Table* table )
{
	return "ALTER TABLE " + table->GetQuotedName() + " ADD PRIMARY KEY (" + this->GetIndexFieldDeclarationListSQL( index->GetQuotedColumns() ) + ")";
}

string AbstractPlatform::GetCreatePrimaryKeySQL( Index* index, const string& table )
{
	return "ALTER TABLE `" + table + "` ADD PRIMARY KEY (" + this->GetIndexFieldDeclarationListSQL( index->GetQuotedColumns() ) + ")";
}

string AbstractPlatform::GetCreateSchemaSQL( const string& schemaName )
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

string AbstractPlatform::QuoteIdentifier( const string& str )
{
	vector< string > parts;

	vector< string > strings = StringSplit( str, " + " );

	if( strings.size() > 0 )
	{
		for( const string& s : strings )
		{
			parts.push_back( this->QuoteSingleIdentifier( s ) );
		}

		return VectorJoin( parts, " + " );
	}

	return this->QuoteSingleIdentifier( str );
}

string AbstractPlatform::QuoteSingleIdentifier( const string& str )
{
	string c = this->GetIdentifierQuoteCharacter();

	return c + str + c;
}

string AbstractPlatform::GetCreateForeignKeySQL( ForeignKeyConstraint* foreignKey, Table* table )
{
	return "ALTER TABLE " + table->GetQuotedName() + " ADD " + this->GetForeignKeyDeclarationSQL( foreignKey );
}

string AbstractPlatform::GetCreateForeignKeySQL( ForeignKeyConstraint* foreignKey, const string& table )
{
	return "ALTER TABLE `" + table + "` ADD " + this->GetForeignKeyDeclarationSQL( foreignKey );
}

AbstractPlatform::StringArray AbstractPlatform::GetAlterTableSQL( TableDiff* diff )
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

AbstractPlatform::StringArray AbstractPlatform::GetPreAlterTableIndexForeignKeySQL( TableDiff* diff )
{
	string tableName = diff->GetName();

	AbstractPlatform::StringArray sql;

	if( this->SupportsForeignKeyConstraints() )
	{
		for( const auto& foreignKey : diff->RemovedForeignKeys )
		{
			sql.push_back( this->GetDropForeignKeySQL( foreignKey->GetName(), tableName ) );
		}

		for( const auto& foreignKey : diff->ChangedForeignKeys )
		{
			sql.push_back( this->GetDropForeignKeySQL( foreignKey->GetName(), tableName ) );
		}
	}

	for( const auto& iter : diff->RemovedIndexes )
	{
		sql.push_back( this->GetDropIndexSQL( iter ) );
	}

	for( const auto& iter : diff->ChangedIndexes )
	{
		sql.push_back( this->GetDropIndexSQL( iter ) );
	}

	return sql;
}

AbstractPlatform::StringArray AbstractPlatform::GetPostAlterTableIndexForeignKeySQL( TableDiff* diff )
{
	string tableName = diff->GetNewName().length() ? diff->GetNewName() : diff->GetName();

	AbstractPlatform::StringArray sql;

	if( this->SupportsForeignKeyConstraints() )
	{
		for( const auto& foreignKey : diff->AddedForeignKeys )
		{
			sql.push_back( this->GetCreateForeignKeySQL( foreignKey, tableName ) );
		}

		for( const auto& foreignKey : diff->ChangedForeignKeys )
		{
			sql.push_back( this->GetCreateForeignKeySQL( foreignKey, tableName ) );
		}
	}

	for( const auto& iter : diff->AddedIndexes )
	{
		sql.push_back( this->GetCreateIndexSQL( iter, tableName ) );
	}

	for( const auto& iter : diff->ChangedIndexes )
	{
		sql.push_back( this->GetCreateIndexSQL( iter, tableName ) );
	}

	for( const auto& index : diff->RenamedIndexes )
	{
		for( const string& str : this->GetRenameIndexSQL( index->GetQuotedName(), index, tableName ) )
		{
			sql.push_back( str );
		}
	}

	return sql;
}

AbstractPlatform::StringArray AbstractPlatform::GetRenameIndexSQL( const string& oldIndexName, Index* index, const string& tableName )
{
	AbstractPlatform::StringArray arr;

	arr.push_back( this->GetDropIndexSQL( oldIndexName, tableName ) );
	arr.push_back( this->GetCreateIndexSQL( index, tableName ) );

	return arr;
}

AbstractPlatform::StringArray AbstractPlatform::_getAlterTableIndexForeignKeySQL( TableDiff* diff )
{
	AbstractPlatform::StringArray sql1 = this->GetPreAlterTableIndexForeignKeySQL( diff );
	AbstractPlatform::StringArray sql2 = this->GetPostAlterTableIndexForeignKeySQL( diff );

	AbstractPlatform::StringArray sql;

	sql.reserve( sql1.size() + sql2.size() );
	sql.insert( sql.end(), sql1.begin(), sql1.end() );
	sql.insert( sql.end(), sql2.begin(), sql2.end() );

	return sql;
}

string AbstractPlatform::GetColumnDeclarationListSQL( const vector< Column* >& fields )
{
	AbstractPlatform::StringArray queryFields;

	for( Column* column : fields )
	{
		queryFields.push_back( this->GetColumnDeclarationSQL( column ) );
	}

	return VectorJoin( queryFields, ", " );
}

string AbstractPlatform::GetColumnDeclarationSQL( Column* field )
{
	string columnDef;

	if( field->ColumnDefinition.size() > 0 )
	{
		columnDef = this->GetCustomTypeDeclarationSQL( field );
	}
	else
	{
		string default = this->GetDefaultValueDeclarationSQL( field );

		string charset   = !field->Charset.empty() ? " " + this->GetColumnCharsetDeclarationSQL( field->Charset ) : "";
		string collation = !field->Collation.empty() ? " " + this->GetColumnCollationDeclarationSQL( field->Collation ) : "";
		string notnull   = field->NotNull ? " NOT NULL" : "";
		string unique    = field->Unique ? " " + this->GetUniqueFieldDeclarationSQL() : "";
		string check     = field->Options.count( "check" ) ? " " + field->Options[ "check" ] : "";

		string typeDecl  = field->Type->GetSQLDeclaration( field, this );

		columnDef = typeDecl + charset + default + notnull + unique + check + collation;
	}

	if( this->SupportsInlineColumnComments() && !field->Comment.empty() )
	{
		columnDef += " COMMENT " + this->QuoteStringLiteral( field->Comment );
	}

	return field->GetQuotedName() + " " + columnDef;
}

string AbstractPlatform::GetDecimalTypeDeclarationSQL( Column* columnDef )
{
	columnDef->Precision = columnDef->Precision == 0 ? 10 : columnDef->Precision;
	columnDef->Scale     = columnDef->Scale     == 0 ? 0  : columnDef->Scale;

	stringstream ss;

	ss << "NUMERIC(" << columnDef->Precision << ", " << columnDef->Scale << ")";

	return ss.str();
}

string AbstractPlatform::GetDefaultValueDeclarationSQL( Column* field )
{
	string default = !field->NotNull ? " DEFAULT NULL" : "";

	if( !field->Default.empty() && field->Default != "NULL" )
	{
		default = " DEFAULT \"" + field->Default + "\"";

		if( field->Type != nullptr )
		{
			switch( field->Type->GetID() )
			{
				case ColumnType::INTEGER:
				case ColumnType::BIGINT:
				case ColumnType::SMALLINT:
				{
					default = " DEFAULT " + field->Default;

					break;
				}
				case ColumnType::DATETIME:
				case ColumnType::DATETIMETZ:
				case ColumnType::DATE:
				case ColumnType::TIME:
				{
					if( field->Default == this->GetCurrentTimestampSQL() )
					{
						default = " DEFAULT " + this->GetCurrentTimestampSQL();
					}
					else if( field->Default == this->GetCurrentTimeSQL() )
					{
						default = " DEFAULT " + this->GetCurrentTimeSQL();
					}
					else if( field->Default == this->GetCurrentDateSQL() )
					{
						default = " DEFAULT " + this->GetCurrentDateSQL();
					}

					break;
				}
				case ColumnType::BOOLEAN:
				{
					default = " DEFAULT \"" + this->ConvertBooleans( field->Default ) + "\"";

					break;
				}
			}
		}
	}

	return default;
}

string AbstractPlatform::GetCheckDeclarationSQL( const vector< Column* >& definition )
{
	AbstractPlatform::StringArray constraints;

	for( Column* field : definition )
	{
		const string& def = field->GetName();

		const map< string, string >& options = field->Options;

		if( options.count( "min" ) == 0  && options.count( "max" ) == 0 )
		{
			constraints.push_back( "CHECK (" + def + ")" );
		}
		else
		{
			if( options.count( "min" ) > 0 )
			{
				constraints.push_back( "CHECK (" + def + " >= " + options.at( "min" ) + ")" );
			}

			if( options.count( "max" ) > 0 )
			{
				constraints.push_back( "CHECK (" + def + " <= " + options.at( "max" ) + ")" );
			}
		}
	}

	return VectorJoin( constraints, ", " );
}

string AbstractPlatform::GetUniqueConstraintDeclarationSQL( const string& name, Index* index )
{
	AbstractPlatform::StringArray columns = index->GetQuotedColumns();

	if( columns.size() == 0 )
	{
		throw new exception( "Incomplete definition 'columns' required" );
	}

	return "CONSTRAINT `" + name + "` UNIQUE (" + this->GetIndexFieldDeclarationListSQL( columns ) + ")" + this->GetPartialIndexSQL( index );
}

string AbstractPlatform::GetIndexDeclarationSQL( const string& name, Index* index )
{
	AbstractPlatform::StringArray columns = index->GetQuotedColumns();

	if( columns.size() == 0 )
	{
		throw new exception( "Incomplete definition 'columns' required" );
	}

	return this->GetCreateIndexSQLFlags( index ) + "INDEX `" + name + "` (" + this->GetIndexFieldDeclarationListSQL( columns ) + ")" + this->GetPartialIndexSQL( index );
}

string AbstractPlatform::GetCustomTypeDeclarationSQL( Column* columnDef )
{
	return columnDef->ColumnDefinition;
}

string AbstractPlatform::GetIndexFieldDeclarationListSQL( const map< string, Column* >& fields )
{
	vector< string > ret;

	for( const auto& iter : fields )
	{
		ret.push_back( iter.first );
	}

	return VectorJoin( ret, ", " );
}

string AbstractPlatform::GetIndexFieldDeclarationListSQL( const vector< string >& fields )
{
	return VectorJoin( fields, ", " );
}

string AbstractPlatform::GetTemporaryTableSQL()
{
	return "TEMPORARY";
}

string AbstractPlatform::GetTemporaryTableName( const string& tableName )
{
	return tableName;
}

string AbstractPlatform::GetForeignKeyDeclarationSQL( ForeignKeyConstraint* foreignKey )
{
	string sql;

	sql = this->GetForeignKeyBaseDeclarationSQL( foreignKey );
	sql += this->GetAdvancedForeignKeyOptionsSQL( foreignKey );

	return sql;
}

string AbstractPlatform::GetAdvancedForeignKeyOptionsSQL( ForeignKeyConstraint* foreignKey )
{
	string query;

	if( this->SupportsForeignKeyOnUpdate() && foreignKey->HasOption( "OnUpdate" ) )
	{
		query += " ON UPDATE " + this->GetForeignKeyReferentialActionSQL( foreignKey->GetOption( "OnUpdate" ) );
	}
	if( foreignKey->HasOption( "OnDelete" ) )
	{
		query += " ON DELETE " + this->GetForeignKeyReferentialActionSQL( foreignKey->GetOption( "OnDelete" ) );
	}

	return query;
}

string AbstractPlatform::GetForeignKeyReferentialActionSQL( const string& action )
{
	string upper = strtoupper( action );

	if( upper == "CASCADE"
		|| upper == "SET NULL"
		|| upper == "NO ACTION"
		|| upper == "RESTRICT"
		|| upper == "SET DEFAULT"
	)
	{
		return upper;
	}

	throw new exception( ( "Invalid foreign key action: " + upper ).c_str() );
}

string AbstractPlatform::GetForeignKeyBaseDeclarationSQL( ForeignKeyConstraint* foreignKey )
{
	string sql = "";

	if( foreignKey->GetName().length() > 0 )
	{
		sql += "CONSTRAINT " + foreignKey->GetQuotedName() + " ";
	}

	sql += "FOREIGN KEY (";

	if( foreignKey->GetLocalColumns().size() == 0 )
	{
		throw new exception( "Incomplete definition 'local' required" );
	}
	if( foreignKey->GetForeignColumns().size() == 0 )
	{
		throw new exception( "Incomplete definition 'foreign' required" );
	}
	if( foreignKey->GetForeignTableName().length() == 0 )
	{
		throw new exception( "Incomplete definition 'foreignTable' required" );
	}

	sql += VectorJoin( foreignKey->GetQuotedLocalColumns(), ", " ) + ") REFERENCES ";
	sql += foreignKey->GetQuotedForeignTableName() + " (" + VectorJoin( foreignKey->GetQuotedForeignColumns(), ", " ) + ")";

	return sql;
}

string AbstractPlatform::GetUniqueFieldDeclarationSQL()
{
	return "UNIQUE";
}

string AbstractPlatform::GetColumnCharsetDeclarationSQL( const string& charset )
{
	return "";
}

string AbstractPlatform::GetColumnCollationDeclarationSQL( const string& collation )
{
	return this->SupportsColumnCollation() ? "COLLATE " + collation : "";
}

bool AbstractPlatform::PrefersSequences()
{
	return false;
}

bool AbstractPlatform::PrefersIdentityColumns()
{
	return false;
}

string AbstractPlatform::ConvertBooleans( bool item )
{
	return item ? "1" : "0";
}

string AbstractPlatform::ConvertBooleans( const string& item )
{
	return item;
}

bool AbstractPlatform::ConvertFromBoolean( const string& item )
{
	return item == "true";
}

string AbstractPlatform::ConvertBooleansToDatabaseValue( bool item )
{
	return this->ConvertBooleans( item );
}

string AbstractPlatform::GetCurrentDateSQL()
{
	return "CURRENT_DATE";
}

string AbstractPlatform::GetCurrentTimeSQL()
{
	return "CURRENT_TIME";
}

string AbstractPlatform::GetCurrentTimestampSQL()
{
	return "CURRENT_TIMESTAMP";
}

string AbstractPlatform::_getTransactionIsolationLevelSQL( int level )
{
	switch( level )
	{
		case TRANSACTION_READ_UNCOMMITTED:
			return "READ UNCOMMITTED";
		case TRANSACTION_READ_COMMITTED:
			return "READ COMMITTED";
		case TRANSACTION_REPEATABLE_READ:
			return "REPEATABLE READ";
		case TRANSACTION_SERIALIZABLE:
			return "SERIALIZABLE";
		default:
			throw new exception( "Invalid isolation level: " + level );
	}
}

string AbstractPlatform::GetListDatabasesSQL()
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

string AbstractPlatform::GetListNamespacesSQL()
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

string AbstractPlatform::GetListSequencesSQL( const string& database )
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

string AbstractPlatform::GetListTableConstraintsSQL( const string& table )
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

string AbstractPlatform::GetListTableColumnsSQL( const string& table, const string& database )
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

string AbstractPlatform::GetListTablesSQL()
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

string AbstractPlatform::GetListUsersSQL()
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

string AbstractPlatform::GetListViewsSQL( const string& database )
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

string AbstractPlatform::GetListTableIndexesSQL( const string& table, const string& currentDatabase )
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

string AbstractPlatform::GetListTableForeignKeysSQL( const string& table, const string& database )
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

string AbstractPlatform::GetCreateViewSQL( const string& name, const string& sql )
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

string AbstractPlatform::GetDropViewSQL( const string& name )
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

string AbstractPlatform::GetDropSequenceSQL( const string& sequence )
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

string AbstractPlatform::GetSequenceNextValSQL( const string& sequenceName )
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

string AbstractPlatform::GetCreateDatabaseSQL( const string& database )
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

string AbstractPlatform::GetSetTransactionIsolationSQL( int level )
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

string AbstractPlatform::GetDateTimeTypeDeclarationSQL( Column* fieldDeclaration )
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

string AbstractPlatform::GetDateTimeTzTypeDeclarationSQL( Column* fieldDeclaration )
{
	return this->GetDateTimeTypeDeclarationSQL( fieldDeclaration );
}

string AbstractPlatform::GetDateTypeDeclarationSQL( Column* fieldDeclaration )
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

string AbstractPlatform::GetTimeTypeDeclarationSQL( Column* fieldDeclaration )
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

string AbstractPlatform::GetFloatTypeDeclarationSQL( Column* fieldDeclaration )
{
	return "DOUBLE PRECISION";
}

int AbstractPlatform::GetDefaultTransactionIsolationLevel()
{
	return TRANSACTION_READ_COMMITTED;
}

bool AbstractPlatform::SupportsSequences()
{
	return false;
}

bool AbstractPlatform::SupportsIdentityColumns()
{
	return false;
}

bool AbstractPlatform::UsesSequenceEmulatedIdentityColumns()
{
	return false;
}

string AbstractPlatform::GetIdentitySequenceName( const string& tableName, const string& columnName )
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

bool AbstractPlatform::SupportsIndexes()
{
	return true;
}

bool AbstractPlatform::SupportsPartialIndexes()
{
	return false;
}

bool AbstractPlatform::SupportsAlterTable()
{
	return true;
}

bool AbstractPlatform::SupportsTransactions()
{
	return true;
}

bool AbstractPlatform::SupportsSavepoints()
{
	return true;
}

bool AbstractPlatform::SupportsReleaseSavepoints()
{
	return this->SupportsSavepoints();
}

bool AbstractPlatform::SupportsPrimaryConstraints()
{
	return true;
}

bool AbstractPlatform::SupportsForeignKeyConstraints()
{
	return true;
}

bool AbstractPlatform::SupportsForeignKeyOnUpdate()
{
	return ( this->SupportsForeignKeyConstraints() && true );
}

bool AbstractPlatform::SupportsSchemas()
{
	return false;
}

bool AbstractPlatform::CanEmulateSchemas()
{
	return false;
}

string AbstractPlatform::GetDefaultSchemaName()
{
	throw new exception( "Not supported method \"" __FUNCTION__ "\"" );
}

bool AbstractPlatform::SupportsCreateDropDatabase()
{
	return true;
}

bool AbstractPlatform::SupportsGettingAffectedRows()
{
	return true;
}

bool AbstractPlatform::SupportsInlineColumnComments()
{
	return false;
}

bool AbstractPlatform::SupportsCommentOnStatement()
{
	return false;
}

bool AbstractPlatform::HasNativeGuidType()
{
	return false;
}

bool AbstractPlatform::HasNativeJsonType()
{
	return false;
}

bool AbstractPlatform::SupportsViews()
{
	return true;
}

bool AbstractPlatform::SupportsColumnCollation()
{
	return false;
}

string AbstractPlatform::GetDateTimeFormatString()
{
	return "Y-m-d H:i:s";
}

string AbstractPlatform::GetDateTimeTzFormatString()
{
	return "Y-m-d H:i:s";
}

string AbstractPlatform::GetDateFormatString()
{
	return "Y-m-d";
}

string AbstractPlatform::GetTimeFormatString()
{
	return "H:i:s";
}

string AbstractPlatform::ModifyLimitQuery( const string& query, int limit, int offset )
{
	if( offset != -1 )
	{
		if( offset < 0 )
		{
			stringstream ss;

			ss << "LIMIT argument offset=" << offset << " is not valid";

			throw new exception( ss.str().c_str() );
		}

		if( offset > 0 && !this->SupportsLimitOffset() )
		{
			throw new exception( "Platform does not support offset values in limit queries" );
		}
	}

	return this->DoModifyLimitQuery( query, limit, offset );
}

string AbstractPlatform::DoModifyLimitQuery( const string& _query, int limit, int offset )
{
	stringstream query;

	query << _query;

	if( limit != -1 )
	{
		query << " LIMIT " << limit;
	}

	if( offset != -1 )
	{
		query << " OFFSET " << offset;
	}

	return query.str();
}

bool AbstractPlatform::SupportsLimitOffset()
{
	return true;
}

string AbstractPlatform::GetSQLResultCasing( const string& column )
{
	return column;
}

string AbstractPlatform::FixSchemaElementName( const string& schemaElementName )
{
	return schemaElementName;
}

int AbstractPlatform::GetMaxIdentifierLength()
{
	return 63;
}

string AbstractPlatform::GetEmptyIdentityInsertSQL( const string& tableName, const string& identifierColumnName )
{
	return "INSERT INTO " + tableName + " (" + identifierColumnName + ") VALUES (null)";
}

string AbstractPlatform::GetTruncateTableSQL( const string& tableName, bool cascade )
{
	return "TRUNCATE `" + tableName + "`";
}

string AbstractPlatform::GetDummySelectSQL()
{
	return "SELECT 1";
}

string AbstractPlatform::CreateSavePoint( const string& savepoint )
{
	return "SAVEPOINT " + savepoint;
}

string AbstractPlatform::ReleaseSavePoint( const string& savepoint )
{
	return "RELEASE SAVEPOINT " + savepoint;
}

string AbstractPlatform::RollbackSavePoint( const string& savepoint )
{
	return "ROLLBACK TO SAVEPOINT " + savepoint;
}

string AbstractPlatform::QuoteStringLiteral( const string& str )
{
	const string& c = this->GetStringLiteralQuoteCharacter();

	return c + str + c;
}

string AbstractPlatform::GetStringLiteralQuoteCharacter()
{
	return "'";
}