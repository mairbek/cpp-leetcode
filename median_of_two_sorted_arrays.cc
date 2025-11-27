#include <iostream>
#include <vector>

namespace {
class Solution {
 public:
  double findMedianSortedArrays(std::vector<int>& a, std::vector<int>& b) {
    // Make sure nums1 is the smaller array (or handle empty case)
    if (a.size() > b.size()) {
      return findMedianSortedArrays(b, a);
    }

    // If nums1 is empty, just find median of nums2
    if (a.empty()) {
      int n = b.size();
      if (n % 2 == 1) {
        return b[n / 2];
      } else {
        return (b[n / 2 - 1] + b[n / 2]) / 2.0;
      }
    }

    int left = 0, right = a.size();
    while (left <= right) {
      int m = (left + right) / 2;
      int mb = (a.size() + b.size() + 1) / 2 - m;

      int maxLeftA = (m == 0) ? INT_MIN : a[m - 1];
      int minRightA = (m == a.size()) ? INT_MAX : a[m];
      int maxLeftB = (mb == 0) ? INT_MIN : b[mb - 1];
      int minRightB = (mb == b.size()) ? INT_MAX : b[mb];

      if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
        if ((a.size() + b.size()) % 2 == 1) {
          return std::max(maxLeftA, maxLeftB);
        } else {
          return (std::max(maxLeftA, maxLeftB) +
                  std::min(minRightA, minRightB)) /
                 2.0;
        }
      } else if (maxLeftA > minRightB) {
        // Too many elements from a, move left
        right = m - 1;
      } else {
        // Too few elements from a, move right
        left = m + 1;
      }
    }
    return 0.0;
  }
};
}  // namespace

void solve(std::vector<int> nums1, std::vector<int> nums2, double expected) {
  Solution sol;
  auto result = sol.findMedianSortedArrays(nums1, nums2);
  std::cout << "nums1 = [";
  for (uint i = 0; i < nums1.size(); i++) {
    if (i > 0) {
      std::cout << ",";
    }
    std::cout << nums1[i];
  }
  std::cout << "], nums2 = [";
  for (uint i = 0; i < nums2.size(); i++) {
    if (i > 0) {
      std::cout << ",";
    }
    std::cout << nums2[i];
  }
  std::cout << "] | Expected: " << expected << " | Got: " << result
            << std::endl;
}

int main(int argc, char const** argv) {
  solve(std::vector<int>{1, 3}, std::vector<int>{2}, 2.00000);
  solve(std::vector<int>{1, 2}, std::vector<int>{3, 4}, 2.50000);
  solve(std::vector<int>{1, 3, 8, 9, 15},
        std::vector<int>{7, 11, 18, 19, 21, 25}, 11);
  return 0;
}
