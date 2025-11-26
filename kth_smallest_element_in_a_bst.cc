#include <iostream>
#include <stack>

// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// iterative approach using stack.
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
  int kthSmallest(TreeNode* root, int k) {
    std::stack<TreeNode*> st;
    TreeNode* current = root;
    int count = 0;
    while (current != nullptr || !st.empty()) {
      if (current == nullptr) {
        TreeNode* top = st.top();
        st.pop();
        if (++count == k) {
          return top->val;
        }
        current = top->right;
      } else {
        st.push(current);
        current = current->left;
      }
    }
    return -1;
  }
};
}  // namespace

void solve(TreeNode* node, int k) {
  Solution sol;
  int result = sol.kthSmallest(node, k);

  std::cout << k << " " << result << std::endl;
}
int main(int argc, char const** argv) {
  {
    TreeNode root(3, new TreeNode(1, nullptr, new TreeNode(2)),
                  new TreeNode(4));
    solve(&root, 1);
    solve(&root, 2);
    solve(&root, 3);
  }
  {
    TreeNode root(5,
                  new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr),
                               new TreeNode(4)),
                  new TreeNode(6));
    solve(&root, 1);
    solve(&root, 2);
    solve(&root, 3);
  }
  return 0;
}
