#include "DataColumn.h"

namespace dnc{
	namespace Data{

		DataColumn::DataColumn(){}

		DataColumn::DataColumn(const char * name, Type& type){
			this->name = String(&std::string(name));
			this->type = type;
		}

		DataColumn::DataColumn(String & name, Type& type){
			this->name = name;
			this->type = type;
		}

		DataColumn::~DataColumn(){}

		std::string DataColumn::toString(){
			return std::string("System.Data.DataColumn");
		}

		std::string DataColumn::getTypeString(){
			return std::string("DataColumn");
		}

		bool DataColumn::checkType(Type& type){
			return this->type == type;
		}

		String DataColumn::ColumnName(){
			return this->name;
		}

		void DataColumn::ColumnName(const char * columnName){
			String* str = new String(&std::string(columnName));
			this->name = str;
		}

		void DataColumn::ColumnName(String & columnName){
			String* str = new String(columnName);
			this->name = str;
		}

		Type DataColumn::DataType(){

			return this->type;
		}

		void DataColumn::DataType(Type & type){
			this->type = type;
		}
	}
}