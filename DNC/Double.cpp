#include "Double.h"

namespace dnc{

	Double::Double(){}

	Double::Double(double d): value(d){
	
	}

	Double::~Double(){}

	std::string Double::ToString(){
		return std::to_string(this->value);
	}

	std::string Double::GetTypeString(){
		return std::string("Double");
	}

	Double Double::operator=(double d){
		this->value = d;

		return *this;
	}

	Double::operator double(){
		return this->value;
	}

}