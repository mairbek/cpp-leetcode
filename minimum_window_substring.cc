#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

namespace {
class Solution {
 public:
  std::string minWindow(std::string s, std::string t) {
    std::unordered_map<char, int> tchars;
    for (int i = 0; i < t.length(); i++) {
      tchars[t[i]]++;
    }
    std::set<int> matches;
    std::unordered_map<char, std::set<int>> w;
    int ptr = 0;
    int min_len = s.length() + 1;
    for (int i = 0; i < s.length(); i++) {
      char ch = s[i];
      if (tchars.count(ch) == 0) {
        continue;
      }
      w[ch].insert(i);
      matches.insert(i);
      if (w[ch].size() > tchars[ch]) {
        auto f = w[ch].begin();
        matches.erase(*f);
        w[ch].erase(f);
      }
      if (matches.size() == t.length()) {
        int f = *matches.begin();
        int l = *matches.rbegin();
        int new_min_len = l - f + 1;
        if (new_min_len < min_len) {
          ptr = f;
          min_len = new_min_len;
        }
      }
      /*
      std::cout << "s[i]" << s[i] << " ";
      for (auto m : matches) {
        std::cout << m << " ";
      }
      std::cout << std::endl;
      */
    }
    if (min_len > s.length()) {
      return "";
    }
    return s.substr(ptr, min_len);
  }
};
}  // namespace

void solve(std::string s, std::string t) {
  Solution sol;
  auto result = sol.minWindow(s, t);
  std::cout << s << " " << t << " " << result << std::endl;
}

int main(int argc, char const** argv) {
  solve("ADOBECODEBANC", "ABC");
  solve("a", "a");
  solve("a", "aa");
  solve("babab", "ab");
  solve("adz", "az");
  solve("aaaabaaaaaaaazb", "azb");
  solve("cabwefgewcwaefgcf", "cae");
  return 0;
}