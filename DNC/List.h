#pragma once
#include "String.h"

namespace dnc::Collections::Generic{

	/**
	Generic collection with indexed access and several manipulation methods (wraps the std::vector)
	*/
	template<typename T>
	class List: public Object{
	public:
		List();
		List(unsigned int capacity);
		~List();

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

	private:
		vector<T> values;
	};

}