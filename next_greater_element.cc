#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

namespace {
class Solution {
 public:
  std::vector<int> nextGreaterElement(std::vector<int>& nums1,
                                      std::vector<int>& nums2) {
    std::unordered_map<int, int> m;
    std::stack<int> st;
    st.push(-1);
    for (int i = nums2.size() - 1; i >= 0; i--) {
      while (!st.empty() && st.top() <= nums2[i]) {
        st.pop();
      }
      int next = -1;
      if (!st.empty()) {
        next = st.top();
      }
      m[nums2[i]] = next;
      st.push(nums2[i]);
    }
    for (int i = 0; i < nums1.size(); i++) {
      nums1[i] = m[nums1[i]];
    }
    return nums1;
  }
};
}  // namespace

void solve(std::vector<int> nums1, std::vector<int> nums2) {
  Solution sol;
  auto result = sol.nextGreaterElement(nums1, nums2);
  for (int i = 0; i < result.size(); i++) {
    std::cout << result[i] << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char const** argv) {
  solve(std::vector<int>{4, 1, 2}, std::vector<int>{1, 3, 4, 2});
  return 0;
}