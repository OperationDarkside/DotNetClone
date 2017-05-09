#include "Long.h"

namespace dnc{

	Long::Long(){}

	Long::Long(long l): value(l){}

	Long::~Long(){}

	std::string Long::toString(){
		return std::to_string(this->value);
	}

	std::string Long::getTypeString(){
		return std::string("Long");
	}

	Long Long::operator=(long l){
		return Long(l);
	}

	Long::operator long(){
		return this->value;
	}
}