#pragma once

#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include "String.h"
#include "List.h"
#include <functional>

namespace dnc {

	class SerializableAttribute : public Object {
	public:
		SerializableAttribute(const SerializableAttribute& obj);
		SerializableAttribute(String attrName, Object& member);
		~SerializableAttribute();

		String AttributeName();
		void AttributeName(String name);

		Object& Member();
		void Member(Object& mem);

		SerializableAttribute& operator=(SerializableAttribute& obj);

	private:

		String name;
		Object& member;

	};

	class Serializable : public Object {
	public:

		Serializable();
		virtual ~Serializable() = 0;

		//String ToXml();
		//void FromXml(String& xmlString);

		String& Name();
		SerializableAttribute& Attribute(int index);
		size_t AttrLen();

		void SetProperty(std::string& propName, std::string& propValue);

	protected:
		friend class XmlSerializer;

		String name;
		dnc::Collections::Generic::List<SerializableAttribute> attributes;

		//String ToXml(Collections::Generic::List<unsigned long long>& _childPtrs);

	private:
		//void FromString(std::string val) override;
	};

}
#endif