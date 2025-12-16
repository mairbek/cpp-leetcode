#include <iostream>
#include <vector>

long long solve(std::vector<int> const& a) {
  int n = a.size();
  int first_nonzero = 0;
  while (first_nonzero < n - 1 && a[first_nonzero] == 0) {
    first_nonzero++;
  }
  long long result = 0;
  for (int i = first_nonzero; i < n - 1; i++) {
    result += (a[i] == 0) ? 1 : a[i];
  }
  return result;
}

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    std::cout << solve(a) << std::endl;
  }

  return 0;
}
