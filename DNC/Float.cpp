#include "Float.h"

namespace dnc{

	Float::Float(){}

	Float::Float(float f): value(f){}


	Float::~Float(){}

	string Float::toString(){
		return to_string(this->value);
	}

	string Float::getTypeString(){
		return string("Float");
	}

	Float Float::operator=(float f){
		return Float(f);
	}

	Float::operator float(){
		return this->value;
	}
}