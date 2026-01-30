#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

namespace {
class Solution {
 public:
  long long countPairs(std::vector<std::string>& words) {
      long long result = 0;
      std::unordered_map<std::string, int> visited;
      for (size_t i = 0; i < words.size(); i++) {
        std::string w = words[i];
        int diff = w[0] - 'a';
        for (size_t k = 0; k < w.size(); k++) {
            int d = (w[k] - 'a' - diff + 26) % 26;
            w[k] = 'a' + d;
        }
        // std::cout << words[i] << " " << w << std::endl;
        visited[w]++;
      }
      for (const auto& kv : visited) {
          long long n = kv.second;
          result += n * (n - 1) / 2;
      }
      return result;
  }
};
}  // namespace

void solve(std::vector<std::string> words, long long expected) {
  Solution sol;
  long long result = sol.countPairs(words);
  std::cout << "[";
  for (size_t i = 0; i < words.size(); i++) {
    if (i > 0) {
      std::cout << ", ";
    }
    std::cout << "\"" << words[i] << "\"";
  }
  std::cout << "] => " << result << " (expected: " << expected << ")"
            << std::endl;
}

int main(int argc, char const** argv) {
  solve({"fusion", "layout"}, 1);
  solve({"ab", "aa", "za", "aa"}, 2);
  solve({"a", "a", "a"}, 3);
  return 0;
}
