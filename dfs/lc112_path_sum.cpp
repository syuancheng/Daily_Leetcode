#include "type.h"
#include <vector>

class Solution {
  std::vector<int> s;

public:
  /**
  sum(root) += sum(root.left)
必须从上往下传
*/

  bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
      return false;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return root->val == targetSum;
    }
    int remaining = targetSum - root->val;

    return hasPathSum(root->left, remaining) ||
           hasPathSum(root->right, remaining);
  }
};