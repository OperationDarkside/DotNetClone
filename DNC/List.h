#pragma once

#ifndef LIST_H
#define LIST_H

#include "Object.h"
#include <vector>


namespace dnc{
	namespace Collections{
		namespace Generic{

			/**
			Generic collection with indexed access and several manipulation methods (wraps the std::vector)
			*/
			template<typename T>
			class List: public Object{
			public:
				List();
				List(unsigned int capacity);
				~List();

				std::string ToString() override;
				std::string GetTypeString() override;

				/**
				Adds a new Item to the list
				@param item The new Item
				*/
				void Add(T item);
				/**
				Adds several new Items to the list
				@param items Array of new items
				*/
				void AddRange(T collection[]);
				/**
				Adds several new Items to the list
				@param items List of new items
				*/
				void AddRange(List<T> collection);
				/**
				Removes all items of this list instance
				*/
				void Clear();
				/**
				Returns true if an item is in this list
				@param item to be found
				*/
				bool Contains(T item);
				/**
				Copys this lists contents to the given pointer
				@param array Pointer to the new array
				*/
				void CopyTo(T* array[]);
				// void CopyTo(T* array, int arrayIndex);
				// void CopyTo(int index ,T* array, int arrayIndex, int count);
				/**
				Returns the amount of items in this collection
				@return unsigned long number of items
				*/
				unsigned long Count();
				/**
				Returns a sub-list in this collection
				@param index First item to return
				@param count Number of items to return
				@return sub-list
				*/
				List<T> GetRange(int index, int count);
				/**
				Returns the position of the item in this list
				@param item Pointer to the searched item
				@return Position
				*/
				long long IndexOf(T* item);
				/**
				Returns the position of the item in this list
				@param item Pointer to the searched item
				@param index Starting point where the search begins
				@return Position
				*/
				long long IndexOf(T* item, int index);
				/**
				Returns the position of the item in this list
				@param item Pointer to the searched item
				@param index Starting point where the search begins
				@param count Number items to be searched
				@return Position
				*/
				long long IndexOf(T* item, int index, int count);
				/**
				Inserts a new item into the list at the given position
				@param index Position where to insert
				@param item Element to insert
				*/
				void Insert(int index, T item);
				/**
				Insert a few new items into the list at the given position
				@param index Position where to insert
				@param collection Elements to insert
				*/
				void InsertRange(int index, List<T> collection);
				/**
				Returns the position of the item in this list starting at the end to front
				@param item Pointer to the searched item
				@return Position
				*/
				unsigned long LastIndexOf(T* item);
				/**
				Returns the position of the item in this list starting at the end from front
				@param item Pointer to the searched item
				@param index Starting point where the search begins
				@return Position
				*/
				unsigned long LastIndexOf(T* item, int index);
				/**
				Returns the position of the item in this list starting at the end from front
				@param item Pointer to the searched item
				@param index Starting point where the search begins
				@param count Number items to be searched
				@return Position
				*/
				unsigned long LastIndexOf(T* item, int index, int count);
				/**
				Removes a specific item from this list
				@param item Pointer to the be removed item
				@return if it was removed
				*/
				bool Remove(T* item);
				/**
				Removes a specific item from this list
				@param index Position of the item to be removed
				*/
				void RemoveAt(int index);
				/**
				Removes multiple items from this list
				@param index Position of the first item to be removed
				@param count Number of elements to remove
				*/
				void RemoveRange(int index, int count);
				/**
				Reverses the list
				*/
				void Reverse();
				/**
				Returns the internal array of this list
				@return Pointer to the array
				*/
				T* ToArray();
				/**
				Returns the contained vector

				@return The vector wrapped by this class
				*/
				std::vector<T> Vector();
				/**
				Sets the vector for this class

				@param vec vector to be the datasource for this class
				*/
				void Vector(std::vector<T> vec);

				T& operator[](int position);

			private:
				std::vector<T> values;
			};


			template<typename T>
			inline List<T>::List(){}

			template<typename T>
			inline List<T>::List(unsigned int capacity){
				this->values = std::vector<T>(capacity);
			}

			template<typename T>
			inline List<T>::~List(){}

			template<typename T>
			inline std::string List<T>::ToString(){
				return std::string("System.Collections.Generics.List");
			}

			template<typename T>
			inline std::string List<T>::GetTypeString(){
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
			inline T * List<T>::ToArray(){
				return this->values.data();
			}

			template<typename T>
			inline std::vector<T> List<T>::Vector(){
				return this->values;
			}

			template<typename T>
			inline void List<T>::Vector(std::vector<T> vec){
				this->values = vec;
			}

			template<typename T>
			inline T& List<T>::operator[](int position){
				size_t len = 0;

				len = this->values.size();

				if(len > 0 && position < len){
					return this->values[position];
				} else{
					throw "Index out of Range!";
				}
			}

}
	}
}
#endif // !LIST_H