// myList.cpp : Defines the entry point for the application.
//

#include "myList.h"

using namespace std;

template<typename T>
void printData(T data) {
	std::cout << data << " ";
}

int main()
{
	MyList<int> testList;

    if (testList.empty()) {
        std::cout << "List is empty" << std::endl;
    }

    testList.push_back(10);
    testList.push_back(20);
    testList.push_front(5);

    std::cout << "Front: " << testList.front() << std::endl;
    std::cout << "Back: " << testList.back() << std::endl;


    testList.traverse(printData<int>);
    std::cout << std::endl;

    testList.pop_front();
    testList.pop_back();

    if (testList.empty()) {
        std::cout << "List is empty" << std::endl;
    }

    return 0;
}
