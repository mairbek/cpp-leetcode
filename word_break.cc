#include <iostream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace {
// https://leetcode.com/problems/word-break/
// ???
class Solution {
 public:
  bool wordBreak(std::string s, std::vector<std::string>& words) {
    std::unordered_map<int, bool> cache;
    return loop(s, 0, words, cache);
  }

  bool loop(std::string_view sv, int start, std::vector<std::string>& words,
            std::unordered_map<int, bool>& cache) {
    if (sv.empty()) {
      return true;
    }
    auto it = cache.find(start);
    if (it != cache.end()) {
      return it->second;
    }
    for (int i = 0; i < words.size(); i++) {
      if (starts_with(sv, words[i])) {
        int start = words[i].length();
        int length = sv.length() - start;
        std::string_view sub = sv.substr(start, length);
        if (loop(sub, start, words, cache)) {
          return true;
        }
        cache[start] = false;
      }
    }
    return false;
  }

  bool starts_with(std::string_view s, std::string_view prefix) {
    if (s.length() < prefix.length()) {
      return false;
    }
    for (int i = 0; i < prefix.length(); i++) {
      if (s[i] != prefix[i]) {
        return false;
      }
    }
    return true;
  }
};
}  // namespace

using int64 = long long;

void solve(std::string s, std::vector<std::string> words) {
  Solution sol;
  bool result = sol.wordBreak(s, words);
  std::cout << result << std::endl;
}

int main(int argc, const char** argv) {
  solve("leetcode", std::vector<std::string>{"leet", "code"});
  solve("applepenapple", std::vector<std::string>{"apple", "pen"});
  solve("catsandog",
        std::vector<std::string>{"cats", "dog", "sand", "and", "cat"});
  return 0;
}