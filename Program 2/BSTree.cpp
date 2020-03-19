//
//  BSTree.cpp
//  Test
//
//  Created by Shashvat Gupta on 2/17/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//

#include <stdio.h>
#include "BSTree.h"
#include <iostream>
#include <algorithm>
using namespace std;

BSTree::BSTree() {
    root = nullptr;
}

BSTree::~BSTree() {
    //delete root;
}
void BSTree::insert(const string &newString) {
    
    if(root == nullptr) {
        root = new Node(newString);
        return;
    }
    
    Node *tmp = new Node(newString);
    Node *current = root;
    while(current != nullptr) {
        if(tmp->data==current->data) {
            current->count++;
            return;
        }
        else if(tmp->data<current->data) {
            if(current->left==nullptr) {
                current->left=tmp;
                return;
            }
            else {
                current=current->left;
            }
        }
        else if(tmp->data > current->data) {
            if(current->right==nullptr) {
                current->right=tmp;
                return;
            }
            else {
                current=current->right;
            }
        }
        
    }
    
}

/* Remove a specified string from the tree.
 Be sure to maintain all bianry search tree properties.
 If removing a node with a count greater than 1, just decrement the count, otherwise,
 if the count is simply 1, remove the node.
 You MUST follow the remove algorithm shown in the slides and discussed in class or else
 your program will not pass the test functions.
 When removing,
 if removing a leaf node, simply remove the leaf. Otherwise,
 if the node to remove has a left child, replace the node to remove with the largest
 string value that is smaller than the current string to remove
 (i.e. find the largest value in the left subtree of the node to remove).
 If the node has no left child, replace the node to remove with the smallest value
 larger than the current string to remove
 (i.e. find the smallest value in the right subtree of the node to remove.
 */
void BSTree::remove(const string &key) {
    root = remove(root,key);
}

Node* BSTree::remove(Node* a, string key)
{
    if (a == nullptr)
        return a;
    
    if (key < root->data) {
        a->left = remove(a->left, key);
    } else if (key > a->data) {
        a->right = remove(a->right, key);
    } else {
        if(a->count>1) {
            a->count--;
        }
        else {
            if (a->left == nullptr) {
                return a->right;
            } else if (a->right == nullptr)
                return a->left;
            
            Node* tmp = a->right;
            while (tmp->left != nullptr) {
                tmp = tmp->left;
            }
            
            a->data = tmp->data;
            a->count = tmp->count;
            
            a->right = remove(a->right, root->data);
        }
    }
    
    return a;
}


bool BSTree::search(const string &key) const {
    return search(root, key);
}

bool BSTree::search(Node *a, string key) const {
    if(a==nullptr) {
        return NULL;
    }
    else if(a->data == key) {
        return true;
    }
    else if(a->data < key) {
        return search(a->left,key);
    }
    else if(a->data > key) {
        return search(a->right, key);
    }
    return false;
}


string BSTree::largest() const {
    if(root==nullptr) {
        return "";
    }
    Node *current = root;
    while(current->right!=nullptr) {
        current = current->right;
    }
    return current->data;
}
string BSTree::smallest() const {
    if(root==nullptr) {
        return "";
    }
    Node *current = root;
    while(current->left!=nullptr) {
        current = current->left;
    }
    return current->data;
}

int BSTree::height(const string& key) const {
    Node *current = root;
    int ht = 1;
    while(current != nullptr) {
        if(key==current->data) {
            return ht;
        }
        else if(key<current->data) {
            current=current->left;
            ht++;
        }
        else if(key > current->data) {
            current=current->right;
            ht++;
        }
        
    }
    return -1;
}

//PRINTING//

void BSTree::preOrder(Node *a) const{
    if(a == nullptr)
        return;
    cout << a->data << "(" << a->count << ")";
    if(a->left!=nullptr) {
        cout << ", ";
        preOrder(a->left);
    }
    if(a->right != nullptr) {
        cout << ", ";
        preOrder(a->right);
    }
}

void BSTree::postOrder(Node *a) const{
    if(a == nullptr)
        return;
    if(a->left!=nullptr) {
        
        postOrder(a->left);
        cout << ", ";
    }
    if(a->right!=nullptr) {
        
        postOrder(a->right);
        cout << ", ";
    }
    cout << a->data << "(" << a->count << ")";
    
    
}

void BSTree::inOrder(Node *a) const {
    if(a == nullptr)
        return;
    if(a->left!=nullptr) {
        inOrder(a->left);
        cout << ", ";
    }
    cout << a->data << "(" << a->count << ")";
    
    if(a->right!=nullptr) {
        cout << ", ";
        inOrder(a->right);
    }
}

void BSTree::preOrder() const {
    preOrder(root);
    if(root != nullptr)
        cout << ", ";
}
void BSTree::postOrder() const {
    postOrder(root);
    if(root != nullptr)
        cout << ", ";
}
void BSTree::inOrder() const {
    inOrder(root);
    if(root != nullptr)
        cout << ", ";
}
