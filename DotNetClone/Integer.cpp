#include "Integer.h"



Integer::Integer(){}

Integer::Integer(int i) : value(i){}


Integer::~Integer(){}

string Integer::toString(){
	return string("System.Integer");
}

string Integer::getTypeString(){
	return string("Integer");
}

Integer Integer::operator=(int i){
	return Integer(i);
}

Integer::operator int(){
	return this->value;
}
