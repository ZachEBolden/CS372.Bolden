// MyList.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <functional>

template <typename T>
class MyList 
{
private:
	class Node 
	{
	public:
		T data;
		Node* prev;
		Node* next;
		bool isHiddenNode = false;
	};
	Node* head;
	Node* tail;
	void deleteListContents()
	{

		Node* current = head;
		Node* temp = nullptr;
		while (current != nullptr) {
			temp = current->next;
			delete current;
			current = temp;
		}

	}
	void setupList()
	{
		Node* newNode = new Node();
		newNode->next = nullptr;
		newNode->prev = nullptr;
		head = newNode;
		tail = newNode;
	}
public:
    MyList()
	{
		setupList();
	}
    MyList(T newData)
	{
		setupList();
		head->data = newData;
	}
    MyList(MyList& rhs)
	{
		deleteListContents();
		head = rhs.head;
		tail = rhs.tail;
	}
	~MyList()
	{
		deleteListContents();
	}
    bool  empty()
    {
        return head == nullptr;
    }
    void push_front(T data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        newNode->prev = nullptr;
        head->prev = newNode;
        head = newNode;
    }
    void push_back(T data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    T front()
    {
        return head->data;
    }
    T back()
    {
        return tail->data;
    }
    void pop_back()
    {
        Node* lastNode = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete lastNode;


    }
    void pop_front()
    {
        Node* firstNode = head;
        head = head->next;
        head->prev = nullptr;
        delete firstNode;
    }

	void traverse(std::function<void(T& data)> doIt) {
		Node* current = head->next;
		while (current != tail) {
			doIt(current->data);
			current = current->next;
		}
	}
};