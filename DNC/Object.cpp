#include "Object.h"
#include "Double.h"

namespace dnc{

	Object::Object(){
		generateHashCode();
	}

	Object::Object(double d){
		
	}

	Object::~Object(){}

	bool Object::equals(Object * o){
		return o == this;
	}

	int Object::getHashCode(){
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
		hashCode = (int)this;
	}
}