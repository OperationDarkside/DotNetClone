#include "DataColumn.h"

#pragma once
class DataColumnCollection :public Object
{
public:
	DataColumnCollection();
	~DataColumnCollection();

	string toString();
	string getTypeString();

	void Add(DataColumn& column);
	long Count();
private:
	vector<DataColumn> cols;
};

