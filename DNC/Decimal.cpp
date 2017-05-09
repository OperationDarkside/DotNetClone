#include "Decimal.h"

namespace dnc{

	Decimal::Decimal(){}

	Decimal::Decimal(long double ld):value(ld){}


	Decimal::~Decimal(){}

	std::string Decimal::toString(){
		return std::to_string(this->value);
	}

	std::string Decimal::getTypeString(){
		return std::string("Decimal");
	}

	Decimal Decimal::operator=(long double ld){
		return Decimal(ld);
	}

	Decimal::operator long double(){
		return this->value;
	}

}