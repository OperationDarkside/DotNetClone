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

void DataRowCollection::Add(DataRow& row)
{
	DataRow* r = new DataRow(row);

	this->rows.push_back(*r);
}

long DataRowCollection::Count()
{
	return this->rows.size();
}

DataRow & DataRowCollection::operator[](int columnNr)
{
	return this->rows[columnNr];
}
