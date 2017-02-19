#include "DataColumn.h"



DataColumn::DataColumn()
{
}

DataColumn::DataColumn(const char * name)
{
}

DataColumn::DataColumn(String & name)
{
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
	return String();
}

void DataColumn::ColumnName(String & columnName)
{
}
