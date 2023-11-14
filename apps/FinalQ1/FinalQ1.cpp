//Help me. The trees are surrounding me.

#include "tree2.h"


int countNodes(Tree::Node* root);

int countInternals(Tree::Node* root);

void treeSum(Tree::Node* root, int& sum);

int main()
{
    int nodeCount,internalCount, extPath=0;
    Tree myTree;
    myTree.insert(4);
    myTree.insert(2);
    myTree.insert(6);
    myTree.insert(1);
    myTree.insert(3);
    myTree.insert(5);
    myTree.insert(7);

    nodeCount = countNodes(myTree.root);

    internalCount = countInternals(myTree.root);

    treeSum(myTree.root, extPath);
    cout << "External path length of the tree: " << extPath << endl;
}

int countNodes(Tree::Node* root) {
    if (root == nullptr) {
        return 0;
    }
    else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}


int countInternals(Tree::Node* root)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return 0;
    }
    else {
        return 1 + countInternals(root->left) + countInternals(root->right);
    }
}

void treeSum(Tree::Node* root, int& sum)
{
    if (root == nullptr) {
        return;
    }
    else if (root->left == nullptr && root->right == nullptr) {
        sum += 1;
    }
    else {
        sum += 1;
        treeSum(root->left, sum);
        treeSum(root->right, sum);
    }
}