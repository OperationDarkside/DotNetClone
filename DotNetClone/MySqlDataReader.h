#pragma once
#include "DateTime.h"
#include "Type.h"
#include "DataTable.h"
#include "SqlDataReader.h"
#include "MySQL\include\cppconn\resultset.h"
#include "MySQL\include\cppconn\resultset_metadata.h"

class MySqlDataReader: public SqlDataReader{

	friend class MySqlCommand;
	friend class MySqlDataAdapter;

public:
	~MySqlDataReader();

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

	bool NextResult();

private:
	sql::ResultSet* result;
	sql::ResultSetMetaData* meta;

	MySqlDataReader(sql::ResultSet* result, sql::ResultSetMetaData* meta);

	void FillTable(DataTable& table);
};

