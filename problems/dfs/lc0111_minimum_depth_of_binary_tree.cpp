#include "../common/nodes.h"
#include <algorithm>
#include <climits>

class Solution {
private:
  int minDepthValue = INT_MAX;
  int currentDepth = 0;

  void traverse(TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    currentDepth++;
    if (root->left == nullptr && root->right == nullptr) {
      minDepthValue = std::min(currentDepth, minDepthValue);
    }
    traverse(root->left);
    traverse(root->right);
    currentDepth--;
  }

public:
  int minDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    traverse(root);
    return minDepthValue;
  }
};
