//
//  Node.cpp
//  Test
//
//  Created by Shashvat Gupta on 2/17/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//

#include "Node.h"

Node::Node() {
    left = nullptr;
    right = nullptr;
    data = "";
    height = 1;
}

Node::Node(string a) {
    left = nullptr;
    right = nullptr;
    data = a;
    height = 1;
}
