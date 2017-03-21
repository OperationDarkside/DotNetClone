#pragma once

#include "SqlConnection.h"
#include "MySqlCommand.h"

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;
using namespace sql;

class MySqlConnection: public SqlConnection {

	friend class MySqlCommand;

public:
	MySqlConnection();
	MySqlConnection(String& conString);
	~MySqlConnection();

	string toString();
	string getTypeString();
	
	void Close();
	MySqlCommand CreateCommand();
	void Open();

private:
	Driver* driver = nullptr;
	Connection* con = nullptr;
};

