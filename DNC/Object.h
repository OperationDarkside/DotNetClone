#pragma once

#ifndef OBJECT_H
#define OBJECT_H

#include <string>

namespace dnc{
	/**
	Represents the base class to all DNC Classes
	*/
	class Object{

		friend class Serializable;

	public:
		Object();
		virtual ~Object();

		/**
		Compares the pointer of Object o and this instance

		@param o Object pointer to compare
		@return If the pointers are the same
		*/
		virtual bool equals(Object* o);
		/**
		Returns a hashcode of this instance (integer representation of its pointer)

		@return The hashcode
		*/
		virtual unsigned long long getHashCode();
		/**
		Returns a c++ string pointer representation of this class name

		@return C++ string class name
		*/
		virtual std::string GetTypeString();
		/**
		Returns a c++ string pointer representation of this class. Should be implemented by every derivated class

		@return C++ string with information about this class/instance
		*/
		virtual std::string ToString();

		//Object& operator=(double d);
		//operator double();

	private:
		unsigned long long hashCode = 0;

		void generateHashCode();

		virtual void FromString(std::string val);
	};
}
#endif // !OBJECT_H