//
//  AVLTree.cpp
//  Test
//
//  Created by Shashvat Gupta on 2/17/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//

#include <stdio.h>
#include "AVLTree.h"
#include <iostream>
#include <algorithm>
using namespace std;

AVLTree::AVLTree() {
    root = nullptr;
}

AVLTree::~AVLTree() {
    //delete root;
}



int max(int a, int b) {
    if(a>b)
        return a;
    return b;
}

Node* AVLTree::rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    
    return x;
}

Node* AVLTree::leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;
    return y;
}

int AVLTree::balanceFactor(Node* a) {
    if (a == nullptr||a==NULL)
        return 0;
    return height(a->left) - height(a->right);
}

void AVLTree::insert(const string &s) {
    root = insert(root, s);
}

Node* AVLTree::insert(Node* node, string s)
{
    if (node == nullptr||node==NULL) {
        Node *tmp = new Node(s);
        tmp->height = 1;
        return tmp;
    }
    
    if (s < node->data) {
        node->left = insert(node->left, s);
    }
    else if(s > node->data) {
        node->right = insert(node->right, s);
    }
    else {
        return node;
    }
    node->height = 1 + max(height(node->left),height(node->right));

    int balance = balanceFactor(node);
    
    // Left Left Case
    if (balance > 1 && s < node->left->data)
        return rightRotate(node);
    
    // Right Right Case
    if (balance < -1 && s > node->right->data)
        return leftRotate(node);
    
    // Left Right Case
    if (balance > 1 && s > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    // Right Left Case
    if (balance < -1 && s < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

int AVLTree::height(Node* a) {
    if (a == nullptr||a==NULL)
        return 0;
    return a->height;
}

//PRINTING//


void AVLTree::inOrder(Node *a) {
    if(a == nullptr)
        return;
    if(a->left!=nullptr) {
        inOrder(a->left);
    }
    int i = balanceFactor(a);
    cout << a->data << "(" << i << "), ";
    
    if(a->right!=nullptr) {
        inOrder(a->right);
    }
}


void AVLTree::printBalanceFactors() {
    inOrder(root);
}

