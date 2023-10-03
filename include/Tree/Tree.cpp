// Tree.cpp : Defines the entry point for the application.
//

#include "Tree.h"

//Got help from Jo Gentry. Also super confused by tree implementation.

template<typename T>
Tree<T> prune(const Tree<T>& tree);

int main()
{
    Tree<int> myTree;
    myTree.insert(5);
    myTree.insert(4);
    myTree.insert(6);
    myTree.insert(1);
    myTree.insert(3);
    myTree.insert(5);
    myTree.insert(8);

    Tree<int> prunedTree = prune(myTree);
}

template<typename T>
Tree<T> prune(const Tree<T>& tree) {
    Tree<T> prunedTree;
    prunedTree.root = pruneNode<T>(tree.root);
    return prunedTree;
}

template<typename T>
Tree<T> pruneNode(const std::shared_ptr<typename Tree<T>::Node>& node) {
    if (node == nullptr) {
        return nullptr;
    }
    else if (node->left == nullptr && node->right == nullptr) {
        return nullptr;
    }
    else {
        node->left = pruneNode<T>(node->left);
        node->right = pruneNode<T>(node->right);
        return node;
    }
}