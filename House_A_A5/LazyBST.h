/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A5

Description: 
Template class for  lazy binary search tree.
*/

#ifndef LazyBST_H
#define LazyBST_H

#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

//TREE NODE CLASS
template<class T>
class TreeNode {
public:
    TreeNode();
    TreeNode(T data);
    virtual ~TreeNode();
    TreeNode(const TreeNode& other); // copy constructor
    TreeNode& operator=(const TreeNode& other);
    T getValue();
    int getDepth();
    void updateDepth();
    void setLeft(TreeNode<T>* node);
    void setRight(TreeNode<T>* node);

    T key;
    TreeNode<T> *left;
    TreeNode<T> *right;

private:
    int depth_left;
    int depth_right;
};

//TREE NODE OVERLOADED CONSTRUCTOR
template<class T>
TreeNode<T>::TreeNode(T k) {
    left = NULL;
    right = NULL;
    key = k;
    depth_left = 0;
    depth_right = 0;
}

//TREE NODE CONSTRUCTOR
template<class T>
TreeNode<T>::TreeNode() {
    left = NULL;
    right = NULL;
    depth_left = 0;
    depth_right = 0;
}

//TREE NODE DESTRUCTOR CONSTRUCTOR
template<class T>
TreeNode<T>::~TreeNode() {
    left = NULL;
    right = NULL;
}

//GET VALUE
template<class T>
T TreeNode<T>::getValue() {
    return key;
}

//GET DEPTH
template<class T>
int TreeNode<T>::getDepth() {
    return max(depth_left, depth_right);
}

//UPDATE DEPTH
template<class T>
void TreeNode<T>::updateDepth() {
    int left_depth = (left == NULL) ? -1 : left->getDepth();
    int right_depth = (right == NULL) ? -1 : right->getDepth();
    depth_left = left_depth + 1;
    depth_right = right_depth + 1;
}

//SET LEFT
template<class T>
void TreeNode<T>::setLeft(TreeNode<T>* node) {
    left = node;
    updateDepth();
}

//SET RIGHT
template<class T>
void TreeNode<T>::setRight(TreeNode<T>* node) {
    right = node;
    updateDepth();
}

//TREE NODE
template<class T>
TreeNode<T>::TreeNode(const TreeNode& other) {
    key = other.key;
    if (other.left != NULL) {
        left = new TreeNode<T>(*other.left); // recursively copy left subtree
    } else {
        left = NULL;
    }
    if (other.right != NULL) {
        right = new TreeNode<T>(*other.right); // recursively copy right subtree
    } else {
        right = NULL;
    }
    depth_left = other.depth_left;
    depth_right = other.depth_right;
}

//TREE NODE OPERATOR
template<class T>
TreeNode<T>& TreeNode<T>::operator=(const TreeNode& other) {
    if (this != &other) {
        key = other.key;
        if (other.left != NULL) {
            delete left;
            left = new TreeNode(*other.left);
        } else {
            left = NULL;
        } 
        if (other.right != NULL) {
            delete right;
            right = new TreeNode(*other.right);
        } else {
            right = NULL;
        }
    }
    return *this;
}



//LAZY BST
template<class T>
class LazyBST {
    public:
        LazyBST();
        virtual ~LazyBST();
        LazyBST(const LazyBST<T>& other);

        void insert(T value);
        bool contains(T value);
        bool deleteNode(T k);
        bool isEmpty();
        TreeNode<T>* get(T value);
        void printTreeToFile(const string& filename);
        void studentPrintToFile(TreeNode<T> *node, ofstream& outFile);
 

        T* getMin();
        T* getMax();
        
        TreeNode<T>* getSuccessor(TreeNode<T>* d); // d represents the node we are going to delete
        void replace(T oldValue, T newValue);
        void printTree();
        void recPrint(TreeNode<T> *node);
        void studentPrint(TreeNode<T> *node);
        void studentPrinter();
        TreeNode<T> *getRoot();
        TreeNode<T>* searchByID(int studentID);
        bool needsRebuild(TreeNode<T>* root);
        TreeNode<T>* constructLBTree(const T* values, int start, int end);
        void rebuildTree(TreeNode<T>*& root);
        int countNodes(TreeNode<T>* node);
        void flattenTree(TreeNode<T>* node, T* values, int& index);

        //OVERLOADED OPERATOR
        LazyBST<T>& operator=(const LazyBST<T>& other) {
        if (this != &other) {
            TreeNode<T>* new_root = NULL;
            if (other.root != NULL) {
                new_root = new TreeNode<T>(*(other.root));
            }
            delete root;
            root = new_root;
        }
        return *this;
        }

    private:
        TreeNode<T> *root;
};

//LAZY BST CONSTRUCTOR
template<class T>
LazyBST<T>::LazyBST() {
    root = NULL;
}

//LAZY BST REBUILD
template<class T>
bool needsRebuild(TreeNode<T>* root) {
    if (root == nullptr) {
        return false;
    }
    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);
    int maxDepth = std::max(leftDepth, rightDepth);
    return (std::abs(leftDepth - rightDepth) > maxDepth * 1.5);
}

// DESTRUCTOR
template<class T>
LazyBST<T>::~LazyBST() {

}

//LAZY BST INSERT
template<class T>
LazyBST<T>::LazyBST(const LazyBST<T>& other) {
    if (other.root == NULL) {
        root = NULL;
    } else {
        root = new TreeNode<T>(*(other.root));
    }
}

//GET ROOT
template<class T>
TreeNode<T>* LazyBST<T>::getRoot() {
    return root;
}

//GET
template<class T>
TreeNode<T>* LazyBST<T>::get(T value) {
    if (isEmpty()) {
        return NULL;
    }

    TreeNode<T> *current = root;
    while (current != NULL) {
        if (current->key == value) {
            return current;
        } else if (value < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return NULL; // key not found
}

//REC PRINT
template<class T>
void LazyBST<T>::recPrint(TreeNode<T> *node) {
    if(node == NULL) {
        return;
    }
    recPrint(node->left);
    cout << node->key << " ";
    recPrint(node->right);
}

//PRINT TO FILE
template<class T>
void LazyBST<T>::printTree() {
    recPrint(root); //Prints entire tree - root down.
}

//IS EMPTY
template<class T>
bool LazyBST<T>::isEmpty() {
    return (root == NULL);
}

//GET MIN
template<class T>
T* LazyBST<T>::getMin() {
    if(isEmpty()) {
        return NULL;
    }
    TreeNode<T> *current = root;
    while(current->left != NULL) {
        current = current->left;
    }
    return &(current->key);
}

//GET MAX
template<class T>
T* LazyBST<T>::getMax() {
    if(isEmpty()) {
        return NULL;
    }
    TreeNode<T> *current = root;
    while(current->right != NULL) {
        current = current->right;
    }
    return &(current->key);
}

//INSERT
template<class T>
void LazyBST<T>::insert(T value) {
    TreeNode<T> *node = new TreeNode<T>(value);

    if(isEmpty()) {
        root = node;
    } else {
        TreeNode<T> *current = root;
        TreeNode<T> *parent = NULL;
        while(true) {
            parent = current;
            if(value < current->key) {
                current = current->left;
                if(current == NULL) {
                    parent->left = node;
                    break;
                }
            } else {
                current = current->right;
                if(current == NULL) {
                    parent->right = node;
                    break;
                }
            }
        }
    }
}

//SEARCH BY ID
template<class T>
TreeNode<T>* LazyBST<T>::searchByID(int studentID) {
    if (isEmpty()) {
        return NULL;
    }
    TreeNode<T> *current = root;
    while (current != NULL) {
        if (current->getValue().getID() == studentID) {
            return current;
        } else if (studentID < current->getValue().getID()) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return NULL;
}

//CONTAINS
template <class T>
bool LazyBST<T>::contains(T value) {

    if(isEmpty()) {
        return false;
    }

    TreeNode<T> *current = root;
    while(current != nullptr) {
        if(current->key == value) {
            return true;
        } else if(value < current->key) {
            if(current->left == nullptr) {
                return false;
            }
            current = current->left;
        } else {
            if(current->right == nullptr) {
                return false;
            }
            current = current->right;
        }
    }

    return false; // This line will only be reached if the tree is empty
}

//REPLACE
template<class T>
void LazyBST<T>::replace(T oldValue, T newValue) {
    TreeNode<T>* node = get(oldValue);
    if (node != NULL) {
        node->key = newValue;
    }
}

//DELETE NODE
template<class T>
bool LazyBST<T>::deleteNode(T k) {
    if (isEmpty()) {
        return false;
    }

    TreeNode<T> *current = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;

    while (current->key != k) {
        parent = current;
        if (k < current->key) {
            current = current->left;
            isLeft = true;
        } else {
            current = current->right;
            isLeft = false;
        }
        if (current == NULL) {
            return false;
        }
    }

    if (current->left == NULL && current->right == NULL) {
        if (current == root) {
            root = NULL;
        } else if (isLeft) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
    } else if (current->right == NULL) {
        if (current == root) {
            root = current->left;
        } else if (isLeft) {
            parent->left = current->left;
        } else {
            parent->right = current->left;
        }
    } else if (current->left == NULL) {
        if (current == root) {
            root = current->right;
        } else if (isLeft) {
            parent->left = current->right;
        } else {
            parent->right = current->right;
        }
    } else {
        TreeNode<T> *successor = getSuccessor(current);
        if (current == root) {
            root = successor;
        } else if (isLeft) {
            parent->left = successor;
        } else {
            parent->right = successor;
        }
        successor->left = current->left;
    }
    delete current;
    return true;
}

//GET SUCCESSOR
template<class T>
TreeNode<T>* LazyBST<T>::getSuccessor(TreeNode<T>* d) {
    //d represents the node to be deleted
    TreeNode<T> *sp = d;
    TreeNode<T> *successor = d;
    TreeNode<T> *current = d->right;

    while(current != NULL) {
        sp = successor;
        successor = current;
        current = current->left;
    }

    if(successor != d->right) {
        sp->left = successor->right;
        successor->right = d->right;
    } 

    return successor;
}

//CONSTRUCT LB TREE
template<class T>
TreeNode<T>* constructLBTree(const T* values, int start, int end) {
    if (start > end) {
        return nullptr;
    }
    int mid = start + (end - start) / 2;
    TreeNode<T>* node = new TreeNode<T>(values[mid]);
    node->left = constructLBTree(values, start, mid - 1);
    node->right = constructLBTree(values, mid + 1, end);
    return node;
}

//REBUILD TREE
template<class T>
void rebuildTree(TreeNode<T>*& root) {
    int size = countNodes(root);
    T* values = new T[size];
    int i = 0;
    flattenTree(root, values, i);
    std::sort(values, values + size);
    root = constructLBTree(values, 0, size - 1);
    updateDepths(root);
    delete[] values;
}

//COUNT NODES
template<class T>
int countNodes(TreeNode<T>* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + countNodes(node->left) + countNodes(node->right);
}

//FLATTEN TREE
template<class T>
void flattenTree(TreeNode<T>* node, T* values, int& index) {
    if (node == nullptr) {
        return;
    }
    flattenTree(node->left, values, index);
    values[index++] = node->key;
    flattenTree(node->right, values, index);
}

//STUDENT PRINT
template<class T>
void LazyBST<T>::studentPrint(TreeNode<T> *node) {
    if(node == NULL) {
        return;
    }
    studentPrint(node->left);
    node->key.print();
    studentPrint(node->right);
}

//STUDENT PRINTER
template<class T>
void LazyBST<T>::studentPrinter() {
    studentPrint(root); 
}

#endif
