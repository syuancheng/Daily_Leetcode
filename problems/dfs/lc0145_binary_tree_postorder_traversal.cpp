#include "../common/nodes.h"
#include <algorithm>
#include <cstddef>
#include <stack>
#include <vector>
using namespace std;

/**
后续遍历: 左，右，根
*/
class Solution {
public:
  void postorderOrder(TreeNode *node, vector<int> &res) {
    if (node == nullptr) {
      return;
    }
    postorderOrder(node->left, res);
    postorderOrder(node->right, res);
    res.push_back(node->val);
  }
  vector<int> postorderTraversal(TreeNode *root) {
  }

  // 左右根 》 根右左 》reverse res
  void postorderOrder2(TreeNode *node, vector<int> &res) {
    if (node == nullptr) {
      return;
    }
    stack<TreeNode *> sk;
    sk.push(node);
    
    while (!sk.empty()) {
      auto node = sk.top();
      sk.pop();
      res.push_back(node->val);

      if (node->left) {
        sk.push(node->left);
      }
      if (node->right) {
        sk.push(node->right);
      }
    }
    reverse(res.begin(), res.end());
  }
};