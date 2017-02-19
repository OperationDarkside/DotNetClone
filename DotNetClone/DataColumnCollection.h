#include "DataColumn.h"

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
private:
	vector<DataColumn> cols;
};

