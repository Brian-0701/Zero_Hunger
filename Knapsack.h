#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <vector>
#include <string>

struct Item {
    std::string name;
    int weight;
    int value;
    int shelfLife;
};

int knapsack(int capacity, const std::vector<Item>& items);

#endif