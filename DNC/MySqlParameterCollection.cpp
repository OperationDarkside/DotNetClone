#include "MySqlParameterCollection.h"

namespace dnc{
	namespace Data{
		namespace SqlClient{

			MySqlParameterCollection::MySqlParameterCollection(){}


			MySqlParameterCollection::~MySqlParameterCollection(){}

			std::string MySqlParameterCollection::toString(){
				return std::string("System.Data.MySqlClient.MySqlParameterCollection");
			}

			std::string MySqlParameterCollection::getTypeString(){
				return std::string("MySqlParameterCollection");
			}

			void MySqlParameterCollection::Add(MySqlParameter & parameter){
				this->paramters.Add(parameter);
			}

			void MySqlParameterCollection::Clear(){
				this->paramters.Clear();
			}

			long MySqlParameterCollection::Count(){
				return this->paramters.Count();
			}

			int MySqlParameterCollection::IndexOf(MySqlParameter & parameter){
				return 0;
			}

			void MySqlParameterCollection::InsertAt(MySqlParameter & parameter, int pos){
				this->paramters.Insert(pos, parameter);
			}

			MySqlParameter & MySqlParameterCollection::operator[](int columnNr){
				return this->paramters[columnNr];
			}
		}
	}
}