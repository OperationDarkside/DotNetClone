#pragma once

#ifndef MYSQLCONNECTION_H
#define MYSQLCONNECTION_H

#include "SqlConnection.h"
#include "MySqlCommand.h"
#include <my_global.h>
#include "mysql.h"

namespace dnc{
	namespace Data{
		namespace SqlClient{



			class MySqlConnection: public SqlConnection{

				friend class MySqlCommand;

			public:
				MySqlConnection();
				MySqlConnection(String& conString);
				~MySqlConnection();

				std::string toString();
				std::string getTypeString();

				void Close();
				MySqlCommand CreateCommand();
				void Open();

			private:
				MYSQL* connection;
			};
		}
	}
}
#endif // !MYSQLCONNECTION_H