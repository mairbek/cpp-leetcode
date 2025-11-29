#include <iostream>
#include <string>
#include <unordered_map>

int main() {
  // Read from stdin
  int n;
  std::string s;
  std::cin >> n >> s;

  std::unordered_map<std::string, int> counts;
  int max = 0;
  std::string res;
  for (int i = 1; i < s.length(); i++) {
      std::string cur;
      cur += s[i-1];
      cur += s[i];
      counts[cur]++;
      if (counts[cur] > max) {
          max = counts[cur];
          res = cur;
      }
  }

  std::cout << res << std::endl;

  return 0;
}
