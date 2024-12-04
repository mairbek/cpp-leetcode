#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

namespace {
class Solution {
 public:
  std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
    std::stack<int> st;
    std::vector<int> results(temperatures.size(), 0);
    for (int i = 0; i < temperatures.size(); i++) {
      while (!st.empty()) {
        int j = st.top();
        if (temperatures[j] >= temperatures[i]) {
          break;
        }
        results[j] = i - j;
        st.pop();
      }
      st.push(i);
    }
    return results;
  }
};
}  // namespace

void solve(std::vector<int> nums1) {
  Solution sol;
  auto result = sol.dailyTemperatures(nums1);
  for (int i = 0; i < result.size(); i++) {
    std::cout << result[i] << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char const** argv) {
  solve(std::vector<int>{73, 74, 75, 71, 69, 72, 76, 73});
  solve(std::vector<int>{30, 40, 50, 60});
  solve(std::vector<int>{30, 60, 90});
  return 0;
}