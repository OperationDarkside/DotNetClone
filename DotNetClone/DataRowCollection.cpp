#include "DataRowCollection.h"

DataRowCollection::DataRowCollection(){}

DataRowCollection::~DataRowCollection(){}

string DataRowCollection::toString(){
	return string("System.Data.DataRowCollection");
}

string DataRowCollection::getTypeString(){
	return string("DataRowCollection");
}

void DataRowCollection::Add(DataRow& row){
	DataRow* r = new DataRow(row);

	this->rows.push_back(*r);
}

void DataRowCollection::Clear(){
	this->rows.clear();
}

long DataRowCollection::Count(){
	return this->rows.size();
}

int DataRowCollection::IndexOf(DataRow & row){
	size_t len = 0;

	len = this->rows.size();

	for(size_t i = 0; i < len; i++){
		if(&this->rows[i] == &row){
			return i;
		}
	}

	return -1;
}

void DataRowCollection::InsertAt(DataRow & row, int pos){
	this->rows.insert(this->rows.begin() + pos, row);
}

DataRow & DataRowCollection::operator[](int columnNr){
	return this->rows[columnNr];
}