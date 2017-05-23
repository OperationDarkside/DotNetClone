#include "Short.h"

namespace dnc{

	Short::Short(){}

	Short::Short(short s): value(s){}

	Short::~Short(){}

	std::string Short::ToString(){
		return std::string(std::to_string(this->value));
	}

	std::string Short::GetTypeString(){
		return std::string("Short");
	}

	Short Short::operator=(short s){
		return Short(s);
	}

	Short::operator short(){
		return this->value;
	}
}