//
//  Tree.cpp
//  Test
//
//  Created by Shashvat Gupta on 2/25/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//

#include "Tree.h"
#include <iostream>

Tree::Tree() {
    root = nullptr;
}


void Tree::reorder(Tree& t2) {
    Tree t1;
    reorder(t1,t2.root);
    t2=t1;
}

void Tree::reorder(Tree &t,Node* a) {
    
    if(a->left!=nullptr) {
        reorder(t,a->left);
    }
    
    if(a->middle!=nullptr) {
        reorder(t,a->middle);
    }
    
    if(a->right!=nullptr) {
        reorder(t,a->right);
    }
    
         if(a->small!="") {
             t.insert(a->small);
           }
    
    if(a->large!="") {
t.insert(a->large);
    }
}

bool Tree::isLeaf(Node* a) {
    if(a->left == nullptr) {
        return true;
    }
    return false;
}

void Tree::insert(string key) {
    if (root==nullptr) {
        root = new Node(key,nullptr);
        return;
    }
    
    Node* current = root;
    while(true) {
        if(isLeaf(current)) { //ISLEAF
            if(current->small<key && current->large == "") {
                current->large = key;
                return;
            }
            else if (current->small>key && current->large == "") {
                string tmp = current->small;
                current->small = key;
                current->large = tmp;
                return;
                
            }
            else { //adding third value to node
                    
                string small = current->small;
                string large = current->large;
                string mid = key;
                //sort items
                if(mid<small) {
                    string tmp = mid;
                    mid = small;
                    small = tmp;
                }
                else if(mid>large) {
                    string tmp = mid;
                    mid = large;
                    large = tmp;
                }
                
                if (current->parent==nullptr) {
                    current->small = mid;
                    current->large = "";
                    current->left = new Node(small,current);
                    current->right = new Node(large,current);
                    return;
                }
                
                if(current->parent->large=="") {
                    if(current->parent->right == current) {
                    current->parent->middle = new Node(small,current);
                    current->parent->large = mid;
                    current->parent->right->large = "";
                    current->parent->right->small = large;
                    }
//                    else if(current->parent->left == current) {
//                        current->parent->middle = new Node(large,current);
//                        current->large = mid;
//                        current->parent->right->large = "";
//                        current->parent->right->small = large;
//                    }
                    return;
                }
                else {
                current->small = mid;
                current->large = "";
                current->left = new Node(small,current);
                current->right = new Node(large,current);
                return;
                }
            }
            
        }
        else if(key>current->small && key<current->large) { //MIDDLE
            current = current->middle;
        }
        else if(key<current->small) { //LEFT
            current = current->left;
        }
        else if(key>current->large) { //RIGHT
            current = current->right;
        }
    }
}



bool Tree::search(string key) {
    return search(root, key);
}

bool Tree::search(Node* root, string key) {
    if (root == nullptr) //NOT FOUND
        return NULL;
    else if(root->small==key||root->large==key) { //FOUND
        return true;
    }
    else if(key>root->small && key<root->large) { //MIDDLE
        return search(root->middle, key);
    }
    else if(key<root->small) { //LEFT
        return search(root->left, key);
    }
    else if(key>root->large) { //RIGHT
        return search(root->right,key);
    }
    
    return false; //NOT FOUND
}

void Tree::remove(string key) {
        
        Node* current = root;
    if(root==nullptr) {
        return;
    }
        while(current!=nullptr) {
            if(current->small == key) { //ISLEAF
                current->small="";
                if(current->left!=nullptr && current->parent!=nullptr) {
                    current->parent->left=current->left;
                }
            }
            else if(current->large == key) {
                current->large="";
            }
            else if(key>current->small && key<current->large) { //MIDDLE
                current = current->middle;
            }
            else if(key<current->small) { //LEFT
                current = current->left;
            }
            else if(key>current->large) { //RIGHT
                current = current->right;
            }
        }
    reorder(*this);
}

//PRINTING//

void Tree::preOrder() {
    preOrder(root);
    cout << endl;
}

void Tree::preOrder(Node *a) {
    if(a == nullptr)
        return;
    if(a->small!="") {
    cout << a->small;
    cout << ", ";
    }
    
    if(a->left!=nullptr) {
        preOrder(a->left);
    }
    
    if(a->large!="") {
        cout << a->large;
        cout << ", ";
    }
    
    if(a->middle!=nullptr) {
        preOrder(a->middle);
    }
    
    if(a->right!=nullptr) {
        preOrder(a->right);
    }
    
}

void Tree::inOrder() {
    inOrder(root);
    cout << endl;
}

void Tree::inOrder(Node *a) {
    if(a == nullptr)
        return;
    if(a->left!=nullptr) {
        inOrder(a->left);
    }
    
     if(a->small!="") {
       cout << a->small;
       cout << ", ";
       }
    
    if(a->middle!=nullptr) {
        postOrder(a->middle);
    }
    
    if(a->large!="") {
        cout << a->large;
        cout << ", ";
        
    }
    
    if(a->right!=nullptr) {
        inOrder(a->right);
    }
}

void Tree::postOrder() {
    postOrder(root);
    cout << endl;
}


void Tree::postOrder(Node* a) {
    if(a == nullptr)
        return;
    
    bool tst = false;
    
    if(a->left!=nullptr) {
        postOrder(a->left);
    }
    
    if(a->middle!=nullptr) {
        postOrder(a->middle);
        tst=true;
    }
    if(tst) {
     if(a->small!="") {
       cout << a->small;
       cout << ", ";
       }
    }
    
    if(a->right!=nullptr) {
        postOrder(a->right);
    }
    
    if(!tst) {
         if(a->small!="") {
           cout << a->small;
           cout << ", ";
           }
    }
    if(a->large!="") {
        cout << a->large;
        cout << ", ";
    }
}


