#include <iostream>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace {
// https://leetcode.com/problems/text-justification/
class Solution {
 public:
  int div(int x, int y) {
    return x/y + (x % y != 0);
  }
  std::vector<std::string> fullJustify(std::vector<std::string>& words,
                                       int maxWidth) {
    std::vector<std::string> result;

    int start = 0;
    int word_count = 0;

    for (int i = 0; i < words.size(); i++) {
      std::vector<std::tuple<int, int, int, int>> windows;
      if (word_count + words[i].length() + (i - start) > maxWidth) {
        int num_spaces = maxWidth - word_count;
        int sp = div(num_spaces, (i - 1 - start));
        windows.emplace_back(start, i - 1, num_spaces, sp);
        start = i;
        word_count = 0;
      }
      if (i == (words.size() - 1)) {
        word_count += words[i].length();
        int num_spaces = maxWidth - word_count;
        int sp = 1;
        windows.emplace_back(start, i + 1, num_spaces, sp);
      }
      for (auto w : windows) {
        int wl = std::get<0>(w);
        int wr = std::get<1>(w);
        int num_spaces = std::get<2>(w);
        int sp = std::get<3>(w);

        // justify
        int ns = num_spaces;
        std::string s = "";
        for (int j = wl; j <= wr; j++) {
          if (j > wl) {
            int ss = sp;
            if (j == wr) {
              ss = ns;
            }
            for (int k = 0; k < ss; k++) {
              s += " ";
              ns--;
            }
          }
          s += words[j];
        }
        for (int k = 0; k < ns; k++) {
          s += " ";
        }
        result.push_back(s);
      }
      if (windows.size() > 0) {
        word_count = 0;
        start = i;
      }
      word_count += words[i].length();
    }

    return result;
  }
};
}  // namespace

using int64 = long long;

void solve(std::vector<std::string> words, int maxWidth) {
  Solution sol;
  auto result = sol.fullJustify(words, maxWidth);
  std::cout << "words: ";
  for (auto& word : words) {
    std::cout << word << " ";
  }
  std::cout << std::endl;
  for (auto& line : result) {
    std::cout << "|" << line << "|" << std::endl;
  }
}

int main(int argc, char const** argv) {
  solve(std::vector<std::string>{"This", "is", "an", "example", "of", "text",
                                 "justification."},
        16);
  solve(std::vector<std::string>{"What", "must", "be", "acknowledgment",
                                 "shall", "be"},
        16);
  solve(std::vector<std::string>{"Science", "is", "what", "we", "understand",
                                 "well", "enough", "to", "explain", "to", "a",
                                 "computer.", "Art", "is", "everything", "else",
                                 "we", "do"},
        20);
  return 0;
}


// 5