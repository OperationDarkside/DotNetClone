#include "Double.h"

namespace dnc{

	Double::Double(){}

	Double::Double(double d): value(d){}

	Double::~Double(){}

	std::string Double::toString(){
		return std::to_string(this->value);
	}

	std::string Double::getTypeString(){
		return std::string("Double");
	}

	Double Double::operator=(double d){
		return Double(d);
	}

	Double::operator double(){
		return this->value;
	}
}