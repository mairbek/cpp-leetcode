#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

namespace {
class Solution {
 public:
  std::string minWindow(std::string s, std::string t) {
    std::unordered_multiset<char> tchars;
    for (int i = 0; i < t.length(); i++) {
      tchars.insert(t[i]);
    }

    std::vector<std::pair<int, std::unordered_multiset<char>*>> pending;
    int idx = 0;
    int min_result = s.length() + 1;
    for (int i = 0; i < s.length(); i++) {
      auto it = tchars.find(s[i]);
      if (it == tchars.end()) {
        continue;
      }
      pending.emplace_back(std::make_pair(i, new std::unordered_multiset<char>()));
      pending.back().second->insert(tchars.begin(), tchars.end());

      for (auto pit = pending.begin(); pit != pending.end(); ) {
        auto pchars = pit->second;
        auto it = pchars->find(s[i]);
        if (it != pchars->end()) {
          pchars->erase(it);
          if (pchars->size() == 0) {
            int b = pit->first;
            if (min_result > (i - b + 1)) {
              min_result = (i - b + 1);
              idx = b;
            }
            pit = pending.erase(pit);
            continue;
          }
        }
        pit++;
      }
    }
    if (min_result <= s.length()) {
      return s.substr(idx, min_result);
    }
    return "";
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
  return 0;
}