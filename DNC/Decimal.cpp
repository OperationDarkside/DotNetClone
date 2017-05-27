#include "Decimal.h"

namespace dnc{

	Decimal::Decimal(){}

	Decimal::Decimal(long double ld):value(ld){}


	Decimal::~Decimal(){}

	std::string Decimal::ToString(){
		return std::to_string(this->value);
	}

	std::string Decimal::GetTypeString(){
		return std::string("Decimal");
	}

	Decimal Decimal::operator=(long double ld){
		this->value = ld;
		return *this;
	}

	Decimal::operator long double(){
		return this->value;
	}

}