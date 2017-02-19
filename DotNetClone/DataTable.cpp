#include "DataTable.h"



DataTable::DataTable()
{
	this->columns = new DataColumnCollection();
	this->rows = new DataRowCollection();
}

DataTable::DataTable(const char * name)
{
	this->name = name;
	this->columns = new DataColumnCollection();
	this->rows = new DataRowCollection();
}

DataTable::DataTable(String & name)
{
	this->name = name;
	this->columns = new DataColumnCollection();
	this->rows = new DataRowCollection();
}


DataTable::~DataTable()
{
	delete this->columns;
	delete this->rows;
}

string DataTable::toString()
{
	return string("System.Data.DataTable");
}

string DataTable::getTypeString()
{
	return string("DataTable");
}

DataRow DataTable::NewRow()
{
	return DataRow(this->columns);
}

String DataTable::TableName()
{
	return this->name;
}

void DataTable::TableName(String & name)
{
	this->name = name;
}

DataColumnCollection& DataTable::Columns()
{
	return *this->columns;
}

/*
void DataTable::Columns(DataColumnCollection col)
{
	this->columns = col;
}
*/

DataRowCollection& DataTable::Rows()
{
	return *this->rows;
}

/*
void DataTable::Rows(DataRowCollection rows)
{
	this->rows = rows;
}
*/