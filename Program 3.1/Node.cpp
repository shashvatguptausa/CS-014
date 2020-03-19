//
//  Node.cpp
//  Test
//
//  Created by Shashvat Gupta on 2/25/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "Node.h"

using namespace std;

Node::Node() {
    small = "";
    large = "";
    
    left = nullptr;
    middle = nullptr;
    right = nullptr;
    parent = nullptr;
}


Node::Node(string s,Node* rt) {
    small = s;
    large = "";
    
    left = nullptr;
    middle = nullptr;
    right = nullptr;
    parent = rt;
}
