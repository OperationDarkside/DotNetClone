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
			i++;
		}

		// Name
		//this->colNames.push_back(field->name);

		//Type
		switch(field->type){
		case enum_field_types::MYSQL_TYPE_INT24:
			t = Type::getType<int>(3456);
			break;
		case enum_field_types::MYSQL_TYPE_LONG:
			t = Type::getType<long>(3456);
			break;
		case enum_field_types::MYSQL_TYPE_VARCHAR:
			t = Type::getType<String>(String());
			break;
		case enum_field_types::MYSQL_TYPE_VAR_STRING:
			t = Type::getType<String>(String());
			break;
		}
		//this->colTypes.push_back(t);

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
	//return meta->getColumnCount();
	return mysql_num_fields(this->resultset);
}

bool MySqlDataReader::GetBoolean(int i){
	bool res;
	/*int colType = 0;

	colType = this->meta->getColumnType(i);

	if(colType == sql::DataType::BIT){
		res = this->result->getBoolean(i);
	} else{

	}*/

	return false;
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
	return DateTime();
}

double MySqlDataReader::GetDouble(int i){
	return 0.0;
}

Type MySqlDataReader::GetFieldType(int i){
	/*mysqlpp::mysql_type_info colType;
	Type t;

	colType = this->result.field_type(i);

	// INTEGER
	if(colType == typeid(mysqlpp::sql_int)){
		t = Type::getType<int>(3456);
	}
	// STRING
	if(colType == typeid(mysqlpp::sql_varchar)){
		t = Type::getType<String>(String());
	}

	return t;*/
	return this->cols[i].second;
}

float MySqlDataReader::GetFloat(int i){
	return 0.0f;
}

int MySqlDataReader::GetInteger(int i){
	int res = 0;
	int colType = 0;

	/*colType = this->meta->getColumnType(i);

	switch(colType){
	case sql::DataType::INTEGER:
		res = this->result->getInt(i);
		break;
	}*/

	return res;
}

long MySqlDataReader::GetLong(int i){
	return 0;
}

String MySqlDataReader::GetName(int i){
	/*string name = this->result.field_name(i);
	return String(&name);*/
	return String();
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
	return 0;
}

String MySqlDataReader::GetString(int i){
	int colType = 0;
	String res;

	/*colType = this->meta->getColumnType(i);

	switch(colType){
	case sql::DataType::VARCHAR:
		istream* stream = this->result->getBlob(i);
		res = string(istreambuf_iterator<char>(*stream), {});
		break;
	}*/

	return res;
}

bool MySqlDataReader::NextResult(){
	return false;
}
