#include "String.h"

#pragma once

using namespace std;

class SqlDataReader : public Object {

	friend class SqlCommand;

public:
	SqlDataReader();
	~SqlDataReader();
};

