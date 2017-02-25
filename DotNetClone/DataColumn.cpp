#include "DataColumn.h"

DataColumn::DataColumn(){}

DataColumn::DataColumn(const char * name, Object* o) {
	this->name = String(&string(name));
	this->type = &typeid(*o);
}

DataColumn::DataColumn(String & name, Object* o) {
	this->name = name;
	this->type = &typeid(*o);
}

DataColumn::~DataColumn(){}

string DataColumn::toString(){
	return string("System.Data.DataColumn");
}

string DataColumn::getTypeString(){
	return string("DataColumn");
}

String DataColumn::ColumnName(){
	return this->name;
}

void DataColumn::ColumnName(String & columnName){
	String* str = new String(columnName);
	this->name = str;
}

String DataColumn::DataType(){
	//string str(this->type->name());
	stringstream ss;

	ss << this->type->name();

	return String(&ss.str());
}

/*template <typename T>
bool DataColumn::checkType(T type){
	//type_info ti1 = typeid(T);
	//type_info ti2 = *this->type;

	if(typeid(T) == this->type->hash_code()){
		return true;
	} else{
		return false;
	}

	return true;
}*/