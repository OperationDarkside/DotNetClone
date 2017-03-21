#include "MySqlCommand.h"
#include "MySqlConnection.h"
#include "MySQL\include\cppconn\prepared_statement.h"



MySqlCommand::MySqlCommand(){}

MySqlCommand::MySqlCommand(String & cmdText){
	this->CommandText(cmdText);
}

MySqlCommand::MySqlCommand(String & cmdText, MySqlConnection * connection){
	this->CommandText(cmdText);
	this->Connection(connection);
}


MySqlCommand::~MySqlCommand(){}

string MySqlCommand::toString(){
	return string("System.Data.MySql.MySqlClient");
}

string MySqlCommand::getTypeString(){
	return string("MySqlClient");
}

int MySqlCommand::ExecuteNonQuery(){
	int rowsAffected = 0;
	String cmd;
	SqlConnection* con;
	MySqlConnection* myCon;

	cmd = this->CommandText();

	if(cmd == ""){
		throw "The command is empty";
	}

	con = this->Connection();

	if(con == nullptr){
		throw "Connection is null";
	}

	myCon = dynamic_cast<MySqlConnection*>(con);

	if(myCon->con->isClosed()){
		throw "Connection is closed";
	}

	sql::PreparedStatement* ps = myCon->con->prepareStatement(cmd.toCharArray());

	rowsAffected = ps->executeUpdate();

	return rowsAffected;
}

MySqlDataReader MySqlCommand::ExecuteReader(){
	String cmd;
	SqlConnection* con;
	MySqlConnection* myCon;

	cmd = this->CommandText();

	if(cmd == ""){
		throw "The command is empty";
	}

	con = this->Connection();

	if(con == nullptr){
		throw "Connection is null";
	}

	myCon = dynamic_cast<MySqlConnection*>(con);

	if(myCon->con->isClosed()){
		throw "Connection is closed";
	}

	sql::PreparedStatement* ps = myCon->con->prepareStatement(cmd.toCharArray());

	ResultSet* result = ps->executeQuery();
	ResultSetMetaData* meta = ps->getMetaData();

	MySqlDataReader res(result, meta);

	return res;
}
