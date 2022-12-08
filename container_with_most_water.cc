#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

namespace {
class Solution {
 public:
  int maxArea(std::vector<int>& height) {
    int max_area = 0;
    for (int i = 0; i < height.size(); i++) {
        for (int j = i + 1; j < height.size(); j++) {
            int area = std::min(height[i], height[j]) * (j - i);
            if (area > max_area) {
                max_area = area;
            }
        }
    }
    return max_area;
  }
};
}  // namespace

void solve(std::vector<int> height) {
  Solution sol;
  auto result = sol.maxArea(height);
  std::cout << "[";
  for (uint i = 0; i < height.size(); i++) {
    if (i > 0) {
      std::cout << ", ";
    }
    std::cout << height[i];
  }
  std::cout << "] " << result << std::endl;
}

int main(int argc, char const** argv) {
  solve(std::vector<int>{1, 8, 6, 2, 5, 4, 8, 3, 7});
  solve(std::vector<int>{1, 1});
  solve(std::vector<int>{1});
  return 0;
}
