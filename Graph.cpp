#include "Graph.h"
#include <limits>

Graph::Graph(int v) : vertices(v), adjMatrix(v, std::vector<int>(v, 0)) {}

void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}

int Graph::tspNearestNeighbor(int start) const {
    if (vertices <= 1) return 0;

    std::vector<bool> visited(vertices, false);
    int current = start;
    int totalDistance = 0;
    visited[current] = true;

    for (int i = 1; i < vertices; ++i) {
        int nearest = -1;
        int minDist = std::numeric_limits<int>::max();

        for (int j = 0; j < vertices; ++j) {
            if (!visited[j] && adjMatrix[current][j] > 0 &&
                adjMatrix[current][j] < minDist) {
                nearest = j;
                minDist = adjMatrix[current][j];
            }
        }

        if (nearest == -1) break;

        visited[nearest] = true;
        totalDistance += minDist;
        current = nearest;
    }

    // Return to starting point
    if (adjMatrix[current][start] > 0)
        totalDistance += adjMatrix[current][start];

    return totalDistance;
}