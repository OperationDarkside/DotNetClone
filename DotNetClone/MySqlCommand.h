#include "SqlCommand.h"
#include "MySqlDataReader.h"

#pragma once
class MySqlCommand : public SqlCommand {

	friend class MySqlConnection;

public:
	MySqlCommand();
	MySqlCommand(String& cmdText);
	MySqlCommand(String& cmdText, MySqlConnection* connection);
	~MySqlCommand();

	string toString();
	string getTypeString();

	int ExecuteNonQuery();
	MySqlDataReader ExecuteReader();
	template <typename T>
	T ExecuteScalar();
};

template<typename T>
inline T MySqlCommand::ExecuteScalar(){
	return T();
}
