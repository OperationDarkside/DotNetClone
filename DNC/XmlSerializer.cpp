#include "XmlSerializer.h"

namespace dnc {
	namespace Xml {

		XmlSerializer::XmlSerializer() {}


		XmlSerializer::~XmlSerializer() {}

		std::string XmlSerializer::ToString() {
			return std::string("System.Xml.XmlSerializer");
		}

		std::string XmlSerializer::GetTypeString() {
			return std::string("XmlSerializer");
		}

		String XmlSerializer::ToXml(Serializable* obj, Collections::Generic::List<unsigned long long>& _childPtrs) {
			unsigned long long hash = 0;
			String res;
			size_t len;
			//Serializable* seri = nullptr;

			/*if(std::is_same<T, Serializable*>::value) {
			seri = (Serializable*) obj;
			} else {
			seri = static_cast<Serializable*>(&obj);
			}*/

			len = obj->AttrLen();

			res = "<" + obj->Name() + " ID=\"" + obj->getHashCode() + "\">";

			for(size_t i = 0; i < len; i++) {
				SerializableAttribute& t = obj->Attribute(i);

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
						res += "<" + attrName + " type=\"" + val.GetTypeString() + "\">";
						res += ToXml(child, _childPtrs);
						res += "</" + attrName + ">";
					}
				}
			}

			res += "</" + obj->Name() + ">\r\n";

			return res;
		}
	}
}