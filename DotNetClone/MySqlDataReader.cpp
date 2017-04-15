#include "MySqlDataReader.h"

MySqlDataReader::~MySqlDataReader(){
	mysql_free_result(this->resultset);
}

MySqlDataReader::MySqlDataReader(MYSQL_RES * _resultset): resultset(_resultset){
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

		this->cols.push_back(make_pair(field->name, t));
	}
}

void MySqlDataReader::FillTable(DataTable& table){
	size_t colCount = 0;
	size_t rowCount = 0;
	Type t;
	MYSQL_FIELD* field;
	MYSQL_ROW rowSrc;

	table = GetSchemaTable();

	colCount = this->cols.size();
	rowCount = mysql_num_rows(this->resultset);

	for(size_t i = 0; i < rowCount; ++i){
		DataRow rowDest = table.NewRow();

		rowSrc = mysql_fetch_row(this->resultset);

		for(size_t g = 0; g < colCount; ++g){
			field = mysql_fetch_field_direct(this->resultset, g);

			switch(field->type){
			case enum_field_types::MYSQL_TYPE_INT24:
			{
				int temp = atoi(rowSrc[g]);
				rowDest.SetField(g, temp);
			}
			break;
			case enum_field_types::MYSQL_TYPE_LONG:
			{
				long temp = atol(rowSrc[g]);
				rowDest.SetField(g, temp);
			}
			break;
			case enum_field_types::MYSQL_TYPE_VARCHAR:
			{
				string str = rowSrc[g];
				String temp(&str);
				rowDest.SetField<String>(g, temp);
			}
			case enum_field_types::MYSQL_TYPE_VAR_STRING:
			{
				string str = rowSrc[g];
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



	return res;
}

char MySqlDataReader::GetByte(int i){
	return 0;
}

long MySqlDataReader::GetBytes(int i, long dataIndex, char * buffer, int bufferIndex, int length){
	return 0;
}

long MySqlDataReader::GetChars(int i, long dataIndex, char * buffer, int bufferIndex, int length){
	return 0;
}

String MySqlDataReader::GetDataTypeName(int i){
	//return String(&string(this->meta->getColumnTypeName(i).asStdString()));
	return String();
}

DateTime MySqlDataReader::GetDateTime(int i){
	DateTime res;
	MYSQL_FIELD* field;

	if(!(i < this->cols.size())){
		throw "Column out of Range!";
	}

	field = mysql_fetch_field_direct(this->resultset, i);
	if(field->type != enum_field_types::MYSQL_TYPE_DATETIME){
		throw string("Column Nr." + to_string(i) + " is not of DateTime-type.");
	}

	// TODO

	// res = this->row[i];

	return res;
}

double MySqlDataReader::GetDouble(int i){
	float res;
	MYSQL_FIELD* field;

	if(!(i < this->cols.size())){
		throw "Column out of Range!";
	}

	field = mysql_fetch_field_direct(this->resultset, i);
	if(field->type != enum_field_types::MYSQL_TYPE_FLOAT){
		throw string("Column Nr." + to_string(i) + " is not of float-type.");
	}
	res = atof(this->row[i]);

	return res;
}

Type MySqlDataReader::GetFieldType(int i){
	return this->cols[i].second;
}

float MySqlDataReader::GetFloat(int i){
	float res;
	MYSQL_FIELD* field;

	if(!(i < this->cols.size())){
		throw "Column out of Range!";
	}

	field = mysql_fetch_field_direct(this->resultset, i);
	if(field->type != enum_field_types::MYSQL_TYPE_FLOAT){
		throw string("Column Nr." + to_string(i) + " is not of float-type.");
	}
	res = atof(this->row[i]);

	return res;
}

int MySqlDataReader::GetInteger(int i){
	int res;
	MYSQL_FIELD* field;

	if(!(i < this->cols.size())){
		throw "Column out of Range!";
	}

	field = mysql_fetch_field_direct(this->resultset, i);
	if(field->type != enum_field_types::MYSQL_TYPE_INT24){
		throw string("Column Nr." + to_string(i) + " is not of int-type.");
	}
	res = atoi(this->row[i]);

	return res;
}

long MySqlDataReader::GetLong(int i){
	long res;
	MYSQL_FIELD* field;

	if(!(i < this->cols.size())){
		throw "Column out of Range!";
	}

	field = mysql_fetch_field_direct(this->resultset, i);
	if(field->type != enum_field_types::MYSQL_TYPE_LONG){
		throw string("Column Nr." + to_string(i) + " is not of long-type.");
	}
	res = atol(this->row[i]);

	return res;
}

String MySqlDataReader::GetName(int i){
	return this->cols[i].first;
}

int MySqlDataReader::GetOrdinal(String & name){
	return 0;
}

DataTable MySqlDataReader::GetSchemaTable(){
	size_t len = 0;
	String colName;
	Type t;
	DataTable table;
	MYSQL_FIELD *field;

	len = mysql_num_fields(this->resultset);

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

	if(!(i < this->cols.size())){
		throw "Column out of Range!";
	}

	field = mysql_fetch_field_direct(this->resultset, i);
	if(field->type != enum_field_types::MYSQL_TYPE_SHORT){
		throw string("Column Nr." + to_string(i) + " is not of short-type.");
	}
	res = atoi(this->row[i]);

	return res;
}

String MySqlDataReader::GetString(int i){
	int colType = 0;
	String res;
	MYSQL_FIELD* field;

	if(!(i < this->cols.size())){
		throw "Column out of Range!";
	}

	field = mysql_fetch_field_direct(this->resultset, i);
	if(field->type != enum_field_types::MYSQL_TYPE_JSON || field->type != enum_field_types::MYSQL_TYPE_STRING || field->type != enum_field_types::MYSQL_TYPE_VARCHAR || field->type != enum_field_types::MYSQL_TYPE_VAR_STRING){
		throw string("Column Nr." + to_string(i) + " is not a string-type.");
	}

	string str = this->row[i];
	res = String(&str);

	return res;
}

bool MySqlDataReader::NextResult(){
	this->row = mysql_fetch_row(this->resultset);

	if(this->row){
		return true;
	} else{
		return false;
	}
}
