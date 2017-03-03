#include "DataRow.h"

#pragma once
/**
Stores the rows of a DataTable instance
*/
class DataRowCollection : public Object
{
public:
	DataRowCollection();
	~DataRowCollection();

	string toString();
	string getTypeString();

	friend class DataTable;

	/**
	Adds a DataRow instance to this collection

	@param The DataRow to be added
	*/
	void Add(DataRow& row);
	/**
	Returns the amount of rows in this collection

	@return The row count
	*/
	long Count();

	DataRow& operator[](int columnNr);
	
private:
	vector<DataRow> rows;
};