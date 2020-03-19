//
//  Jug.cpp
//  Test
//
//  Created by Shashvat Gupta on 3/9/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//

#include "Jug.h"
#include <algorithm>
#include <vector>
#include <stack>
int sz = 1;
const int maximum = 50;
#define inf 9999;

Node::Node() {
    prev = nullptr;
    a=-1;
    b=-1;
    dist = inf;
    index=-1;
}

Node::Node(Node* p, int aa, int bb, int i) {
    prev = p;
    a=aa;
    b=bb;
    dist = inf;
    index = i;
    weight=0;
}

Jug::Jug(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
    Ca=a; //capacity
    Cb=b;
    N=c;  //goal
    cfA=d;  //cost to fill
    cfB=e;
    ceA=f;  //cost to empty
    ceB=g;
    cpAB=h; //cost to pour
    cpBA=i;
    
    size=0;
}

Jug::~Jug() {
    
}

bool Jug::isHere(Node* cur, int &index, list<Node*> g[]) {
    bool here = false;
    for(int i = 0; i < maximum; i++) {
        if(g[i].front()!=nullptr) {
            if(g[i].front()->a == cur->a && g[i].front()->b == cur->b) {
                //is here, dont need to create new
                here = true;
            }
        }
    }
    
    if( !(g[cur->prev->index].front()->a==cur->a && g[cur->prev->index].front()->b==cur->b) )  {
        g[cur->prev->index].push_back(cur);
    }
    
    if(!here) {
        size++;
        index++;
        cur->index++;
        
        g[index].push_back(cur);
        if(index!=cur->index)
            g[cur->index].push_back(cur);
        
        return false;
    }
    return  true;
}

 list<Node*>* Jug::createG() {
    
     list<Node*> *g = new list<Node*>[maximum];

    for(int i = 0; i < size; i++) {
        g[i].clear();
    }
    
    //create starting node:
    g[0].push_back(new Node(nullptr,0,0,0));
    g[0].front()->dist=0;
    size++;
    
    queue<Node*> q;
    q.push(g[0].front());
    int index = 0;
    
    while(!q.empty()) {
        Node* cur = q.front();
        q.pop();
        
        //fill A
        if(cur->a==Ca) {
            // cout << "not filling into A" << endl;
        }
        else {
            Node* newNode = new Node(cur,Ca,cur->b,index);
            if( !isHere(newNode, index, g) ) {
                q.push(newNode);
            }
        }
        //fill B
        if(cur->b==Cb) {
            // cout << "not filling into B" << endl;
        }
        else {
            Node* newNode = new Node(cur,cur->a,Cb,index);
            if( !isHere(newNode, index, g) ) {
                q.push(newNode);
            }
        }
        
        //empty A
        if(cur->a==0) {
            // cout << "not filling into A (empty)" << endl;
        }
        else {
            Node* newNode = new Node(cur,0,cur->b,index);
            if( !isHere(newNode, index, g) ) {
                q.push(newNode);
            }
        }
        //empty B
        if(cur->b==0) {
            // cout << "not filling into B (empty)" << endl;
        }
        else {
            Node* newNode = new Node(cur,cur->a,0,index);
            if( !isHere(newNode, index, g) ) {
                q.push(newNode);
            }
        }
        
        //A->B
        if( (cur->a==Ca&&cur->b==Cb) || (cur->a==0)) {
            //  cout << "! A->B (both full)" << endl;
        }
        else {
            int bTot = (cur->a)+(cur->b);
            int aTot=0;
            if(bTot>Cb) {
                aTot=(bTot-Cb);
                bTot=Cb;
            }
            if(cur->a==3&&cur->b==3) {
                
            }
            Node* newNode = new Node(cur,aTot,bTot,index);
            if( !isHere(newNode, index, g) ) {
                q.push(newNode);
            }
        }
        //B->A
        if( (cur->a==Ca&&cur->b==Cb) || (cur->b==0)) {
            //  cout << "! B->A (both full)" << endl;
        }
        else {
            
            int aTot = (cur->a)+(cur->b);
            int bTot=0;
            if(aTot>Ca) {
                bTot=(aTot-Ca);
                aTot=Ca;
            }
            
            Node* newNode = new Node(cur,aTot,bTot,index);
            if( !isHere(newNode, index, g) ) {
                q.push(newNode);
            }
        }
        
    }
    
    for(int i = 0; i < size; i++) {
        g[i].front()->dist=inf;
    }
     return g;
}

void Jug::printAdj(list<Node*> g[]) {
    cout << "ADJ LIST: " << endl;
    for(int i = 0; i < size; i++) {
        cout << "\n(" << g[i].front()->a << ", " << g[i].front()->b << ") (dist "<< g[i].front()->dist <<"):\t";
        for(list<Node*>::iterator it = g[i].begin(); (it)!=g[i].end(); it++) {
            if(it!=g[i].begin())
                cout << "(" << (*it)->a << ", " << (*it)->b << "), ";
        }
    }
    cout << endl;
}


//returns -1 if invalid inputs. solution set to empty string.
//returns 0 if inputs are valid but a solution does not exist. solution set to empty string.
//returns 1 if solution is found and stores solution steps in solution string.

void Jug::relax(Node* &u, Node* &v, int w) {
    if(v->dist > u->dist + w) {
        
        //if(u->a==3&&u->b==4) {
            cout << "comparing (" << u->a << ", " << u->b << ")->(" << v->a << ", " << v->b << ")" << endl;
            cout << "dist u vs v: " << v->dist << " <- " << u->dist << " + " << w << endl;
        //}
        v->dist = u->dist + w;
        v->prev=u;
    }
    
}


//create adj nodes:

bool Node::operator<(const Node* &lhs) {
    return lhs->dist < this->dist;
}


int Jug::solve(string &sol) {
    
//    cout <<  "fill A\npour A B\nfill A\npour A B\nempty B\npour A B\nfill A\npour A B\nsuccess 27\n\nfill A\npour A B\nfill A\npour A B\nempty B\npour A B\nfill A\npour A B\nsuccess 8" << endl;
//    return 0;
    
    if(Ca>=Cb || Ca < 0 || Cb < 0) {
        sol = "";
        return -1;
    }
    
    if(Cb==N) {
        sol = "success 1\n";
        return 1;
    }
    
    list<Node*>* g = createG();
    
    
    vector<Node*> cloud;
    
    priority_queue <Node*, vector<Node*>, greater<Node*> > pq;
    pq.push(g[0].front());
    // (0,0)
    
    g[0].front()->dist=0;
    list<Node*> Q;
    
    int di[size];
    Node* pre[size];
    
    for(int x = 0; x<size; x++) {
        di[x]=g[x].front()->dist;
    }
    
    for(int x = 1; x<size; x++) {
        g[x].front()->prev=nullptr;
       Q.push_back(g[x].front());    //add each node into queue
    }

    while(!Q.empty()) {
        Node* u = new Node();
       list<Node*> :: iterator i;
        int Ldist = inf;
        for(i=Q.begin();i!=Q.end();i++) {
            if(Ldist > (*i)->dist) {
                Ldist = (*i)->dist;
                u = *i;
            }
        }
        
       Q.remove(u);
        int w = 0;

        cloud.push_back(u);
        for(list<Node*>::iterator i = g[u->index].begin(); i!= g[u->index].end(); i++) {
            Node* v = *i;
            
            
            
            if( !(u->a==v->a&&u->b==v->b)) {
                if(Ca==v->a && u->b == v->b) { //fill a
                    w=cfA;
                }
                else if(Cb==v->b && u->a==v->a) { //fill b
                    w=cfB;
                }
                else if(v->a==0 && u->a!=0 && u->b==v->b) { //empty a
                    w=ceA;
                }
                else if(v->b==0 && u->b!=0 && u->a==v->a) { //empty b
                    w=ceB;
                }
                else if( (v->a==0&&v->b==(u->a+u->b) ) || (v->b==Cb && v->a==(u->a+u->b-Cb) ) ) {//A->B
                    w=cpAB;
                }
                else if( (v->b==0&&v->a==(u->b+u->a) ) || (v->a==Ca && v->b==(u->b+u->a-Ca) ) ) {//B->A)
                    w=cpBA;
                }
                else {
                    cout << "\n Error\tu: (" << u->a << ", " << u->b << ")->(" << v->a << ", " << v->b << ")" << endl;
                    //uhhhhhhh
                }
            }
            //relax(u, v, w);
            v->dist=di[v->index];
            if(v->dist > u->dist + w) {
                di[v->index]=u->dist + w;
                v->dist = u->dist + w;
                pre[v->index]=u;
                v->prev=u;
            }
        }
       // pq.pop();
    }
    
    for(int i = 1; i<size;i++) {
        g[i].front()->dist=di[i];
        g[i].front()->prev=pre[i];
        cloud.at(i)->dist=di[i];
        cloud.at(i)->prev=pre[i];
    }

    
    Node* ans = new Node();
    int shortest = inf;
    
    for(int w = 1; w < size; w++) { //find ans
        if(cloud.at(w)->b==N) {
            if(shortest>cloud.at(w)->dist && cloud.at(w)->dist>0) {
                ans = cloud.at(w);
                shortest = ans->dist;
            }
        }
    }
    
    if(ans->a == -1 || ans->b == -1) {
        return -1;
    }
    //-----------------//

       //printAdj(g);
   
    //-----------------//
    Node* v = ans;
    Node* u = v->prev;
    stack<string> aq;
    
    g[0].front()->prev=nullptr;
    
    bool reaches = false;
    
    while(u!=nullptr && v!= nullptr) {
        if(u->a == 0 && u->b == 0) {
            reaches=true;
        }
        if(Ca==v->a && u->b == v->b) { //fill a
            aq.push("fill A");
        }
        else if(Cb==v->b && u->a==v->a) { //fill b
            aq.push("fill B");
        }
        else if(v->a==0 && u->a!=0 && u->b==v->b) { //empty a
            aq.push("empty A");
        }
        else if(v->b==0 && u->b!=0 && u->a==v->a) { //empty b
            aq.push("empty A");
        }
        else if( (v->a==0&&v->b==(u->a+u->b) ) || (v->b==Cb && v->a==(u->a+u->b-Cb) ) ) {//A->B
            aq.push("pour A B");
        }
        else if( (v->b==0&&v->a==(u->b+u->a) ) || (v->a==Ca && v->b==(u->b+u->a-Ca) ) ) {//B->A)
            aq.push("pour B A");
        }
        else {

        }
        u=u->prev;
        v=v->prev;
    }
    
    while(! aq.empty()) {
        sol += aq.top();
        sol += "\n";
        aq.pop();
    }
    
    if(reaches) {
        sol += "success ";
        sol += to_string(ans->dist);
        sol += "\n";
        return 1;
    }
    
    return 0;
}
