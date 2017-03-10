#include "DataTable.h"

DataTable::DataTable()
{
	this->columns.table = this;
}

DataTable::DataTable(const char * name)
{
	this->name = name;
	this->columns.table = this;
}

DataTable::DataTable(String & name)
{
	this->name = name;
	this->columns.table = this;
}


DataTable::~DataTable()
{
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
	return DataRow(&this->columns);
}

void DataTable::Clear(){
	this->columns.Clear();
	this->rows.Clear();
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
	return this->columns;
}

DataRowCollection& DataTable::Rows()
{
	return this->rows;
}

void DataTable::RemoveColumn(size_t index){
	size_t len = 0;

	len = this->rows.rows.size();

	for(size_t i = 0; i < len; i++){
		this->rows.rows[i].RemoveItem(index);
	}
}