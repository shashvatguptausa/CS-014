//
//  Node.cpp
//  Test
//
//  Created by Shashvat Gupta on 2/25/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//

#ifndef __NODE_H
#define __NODE_H

#include <string>

using namespace std;

class Node {

  friend class Tree;

private:
  string small;
  string large;

  Node *left;
  Node *middle;
  Node *right;
  Node *parent;

public:
    Node();
    Node(string,Node*);
  // Add additional functions/variables here. Remember, you may not add any
  // Node * or string variables.

};

#endif
