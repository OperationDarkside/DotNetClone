#include "Serializable.h"

namespace dnc {

	SerializableAttribute::SerializableAttribute(String attrName, Object & member) : name(attrName), member(member) {}

	SerializableAttribute::~SerializableAttribute() {}

	String SerializableAttribute::AttributeName() {
		return this->name;
	}

	void SerializableAttribute::AttributeName(String name) {
		this->name = name;
	}

	Object & SerializableAttribute::Member() {
		return this->member;
	}

	void SerializableAttribute::Member(Object & mem) {
		this->member = mem;
	}

	Serializable::Serializable() {}

	Serializable::~Serializable() {}

	String Serializable::ToXml() {
		String res;
		size_t len;
		Collections::Generic::List<unsigned long long> childPtrs;

		len = attributes.Count();

		res = "<" + this->name+ " ID=\"" + this->getHashCode() + "\">";

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
				res += "<" + attrName + " type=\"" + val.GetTypeString() + "\">";
				res += val.ToString();
				res += "</" + attrName + ">";
			} else {
				// Step into
				childPtrs.Add(child->getHashCode());
				res += child->ToXml(childPtrs);
			}
		}

		res += "</" + this->name + ">";

		return res;
	}

	void Serializable::FromXml(String & xmlString) {
		bool isTag = false;
		bool isClosingTag = false;
		unsigned short depth = 0;
		size_t len = xmlString.length();
		std::string tag;
		std::string tag_name = "";
		std::string val = "";


		for(size_t i = 0; i < len; ++i) {
			char c = xmlString[i];

			if(c == '<') {

				char c2 = xmlString[i + 1];
				if(c2 == '/' && tag_name != "") {
					// Closing Tag
					isClosingTag = true;
					if(depth < 3) {
						SetProperty(tag_name, val);

						tag_name = "";
						val = "";

						isTag = true;
						continue;
					}
				} else {
					// Opening Tag
					++depth;
				}

				/*if(i != 0 && tag_name != "") {

				}*/
				if(depth < 3) {
					isTag = true;
					continue;
				}
			} else if(xmlString[i] == '>') {
				


				// Standalone tag
				if(xmlString[i - 1] == '/') {
					--depth;
					if(depth < 2) {
						tag_name = "";
						val = "";
						continue;
					}
				}

				if(isClosingTag) {
					isClosingTag = false;
					--depth;

					if(depth < 2) {
						
						tag = "";
						continue;
					}
				}

				if(depth < 3 && isTag) {
					isTag = false;
					tag_name = tag.substr(0, tag.find(' ', 0));

					tag = "";
					continue;
				}
			}

			if(isTag) {
				tag += xmlString[i];
			} else {
				val += xmlString[i];
			}

		}
	}

	void Serializable::SetProperty(std::string& propName, std::string& propValue) {
		size_t len = attributes.Count();

		for(size_t i = 0; i < len; i++) {
			if(attributes[i].AttributeName().value == propName) {
				attributes[i].Member().FromString(propValue);
				continue;
			}
		}
	}

	String Serializable::ToXml(Collections::Generic::List<unsigned long long>& _childPtrs) {
		unsigned long long hash = 0;
		String res;
		size_t len;

		len = attributes.Count();

		res = "<" + this->name+ " ID=\"" + this->getHashCode() + "\">";

		for(size_t i = 0; i < len; i++) {
			SerializableAttribute t = attributes[i];

			// Get Values
			String attrName = t.AttributeName();
			Object& val = t.Member();

			// Check Serializable
			Serializable* child = dynamic_cast<Serializable*>(&val);

			if(child == nullptr) {
				// Just serialize
				res += "<" + attrName + " type=\"" + val.GetTypeString() + "\">";
				res += val.ToString();
				res += "</" + attrName + ">";
			} else {
				// Is Serializable
				hash = child->getHashCode();

				if(_childPtrs.Contains(hash)) {
					// Just add a reference
					res += "<" + attrName + " ref=\"" + hash + "\"/>";
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

	void Serializable::FromString(std::string val) {
		this->FromXml(String(&val));
	}
}