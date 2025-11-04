#include <iostream>
#include <map>
#include <vector>

// https://leetcode.com/problems/falling-squares/description/
namespace {
class Solution {
 public:
  int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
    std::sort(envelopes.begin(), envelopes.end(), [&](std::vector<int>&a,std::vector<int>&b){
        if(a[0]==b[0]) {
            return a[1]>b[1];
        }
        return a[0]<b[0];
    });

    if (envelopes.size() == 0) {
      return 0;
    }
    std::vector<int> lis(envelopes.size(), 0);
    lis[0] = 1;
    int result = 1;
    for (int i = 1; i < envelopes.size(); i++) {
      int max = 0;
      for (int j = 0; j < i; j++) {
        if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
          if (max < lis[j]) {
            max = lis[j];
          }
        }
      }
      lis[i] = 1 + max;
      if (result < lis[i]) {
        result = lis[i];
      }
    }
    return result;
  }
};
}  // namespace

void solve(std::vector<std::vector<int>> s) {
  Solution sol;
  int result = sol.maxEnvelopes(s);
  std::cout << result << std::endl;
}

int main(int argc, char const** argv) {
  solve(std::vector<std::vector<int>>{{5, 4}, {6, 4}, {6, 7}, {2, 3}});
  solve(std::vector<std::vector<int>>{{1, 1}, {1, 1}, {1, 1}});
  return 0;
}
