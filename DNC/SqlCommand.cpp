#include "SqlCommand.h"

namespace dnc::Data::SqlClient{

	SqlCommand::SqlCommand(){}

	SqlCommand::SqlCommand(String & cmdText): cmdText(cmdText){

	}

	SqlCommand::SqlCommand(String & cmdText, SqlConnection * connection) : cmdText(cmdText), con(connection){

	}

	SqlCommand::~SqlCommand(){}


	string SqlCommand::ToString(){
		return string("System.Data.SqlClient.SqlCommand");
	}

	string SqlCommand::getTypeString(){
		return string("SqlCommand");
	}

	String SqlCommand::CommandText(){
		return this->cmdText;
	}

	void SqlCommand::CommandText(String & cmdText){
		this->cmdText = cmdText;
	}

	SqlConnection * SqlCommand::Connection(){
		return this->con;
	}

	void SqlCommand::Connection(SqlConnection * connection){
		this->con = connection;
	}

	int SqlCommand::ExecuteNonQuery(){
		throw "This is just an abstract class";
	}

	/*SqlDataReader SqlCommand::ExecuteReader(){
		throw "This is just an abstract class";
	}*/
}