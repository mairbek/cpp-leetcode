#include <iostream>
#include <vector>
#include <map>

void print_lower_bound(std::map<int, int>& ordered, int key) {
  auto it = ordered.lower_bound(key);
  std::cout << "lower_bound(" << key << ") = " 
    << "(" << it->first << ", " << it->second << ")"
    << " " << (it == ordered.begin() ? "begin" : "not begin")
    << " " << (it == ordered.end() ? "end" : "not end")
    << std::endl;
}

int main(int argc, const char** argv) {
  std::map<int, int> ordered{{1, 0}, {3, 1}, {5, 2}, {7, 3}, {9, 4}};
  print_lower_bound(ordered, -1);
  print_lower_bound(ordered, 1);
  print_lower_bound(ordered, 2);
  print_lower_bound(ordered, 3);
  print_lower_bound(ordered, 4);
  return 0;
}
