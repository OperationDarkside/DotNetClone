#include "Integer.h"

namespace dnc{

	Integer::Integer(){}

	Integer::Integer(int i): value(i){}


	Integer::~Integer(){}

	std::string Integer::toString(){
		return std::to_string(this->value);
	}

	std::string Integer::getTypeString(){
		return std::string("Integer");
	}

	Integer Integer::operator=(int i){
		return Integer(i);
	}

	Integer::operator int(){
		return this->value;
	}
}