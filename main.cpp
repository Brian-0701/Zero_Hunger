#include <iostream>
#include <fstream>
#include <memory>
#include "Graph.h"
#include "Knapsack.h"

int main() {
    std::ifstream file("data/sample_input.txt");
    if (!file) {
        std::cerr << "Error: Unable to open sample_input.txt\n";
        return 1;
    }

    int n;
    file >> n;

    // Create graph using smart pointer
    std::unique_ptr<Graph> graph = std::make_unique<Graph>(n);

    // Read distance matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int distance;
            file >> distance;
            if (i < j && distance > 0) {
                graph->addEdge(i, j, distance);
            }
        }
    }

    int numItems;
    file >> numItems;

    std::vector<Item> items;
    for (int i = 0; i < numItems; ++i) {
        Item item;
        file >> item.name >> item.weight
             >> item.value >> item.shelfLife;
        items.push_back(item);
    }

    int capacity;
    file >> capacity;

    int optimalDistance = graph->tspNearestNeighbor();
    int maxValue = knapsack(capacity, items);

    std::cout << "Optimal Delivery Distance: "
              << optimalDistance << " km\n";
    std::cout << "Maximum Load Value: "
              << maxValue << "\n";

    return 0;
}