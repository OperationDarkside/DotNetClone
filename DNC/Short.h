#include "String.h"

#pragma once
class Short : public Object {
public:
	Short();
	Short(short s);
	~Short();

	string toString();
	string getTypeString();

	Short operator=(short s);
	operator short();

private:
	short value;
};

