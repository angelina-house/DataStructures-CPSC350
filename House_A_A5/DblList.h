/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A5

Description: 
Template class for a doubly linked list.
*/

#ifndef DblList_H
#define DblList_H

#include "ListNode.h"
#include <iostream>

//DBLLIST CLASS
template <class Type>
class DblList {
public:
    DblList();
    ~DblList();

    void insertFront(Type d);
    Type removeFront();
    Type removeBack();
    Type deletePos(int pos);
    Type getFront();
    int find(Type value);
    bool isEmpty();
    void insertBack(const Type& d);
    Type& getAt(int index) const;
    void printList();
    unsigned int getSize() const;
    ListNode<Type>* remove(Type key);
    DblList(const DblList& rhs );

    //OPERATOR
    DblList<Type>& operator=(const DblList<Type>& rhs) {
        if (this == &rhs) {
            return *this;
        }
        front = nullptr;
        back = nullptr;
        size = 0;

        ListNode<Type>* current = rhs.front;
        while (current != nullptr) {
            insertBack(current->data);
            current = current->next;
        }
        return *this;
    }

    ListNode<Type> *front;
    ListNode<Type> *back;
    unsigned int size;

    Type& operator[](int index) {
        if (index < 0 || index >= getSize()) {
            throw std::out_of_range("Index out of bounds");
        }
        ListNode<Type> *current = front;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }
};

//CONSTRUCTOR
template <class Type>
DblList<Type>::DblList(const DblList& rhs) {
    front = nullptr;
    back = nullptr;
    size = 0;

    ListNode<Type>* current = rhs.front;
    while (current != nullptr) {
        insertBack(current->data);
        current = current->next;
    }
}


//GET AT
template<class Type>
Type& DblList<Type>::getAt(int index) const {
    if (index < 0 || index >= getSize()) {
        throw std::out_of_range("Index out of bounds");
    }
    ListNode<Type> *current = front;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

//DEFAULT CONSTRUCTOR
template <class Type>
DblList<Type>::DblList() {
    back = nullptr;
    front = nullptr;
    size = 0;
}

//DESTRUCTOR
template <class Type>
DblList<Type>::~DblList() {
    ListNode<Type> *current = front;
    while (current != nullptr) {
        ListNode<Type> *temp = current->next;
        delete current;
        current = temp;
    }
}

//GET SIZE
template <class Type>
unsigned int DblList<Type>::getSize() const {
    return size;
}

//PRINT LIST
template <class Type>
void DblList<Type>::printList() {
    ListNode<Type> *current = front;
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}

//INSERT FRONT
template <class Type>
void DblList<Type>::insertFront(Type d) {
    ListNode<Type> *node = new ListNode<Type>(d);
    if (size == 0) {
        back = node;
    }
    else {
        front->prev = node;
        node->next = front;
    }
    front = node;
    ++size;
}

//INSERT BACK
template <class Type>
void DblList<Type>::insertBack(const Type& d) {
    ListNode<Type> *node = new ListNode<Type>(d);
    if (size == 0) {
        front = node;
    }
    else {
        back->next = node;
        node->prev = back;
    }
    back = node;
    ++size;
}

//REMOVE FRONT
template <class Type>
Type DblList<Type>::removeFront() {
    if (size == 0) {
        throw std::logic_error("List is empty");
    }
    ListNode<Type> *temp = front;
    if (front->next == nullptr) {
        back = nullptr;
    }
    else {
        front->next->prev = nullptr;
    }
    front = front->next;
    temp->next = nullptr;
    Type data = temp->data;
    delete temp;
    --size;
    return data;
}

//REMOVE BACK
template <class Type>
Type DblList<Type>::removeBack() {
    if (size == 0) {
        throw std::logic_error("List is empty");
    }
    ListNode<Type> *temp = back;
    if (back->prev == nullptr) {
        front = nullptr;
    }
    else {
        back->prev->next = nullptr;
    }
    back = back->prev;
    temp->prev = nullptr;
    Type data = temp->data;
    delete temp;
    --size;
    return data;
}

//FIND
template <class Type>
int DblList<Type>::find(Type value) {
    int index = -1;
    ListNode<Type> *current = front;
    while (current != nullptr) {
        ++index;
        if (current->data == value) {
            break;
        }
        else {
            current = current->next;
        }
    }
    if (current == nullptr) {
        index = -1;
    }
    return index;
}

//DELETE POS
template <class Type>
Type DblList<Type>::deletePos(int pos)
{
	--size;
	int index =0;
	ListNode<Type> *curr = front;
	ListNode<Type> *prev = front;
	while (index!=pos) 
	{
		prev = curr;
		curr = curr->next;
		++index;
	}

	prev->next = curr->next;
	curr->next = NULL;
	Type d = curr-> data;
	delete curr;
	return d;

}

//REMOVE
template <class Type>
ListNode<Type>* DblList<Type>::remove(Type key)
{
	ListNode<Type>* current = front;
	while(current->data!=key)
	{
		current = current->next;
		if (current == NULL)
			return NULL;
	}

	if (current == front)
	{
		front = current->next;
	}

	else
	{
		current->prev->next = current->next;
	}

	if(current == back)
	{
		back = current->prev;
	}

	else
	{
		current->next->prev = current->prev;
	}
	current->next = NULL;
	current ->prev = NULL;
	--size;
	return current;
}

//IS EMPTY
template<class Type>
bool DblList<Type>::isEmpty() {
	return this->getSize() == 0;
}

//GET FRONT
template<class Type>
Type DblList<Type>::getFront() {
    if (size == 0) {
        throw std::logic_error("List is empty");
    }
    return front->data;
}



#endif