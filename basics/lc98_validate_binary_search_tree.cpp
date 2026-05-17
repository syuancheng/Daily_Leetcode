#include "type.h"
#include <climits>

class Solution {
public:
  long long prev = LONG_MIN;

  bool isValidBST(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }

    if (!isValidBST(root->left)) {
      return false;
    }

    if (root->val <= prev) {
      return false;
    }
    prev = root->val;

    return isValidBST(root->right);
  }
};
