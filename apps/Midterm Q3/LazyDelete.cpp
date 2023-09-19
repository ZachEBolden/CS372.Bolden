//Midterm Q3
//Zachary Bolden

#include "LazyList.h"

int main()
{
	LazyList<int> testList;

    testList.push_back(1);
    testList.push_back(2);
    testList.push_back(3);
    testList.push_back(4);
    testList.push_back(5);


    testList.markNodeAsDeleted(testList.head->next);
    testList.markNodeAsDeleted(testList.tail);


    testList.traverse([](int data)
        {
            std::cout << data << " ";
        });
    std::cout << std::endl;


    testList.deleteAllDeletedNodes();

    testList.traverse([](int data)
        {
            std::cout << data << " ";
        });
    std::cout << std::endl;

    std::cout << testList.itemCount << std::endl;
    std::cout << testList.deletedCount << std::endl;

    return 0;
}