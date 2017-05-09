#pragma once
#include "mysql.h"

namespace dnc{
	namespace Data{
		namespace SqlClient{

			enum class MySqlDbTypes{
				BIT = enum_field_types::MYSQL_TYPE_BIT,
				BLOB = enum_field_types::MYSQL_TYPE_BLOB,
				DATE = enum_field_types::MYSQL_TYPE_DATE,
				DATETIME = enum_field_types::MYSQL_TYPE_DATETIME,
				DATETIME2 = enum_field_types::MYSQL_TYPE_DATETIME2,
				DECIMAL = enum_field_types::MYSQL_TYPE_DECIMAL,
				DOUBLE = enum_field_types::MYSQL_TYPE_DOUBLE,
				ENUM = enum_field_types::MYSQL_TYPE_ENUM,
				FLOAT = enum_field_types::MYSQL_TYPE_FLOAT,
				GEOMETRY = enum_field_types::MYSQL_TYPE_GEOMETRY,
				INT = enum_field_types::MYSQL_TYPE_INT24,
				JSON = enum_field_types::MYSQL_TYPE_JSON,
				LONG = enum_field_types::MYSQL_TYPE_LONG,
				LONGLONG = enum_field_types::MYSQL_TYPE_LONGLONG,
				LONG_BLOB = enum_field_types::MYSQL_TYPE_LONG_BLOB,
				MEDIUM_BLOB = enum_field_types::MYSQL_TYPE_MEDIUM_BLOB,
				NEWDATE = enum_field_types::MYSQL_TYPE_NEWDATE,
				NEWDECIMAL = enum_field_types::MYSQL_TYPE_NEWDECIMAL,
				Null = enum_field_types::MYSQL_TYPE_NULL,
				SET = enum_field_types::MYSQL_TYPE_SET,
				SHORT = enum_field_types::MYSQL_TYPE_SHORT,
				STRING = enum_field_types::MYSQL_TYPE_STRING,
				TIME = enum_field_types::MYSQL_TYPE_TIME,
				TIME2 = enum_field_types::MYSQL_TYPE_TIME2,
				TIMESTAMP = enum_field_types::MYSQL_TYPE_TIMESTAMP,
				TIMESTAMP2 = enum_field_types::MYSQL_TYPE_TIMESTAMP2,
				TINY = enum_field_types::MYSQL_TYPE_TINY,
				TINY_BLOB = enum_field_types::MYSQL_TYPE_TINY_BLOB,
				VARCHAR = enum_field_types::MYSQL_TYPE_VARCHAR,
				VAR_STRING = enum_field_types::MYSQL_TYPE_VAR_STRING,
				YEAR = enum_field_types::MYSQL_TYPE_YEAR
			};
		}
	}
}