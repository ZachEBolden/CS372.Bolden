// ListBag.h : Include file for standard system include files,
// or project specific include files.

#pragma once

//got help from Jo Gentry

#include <iostream>
#include "../myList/myList.h"

template <typename Thing>
class ReceiptBag {
private:
    struct Item {
        Thing value;
        int receipt;
        typename MyList<Item>::Node* node;
    };

    MyList<Item> bagList;
    int nextReceipt;

public:
    ReceiptBag() : nextReceipt(1) {}

    int insert(const Thing& aThing) {
        int receipt = nextReceipt++;
        typename MyList<Item>::Node* newNode = new typename MyList<Item>::Node();
        newNode->data = { aThing, receipt, newNode };
        bagList.push_back(newNode);
        return receipt;
    }

    Thing& remove(int receipt) {
        typename MyList<Item>::Node* curr = bagList.front();
        while (curr != nullptr && curr->data.receipt != receipt) {
            curr = curr->next;
        }

        if (curr == nullptr) {
            throw std::runtime_error("This is not in the bag!");
        }

        Thing& removeItem = curr->data.value;
        bagList.pop_node(curr);
        return removeItem;
    }

    int size() const {
        int count = 0;
        bagList.traverse([&](const typename MyList<Item>::Node* node) {
            count++;
            });
        return count;
    }

    bool isSameThing(const Thing& a, const Thing& b) const {
        return (a == b);
    }

    int count(const Thing& aThing) const {
        int count = 0;
        bagList.traverse([&](const typename MyList<Item>::Node* node) {
            if (isSameThing(node->data.value, aThing)) {
                count++;
            }
            });
        return count;
    }
};