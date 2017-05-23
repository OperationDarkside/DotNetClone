#pragma once

#ifndef DATACOLCOLLECTION_H
#define DATACOLCOLLECTION_H

#include "DataColumn.h"

namespace dnc{
	namespace Data{

		class DataTable;

		#pragma once
		/**
		Stores the columns of a DataTable instance
		*/
		class DataColumnCollection: public Object{
		public:
			DataColumnCollection();
			~DataColumnCollection();

			std::string ToString() override;
			std::string GetTypeString() override;

			friend class DataTable;

			/**
			Adds a DataColumn instance to this collection

			@param The DataColumn instance to be added
			*/
			void Add(DataColumn& column);
			/**
			Removes all columns from this instance
			*/
			void Clear();
			/**
			Returns the amount of columns in this collection

			@return The column number
			*/
			long Count();
			/**
			Returns the position of the given column in this collection

			@return The column number
			*/
			int IndexOf(DataColumn& column);
			/**
			Removes the column from all rows

			@param column The column to remove
			*/
			void Remove(DataColumn* column);
			/**
			Removes the column with the given name from all rows

			@param name of the colum to remove
			*/
			void Remove(String& name);
			/**
			Returns the DataTable instance associated with this DataColumnCollection instance
			*/
			DataTable* Table();
			/**
			Sets the DataTable instance to associate with this DataColumnCollection instance
			*/
			void Table(DataTable* _table);

			DataColumn& operator[](int colNr);
		private:
			DataTable* table;
			Collections::Generic::List<DataColumn> cols;
		};
	}
}
#endif // !DATACOLCOLLECTION_H