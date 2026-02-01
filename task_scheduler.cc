#include <iostream>
#include <ostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

// https://leetcode.com/problems/task-scheduler/
namespace {

class Solution {
 public:
  int leastInterval(std::vector<char>& tasks, int n) {
    std::unordered_map<char, int> task_count;
    for (char task : tasks) {
      task_count[task]++;
    }
    std::priority_queue<int> pq;  // max-heap of counts
    for (auto& kv : task_count) {
      pq.push(kv.second);
    }
    std::queue<std::pair<int, int>> idle;
    int steps = 0;
    while (!pq.empty() || !idle.empty()) {
      while (!idle.empty()) {
        auto& idle_task = idle.front();
        if (idle_task.first > steps) {
          break;
        }
        pq.push(idle_task.second);
        idle.pop();
      }
      if (!pq.empty()) {
        int count = pq.top();
        if (count > 1) {
          idle.push(std::make_pair(steps + n + 1, count - 1));
        }
        pq.pop();
      }
      steps++;
    }
    return steps;
  }
};

}  // namespace

void solve(std::vector<char> tasks, int n, int expected) {
  Solution sol;
  int result = sol.leastInterval(tasks, n);
  std::cout << "n=" << n << " result=" << result << " expected=" << expected
            << std::endl;
}

int main(int argc, char const** argv) {
  // Example 1: tasks = ["A","A","A","B","B","B"], n = 2
  // Output: 8
  solve({'A', 'A', 'A', 'B', 'B', 'B'}, 2, 8);

  // Example 2: tasks = ["A","C","A","B","D","B"], n = 1
  // Output: 6
  solve({'A', 'C', 'A', 'B', 'D', 'B'}, 1, 6);

  // Example 3: tasks = ["A","A","A","B","B","B"], n = 3
  // Output: 10
  solve({'A', 'A', 'A', 'B', 'B', 'B'}, 3, 10);

  solve({'A', 'B', 'C', 'D', 'E', 'A', 'B', 'C', 'D', 'E'}, 4, 10);
  return 0;
}
