#include "Serializable.h"

namespace dnc{

	Serializable::Serializable(){
	}

	Serializable::~Serializable(){}

	String dnc::Serializable::ToXml(){
		String res;
		size_t len;

		len = attributes.Count();

		res = "<" + this->name + ">\r\n";

		for(size_t i = 0; i < len; i++){
			SerializableAttribute t = attributes[i];

			String attrName = t.AttributeName();
			Object& val = t.Member();

			res += "\t<" + attrName + " type=\"" + val.GetTypeString() + "\" >";
			res += val.ToString();
			res += "</" + attrName + ">\r\n";
		}

		res += "</" + this->name + ">\r\n";

		return res;
	}

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