#include "MySqlDataReader.h"

MySqlDataReader::MySqlDataReader(sql::ResultSet* result, sql::ResultSetMetaData* meta):result(result), meta(meta){

}

void MySqlDataReader::FillTable(DataTable& table){
	int colType = 0;
	unsigned int colCount = 0;
	int* colTypes;
	Type t;
	//DataTable resTable;

	table = GetSchemaTable();

	colCount = this->meta->getColumnCount();
	colTypes = new int[colCount + 1];

	for(unsigned int i = 1; i <= colCount; i++){
		colTypes[i] = this->meta->getColumnType(i);
	}

	while(this->result->next()){
		DataRow row = table.NewRow();

		for(unsigned int i = 1; i <= colCount; i++){
			colType = colTypes[i];

			switch(colType){
			case sql::DataType::BIGINT:
				if(this->meta->isSigned(i)){
					//nyi
					t = Type::getType<long long>(3456L);
				} else{
					//nyi
					t = Type::getType<unsigned long long>(3456L);
				}
				break;
			case sql::DataType::INTEGER:
				if(this->meta->isSigned(i)){
					row.SetField(i - 1, this->result->getInt(i));
				} else{
					//nyi
					t = Type::getType<unsigned int>(3456);
				}
				break;
			case sql::DataType::VARCHAR:
				istream* stream = this->result->getBlob(i);
				string str(istreambuf_iterator<char>(*stream), {});

				row.SetField<String>(i - 1, String(&str));
				break;
			}

		}

		table.Rows().Add(row);
	}
}


MySqlDataReader::~MySqlDataReader(){}

unsigned int MySqlDataReader::FieldCount(){
	return meta->getColumnCount();
}

bool MySqlDataReader::GetBoolean(int i){
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
	return String(&string(this->meta->getColumnTypeName(i).asStdString()));
}

DateTime MySqlDataReader::GetDateTime(int i){
	return DateTime();
}

double MySqlDataReader::GetDouble(int i){
	return 0.0;
}

Type MySqlDataReader::GetFieldType(int i){
	int colType = 0;
	Type t;

	colType = this->meta->getColumnType(i);

	switch(colType){
	case sql::DataType::BIGINT:
		if(this->meta->isSigned(i)){
			t = Type::getType<long long>(3456L);
		} else{
			t = Type::getType<unsigned long long>(3456L);
		}
		break;
	case sql::DataType::INTEGER:
		if(this->meta->isSigned(i)){
			t = Type::getType<int>(3456);
		} else{
			t = Type::getType<unsigned int>(3456);
		}
		break;
	case sql::DataType::VARCHAR:
		t = Type::getType<String>(String());
		break;
	}

	return t;
}

float MySqlDataReader::GetFloat(int i){
	return 0.0f;
}

int MySqlDataReader::GetInteger(int i){
	int res = 0;
	int colType = 0;

	colType = this->meta->getColumnType(i);

	switch(colType){
	case sql::DataType::INTEGER:
		res = this->result->getInt(i);
		break;
	}

	return res;
}

long MySqlDataReader::GetLong(int i){
	return 0;
}

String MySqlDataReader::GetName(int i){
	sql::SQLString sqlstr;

	sqlstr = this->meta->getColumnName(i);

	return String(&string(sqlstr.c_str()));
}

int MySqlDataReader::GetOrdinal(String & name){
	return 0;
}

DataTable MySqlDataReader::GetSchemaTable(){
	unsigned int len = 0;
	sql::SQLString tableName;
	String colName;
	Type t;
	DataTable table;

	tableName = this->meta->getTableName(1);
	table.TableName(String(&string(tableName.c_str())));

	len = this->meta->getColumnCount();

	for(size_t i = 1; i <= len; i++){
		DataColumn col;

		t = GetFieldType(i);
		colName = GetName(i);

		col.ColumnName(colName);
		col.DataType(t);

		table.Columns().Add(col);
	}

	return table;
}

short MySqlDataReader::GetShort(int i){
	return 0;
}

String MySqlDataReader::GetString(int i){
	int colType = 0;
	String res;

	colType = this->meta->getColumnType(i);

	switch(colType){
	case sql::DataType::VARCHAR:
		istream* stream = this->result->getBlob(i);
		res = string(istreambuf_iterator<char>(*stream), {});
		break;
	}

	return res;
}

bool MySqlDataReader::NextResult(){
	return false;
}
