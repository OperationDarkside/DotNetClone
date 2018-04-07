#include "SerializationObject.h"



SerializationObject::SerializationObject()
{
}


SerializationObject::~SerializationObject()
{
}

std::unordered_map<std::string, std::string>& SerializationObject::getValues() {
	return values;
}

std::unordered_map<std::string, SerializationObject>& SerializationObject::getSubObjects() {
	return subObjects;
}

std::unordered_map<std::string, std::vector<SerializationObject>>& SerializationObject::getArrays () {
	return arrays;
}
