
#include <cstddef>
#include <queue>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int minDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    
    std::queue<TreeNode *> q;
    q.push(root);

    int depth = 1;

    while (!q.empty()) {
      int size = q.size();

      for (int i = 0; i < size; i++) {
        TreeNode *node = q.front();
        q.pop();

        // is target?
        if (node->left == nullptr && node->right == nullptr) {
          return depth;
        }

        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
      depth++;
    }
    return depth;
  }
};
