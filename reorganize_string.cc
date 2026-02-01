#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>

// https://leetcode.com/problems/reorganize-string/
namespace {

class Solution {
 public:
  std::string reorganizeString(std::string s) {
    std::string result;
    std::unordered_map<char, int> frequency;
    for (char c : s) {
      frequency[c]++;
    }
    std::priority_queue<std::pair<int, char>> q;
    for (auto& kv : frequency) {
      q.push(std::make_pair(kv.second, kv.first));
    }
    std::queue<std::pair<int, char>> stash;
    while (!q.empty()) {
      auto kv = q.top();
      q.pop();
      if (!stash.empty()) {
          q.push(stash.front());
          stash.pop();
      }
      if (kv.first > 1) {
        stash.push(std::make_pair(kv.first - 1, kv.second));
      }
      result += kv.second;
    }
    if (!stash.empty()) {
        return "";
    }

    return result;
  }
};

}  // namespace

void solve(std::string s, std::string expected) {
  Solution sol;
  std::string result = sol.reorganizeString(s);
  std::cout << "s=\"" << s << "\" result=\"" << result << "\" expected=\""
            << expected << "\"" << std::endl;
}

int main(int argc, char const** argv) {
  // Example 1: s = "aab"
  // Output: "aba"
  solve("aab", "aba");

  // Example 2: s = "aaab"
  // Output: ""
  solve("aaaab", "");
  solve("aabc", "acba");

  return 0;
}
