#include "DataRow.h"



DataRow::DataRow()
{
}

DataRow::DataRow(DataColumnCollection * columns) : cols(columns)
{
	this->items.resize(columns->Count());
}


DataRow::~DataRow()
{
	/*long len = 0;

	len = this->items.size();

	for (size_t i = 0; i < len; i++)
	{
		delete this->items[i];
	}*/
}

string DataRow::toString()
{
	return string("System.Data.DataRow");
}

string DataRow::getTypeString()
{
	return string("DataRow");
}

void DataRow::SetField(int columnNr, bool value)
{
	Boolean* boo;

	boo = new Boolean(value);

	this->items[columnNr] = boo;
}