#include "Decimal.h"

namespace dnc{

	Decimal::Decimal(){}

	Decimal::Decimal(long double ld):value(ld){}


	Decimal::~Decimal(){}

	string Decimal::toString(){
		return to_string(this->value);
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

}