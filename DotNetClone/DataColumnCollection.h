#ifndef DATACOLCOLLECTION_H
#define DATACOLCOLLECTION_H

#include "DataColumn.h"

class DataTable;

#pragma once
/**
Stores the columns of a DataTable instance
*/
class DataColumnCollection : public Object
{
public:
	DataColumnCollection();
	~DataColumnCollection();

	string toString();
	string getTypeString();

	friend class DataTable;

	/**
	Adds a DataColumn instance to this collection

	@param The DataColumn instance to be added
	*/
	void Add(DataColumn& column);
	/**
	Returns the amount of columns in this collection

	@return The column number
	*/
	long Count();
	void Remove(DataColumn* column);
	void Remove(String& name);
	DataTable* Table();
	void Table(DataTable* _table);

	DataColumn& operator[](int colNr);
private:
	DataTable* table;
	vector<DataColumn> cols;
};
#endif // !DATACOLCOLLECTION_H