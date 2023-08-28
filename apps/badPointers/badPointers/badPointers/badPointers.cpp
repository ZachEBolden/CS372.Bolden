//Zachary Bolden
//Showing how ridiculous pointers can be

#include <iostream>

void badPointer1();
void badPointer2();
std::string* allocateString();
void printStuff(const std::string* badString);

int main()
{
	//badPointer1();
	//badPointer2();
	std::string* badString = allocateString();
	printStuff(badString);

	return 1;
}

void badPointer1()
{
	int size = 10000;

	int* badPtr1 = new int[size];//heap array made

	for (int i = 0; i < size; i++)
		badPtr1[i] = i;

	int* badPtr2 = badPtr1;//pointing at heap array

	delete[] badPtr1;//array delete

	for (int i = 0; i < 10; i++)
		std::cout << badPtr2[i] << " ";//prints out junk data'
	std::cout << std::endl;
}

void badPointer2()
{
	int size = 10000;

	int* badArr = new int[size];//array made on heap

	for (int i = 0; i < size; i++)
		badArr[i] = i;

	int* badPtr1 = badArr;//first pointer pointing at array
	int* badPtr2 = badArr;//second pointer pointing at array

	delete badPtr1;//deleting the first pointer

	std::cout << "Address of second pointer = " << *badPtr2 << std::endl;

	for (int i = 0; i < 10; i++)
		std::cout << badPtr2[i] << " ";//prints junk data

	std::cout << std::endl;	
}

std::string* allocateString()
{
	std::string* badString = new std::string("abcdefghijkl");

	return badString;
}

void printStuff(const std::string* badString)
{
	std::cout << *badString << std::endl;
}