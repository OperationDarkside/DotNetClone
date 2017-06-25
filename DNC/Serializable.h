#pragma once
#include "String.h"
#include "List.h"
#include <functional>

namespace dnc {

	class SerializableAttribute : public Object {
	public:
		SerializableAttribute(String attrName, Object& member);
		~SerializableAttribute();

		String AttributeName();
		void AttributeName(String name);

		Object& Member();
		void Member(Object& mem);

	private:

		String name;
		Object& member;

	};

	class Serializable : public Object {
	public:

		Serializable();
		virtual ~Serializable() = 0;

		String ToXml();
		void FromXml(String& xmlString);



	protected:

		String name;
		dnc::Collections::Generic::List<SerializableAttribute> attributes;

		void SetProperty(std::string& propName, std::string& propValue);
		String ToXml(Collections::Generic::List<unsigned long long>& _childPtrs);

	private:
		void FromString(std::string val) override;
	};

}