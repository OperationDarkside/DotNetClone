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
		this->value = s;

		return *this;
	}

	Short::operator short(){
		return this->value;
	}

	void Short::FromString(std::string val) {
		std::string::size_type sz;

		try {
			this->value = std::stoi(val, &sz);
		} catch(const std::invalid_argument& ia) {
			throw "Couldn't convert std::string to double";
		} catch(const std::out_of_range& oor) {
			throw "Out of range error";
		}
	}
}