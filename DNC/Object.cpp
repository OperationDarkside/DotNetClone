#include "Object.h"
#include "Double.h"

namespace dnc{

	Object::Object(){
		generateHashCode();
	}

	Object::~Object(){}

	bool Object::equals(Object * o){
		return o == this;
	}

	unsigned long long Object::getHashCode(){
		return hashCode;
	}

	std::string Object::GetTypeString(){
		return std::string("Object");
	}

	std::string Object::ToString(){
		return std::string("System.Object");
	}

	/*Object& Object::operator=(double d){
		return Double(d);
	}

	Object::operator double(){}*/

	void Object::generateHashCode(){
		hashCode = (unsigned long long)this;
	}
	void Object::FromString(std::string val) {
		
	}
}