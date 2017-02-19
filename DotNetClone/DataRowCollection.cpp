#include "DataRowCollection.h"



DataRowCollection::DataRowCollection()
{
}


DataRowCollection::~DataRowCollection()
{
}

string DataRowCollection::toString()
{
	return string("System.Data.DataRowCollection");
}

string DataRowCollection::getTypeString()
{
	return string("DataRowCollection");
}

void DataRowCollection::Add(DataRow row)
{
	this->rows.push_back(row);
}

long DataRowCollection::Count()
{
	return this->rows.size();
}
