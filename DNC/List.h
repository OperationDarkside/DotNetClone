#pragma once
#include "String.h"

template<typename T>
class List : public Object {
public:
	List();
	List(unsigned int capacity);
	~List();

	void Add(T item);
	void AddRange(T collection[]);
	void AddRange(List<T> collection);
	void Clear();
	bool Contains(T item);
	void CopyTo(T* array[]);
	// void CopyTo(T* array, int arrayIndex);
	// void CopyTo(int index ,T* array, int arrayIndex, int count);
	unsigned long Count();
	List<T> GetRange(int index, int count);
	long long IndexOf(T* item);
	long long IndexOf(T* item, int index);
	long long IndexOf(T* item, int index, int count);
	void Insert(int index, T item);
	void InsertRange(int index, List<T> collection);
	unsigned long LastIndexOf(T* item);
	unsigned long LastIndexOf(T* item, int index);
	unsigned long LastIndexOf(T* item, int index, int count);
	bool Remove(T* item);
	void RemoveAt(int index);
	void RemoveRange(int index, int count);
	void Reverse();
	T* ToArray();

private:
	vector<T> values;
};

