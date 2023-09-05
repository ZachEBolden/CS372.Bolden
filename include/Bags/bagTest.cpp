//testing bag and receipts
//Zachary Bolden

#include "receiptBag.h"

int main()
{
    ReceiptBag<int> testBag;

    int receipt1 = testBag.insert(10);
    int receipt2 = testBag.insert(20);
    int receipt3 = testBag.insert(10);

    std::cout << "Size: " << testBag.size() << std::endl; // Output: Size: 3

    testBag.remove(receipt2);

    std::cout << "Size: " << testBag.size() << std::endl; // Output: Size: 2

    int count = testBag.count(10);
    std::cout << "Count: " << count << std::endl; // Output: Count: 2

    return 0;
}