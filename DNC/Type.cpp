#include "Type.h"

namespace dnc{

	Type::Type(){}

	Type::Type(size_t hashcode, String& name): code(hashcode), name(new String(name)){}

	Type::~Type(){}

	std::string Type::ToString(){
		return this->name->GetStringValue();
	}

	std::string Type::GetTypeString(){
		return std::string("Type");
	}

	bool Type::operator==(Type& t){
		return this->code == t.code;
	}
}