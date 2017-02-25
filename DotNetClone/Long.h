#include "String.h"

#pragma once
class Long : public Object{
public:
	Long();
	Long(long l);
	~Long();

	string toString();
	string getTypeString();

	Long operator=(long l);
	operator long();
private:
	long value;
};

