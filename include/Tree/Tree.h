#pragma once
#include <memory>
#include<functional>
#include<queue>
#include <iostream>

template<typename V>
class Tree {
private:
    struct Node
    {
        Node(V v, std::shared_ptr<Node>& l, std::shared_ptr<Node>& r) :
            value(v), left(l), right(r) {}
        V value;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;
    };
    explicit Tree(std::shared_ptr<Node>& node) : root(node) {}
    std::shared_ptr<Node> root;
public:
    Tree() {}
    Tree(Tree const& lft, V value, Tree const& rgt) :
        root(Node(value, lft->root, rgt->root)) {}

    bool isEmpty() const { return !root };
    V root() const { return root->val };
    Tree& left() const { return root->left };
    Tree& right() const { return root->right };

    bool member(V x) const 
    {
        if (isEmpty())
            return false;
        V y = root();
        if (x < y)
            return left().member(x);
        else if (y < x)
            return right().member(x);
        else
            return true;
    }

    //used https://stackoverflow.com/questions/34249476/in-binary-tree-checking-if-given-node-is-leaf-node-or-not
    //for help on how to build this
    bool isLeaf() const
    {
        if (isEmpty())
            return false;
        V y = root();
        if (left() == nullptr && right() == nullptr)
            return true;
        else if (x < y)
            return isLeaf(right());
        else
            return isLeaf(left());
    }

    Tree insert(V x) const {
        if (isEmpty())
            return Tree(Tree(), x, Tree());
        V y = root();
        if (x < y)
            return Tree(left().insert(x), y, right());
        else if (y < x)
            return Tree(left(), y, right().insert(x));
        else
            return *this; 
    }

    void preorder(std::function<void(V)> visit) const 
    {
        if (isEmpty())
            return;
        V contents = root();
        visit(contents);
        left().preorder(visit);
        right().preorder(visit);
    }

    void inorder(std::function<void(V)> visit) const 
    {
        if (isEmpty()) return;
        left().inorder(visit);
        V contents = root();
        visit(contents);
        right().inorder(visit);
    }

    void postorder(std::function<void(V)> visit) const 
    {
        if (isEmpty()) return;
        left().postorder(visit);
        right().postorder(visit);
        V contents = root();
        visit(contents);
    }

    //used https://www.geeksforgeeks.org/deletion-in-binary-search-tree/
    //for help
    Node Delete(V x)
    {
        if (isEmpty())
        {
            return false;
        }

        V y = root();
        if (x < y)
        {
            return left().Delete(x);
        }
        else if (x > y)
        {
            return right().Delete(x);
        }
        else
        {
            if (left() == nullptr)
            {
                shared_ptr<Node> temp = root().right();
                delete root;
                return temp;

            }
            else if (right() == nullptr)
            {

                shared_ptr<Node> temp = root().left();
                delete root;
                return temp;
            }
            else
            {

                std::shared_ptr<Node> tempParen = root();
                shared_ptr<Node> temp = root().right();

                while (temp.left() != nullptr)
                {
                    tempParen = temp;
                    temp = temp.left();
                }

                if (tempParen != root())
                {
                    tempParen.left() = temp.right();
                }
                else
                {
                    tempParen.right() = temp.right();
                }
                root = temp;

                delete temp;

                return root;

            }
        }
    }
};