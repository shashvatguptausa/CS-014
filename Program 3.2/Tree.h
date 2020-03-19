//
//  Tree.cpp
//  Test
//
//  Created by Shashvat Gupta on 2/25/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "Node.h"

using namespace std;

class Tree {
private:
    Node* root;
public:
    Tree();
    
    void preOrder();
    void inOrder();
    void postOrder();
    void preOrder(Node*);
    void inOrder(Node*);
    void postOrder(Node*);
    
    void insert(string);
    void insert(Node* &a, Node* &parent, string k);
    
    bool search(string);
    bool search(Node*, string); //recursive helper
    
    void remove(string);
    void remove(Node*, string);
    
    void reorder(Tree&);
    void reorder(Tree&,Node*);
    
    bool isLeaf(Node*);
};
