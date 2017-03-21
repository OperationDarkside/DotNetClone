#include "String.h"

#pragma once
using namespace std;

class SqlConnection : public Object{
public:
	SqlConnection();
	SqlConnection(String& conString);
	~SqlConnection();

	string toString();
	string getTypeString();

	virtual void Close();
	String ConnectionString();
	void ConnectionString(String& conString);
	virtual void Open();

private:
	String connectionString;
};

