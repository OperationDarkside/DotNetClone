#include "MySqlParameter.h"

namespace dnc {
	namespace Data {
		namespace SqlClient {

			MySqlParameter::MySqlParameter() {}

			/*MySqlParameter::MySqlParameter(const MySqlParameter & copy) :param(copy.param), t(copy.t) {

			}*/

			//MySqlParameter::MySqlParameter(MySqlParameter && move) : param(std::move(move.param)), t(std::move(move.t)) {}

			MySqlParameter::MySqlParameter(MySqlDbTypes _type) {
				memset(&this->param, 0, sizeof(this->param));
				this->param.buffer_type = static_cast<enum_field_types>(_type);
			}

			MySqlParameter::MySqlParameter(MySqlDbTypes _type, char value) : t(Type::getType<char>('a')) {
				memset(&this->param, 0, sizeof(this->param));
				this->param.buffer_type = static_cast<enum_field_types>(_type);
				this->param.buffer = &value;
				unsigned long len = sizeof(value);
				this->param.length = &len;
			}

			MySqlParameter::MySqlParameter(MySqlDbTypes _type, short value) : t(Type::getType<short>(1)) {
				memset(&this->param, 0, sizeof(this->param));
				this->param.buffer_type = static_cast<enum_field_types>(_type);
				this->param.buffer = &value;
				unsigned long len = sizeof(value);
				this->param.length = &len;
			}

			MySqlParameter::MySqlParameter(MySqlDbTypes _type, int value) : t(Type::getType<int>(1234)) {
				memset(&this->param, 0, sizeof(this->param));
				this->param.buffer_type = static_cast<enum_field_types>(_type);
				this->param.buffer = &value;
				unsigned long len = sizeof(value);
				this->param.length = &len;
			}

			MySqlParameter::MySqlParameter(MySqlDbTypes _type, long value) : t(Type::getType<long>(123456)) {
				memset(&this->param, 0, sizeof(this->param));
				this->param.buffer_type = static_cast<enum_field_types>(_type);
				this->param.buffer = &value;
				unsigned long len = sizeof(value);
				this->param.length = &len;
			}

			MySqlParameter::MySqlParameter(MySqlDbTypes _type, long long value) : t(Type::getType<long long>(123456789)) {
				memset(&this->param, 0, sizeof(this->param));
				this->param.buffer_type = static_cast<enum_field_types>(_type);
				this->param.buffer = &value;
				unsigned long len = sizeof(value);
				this->param.length = &len;
			}

			MySqlParameter::MySqlParameter(MySqlDbTypes _type, float value) : t(Type::getType<float>(123.5)) {
				memset(&this->param, 0, sizeof(this->param));
				this->param.buffer_type = static_cast<enum_field_types>(_type);
				this->param.buffer = &value;
				unsigned long len = sizeof(value);
				this->param.length = &len;
			}

			MySqlParameter::MySqlParameter(MySqlDbTypes _type, double value) : t(Type::getType<double>(12345.1234)) {
				memset(&this->param, 0, sizeof(this->param));
				this->param.buffer_type = static_cast<enum_field_types>(_type);
				this->param.buffer = &value;
				unsigned long len = sizeof(value);
				this->param.length = &len;
			}

			MySqlParameter::MySqlParameter(MySqlDbTypes _type, String & value) : t(Type::getType<String>(String())) {
				memset(&this->param, 0, sizeof(this->param));
				this->param.buffer_type = static_cast<enum_field_types>(_type);
				char* val = value.ToCharArray();
				this->param.buffer = val;
				unsigned long len = strlen(val);
				this->param.length = &len;
			}

			MySqlParameter::~MySqlParameter() {}

			std::string MySqlParameter::ToString() {
				return std::string("System.Data.MySqlClient.MySqlParameter");
			}

			std::string MySqlParameter::GetTypeString() {
				return std::string("MySqlParameter");
			}

			MySqlParameter & MySqlParameter::operator=(const MySqlParameter & copy) {
				this->param = copy.param;
				this->t = Type(copy.t);

				return *this;
			}

			/*MySqlParameter & MySqlParameter::operator=(MySqlParameter & copy) {
				this->param = copy.param;
				this->t = copy.t;

				return *this;
			}

			MySqlParameter & MySqlParameter::operator=(MySqlParameter && move) {
				if(this != &move) {// prevent self-move
					this->param = std::move(move.param);
					this->t = std::move(move.t);
				}

				return *this;
			}*/

			/*String & MySqlParameter::Name(){
				return this->name;
			}

			void MySqlParameter::Name(String & name){
				this->name = name;
			}*/

			template<typename T>
			T MySqlParameter::Value() {
				T val;

				if(Type::getType<T>(val) != this->t) {
					throw "Type Mismatch";
				}

				val = *dynamic_cast<T*>(this->param.buffer);

				return val;
			}

			template<typename T>
			void MySqlParameter::Value(T value) {
				if(Type::getType<T>(value) != this->t) {
					throw "Type Mismatch";
				}

				unsigned long len = sizeof(value);
				this->param.length = &len;
				this->param.buffer = &value;
			}
		}
	}
}