#pragma once
#include "String.h"
#include "MySqlDataReader.h"
#include "MySqlCommand.h"

class MySqlDataAdapter: public Object{

public:
	MySqlDataAdapter();
	MySqlDataAdapter(MySqlCommand& command);
	~MySqlDataAdapter();

	long Fill(DataTable& table);
private:
	MySqlCommand cmd;
};