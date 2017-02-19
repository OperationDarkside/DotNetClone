#include "Object.h"
#include "String.h"
#include "Boolean.h"
#include "DataColumnCollection.h"
#include <typeinfo>

#pragma once
/**
Row Object to a DataTable
*/
class DataRow : public Object
{
	friend class DataTable;

public:
	DataRow();
	DataRow(DataColumnCollection* columns);
	~DataRow();

	string toString();
	string getTypeString();


	/**
	Returns the value of the cell in the given column

	@param columnNr Zero based column index
	@return Cell value of the given type
	*/
	template <typename T>
	T Field(int columnNr);
	/**
	Returns the bool value of the cell in the given column

	@param columnNr Zero based column index
	@return bool cell value
	*/
	template <>
	bool Field(int columnNr);

	/**
	Sets the value of the cell in the given column

	@param columnNr Zero based column index
	@param value of the given type
	*/
	template<typename T>
	void SetField(int columnNr, T& value);
	/**
	Sets the value of the cell in the given column

	@param columnNr Zero based column index
	@param bool value of the given type
	*/
	void SetField(int columnNr, bool value);

private:
	DataColumnCollection* cols;
	vector<Object*> items;
};

template<typename T>
inline T DataRow::Field(int columnNr)
{
	T* res;
	Object* o = items[columnNr];

	res = dynamic_cast<T*>(o);

	return *res;
}
template<>
inline bool DataRow::Field<bool>(int columnNr)
{
	Object* o = items[columnNr];

	bool b;
	Boolean* boo = dynamic_cast<Boolean*>(o);

	b = *boo;

	return b;
}

template<typename T>
inline void DataRow::SetField(int columnNr, T& value)
{
	T* o = new T(value);
	
	this->items[columnNr] = o;
}