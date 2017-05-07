#include "ULong.h"

namespace dnc{

	ULong::ULong(){}

	ULong::ULong(unsigned long ul):value(ul){

	}


	ULong::~ULong(){}

	string ULong::toString(){
		return string("System.ULong");
	}

	string ULong::getTypeString(){
		return to_string(this->value);
	}

	ULong ULong::operator=(unsigned long l){
		return ULong(l);
	}

	ULong::operator unsigned long(){
		return this->value;
	}
}