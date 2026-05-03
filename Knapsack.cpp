#include "Knapsack.h"
#include <algorithm>

int knapsack(int capacity, const std::vector<Item>& items) {
    int n = items.size();
    std::vector<std::vector<int>> dp(n + 1,
                                    std::vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = std::max(
                    items[i - 1].value +
                    dp[i - 1][w - items[i - 1].weight],
                    dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}