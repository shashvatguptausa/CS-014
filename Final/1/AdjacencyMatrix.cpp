//
//  AdjacencyMatrix.cpp
//  Test
//
//  Created by Shashvat Gupta on 3/17/20.
//  Copyright © 2020 Shashvat Gupta. All rights reserved.
//

#include "AdjacencyMatrix.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

AdjacencyMatrix::AdjacencyMatrix(string filename) {
    
    
    
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
    vector<int> path;
    vector<int> previous;
    
    for (unsigned i = 0; i < vert; i++) {
        al.push_back( *(new vector<int>));
        for(int w = 0; w < vert; w++) {
            al.at(i).push_back(0);
        }
    }
    
    int source, sink;
    file>>source;
    file>>sink;
    while(source!=-1&&sink!=-1) {
        al.at(source).at(sink)=1;
        source=-1;
        sink=-1;
        file>>source;
        file>>sink;
        edge++;
    }
    
    
    if(edge==0) {
        vert=0;
        edge=0;
        return;
    }
}

int AdjacencyMatrix::vertices() const {
    if(vert<=0) {
        return 0;
    }
    return vert;
}
int AdjacencyMatrix::edges() const {
    if(edge<=0||vert==0) {
        return 0;
    }
    return edge;
}
int AdjacencyMatrix::distance(int i) const {
    
    if(i<0||i>distances.size()) {
        
    }
    
    return distances.at(i);
}
string AdjacencyMatrix::path(int i) const {
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

//  V=Number of Vertices
//Overall runtime complexity: O(V^2)
//Overall space complexity: O(V^2)
void AdjacencyMatrix::bfs(int in) {
    
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
    
    distances.at(in)=0; //O(1)
    
    while(!q.empty()) { //O(V^2)
        
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
        
        for(int i = 0; i < vertices(); i++) {      //O(V)
            if(al.at(u).at(i)==1) { //O(1)
                v=i; //O(1)
                if(distances.at(v) > distances.at(u)+1) { //O(1)
                    distances.at(v) = distances.at(u)+1; //O(1)
                    previous.at(v) = u; //O(1)
                }
                //RELAX
            }
        }
        
        q.erase(q.begin()+pos);   //O(V)
    }
    //display();
}

//-------------------------------------------------------------------------

//recursive helper
void AdjacencyMatrix::dfs(int pre, int dist, int v, bool visited[])
{
    visited[v] = true;  //O(1)
    //cout << "from " << pre << " to: " << v << endl;
    
    if(distances.at(v)>dist) {      //O(1)
        distances.at(v)=dist;   //O(1)
        if(pre>=0) {    //O(1)
            previous.at(v)=pre; //O(1)
        }
    }
    
    for (int i = 0; i < vertices(); i++) {     //O(V^2)
        if (al.at(v).at(i)==1 && visited[i] == false) {  //O(1)
            dfs(v, dist+1, i, visited);    //O(V)
        }
    }
}

//  V=Number of Vertices
//Overall runtime complexity: O(V^2)
//Overall space complexity: O(V^2)
void AdjacencyMatrix::dfs(int in) {
    
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
    dfs(-1, 0, in, visited);     //O(V^2)
    
}


//-------------------------------------------------------------------------

void AdjacencyMatrix::display() const {
    
}
