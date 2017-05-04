#include "Double.h"



Double::Double(){}

Double::Double(double d) : value(d) {}

Double::~Double(){}

string Double::toString(){
	return string("System.Double");
}

string Double::getTypeString(){
	return string("Double");
}

Double Double::operator=(double d){
	return Double(d);
}

Double::operator double(){
	return this->value;
}
