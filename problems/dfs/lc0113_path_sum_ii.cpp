#include "type.h"
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> result;

public:
  int dfs(TreeNode *node, int remain) {
    if (node == nullptr) {
      return 0;
    }

    if (node->left == nullptr && node->right == nullptr) {
      
    }
    int l_sum = node->val + dfs(node->left, remain = node->val);
    int r_sum = node->val + dfs(node->right, remain = node->val);

  }
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
      return {};
    }
    dfs(root, targetSum);
  }
};