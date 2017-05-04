#include "Object.h"
#include "String.h"

#pragma once
/**
Object related wrapper for primitive bool type
*/
class Boolean : public Object
{
public:
	Boolean();
	Boolean(bool b);
	~Boolean();

	string toString();
	string getTypeString();

	Boolean operator=(bool b);
	operator bool();
private:
	bool value;
};