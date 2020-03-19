//
//  Node.hpp
//  Test
//
//  Created by Shashvat Gupta on 2/17/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <stdio.h>
#include <string>

using namespace std;

struct Node {
    friend class BSTree;
private:
    string data;
    Node *left;
    Node *right;
    int count;
public:
    Node();
    Node(string a);
};

#endif /* Node_hpp */
