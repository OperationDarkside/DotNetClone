#include "Decimal.h"



Decimal::Decimal(){}

Decimal::Decimal(long double ld):value(ld){}


Decimal::~Decimal(){}

string Decimal::toString(){
	return string("System.Decimal");
}

string Decimal::getTypeString(){
	return string("Decimal");
}

Decimal Decimal::operator=(long double ld){
	return Decimal(ld);
}

Decimal::operator long double(){
	return this->value;
}
