#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

namespace {
class Solution {
 public:
  std::string shiftingLetters(std::string s,
                              std::vector<std::vector<int>>& shifts) {
    std::vector<char> chars(s.begin(), s.end());
    for (auto& sh : shifts) {
      int st = sh[0];
      int en = sh[1];
      int dir = sh[2] == 1 ? 1 : -1;
      for (int i = st; i <= en; i++) {
        chars[i] = (chars[i] - 'a' + dir + 26) % 26 + 'a';
      }
    }
    std::string result(chars.begin(), chars.end());
    return result;
  }
};
}  // namespace

void solve(std::string s, std::vector<std::vector<int>> shifts) {
  Solution sol;
  auto result = sol.shiftingLetters(s, shifts);
  std::cout << s << " " << result << std::endl;
}

int main(int argc, char const** argv) {
  solve("abc", std::vector<std::vector<int>>{{0, 2, 0}});
  solve("abc", std::vector<std::vector<int>>{{0, 1, 0}, {1, 2, 1}, {0, 2, 1}});
  return 0;
}
