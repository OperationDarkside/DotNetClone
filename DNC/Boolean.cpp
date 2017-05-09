#include "Boolean.h"

namespace dnc{

	Boolean::Boolean(){}

	Boolean::Boolean(bool b): value(b){}

	Boolean::~Boolean(){}

	std::string Boolean::toString(){
		return std::to_string(this->value);
	}

	std::string Boolean::getTypeString(){
		return std::string("Boolean");
	}

	Boolean Boolean::operator=(bool b){
		return Boolean(b);
	}

	Boolean::operator bool(){
		return this->value;
	}
}