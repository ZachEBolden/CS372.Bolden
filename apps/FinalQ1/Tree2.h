#include <iostream>

using namespace std;

class Tree {
public:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int data) : data(data), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Tree() : root(nullptr) {}

    void insert(int data) {
        root = insertRec(root, data);
    }

private:
    Node* insertRec(Node* root, int data) {
        if (root == nullptr) {
            return new Node(data);
        }

        if (data < root->data) {
            root->left = insertRec(root->left, data);
        }
        else if (data > root->data) {
            root->right = insertRec(root->right, data);
        }

        return root;
    }
};