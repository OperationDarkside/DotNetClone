#include "DataRow.h"
#include "DataColumnCollection.h"

namespace dnc{
	namespace Data{

		DataRow::DataRow(){}

		DataRow::DataRow(const DataRow & row): cols(std::move(row.cols)), items(std::move(row.items)){
			int i = 0;
			i++;
		}

		DataRow::DataRow(DataRow && row) : cols(std::move(row.cols)), items(std::move(row.items)){
			row.cols = nullptr;
		}

		DataRow::DataRow(DataColumnCollection * columns) : cols(columns){
			long len = columns->Count();

			this->items = Collections::Generic::List<Object*>(len);
		}

		DataRow::~DataRow(){
			//this->Delete();
		}

		std::string DataRow::ToString(){
			return std::string("System.Data.DataRow");
		}

		std::string DataRow::GetTypeString(){
			return std::string("DataRow");
		}

		void DataRow::Delete(){
			size_t len = 0;

			len = this->items.Count();

			for(size_t i = 0; i < len; i++){
				delete this->items[i];
			}
		}

		void DataRow::SetField(int columnNr, bool value){
			Boolean* boo;

			if(columnNr >= this->cols->Count()){
				throw "Column Nr out of Range!";
				return;
			}

			DataColumn col = (*this->cols)[columnNr];
			if(!col.checkType(Type::getType<bool>(value))){
				throw "Type mismatch!";
				return;
			}

			boo = new Boolean(value);

			this->items[columnNr] = boo;
		}

		void DataRow::SetField(int columnNr, short value){
			Short* sh;

			if(columnNr >= this->cols->Count()){
				throw "Column Nr out of Range!";
				return;
			}

			DataColumn col = (*this->cols)[columnNr];
			if(!col.checkType(Type::getType<short>(value))){
				throw "Type mismatch!";
				return;
			}

			sh = new Short(value);

			this->items[columnNr] = sh;
		}

		void DataRow::SetField(int columnNr, int value){
			Integer* inte;

			if(columnNr >= this->cols->Count()){
				throw "Column Nr out of Range!";
				return;
			}

			DataColumn col = (*this->cols)[columnNr];
			if(!col.checkType(Type::getType<int>(value))){
				throw "Type mismatch!";
				return;
			}

			inte = new Integer(value);

			this->items[columnNr] = inte;
		}

		void DataRow::SetField(int columnNr, long value){
			Long* l;

			if(columnNr >= this->cols->Count()){
				throw "Column Nr out of Range!";
				return;
			}

			DataColumn col = (*this->cols)[columnNr];
			if(!col.checkType(Type::getType<long>(value))){
				throw "Type mismatch!";
				return;
			}

			l = new Long(value);

			this->items[columnNr] = l;
		}

		void DataRow::SetField(int columnNr, unsigned long value){
			ULong* l;

			if(columnNr >= this->cols->Count()){
				throw "Column Nr out of Range!";
				return;
			}

			DataColumn col = (*this->cols)[columnNr];
			if(!col.checkType(Type::getType<unsigned long>(value))){
				throw "Type mismatch!";
				return;
			}

			l = new ULong(value);

			this->items[columnNr] = l;
		}

		void DataRow::SetField(int columnNr, long long value){
			LongLong* l;

			if(columnNr >= this->cols->Count()){
				throw "Column Nr out of Range!";
				return;
			}

			DataColumn col = (*this->cols)[columnNr];
			if(!col.checkType(Type::getType<long long>(value))){
				throw "Type mismatch!";
				return;
			}

			l = new LongLong(value);

			this->items[columnNr] = l;
		}

		void DataRow::SetField(int columnNr, float value){
			Float* f;

			if(columnNr >= this->cols->Count()){
				throw "Column Nr out of Range!";
				return;
			}

			DataColumn col = (*this->cols)[columnNr];
			if(!col.checkType(Type::getType<float>(value))){
				throw "Type mismatch!";
				return;
			}

			f = new Float(value);

			this->items[columnNr] = f;
		}

		void DataRow::SetField(int columnNr, double value){
			Double* d;

			if(columnNr >= this->cols->Count()){
				throw "Column Nr out of Range!";
				return;
			}

			DataColumn col = (*this->cols)[columnNr];
			if(!col.checkType(Type::getType<double>(value))){
				throw "Type mismatch!";
				return;
			}

			d = new Double(value);

			this->items[columnNr] = d;
		}

		void DataRow::SetField(int columnNr, long double value){
			Decimal* d;

			if(columnNr >= this->cols->Count()){
				throw "Column Nr out of Range!";
				return;
			}

			DataColumn col = (*this->cols)[columnNr];
			if(!col.checkType(Type::getType<long double>(value))){
				throw "Type mismatch!";
				return;
			}

			d = new Decimal(value);

			this->items[columnNr] = d;
		}

		Object* DataRow::operator[](int columnNr){
			Object* o = items[columnNr];

			return o;
		}

		DataRow & DataRow::operator=(const DataRow & row){
			if(this != &row){
				this->cols = row.cols;
				this->items = row.items;
			}

			return *this;
		}

		DataRow & DataRow::operator=(DataRow && row) noexcept{
			this->cols = row.cols;
			row.cols = nullptr;
			return *this;
		}

		void DataRow::RemoveItem(size_t index){
			size_t len = 0;

			len = this->items.Count();

			if((len - 1) < index){
				throw "Remove item index out of range";
			}

			delete this->items[index];

			this->items.RemoveAt(index);
		}
	}
}