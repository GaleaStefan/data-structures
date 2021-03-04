#pragma once

#include <stdexcept>

template <class Type>
class LinkedList
{
private:
	class Node
	{
	private:
		Node* next;
		Type data;
	public:
		Node();
		Node(Type _data);

		Type getData() const;
		Type& getDataAddress();
		void setData(Type data);

		Node* getNext() const;
		void setNext(Node*);
	};

	Node* first;
	Node* last;
	int size;

	Node* jump(unsigned steps) const;
public:
	LinkedList();
	LinkedList(const LinkedList<Type>& other);
	~LinkedList();

	void pushLeft(Type _data);
	void pushRight(Type _data);

	int getSize() const;

	void clear();

	int indexOf(Type data) const;
	Type& operator[](unsigned index) const;
	void erase(unsigned index);
};

template <class Type>
LinkedList<Type>::LinkedList() : first(nullptr), last(nullptr), size(0)
{

}

template <class Type>
LinkedList<Type>::LinkedList(const LinkedList<Type>& other)
{
	size = other.size;

	if (size == 0)
	{
		first = nullptr;
		last = nullptr;
	}
	else
	{
		Node* current = other.first;

		while (current != nullptr)
		{
			pushRight(current.data);
			current = current->next;
		}
	}
}

template <class Type>
LinkedList<Type>::~LinkedList()
{
	clear();
}

template <class Type>
void LinkedList<Type>::clear()
{
	Node* current = first;

	while (current != nullptr)
	{
		Node* next = current->getNext();
		delete current;

		current = next;
	}

	first = nullptr;
	last = nullptr;
	size = 0;
}

template <class Type>
void LinkedList<Type>::pushRight(Type info)
{
	Node* toPush = new Node(info);

	if (size == 0)
	{
		first = toPush;
		last = toPush;
	}
	else
	{
		last->setNext(toPush);
		last = last->getNext();

		last->setNext(nullptr);
	}

	size++;
}

template <class Type>
void LinkedList<Type>::pushLeft(Type info)
{
	Node* node = new Node(info);

	if (first == nullptr)
	{
		first = node;
		last = node;
	}
	else
	{
		node->setNext(first);
		first = node;
	}

	size++;
}

template <class Type>
int LinkedList<Type>::getSize() const
{
	return size;
}

template <class Type>
int LinkedList<Type>::indexOf(Type _data) const
{
	unsigned index = 0;

	Node* current = first;

	while (current != nullptr)
	{
		if (current->getData() == _data)
		{
			return index;
		}

		index++;
		current = current->getNext();
	}

	return -1;
}

template <class Type>
typename LinkedList<Type>::Node* LinkedList<Type>::jump(unsigned steps) const
{
	int jumps = 0;
	Node* node = first;

	while (jumps <= steps)
	{
		if (node == nullptr)
		{
			throw std::out_of_range("List out of range");
		}

		if (jumps == steps)
		{
			return node;
		}

		jumps++;
		node = node->getNext();
	}
}

template <class Type>
Type& LinkedList<Type>::operator[](unsigned index) const
{
	Node* atIndex = jump(index);

	return atIndex->getDataAddress();
}

template <class Type>
void LinkedList<Type>::erase(unsigned index)
{
	if (size <= index || size == 0)
	{
		throw std::out_of_range("List out of range");
	}

	if (size == 1)
	{
		delete first;
		delete last;

		first = nullptr;
		last = nullptr;
		size = 0;
		return;
	}

	if (index == 0)
	{
		Node* aux = first->getNext();
		delete first;

		first = aux;
		size--;
		return;
	}

	Node* before = jump(index - 1);
	Node* toErase = before->getNext();
	Node* after = toErase->getNext();

	delete toErase;

	// Erasing the last node
	if (after == nullptr)
	{
		before->setNext(nullptr);
		last = before;
	}
	else
	{
		before->setNext(after);
	}

	size--;
}

template <class Type>
LinkedList<Type>::Node::Node()
{
	next = nullptr;
}

template <class Type>
LinkedList<Type>::Node::Node(Type _data)
{
	data = _data;
	next = nullptr;
}

template <class Type>
Type LinkedList<Type>::Node::getData() const
{
	return data;
}

template <class Type>
void LinkedList<Type>::Node::setData(Type _data)
{
	data = _data;
}

template <class Type>
typename LinkedList<Type>::Node* LinkedList<Type>::Node::getNext() const
{
	return next;
}

template <class Type>
void LinkedList<Type>::Node::setNext(Node* _next)
{
	next = _next;
}

template <class Type>
Type& LinkedList<Type>::Node::getDataAddress()
{
	return data;
}