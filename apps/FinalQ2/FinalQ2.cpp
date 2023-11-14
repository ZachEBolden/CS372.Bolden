#include <list>
#include <iostream>

//used https://stackoverflow.com/questions/71121818/how-to-write-partition-for-quicksort-with-c for inspiration

template <typename T>
void partitionList(const T& splittingValue, const std::list<T>& inputList, std::list<T>* lessList, std::list<T>* greaterList) 
{
    for (const auto& value : inputList) 
    {
        if (value < splittingValue) 
        {
            lessList->push_back(value);
        }
        else if (value > splittingValue) 
        {
            greaterList->push_back(value);
        }
    }
}

template <typename T>
std::list<T>* quicksort(const std::list<T>& inputList) 
{
    if (inputList.size() <= 1) {
        return new std::list<T>(inputList);
    }

    auto pivotIter = std::next(inputList.begin(), inputList.size() / 2);
    T pivotValue = *pivotIter;

    std::list<T> lessList, greaterList;
    partitionList(pivotValue, inputList, &lessList, &greaterList);

    std::list<T>* sortedLess = quicksort(lessList);
    std::list<T>* sortedGreater = quicksort(greaterList);

    std::list<T>* result = new std::list<T>();
    result->insert(result->end(), sortedLess->begin(), sortedLess->end());
    result->push_back(pivotValue);  
    result->insert(result->end(), sortedGreater->begin(), sortedGreater->end());

    delete sortedLess;
    delete sortedGreater;

    return result;
}

int main()
{
std::list<int> inputList = { 5, 2, 8, 1, 6, 3, 7, 4 };

std::list<int>* sortedList = quicksort(inputList);

std::cout << "Sorted list: ";
for (const auto& value : *sortedList) {
    std::cout << value << " ";
}
std::cout << std::endl;

delete sortedList;

return 0;
}