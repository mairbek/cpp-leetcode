#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    int m;
    std::cin >> m;

    std::vector<int> seq(m);
    for (int j = 0; j < m; ++j) {
      std::cin >> seq[j];
    }

    std::unordered_set<int> visited;
    for (int i = 0; i < seq.size(); i++) {
      visited.insert(seq[i]);
    }
    std::vector<int> newseq;
    while (true) {
      int s = visited.size();
      if (newseq.size() > 0 && s == newseq[newseq.size() - 1]) {
        std::cout << s << std::endl;
        break;
      }
      visited.insert(s);
      newseq.push_back(s);
    }
  }

  return 0;
}
