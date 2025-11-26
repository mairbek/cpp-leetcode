#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

namespace {
// https://leetcode.com/problems/maximum-performance-of-a-team/
class Solution {
 public:
  int maxPerformance(int n, std::vector<int>& speed,
                     std::vector<int>& efficiency, int k) {
    int const MOD = 1e9 + 7;
    std::vector<std::pair<int, int>> speed_efficiency;
    for (size_t i = 0; i < speed.size(); i++) {
      speed_efficiency.push_back({speed[i], efficiency[i]});
    }
    std::sort(speed_efficiency.begin(), speed_efficiency.end(),
              [](std::pair<int, int> const& a, std::pair<int, int> const& b) {
                return a.second > b.second;
              });
    long long result = 0;
    long long total_speed = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    for (int i = 0; i < speed_efficiency.size(); i++) {
      int s = speed_efficiency[i].first;
      int e = speed_efficiency[i].second;
      q.push(s);
      total_speed += s;
      if (q.size() > k) {
        total_speed -= q.top();
        q.pop();
      }

      if (total_speed * e > result) {
        result = total_speed * e;
      }
    }
    return result % MOD;
  }
};
}  // namespace

void solve(int n, std::vector<int> speed, std::vector<int> efficiency, int k,
           int expected) {
  Solution sol;
  int result = sol.maxPerformance(n, speed, efficiency, k);
  std::cout << "n=" << n << " k=" << k << " speed=[";
  for (size_t i = 0; i < speed.size(); i++) {
    if (i > 0) std::cout << ",";
    std::cout << speed[i];
  }
  std::cout << "] efficiency=[";
  for (size_t i = 0; i < efficiency.size(); i++) {
    if (i > 0) std::cout << ",";
    std::cout << efficiency[i];
  }
  std::cout << "] => " << result;
  if (result == expected) {
    std::cout << " ✓";
  } else {
    std::cout << " ✗ (expected " << expected << ")";
  }
  std::cout << std::endl;
}

int main(int argc, char const** argv) {
  // Example 1
  solve(6, {2, 10, 3, 1, 5, 8}, {5, 4, 3, 9, 7, 2}, 2, 60);

  // Example 2
  solve(6, {2, 10, 3, 1, 5, 8}, {5, 4, 3, 9, 7, 2}, 3, 68);

  // Example 3
  solve(6, {2, 10, 3, 1, 5, 8}, {5, 4, 3, 9, 7, 2}, 4, 72);

  return 0;
}
