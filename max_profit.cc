#include <iostream>
#include <vector>

namespace {
class Solution {
 public:
  int maxProfit(std::vector<int>& prices) {
    int min = prices[0];
    int result = 0;
    for (uint i = 1; i < prices.size(); i++) {
      if (prices[i] < min) {
        min = prices[i];
      }
      int p = prices[i] - min;
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
  std::cout << "] " << result << std::endl;
}

int main(int argc, char const** argv) {
  solve(std::vector<int>{7, 1, 5, 3, 6, 4});
  solve(std::vector<int>{7, 6, 4, 3, 1});
  return 0;
}
