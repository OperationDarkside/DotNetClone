#include "LongLong.h"

namespace dnc{

	LongLong::LongLong(){}

	LongLong::LongLong(long long ll):value(ll){}


	LongLong::~LongLong(){}

	std::string LongLong::ToString(){
		return std::to_string(this->value);
	}

	std::string LongLong::GetTypeString(){
		return std::string("LongLong");
	}

	LongLong LongLong::operator=(long long ll){
		this->value = ll;

		return *this;
	}

	LongLong::operator long long(){
		return this->value;
	}

	void LongLong::FromString(std::string val) {
		std::string::size_type sz;

		try {
			this->value = std::stoll(val, &sz);
		} catch(const std::invalid_argument& ia) {
			throw "Couldn't convert std::string to double";
		} catch(const std::out_of_range& oor) {
			throw "Out of range error";
		}
	}
}