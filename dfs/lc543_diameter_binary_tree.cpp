#include "type.h"
#include <algorithm>

class Solution {
private:
  int result{0};

public:
  int dfs(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }
    int l = dfs(node->left);
    int r = dfs(node->right);
    result = std::max(result, l + r);

    return std::max(l, r) + 1;
  }
  int diameterOfBinaryTree(TreeNode *root) {
    if (root == nullptr) {
      return result;
    }
    dfs(root);
    return result;
  }
};
