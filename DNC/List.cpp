#include "List.h"
#include <algorithm>

namespace dnc{
	namespace Collections{
		namespace Generic{
/*
			template<typename T>
			inline List<T>::List(){}

			template<typename T>
			inline List<T>::List(unsigned int capacity){
				this->values.reserve(capacity);
			}

			template<typename T>
			inline List<T>::~List(){}

			template<typename T>
			inline std::string List<T>::ToString(){
				return std::string("System.Collections.Generics.List");
			}

			template<typename T>
			inline std::string List<T>::getTypeString(){
				return std::string("List");
			}

			template<typename T>
			inline void List<T>::Add(T item){
				this->values.push_back(item);
			}

			template<typename T>
			inline void List<T>::AddRange(T collection[]){
				std::vector<T> temp(collection);
				this->values.insert(this->values.end(), temp.begin(), temp.end());
			}

			template<typename T>
			inline void List<T>::AddRange(List<T> collection){
				this->values.insert(this->values.end(), collection.begin(), collection.end());
			}

			template<typename T>
			inline void List<T>::Clear(){
				this->values.clear();
			}

			template<typename T>
			inline bool List<T>::Contains(T item){
				return std::find(this->values.begin(), this->values.end(), item) != this->values.end();
			}

			template<typename T>
			inline void List<T>::CopyTo(T * array[]){
				size_t fullsize = 0, len = 0;
				T* original;
				T temp[];

				original = this->values.data();

				len = this->values.size();
				fullsize = sizeof(T) * len; // ???
				temp = new T[len];

				std::memcpy(temp, original, fullsize);

				*array = temp;
			}
			/*
			template<typename T>
			void List<T>::CopyTo(T * array, int arrayIndex){}

			template<typename T>
			void List<T>::CopyTo(int index, T * array, int arrayIndex, int count){}
			
			template<typename T>
			inline unsigned long List<T>::Count(){
				return this->values.size();
			}

			template<typename T>
			inline List<T> List<T>::GetRange(int index, int count){
				List<T> res;
				std::vector<T>::iterator start;
				std::vector<T>::iterator end;

				if((index + count) > this->values.size()){
					throw "Index and/or count out of range";
				}

				start = this->values.begin() + index;
				end = start + count;

				res.values = std::vector<T>(start, end);

				return res;
			}

			template<typename T>
			inline long long List<T>::IndexOf(T * item){
				long long res = -1;
				size_t len = 0;

				len = this->values.size();

				for(size_t i = 0; i < len; i++){
					if(&this->values[i] == item){
						res = i;
						break;
					}
				}

				return res;
			}

			template<typename T>
			inline long long List<T>::IndexOf(T * item, int index){
				long long res = -1;
				size_t len = 0;

				len = this->values.size();

				if(index > len){
					throw "IndexOf: Index out of range";
				}

				for(size_t i = index; i < len; i++){
					if(&this->values[i] == item){
						res = i;
						break;
					}
				}

				return res;
			}

			template<typename T>
			inline long long List<T>::IndexOf(T * item, int index, int count){
				long long res = -1;
				size_t len = 0;

				len = index + count;

				if(len > this->values.size()){
					throw "IndexOf: Index and/or count out of range";
				}

				for(size_t i = index; i < len; i++){
					if(&this->values[i] == item){
						res = i;
						break;
					}
				}

				return res;
			}

			template<typename T>
			inline void List<T>::Insert(int index, T item){
				if(index > this->values.size()){
					throw "Insert: Index out of range";
				}

				this->values.insert(this->values.begin() + index, item);
			}

			template<typename T>
			inline void List<T>::InsertRange(int index, List<T> collection){
				if(index > this->values.size()){
					throw "Insert: Index out of range";
				}

				this->values.insert(this->values.begin() + index, collection.values);
			}

			template<typename T>
			inline unsigned long List<T>::LastIndexOf(T * item){
				long long res = -1;
				size_t len = 0;

				len = this->values.size() - 1;

				for(size_t i = len; i > -1; --i){
					if(&this->values[i] == item){
						res = i;
						break;
					}
				}

				return res;
			}

			template<typename T>
			inline unsigned long List<T>::LastIndexOf(T * item, int index){
				long long res = -1;
				// size_t len = 0;

				// len = this->values.size() - 1;

				if(index < this->values.size()){
					throw "LastIndexOf: Index out of range";
				}

				for(size_t i = index; i > -1; --i){
					if(&this->values[i] == item){
						res = i;
						break;
					}
				}

				return res;
			}

			template<typename T>
			inline unsigned long List<T>::LastIndexOf(T * item, int index, int count){
				long long res = -1;
				size_t len = 0;

				len = index - count;

				if(index < this->values.size() && len > 0){
					throw "LastIndexOf: Index and/or count out of range";
				}

				for(size_t i = index; i > -1; --i){
					if(&this->values[i] == item){
						res = i;
						break;
					}
				}

				return res;
			}

			template<typename T>
			inline bool List<T>::Remove(T * item){
				bool res = false;
				size_t len = 0;

				len = this->values.size();

				for(size_t i = 0; i < len; i++){
					if(&this->values[i] == item){
						this->values.erase(this->values.begin() + i);

						res = true;
						break;
					}
				}

				return res;
			}

			template<typename T>
			inline void List<T>::RemoveAt(int index){
				this->values.erase(this->values.begin() + index);
			}

			template<typename T>
			inline void List<T>::RemoveRange(int index, int count){
				this->values.erase(this->values.begin() + index, this->values.begin() + index + count);
			}

			template<typename T>
			inline void List<T>::Reverse(){
				std::reverse(this->values.begin(), this->values.end());
			}

			template<typename T>
			inline T* List<T>::ToArray(){
				return this->values.data();
			}

			template<typename T>
			inline T List<T>::operator[](int position){
				return this->values[position];
			}
			*/
		}
	}
}