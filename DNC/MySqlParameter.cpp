#include "MySqlParameter.h"

namespace dnc{
	namespace Data{
		namespace SqlClient{

			MySqlParameter::MySqlParameter(){}

			MySqlParameter::MySqlParameter(MySqlDbTypes _type){
				memset(&this->param, 0, sizeof(this->param));
				this->param.buffer_type = static_cast<enum_field_types>(_type);
			}

			MySqlParameter::MySqlParameter(MySqlDbTypes _type, char value): t(Type::getType<char>('a')){
				memset(&this->param, 0, sizeof(this->param));
				this->param.buffer_type = static_cast<enum_field_types>(_type);
				this->param.buffer = &value;
				unsigned long len = sizeof(value);
				this->param.length = &len;
			}

			MySqlParameter::MySqlParameter(MySqlDbTypes _type, short value): t(Type::getType<short>(1)){
				memset(&this->param, 0, sizeof(this->param));
				this->param.buffer_type = static_cast<enum_field_types>(_type);
				this->param.buffer = &value;
				unsigned long len = sizeof(value);
				this->param.length = &len;
			}

			MySqlParameter::MySqlParameter(MySqlDbTypes _type, int value): t(Type::getType<int>(1234)){
				memset(&this->param, 0, sizeof(this->param));
				this->param.buffer_type = static_cast<enum_field_types>(_type);
				this->param.buffer = &value;
				unsigned long len = sizeof(value);
				this->param.length = &len;
			}

			MySqlParameter::MySqlParameter(MySqlDbTypes _type, long value): t(Type::getType<long>(123456)){
				memset(&this->param, 0, sizeof(this->param));
				this->param.buffer_type = static_cast<enum_field_types>(_type);
				this->param.buffer = &value;
				unsigned long len = sizeof(value);
				this->param.length = &len;
			}

			MySqlParameter::MySqlParameter(MySqlDbTypes _type, long long value): t(Type::getType<long long>(123456789)){
				memset(&this->param, 0, sizeof(this->param));
				this->param.buffer_type = static_cast<enum_field_types>(_type);
				this->param.buffer = &value;
				unsigned long len = sizeof(value);
				this->param.length = &len;
			}

			MySqlParameter::MySqlParameter(MySqlDbTypes _type, float value): t(Type::getType<float>(123.5)){
				memset(&this->param, 0, sizeof(this->param));
				this->param.buffer_type = static_cast<enum_field_types>(_type);
				this->param.buffer = &value;
				unsigned long len = sizeof(value);
				this->param.length = &len;
			}

			MySqlParameter::MySqlParameter(MySqlDbTypes _type, double value): t(Type::getType<double>(12345.1234)){
				memset(&this->param, 0, sizeof(this->param));
				this->param.buffer_type = static_cast<enum_field_types>(_type);
				this->param.buffer = &value;
				unsigned long len = sizeof(value);
				this->param.length = &len;
			}

			MySqlParameter::MySqlParameter(MySqlDbTypes _type, String & value): t(Type::getType<String>(String())){
				memset(&this->param, 0, sizeof(this->param));
				this->param.buffer_type = static_cast<enum_field_types>(_type);
				char* val = value.toCharArray();
				this->param.buffer = val;
				unsigned long len = strlen(val);
				this->param.length = &len;
			}

			MySqlParameter::~MySqlParameter(){}

			std::string MySqlParameter::ToString(){
				return std::string("System.Data.MySqlClient.MySqlParameter");
			}

			std::string MySqlParameter::GetTypeString(){
				return std::string("MySqlParameter");
			}

			/*String & MySqlParameter::Name(){
				return this->name;
			}

			void MySqlParameter::Name(String & name){
				this->name = name;
			}*/

			template<typename T>
			T MySqlParameter::Value(){
				T val;

				if(Type::getType<T>(val) != t){
					throw "Type Mismatch";
				}

				val = *dynamic_cast<T*>(this->buffer);

				return val;
			}

			template<typename T>
			void MySqlParameter::Value(T value){
				T val;

				if(Type::getType<T>(val) != t){
					throw "Type Mismatch";
				}

				this->buffer = &value;
			}
		}
	}
}