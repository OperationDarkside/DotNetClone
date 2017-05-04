#include "Object.h"



Object::Object()
{
	generateHashCode();
}


Object::~Object()
{
}

bool Object::equals(Object * o)
{
	return o == this;
}

int Object::getHashCode()
{
	return hashCode;
}

std::string Object::getTypeString()
{
	return std::string("Object");
}

std::string Object::toString()
{
	return std::string("System.Object");
}

void Object::generateHashCode()
{
	hashCode = (int)this;
}
