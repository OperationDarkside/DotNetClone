#include "Object.h"
#include "String.h"

#pragma once
/**
Column Object for the DataTable class
*/
class DataColumn : public Object
{
public:
	DataColumn();
	DataColumn(const char* name);
	DataColumn(String& name);
	~DataColumn();

	string toString();
	string getTypeString();

	/**
	Returns the name of this column instance

	@return The column name
	*/
	String ColumnName();
	/**
	Sets the name of this column instance

	@param The column name
	*/
	void ColumnName(String& columnName);
private:
	String name;
};

