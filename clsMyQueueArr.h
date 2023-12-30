#pragma once
#include "clsDynamicArray.h"

template <class T>
class clsMyQueueArr
{

protected :

	clsDynamicArray<T> _MyList;

public :

	void push(T value)
	{
		_MyList.InsertAtEnd(value); 
	}

	void pop()
	{
		_MyList.DeleteFirstItem(); 
	}

	void Print()
	{
		_MyList.PrintList(); 
	}

	short Size()
	{
		return _MyList.Size(); 
	}

	bool IsEmpty()
	{
		return _MyList.IsEmpty();
	}

	T front()
	{
		return _MyList.GetItem(0); 
	}

	T back()
	{
		return _MyList.GetItem(Size() - 1); 
	}

	T GetItem(short Index)
	{
		return _MyList.GetItem(Index);
	}

	void UpdateItem(short Index, T newItem)
	{
		_MyList.SetItem(Index, newItem);
	}

	void InsertAtFront(T Item)
	{
		_MyList.InsertAtBeginning(Item);
	}

	void InsertAtBack(T Item)
	{
		_MyList.InsertAtEnd(Item);
	}

	void InsertAfter(short Index, T Item)
	{
		_MyList.InsertAfter(Index, Item);
	}

	void Reverse()
	{
		_MyList.Reverse();
	}

	void Clear()
	{
		_MyList.Clear();
	}

};

