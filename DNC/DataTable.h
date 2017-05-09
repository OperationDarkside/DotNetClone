#ifndef DATATABLE_H
#define DATATABLE_H

#include "Object.h"
#include "String.h"
#include "DataRowCollection.h"
#include "DataColumnCollection.h"

#pragma once

namespace dnc{
	namespace Data{

		/**
		In-Memory dynamic Table class
		*/
		class DataTable: public Object{

			friend class DataColumnCollection;

		public:
			// Constructors
			DataTable();
			DataTable(const char* name);
			DataTable(String& name);
			~DataTable();

			// Inherited
			std::string toString();
			std::string getTypeString();

			//Methods
			/**
			Creates a new DataRow with a link to the columns

			@return New DataRow
			*/
			DataRow NewRow();
			/**
			Removes all columns and rows
			*/
			void Clear();

			//Properties
			/**
			Returns the name of this table

			@return name
			*/
			String TableName();
			/**
			Sets the name of this DataTable instance

			@param name String with the name
			*/
			void TableName(String& name);
			/**
			Returns a reference to the columns of this instance

			@return columns
			*/
			DataColumnCollection& Columns();
			/**
			Returns a reference to the rows of this instance
			*/
			DataRowCollection& Rows();

			DataRow& operator[](unsigned int rowIndex);
		private:
			String name;
			DataColumnCollection columns;
			DataRowCollection rows;

			void RemoveColumn(size_t index);
		};
	}
}
#endif // !DATATABLE_H