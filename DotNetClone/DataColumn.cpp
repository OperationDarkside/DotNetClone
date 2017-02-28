#include "DataColumn.h"

DataColumn::DataColumn(){}

DataColumn::DataColumn(const char * name, Type& type){
	this->name = String(&string(name));
	this->type = type;
}

DataColumn::DataColumn(String & name, Type& type){
	this->name = name;
	this->type = type;
}

DataColumn::~DataColumn(){}

string DataColumn::toString(){
	return string("System.Data.DataColumn");
}

string DataColumn::getTypeString(){
	return string("DataColumn");
}

bool DataColumn::checkType(Type& type){
	return this->type == type;
}

String DataColumn::ColumnName(){
	return this->name;
}

void DataColumn::ColumnName(String & columnName){
	String* str = new String(columnName);
	this->name = str;
}

Type DataColumn::DataType(){

	return this->type;
}

void DataColumn::DataType(Type & type){
	this->type = type;
}