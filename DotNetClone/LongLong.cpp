#include "LongLong.h"



LongLong::LongLong(){}

LongLong::LongLong(long long ll):value(ll){}


LongLong::~LongLong(){}

string LongLong::toString(){
	return string("System.LongLong");
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
