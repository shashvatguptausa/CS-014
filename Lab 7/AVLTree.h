#ifndef __AVLTree_H__
#define __AVLTree_H__

#include "Node.h"

class AVLTree {
private:
    Node *root;
public:
    AVLTree();
    ~AVLTree();
    
    void insert(const string &);
    Node* insert(Node* node, string s);
    Node* rightRotate(Node *y);
    Node* leftRotate(Node *y);
    int height(Node*);
    
    void printBalanceFactors();

    void inOrder(Node*);
    
    int balanceFactor(Node*);
};

#endif // __AVLTree_H__
