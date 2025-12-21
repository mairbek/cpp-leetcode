
#include <iostream>
#include <string>
#include <string_view>

int solve(std::string_view s) {
    int zeros = 0, ones = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            zeros++;
        } else {
            ones++;
        }
    }
    int i = 0;
    for (; i < s.size(); i++) {
        if (s[i] == '0') {
            ones--;
            if (ones < 0) {
                break;
            }
        } else {
            zeros--;
            if (zeros < 0) {
                break;
            }
        }
    }
    return s.size() - i;
}

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    std::string s;
    std::cin >> s;
    std::cout << solve(s) << std::endl;
  }

  return 0;
}
