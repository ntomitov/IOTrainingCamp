/*
	Description: Immutable stack class definition
	Author: Konstantin Dinev
	Date: April 2012
*/

#ifndef IMMUTABLESTACK_H

#define IMMUTABLESTACK_H

#ifndef STACKMAXSIZE

#define STACK_MAX_SIZE 100

#endif

template <class ItemType>
class ImmutableStack
{
public:
	// Default constructor
	ImmutableStack();
	// State constructor
	ImmutableStack(ItemType[], int);
	// Copy constructor
	ImmutableStack(const ImmutableStack&);

	// Stack manipulation methods
	ImmutableStack Push(ItemType item);
	ImmutableStack Pop(ItemType& item);
	ImmutableStack Pop();
	ItemType Top();

	// Utility methods
	ImmutableStack operator=(const ImmutableStack&);

	// Accessors and Modifiers
	int GetSize();
	int GetMaxSize();
	ItemType GetItemArray();
	void SetMaxSize(int);

private:
	int _stackSize;
	static const int _stackMaxSize = STACK_MAX_SIZE;
	ItemType _items[_stackMaxSize];
};

// Default constructor
template <class ItemType>
ImmutableStack<ItemType>::ImmutableStack()
{
	_stackSize = 0;
}

// State constructor
template <class ItemType>
ImmutableStack<ItemType>::ImmutableStack(ItemType items [100], int stackSize)
{
	if (stackSize > _stackMaxSize) 
	{
		throw "Maximum stack size exceeded.";
	}
	for (int i = 0; i < stackSize; i++) 
	{
		_items[i] = items[i];
	}
	_stackSize = stackSize;
}

// Copy constructor
template <class ItemType>
ImmutableStack<ItemType>::ImmutableStack(const ImmutableStack<ItemType>& oldStack)
{
	_stackSize = oldStack._stackSize;
	for (int i = 0; i < _stackSize; i++)
	{
		_items[i] = oldStack._items[i];
	}
}

// ************************* MANIPULATION METHODS *************************

template <class ItemType>
ImmutableStack<ItemType> ImmutableStack<ItemType>::Push(ItemType item)
{
	_items[_stackSize] = item;
	return ImmutableStack<ItemType>(_items, _stackSize + 1);
}

template <class ItemType>
ImmutableStack<ItemType> ImmutableStack<ItemType>::Pop(ItemType& item)
{
	item = _items[_stackSize];
	return ImmutableStack(_items, _stackSize - 1);
}

template <class ItemType>
ImmutableStack<ItemType> ImmutableStack<ItemType>::Pop()
{
	return ImmutableStack(_items, _stackSize - 1);
}

template <class ItemType>
ItemType ImmutableStack<ItemType>::Top()
{
	if (_stackSize > 0)
	{
		return _items[_stackSize - 1];
	}
	else
	{
		throw("Stack is empty.");
	}
}

// ************************* Utility Methods *************************

/*
	Remember that this method changes the state of the left-hand-side operand.
*/
template <class ItemType>
ImmutableStack<ItemType> ImmutableStack<ItemType>::operator=(const ImmutableStack& rhs)
{
	if (this != &rhs)
	{
		_stackSize = rhs._stackSize;
		for (int i = 0; i < _stackSize; i++)
		{
			_items[i] = rhs._items[i];
		}
	}
	return *this;
}

// ************************* Accessors and Modifiers *************************

template <class ItemType>
int ImmutableStack<ItemType>::GetSize()
{
	return _stackSize;
}

template <class ItemType>
int ImmutableStack<ItemType>::GetMaxSize()
{
	return _stackMaxSize;
}

template <class ItemType>
ItemType ImmutableStack<ItemType>::GetItemArray()
{
	return _items;
}

template <class ItemType>
void ImmutableStack<ItemType>::SetMaxSize(int newSize)
{
	_stackSize = newSize;
}

#endif
