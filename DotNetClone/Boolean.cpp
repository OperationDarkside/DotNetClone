#include "Boolean.h"


Boolean::Boolean()
{
}

Boolean::Boolean(bool b) : value(b)
{
}

Boolean::~Boolean()
{
}

string Boolean::toString()
{
	return string("System.Boolean");
}

string Boolean::getTypeString()
{
	return string("Boolean");
}

Boolean Boolean::operator=(bool b)
{
	return Boolean(b);
}

Boolean::operator bool()
{
	return this->value;
}
