// SmartList.cpp : Defines the entry point for the application.
//

//Received help from Jo Gentry

#include "SmartList.h"

void printData(int data) {
    std::cout << data << " ";
}

int main() {
    // Create a List object
    SmartList<int> testList;

    // Test push_front and push_back
    testList.push_front(1);
    testList.push_front(2);
    testList.push_back(3);
    testList.push_back(4);

    // Test traverse
    std::cout << "Traverse: ";
    testList.traverse(printData);
    std::cout << std::endl;

    // Test front and back
    std::cout << "Front: " << testList.front() << std::endl;
    std::cout << "Back: " << testList.back() << std::endl;

    // Test pop_front and pop_back
    testList.pop_front();
    testList.pop_back();

    // Test traverse after removal
    std::cout << "Traverse after removal: ";
    testList.traverse(printData);
    std::cout << std::endl;

    // Test empty
    std::cout << "Is empty? " << (testList.empty() ? "Yes" : "No") << std::endl;

    return 0;
}