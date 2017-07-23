#pragma once

#ifndef XMLSERIALIZER_H
#define XMLSERIALIZER_H

#include "Serializable.h"

namespace dnc {
	namespace Xml {

		class XmlSerializer : public Object {
		public:
			XmlSerializer();
			~XmlSerializer();

			std::string ToString() override;
			std::string GetTypeString() override;

			template<class T>
			String Serialize(T& obj);

			template<class T>
			T Deserialize(String& xmlString);

		private:
			
			String ToXml(Serializable* obj, Collections::Generic::List<unsigned long long>& _childPtrs);
		};

		template<class T>
		inline String XmlSerializer::Serialize(T& obj) {
			// Base check
			static_assert(std::is_base_of<Serializable, T>::value , "T is not a base class of Serializable");

			String res;
			size_t len;
			Serializable* seri = nullptr;
			Collections::Generic::List<unsigned long long> childPtrs;

			seri = static_cast<Serializable*>(&obj);

			len = seri->AttrLen();

			res = "<" + seri->Name() + " ID=\"" + seri->getHashCode() + "\">";

			for(size_t i = 0; i < len; i++) {
				SerializableAttribute& t = seri->Attribute(i);

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
					res += "<" + attrName + " type=\"" + val.GetTypeString() + "\">";
					childPtrs.Add(child->getHashCode());
					res += ToXml(child, childPtrs);
					res += "</" + attrName + ">";
				}
			}

			res += "</" + seri->Name() + ">";

			return res;
		}

		template<class T>
		inline T XmlSerializer::Deserialize(String& xmlString) {
			// Base check
			static_assert(std::is_base_of<Serializable, T> {}, "T is not a base class of Serializable");

			bool isTag = false;
			bool isClosingTag = false;
			unsigned short depth = 0;
			size_t len = xmlString.length();
			std::string tag;
			std::string tag_name = "";
			std::string val = "";
			Serializable* seri = nullptr;
			T res;

			seri = static_cast<Serializable*>(&res);

			for(size_t i = 0; i < len; ++i) {
				char c = xmlString[i];

				if(c == '<') {

					char c2 = xmlString[i + 1];
					if(c2 == '/' && tag_name != "") {
						// Closing Tag
						isClosingTag = true;
						if(depth < 3) {
							seri->SetProperty(tag_name, val);

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

			return res;
		}


	}
}
#endif // !XMLSERIALIZER_H