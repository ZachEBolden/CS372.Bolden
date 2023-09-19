//Midterm Q1
//Zachary Bolden
//Using https://www.geeksforgeeks.org/search-an-element-in-a-linked-list-iterative-and-recursive/
// for searching the linked list

#include "AdjustingList.h"

int main()
{
	AdjustingList<int> testList;
	int search;

	testList.push_front(1);
	testList.push_front(2);
	testList.push_front(3);
	testList.push_front(4);
	testList.push_front(5);
	testList.push_front(6);
	testList.push_front(7);
	testList.push_front(8);
	testList.push_front(9);

	std::cout << "Please enter your search request" << std::endl;
	std::cin >> search;

	testList.find(search);


}