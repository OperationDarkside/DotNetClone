#include "DataColumnCollection.h"
#include "DataTable.h"

namespace dnc{
	namespace Data{

		DataColumnCollection::DataColumnCollection(){}

		DataColumnCollection::~DataColumnCollection(){}

		std::string DataColumnCollection::toString(){
			return std::string("System.Data.DataColumnCollection");
		}

		std::string DataColumnCollection::getTypeString(){
			return std::string("DataColumnCollection");
		}

		void DataColumnCollection::Add(DataColumn& column){
			size_t len = 0;
			len = this->cols.Count();

			for(size_t i = 0; i < len; i++){
				if(this->cols[i].ColumnName() == column.ColumnName()){
					throw "Column already exists!";
					return;
				}
			}

			this->cols.Add(column);
		}

		void DataColumnCollection::Clear(){
			this->cols.Clear();
		}

		long DataColumnCollection::Count(){
			return this->cols.Count();
		}

		int DataColumnCollection::IndexOf(DataColumn & column){
			size_t len = 0;
			len = this->cols.Count();

			for(size_t i = 0; i < len; i++){
				if(this->cols[i].ColumnName() == column.ColumnName()){
					return i;
				}
			}

			return -1;
		}

		void DataColumnCollection::Remove(DataColumn * column){
			size_t len_col = 0;
			DataColumn* col2comp;

			if(column == nullptr){
				throw "Column is null";
				return;
			}

			len_col = this->cols.Count();
			for(size_t i = 0; i < len_col; i++){
				col2comp = &this->cols[i];

				if(col2comp->ColumnName() == column->ColumnName()){
					this->cols.RemoveAt(i);

					this->table->RemoveColumn(i);
					return;
				}
			}
		}

		void DataColumnCollection::Remove(String & name){
			size_t len_col = 0;
			DataColumn* col2comp;

			len_col = this->cols.Count();
			for(size_t i = 0; i < len_col; i++){
				col2comp = &this->cols[i];

				if(col2comp->ColumnName() == name){
					this->cols.RemoveAt(i);

					this->table->RemoveColumn(i);
					return;
				}
			}
		}

		DataTable * DataColumnCollection::Table(){
			return this->table;
		}

		void DataColumnCollection::Table(DataTable * _table){
			this->table = _table;
		}

		DataColumn & DataColumnCollection::operator[](int colNr){
			return cols[colNr];
		}
	}
}