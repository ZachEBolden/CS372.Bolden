// BinSearch.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <vector>

template <typename T>
bool binarySearch(std::vector<T> aSortedVector, T itemToBeFound, bool printDebugData = false);

int main()
{
	std::vector<int> testVec;
	bool printData = true, found = false;

	for (int i = 0; i < 100; i++)
		testVec[i] = i;

	found = binarySearch(testVec, 5, printData);

	if (found)
		std::cout << "Ladies and Gentlement, we got him." << std::endl;
	else
		std::cout << "No life detected" << std::endl;

	return 0;
}

//https://stackoverflow.com/questions/18774858/using-binary-search-with-vectors
//using this for search
template <typename T>
bool binarySearch(std::vector<T> aSortedVector, T itemToBeFound, bool printDebugData)
{
	size_t middle, start = 0;
	size_t end = aSortedVector.size();

	if (printDebugData)
	{
		std::cout << "Vector has " << aSortedVector.size() << " elements to search" << std::endl;
	}

	while (start < end)
	{
		middle = start + ((end - start) / 2);
		if (itemToBeFound > aSortedVector[middle])
			start = middle + 1;
		else if (itemToBeFound > aSortedVector[middle])
			end = middle;
		else
			return true;
	}

	return false;
}