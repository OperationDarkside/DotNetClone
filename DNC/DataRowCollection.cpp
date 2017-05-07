#include "DataRowCollection.h"

namespace dnc::Data{

	DataRowCollection::DataRowCollection(){}

	DataRowCollection::~DataRowCollection(){}

	string DataRowCollection::toString(){
		return string("System.Data.DataRowCollection");
	}

	string DataRowCollection::getTypeString(){
		return string("DataRowCollection");
	}

	void DataRowCollection::Add(DataRow& row){
		this->rows.push_back(row);
	}

	void DataRowCollection::Clear(){
		size_t len = 0;

		len = this->rows.size();

		for(size_t i = 0; i < len; i++){
			this->rows[i].Delete();
		}

		this->rows.clear();
	}

	long DataRowCollection::Count(){
		return this->rows.size();
	}

	int DataRowCollection::IndexOf(DataRow & row){
		size_t len = 0;

		len = this->rows.size();

		for(size_t i = 0; i < len; i++){
			if(&this->rows[i].items == &row.items){
				return i;
			}
		}

		return -1;
	}

	void DataRowCollection::InsertAt(DataRow & row, int pos){
		this->rows.insert(this->rows.begin() + pos, row);
	}

	void DataRowCollection::Remove(DataRow & row){
		size_t len = 0;

		len = this->rows.size();

		for(size_t i = 0; i < len; i++){
			if(&this->rows[i].items == &row.items){
				this->rows.erase(this->rows.begin() + i);
				return;
			}
		}

		throw "DataRow not found to remove";
	}

	void DataRowCollection::RemoveAt(unsigned long index){
		if(this->rows.size() > index){
			this->rows.erase(this->rows.begin() + index);
		} else{
			throw "Index of DataRow out of range";
		}
	}

	DataRow & DataRowCollection::operator[](unsigned int columnNr){
		return this->rows[columnNr];
	}
}