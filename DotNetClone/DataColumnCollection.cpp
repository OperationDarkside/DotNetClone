#include "DataColumnCollection.h"
#include "DataTable.h"

DataColumnCollection::DataColumnCollection(){}

DataColumnCollection::~DataColumnCollection(){}

string DataColumnCollection::toString(){
	return string("System.Data.DataColumnCollection");
}

string DataColumnCollection::getTypeString(){
	return string("DataColumnCollection");
}

void DataColumnCollection::Add(DataColumn& column){
	this->cols.push_back(column);
}

long DataColumnCollection::Count(){
	return this->cols.size();
}

void DataColumnCollection::Remove(DataColumn * column){
	size_t index = 0;
	size_t len_col = 0;
	size_t len_rows = 0;
	DataColumn* col2comp;

	if(column == nullptr){
		throw "Column is null";
		return;
	}

	len_col = this->cols.size();
	for(size_t i = 0; i < len_col; i++){
		col2comp = &this->cols[i];

		if(col2comp->ColumnName() == column->ColumnName()){
			this->cols.erase(this->cols.begin() + i);

			this->table->RemoveColumn(i);
			return;
		}
	}
}

void DataColumnCollection::Remove(String & name){

}

DataTable * DataColumnCollection::Table(){
	return nullptr;
}

void DataColumnCollection::Table(DataTable * _table){}

DataColumn & DataColumnCollection::operator[](int colNr){
	return cols[colNr];
}
