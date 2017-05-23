#include "SqlConnection.h"

namespace dnc{
	namespace Data{
		namespace SqlClient{

			SqlConnection::SqlConnection(){

			}

			SqlConnection::SqlConnection(String & conString): connectionString(conString){

			}

			SqlConnection::~SqlConnection(){}



			std::string SqlConnection::ToString(){
				return std::string("System.Data.SqlClient.SqlConnection");
			}

			std::string SqlConnection::GetTypeString(){
				return std::string("SqlConnection");
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
		}
	}
}