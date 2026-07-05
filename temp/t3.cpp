#include "../problems/common/nodes.h"
#include <algorithm>
#include <climits>
#include <cstddef>

class Solution {
private:
  int minDepthValue = INT_MAX;

  int currentDepth = 0;

public:
  int minDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    traverse(root);
    return minDepthValue;
  };

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
  };
};