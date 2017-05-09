#include "Float.h"

namespace dnc{

	Float::Float(){}

	Float::Float(float f): value(f){}


	Float::~Float(){}

	std::string Float::toString(){
		return std::to_string(this->value);
	}

	std::string Float::getTypeString(){
		return std::string("Float");
	}

	Float Float::operator=(float f){
		return Float(f);
	}

	Float::operator float(){
		return this->value;
	}
}