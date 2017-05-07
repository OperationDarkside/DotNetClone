#pragma once
#include "MySqlParameter.h"

namespace dnc::Data::SqlClient{

	class MySqlParameterCollection{
	public:
		MySqlParameterCollection();
		~MySqlParameterCollection();

		string toString();
		string getTypeString();

		friend class DataTable;

		/**
		Adds a MySqlParameter instance to this collection

		@param The MySqlParameter to be added
		*/
		void Add(MySqlParameter& parameter);
		/**
		Removes all MySqlParameters from this instance
		*/
		void Clear();
		/**
		Returns the amount of MySqlParameters in this collection

		@return The row count
		*/
		long Count();
		/**
		Returns the index of the given MySqlParameter instance in this collection
		*/
		int IndexOf(MySqlParameter& parameter);
		/**
		Inserts the given MySqlParameter at the given position
		*/
		void InsertAt(MySqlParameter& parameter, int pos);

		MySqlParameter& operator[](int columnNr);

	private:
		vector<MySqlParameter> paramters;
	};
}
