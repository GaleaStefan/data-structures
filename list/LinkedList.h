#pragma once

#include <stdexcept>

template <class Type>
class LinkedList
{
private:
	class Node
	{
	private:
		Node* mp_next;
		Type m_data;
	public:
		Node();
		Node(Type _data);

		Type getData() const;
		Type& getDataAddress();
		void setData(Type m_data);

		Node* getNext() const;
		void setNext(Node*);
	};

	Node* mp_first;
	Node* mp_last;
	unsigned m_size;

	Node* jump(unsigned steps) const;
public:
	LinkedList();
	LinkedList(const LinkedList<Type>& other);
	~LinkedList();

	void pushLeft(Type _data);
	void pushRight(Type _data);

	int getSize() const;

	void clear();

	int indexOf(Type m_data) const;
	void insert(unsigned index, Type m_data);
	void erase(unsigned index);

	Type& operator[](unsigned index) const;
	LinkedList<Type>& operator=(const LinkedList<Type>& other);
};

template <class Type>
LinkedList<Type>::LinkedList() : mp_first(nullptr), mp_last(nullptr), m_size(0)
{

}

template <class Type>
LinkedList<Type>::LinkedList(const LinkedList<Type>& other)
{
	m_size = 0;

	if (other.m_size == 0)
	{
		mp_first = nullptr;
		mp_last = nullptr;
	}
	else
	{
		Node* current = other.mp_first;

		while (current != nullptr)
		{
			pushRight(current->getData());
			current = current->getNext();
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
	Node* current = mp_first;

	while (current != nullptr)
	{
		Node* mp_next = current->getNext();
		delete current;

		current = mp_next;
	}

	mp_first = nullptr;
	mp_last = nullptr;
	m_size = 0;
}

template <class Type>
void LinkedList<Type>::pushRight(Type info)
{
	Node* toPush = new Node(info);

	if (m_size == 0)
	{
		mp_first = toPush;
		mp_last = toPush;
	}
	else
	{
		mp_last->setNext(toPush);
		mp_last = mp_last->getNext();

		mp_last->setNext(nullptr);
	}

	m_size++;
}

template <class Type>
void LinkedList<Type>::pushLeft(Type info)
{
	Node* node = new Node(info);

	if (mp_first == nullptr)
	{
		mp_first = node;
		mp_last = node;
	}
	else
	{
		node->setNext(mp_first);
		mp_first = node;
	}

	m_size++;
}

template <class Type>
int LinkedList<Type>::getSize() const
{
	return m_size;
}

template <class Type>
int LinkedList<Type>::indexOf(Type _data) const
{
	unsigned index = 0;

	Node* current = mp_first;

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
	unsigned jumps = 0;
	Node* node = mp_first;

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

	return nullptr;
}

template <class Type>
Type& LinkedList<Type>::operator[](unsigned index) const
{
	Node* atIndex = jump(index);

	return atIndex->getDataAddress();
}

template <class Type>
LinkedList<Type>& LinkedList<Type>::operator=(const LinkedList<Type>& other)
{
	if (this == &other)
	{
		return *this;
	}

	if (this->m_size)
	{
		this->clear();
	}

	this->m_size = 0;
	this->mp_first = nullptr;
	this->mp_last = nullptr;

	if (other.m_size == 0)
	{
		return *this;
	}

	Node* current = other.mp_first;

	while (current != nullptr)
	{
		this->pushRight(current->getData());
		current = current->getNext();
	}

	return *this;
}

template <class Type>
void LinkedList<Type>::erase(unsigned index)
{
	if (m_size <= index || m_size == 0)
	{
		throw std::out_of_range("List out of range");
	}

	if (m_size == 1)
	{
		delete mp_first;
		delete mp_last;

		mp_first = nullptr;
		mp_last = nullptr;
		m_size = 0;
		return;
	}

	if (index == 0)
	{
		Node* aux = mp_first->getNext();
		delete mp_first;

		mp_first = aux;
		m_size--;
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
		mp_last = before;
	}
	else
	{
		before->setNext(after);
	}

	m_size--;
}

template <class Type>
void LinkedList<Type>::insert(unsigned index, Type m_data)
{
	if (index > m_size)
	{
		throw std::out_of_range("Insert index exceeded the end of the list");
	}

	if (m_size == 0 || index == 0)
	{
		pushLeft(m_data);
		return;
	}

	if (index == m_size)
	{
		pushRight(m_data);
		return;
	}


	Node* newNode = new Node(m_data);
	Node* before = jump(index - 1);
	Node* after = before->getNext();

	before->setNext(newNode);
	newNode->setNext(after);
	
	m_size++;
}

template <class Type>
LinkedList<Type>::Node::Node()
{
	mp_next = nullptr;
}

template <class Type>
LinkedList<Type>::Node::Node(Type _data)
{
	m_data = _data;
	mp_next = nullptr;
}

template <class Type>
Type LinkedList<Type>::Node::getData() const
{
	return m_data;
}

template <class Type>
void LinkedList<Type>::Node::setData(Type _data)
{
	m_data = _data;
}

template <class Type>
typename LinkedList<Type>::Node* LinkedList<Type>::Node::getNext() const
{
	return mp_next;
}

template <class Type>
void LinkedList<Type>::Node::setNext(Node* _next)
{
	mp_next = _next;
}

template <class Type>
Type& LinkedList<Type>::Node::getDataAddress()
{
	return m_data;
}