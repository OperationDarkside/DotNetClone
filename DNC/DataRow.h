#pragma once

#ifndef DATAROW_H
#define DATAROW_H

#include "String.h"
#include "Boolean.h"
#include "Short.h"
#include "Integer.h"
#include "Long.h"
#include "ULong.h"
#include "Float.h"
#include "Double.h"
#include "Decimal.h"
#include "LongLong.h"
#include <memory>

namespace dnc {
	namespace Data {

		/**
		Row Object to a DataTable
		*/
		class DataRow : public Object {

			friend class DataColumnCollection;
			friend class DataRowCollection;
			friend class DataTable;

		public:

			DataRow(const DataRow& row);
			DataRow(DataRow&& row);
			~DataRow();

			std::string ToString() override;
			std::string GetTypeString() override;

			/**
			Removes all values from this row
			*/
			void Delete();

			/**
			Returns the value of the cell in the given column

			@param columnNr Zero based column index
			@return Cell value of the given type (must be derived from Object)
			*/
			template <typename T>
			T Field(int columnNr);
			/**
			Returns the bool value of the cell in the given column (Wraps the Boolean class)

			@param columnNr Zero based column index
			@return bool cell value
			*/
			template <>
			bool Field<bool>(int columnNr);
			/**
			Returns the short value of the cell in the given column (Wraps the Short class)

			@param columnNr Zero based column index
			@return short cell value
			*/
			template <>
			short Field<short>(int columnNr);
			/**
			Returns the int value of the cell in the given column (Wraps the Integer class)

			@param columnNr Zero based column index
			@return int cell value
			*/
			template <>
			int Field<int>(int columnNr);
			/**
			Returns the long value of the cell in the given column (Wraps the Long class)

			@param columnNr Zero based column index
			@return long cell value
			*/
			template <>
			long Field<long>(int columnNr);
			/**
			Returns the unsigned long value of the cell in the given column (Wraps the ULong class)

			@param columnNr Zero based column index
			@return unsigned long cell value
			*/
			template <>
			unsigned long Field<unsigned long>(int columnNr);
			/**
			Returns the long long value of the cell in the given column (Wraps the LongLong class)

			@param columnNr Zero based column index
			@return long long cell value
			*/
			template <>
			long long Field<long long>(int columnNr);
			/**
			Returns the float value of the cell in the given column (Wraps the Float class)

			@param columnNr Zero based column index
			@return float cell value
			*/
			template <>
			float Field<float>(int columnNr);
			/**
			Returns the double value of the cell in the given column (Wraps the Double class)

			@param columnNr Zero based column index
			@return double cell value
			*/
			template <>
			double Field<double>(int columnNr);

			/**
			Sets the value of the cell in the given column

			@param columnNr Zero based column index
			@param value of the given type (must be derived from Object)
			*/
			template<typename T>
			void SetField(int columnNr, T& value);
			/**
			Sets the value of the cell in the given column (Wraps the Boolean class)

			@param columnNr Zero based column index
			@param bool value of the given type
			*/
			void SetField(int columnNr, bool value);
			/**
			Sets the value of the cell in the given column (Wraps the Short class)

			@param columnNr Zero based column index
			@param short value of the given type
			*/
			void SetField(int columnNr, short value);
			/**
			Sets the value of the cell in the given column (Wraps the Integer class)

			@param columnNr Zero based column index
			@param int value of the given type
			*/
			void SetField(int columnNr, int value);
			/**
			Sets the value of the cell in the given column (Wraps the Long class)

			@param columnNr Zero based column index
			@param long value of the given type
			*/
			void SetField(int columnNr, long value);
			/**
			Sets the value of the cell in the given column (Wraps the ULong class)

			@param columnNr Zero based column index
			@param unsigned long value of the given type
			*/
			void SetField(int columnNr, unsigned long value);
			/**
			Sets the value of the cell in the given column (Wraps the LongLong class)

			@param columnNr Zero based column index
			@param long long value of the given type
			*/
			void SetField(int columnNr, long long value);
			/**
			Sets the value of the cell in the given column (Wraps the Float class)

			@param columnNr Zero based column index
			@param float value of the given type
			*/
			void SetField(int columnNr, float value);
			/**
			Sets the value of the cell in the given column (Wraps the Double class)

			@param columnNr Zero based column index
			@param double value of the given type
			*/
			void SetField(int columnNr, double value);
			/**
			Sets the value of the cell in the given column (Wraps the Decimal class)

			@param columnNr Zero based column index
			@param long double value of the given type
			*/
			void SetField(int columnNr, long double value);

			/**
			Returns the pointer to the value in the specified column

			 @param columnNr Index of the column
			 @return
			*/
			Object* operator[](int columnNr);
			DataRow& operator=(const DataRow& row);
			DataRow& operator=(DataRow&& row) noexcept;
		private:
			DataColumnCollection* cols;
			Collections::Generic::List<std::shared_ptr<Object>> items;

			DataRow();
			DataRow(DataColumnCollection* columns);

			/**
			Removes one item from the inventory

			@param index Position of the Cell to be deleted
			*/
			void RemoveItem(size_t index);
		};

		template<typename T>
		inline T DataRow::Field(int columnNr) {
			T* res;
			Object* o = items[columnNr].get();

			res = dynamic_cast<T*>(o);

			if(res != nullptr) {
				return *res;
			} else {
				throw "Bad Conversion";
			}
		}

		template<>
		inline bool DataRow::Field<bool>(int columnNr) {
			Object* o = items[columnNr].get();

			bool b;
			Boolean* boo = dynamic_cast<Boolean*>(o);

			if(boo != nullptr) {
				b = *boo;
			} else {
				throw "Bad bool Conversion";
			}

			return b;
		}
		template<>
		inline short DataRow::Field<short>(int columnNr) {
			Object* o = items[columnNr].get();

			short s;
			Short* sh = dynamic_cast<Short*>(o);

			if(sh != nullptr) {
				s = *sh;
			} else {
				throw "Bad bool Conversion";
			}

			return s;
		}
		template<>
		inline int DataRow::Field<int>(int columnNr) {
			Object* o = items[columnNr].get();

			int i;
			Integer* inte = dynamic_cast<Integer*>(o);

			if(inte != nullptr) {
				i = *inte;
			} else {
				throw "Bad bool Conversion";
			}

			return i;
		}
		template<>
		inline long DataRow::Field<long>(int columnNr) {
			Object* o = items[columnNr].get();

			long l;
			Long* lo = dynamic_cast<Long*>(o);

			if(lo != nullptr) {
				l = *lo;
			} else {
				throw "Bad bool Conversion";
			}

			return l;
		}
		template<>
		inline unsigned long DataRow::Field<unsigned long>(int columnNr) {
			Object* o = items[columnNr].get();

			unsigned long l;
			ULong* ul = dynamic_cast<ULong*>(o);

			if(ul != nullptr) {
				l = *ul;
			} else {
				throw "Bad bool Conversion";
			}

			return l;
		}
		template<>
		inline long long DataRow::Field<long long>(int columnNr) {
			Object* o = items[columnNr].get();

			long long ll;
			LongLong* llo = dynamic_cast<LongLong*>(o);

			if(llo != nullptr) {
				ll = *llo;
			} else {
				throw "Bad bool Conversion";
			}

			return ll;
		}
		template<>
		inline float DataRow::Field<float>(int columnNr) {
			Object* o = items[columnNr].get();

			float f;
			Float* flo = dynamic_cast<Float*>(o);

			if(flo != nullptr) {
				f = *flo;
			} else {
				throw "Bad bool Conversion";
			}

			return f;
		}
		template<>
		inline double DataRow::Field<double>(int columnNr) {
			Object* o = items[columnNr].get();

			double d;
			Double* dob = dynamic_cast<Double*>(o);

			if(dob != nullptr) {
				d = *dob;
			} else {
				throw "Bad bool Conversion";
			}

			return d;
		}
		template<>
		inline long double DataRow::Field<long double>(int columnNr) {
			Object* o = items[columnNr].get();

			double d;
			Decimal* dob = dynamic_cast<Decimal*>(o);

			if(dob != nullptr) {
				d = *dob;
			} else {
				throw "Bad bool Conversion";
			}

			return d;
		}

		template<typename T>
		inline void DataRow::SetField(int columnNr, T& value) {
			static_assert(std::is_base_of<Object, T>::value, "T is not an Object");

			if(columnNr >= this->cols->Count()) {
				throw "Column Nr out of Range!";
				return;
			}

			DataColumn col = (*this->cols)[columnNr];
			if(!col.checkType(Type::getType<T>(value))) {
				throw "Type mismatch!";
				return;
			}

			this->items[columnNr].reset(new T(value));
		}
	}
}
#endif