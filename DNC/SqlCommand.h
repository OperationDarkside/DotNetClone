#include "String.h"
#include "SqlConnection.h"
#include "SqlDataReader.h"

#pragma once
namespace dnc{
	namespace Data{
		namespace SqlClient{



			class SqlCommand: public Object{
			public:
				SqlCommand();
				SqlCommand(String& cmdText);
				SqlCommand(String& cmdText, SqlConnection* connection);
				~SqlCommand();

				std::string ToString();
				std::string getTypeString();

				String CommandText();
				void CommandText(String& cmdText);
				SqlConnection* Connection();
				void Connection(SqlConnection* connection);
				virtual int ExecuteNonQuery();
				//virtual SqlDataReader ExecuteReader();
				template <typename T>
				T ExecuteScalar();
			private:
				String cmdText;
				SqlConnection* con;
			};

			template<typename T>
			inline T SqlCommand::ExecuteScalar(){
				throw "This is just an abstract class";
			}
		}
	}
}