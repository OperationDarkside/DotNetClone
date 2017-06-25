#include "Long.h"

namespace dnc{

	Long::Long(){}

	Long::Long(long l): value(l){}

	Long::~Long(){}

	std::string Long::ToString(){
		return std::to_string(this->value);
	}

	std::string Long::GetTypeString(){
		return std::string("Long");
	}

	Long Long::operator=(long l){
		this->value = l;

		return *this;
	}

	Long::operator long(){
		return this->value;
	}

	void Long::FromString(std::string val) {
		std::string::size_type sz;

		try {
			this->value = std::stol(val, &sz);
		} catch(const std::invalid_argument& ia) {
			throw "Couldn't convert std::string to double";
		} catch(const std::out_of_range& oor) {
			throw "Out of range error";
		}
	}
}