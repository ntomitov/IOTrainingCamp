/*
	Name: Heap Abstract Data Type
	Description: Generic Max Heap Data Structure
	Author: Konstantin Dinev
	Date: December 2013
	License: MIT Licence
*/

#ifndef HEAP_H

#define HEAP_h

#ifndef HEAP_MAX_SIZE

#define HEAP_MAX_SIZE 100

#endif

/// <summary>
/// Generic Max Heap Data Structure
/// </summary>
template <class Type>
class Heap {
private:
	Type container[HEAP_MAX_SIZE];
	int size;

public:
	// Constructors
	Heap();
	Heap(Type[], int);
	
	// Accessors and Modifiers
	void Insert(Type);
	bool DeleteByValue(Type);
	Type DeleteByIndex(int index);
	void HeapifyUp(int);
	void HeapifyDown(int);

	// Utilities
	bool IsFull();
	bool IsEmpty();
};

/// <summary>
/// Initializes a new instance of the <see cref="Heap{Type}"/> class.
/// </summary>
template <class Type>
Heap<Type>::Heap() {
	size = 0;
}

/// <summary>
/// Initializes a new instance of the <see cref="Heap{Type}"/> class.
/// </summary>
/// <param name="items">The items.</param>
/// <param name="max_size">The max_size.</param>
template <class Type>
Heap<Type>::Heap(Type items [], int max_size) {
	size = max_size;
	container = items;
}

/// <summary>
/// Insert at the last position and <see cref="Heap{Type}::HeapifyUp"/>
/// </summary>
/// <param name="item">The item.</param>
template <class Type>
void Heap<Type>::Insert(Type item) {
	container[size] = item;
	HeapifyUp(size);
	size++;
}

/// <summary>
/// Deletes the by value.
/// </summary>
/// <param name="item">The item.</param>
/// <returns>true if the item was found and deleted, false otherwise</returns>
template <class Type>
bool Heap<Type>::DeleteByValue(Type item) {
	// Not Implemented
	return false;
}

/// <summary>
/// Delete at index and <see cref="Heap{Type}::HeapifyDown"/>.
/// </summary>
/// <param name="index">The index.</param>
/// <returns>The value of the deleted item</returns>
template <class Type>
Type Heap<Type>::DeleteByIndex(int index) {
	int temp = container[index];
	container[index] = container[--size];
	HeapifyDown(index);
	return temp;
}

/// <summary>
/// Heapifies up.
/// </summary>
/// <param name="index">The index.</param>
template <class Type>
void Heap<Type>::HeapifyUp(int index) {
	if (index > 0) {
		int parent = index / 2;
		if (container[index] > container[parent]) {
			Type temp = container[parent];
			container[parent] = container[index];
			container[index] = temp;
			HeapifyUp(parent);
		}
	}
}

/// <summary>
/// Heapifies down.
/// </summary>
/// <param name="index">The index.</param>
template <class Type>
void Heap<Type>::HeapifyDown(int index) {
	int child = index * 2 + 1;
	if (child + 1 < size) {
		child = container[child] < container[child + 1] ? child + 1 : child;
		if (container[child] > container[index]) {
			Type temp = container[child];
			container[child] = container[index];
			container[index] = temp;
			HeapifyDown(child);
		}
	} else if (child < size && container[child] > container[index]) {
		Type temp = container[child];
		container[child] = container[index];
		container[index] = temp;
		HeapifyDown(child);
	}
}

/// <summary>
/// Determines whether this instance is empty.
/// </summary>
/// <returns>true if empty, false otherwise</returns>
template <class Type>
bool Heap<Type>::IsEmpty() {
	return size == 0;
}

/// <summary>
/// Determines whether this instance is full.
/// </summary>
/// <returns>true if full, false otherwise</returns>
template <class Type>
bool Heap<Type>::IsFull() {
	// Not Implemented
	return false;
}

#endif