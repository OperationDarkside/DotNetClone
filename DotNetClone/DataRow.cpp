#include "DataRow.h"
#include "DataColumnCollection.h"


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

void DataRow::RemoveItem(size_t index){
	size_t len = 0;

	len = this->items.size();

	if((len - 1) < index){
		throw "Remove item index out of range";
	}

	delete this->items[index];

	this->items.erase(this->items.begin() + index);
}
