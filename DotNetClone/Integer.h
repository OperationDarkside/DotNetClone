#include "String.h"

#pragma once
class Integer : public Object {
public:
	Integer();
	Integer(int i);
	~Integer();

	string toString();
	string getTypeString();

	Integer operator=(int i);
	operator int();
private:
	int value;
};

