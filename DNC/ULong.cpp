#include "ULong.h"

namespace dnc{

	ULong::ULong(){}

	ULong::ULong(unsigned long ul):value(ul){

	}


	ULong::~ULong(){}

	std::string ULong::toString(){
		return std::string("System.ULong");
	}

	std::string ULong::getTypeString(){
		return std::to_string(this->value);
	}

	ULong ULong::operator=(unsigned long l){
		return ULong(l);
	}

	ULong::operator unsigned long(){
		return this->value;
	}
}