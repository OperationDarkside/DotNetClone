#include "LongLong.h"

namespace dnc{

	LongLong::LongLong(){}

	LongLong::LongLong(long long ll):value(ll){}


	LongLong::~LongLong(){}

	string LongLong::toString(){
		return to_string(this->value);
	}

	string LongLong::getTypeString(){
		return string("LongLong");
	}

	LongLong LongLong::operator=(long long ll){
		return LongLong(ll);
	}

	LongLong::operator long long(){
		return this->value;
	}
}