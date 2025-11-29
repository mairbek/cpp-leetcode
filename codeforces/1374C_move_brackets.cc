#include <iostream>
#include <string>

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;

  int balance = 0;
  int result = 0;
  for (int i = 0; i < n; i++) {
    balance += (s[i] == '(') ? 1 : -1;
    if (balance < 0) {
      result++;
      balance++;
    }
  }
  std::cout << result << std::endl;
}

int main() {
  int t;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}

// )()(
// (())
// 1001 = 2

// ()()()()
// (((())))
// 01011010=4

// ( )()()() 0
// (_ ()()()) 1
// (_( )()()) 0
// (_(_ ()())) 1
// (_(_( )())) 0
// (_(_(_ ()))) 1
// (_(_(_( )))) 0
