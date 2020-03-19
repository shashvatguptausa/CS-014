//
//  arithmeticExpression.cpp
//  Test
//
//  Created by Shashvat Gupta on 2/12/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//

#include "arithmeticExpression.h"
#include <fstream>
#include <sstream>

int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

/* Helper function for generating the dotty file. This is a recursive function. */
void arithmeticExpression::visualizeTree(ofstream &out, TreeNode *node) {
    out << "key12 -> key8;";
    out << "key12 -> key16;";
    out << "key8  -> key1;";
    out << "key8  -> key11;";
    out << "key16 -> key13;";
    out << "key16 -> key25;";
}

void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

/* Initializes an empty tree and sets the infixExpression
 to the value of parameter passed in. */
arithmeticExpression::arithmeticExpression(const string &a) {
    infixExpression = a;
    root = new TreeNode('0','a');
}

/* Implementation of destrucor is optional.
 The destructor should deallocate all the nodes in the tree. */
//~arithmeticExpression();



void arithmeticExpression::buildTree() {
    if(infixExpression.size() < 2) {
        cout << "too small of expression" << endl;
        return;
    }
    
    string post = infix_to_postfix();
    //string post = infixExpression;
    
    stack<TreeNode *> st;
    TreeNode *tmp;
    TreeNode *t1;
    TreeNode *t2;
    
    char key = 'a';
    
    for(int i = 0; i < (int)post.length(); i++) {
        if(post.at(i)=='+'||post.at(i)=='-'||post.at(i)=='*'||post.at(i)=='/') {
            tmp = new TreeNode(post.at(i),key);
            key++;
            t1 = st.top();
            st.pop();
            t2 = st.top();
            st.pop();
            
            tmp->right=t1;
            tmp->left=t2;
            
            st.push(tmp);
            
        }
        else {
            tmp = new TreeNode(post.at(i),key);
            key++;
            st.push(tmp);
        }
    }
    
    root = st.top();
    st.pop();
    
    
}


/* Helper function that outputs the infix notation of the arithmetic expression tree
 by performing the inorder traversal of the tree.
 An opening and closing parenthesis must be added at the
 beginning and ending of each expression. */
void arithmeticExpression::infix(TreeNode *par) {
    if(par==nullptr) {
        return;
    }
    if(par->left!=nullptr) {
        cout << "(";
    }
    
    infix(par->left);
    cout << par->data;
    infix(par->right);
    
    if(par->right!=nullptr) {
        cout << ")";
    }
}

/* Helper function that outputs the prefix notation of the arithmetic expression tree
 by performing the preorder traversal of the tree. */
void arithmeticExpression::prefix(TreeNode *par) {
    if(par!=nullptr) {
        cout << par->data;
        prefix(par->left);
        prefix(par->right);
    }
}

/* Helper function that outputs the postfix notation of the arithmetic expression tree
 by performing the postorder traversal of the tree. */
void arithmeticExpression::postfix(TreeNode *par) {
    if(par!=nullptr) {
            postfix(par->left);
            postfix(par->right);
            cout << par->data;
    }
}

/* Calls the recursive infix function. */
void arithmeticExpression::infix() {
    infix(root);
}

/* Calls the recursive prefix function. */
void arithmeticExpression::prefix() {
    prefix(root);
}

/* Calls the recursive postfix function. */
void arithmeticExpression::postfix() {
    postfix(root);
}
