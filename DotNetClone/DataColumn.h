#include "Object.h"
#include "String.h"

#pragma once
class DataColumn : public Object
{
public:
	DataColumn();
	DataColumn(const char* name);
	DataColumn(String& name);
	~DataColumn();

	string toString();
	string getTypeString();

	String ColumnName();
	void ColumnName(String& columnName);
private:
	String name;
};

