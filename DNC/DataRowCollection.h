#include "DataRow.h"

#pragma once
namespace dnc::Data {

	/**
	Stores the rows of a DataTable instance
	*/
	class DataRowCollection: public Object{
	public:
		DataRowCollection();
		~DataRowCollection();

		string toString();
		string getTypeString();

		friend class DataTable;

		/**
		Adds a DataRow instance to this collection

		@param The DataRow to be added
		*/
		void Add(DataRow& row);
		/**
		Removes all rows from this instance
		*/
		void Clear();
		/**
		Returns the amount of rows in this collection

		@return The row count
		*/
		long Count();
		/**
		Returns the index of the given DataRow instance in this table
		*/
		int IndexOf(DataRow& row);
		/**
		Inserts the given row at the given position
		*/
		void InsertAt(DataRow& row, int pos);
		/*
		Removes the DataRow from this collection
		*/
		void Remove(DataRow& row);
		/*
		Removes the DataRow from this collection
		*/
		void RemoveAt(unsigned long index);

		DataRow& operator[](unsigned int columnNr);

	private:
		vector<DataRow> rows;
	};
}