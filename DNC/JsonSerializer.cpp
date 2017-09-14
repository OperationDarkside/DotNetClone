#include "JsonSerializer.h"

namespace dnc {
	namespace Json {

		JsonSerializer::JsonSerializer() {}


		JsonSerializer::~JsonSerializer() {}

		std::string JsonSerializer::ToString() {
			return std::string("System.Json.JsonSerializer");
		}

		std::string JsonSerializer::GetTypeString() {
			return std::string("JsonSerializer");
		}

		String JsonSerializer::ToJson(Serializable * obj, Collections::Generic::List<unsigned long long>& _childPtrs) {
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

			res = "{\"Name\":\"" + obj->Name() + "\",\"ID\":" + obj->getHashCode() + ",\"Attributes\":{";

			for(size_t i = 0; i < len; i++) {
				SerializableAttribute& t = obj->Attribute(i);

				// Get Values
				String attrName = t.AttributeName();
				Object& val = t.Member();

				// Check Serializable
				Serializable* child = dynamic_cast<Serializable*>(&val);

				if(child == nullptr) {
					// Just serialize
					res += "\"" + attrName + "\":{\"Type\":\"" + val.GetTypeString() + "\",\"Value\":\"";
					res += val.ToString();
					res += "\"},";
				} else {
					// Is Serializable
					hash = child->getHashCode();

					if(_childPtrs.Contains(hash)) {
						// Just add a reference
						res += "\"" + attrName + "\":{\"Type\":\"" + val.GetTypeString() + "\",\"Ref\":" + hash + "},";
					} else {
						// Call serialize
						_childPtrs.Add(hash);
						res += "\"" + attrName + "\":{\"Type\":\"" + val.GetTypeString() + "\",\"Value\":";
						res += ToJson(child, _childPtrs);
						res += "},";
					}
				}
			}

			res = res.Substring(0, res.Length() - 1);

			res += "}}";

			return res;
		}

	}
}