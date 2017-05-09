#pragma once

#ifndef TYPE_H
#define TYPE_H

#include "Object.h"
#include "String.h"
#include <typeinfo>

namespace dnc{

	/**
	Stores the type of a class/primitive Type
	*/
	class Type: public Object{
	public:
		Type();
		Type(size_t hashcode, String& name);
		~Type();

		std::string ToString();
		std::string getTypeString();

		/**
		Returns a Type class instance of the given class

		@param var variable of the seeked Type
		*/
		template <typename T>
		static Type getType(T var);

		bool operator==(Type& t);

	private:
		size_t code = 0;
		String* name;
	};

	template<typename T>
	inline Type Type::getType(T var){
		const type_info& ti = typeid(var);

		size_t code = ti.hash_code();
		String* n = new String(&std::string(ti.name()));

		return Type(code, *n);
	}
}
#endif // !TYPE_H