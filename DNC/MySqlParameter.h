#pragma once
#include "String.h"
#include "Type.h"
#include "MySqlDbTypes.h"

namespace dnc{
	namespace Data{
		namespace SqlClient{

			class MySqlParameter{

				friend class MySqlParameterCollection;
				friend class MySqlCommand;

			public:
				MySqlParameter();
				MySqlParameter(MySqlDbTypes _type);
				MySqlParameter(MySqlDbTypes _type, char value);
				MySqlParameter(MySqlDbTypes _type, short value);
				MySqlParameter(MySqlDbTypes _type, int value);
				MySqlParameter(MySqlDbTypes _type, long value);
				MySqlParameter(MySqlDbTypes _type, long long value);
				MySqlParameter(MySqlDbTypes _type, float value);
				MySqlParameter(MySqlDbTypes _type, double value);
				MySqlParameter(MySqlDbTypes _type, String& value);
				~MySqlParameter();

				std::string toString();
				std::string getTypeString();

				template<typename T>
				T Value();
				template<typename T>
				void Value(T value);

				//String& Name();
				//void Name(String& name);

			private:
				//String name;
				//MySqlDbTypes dbType;
				Type t;
				MYSQL_BIND param;
				//void* buffer;
			};
		}
	}
}