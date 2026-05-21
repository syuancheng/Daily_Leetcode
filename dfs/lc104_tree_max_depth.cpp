#include "type.h"
#include <algorithm>

/**
recursion formula： depth(root) = max(depth(root.left), depth(root.right)) + 1;
stop condition: root == 0 ? 0
*/
class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};

/**


*/