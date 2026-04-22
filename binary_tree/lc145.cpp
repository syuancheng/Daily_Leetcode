#include "tree.h"
#include <algorithm>
#include <cstddef>
#include <stack>
#include <vector>
using namespace std;

/**
后续遍历: 左，右，中
*/
class Solution {
public:
  void postorderOrder(TreeNode *node, vector<int> &res) {
    if (node == nullptr) {
      return;
    }
    postorderOrder(node->left, res);
    postorderOrder(node->right, res);
    res.emplace_back(node->val);
  }
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> ans;
    if (root == nullptr) {
      return ans;
    }
    postorderOrder(root, ans);
    return ans;
  }

  // #2, 左，右，根 -》 根  右 左
  void postorderOrder2(TreeNode *node, vector<int> &res) {
    if (node == nullptr) {
      return;
    }
    stack<TreeNode *> sk;
    sk.push(node);

    while (!sk.empty()) {
      TreeNode *curr = sk.top();
      sk.pop();
      res.push_back(curr->val);

      if (curr->left) {
        sk.push(curr->left);
      }
      if (curr->right) {
        sk.push(curr->right);
      }
    }

    reverse(res.begin(), res.end());
  }
};