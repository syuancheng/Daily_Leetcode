#include "../common/nodes.h"
#include <algorithm>

// 遍历的思路
class Solution1 {
private:
  int res = 0; // max depth

  int depth = 0;

public:
  int maxDepth(TreeNode *root) {
    traverse(root);
    return res;
  }

  void traverse(TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    depth++;
    if (root->left == nullptr && root->right == nullptr) {
      res = std::max(res, depth);
    }
    traverse(root->left);
    traverse(root->right);
    depth--;
  }
};

// 分解问题的思路
class Solution2 {
public:
  // 定义：输入一个节点，返回以该节点为根的二叉树的最大深度
  int maxDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    // 利用定义，计算左右子树的最大深度
    int leftMax = maxDepth(root->left);
    int rightMax = maxDepth(root->right);

    // 根据左右子树的最大深度推出原二叉树的最大深度
    // 整棵树的最大深度等于左右子树的最大深度取最大值，
    // 然后再加上根节点自己
    return 1 + std::max(leftMax, rightMax);
  }
};

/**


*/
