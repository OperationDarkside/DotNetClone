#include "MySqlCommand.h"
#include "MySqlConnection.h"

namespace dnc{
	namespace Data{
		namespace SqlClient{

			MySqlCommand::MySqlCommand(){}

			MySqlCommand::MySqlCommand(String & cmdText){
				this->CommandText(cmdText);
			}

			MySqlCommand::MySqlCommand(String & cmdText, MySqlConnection * connection){
				this->CommandText(cmdText);
				this->Connection(connection);
			}

			MySqlCommand::~MySqlCommand(){}

			std::string MySqlCommand::toString(){
				return std::string("System.Data.MySqlClient.MySqlCommand");
			}

			std::string MySqlCommand::getTypeString(){
				return std::string("MySqlCommand");
			}

			int MySqlCommand::ExecuteNonQuery(){
				int query_res = 0;
				char* cmdP;
				String cmd;
				SqlConnection* con;
				MySqlConnection* myCon;

				cmd = this->CommandText();

				if(cmd == ""){
					throw "The command is empty";
				}

				con = this->Connection();

				if(con == nullptr){
					throw "Connection is null";
				}

				myCon = dynamic_cast<MySqlConnection*>(con);

				if(this->parameters.Count() > 0){
					query_res = mysql_query(myCon->connection, cmd.toCharArray());

					if(query_res){
						std::cerr << mysql_error(myCon->connection);
						mysql_close(myCon->connection);
						throw "Query failed!";
					}

					return mysql_affected_rows(myCon->connection);
				} else{
					MYSQL_STMT* stmt;
					// INIT
					stmt = mysql_stmt_init(myCon->connection);

					// Prepare
					cmdP = cmd.toCharArray();
					mysql_stmt_prepare(stmt, cmdP, strlen(cmdP));
					mysql_stmt_bind_param(stmt, this->bindParameters());
					if(mysql_stmt_execute(stmt)){
						return mysql_stmt_affected_rows(stmt);
					} else{
						throw "Query with parameters failed";
					}
				}
			}

			MySqlDataReader MySqlCommand::ExecuteReader(){
				int query_res = 0;
				char* cmdP;
				String cmd;
				SqlConnection* con;
				MySqlConnection* myCon;
				MYSQL_RES* resultset;

				cmd = this->CommandText();

				if(cmd == ""){
					throw "The command is empty";
				}

				con = this->Connection();

				if(con == nullptr){
					throw "Connection is null";
				}

				myCon = dynamic_cast<MySqlConnection*>(con);

				/*if(this->parameters.Count() > 0){
					query_res = mysql_query(myCon->connection, cmd.toCharArray());

					if(query_res){
						cerr << mysql_error(myCon->connection);
						mysql_close(myCon->connection);
						throw "Query failed!";
					}

					resultset = mysql_store_result(myCon->connection);

					if(resultset == nullptr){
						cerr << mysql_error(myCon->connection);
						mysql_free_result(resultset);
						mysql_close(myCon->connection);
						throw "Could not store result!";
					}
				} else{*/
				MYSQL_STMT* stmt;
				// INIT
				stmt = mysql_stmt_init(myCon->connection);

				// Prepare
				cmdP = cmd.toCharArray();
				mysql_stmt_prepare(stmt, cmdP, strlen(cmdP));

				// Param count
				int param_count = mysql_stmt_param_count(stmt);
				std::cout << param_count << std::endl;

				// Parameters
				if(this->parameters.Count() > 0){
					if(mysql_stmt_bind_param(stmt, this->bindParameters())){
						std::cout << mysql_stmt_error(stmt) << std::endl;
						throw "Couldn't bind parameters";
					}
				}

				// Prepare Result
				MYSQL_RES* prepRes = mysql_stmt_result_metadata(stmt);

				// Columns in result
				int colCount = mysql_num_fields(prepRes);

				//Execute
				//mysql_stmt_attr_set(stmt, enum_stmt_attr_type::STMT_ATTR_UPDATE_MAX_LENGTH, (void*)int(1));
				int ex_res = mysql_stmt_execute(stmt);
				if(!ex_res){
					/*if(mysql_stmt_store_result(stmt)){
						cout << mysql_stmt_error(stmt) << endl;
						throw "Couldn't store result";
					}*/
					resultset = mysql_stmt_result_metadata(stmt);
				} else{
					std::cout << mysql_stmt_error(stmt) << std::endl;
					throw "Query with parameters failed";
				}
				//}

				return MySqlDataReader(stmt, resultset);
			}

			MySqlParameterCollection & MySqlCommand::Parameters(){
				return this->parameters;
			}

			void MySqlCommand::Parameters(MySqlParameterCollection & parameters){
				this->parameters = parameters;
			}

			MYSQL_BIND * MySqlCommand::bindParameters(){
				unsigned long paramLen = 0;
				MYSQL_BIND* params;

				paramLen = this->parameters.Count();

				params = new MYSQL_BIND[paramLen];

				for(size_t i = 0; i < paramLen; ++i){
					MySqlParameter param = this->parameters[i];

					params[i] = param.param;
				}

				return params;
			}
		}
	}
}