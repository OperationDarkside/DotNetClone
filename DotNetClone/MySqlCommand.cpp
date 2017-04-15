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
	return string("System.Data.MySql.MySqlClient.MySqlCommand");
}

string MySqlCommand::getTypeString(){
	return string("MySqlCommand");
}

int MySqlCommand::ExecuteNonQuery(){
	int query_res = 0;
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

	query_res = mysql_query(myCon->connection, cmd.toCharArray());

	if(query_res){
		cerr << mysql_error(myCon->connection);
		mysql_close(myCon->connection);
		throw "Query failed!";
	}

	return mysql_affected_rows(myCon->connection);
}

MySqlDataReader MySqlCommand::ExecuteReader(){
	int query_res = 0;
	String cmd;
	SqlConnection* con;
	MySqlConnection* myCon;
	MYSQL_RES* resultset;

	cmd = this->CommandText();

	if(cmd == ""){
		throw "The command is empty";
	}

	con = this->Connection();

	if(con == nullptr){
		throw "Connection is null";
	}

	myCon = dynamic_cast<MySqlConnection*>(con);

	query_res = mysql_query(myCon->connection, cmd.toCharArray());

	if(query_res){
		cerr << mysql_error(myCon->connection);
		mysql_close(myCon->connection);
		throw "Query failed!";
	}

	resultset = mysql_store_result(myCon->connection);

	if(resultset == nullptr){
		cerr << mysql_error(myCon->connection);
		mysql_free_result(resultset);
		mysql_close(myCon->connection);
		throw "Could not store result!";
	}

	return MySqlDataReader(resultset);
}

MySqlParameterCollection & MySqlCommand::Parameters(){
	return this->parameters;
}

void MySqlCommand::Parameters(MySqlParameterCollection & parameters){
	this->parameters = parameters;
}
