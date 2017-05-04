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
	size_t len = 0;
	len = this->cols.size();

	for(size_t i = 0; i < len; i++){
		if(this->cols[i].ColumnName() == column.ColumnName()){
			throw "Column already exists!";
			return;
		}
	}

	this->cols.push_back(column);
}

void DataColumnCollection::Clear(){
	this->cols.clear();
}

long DataColumnCollection::Count(){
	return this->cols.size();
}

int DataColumnCollection::IndexOf(DataColumn & column){
	size_t len = 0;
	len = this->cols.size();

	for(size_t i = 0; i < len; i++){
		if(this->cols[i].ColumnName() == column.ColumnName()){
			return i;
		}
	}

	return -1;
}

void DataColumnCollection::Remove(DataColumn * column){
	size_t len_col = 0;
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
	size_t len_col = 0;
	DataColumn* col2comp;

	len_col = this->cols.size();
	for(size_t i = 0; i < len_col; i++){
		col2comp = &this->cols[i];

		if(col2comp->ColumnName() == name){
			this->cols.erase(this->cols.begin() + i);

			this->table->RemoveColumn(i);
			return;
		}
	}
}

DataTable * DataColumnCollection::Table(){
	return this->table;
}

void DataColumnCollection::Table(DataTable * _table){
	this->table = _table;
}

DataColumn & DataColumnCollection::operator[](int colNr){
	return cols[colNr];
}
