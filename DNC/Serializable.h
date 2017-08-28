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

		std::string ToString() override;
		std::string GetTypeString() override;

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

		std::string ToString() override;
		std::string GetTypeString() override;
		//String ToXml();
		//void FromXml(String& xmlString);

		String& Name();
		SerializableAttribute& Attribute(int index);
		SerializableAttribute& Attribute(const std::string& name);
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