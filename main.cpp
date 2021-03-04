#include "LinkedList.h"
#include <iostream>

int main()
{
	LinkedList<int> test;

	test.pushRight(2);
	test.pushRight(1);
	test.pushRight(3);
	test.pushRight(5);

	test.erase(2);

	for (int i = 0; i < test.getSize(); i++)
	{
		std::cout << test[i] << " ";
	}
}