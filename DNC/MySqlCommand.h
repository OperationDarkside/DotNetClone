#include "SqlCommand.h"
#include "MySqlDataReader.h"
#include "MySqlParameterCollection.h"

#pragma once

namespace dnc::Data::SqlClient{

	class MySqlCommand: public SqlCommand{

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

		MySqlParameterCollection& Parameters();
		void Parameters(MySqlParameterCollection& parameters);

	private:
		MySqlParameterCollection parameters;

		MYSQL_BIND* bindParameters();
	};

	template<typename T>
	inline T MySqlCommand::ExecuteScalar(){
		String cmd;
		SqlConnection* con;
		MySqlConnection* myCon;
		T resTemplate;

		cmd = this->CommandText();

		if(cmd == ""){
			throw "The command is empty";
		}

		con = this->Connection();

		if(con == nullptr){
			throw "Connection is null";
		}

		myCon = dynamic_cast<MySqlConnection*>(con);

		if(!myCon->conn.connected()){
			throw "Connection is closed";
		}

		//resTemplate = ;

		return resTemplate;
	}
}