#include "MySqlParameter.h"



MySqlParameter::MySqlParameter(){}

MySqlParameter::MySqlParameter(String& parameterName, char value): name(parameterName){
	// this->adapt = value;
}

MySqlParameter::MySqlParameter(String & parameterName, short value) : name(parameterName){
	// this->adapt = value;
}

MySqlParameter::MySqlParameter(String & parameterName, int value) : name(parameterName){
	// this->adapt = value;
}

MySqlParameter::MySqlParameter(String & parameterName, long value) : name(parameterName){
	// this->adapt = value;
}

MySqlParameter::MySqlParameter(String & parameterName, long long value) : name(parameterName){
	// this->adapt = value;
}

MySqlParameter::MySqlParameter(String & parameterName, float value) : name(parameterName){
	// this->adapt = value;
}

MySqlParameter::MySqlParameter(String & parameterName, double value) : name(parameterName){
	// this->adapt = value;
}

MySqlParameter::MySqlParameter(String & parameterName, String & value){
	// this->adapt = mysqlpp::SQLTypeAdapter(value.getStringValue());
}

MySqlParameter::~MySqlParameter(){}

string MySqlParameter::toString(){
	return string("System.Data.MySqlClient.MySqlParameter");
}

string MySqlParameter::getTypeString(){
	return string("MySqlParameter");
}

String & MySqlParameter::Name(){
	return this->name;
}

void MySqlParameter::Name(String & name){
	this->name = name;
}
