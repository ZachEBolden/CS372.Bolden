//
// File:   bag.h
// Author: Your Glorious Instructor
// Purpose:
// Implement the Bag ADT.
//
#pragma once
#include <iostream>
#include "vector.hpp"

template <typename Thing>
class Bag 
{
public:

    ReceiptBag() : nextReceipt(1) {}//received help from Jo Gentry
    void insert(Thing aThing) 
    {
        bagContents.push_back(aThing);
        bagSize++;
    }

    Thing& remove(int receipt)//received help from Jo Gentry
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

    //Thing &pop() 
    //{
    //    Thing aThing;
    //   if (bagContents.size() > 0) 
    //    {
    //        aThing = bagContents[bagSize];
    //        bagSize--;
    //    }
    //    else 
    //   {
    //       std::cerr << "Can't pop out of an empty bag" << std::endl;
    //    }
    //    return aThing;
   // }
    int size() 
    {
        return bagSize;
    }
    int count(Thing aThing) 
    {
        int bagCount = 0;
        for (int i = 0 ; i < bagSize; i++) 
        {
            if (bagContents[i] == aThing) 
            {
                bagCount++;
            }
        }
        return bagCount;
    }
private:

    struct Item
    {
        Thing value;
        int receipt;
    };
    std::vector<Item> bagVector;
    int bagSize = 0;
    int nextReceipt;
};
