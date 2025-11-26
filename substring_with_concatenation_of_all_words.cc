#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

namespace {
class Solution {
 public:
  std::vector<int> findSubstring(std::string s,
                                 std::vector<std::string>& words) {
    std::vector<int> result;

    std::unordered_map<std::string, int> wc;
    for (int i = 0; i < words.size(); i++) {
      wc[words[i]] += 1;
    }

    int wl = words[0].length();

    for (int i = 0; i < s.length(); i++) {
      std::unordered_map<std::string, int> wwc;
      bool fail = false;
      for (int k = 0; k < words.size(); k++) {
        int ik = i + wl * k;
        auto ss = s.substr(ik, wl);
        if (wc[ss] == 0) {
          fail = true;
          break;
        }
        wwc[ss]++;
      }
      if (!fail) {
        for (auto& wcit : wc) {
          if (wcit.second != wwc[wcit.first]) {
            fail = true;
            break;
          }
        }
      }
      if (!fail) {
        result.push_back(i);
      }
    }

    return result;
  }
};
}  // namespace

using int64 = long long;

void solve(std::string s, std::vector<std::string> words) {
  Solution sol;
  auto result = sol.findSubstring(s, words);
  std::cout << s << " | ";
  for (auto rr : result) {
    std::cout << rr << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char const** argv) {
  solve("barfoothefoobarman", std::vector<std::string>{"foo", "bar"});
  solve("wordgoodgoodgoodbestword",
        std::vector<std::string>{"word", "good", "best", "word"});
  solve("barfoofoobarthefoobarman",
        std::vector<std::string>{"bar", "foo", "the"});
  return 0;
}
