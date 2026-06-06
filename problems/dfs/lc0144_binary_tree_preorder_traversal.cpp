#include "type.h"
#include <cstddef>
#include <stack>
#include <vector>

using namespace std;

/**
144. 二叉树的前序遍历
中左右
*/

class Solution {
public:
  void preOrder(TreeNode *root, vector<int> &res) {
    if (root == nullptr) {
      return;
    }
    res.push_back(root->val);
    preOrder(root->left, res);
    preOrder(root->right, res);
  }

  void preOrder2(TreeNode *root, vector<int> &res) {
    if (root == nullptr) {
      return;
    }
    stack<TreeNode *> sk;
    sk.push(root);
    while (!sk.empty()) {
      auto node = sk.top();
      sk.pop();
      res.push_back(node->val);

      if (node->right) {
        sk.push(node->right);
      }
      if (node->left) {
        sk.push(node->left);
      }
    }
    return;
  }
};