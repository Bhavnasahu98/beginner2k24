#include <iostream>
#include <vector>

int knapsack(int W, const std::vector<int>& weights, const std::vector<int>& values) {
    int n = weights.size();
    std::vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int w = W; w >= weights[i]; --w) {
            dp[w] = std::max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }

    return dp[W];
}

int main() {
    int W, n;
    std::cin >> W >> n;
    std::vector<int> weights(n), values(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> weights[i] >> values[i];
    }

    std::cout << knapsack(W, weights, values) << std::endl;

    return 0;
}

