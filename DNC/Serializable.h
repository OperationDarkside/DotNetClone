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

	template<typename T>
	class Serializable : public Object {
	public:

		Serializable();
		virtual ~Serializable() = 0;

		String ToXml();

	protected:

		String name;
		dnc::Collections::Generic::List<SerializableAttribute> attributes;

		String ToXml(Collections::Generic::List<unsigned long long>& _childPtrs);
	};

	template<typename T>
	Serializable<T>::Serializable() {}

	template<typename T>
	Serializable<T>::~Serializable() {}

	template<typename T>
	String Serializable<T>::ToXml() {
		String res;
		size_t len;
		Collections::Generic::List<unsigned long long> childPtrs;

		len = attributes.Count();

		res = "<" + this->name+ " ID=\"" + this->getHashCode() + "\">\r\n";

		for(size_t i = 0; i < len; i++) {
			SerializableAttribute t = attributes[i];

			// Get Values
			String attrName = t.AttributeName();
			Object& val = t.Member();

			// Check Serializable
			Serializable* child;

			child = dynamic_cast<Serializable*>(&val);

			if(child == nullptr) {
				// Just serialize
				res += "\t<" + attrName + " type=\"" + val.GetTypeString() + "\">";
				res += val.ToString();
				res += "</" + attrName + ">\r\n";
			} else {
				// Step into
				childPtrs.Add(child->getHashCode());
				res += child->ToXml(childPtrs);
			}
		}

		res += "</" + this->name + ">\r\n";

		return res;
	}

	template<typename T>
	inline String Serializable<T>::ToXml(Collections::Generic::List<unsigned long long>& _childPtrs) {
		unsigned long long hash = 0;
		String res;
		size_t len;

		len = attributes.Count();

		res = "<" + this->name+ " ID=\"" + this->getHashCode() + "\">\r\n";

		for(size_t i = 0; i < len; i++) {
			SerializableAttribute t = attributes[i];

			// Get Values
			String attrName = t.AttributeName();
			Object& val = t.Member();

			// Check Serializable
			Serializable* child = dynamic_cast<Serializable*>(&val);

			if(child == nullptr) {
				// Just serialize
				res += "\t<" + attrName + " type=\"" + val.GetTypeString() + "\">";
				res += val.ToString();
				res += "</" + attrName + ">\r\n";
			} else {
				// Is Serializable
				hash = child->getHashCode();

				if(_childPtrs.Contains(hash)) {
					// Just add a reference
					res += "\t<" + attrName + " ref=\"" + hash + "\"/>\r\n";
				} else {
					// Call serialize
					_childPtrs.Add(hash);
					res += child->ToXml(_childPtrs);
				}
			}
		}

		res += "</" + this->name + ">\r\n";

		return res;
	}

}