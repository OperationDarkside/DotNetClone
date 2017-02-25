#include "DataColumnCollection.h"



DataColumnCollection::DataColumnCollection()
{
}


DataColumnCollection::~DataColumnCollection()
{
}

string DataColumnCollection::toString()
{
	return string("System.Data.DataColumnCollection");
}

string DataColumnCollection::getTypeString()
{
	return string("DataColumnCollection");
}

void DataColumnCollection::Add(DataColumn& column)
{
	this->cols.push_back(column);
}

long DataColumnCollection::Count()
{
	return this->cols.size();
}

DataColumn & DataColumnCollection::operator[](int colNr){
		return cols[colNr];
}
