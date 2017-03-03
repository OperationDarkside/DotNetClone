#ifndef DATATABLE_H
#define DATATABLE_H

#include "Object.h"
#include "String.h"
#include "DataRowCollection.h"

class DataColumnCollection;

#pragma once
/**
In-Memory dynamic Table class
*/
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

	friend class DataColumnCollection;

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

	void RemoveColumn(size_t index);
};
#endif // !DATATABLE_H