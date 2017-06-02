#include "Serializable.h"

namespace dnc{

	SerializableAttribute::SerializableAttribute(String attrName, Object & member): name(attrName), member(member){}

	SerializableAttribute::~SerializableAttribute(){}

	String SerializableAttribute::AttributeName(){
		return this->name;
	}

	void SerializableAttribute::AttributeName(String name){
		this->name = name;
	}

	Object & SerializableAttribute::Member(){
		return this->member;
	}

	void SerializableAttribute::Member(Object & mem){
		this->member = mem;
	}
}