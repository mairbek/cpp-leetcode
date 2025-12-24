#include <iostream>
#include <vector>

using ll = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (i > 0) {
            sum += abs(a[i] - a[i-1]);
        }
    }

    int result = sum;
    for (int i = 0; i < n; ++i) {
        int sub = 0;
        int add = 0;
        if (i > 0) {
            sub += abs(a[i] - a[i-1]);
        }
        if (i < (n-1)) {
            sub += abs(a[i+1] - a[i]);
        }
        if (i > 0 && i < (n-1)){
            add += abs(a[i+1] - a[i-1]);
        }
        result = std::min(result, sum - sub + add);
    }

    std::cout << result << std::endl;

  }
  return 0;
}
