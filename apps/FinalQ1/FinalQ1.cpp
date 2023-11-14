//Help me. The trees are surrounding me.

#include "../../include/Tree/Tree.h"
template <typename T>
int countNodes(Tree<T>);

template <typename T>
void countInternals(const std::shared_ptr<typename Tree<T>::Node>&);

template <typename T>
void treeSum(const std::shared_ptr<typename Tree<T>::Node>&);

int main()
{
    int count;
    Tree<int> myTree;
    myTree.insert(4);
    myTree.insert(2);
    myTree.insert(6);
    myTree.insert(1);
    myTree.insert(3);
    myTree.insert(5);
    myTree.insert(7);

    count = countNodes(myTree);
}
template <typename T>
int countNodes(Tree<T> current) {
    if (current == nullptr) {
        return 0;
    }

    int leftCount = countNodes(current->left);
    int rightCount = countNodes(current->right);

    return 1 + leftCount + rightCount;
}

//template <typename T>
//void countInternals(const std::shared_ptr<typename Tree<T>::Node>& )
//{

//}

//template <typename T>
//void treeSum(const std::shared_ptr<typename Tree<T>::Node>&,)
//{

//}