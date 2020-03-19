//
//  AdjacencyList.cpp
//  Test
//
//  Created by Shashvat Gupta on 3/17/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//

#include "AdjacencyList.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

AdjacencyList::AdjacencyList(string filename) {
    
    
    
    string vertices;
    fstream file;
    file.open(filename);
    
    getline(file, vertices);
    
    
    
    if(vertices=="") {
        vert=0;
        edge=0;
        return;
    }
        
    vert = stoi (vertices,nullptr,0);
    
    vector<int> distances;
    vector<int> previous;
    
    for (unsigned i = 0; i < stoi (vertices,nullptr,0);++i) {
        al.push_back( *(new list<int>));
    }
    
    int source, sink;
    file>>source;
    file>>sink;
    while(source!=-1&&sink!=-1) {
        al.at(source).push_back(sink);
        
        source=-1;
        sink=-1;
        
        file>>source;
        file>>sink;
        edge++;
    }
}

int AdjacencyList::vertices() const {
    if(vert<=0) {
        return 0;
    }
    return vert;
}
int AdjacencyList::edges() const {
    if(edge<0||vert==0) {
        return 0;
    }
    return edge;
}
int AdjacencyList::distance(int i) const {
    
//    if(i<0||i>distances.size()) {
//        cout << "ERROR IN DIST"<< endl;
//    }
    return distances.at(i);
}
string AdjacencyList::path(int i) const {
    stack<int> p;
    int curr=i;
    while(curr!=0) {
        p.push(curr);
        curr=previous.at(curr);
    }
    
    string ans = "{0";
    
    while (!p.empty()) {
        ans+="->";
        ans+= to_string(p.top());
        p.pop();
    }
    
    ans+="}";
    
    return ans;
}

// V=Numver of Vertices, E=Number of Edges
//Overall runtime complexity: O(V(V+E))
//Overall space complexity: O(V^2)
void AdjacencyList::bfs(int) {
    
    if(edge<=0) { //O(1)
        return; //O(1)
    }
    
    vector<int> cloud; //O(1)
    vector<int> q; //O(1)
    
    for(int i = 0; i < vertices(); i++) { // O(V)
        distances.push_back(999); //O(1)
        previous.push_back(-1); //O(1)
        q.push_back(i); //O(1)
    }
    
    distances.at(0)=0; //O(1)

    
    while(!q.empty()) { //O(V(V+E))
        
        int u = -1; //O(1)
        int v = -1; //O(1)
        int pos = -1; //O(1)
        
        int low=999; //O(1)
        for (int i = 0; i<q.size(); i++) {      //O(V)
            if(low>distances.at(q.at(i))) { //O(1)
                low=distances.at(q.at(i)); //O(1)
                u = q.at(i); //O(1)
                pos = i; //O(1)
            }
        }
        
        cloud.push_back(u); //O(1)
        
        list<int>::iterator it;
        for(it = al.at(u).begin(); it != al.at(u).end(); it++) {      //O(E)
            v= *it; //O(1)
            if(distances.at(v) > distances.at(u)+1) { //O(1)
                distances.at(v) = distances.at(u)+1; //O(1)
                previous.at(v) = u; //O(1)
            }
            //RELAX
        }
        q.erase(q.begin()+pos);   //O(N)
    }
    display();
}

//-------------------------------------------------------------------------

void AdjacencyList::dfs(int pre, int dist, int v, bool visited[])
{
    visited[v] = true;  //O(1)
        
    if(distances.at(v)>dist) {      //O(1)
        distances.at(v)=dist;   //O(1)
        if(pre>=0) {    //O(1)
            previous.at(v)=pre; //O(1)
        }
    }
    
    list<int>::iterator it;
    for(it = al.at(v).begin(); it != al.at(v).end(); it++) { //O(E)
        if (visited[*it] == false) {  //O(1)
            dfs(v, dist+1, *it, visited);
        }
    }
}

// V=Numver of Vertices, E=Number of Edges
//Overall runtime complexity: O(V+E)
//Overall space complexity: O(V+E)
void AdjacencyList::dfs(int) {
    
    if(edge<=0) {   //O(1)
        return; //O(1)
    }
    
    bool visited[vertices()];   //O(1)
    
    distances.clear();  //O(1)
    previous.clear();   //O(1)
    
    for(int i = 0; i < vertices(); i++) { // O(V)
        distances.push_back(999); //O(1)
        previous.push_back(-1); //O(1)
    }
    
    distances.at(0)=0;  //O(1)
    
    for(int i = 0; i < vertices(); i++) {   //O(V)
        visited[i]=false;   //O(1)
    }
            dfs(-1, 0, 0, visited);     //O(E)
}


//-------------------------------------------------------------------------

void AdjacencyList::display() const {
    
}
