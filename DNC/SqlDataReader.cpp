#include "SqlDataReader.h"

namespace dnc{
	namespace Data{
		namespace SqlClient{

			SqlDataReader::SqlDataReader(){

			}


			SqlDataReader::~SqlDataReader(){}
			std::string SqlDataReader::ToString(){
				return std::string("System.Data.SqlClient.SqlDataReader");
			}
			std::string SqlDataReader::GetTypeString(){
				return std::string("SqlDataReader");
			}
		}
	}
}