#include "Object.h"
#include "String.h"

#pragma once
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