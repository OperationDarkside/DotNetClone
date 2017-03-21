#include "Object.h"
#include "String.h"
#include "Boolean.h"
#include "Short.h"
#include "Integer.h"
#include "Long.h"
#include "Float.h"
#include "Double.h"
#include <typeinfo>

#pragma once
/**
Row Object to a DataTable
*/
class DataRow: public Object{

	friend class DataColumnCollection;
	friend class DataTable;

public:
	DataRow();
	DataRow(const DataRow& row);
	DataRow(DataRow&& row) noexcept;
	DataRow(DataColumnCollection* columns);
	~DataRow();

	string toString();
	string getTypeString();

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
	Returns the pointer to the value in the specified column

	 @param columnNr Index of the column
	 @return 
	*/
	Object* operator[](int columnNr);
	DataRow& operator=(const DataRow& row);
	DataRow& operator=(DataRow&& row) noexcept;
private:
	DataColumnCollection* cols;
	vector<Object*> items;

	/**
	Removes one item from the inventory

	@param index Position of the Cell to be deleted
	*/
	void RemoveItem(size_t index);
};

template<typename T>
inline T DataRow::Field(int columnNr){
	T* res;
	Object* o = items[columnNr];

	res = dynamic_cast<T*>(o);

	return *res;
}
template<>
inline bool DataRow::Field<bool>(int columnNr){
	Object* o = items[columnNr];

	bool b;
	Boolean* boo = dynamic_cast<Boolean*>(o);

	b = *boo;

	return b;
}
template<>
inline short DataRow::Field<short>(int columnNr){
	Object* o = items[columnNr];

	short s;
	Short* sh = dynamic_cast<Short*>(o);

	s = *sh;

	return s;
}
template<>
inline int DataRow::Field<int>(int columnNr){
	Object* o = items[columnNr];

	int i;
	Integer* inte = dynamic_cast<Integer*>(o);

	i = *inte;

	return i;
}
template<>
inline long DataRow::Field<long>(int columnNr){
	Object* o = items[columnNr];

	long l;
	Long* lo = dynamic_cast<Long*>(o);

	l = *lo;

	return l;
}
template<>
inline float DataRow::Field<float>(int columnNr){
	Object* o = items[columnNr];

	float f;
	Float* flo = dynamic_cast<Float*>(o);

	f = *flo;

	return f;
}
template<>
inline double DataRow::Field<double>(int columnNr){
	Object* o = items[columnNr];

	double d;
	Double* dob = dynamic_cast<Double*>(o);

	d = *dob;

	return d;
}

template<typename T>
inline void DataRow::SetField(int columnNr, T& value){
	T* o = new T(value);

	if(columnNr >= this->cols->Count()){
		throw "Column Nr out of Range!";
		return;
	}

	DataColumn col = (*this->cols)[columnNr];
	if(!col.checkType(Type::getType<T>(value))){
		throw "Type mismatch!";
		return;
	}

	this->items[columnNr] = o;
}