//
//  arithmeticExpression.h
//  Test
//
//  Created by Shashvat Gupta on 2/12/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//

#ifndef ARITHMETICEXPRESSION_H
#define ARITHMETICEXPRESSION_H
#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;
struct TreeNode{
    char data;
    char key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char data, char key):data(data),key(key),left(0),right(0){}
};

class arithmeticExpression{
  private:
    string infixExpression;
    TreeNode* root;

  public:
    arithmeticExpression(const string &);

    /* Implementation of destrucor is optional.
       The destructor should deallocate all the nodes in the tree. */
    //~arithmeticExpression();

    void buildTree();

    /* Calls the recursive infix function. */
    void infix();

    /* Calls the recursive prefix function. */
    void prefix();

    /* Calls the recursive postfix function. */
    void postfix();

    /* Calls the recursive visualizeTree function and generates the .png file using system call. */
    void visualizeTree(const string &);

 private:
    /* Helper function that returns an integer according to
       the priority of the given operator. */
    int priority(char);

    /* Helper function that returns the postfix notation equivalent
       to the given infix expression */
    string infix_to_postfix();

    /* Helper function that outputs the infix notation of the arithmetic expression tree
       by performing the inorder traversal of the tree.
       An opening and closing parenthesis must be added at the
       beginning and ending of each expression. */
    void infix(TreeNode *);

    /* Helper function that outputs the prefix notation of the arithmetic expression tree
       by performing the preorder traversal of the tree. */
    void prefix(TreeNode *);

    /* Helper function that outputs the postfix notation of the arithmetic expression tree
       by performing the postorder traversal of the tree. */
    void postfix(TreeNode *);

    /* Helper function for generating the dotty file. This is a recursive function. */
    void visualizeTree(ofstream &, TreeNode *);
};
#endif
