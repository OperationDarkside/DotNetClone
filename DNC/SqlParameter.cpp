#include "SqlParameter.h"

namespace dnc{
	namespace Data{
		namespace SqlClient{

			SqlParameter::SqlParameter(){}


			SqlParameter::~SqlParameter(){}
			std::string SqlParameter::ToString(){
				return std::string("System.Data.SqlClient.SqlParameter");
			}
			std::string SqlParameter::GetTypeString(){
				return std::string("SqlParameter");
			}
		}
	}
}