#pragma once
#include "String.h"

class LongLong : public Object{
public:
	LongLong();
	LongLong(long long ll);
	~LongLong();

	string toString();
	string getTypeString();

	LongLong operator=(long long ll);
	operator long long();
private:
	long long value;
};

