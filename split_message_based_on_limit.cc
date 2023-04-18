#include <iostream>
#include <unordered_map>
#include <vector>

namespace {

class Solution {
 public:
  int intlen(int s) {
    return std::to_string(s).length();
  }

  std::vector<std::string> splitMessage(std::string s, int limit) {
    std::vector<std::string> result;

    int n = s.length();

    int num_chunks = 0;
    for (int i = 1; i <= n; i++) {
        int j = 0;
        bool overflow = false;
        int chunks = 0;
        while (j < n) {
            if (chunks >= i) {
                overflow = true;
                break;
            }
            int suf = 3 + intlen(i) + intlen(chunks);
            int k = std::min(limit - suf, n - j);
            if (k <= 0) {
                overflow = true;
                break;
            }
            j += k;
            chunks += 1;
        }
        if (!overflow) {
            num_chunks = i;
            break;
        }
    }

    int j = 0;
    for (int i = 1; i <= num_chunks; i++) {
        int suf = 3 + intlen(i) + intlen(num_chunks);
        int k = std::min(limit - suf, n - j);
        std::string rs = s.substr(j, k);
        result.push_back("" + rs + "<" + std::to_string(i) + "/" + std::to_string(num_chunks) + ">");
        j += k;
    }

    return result;
  }
};
}  // namespace

using int64 = long long;

void solve(std::string s, int limit) {
  Solution sol;
  auto result = sol.splitMessage(s, limit);
  std::cout << s << " | " << limit << " | ";
  for (auto& s : result) {
    std::cout << s << ",";
  }
  std::cout << std::endl;
}

int main(int argc, char const** argv) {
  solve("this is really a very awesome message", 9);
  solve("short message", 15);
  return 0;
}