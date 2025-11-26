#include <unordered_map>
#include <vector>

// https://leetcode.com/problems/clone-graph/
// clone graph, recursive.
namespace {
class Node {
 public:
  int val;
  std::vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = std::vector<Node*>();
  }

  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node*>();
  }

  Node(int _val, std::vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (node == nullptr) {
      return nullptr;
    }
    std::unordered_map<Node*, Node*> visited;

    return doCloneGraph(node, visited);
  }

  Node* doCloneGraph(Node* node, std::unordered_map<Node*, Node*>& visited) {
    auto it = visited.find(node);

    if (it != visited.end()) {
      return it->second;
    }
    Node* clone = new Node(node->val);
    visited[node] = clone;

    for (int i = 0; i < node->neighbors.size(); i++) {
      Node* n = node->neighbors[i];
      Node* nclone = doCloneGraph(n, visited);
      clone->neighbors.push_back(nclone);
    }
    return clone;
  }
};
}  // namespace

int main(int argc, char const** argv) { return 0; }
