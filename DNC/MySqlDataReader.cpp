#include "MySqlDataReader.h"

namespace dnc{
	namespace Data{
		namespace SqlClient{

			MySqlDataReader::~MySqlDataReader(){
				mysql_free_result(this->resultset);
			}

			std::string MySqlDataReader::ToString(){
				return std::string("System.Data.MySqlClient.MySqlDataReader");
			}

			std::string MySqlDataReader::GetTypeString(){
				return std::string("MySqlDataReader");
			}

			MySqlDataReader::MySqlDataReader(MYSQL_STMT* _stmt, MYSQL_RES* _resultset): stmt(_stmt), resultset(_resultset){
				// Load fields
				LoadColumns();
			}

			void MySqlDataReader::LoadColumns(){
				int i = 0;
				Type t;
				MYSQL_FIELD* field;

				while(field = mysql_fetch_field(this->resultset)){
					if(i == 0){
						tableName = field->table;
						++i;
					}

					//Type
					switch(field->type){
						case enum_field_types::MYSQL_TYPE_BIT:
							t = Type::getType<unsigned long>(346534);
							break;
						case enum_field_types::MYSQL_TYPE_BLOB:
							t = Type::getType<char*>("");
							break;
						case enum_field_types::MYSQL_TYPE_DATE:
							t = Type::getType<DateTime>(DateTime());
							break;
						case enum_field_types::MYSQL_TYPE_DATETIME:
							t = Type::getType<DateTime>(DateTime());
							break;
						case enum_field_types::MYSQL_TYPE_DATETIME2:
							t = Type::getType<DateTime>(DateTime());
							break;
						case enum_field_types::MYSQL_TYPE_DECIMAL:
							t = Type::getType<long double>(234.000);
							break;
						case enum_field_types::MYSQL_TYPE_DOUBLE:
							t = Type::getType<double>(132456.0);
							break;
						case enum_field_types::MYSQL_TYPE_FLOAT:
							t = Type::getType<float>(2134);
							break;
						case enum_field_types::MYSQL_TYPE_INT24:
							t = Type::getType<int>(3456);
							break;
						case enum_field_types::MYSQL_TYPE_JSON:
							t = Type::getType<String>(String());
							break;
						case enum_field_types::MYSQL_TYPE_LONG:
							t = Type::getType<long>(3456);
							break;
						case enum_field_types::MYSQL_TYPE_LONGLONG:
							t = Type::getType<long long>(23435);
							break;
						case enum_field_types::MYSQL_TYPE_LONG_BLOB:
							t = Type::getType<char*>("");
							break;
						case enum_field_types::MYSQL_TYPE_MEDIUM_BLOB:
							t = Type::getType<char*>("");
							break;
						case enum_field_types::MYSQL_TYPE_NEWDATE:
							t = Type::getType<DateTime>(DateTime());
							break;
						case enum_field_types::MYSQL_TYPE_NEWDECIMAL:
							t = Type::getType<long double>(3456.0);
							break;
						case enum_field_types::MYSQL_TYPE_NULL:
							t = Type::getType<void*>(nullptr);
							break;
						case enum_field_types::MYSQL_TYPE_SHORT:
							t = Type::getType<short>(213);
							break;
						case enum_field_types::MYSQL_TYPE_STRING:
							t = Type::getType<String>(String());
							break;
						case enum_field_types::MYSQL_TYPE_TIME:
							t = Type::getType<DateTime>(DateTime());
							break;
						case enum_field_types::MYSQL_TYPE_TIME2:
							t = Type::getType<DateTime>(DateTime());
							break;
						case enum_field_types::MYSQL_TYPE_TIMESTAMP:
							t = Type::getType<DateTime>(DateTime());
							break;
						case enum_field_types::MYSQL_TYPE_TIMESTAMP2:
							t = Type::getType<DateTime>(DateTime());
							break;
						case enum_field_types::MYSQL_TYPE_TINY:
							t = Type::getType<short>(1);
							break;
						case enum_field_types::MYSQL_TYPE_TINY_BLOB:
							t = Type::getType<char*>("");
							break;
						case enum_field_types::MYSQL_TYPE_VARCHAR:
							t = Type::getType<String>(String());
							break;
						case enum_field_types::MYSQL_TYPE_VAR_STRING:
							t = Type::getType<String>(String());
							break;
						case enum_field_types::MYSQL_TYPE_YEAR:
							t = Type::getType<int>(1990);
							break;
					}

					this->cols.Add(std::make_pair(field->name, t));
				}

				unsigned int lens = mysql_stmt_field_count(this->stmt);
				this->row = new MYSQL_BIND[lens];
				this->buffers = new char*[lens];
				this->buffer_lengths = new unsigned long[lens];
				this->lengths = new unsigned long[lens];
				this->is_nulls = new my_bool[lens];
				this->errors = new my_bool[lens];

				for(size_t i = 0; i < lens; i++){
					field = mysql_fetch_field_direct(this->resultset, i);

					this->row[i].buffer_type = field->type;

					switch(field->type){
						case enum_field_types::MYSQL_TYPE_BIT:
						{
							unsigned long l = 0;
							this->row[i].buffer = (char*)&l;
						}
						break;
						case enum_field_types::MYSQL_TYPE_BLOB:
						{
							this->buffers[i] = new char[field->length];
							this->row[i].buffer = this->buffers[i];
						}
						break;
						case enum_field_types::MYSQL_TYPE_DATE:
						{
							MYSQL_TIME* time;

							time = new MYSQL_TIME();

							this->row[i].buffer = (char*)time;
						}
						break;
						case enum_field_types::MYSQL_TYPE_DATETIME:
						{
							MYSQL_TIME* time;

							time = new MYSQL_TIME();

							this->row[i].buffer = (char*)time;
						}
						break;
						case enum_field_types::MYSQL_TYPE_DATETIME2:
						{
							MYSQL_TIME* time;

							time = new MYSQL_TIME();

							this->row[i].buffer = (char*)time;
						}
						break;
						case enum_field_types::MYSQL_TYPE_DECIMAL:
						{
							long double l = 0;
							this->row[i].buffer = (char*)&l;
						}
						break;
						case enum_field_types::MYSQL_TYPE_DOUBLE:
						{
							double l = 0;
							this->row[i].buffer = (char*)&l;
						}
						break;
						case enum_field_types::MYSQL_TYPE_FLOAT:
						{
							float f = 0;
							this->row[i].buffer = (char*)&f;
						}
						break;
						case enum_field_types::MYSQL_TYPE_INT24:
						{
							int l = 0;
							this->row[i].buffer = (char*)&l;
						}
						break;
						case enum_field_types::MYSQL_TYPE_JSON:
							this->buffers[i] = new char[field->length];
							this->row[i].buffer = this->buffers[i];
							break;
						case enum_field_types::MYSQL_TYPE_LONG:
						{
							this->buffers[i] = new char[sizeof(int)];
							//int l = 0;
							this->row[i].buffer = this->buffers[i];
						}
						break;
						case enum_field_types::MYSQL_TYPE_LONGLONG:
						{
							long long l = 0;
							this->row[i].buffer = (char*)&l;
						}
						break;
						case enum_field_types::MYSQL_TYPE_LONG_BLOB:
							this->buffers[i] = new char[field->length];
							this->row[i].buffer = this->buffers[i];
							break;
						case enum_field_types::MYSQL_TYPE_MEDIUM_BLOB:
							this->buffers[i] = new char[field->length];
							this->row[i].buffer = this->buffers[i];
							break;
						case enum_field_types::MYSQL_TYPE_NEWDATE:
						{
							MYSQL_TIME* time;

							time = new MYSQL_TIME();

							this->row[i].buffer = (char*)time;
						}
						break;
						case enum_field_types::MYSQL_TYPE_NEWDECIMAL:
						{
							long double l = 0;
							this->row[i].buffer = (char*)&l;
						}
						break;
						case enum_field_types::MYSQL_TYPE_NULL:
							t = Type::getType<void*>(nullptr);
							break;
						case enum_field_types::MYSQL_TYPE_SHORT:
						{
							short l = 0;
							this->row[i].buffer = (char*)&l;
						}
						break;
						case enum_field_types::MYSQL_TYPE_STRING:
							this->buffers[i] = new char[field->length];
							this->row[i].buffer = this->buffers[i];
							break;
						case enum_field_types::MYSQL_TYPE_TIME:
						{
							MYSQL_TIME* time;

							time = new MYSQL_TIME();

							this->row[i].buffer = (char*)time;
						}
						break;
						case enum_field_types::MYSQL_TYPE_TIME2:
						{
							MYSQL_TIME* time;

							time = new MYSQL_TIME();

							this->row[i].buffer = (char*)time;
						}
						break;
						case enum_field_types::MYSQL_TYPE_TIMESTAMP:
						{
							MYSQL_TIME* time;

							time = new MYSQL_TIME();

							this->row[i].buffer = (char*)time;
						}
						break;
						case enum_field_types::MYSQL_TYPE_TIMESTAMP2:
						{
							MYSQL_TIME* time;

							time = new MYSQL_TIME();

							this->row[i].buffer = (char*)time;
						}
						break;
						case enum_field_types::MYSQL_TYPE_TINY:
						{
							short l = 0;
							this->row[i].buffer = (char*)&l;
						}
						break;
						case enum_field_types::MYSQL_TYPE_TINY_BLOB:
							this->buffers[i] = new char[field->length];
							this->row[i].buffer = this->buffers[i];
							break;
						case enum_field_types::MYSQL_TYPE_VARCHAR:
						{
							this->buffers[i] = new char[field->length];
							this->row[i].buffer = this->buffers[i];
						}
						break;
						case enum_field_types::MYSQL_TYPE_VAR_STRING:
						{
							this->buffers[i] = new char[field->length];
							this->row[i].buffer = this->buffers[i];
						}
						break;
					}

					this->row[i].buffer_length = field->length;
					this->row[i].length = &this->lengths[i];
					this->row[i].is_null = &this->is_nulls[i];
					this->row[i].error = &this->errors[i];
				}

				if(mysql_stmt_bind_result(this->stmt, this->row)){
					std::cout << mysql_stmt_error(this->stmt) << std::endl;
				}

				if(mysql_stmt_store_result(this->stmt)){
					std::cout << mysql_stmt_error(this->stmt) << std::endl;
				}
			}

			void MySqlDataReader::FillTable(DataTable& table){
				size_t colCount = 0;
				size_t rowCount = 0;
				Type t;
				MYSQL_FIELD* field;

				table = GetSchemaTable();

				colCount = this->cols.Count();
				rowCount = mysql_stmt_num_rows(this->stmt);

				for(size_t i = 0; i < rowCount; ++i){
					DataRow rowDest = table.NewRow();

					mysql_stmt_fetch(this->stmt);
					//rowSrc = mysql_fetch_row(this->resultset);

					for(size_t g = 0; g < colCount; ++g){
						field = mysql_fetch_field_direct(this->resultset, g);

						switch(field->type){
							case enum_field_types::MYSQL_TYPE_BIT:
							{
								unsigned long temp = *((unsigned long*)this->row[g].buffer);
								rowDest.SetField(g, temp);
							}
							break;
							case enum_field_types::MYSQL_TYPE_BLOB:
							{
								std::string str = (char*)this->row[g].buffer;
								String temp(&str);
								rowDest.SetField<String>(g, temp);
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

								rowDest.SetField(g, dt);
							}
							break;
							case enum_field_types::MYSQL_TYPE_DATETIME:
							{
								DateTime dt;
								MYSQL_TIME* time;

								time = ((MYSQL_TIME*)this->row[g].buffer);

								dt = DateTime(time->year, time->month, time->day, time->hour, time->minute, time->second, time->second_part);
								/*dt = dt.addYears(time.year);
								dt = dt.addMonths(time.month);
								dt = dt.addDays(time.day);
								dt = dt.addHours(time.hour);
								dt = dt.addMinutes(time.minute);
								dt = dt.addSeconds(time.second);
								dt = dt.addMicroseconds(time.second_part);*/

								rowDest.SetField(g, dt);
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

								rowDest.SetField(g, dt);
							}
							break;
							case enum_field_types::MYSQL_TYPE_DECIMAL:
							{
								long double temp = *((long double*)this->row[g].buffer);
								rowDest.SetField(g, temp);
							}
							break;
							case enum_field_types::MYSQL_TYPE_DOUBLE:
							{
								double temp = *((double*)this->row[g].buffer);
								rowDest.SetField(g, temp);
							}
							break;
							case enum_field_types::MYSQL_TYPE_FLOAT:
							{
								float temp = *((float*)this->row[g].buffer);
								rowDest.SetField(g, temp);
							}
							break;
							// -------------------------------------------------------
							case enum_field_types::MYSQL_TYPE_INT24:
							{
								int temp = *((int*)this->row[g].buffer);
								rowDest.SetField(g, temp);
							}
							break;
							case enum_field_types::MYSQL_TYPE_JSON:
							{
								std::string str = (char*)this->row[g].buffer;
								String temp(&str);
								rowDest.SetField<String>(g, temp);
							}
							break;
							case enum_field_types::MYSQL_TYPE_LONG:
							{
								long temp = *((long*)this->row[g].buffer);
								rowDest.SetField(g, temp);
							}
							break;
							case enum_field_types::MYSQL_TYPE_LONGLONG:
							{
								long long temp = *((long long*)this->row[g].buffer);
								rowDest.SetField(g, temp);
							}
							break;
							case enum_field_types::MYSQL_TYPE_LONG_BLOB:
							{
								std::string str = (char*)this->row[g].buffer;
								String temp(&str);
								rowDest.SetField<String>(g, temp);
							}
							break;
							case enum_field_types::MYSQL_TYPE_MEDIUM_BLOB:
							{
								std::string str = (char*)this->row[g].buffer;
								String temp(&str);
								rowDest.SetField<String>(g, temp);
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
								rowDest.SetField(g, dt);
							}
							break;
							case enum_field_types::MYSQL_TYPE_NEWDECIMAL:
							{
								long double temp = *((long double*)this->row[g].buffer);
								rowDest.SetField(g, temp);
							}
							break;
							case enum_field_types::MYSQL_TYPE_NULL:
							{
								long temp = *((long*)this->row[g].buffer);
								rowDest.SetField(g, temp);
							}
							break;
							case enum_field_types::MYSQL_TYPE_SHORT:
							{
								short temp = *((short*)this->row[g].buffer);
								rowDest.SetField(g, temp);
							}
							break;
							case enum_field_types::MYSQL_TYPE_STRING:
							{
								std::string str = (char*)this->row[g].buffer;
								String temp(&str);
								rowDest.SetField<String>(g, temp);
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
								rowDest.SetField(g, dt);
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
								rowDest.SetField(g, dt);
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
								rowDest.SetField(g, dt);
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
								rowDest.SetField(g, dt);
							}
							break;
							case enum_field_types::MYSQL_TYPE_TINY:
							{
								short temp = *((short*)this->row[g].buffer);
								rowDest.SetField(g, temp);
							}
							break;
							case enum_field_types::MYSQL_TYPE_TINY_BLOB:
							{
								std::string str = (char*)this->row[g].buffer;
								String temp(&str);
								rowDest.SetField<String>(g, temp);
							}
							break;
							case enum_field_types::MYSQL_TYPE_VARCHAR:
							{
								std::string str = (char*)this->row[g].buffer;
								String temp(&str);
								rowDest.SetField<String>(g, temp);
							}
							case enum_field_types::MYSQL_TYPE_VAR_STRING:
							{
								std::string str = (char*)this->row[g].buffer;
								String temp(&str);
								rowDest.SetField<String>(g, temp);
							}
							break;
						}
					}

					table.Rows().Add(rowDest);
				}
			}

			unsigned int MySqlDataReader::FieldCount(){
				return mysql_num_fields(this->resultset);
			}

			bool MySqlDataReader::GetBoolean(int i){
				bool res;

				res = *((bool*)this->row[i].buffer);

				return res;
			}

			char MySqlDataReader::GetByte(int i){
				return *((char*)this->row[i].buffer);
			}

			long MySqlDataReader::GetBytes(int i, long dataIndex, char * buffer, int bufferIndex, int length){
				return 0;
			}

			long MySqlDataReader::GetChars(int i, long dataIndex, char * buffer, int bufferIndex, int length){
				return 0;
			}

			String MySqlDataReader::GetDataTypeName(int i){
				MYSQL_FIELD* field;
				String res;

				field = mysql_fetch_field_direct(this->resultset, i);

				res = String(field->name);

				return res;
			}

			DateTime MySqlDataReader::GetDateTime(int i){
				DateTime res;
				MYSQL_FIELD* field;
				MYSQL_TIME time;

				if(!(i < this->cols.Count())){
					throw "Column out of Range!";
				}

				field = mysql_fetch_field_direct(this->resultset, i);
				if(field->type != enum_field_types::MYSQL_TYPE_DATETIME){
					throw std::string("Column Nr." + std::to_string(i) + " is not of DateTime-type.");
				}



				time = *((MYSQL_TIME*)this->row[i].buffer);

				res.addYears(time.year);
				res.addMonths(time.month);
				res.addDays(time.day);
				res.addHours(time.hour);
				res.addMinutes(time.minute);
				res.addSeconds(time.second);
				res.addMicroseconds(time.second_part);

				return res;
			}

			double MySqlDataReader::GetDouble(int i){
				float res;
				MYSQL_FIELD* field;

				if(!(i < this->cols.Count())){
					throw "Column out of Range!";
				}

				field = mysql_fetch_field_direct(this->resultset, i);
				if(field->type != enum_field_types::MYSQL_TYPE_FLOAT){
					throw std::string("Column Nr." + std::to_string(i) + " is not of float-type.");
				}

				res = *((double*)this->row[i].buffer);

				return res;
			}

			Type MySqlDataReader::GetFieldType(int i){
				return this->cols[i].second;
			}

			float MySqlDataReader::GetFloat(int i){
				float res;
				MYSQL_FIELD* field;

				if(!(i < this->cols.Count())){
					throw "Column out of Range!";
				}

				field = mysql_fetch_field_direct(this->resultset, i);
				if(field->type != enum_field_types::MYSQL_TYPE_FLOAT){
					throw std::string("Column Nr." + std::to_string(i) + " is not of float-type.");
				}
				res = *((float*)this->row[i].buffer);

				return res;
			}

			int MySqlDataReader::GetInteger(int i){
				int res;
				MYSQL_FIELD* field;

				if(!(i < this->cols.Count())){
					throw "Column out of Range!";
				}

				field = mysql_fetch_field_direct(this->resultset, i);
				if(field->type != enum_field_types::MYSQL_TYPE_INT24){
					throw std::string("Column Nr." + std::to_string(i) + " is not of int-type.");
				}

				res = *((int*)this->row[i].buffer);

				return res;
			}

			long MySqlDataReader::GetLong(int i){
				long res;
				MYSQL_FIELD* field;

				if(!(i < this->cols.Count())){
					throw "Column out of Range!";
				}

				field = mysql_fetch_field_direct(this->resultset, i);
				if(field->type != enum_field_types::MYSQL_TYPE_LONG){
					throw std::string("Column Nr." + std::to_string(i) + " is not of long-type.");
				}

				res = *((long*)this->row[i].buffer);

				return res;
			}

			String MySqlDataReader::GetName(int i){
				if(!(i < this->cols.Count())){
					throw "Column out of Range!";
				}

				return this->cols[i].first;
			}

			int MySqlDataReader::GetOrdinal(String & name){
				int ordinal = -1;
				size_t len = 0;

				len = this->cols.Count();

				for(size_t i = 0; i < len; i++){
					if(this->cols[i].first == name){
						ordinal = i;
						break;
					}
				}

				return ordinal;
			}

			DataTable MySqlDataReader::GetSchemaTable(){
				size_t len = 0;
				String colName;
				Type t;
				DataTable table;
				MYSQL_FIELD *field;

				len = mysql_num_fields(this->resultset);
				unsigned long long len2 = mysql_stmt_field_count(this->stmt);

				for(size_t i = 0; i < len; i++){
					DataColumn col;
					col.ColumnName(this->cols[i].first);
					col.DataType(this->cols[i].second);
					table.Columns().Add(col);
				}

				table.TableName(this->tableName);

				return table;
			}

			short MySqlDataReader::GetShort(int i){
				short res;
				MYSQL_FIELD* field;

				if(!(i < this->cols.Count())){
					throw "Column out of Range!";
				}

				field = mysql_fetch_field_direct(this->resultset, i);
				if(field->type != enum_field_types::MYSQL_TYPE_SHORT){
					throw std::string("Column Nr." + std::to_string(i) + " is not of short-type.");
				}

				res = *((short*)this->row[i].buffer);

				return res;
			}

			String MySqlDataReader::GetString(int i){
				int colType = 0;
				String res;
				MYSQL_FIELD* field;

				if(!(i < this->cols.Count())){
					throw "Column out of Range!";
				}

				field = mysql_fetch_field_direct(this->resultset, i);
				if(field->type != enum_field_types::MYSQL_TYPE_JSON || field->type != enum_field_types::MYSQL_TYPE_STRING || field->type != enum_field_types::MYSQL_TYPE_VARCHAR || field->type != enum_field_types::MYSQL_TYPE_VAR_STRING){
					throw std::string("Column Nr." + std::to_string(i) + " is not a string-type.");
				}

				std::string str = (char*)this->row[i].buffer;
				res = String(&str);

				return res;
			}

			bool MySqlDataReader::HasRows(){
				return mysql_stmt_num_rows(this->stmt) > 0 ? true : false;
			}

			bool MySqlDataReader::NextResult(){
				mysql_fetch_row(this->resultset);

				if(this->row){
					return true;
				} else{
					return false;
				}
			}
		}
	}
}