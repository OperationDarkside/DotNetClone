#pragma once
#include "String.h"
#include "MySqlDataReader.h"
#include "MySqlCommand.h"

class MySqlDataAdapter: public Object{

public:
	MySqlDataAdapter();
	MySqlDataAdapter(MySqlCommand& command);
	MySqlDataAdapter(String& selectCommandText, MySqlConnection* connection);
	MySqlDataAdapter(String& selectCommandText, String& connectionString);
	~MySqlDataAdapter();

	long Fill(DataTable& table);
private:
	MySqlCommand cmd;
};