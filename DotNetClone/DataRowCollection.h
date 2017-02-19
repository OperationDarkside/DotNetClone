#include "DataRow.h"

#pragma once
class DataRowCollection : public Object
{
public:
	DataRowCollection();
	~DataRowCollection();

	string toString();
	string getTypeString();

	void Add(DataRow row);
	long Count();

private:
	vector<DataRow> rows;
};

