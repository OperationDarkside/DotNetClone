#include "Boolean.h"

namespace dnc{

	Boolean::Boolean(){}

	Boolean::Boolean(bool b): value(b){}

	Boolean::~Boolean(){}

	string Boolean::toString(){
		return to_string(this->value);
	}

	string Boolean::getTypeString(){
		return string("Boolean");
	}

	Boolean Boolean::operator=(bool b){
		return Boolean(b);
	}

	Boolean::operator bool(){
		return this->value;
	}
}