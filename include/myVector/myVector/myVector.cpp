// myVector.cpp : Defines the entry point for the application.
//

#include "myVector.h"

int main()
{
	myVector<int> testMyVector;

	for (int i = 0; i < 10; i++)
	{
		std::cout << "Vector size: " << testMyVector.size() << std::endl;
		std::cout << "Vector capacity: " << testMyVector.capacity() << std::endl;
			testMyVector.push_back(i);
	}
		

	testMyVector.traverse();
	std::cout << std::endl;

}