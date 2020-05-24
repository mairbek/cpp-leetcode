#include <iostream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace {
// https://leetcode.com/problems/word-break/
// DP O(N * M)
class Solution {
 public:
  bool wordBreak(std::string s, std::vector<std::string>& words) {
    // std::unordered_map<int, bool> cache;
    // return loop(s, 0, words, cache);
    return dp(s, words);
  }

  bool dp(std::string_view sv, std::vector<std::string>& words) {
    int n = sv.length();
    bool dp[n + 1];
    dp[0] = true;
    for (int i = 0; i < n; i++) {
      dp[i + 1] = false;
      for (auto& word : words) {
        int m = word.length();
        if (i < (m - 1)) {
          continue;
        }
        bool match = true;
        for (int j = 0; j < m; j++) {
          if (sv[i - m + 1 + j] != word[j]) {
            match = false;
            break;
          }
        }
        if (match && dp[i - m + 1]) {
          dp[i + 1] = true;
          break;
        }
      }
    }
    for (int i = 0; i <= n; i++) {
      std::cout << dp[i] << " ";
    }
    std::cout << std::endl;
    return dp[n];
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
  std::cout << s << " | " << result << std::endl;
}

int main(int argc, const char** argv) {
  solve("leetcode", std::vector<std::string>{"leet", "code"});
  solve("applepenapple", std::vector<std::string>{"apple", "pen"});
  solve("catsandog",
        std::vector<std::string>{"cats", "dog", "sand", "and", "cat"});
  return 0;
}