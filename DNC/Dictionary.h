#ifndef DICTIONARY_H
#define DICTIONARY_H

#pragma once
#include "Object.h"
#include <map>

namespace dnc {
	namespace Collections {
		namespace Generic {

			template<typename K, typename V>
			class Dictionary : public Object {
			public:
				Dictionary();
				Dictionary(K key, V value);
				Dictionary(unsigned int capacity);
				~Dictionary();

				std::string ToString() override;
				std::string GetTypeString() override;

				unsigned long long Count();

				void Add(K key, V value);
				void Clear();
				bool ContainsKey(K& key);
				bool ContainsValue(V& value);
				bool Remove(K& key);

				V operator[](K key);

			private:
				std::map<K, V> m;
			};

			template<typename K, typename V>
			inline Dictionary<K, V>::Dictionary() {

			}

			template<typename K, typename V>
			inline Dictionary<K, V>::Dictionary(K key, V value) {
				this->m.insert(key, value);
			}
			template<typename K, typename V>
			inline Dictionary<K, V>::Dictionary(unsigned int capacity) {}

			template<typename K, typename V>
			inline Dictionary<K, V>::~Dictionary() {

			}

			template<typename K, typename V>
			inline std::string Dictionary<K, V>::ToString() {
				return std::string("System.Collections.Generic.Dictionary");
			}

			template<typename K, typename V>
			inline std::string Dictionary<K, V>::GetTypeString() {
				return std::string("Dictionary");
			}

			template<typename K, typename V>
			inline unsigned long long Dictionary<K, V>::Count() {
				return this->m.size();
			}

			template<typename K, typename V>
			inline void Dictionary<K, V>::Add(K key, V value) {
				this->m.insert(key, value);
			}

			template<typename K, typename V>
			inline void Dictionary<K, V>::Clear() {
				this->m.clear();
			}

			template<typename K, typename V>
			inline bool Dictionary<K, V>::ContainsKey(K & key) {
				std::map<K, V>::iterator it = this->m.find(key);

				if(it != it.end()) {
					return true;
				} else {
					return false;
				}
			}

			template<typename K, typename V>
			inline bool Dictionary<K, V>::ContainsValue(V & value) {
				std::map<K, V>::iterator it = this->m.begin();

				while(it != this->m.end()) {
					if(it->second == value) {
						return true;
					}

					++it;
				}
				return false;
			}

			template<typename K, typename V>
			inline bool Dictionary<K, V>::Remove(K & key) {
				return this->m.erase(key);
			}

			template<typename K, typename V>
			inline V Dictionary<K, V>::operator[](K key) {
				return this->m[key];
			}
		}
	}
}
#endif // !DICTIONARY_H