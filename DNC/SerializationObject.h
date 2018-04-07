#pragma once

#ifndef SERIALIZABLEOBJECT_H
#define SERIALIZABLEOBJECT_H

#include <string>
#include <vector>
#include <unordered_map>
#include <type_traits>

class SerializationObject {
public:
	SerializationObject ();
	~SerializationObject ();

	template<typename T>
	T get (const std::string& key) {

		if constexpr (std::is_same<T, std::string>::value) {
			std::string value;

			auto& it = values.find (key);
			if (it == values.end ()) {
				return value;
			}

			value = it->second;
			return value;
		} else if constexpr (std::is_same<T, bool>::value) {
			bool b;
			std::string value;

			auto& it = values.find (key);
			if (it == values.end ()) {
				return b;
			}

			value = it->second;
			std::transform (str.begin (), str.end (), str.begin (), ::tolower);
			std::istringstream is (str);
			is >> std::boolalpha >> b;
			return b;
		} else if constexpr (std::is_same<T, unsigned int>::value || std::is_same<T, unsigned long>::value) {
			unsigned long uintVal = 0;
			std::string value;

			auto& it = values.find (key);
			if (it == values.end ()) {
				return uintVal;
			}

			value = it->second;
			uintVal = std::stoul (value);
			return uintVal;
		} else if constexpr (std::is_same<T, unsigned long long>::value) {
			unsigned long long ullVal = 0;
			std::string value;

			auto& it = values.find (key);
			if (it == values.end ()) {
				return ullVal;
			}

			value = it->second;
			ullVal = std::stoull (value);
			return ullVal;
		} else if constexpr (std::is_same<T, int>::value) {
			int intVal = 0;
			std::string value;

			auto& it = values.find (key);
			if (it == values.end ()) {
				return intVal;
			}

			value = it->second;
			intVal = std::stoi (value);
			return intVal;
		} else if constexpr (std::is_same<T, long>::value) {
			long longVal = 0;
			std::string value;

			auto& it = values.find (key);
			if (it == values.end ()) {
				return longVal;
			}

			value = it->second;
			longVal = std::stol (value);
			return longVal;
		} else if constexpr (std::is_same<T, long long>::value) {
			long long llVal = 0;
			std::string value;

			auto& it = values.find (key);
			if (it == values.end ()) {
				return llVal;
			}

			value = it->second;
			llVal = std::stoll (value);
			return llVal;
		} else if constexpr (std::is_same<T, float>::value) {
			float fVal = 0;
			std::string value;

			auto& it = values.find (key);
			if (it == values.end ()) {
				return fVal;
			}

			value = it->second;
			fVal = std::stof (value);
			return fVal;
		} else if constexpr (std::is_same<T, double>::value) {
			double dVal = 0;
			std::string value;

			auto& it = values.find (key);
			if (it == values.end ()) {
				return dVal;
			}

			value = it->second;
			dVal = std::stod (value);
			return dVal;
		} else if constexpr (std::is_same<T, long double>::value) {
			long double ldVal = 0;
			std::string value;

			auto& it = values.find (key);
			if (it == values.end ()) {
				return ldVal;
			}

			value = it->second;
			ldVal = std::stold (value);
			return ldVal;
		} else if constexpr (
			std::is_default_constructible<T>::value
			&& std::is_member_function_pointer<
			void
			(T::*)
			(SerializationObject&)
			>::value) {
			auto& it = subObjects.find (key);
			if (it == subObjects.end ()) {
				return T ();
			}

			SerializationObject& value = it->second;
			T t;

			t.deserialize (value);

			return t;
		} else {
			static_assert(false, "Template is not a valid type");
		}
	}

	template<typename T>
	std::vector<T> getArray (const std::string& key) {
		if constexpr (std::is_default_constructible<T>::value && std::is_member_function_pointer<void(T::*)(SerializationObject&)>::value) {
			std::vector<T> res;

			auto& it = arrays.find (key);
			if (it == arrays.end ()) {
				return res;
			}

			std::vector<SerializationObject>& values = it->second;

			for (auto& val : values) {
				T t;

				t.deserialize (val);

				res.push_back (t);
			}

			return res;
		} else {
			static_assert(false, "Template is not a valid type");
		}
	}

	template<typename T>
	void set (const std::string& key, T& value) {

		if constexpr (std::is_same<T, std::string>::value) {
			std::string val;
			val = value;
			values.emplace (key, val);
		} else if constexpr (std::is_arithmetic<T>::value) {
			std::string val;
			val = std::to_string (value);
			values.emplace (key, val);
		} else if constexpr (std::is_member_function_pointer < SerializationObject (T::*) ()> ::value) {
			SerializationObject val = value.serialize ();

			subObjects.emplace (key, val);
		} else {
			static_assert(false, "Template is not a valid type");
		}
	}

	template<typename T>
	void set (const std::string& key, std::vector<T>& values) {
		if constexpr (std::is_member_function_pointer<SerializationObject (T::*) ()>::value) {
			std::vector<SerializationObject> serObjs;

			for (auto& val : values) {
				SerializationObject serObj = val.serialize ();

				serObjs.push_back (serObj);
			}

			arrays.emplace (key, serObjs);
		} else {
			static_assert(false, "Template is not a valid type");
		}
	}

	std::unordered_map<std::string, std::string>& getValues ();

	std::unordered_map<std::string, SerializationObject>& getSubObjects ();

	std::unordered_map<std::string, std::vector<SerializationObject>>& getArrays ();

private:

	std::unordered_map<std::string, std::string> values;

	std::unordered_map<std::string, SerializationObject> subObjects;

	std::unordered_map<std::string, std::vector<SerializationObject>> arrays;
};

#endif // !SERIALIZABLEOBJECT_H