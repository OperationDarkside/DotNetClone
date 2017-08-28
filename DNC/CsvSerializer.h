#pragma once

#ifndef CSVSERIALIZER_H
#define CSVSERIALIZER_H

#include "Serializable.h"
#include "DataTable.h"

namespace dnc {
	namespace CSV {
		class CsvSerializer : public Object {
		public:
			CsvSerializer();
			~CsvSerializer();

			std::string ToString() override;
			std::string GetTypeString() override;

			template<class T>
			String Serialize(Collections::Generic::List<T> collection);

			template<class T>
			Collections::Generic::List<T> Deserialize(String& csvString);

			Data::DataTable Deserialize(String& csvString);
		};

		template<class T>
		inline String CsvSerializer::Serialize(Collections::Generic::List<T> collection) {
			// Base check
			static_assert(std::is_base_of<Serializable, T>::value, "T is not a base class of Serializable");

			String res;
			size_t coll_len;
			size_t attr_len;
			size_t attr_cut_len;
			Serializable* seri = nullptr;


			coll_len = collection.Count();

			if(coll_len == 0) {
				return "";
			}

			// Create Header Row
			seri = static_cast<Serializable*>(&collection[0]);
			attr_len = seri->AttrLen();
			attr_cut_len = attr_len - 1;

			for(size_t i = 0; i < attr_cut_len; i++) {
				SerializableAttribute& t = seri->Attribute(i);

				res += t.AttributeName() + ";";
			}
			SerializableAttribute& t = seri->Attribute(attr_cut_len);
			res += t.AttributeName() + "\r\n";
			seri = nullptr;


			// Write data
			for(size_t i = 0; i < coll_len; i++) {
				T obj = collection[i];
				seri = static_cast<Serializable*>(&obj);

				for(size_t g = 0; g < attr_cut_len; g++) {
					SerializableAttribute& t = seri->Attribute(g);

					res += t.Member().ToString() + ';';
				}
				// Attach last value
				SerializableAttribute& t = seri->Attribute(attr_cut_len);
				res += t.Member().ToString() + "\r\n";

			}
			//SerializableAttribute& t = seri->Attribute(i);

			return res;
		}

		template<class T>
		inline Collections::Generic::List<T> CsvSerializer::Deserialize(String & jsonString) {
			static_assert(std::is_base_of<Serializable, T>::value, "T is not a base class of Serializable");

			return T();
		}
	}
}

#endif // CSVSERIALIZER_H