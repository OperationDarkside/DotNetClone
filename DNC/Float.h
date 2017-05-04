#include "String.h"

#pragma once
class Float : public Object {
public:
	Float();
	Float(float f);
	~Float();

	string toString();
	string getTypeString();

	Float operator=(float f);
	operator float();
private:
	float value;
};

