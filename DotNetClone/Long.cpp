#include "Long.h"



Long::Long(){}

Long::Long(long l) : value(l) {}

Long::~Long(){}

string Long::toString(){
	return string("System.Long");
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
