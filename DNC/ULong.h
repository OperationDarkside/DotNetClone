#pragma once
#include "String.h"

class ULong : public Object{
public:
	ULong();
	ULong(unsigned long ul);
	~ULong();

	string toString();
	string getTypeString();

	ULong operator=(unsigned long l);
	operator unsigned long();
private:
	unsigned long value;
};

