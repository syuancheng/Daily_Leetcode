#include "type.h"
#include <algorithm>

class Solution1 {
public:
  int result = 0;

  // Return the height of the subtree in number of nodes.
  int dfs(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }
    return std::max(dfs(node->left), dfs(node->right)) + 1;
  }

  // Try each node as the highest turning point of the longest path.
  void length(TreeNode *node) {
    if (!node) {
      return;
    }

    int current = 0;
    if (node->left) {
      current += dfs(node->left);
    }
    if (node->right) {
      current += dfs(node->right);
    }

    result = std::max(result, current);

    length(node->left);
    length(node->right);
  }

  int diameterOfBinaryTree(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    length(root);
    return result;
  }
};
