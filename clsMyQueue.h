#pragma once
#include "clsDblLinkedList.h"

template <class T>
class clsMyQueue
{
protected :

	clsDblLinkedList<T> _MyList;

public : 

	void push(T Item)
	{
		_MyList.InsertAtEnd(Item); 
	}

	void pop()
	{
		_MyList.DeleteFirstNode();
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

	bool UpdateItem(short Index , T newItem)
	{
		return _MyList.UpdateItem(Index, newItem);
	}

	void InsertAtFront(T Item)
	{
		_MyList.InsertAtBeginning(Item);
	}

	void InsertAtBack(T Item)
	{
		_MyList.InsertAtEnd(Item);
	}

	bool InsertAfter(short Index, T Item)
	{
		return _MyList.InsertAfter(Index, Item);
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

