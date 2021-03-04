#include "list/LinkedList.h"
#include "stack/ArrayStack.h"
#include <iostream>

int main()
{
	ArrayStack<int> aStack;
	aStack.push(5);
	aStack.pop();
	aStack.push(3);
	std::cout << aStack.top() << "\n";
	std::cout << aStack.empty() << "\n";
	
	aStack.clear();

	LinkedList<int> test;

	test.insert(0, 3);
	test.insert(1, 2);
	test.insert(1, 5);
	test.insert(2, 7);

	for (int i = 0; i < test.getSize(); i++)
	{
		std::cout << test[i] << " ";
	}
}