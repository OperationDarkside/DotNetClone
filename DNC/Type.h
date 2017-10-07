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

		std::string ToString() override;
		std::string GetTypeString() override;

		/**
		Returns a Type class instance of the given class

		@param var variable of the seeked Type
		*/
		template <typename T>
		static Type getType(T var);

		/**
		Checks if a pointer is of a certain type. Usefull for polymorphic checks

		@param var variable of the type to be checked
		*/
		template <typename T1, typename T2>
		static bool isType(T1* var);

		bool operator==(Type& t);

	private:
		size_t code = 0;
		String name;
	};

	template<typename T>
	inline Type Type::getType(T var){
		const type_info& ti = typeid(var);

		size_t code = ti.hash_code();
		String n(std::string(ti.name()));

		return Type(code, n);
	}

	template<typename T1, typename T2>
	inline bool Type::isType(T1* var) {
		bool res = false;

		T2* tmp = dynamic_cast<T2*>(var);

		if(tmp != nullptr) {
			return true;
		} else {
			return false;
		}

		
	}
}
#endif // !TYPE_H