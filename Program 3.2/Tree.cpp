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
    
    if(a->small!="") {
        t.insert(a->small);
    }
    
    if(a->large!="") {
        t.insert(a->large);
    }
    
    if(a->left!=nullptr) {
        reorder(t,a->left);
    }
    
    if(a->middle!=nullptr) {
        reorder(t,a->middle);
    }
    
    if(a->right!=nullptr) {
        reorder(t,a->right);
    }
}

bool Tree::isLeaf(Node* a) {
    if(a==NULL||a==nullptr)
        return false;
    if(a->left == nullptr)
        return true;
    if(a->left->small=="")
        return true;
    
    return false;
}

void Tree::insert(string key) {
    insert(root, root->parent, key);
}

void Tree::insert(Node* &a, Node* &p, string k) {
    
    if(root==nullptr) {
        root = new Node(k,nullptr);
        return;
    }
    
    
    //    if(a==root) {        //AT ROOT
    //        p=a;
    //    }
    if(a!=nullptr && a->small==root->small && a->large==root->large && a->large!="" && isLeaf(a)) {    //NO PARENT AND SMALL AND LARGE FULL
        string sm = a->small;
        string lg = a->large;
        string mid = k;
        if(sm>mid) {
            string tmp2 = sm;
            sm = mid;
            mid = tmp2;
        }
        if(mid>lg) {
            string tmp2 = lg;
            lg = mid;
            mid = tmp2;
        }
        Node* tmp = new Node(mid,a->parent);
        tmp->left = new Node(sm,tmp);
        tmp->right = new Node(lg,tmp);
        a=tmp;
        return;
    }
    
    if(p!=nullptr&&(p->small==""||p->small==k||p->large==k))
        return;
    //BASE CASE RETURNS
    
    if(isLeaf(p)) {     //WAS A LEAF
        if(a==nullptr)
            a = new Node("",p);
        //create new node if not there
        
        if(p->small=="") {      //INSERT INTO SMALL
            p->small=k;
            return;
        }
        else if(p->large=="") { //INSERT INTO LARGE
            if(p->small>k) {
                string tmp = p->small;
                p->small = k;
                p->large = tmp;
            }
            else {
                p->large=k;
            }
            return;
        }
        else if(p->small!=""&&p->large!="") {                 //SMALL AND LARGE BOTH FULL
            string sm = p->small;
            string lg = p->large;
            string mid = k;
            if(sm>mid) {
                string tmp2 = sm;
                sm = mid;
                mid = tmp2;
            }
            if(mid>lg) {
                string tmp2 = lg;
                lg = mid;
                mid = tmp2;
            }
            
            if(p->parent!=nullptr) {
                
                if(p->parent->small!=""&&p->parent->large!="") {    //PARENT SMALL AND LARGE FULL
                    
                    string Psm = p->parent->small;
                    string Plg = p->parent->large;
                    string Pmid = mid;
                    if(Psm>Pmid) {
                        string Ptmp2 = Psm;
                        Psm = Pmid;
                        Pmid = Ptmp2;
                    }
                    if(Pmid>Plg) {
                        string Ptmp2 = Plg;
                        Plg = Pmid;
                        Pmid = Ptmp2;
                    }
                    
                    Node* tmp = new Node(Pmid,p->parent->parent);
                    tmp->left = new Node(Psm,tmp);
                    tmp->right = new Node(Plg,tmp);
                    
                    
                    if(p->parent->right==p) {   //RIGHT REPLACEMENT
                        
                    }
                    else if(p->parent->left==p) {//LEFT REPLACEMENT
                        
                    }
                    else if(p->parent->middle==p) {//MIDDLE REPLACEMENT
                        tmp->left->left = p->parent->left;
                        tmp->left->left->parent=tmp->left;
                        tmp->right->right = p->parent->right;
                        tmp->right->right->parent=tmp->right;
                        
                        tmp->left->right = new Node(sm,tmp->left);
                        tmp->right->left = new Node(lg,tmp->right);
                    }
                    *(p->parent)=*tmp;
                    return;
                }
                else if(p->parent->right==p) {   //RIGHT REPLACEMENT
                    p->parent->large=mid;
                    p->parent->middle = new Node(sm,p->parent);
                    p->parent->right = new Node(lg,p->parent);
                    
                }
                else if(p->parent->left==p) {//LEFT REPLACEMENT
                    p->parent->large=p->parent->small;
                    p->parent->small=mid;
                    p->parent->left = new Node(sm,p->parent);
                    p->parent->middle = new Node(lg,p->parent);
                }
                else if(p->parent->middle==p) {//MIDDLE REPLACEMENT
                    p->parent->large=mid;
                    p->parent->left = new Node(sm,p->parent);
                    p->parent->right = new Node(lg,p->parent);
                }
            }
            
            return;
        }
    }
    
    
    
    if(k<a->small) {              //LEFT
        insert(a->left, a, k);
        return;
    }
    if(k>a->large) {              //RIGHT
        insert(a->right, a, k);
        return;
    }
    if(k>a->small&&k<a->large) {  //MIDDLE
        insert(a->middle, a, k);
        return;
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
    remove(root, key);
    if(root!=nullptr)
    reorder(*this);
}

void Tree::remove(Node* a, string key) {
    if (a == nullptr) //NOT FOUND
        return;
    else if(a->small==key||a->large==key) { //FOUND
        
        if(isLeaf(a)) {         //IS A LEAF
            if(a->large==key) {
                a->large="";
                return;
            }
            else if(a->small==key) {
                if(a->large!="") {
                    a->small=a->large;
                    return;
                }
                else {
                    a->small="";
                    return;
                }
            }
        }
        
    }
    else if(key>a->small && key<a->large) { //MIDDLE
        remove(a->middle, key);
        return;
    }
    else if(key<a->small) { //LEFT
        remove(a->left, key);
        return;
    }
    else if(key>a->large) { //RIGHT
        remove(a->right,key);
        return;
    }
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
    
    bool tmp = false;
    
    if(a->left!=nullptr) {
        postOrder(a->left);
    }
    
    if(a->middle!=nullptr) {
        postOrder(a->middle);
        tmp = true;
    }
    
    if(tmp&&a->small!="") {
        cout << a->small;
        cout << ", ";
    }
    
    if(a->right!=nullptr) {
        postOrder(a->right);
    }
    
    if((tmp==false)&&a->small!="") {
        cout << a->small;
        cout << ", ";
    }
    
    if(a->large!="") {
        cout << a->large;
        cout << ", ";
    }
}


