#include "String.h"

#pragma once
class Double : public Object {
public:
	Double();
	Double(double d);
	~Double();

	string toString();
	string getTypeString();

	Double operator=(double d);
	operator double();
private:
	double value;
};

