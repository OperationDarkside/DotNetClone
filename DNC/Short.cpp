#include "Short.h"

namespace dnc{

	Short::Short(){}

	Short::Short(short s): value(s){}

	Short::~Short(){}

	string Short::toString(){
		return string("System.Short");
	}

	string Short::getTypeString(){
		return to_string(this->value);
	}

	Short Short::operator=(short s){
		return Short(s);
	}

	Short::operator short(){
		return this->value;
	}
}