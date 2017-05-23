#include "Object.h"

namespace dnc{

	Object::Object(){
		generateHashCode();
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

	void Object::generateHashCode(){
		hashCode = (int)this;
	}
}