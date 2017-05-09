#include "LongLong.h"

namespace dnc{

	LongLong::LongLong(){}

	LongLong::LongLong(long long ll):value(ll){}


	LongLong::~LongLong(){}

	std::string LongLong::toString(){
		return std::to_string(this->value);
	}

	std::string LongLong::getTypeString(){
		return std::string("LongLong");
	}

	LongLong LongLong::operator=(long long ll){
		return LongLong(ll);
	}

	LongLong::operator long long(){
		return this->value;
	}
}