#include <iostream>
#include <stack>
#include <map>
#include <vector>

// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// BFS.
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
  std::vector<std::vector<int>> verticalTraversal(TreeNode* root) {

    std::stack<std::pair<TreeNode*, int>> st;
    TreeNode* current = root;
    int level = 0;
    std::map<int, std::map<int>> vert;
    while (current != nullptr || !st.empty()) {
      if (current == nullptr) {
        auto top = st.top();
        st.pop();
        vert[top.second].insert(top.first->val);
        current = top.first->right;
        level = ++top.second;
      } else {
        st.push({current, level--});
        current = current->left;
      }
    }
    std::vector<std::vector<int>> result;
    for (auto& it : vert) {
      std::vector<int> row;
      for (int val : it.second) {
        row.push_back(val);
      }
      result.emplace_back(row);
    }
    return result;
  }
};
}  // namespace

void solve(TreeNode* node) {
  Solution sol;
  auto result = sol.verticalTraversal(node);

  for (int i = 0; i < result.size(); i++) {
    if (i > 0) {
      std::cout << ", ";
    }
    std::cout << "[";
    for (int j = 0; j < result[i].size(); j++) {
      if (j > 0) {
        std::cout << " ";
      }
      std::cout << result[i][j];
    }
    std::cout << "]";
  }
  std::cout << std::endl;
}
int main(int argc, const char** argv) {
  // {
  //   TreeNode root(3, new TreeNode(1, nullptr, new TreeNode(2)),
  //                 new TreeNode(4));
  //   solve(&root);
  // }
  // {
  //   TreeNode root(5,
  //                 new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr),
  //                              new TreeNode(4)),
  //                 new TreeNode(6));
  //   solve(&root);
  // }
  {
    TreeNode root(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    solve(&root);
  }
  return 0;
}
