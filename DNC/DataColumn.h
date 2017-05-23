#pragma once

#ifndef DATACOLUM_H
#define DATACOLUM_H

#include "Object.h"
#include "String.h"
#include "Type.h"

namespace dnc{
	namespace Data{

		/**
		Column Object for the DataTable class
		*/
		class DataColumn: public Object{
		public:
			DataColumn();
			//DataColumn(DataColumn& value);
			DataColumn(const char* name, Type& type);
			DataColumn(String& name, Type& o);
			~DataColumn();

			std::string ToString() override;
			std::string GetTypeString() override;

			/**
			Returns the name of this column instance

			@return The column name
			*/
			String ColumnName();
			/**
			Sets the name of this column instance

			@param columnName The column name
			*/
			void ColumnName(const char* columnName);
			/**
			Sets the name of this column instance

			@param columnName The column name
			*/
			void ColumnName(String& columnName);

			/**
			Compares the DataType of this Column with the given Type

			@param var Variable of the Type to compare
			*/
			bool checkType(Type& type);

			/**
			Returns the data type of this column instance

			@return The column's data type
			*/
			Type DataType();
			/**
			Sets the data type of this column instance

			@param type The column's data type
			*/
			void DataType(Type& type);
		private:
			String name;
			Type type;
		};
	}
}
#endif // !DATACOLUM_H