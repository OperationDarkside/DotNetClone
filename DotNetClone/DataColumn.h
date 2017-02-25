#include "Object.h"
#include "String.h"
#include <typeinfo>

#pragma once
/**
Column Object for the DataTable class
*/
class DataColumn : public Object
{
public:
	DataColumn();
	DataColumn(const char* name, Object* o);
	DataColumn(String& name, Object* o);
	~DataColumn();

	string toString();
	string getTypeString();

	/**
	Returns the name of this column instance

	@return The column name
	*/
	String ColumnName();
	/**
	Sets the name of this column instance

	@param columnName The column name
	*/
	void ColumnName(String& columnName);

	/**
	Compares the DataType of this Column with the given Type

	@param var Variable of the Type to compare
	*/
	template <typename T>
	bool checkType(T val);

	String DataType();
private:
	String name;
	const type_info* type;
};

template<typename T>
inline bool DataColumn::checkType(T val){
	if(typeid(T).hash_code() == this->type->hash_code()){
		return true;
	} else{
		return false;
	}

	return true;
}
