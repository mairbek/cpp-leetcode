#include <iostream>
#include <string>
#include <utility>

// https://leetcode.com/problems/minimum-number-of-frogs-croaking/
namespace {

class Solution {
 public:
  int minNumberOfFrogs(std::string croakOfFrogs) {
    std::string s = "croak";
    std::vector<int> counts(s.length());
    int result = 0, active = 0;
    for (size_t i = 0; i < croakOfFrogs.length(); i++) {
        int idx = s.find(croakOfFrogs[i]);
        if (idx == 0) {
            active++;
            result = std::max(active, result);
        }
        counts[idx]++;
        if (idx > 0) {
            counts[idx - 1]--;
            if (counts[idx - 1] < 0) {
                return -1;
            }
        }
        if (idx == s.length() - 1) {
            active--;
        }
    }
    if (active > 0) {
        return -1;
    }
    return result;
  }
};

}  // namespace

void solve(std::string croakOfFrogs, int expected) {
  Solution sol;
  int result = sol.minNumberOfFrogs(croakOfFrogs);
  std::cout << "croakOfFrogs=\"" << croakOfFrogs << "\" result=" << result
            << " expected=" << expected << std::endl;
}

int main(int argc, char const** argv) {
  // Example 1: croakOfFrogs = "croakcroak"
  // Output: 1
  solve("croakcroak", 1);

  // Example 2: croakOfFrogs = "crcoakroak"
  // Output: 2
  solve("crcoakroak", 2);

  // Example 3: croakOfFrogs = "croakcrook"
  // Output: -1
  solve("croakcrook", -1);

  return 0;
}
