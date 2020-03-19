#ifndef __BSTREE_H__
#define __BSTREE_H__

#include "Node.h"

class BSTree {
private:
    Node *root;
public:
    BSTree();
    ~BSTree();
    
    void insert(const string &newString);
    void remove(const string &key);
    Node* remove(Node*, string);
    bool search(const string &key) const;
    bool search(Node*, string) const;
    string largest() const;
    string smallest() const;
    int height(const string&) const;
    
    void preOrder(Node*) const;
    void postOrder(Node*) const;
    void inOrder(Node*) const;
    void preOrder() const;
    void postOrder() const;
    void inOrder() const;
};

#endif // __BSTREE_H__
