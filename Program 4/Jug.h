//
//  Jug.hpp
//  Test
//
//  Created by Shashvat Gupta on 3/9/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//

#ifndef Jug_h
#define Jug_h

#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>


using namespace std;


class Node {
    friend class Jug;
    Node();
    Node(Node*,int,int,int);
    Node* prev;
    int index;
    int weight;
    int dist;
    int a;
    int b;
    
public:
    bool operator < (const Node* &lhs);
};


class Jug {
    public:
    
        Jug(int,int,int,int,int,int,int,int,int);
        ~Jug();

        //solve is used to check input and find the solution if one exists
        //returns -1 if invalid inputs. solution set to empty string.
        //returns 0 if inputs are valid but a solution does not exist. solution set to empty string.
        //returns 1 if solution is found and stores solution steps in solution string.
        int solve(string &solution);
    private:
    
    
    list<Node*>* createG();
    void relax(Node* &,Node* &, int);
    bool isHere(Node*, int &index, list<Node*> g[]);
    
    void printAdj(list<Node*> g[]);
    
        
        //anything else you need
    int Ca; //capacity
    int Cb;
    int N;  //goal
    int cfA;  //cost to fill
    int cfB;
    int ceA;  //cost to empty
    int ceB;
    int cpAB; //cost to pour
    int cpBA;
    
    int size;
    
    int printAns(Node*, Node*, string[]);
};

#endif /* Jug_h */
