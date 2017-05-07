#pragma once

#include "SqlConnection.h"
#include "MySqlCommand.h"
#include <my_global.h>
#include "mysql.h"

namespace dnc::Data::SqlClient{

	using namespace std;

	class MySqlConnection: public SqlConnection{

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
		MYSQL* connection;
	};
}
