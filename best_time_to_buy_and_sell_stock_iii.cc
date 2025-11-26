#include <iostream>
#include <vector>

namespace {
class Solution {
 public:
  int maxProfit(std::vector<int>& prices) {
    int n = prices.size();
    std::vector<int> max_prices(n);
    int min = prices[0];
    max_prices[0] = 0;
    for (uint i = 1; i < n; i++) {
      if (prices[i] < min) {
        min = prices[i];
      }
      int result = max_prices[i - 1];
      int p = prices[i] - min;
      if (p > result) {
        result = p;
      }
      max_prices[i] = result;
    }
    int max = 0;
    int result = 0;
    for (uint i = 0; i < n; i++) {
      int mp = 0;
      if (i > 0) {
        mp = max_prices[i - 1];
      }
      int cost = -prices[i] + mp;
      if (i == 0 || max < cost) {
        max = cost;
      }
      int p = prices[i] + max;
      if (p > result) {
        result = p;
      }
    }
    return result;
  }
};
}  // namespace

void solve(std::vector<int> prices) {
  Solution sol;
  int result = sol.maxProfit(prices);
  std::cout << "[";
  for (uint i = 0; i < prices.size(); i++) {
    if (i > 0) {
      std::cout << ", ";
    }
    std::cout << prices[i];
  }
  std::cout << "] -> " << result << std::endl;
}

int main(int argc, char const** argv) {
  // Example 1
  solve(std::vector<int>{3, 3, 5, 0, 0, 3, 1, 4});  // Expected: 6

  // Example 2
  solve(std::vector<int>{1, 2, 3, 4, 5});  // Expected: 4

  // Example 3
  solve(std::vector<int>{7, 6, 4, 3, 1});  // Expected: 0

  return 0;
}
