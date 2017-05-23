#include "DataRowCollection.h"

namespace dnc{
	namespace Data{

		DataRowCollection::DataRowCollection(){}

		DataRowCollection::~DataRowCollection(){}

		std::string DataRowCollection::ToString(){
			return std::string("System.Data.DataRowCollection");
		}

		std::string DataRowCollection::GetTypeString(){
			return std::string("DataRowCollection");
		}

		void DataRowCollection::Add(DataRow& row){
			this->rows.Add(row);
		}

		void DataRowCollection::Clear(){
			size_t len = 0;

			len = this->rows.Count();

			for(size_t i = 0; i < len; i++){
				this->rows[i].Delete();
			}

			this->rows.Clear();
		}

		long DataRowCollection::Count(){
			return this->rows.Count();
		}

		int DataRowCollection::IndexOf(DataRow & row){
			size_t len = 0;

			len = this->rows.Count();

			for(size_t i = 0; i < len; i++){
				if(&this->rows[i].items == &row.items){
					return i;
				}
			}

			return -1;
		}

		void DataRowCollection::InsertAt(DataRow & row, int pos){
			this->rows.Insert(pos, row);
		}

		void DataRowCollection::Remove(DataRow & row){
			size_t len = 0;

			len = this->rows.Count();

			for(size_t i = 0; i < len; i++){
				if(&this->rows[i].items == &row.items){
					this->rows.RemoveAt(i);
					return;
				}
			}

			throw "DataRow not found to remove";
		}

		void DataRowCollection::RemoveAt(unsigned long index){
			if(this->rows.Count() > index){
				this->rows.RemoveAt(index);
			} else{
				throw "Index of DataRow out of range";
			}
		}

		DataRow & DataRowCollection::operator[](unsigned int columnNr){
			return this->rows[columnNr];
		}
	}
}