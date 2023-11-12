/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A4

Description: 
ListNode class. Creates a node for a doubly linked list. From class.
*/
#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <cstdlib>
#include <iostream>
using namespace std;

template <typename T>
class ListNode{
    public:
    ListNode(T data);
    virtual ~ListNode();

    template <typename S>
    friend class DblList;

    private:
    T m_data;
    ListNode<T>* m_next;
    ListNode<T>* m_prev;
};

template <typename T>
ListNode<T>::ListNode(T data){
    m_data = data;
    m_next = NULL;
    m_prev = NULL;
}
template <typename T>
ListNode<T>::~ListNode(){
    m_next = NULL;
    m_prev = NULL;
}

#endif