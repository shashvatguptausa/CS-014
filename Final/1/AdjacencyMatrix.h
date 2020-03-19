#ifndef __ADJACENCYMATRIX_H__
#define __ADJACENCYMATRIX_H__

#include "Graph.h"

#include <string>
#include <vector>

class AdjacencyMatrix : public Graph {
private:
    std::vector<std::vector<int>> al;
    std::vector<int> distances;
    std::vector<int> previous;
    int vert;
    int edge;
    
public:
    AdjacencyMatrix(std::string filename);
    
    int vertices() const;
    int edges() const;
    int distance(int i) const;
    std::string path(int i) const;
    void bfs(int);
    void dfs(int);
    void dfs(int, int, int, bool[]); //recur helper
    void display() const;
    
};

#endif // __ADJACENCYMATRIX_H__
