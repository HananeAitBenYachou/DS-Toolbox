#pragma once
#include <iostream>
using namespace std; 

template <class T>
class clsDblLinkedList
{

private : 

	short _Size = 0;

public : 

	class Node
	{
	public :
		T value;
		Node* prev; 
		Node* next;
	};

	Node* Head = NULL;

	void PrintList()
	{
		Node* Current = Head;

		while (Current != NULL)
		{
			cout << Current->value << " "; 
			
			Current = Current->next;
		}
	}

	void InsertAtBeginning(T value)
	{
		Node* newNode = new Node(); 

		newNode->value = value;
		newNode->prev = NULL;
		newNode->next = Head;

		if (Head != NULL)
		{
			Head->prev = newNode;
		}

		Head = newNode;
		_Size++;
	}

	void InsertAfter(Node *CurrentNode , T value)
	{
		if (CurrentNode == NULL)
			return; 

		Node* NewNode = new Node(); 

		NewNode->prev = CurrentNode;
		NewNode->value = value;
		NewNode->next = CurrentNode->next;

		if (CurrentNode->next != NULL)
		{
			CurrentNode->next->prev = NewNode;
		}

		CurrentNode->next = NewNode;
		_Size++;
	}

	void InsertAtEnd(T value)
	{
		Node* NewNode = new Node(); 

		NewNode->value = value;
		NewNode->next = NULL;

		if (Head == NULL)
		{
			NewNode->prev = NULL;
			Head = NewNode;
			_Size++;
			return;		
		}

		Node* LastNode = Head;
		while (LastNode->next != NULL)
		{
			LastNode = LastNode->next;
		}

		LastNode->next = NewNode;
		NewNode->prev = LastNode;
		_Size++;
	}

	Node* Find(T value)
	{
		Node* Current = Head;

		while (Current != NULL)
		{
			if (Current->value == value)
				return Current;

			Current = Current->next;
		}

		return NULL;
	}

	void DeleteNode(Node *&NodeToDelete)
	{
		if (Head == NULL || NodeToDelete == NULL)
			return; 

		if (Head == NodeToDelete)
		{
			Head = Head->next;		
		}

		if (NodeToDelete->next != NULL)
		{
			NodeToDelete->next->prev = NodeToDelete->prev;
		}

		if (NodeToDelete->prev != NULL)
		{
			NodeToDelete->prev->next = NodeToDelete->next;
		}			
		delete NodeToDelete; 
		_Size--;
	}

	void DeleteFirstNode()
	{
		if (Head == NULL)
			return;

		Node* FirstNode = Head;
		Head = Head->next;

		if (Head != NULL)
		{
			Head->prev = NULL;
		}
		delete FirstNode;
		_Size--;
	}

	void DeleteLastNode()
	{
		if (Head == NULL)
			return; 

		if (Head->next == NULL)
		{
			delete Head;
			Head = NULL;
			_Size--;
			return;
		}

		Node* PreLastNode = Head;

		while (PreLastNode->next->next != NULL)
		{
			PreLastNode = PreLastNode->next;
		}

		Node* temp = PreLastNode->next;
		PreLastNode->next = NULL;
		delete temp;
		_Size--;

	}

	short Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0); 
	}

	void Clear()
	{
		while (_Size > 0)
		{
			DeleteFirstNode(); 
		}
	}

	void Reverse()
	{
		Node* temp = nullptr; 
		Node* Current = Head;

		while (Current != nullptr)
		{
			temp = Current->prev;
			Current->prev = Current->next;
			Current->next = temp; 

			Current = Current->prev; 
		}

		if (temp != nullptr)
		{
			Head = temp->prev;
		}
	}

	Node* GetNode(short Index)
	{
		if (Index < 0 || Index >= _Size)
		   return NULL;

		short Counter = 0; 
		Node* Current = Head;

		while (Current != NULL)
		{
			if (Counter == Index)
				break; 

			Current = Current->next; 
			Counter++;
		}

		return Current; 
	}

	T GetItem(short Index)
	{
		Node* ItemNode = GetNode(Index); 

		return (ItemNode != NULL) ? ItemNode->value : NULL;
	}

	bool UpdateItem(short Index , T NewValue)
	{
		Node* ItemNode = GetNode(Index); 

		if (ItemNode != NULL)
		{
			ItemNode->value = NewValue;
			return true;
		}

		return false;
	}
	
	bool InsertAfter(short Index , T value)
	{
		Node* ItemNode = GetNode(Index); 

		if (ItemNode != NULL)
		{
			InsertAfter(ItemNode, value);
			return true;
		}
		
		return false;
	}

};

