#include "DataColumn.h"



DataColumn::DataColumn()
{
}

DataColumn::DataColumn(const char * name)
{
	this->name = String(&string(name));
}

DataColumn::DataColumn(String & name)
{
	this->name = name;
}


DataColumn::~DataColumn()
{
}

string DataColumn::toString()
{
	return string("System.Data.DataColumn");
}

string DataColumn::getTypeString()
{
	return string("DataColumn");
}

String DataColumn::ColumnName()
{
	return this->name;
}

void DataColumn::ColumnName(String & columnName)
{
}
