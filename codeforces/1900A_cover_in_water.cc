#include <iostream>
#include <string>
#include <string_view>

int solve(std::string_view s) {
    int total_empty = 0;
    int conseq_empty = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
            conseq_empty++;
            if (conseq_empty == 3) {
                return 2;
            }
            total_empty++;
        } else {
            conseq_empty = 0;
        }
    }
    return total_empty;
}

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::cout << solve(s) << std::endl;
  }

  return 0;
}
