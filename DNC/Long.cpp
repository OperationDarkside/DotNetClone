#include "Long.h"

namespace dnc{

	Long::Long(){}

	Long::Long(long l): value(l){}

	Long::~Long(){}

	string Long::toString(){
		return to_string(this->value);
	}

	string Long::getTypeString(){
		return string("Long");
	}

	Long Long::operator=(long l){
		return Long(l);
	}

	Long::operator long(){
		return this->value;
	}
}