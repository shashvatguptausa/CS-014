#ifndef __ADJACENCYLIST_H__
#define __ADJACENCYLIST_H__

#include "Graph.h"

#include <string>
#include <vector>
#include <list>


class AdjacencyList : public Graph {
    friend struct compareDist;
private:
    std::vector<int> distances;
    std::vector<int> previous;
    
    int vert;
    int edge;
    
    std::vector<std::list<int>> al;
public:
    
    void dfs(int, int, int, bool[]);
    
    AdjacencyList(std::string filename);
    
    int vertices() const;
    int edges() const;
    int distance(int i) const;
    std::string path(int i) const;
    void bfs(int);
    void dfs(int);
    void display() const;
    
};

#endif // __ADJACENCYLIST_H__

