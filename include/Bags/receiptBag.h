#pragma once

#include <iostream>
#include "../myVector/myVector/myVector.h"
#include <algorithm>

//received help from Joseph Gentry

template <typename Thing>
class ReceiptBag {
private:
    struct Item
    {
        Thing value;
        int receipt;
    };


    myVector<Item> bagVector;
    int nextReceipt;

public:
    ReceiptBag() : nextReceipt(1) {}

    int insert( Thing aThing)
    {
        int receipt = nextReceipt++;
        bagVector.push_back({ aThing, receipt });
        return receipt;
    }

    Thing& remove(int receipt)
    {
        auto iter = std::find_if(bagVector.begin(), bagVector.end(),
            [receipt](const Item& item) { return item.receipt == receipt; });

        if (iter == bagVector.end())
        {
            throw std::runtime_error("This in not in the bag bro!");
        }

        Thing& removeItem = iter->value;
        bagVector.erase(iter);
        return removeItem;
    }

    int size() const 
    {
        return bagVector.size();
    }

    int count(const Thing& aThing) const 
    {
        int count = 0;
        for (const auto& item : bagVector) {
            if (isSameThing(item.value, aThing)) {
                count++;
            }
        }
        return count;
    }

};