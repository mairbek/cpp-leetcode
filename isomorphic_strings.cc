#include <iostream>
#include <unordered_map>

namespace {
class Solution {
 public:
  bool isIsomorphic(std::string s, std::string t) {
    if (s.size() != t.size()) {
      return false;
    }
    std::unordered_map<char, char> map;
    std::unordered_map<char, char> reverse;
    for (int i = 0; i < s.size(); i++) {
      auto it = map.find(s[i]);
      auto rit = reverse.find(t[i]);
      if (it == map.end() && rit == reverse.end()) {
        map[s[i]] = t[i];
        reverse[t[i]] = s[i];
      } else {
        if (it == map.end() || rit == reverse.end()) {
          return false;
        }
        if (it->second != t[i] || rit->second != s[i]) {
          return false;
        }
      }
    }
    return true;
  }
};
}  // namespace

void solve(std::string s, std::string t) {
  Solution sol;
  auto result = sol.isIsomorphic(s, t);
  std::cout << s << " " << t << " " << result << std::endl;
}

int main(int argc, char const** argv) {
  solve("egg", "add");
  solve("foo", "bar");
  solve("paper", "title");
  solve("badc", "baba");
  return 0;
}
