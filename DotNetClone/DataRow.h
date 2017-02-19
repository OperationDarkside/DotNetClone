#include "Object.h"
#include "String.h"
#include "Boolean.h"
#include "DataColumnCollection.h"
#include <typeinfo>

#pragma once
class DataRow : public Object
{
	friend class DataTable;

public:
	DataRow();
	DataRow(DataColumnCollection* columns);
	~DataRow();

	string toString();
	string getTypeString();


	// Field
	template <typename T>
	T Field(int columnNr);
	template <>
	bool Field(int columnNr);

	// SetField
	template<typename T>
	void SetField(int columnNr, T value);
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


template<typename T>
inline void DataRow::SetField(int columnNr, T value)
{
	T* o = new T(value);
	this->items[columnNr] = o;
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