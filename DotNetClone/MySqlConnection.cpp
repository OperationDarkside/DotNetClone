#include "MySqlConnection.h"



MySqlConnection::MySqlConnection(){
	this->driver = get_driver_instance();
}

MySqlConnection::MySqlConnection(String & conString){
	this->ConnectionString(conString);
	this->driver = get_driver_instance();
}

MySqlConnection::~MySqlConnection(){
	delete this->con;
}

string MySqlConnection::toString(){
	return string("System.Data.MySqlClient.MySqlConnection");
}

string MySqlConnection::getTypeString(){
	return string("MySqlConnection");
}

void MySqlConnection::Close(){
	if(this->con == nullptr){
		throw "Driver is null";
	}

	this->con->close();
}

MySqlCommand MySqlConnection::CreateCommand(){
	return MySqlCommand(String(), this);
}

void MySqlConnection::Open(){
	SQLString host;
	SQLString uname;
	SQLString pw;
	SQLString db;
	String conStr;
	vector<String*> conKeyValues;

	conStr = this->ConnectionString();

	if(conStr == ""){
		throw "Connection string is empty";
	}

	conKeyValues = conStr.split(';');

	if(conKeyValues.size() != 4){
		throw "Not enough parameter in the connection string";
	}

	host = conKeyValues[0]->substring(7).toCharArray();
	db = conKeyValues[1]->substring(9).toCharArray();
	uname = conKeyValues[2]->substring(4).toCharArray();
	pw = conKeyValues[3]->substring(9).toCharArray();

	this->con = this->driver->connect(host, uname, pw);
	this->con->setSchema(db);
}
