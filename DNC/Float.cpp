#include "Float.h"

namespace dnc{

	Float::Float(){}

	Float::Float(float f): value(f){}


	Float::~Float(){}

	std::string Float::ToString(){
		return std::to_string(this->value);
	}

	std::string Float::GetTypeString(){
		return std::string("Float");
	}

	Float Float::operator=(float f){
		this->value = f;
		return *this;
	}

	Float::operator float(){
		return this->value;
	}

	void Float::FromString(std::string val) {
		std::string::size_type sz;

		try {
			this->value = std::stof(val, &sz);
		} catch(const std::invalid_argument& ia) {
			throw "Couldn't convert std::string to double";
		} catch(const std::out_of_range& oor) {
			throw "Out of range error";
		}
	}
}