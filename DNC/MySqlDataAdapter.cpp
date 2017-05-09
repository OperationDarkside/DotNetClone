#include "MySqlDataAdapter.h"
#include "MySqlConnection.h"

namespace dnc{
	namespace Data{
		namespace SqlClient{

			MySqlDataAdapter::MySqlDataAdapter(){}

			MySqlDataAdapter::MySqlDataAdapter(MySqlCommand & command):cmd(command){

			}

			MySqlDataAdapter::MySqlDataAdapter(String & selectCommandText, MySqlConnection * connection){
				this->cmd = MySqlCommand(selectCommandText, connection);
			}

			MySqlDataAdapter::MySqlDataAdapter(String & selectCommandText, String & connectionString){
				MySqlConnection con(connectionString);

				this->cmd = MySqlCommand(selectCommandText, &con);
			}

			MySqlDataAdapter::~MySqlDataAdapter(){}

			std::string MySqlDataAdapter::toString(){
				return std::string("System.Data.MySql.MySqlClient.MySqlDataAdapter");
			}

			std::string MySqlDataAdapter::getTypeString(){
				return std::string("MySqlDataAdapter");
			}

			long MySqlDataAdapter::Fill(DataTable& table){
				long res = 0;

				MySqlDataReader reader = this->cmd.ExecuteReader();;

				reader.FillTable(table);

				return table.Rows().Count();
			}
		}
	}
}