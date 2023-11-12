/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A3

Description: 
Creates monostack data structure.

*/

#ifndef MONOSTACK_H
#define MONOSTACK_H

template <typename T>

// Creates monoStack class
class monoStack {
    public:
        monoStack(int s, char a); // s = size, a = type
        virtual ~monoStack();
        void push(T x);
        T pop();
        T peek();
        bool isFull();
        bool isEmpty();
        int size();

    private:
        T* stackArr;
        char stackType;
        int count;
        int maxSize;
        int top;

};

template <typename T>
monoStack<T>::monoStack(int s, char a) {
    stackArr = new T[s];
    stackType = a;
    count = 0;
    maxSize = s;
    top = -1;
}

template <typename T>
monoStack<T>::~monoStack() {
    delete [] stackArr;
}

template <typename T>
bool monoStack<T>::isFull(){
    return (count == maxSize);
}

template <typename T>
bool monoStack<T>::isEmpty(){
    return (count == 0);
}

template <typename T>
int monoStack<T>::size(){
    return count;
}

// Pushes element onto stack, accounts for array size
template <typename T>
void monoStack<T>::push(T x) {
    if (isFull()) {
        T* temp = new T[maxSize*2];
        for (int i = 0; i < maxSize; i++) {
            temp[i] = stackArr[i];
        }
        maxSize *= 2;
        delete [] stackArr;
        stackArr = temp;
    } 

    if (stackType == 'd'){
        while(!isEmpty() && stackArr[top] < x) {
            pop();
        }
        stackArr[++top] = x;
        count++;
    } else if (stackType == 'i'){
        while(!isEmpty() && stackArr[top] > x) {
            pop();
        }
        stackArr[++top] = x;
        count++;
    }
}

template <typename T>
T monoStack<T>::pop() {
    if (isEmpty()) {
        return -1;
    } else {
        count--;
        return stackArr[top--];
    }
}

template <typename T>
T monoStack<T>::peek() {
    if (isEmpty()) {
        return -1;
    } else {
        return stackArr[top];
    }
}


#endif 