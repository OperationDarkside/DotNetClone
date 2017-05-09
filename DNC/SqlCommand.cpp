#include "SqlCommand.h"

namespace dnc{
	namespace Data{
		namespace SqlClient{

			SqlCommand::SqlCommand(){}

			SqlCommand::SqlCommand(String & cmdText): cmdText(cmdText){

			}

			SqlCommand::SqlCommand(String & cmdText, SqlConnection * connection) : cmdText(cmdText), con(connection){

			}

			SqlCommand::~SqlCommand(){}


			std::string SqlCommand::ToString(){
				return std::string("System.Data.SqlClient.SqlCommand");
			}

			std::string SqlCommand::getTypeString(){
				return std::string("SqlCommand");
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
	}
}