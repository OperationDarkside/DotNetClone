#include "Object.h"
#include "String.h"
#include "DataColumnCollection.h"
#include "DataRowCollection.h"

#pragma once
class DataTable : public Object
{
public:
	// Constructors
	DataTable();
	DataTable(const char* name);
	DataTable(String& name);
	~DataTable();

	// Inherited
	string toString();
	string getTypeString();

	//Methods
	DataRow NewRow();

	//Properties
	String TableName();
	void TableName(String& name);
	DataColumnCollection& Columns();
	//void Columns(DataColumnCollection col);
	DataRowCollection& Rows();
	//void Rows(DataRowCollection rows);
private:
	String name;
	DataColumnCollection* columns;
	DataRowCollection* rows;
};

