#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray
{
protected:

	short _Size ;
	T* _TempArray;

public :

	T* _OriginalArray  ;

	clsDynamicArray(short Size = 0)
	{
		if (Size < 0)
			Size = 0;

		_Size = Size;

		_OriginalArray = new T[_Size]; 
	}

	~clsDynamicArray()
	{		
		delete [] _OriginalArray;	
	}

	bool SetItem(short Index, T value)
	{
		if (_Size < 0 || Index < 0 || Index >= _Size)
			return false;

		_OriginalArray[Index] = value;
		return true;
	}

	bool IsEmpty()
	{
		return _Size == 0;
	}

	short Size()
	{
		return _Size; 
	}

	void PrintList()
	{
		for (short i = 0; i <= _Size -1; i++)
		{
			cout << _OriginalArray[i] << " "; 
		}
	}

	void Resize(short NewSize)
	{
		if (NewSize < 0)
			NewSize = 0;

		_TempArray = new T[NewSize];

		if (NewSize < _Size)
			_Size = NewSize;

		for (short i = 0; i < _Size; i++)
		{
			_TempArray[i] = _OriginalArray[i];
		}

		_Size = NewSize; 

		delete[] _OriginalArray;
		_OriginalArray = _TempArray; 
	}

	void Reverse()
	{
		_TempArray = new T[_Size]; 

		short counter = 0; 
		for (short i = _Size - 1; i >= 0; i--)
		{
			_TempArray[counter++] = _OriginalArray[i];
		}

		delete[]_OriginalArray;
		_OriginalArray = _TempArray;
	}

	T GetItem(short Index)
	{
		return _OriginalArray[Index]; 

	}

	void Clear()
	{
		delete[]_OriginalArray;
		_TempArray = new T(0); 
		_OriginalArray = _TempArray;
		_Size = 0;
	}

	void DeleteItemAt(short Index)
	{
		if (_Size < 0 || Index < 0 || Index >= _Size)
			return ;

		_Size--; 

		_TempArray = new T[_Size]; 

		for (short i = 0; i < Index; i++)
		{
			_TempArray[i] = _OriginalArray[i]; 
		}

		for (short i = Index + 1; i < _Size + 1; i++)
		{
			_TempArray[i - 1] = _OriginalArray[i]; 
		}

		delete[]_OriginalArray;
		_OriginalArray = _TempArray; 
	}

	void DeleteFirstItem()
	{
		return DeleteItemAt(0); 
	}

	void DeleteLastItem()
	{
		return DeleteItemAt(_Size - 1);
	}

	short Find(T value)
	{
		for (short i = 0; i < _Size; i++)
		{
			if (_OriginalArray[i] == value)
			{
				return i; 
			}
		}

		return -1;
	}

	bool DeleteItem(T value)
	{
		short ItemIndex = Find(value); 

		if (ItemIndex == -1)
			return false;

		DeleteItemAt(ItemIndex);
		return true;
	}

	bool InsertAt(short Index , T value)
	{
		if (_Size < 0 || Index < 0 || Index > _Size)
			return false;

		_Size++;

		_TempArray = new T[_Size]; 

		for (short i = 0; i < Index; i++)
		{
			_TempArray[i] = _OriginalArray[i]; 
		}

		_TempArray[Index] = value;

		for (short i = Index; i < _Size - 1; i++)
		{
			_TempArray[i + 1] = _OriginalArray[i]; 
		}

		delete[] _OriginalArray;
		_OriginalArray = _TempArray; 
		return true;
	}

	void InsertAtBeginning(T value)
	{
		InsertAt(0, value); 
	}

	void InsertAtEnd(T value)
	{
		InsertAt(_Size,value); 
	}

	void InsertBefore(short Index ,T value)
	{
		if (Index < 1)
		{
			InsertAt(0, value); 
			return; 
		}
			
		InsertAt(Index-1, value); 
	}

	void InsertAfter(short Index, T value)
	{
		if (Index >= _Size)
		{
			InsertAt(_Size, value); 
			return;
		}
			
		InsertAt(Index + 1, value); 
	}

};

