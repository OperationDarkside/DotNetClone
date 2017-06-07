#include "MySqlParameterCollection.h"

namespace dnc{
	namespace Data{
		namespace SqlClient{

			MySqlParameterCollection::MySqlParameterCollection(){}


			MySqlParameterCollection::~MySqlParameterCollection(){}

			std::string MySqlParameterCollection::ToString(){
				return std::string("System.Data.MySqlClient.MySqlParameterCollection");
			}

			std::string MySqlParameterCollection::GetTypeString(){
				return std::string("MySqlParameterCollection");
			}

			void MySqlParameterCollection::Add(MySqlParameter & parameter){
				this->parameters.Add(parameter);
			}

			void MySqlParameterCollection::Clear(){
				this->parameters.Clear();
			}

			long MySqlParameterCollection::Count(){
				return this->parameters.Count();
			}

			int MySqlParameterCollection::IndexOf(MySqlParameter & parameter){
				return 0;
			}

			void MySqlParameterCollection::InsertAt(MySqlParameter & parameter, int pos){
				this->parameters.Insert(pos, parameter);
			}

			MySqlParameter & MySqlParameterCollection::operator[](int columnNr){
				return this->parameters[columnNr];
			}
		}
	}
}