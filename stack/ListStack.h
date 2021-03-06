#pragma once

#include "Stack.h"
#include "../list/LinkedList.h"

template <class Type>
class ListStack : public Stack<Type>
{
private:
	LinkedList<Type> m_elements;

public:
	ListStack();

	void push(Type element) override;
	void pop() override;
	Type top() const override;
	bool empty() const override;
	int size() const override;
	void clear() override;
};

template <class Type>
ListStack<Type>::ListStack()
{
	m_elements = LinkedList<Type>();
}

template <class Type>
void ListStack<Type>::push(Type element)
{
	this->m_elements.pushLeft(element);
}

template <class Type>
void ListStack<Type>::pop()
{
	this->m_elements.erase(0);
}

template <class Type>
Type ListStack<Type>::top() const
{
	return this->m_elements[0];
}

template <class Type>
bool ListStack<Type>::empty() const
{
	return (this->m_elements.getSize() == 0);
}

template <class Type>
int ListStack<Type>::size() const
{
	return this->m_elements.getSize();
}

template <class Type>
void ListStack<Type>::clear()
{
	this->m_elements.clear();
}