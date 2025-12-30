
#include <iostream>
#include <string>
#include <set>

// memory overflow
int solve1(std::string s, std::set<std::string>& visited) {
  if (s == "") {
    return 0;
  }
  if (visited.count(s) > 0) {
    return 0;
  }
  int result = 1;
  visited.insert(s);
  result += solve1(s.substr(1), visited);
  if (s.size() >= 2) {
    std::string without_second =
        std::string(s.substr(0, 1)) + std::string(s.substr(2));
    result += solve1(without_second, visited);
  }
  return result;
}

// memory overflow
int solve2(std::string s, char p, int i, std::set<std::pair<char, int>>& visited) {
  if (i == s.size()) {
    return 0;
  }
  if (visited.count(std::make_pair(p, i)) > 0) {
    return 0;
  }
  if (p == 0) {
      p = s[i];
  }
  int result = 1;
  visited.insert(std::make_pair(p, i));
  result += solve2(s, p, i + 1, visited);
  if ((s.size() - i) >= 2) {
    result += solve2(s, s[i+1], i + 1, visited);
  }
  return result;
}

int solve3(std::string s) {
    std::set<char> visited;
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
        // for every new character we can generate substrings
        if (visited.count(s[i]) > 0) {
            continue;
            // memory overflow
        }
        int num = s.size() - i;
        if (num > 0) {
            result += num;
        }
        visited.insert(s[i]);
    }
    return result;
}

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::set<std::pair<char, int>> visited;
    std::cout << solve3(s) << std::endl;
  }

  return 0;
}
