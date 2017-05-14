#pragma once

#ifndef SQLCONNECTION_H
#define SQLCONNECTION_H

#include "String.h"

namespace dnc{
	namespace Data{
		namespace SqlClient{

			class SqlConnection: public Object{
			public:
				SqlConnection();
				SqlConnection(String& conString);
				~SqlConnection();

				std::string toString();
				std::string getTypeString();

				virtual void Close();
				String ConnectionString();
				void ConnectionString(String& conString);
				virtual void Open();

			private:
				String connectionString;
			};

		}
	}
}
#endif // !SQLCONNECTION_H