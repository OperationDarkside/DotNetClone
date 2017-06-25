#include "Boolean.h"

namespace dnc {

	Boolean::Boolean() {}

	Boolean::Boolean(bool b) : value(b) {}

	Boolean::~Boolean() {}

	std::string Boolean::ToString() {
		return std::to_string(this->value);
	}

	std::string Boolean::GetTypeString() {
		return std::string("Boolean");
	}

	Boolean Boolean::operator=(bool b) {
		this->value = b;

		return *this;
	}

	Boolean::operator bool() {
		return this->value;
	}

	void Boolean::FromString(std::string val) {
		if(val == "true") {
			this->value = true;
		} else if(val == "false") {
			this->value = false;
		}else {
			throw "No valid value";
		}
	}
}