#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
private:
    int vertices;
    std::vector<std::vector<int>> adjMatrix;

public:
    Graph(int v);
    void addEdge(int u, int v, int weight);
    int tspNearestNeighbor(int start = 0) const;
};

#endif