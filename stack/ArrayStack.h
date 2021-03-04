#pragma once

#include "Stack.h"
#include <vector>
#include <stdexcept>

template <class Type>
class ArrayStack : public Stack<Type> {
private:
	std::vector<Type> m_elements;
	int m_top;
public:
	ArrayStack();
	ArrayStack(const ArrayStack<Type>& other);

	void push(Type data) override;
	void pop() override;
	Type top() const override;
	void clear() override;
	int size() const override;
	bool empty() const override;
};

template <class Type>
ArrayStack<Type>::ArrayStack() {
	this->m_top = -1;
}

template <class Type>
ArrayStack<Type>::ArrayStack(const ArrayStack<Type>& other)
{
	this->m_top = other.m_top;
	this->m_elements = other.m_elements;
}

template <class Type>
void ArrayStack<Type>::push(Type element)
{
	this->m_elements.push_back(element);
	this->m_top++;
}

template <class Type>
void ArrayStack<Type>::pop()
{
	if (this->m_top == -1)
	{
		throw new std::underflow_error("The stack is empty");
	}

	this->m_elements.erase(this->m_elements.end() - 1);
	this->m_top--;
}

template <class Type>
Type ArrayStack<Type>::top() const
{
	if (this->m_top == -1)
	{
		throw new std::underflow_error("The stack is empty");
	}

	return this->m_elements[this->m_top];
}

template <class Type>
void ArrayStack<Type>::clear()
{
	this->m_top = -1;
	this->m_elements.clear();
}

template <class Type>
int ArrayStack<Type>::size() const
{
	return this->m_elements.size();
}

template <class Type>
bool ArrayStack<Type>::empty() const
{
	return (this->m_top == -1);
}