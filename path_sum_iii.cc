#include <iostream>
#include <unordered_map>

// https://leetcode.com/problems/path-sum-iii/
namespace {

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  void dfs(TreeNode* node, int target_sum, long long current_sum,
           std::unordered_map<long long, int>& sum_counts, int& result) {
    if (node == nullptr) {
      return;
    }
    current_sum += node->val;
    auto it = sum_counts.find(current_sum - target_sum);
    if (it != sum_counts.end()) {
      result += it->second;
    }
    sum_counts[current_sum]++;
    dfs(node->left, target_sum, current_sum, sum_counts, result);
    dfs(node->right, target_sum, current_sum, sum_counts, result);
    sum_counts[current_sum]--;
  }

  int pathSum(TreeNode* root, int target_sum) {
    std::unordered_map<long long, int> sum_counts;
    sum_counts[0] = 1;
    int result = 0;
    dfs(root, target_sum, 0, sum_counts, result);
    return result;
  }
};
}  // namespace

void solve(TreeNode* root, int targetSum, int expected) {
  Solution sol;
  int result = sol.pathSum(root, targetSum);
  std::cout << "targetSum=" << targetSum << " result=" << result
            << " expected=" << expected << std::endl;
}

int main(int argc, char const** argv) {
  // Example 1: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
  // Expected output: 3
  {
    TreeNode* root = new TreeNode(
        10,
        new TreeNode(5, new TreeNode(3, new TreeNode(3), new TreeNode(-2)),
                     new TreeNode(2, nullptr, new TreeNode(1))),
        new TreeNode(-3, nullptr, new TreeNode(11)));
    solve(root, 8, 3);
  }
  // Example 2: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
  // Expected output: 3
  {
    TreeNode* root = new TreeNode(
        5,
        new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)),
                     nullptr),
        new TreeNode(8, new TreeNode(13),
                     new TreeNode(4, new TreeNode(5), new TreeNode(1))));
    solve(root, 22, 3);
  }
  return 0;
}
