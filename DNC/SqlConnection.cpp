#include "SqlConnection.h"



SqlConnection::SqlConnection(){

}

SqlConnection::SqlConnection(String & conString): connectionString(conString){

}

SqlConnection::~SqlConnection(){}



string SqlConnection::toString(){
	return string("System.Data.SqlClient.SqlConnection");
}

string SqlConnection::getTypeString(){
	return string("SqlConnection");
}



void SqlConnection::Close(){
	throw "This class ist just an abstract class";
}

String SqlConnection::ConnectionString(){
	return this->connectionString;
}

void SqlConnection::ConnectionString(String & conString){
	this->connectionString = conString;
}

void SqlConnection::Open(){
	throw "This class ist just an abstract class";
}
