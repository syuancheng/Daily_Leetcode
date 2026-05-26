#include "type.h"
#include <vector>

class Solution {
public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
      return false;
    }

    if (root->left == nullptr && root->right == nullptr) {
      return root->val == targetSum;
    }
    int remain = targetSum - root->val;

    return hasPathSum(root->left, remain) || hasPathSum(root->right, remain);
  }
};
