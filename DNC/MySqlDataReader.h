#pragma once

#ifndef MYSQLDATAREADER_H
#define MYSQLDATAREADER_H

#include "DateTime.h"
#include "Type.h"
#include "DataTable.h"
#include "SqlDataReader.h"
#include "Serializable.h"
#include <my_global.h>
#include "mysql.h"
#include <iostream>

namespace dnc{
	namespace Data{
		namespace SqlClient{

			class MySqlDataReader: public SqlDataReader{

				friend class MySqlCommand;
				friend class MySqlDataAdapter;

			public:
				~MySqlDataReader();

				std::string ToString() override;
				std::string GetTypeString() override;

				unsigned int FieldCount();
				bool GetBoolean(int i);
				char GetByte(int i);
				long GetBytes(int i, long dataIndex, char* buffer, int bufferIndex, int length);
				long GetChars(int i, long dataIndex, char* buffer, int bufferIndex, int length);
				String GetDataTypeName(int i);
				DateTime GetDateTime(int i);
				double GetDouble(int i);
				Type GetFieldType(int i);
				float GetFloat(int i);
				int GetInteger(int i);
				long GetLong(int i);
				String GetName(int i);
				int GetOrdinal(String& name);
				DataTable GetSchemaTable();
				short GetShort(int i);
				String GetString(int i);
				bool HasRows();

				bool NextResult();

				template<typename T>
				Collections::Generic::List<T> Deserialize();

			private:
				String tableName;
				Collections::Generic::List<std::pair<String, Type>> cols;
				MYSQL_STMT* stmt;
				MYSQL_RES* resultset;
				MYSQL_BIND* row;
				char** buffers;
				unsigned long* buffer_lengths;
				unsigned long* lengths;
				my_bool* is_nulls;
				my_bool* errors;

				MySqlDataReader(MYSQL_STMT* stmt, MYSQL_RES* _resultset);
				void LoadColumns();

				void FillTable(DataTable& table);
			};

			template<typename T>
			inline Collections::Generic::List<T> MySqlDataReader::Deserialize() {
				static_assert(std::is_base_of<Serializable, T>::value, "Template is not derived from Serializable");

				size_t colCount = 0;
				size_t rowCount = 0;
				Type t;
				MYSQL_FIELD* field;
				Collections::Generic::List<T> res;

				GetSchemaTable();

				colCount = this->cols.Count();
				rowCount = mysql_stmt_num_rows(this->stmt);

				for(size_t i = 0; i < rowCount; ++i) {
					T t;
					Serializable* seri = static_cast<Serializable*>(&t);

					mysql_stmt_fetch(this->stmt);
					//rowSrc = mysql_fetch_row(this->resultset);

					for(size_t g = 0; g < colCount; ++g) {
						field = mysql_fetch_field_direct(this->resultset, g);

						SerializableAttribute& attr = seri->Attribute(this->cols[g].first);

						switch(field->type) {
							case enum_field_types::MYSQL_TYPE_BIT:
							{
								unsigned long temp = *((unsigned long*)this->row[g].buffer);
								ULong& ul = (ULong&)attr.Member();
								ul = temp;
							}
							break;
							case enum_field_types::MYSQL_TYPE_BLOB:
							{
								std::string str = (char*)this->row[g].buffer;
								String temp(str);
								attr.Member(temp);
							}
							break;
							case enum_field_types::MYSQL_TYPE_DATE:
							{
								DateTime dt;
								MYSQL_TIME* time;

								time = (MYSQL_TIME*)this->row[g].buffer;

								dt = DateTime(time->year, time->month, time->day, time->hour, time->minute, time->second, time->second_part);
								/*dt = dt.addYears(time->year);
								dt = dt.addMonths(time->month);
								dt = dt.addDays(time->day);
								dt = dt.addHours(time->hour);
								dt = dt.addMinutes(time->minute);
								dt = dt.addSeconds(time->second);
								dt = dt.addMicroseconds(time->second_part);*/

								attr.Member(dt);
							}
							break;
							case enum_field_types::MYSQL_TYPE_DATETIME:
							{
								// DateTime dt;
								MYSQL_TIME* time;

								time = ((MYSQL_TIME*)this->row[g].buffer);

								// dt = DateTime(time->year, time->month, time->day, time->hour, time->minute, time->second, time->second_part);
								/*dt = dt.addYears(time.year);
								dt = dt.addMonths(time.month);
								dt = dt.addDays(time.day);
								dt = dt.addHours(time.hour);
								dt = dt.addMinutes(time.minute);
								dt = dt.addSeconds(time.second);
								dt = dt.addMicroseconds(time.second_part);*/

								DateTime& dt = (DateTime&)attr.Member();
								dt = DateTime(time->year, time->month, time->day, time->hour, time->minute, time->second, time->second_part);
								/*
								dt.Year(time->year);
								dt.Month(time->month);
								dt.Day(time->day);
								dt.Hour(time->hour);
								dt.Minute(time->minute);
								dt.Second(time->second);
								dt.Millisecond(time->second_part);
								*/
							}
							break;
							case enum_field_types::MYSQL_TYPE_DATETIME2:
							{
								DateTime dt;
								MYSQL_TIME* time;

								time = (MYSQL_TIME*)this->row[g].buffer;

								dt = DateTime(time->year, time->month, time->day, time->hour, time->minute, time->second, time->second_part);
								/*
								dt = dt.addYears(time->year);
								dt = dt.addMonths(time->month);
								dt = dt.addDays(time->day);
								dt = dt.addHours(time->hour);
								dt = dt.addMinutes(time->minute);
								dt = dt.addSeconds(time->second);
								dt = dt.addMicroseconds(time->second_part);
								*/

								attr.Member(dt);
							}
							break;
							case enum_field_types::MYSQL_TYPE_DECIMAL:
							{
								long double temp = *((long double*)this->row[g].buffer);
								attr.Member(Decimal(temp));
							}
							break;
							case enum_field_types::MYSQL_TYPE_DOUBLE:
							{
								double temp = *((double*)this->row[g].buffer);
								attr.Member(Double(temp));
							}
							break;
							case enum_field_types::MYSQL_TYPE_FLOAT:
							{
								float temp = *((float*)this->row[g].buffer);
								attr.Member(Float(temp));
							}
							break;
							// -------------------------------------------------------
							case enum_field_types::MYSQL_TYPE_INT24:
							{
								int temp = *((int*)this->row[g].buffer);
								attr.Member(Integer(temp));
							}
							break;
							case enum_field_types::MYSQL_TYPE_JSON:
							{
								std::string str = (char*)this->row[g].buffer;
								String temp(str);
								attr.Member(temp);
							}
							break;
							case enum_field_types::MYSQL_TYPE_LONG:
							{
								int temp = *((int*)this->row[g].buffer);
								Long& l = (Long&)attr.Member();
								l = temp;
							}
							break;
							case enum_field_types::MYSQL_TYPE_LONGLONG:
							{
								long long temp = *((long long*)this->row[g].buffer);
								attr.Member(LongLong(temp));
							}
							break;
							case enum_field_types::MYSQL_TYPE_LONG_BLOB:
							{
								std::string str = (char*)this->row[g].buffer;
								String temp(str);
								attr.Member(temp);
							}
							break;
							case enum_field_types::MYSQL_TYPE_MEDIUM_BLOB:
							{
								std::string str = (char*)this->row[g].buffer;
								String temp(str);
								attr.Member(temp);
							}
							break;
							case enum_field_types::MYSQL_TYPE_NEWDATE:
							{
								DateTime dt;
								MYSQL_TIME* time;

								time = (MYSQL_TIME*)this->row[g].buffer;

								dt = DateTime(time->year, time->month, time->day, time->hour, time->minute, time->second, time->second_part);
								/*dt = dt.addYears(time->year);
								dt = dt.addMonths(time->month);
								dt = dt.addDays(time->day);
								dt = dt.addHours(time->hour);
								dt = dt.addMinutes(time->minute);
								dt = dt.addSeconds(time->second);
								dt = dt.addMicroseconds(time->second_part);
								*/
								attr.Member(dt);
							}
							break;
							case enum_field_types::MYSQL_TYPE_NEWDECIMAL:
							{
								long double temp = *((long double*)this->row[g].buffer);
								attr.Member(Decimal(temp));
							}
							break;
							case enum_field_types::MYSQL_TYPE_NULL:
							{
								long temp = *((long*)this->row[g].buffer);
								attr.Member(Long(temp));
							}
							break;
							case enum_field_types::MYSQL_TYPE_SHORT:
							{
								short temp = *((short*)this->row[g].buffer);
								attr.Member(Short(temp));
							}
							break;
							case enum_field_types::MYSQL_TYPE_STRING:
							{
								std::string str = (char*)this->row[g].buffer;
								String temp(str);
								attr.Member(temp);
							}
							break;
							case enum_field_types::MYSQL_TYPE_TIME:
							{
								DateTime dt;
								MYSQL_TIME* time;

								time = (MYSQL_TIME*)this->row[g].buffer;

								dt = DateTime(time->year, time->month, time->day, time->hour, time->minute, time->second, time->second_part);
								/*
								dt = dt.addYears(time->year);
								dt = dt.addMonths(time->month);
								dt = dt.addDays(time->day);
								dt = dt.addHours(time->hour);
								dt = dt.addMinutes(time->minute);
								dt = dt.addSeconds(time->second);
								dt = dt.addMicroseconds(time->second_part);
								*/
								attr.Member(dt);
							}
							break;
							case enum_field_types::MYSQL_TYPE_TIME2:
							{
								DateTime dt;
								MYSQL_TIME* time;

								time = (MYSQL_TIME*)this->row[g].buffer;

								dt = DateTime(time->year, time->month, time->day, time->hour, time->minute, time->second, time->second_part);
								/*dt = dt.addYears(time->year);
								dt = dt.addMonths(time->month);
								dt = dt.addDays(time->day);
								dt = dt.addHours(time->hour);
								dt = dt.addMinutes(time->minute);
								dt = dt.addSeconds(time->second);
								dt = dt.addMicroseconds(time->second_part);
								*/
								attr.Member(dt);
							}
							break;
							case enum_field_types::MYSQL_TYPE_TIMESTAMP:
							{
								DateTime dt;
								MYSQL_TIME* time;

								time = (MYSQL_TIME*)this->row[g].buffer;

								dt = DateTime(time->year, time->month, time->day, time->hour, time->minute, time->second, time->second_part);
								/*dt = dt.addYears(time->year);
								dt = dt.addMonths(time->month);
								dt = dt.addDays(time->day);
								dt = dt.addHours(time->hour);
								dt = dt.addMinutes(time->minute);
								dt = dt.addSeconds(time->second);
								dt = dt.addMicroseconds(time->second_part);
								*/
								attr.Member(dt);
							}
							break;
							case enum_field_types::MYSQL_TYPE_TIMESTAMP2:
							{
								DateTime dt;
								MYSQL_TIME* time;

								time = (MYSQL_TIME*)this->row[g].buffer;

								dt = DateTime(time->year, time->month, time->day, time->hour, time->minute, time->second, time->second_part);
								/*dt = dt.addYears(time->year);
								dt = dt.addMonths(time->month);
								dt = dt.addDays(time->day);
								dt = dt.addHours(time->hour);
								dt = dt.addMinutes(time->minute);
								dt = dt.addSeconds(time->second);
								dt = dt.addMicroseconds(time->second_part);
								*/
								attr.Member(dt);
							}
							break;
							case enum_field_types::MYSQL_TYPE_TINY:
							{
								short temp = *((short*)this->row[g].buffer);
								attr.Member(Short(temp));
							}
							break;
							case enum_field_types::MYSQL_TYPE_TINY_BLOB:
							{
								std::string str = (char*)this->row[g].buffer;
								String temp(str);
								attr.Member(temp);
							}
							break;
							case enum_field_types::MYSQL_TYPE_VARCHAR:
							{
								std::string str = (char*)this->row[g].buffer;
								String temp(str);
								attr.Member(temp);
							}
							case enum_field_types::MYSQL_TYPE_VAR_STRING:
							{
								std::string str = (char*)this->row[g].buffer;
								String temp(str);
								String& s = (String&)attr.Member();
								s = temp;
							}
							break;
						}
					}
					res.Add(t);
				}

				return res;
			}

		}
	}
}
#endif // !MYSQLDATAREADER_H