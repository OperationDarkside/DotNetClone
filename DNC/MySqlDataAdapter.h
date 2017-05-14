#pragma once

#ifndef MYSQLDATAADAPTER_H
#define MYSQLDATAADAPTER_H

#include "String.h"
#include "MySqlDataReader.h"
#include "MySqlCommand.h"

namespace dnc{
	namespace Data{
		namespace SqlClient{

			class MySqlDataAdapter: public Object{

			public:
				MySqlDataAdapter();
				MySqlDataAdapter(MySqlCommand& command);
				MySqlDataAdapter(String& selectCommandText, MySqlConnection* connection);
				MySqlDataAdapter(String& selectCommandText, String& connectionString);
				~MySqlDataAdapter();

				std::string toString();
				std::string getTypeString();

				long Fill(DataTable& table);
			private:
				MySqlCommand cmd;
			};
		}
	}
}
#endif // !MYSQLDATAADAPTER_H