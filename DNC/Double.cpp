#include "Double.h"

namespace dnc{

	Double::Double(){}

	Double::Double(double d): value(d){
	
	}

	Double::~Double(){}

	std::string Double::ToString(){
		return std::to_string(this->value);
	}

	std::string Double::GetTypeString(){
		return std::string("Double");
	}

	Double Double::operator=(double d){
		this->value = d;

		return *this;
	}

	Double::operator double(){
		return this->value;
	}

	void Double::FromString(std::string val) {
		std::string::size_type sz;

		try {
			this->value = std::stod(val, &sz);
		} catch(const std::invalid_argument& ia) {
			throw "Couldn't convert std::string to double";
		} catch(const std::out_of_range& oor) {
			throw "Out of range error";
		}

		// this->value = std::atof(val.data());
	}

}