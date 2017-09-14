#pragma once

#ifndef JSONSERIALIZER_H
#define JSONSERIALIZER_H

#include "Serializable.h"

namespace dnc {
	namespace Json {

		class JsonSerializer : public Object {
		public:
			JsonSerializer();
			~JsonSerializer();

			std::string ToString() override;
			std::string GetTypeString() override;

			template<class T>
			String Serialize(T& obj);

			template<class T>
			T Deserialize(String& jsonString);

		private:
			String ToJson(Serializable* obj, Collections::Generic::List<unsigned long long>& _childPtrs);
		};

		template<class T>
		inline String JsonSerializer::Serialize(T & obj) {
			// Base check
			static_assert(std::is_base_of<Serializable, T>::value, "T is not a base class of Serializable");

			String res;
			size_t len;
			Serializable* seri = nullptr;
			Collections::Generic::List<unsigned long long> childPtrs;

			seri = static_cast<Serializable*>(&obj);

			len = seri->AttrLen();

			res = "{\"Name\":\"" + seri->Name() + "\",\"ID\":" + seri->getHashCode() + ",\"Attributes\":{";

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
					res += "\"" + attrName + "\":{\"Type\":\"" + val.GetTypeString() + "\",\"Value\":\"";
					res += val.ToString();
					res += "\"},";
				} else {
					// Step into
					res += "\"" + attrName + "\":{\"Type\":\"" + val.GetTypeString() + "\",\"Value\":";
					childPtrs.Add(child->getHashCode());
					res += ToJson(child, childPtrs);
					res += "},";
				}
			}

			res = res.Substring(0, res.Length() - 1);

			res += "}}";

			return res;
		}

		template<class T>
		inline T JsonSerializer::Deserialize(String & jsonString) {
			return T();
		}

	}
}
#endif