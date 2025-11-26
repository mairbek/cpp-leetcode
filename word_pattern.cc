#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

namespace {
class Solution {
 public:
  bool wordPattern(std::string pattern, std::string s) {
    std::stringstream ss(s);
    std::vector<std::string> tokens;
    std::string token;
    while (std::getline(ss, token, ' ')) {
      tokens.push_back(token);
    }
    if (pattern.size() != tokens.size()) {
      return false;
    }
    std::unordered_map<char, std::string> map;
    std::unordered_map<std::string, char> reverse;
    for (int i = 0; i < pattern.size(); i++) {
      auto it = map.find(pattern[i]);
      auto rit = reverse.find(tokens[i]);
      if (it == map.end() && rit == reverse.end()) {
        map[pattern[i]] = tokens[i];
        reverse[tokens[i]] = pattern[i];
      } else {
        if (it == map.end() || rit == reverse.end()) {
          return false;
        }
        if (it->second != tokens[i] || rit->second != pattern[i]) {
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
  auto result = sol.wordPattern(s, t);
  std::cout << s << " " << t << " " << result << std::endl;
}

int main(int argc, char const** argv) {
  solve("abba", "dog cat cat dog");
  solve("abba", "dog cat cat fish");
  solve("aaaa", "dog cat cat dog");
  solve("aaaa", "dog dog dog dog");
  solve("x", "dog");
  return 0;
}
