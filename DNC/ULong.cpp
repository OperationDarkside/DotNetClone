#include "ULong.h"

namespace dnc{

	ULong::ULong(){}

	ULong::ULong(unsigned long ul):value(ul){

	}


	ULong::~ULong(){}

	std::string ULong::ToString(){
		return std::string("System.ULong");
	}

	std::string ULong::GetTypeString(){
		return std::to_string(this->value);
	}

	ULong ULong::operator=(unsigned long l){
		this->value = l;

		return *this;
	}

	ULong::operator unsigned long(){
		return this->value;
	}

	void ULong::FromString(std::string val) {
		std::string::size_type sz;

		try {
			this->value = std::stoul(val, &sz);
		} catch(const std::invalid_argument& ia) {
			throw "Couldn't convert std::string to double";
		} catch(const std::out_of_range& oor) {
			throw "Out of range error";
		}
	}
}