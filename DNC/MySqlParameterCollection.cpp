#include "MySqlParameterCollection.h"



MySqlParameterCollection::MySqlParameterCollection(){}


MySqlParameterCollection::~MySqlParameterCollection(){}

string MySqlParameterCollection::toString(){
	return string("System.Data.MySql.MySqlClient.MySqlParameterCollection");
}

string MySqlParameterCollection::getTypeString(){
	return string("MySqlParameterCollection");
}

void MySqlParameterCollection::Add(MySqlParameter & parameter){
	this->paramters.push_back(parameter);
}

void MySqlParameterCollection::Clear(){
	this->paramters.clear();
}

long MySqlParameterCollection::Count(){
	return this->paramters.size();
}

int MySqlParameterCollection::IndexOf(MySqlParameter & parameter){
	return 0;
}

void MySqlParameterCollection::InsertAt(MySqlParameter & parameter, int pos){
	this->paramters.insert(this->paramters.begin() + pos, parameter);
}

MySqlParameter & MySqlParameterCollection::operator[](int columnNr){
	return this->paramters[columnNr];
}
