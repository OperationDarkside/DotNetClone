#include "Integer.h"

namespace dnc{

	Integer::Integer(){}

	Integer::Integer(int i): value(i){}

	Integer::Integer(Object & o){
		Integer& in_ref = (Integer&)o;

		this->value = in_ref.value;
	}


	Integer::~Integer(){}

	std::string Integer::ToString(){
		return std::to_string(this->value);
	}

	std::string Integer::GetTypeString(){
		return std::string("Integer");
	}

	Integer Integer::operator=(int i){
		this->value = i;

		return *this;
	}

	Integer::operator int(){
		return this->value;
	}

	void Integer::FromString(std::string val) {
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