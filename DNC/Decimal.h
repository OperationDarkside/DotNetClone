#pragma once
#include "String.h"

class Decimal : public Object{
public:
	Decimal();
	Decimal(long double ld);
	~Decimal();

	string toString();
	string getTypeString();

	Decimal operator=(long double ld);
	operator long double();
private:
	long double value;
};

