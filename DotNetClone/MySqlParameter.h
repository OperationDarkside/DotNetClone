#pragma once
#include "String.h"

class MySqlParameter{

	friend class MySqlParameterCollection;
	friend class MySqlCommand;

public:
	MySqlParameter();
	MySqlParameter(String& parameterName, char value);
	MySqlParameter(String& parameterName, short value);
	MySqlParameter(String& parameterName, int value);
	MySqlParameter(String& parameterName, long value);
	MySqlParameter(String& parameterName, long long value);
	MySqlParameter(String& parameterName, float value);
	MySqlParameter(String& parameterName, double value);
	MySqlParameter(String& parameterName, String& value);
	~MySqlParameter();

	string toString();
	string getTypeString();

	String& Name();
	void Name(String& name);

private:
	String name;
};

