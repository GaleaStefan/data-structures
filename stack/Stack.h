#pragma once

#include "../list/LinkedList.h"

template<class Type>
class Stack
{
protected:
	//int m_top;

public:
	Stack();
	Stack(int defaultTop);

	virtual void push(Type data) = 0;
	virtual void pop() = 0;
	virtual Type top() const = 0;
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual void clear() = 0;
};

template<class Type>
Stack<Type>::Stack()
{
	//m_top = -1;
}

template<class Type>
Stack<Type>::Stack(int defaultTop)
{
	//m_top = defaultTop;
}