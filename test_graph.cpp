#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "../src/Graph.h"
#include "../src/Knapsack.h"

TEST_CASE("TSP computes a valid distance") {
    Graph g(3);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 20);
    g.addEdge(2, 0, 15);

    REQUIRE(g.tspNearestNeighbor() == 45);
}

TEST_CASE("Knapsack computes correct maximum value") {
    std::vector<Item> items = {
        {"PiliNuts", 5, 10, 7},
        {"Bananas", 4, 40, 3},
        {"Coconuts", 3, 50, 10}
    };

    REQUIRE(knapsack(10, items) == 90);
}