#include "tree.h"
#include <cstddef>
#include <stack>
#include <vector>
using namespace std;

/**
中序遍历
左，中，右
*/
class Solution {
public:
  void inorderOrder(TreeNode *node, vector<int> &res) {
    if (node == nullptr) {
      return;
    }

    inorderOrder(node->left, res);
    res.push_back(node->val);
    inorderOrder(node->right, res);
  }
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    inorderOrder(root, res);

    return res;
  }

  vector<int> inorderTraversalWithSk(TreeNode *root) {
    vector<int> res;
    stack<TreeNode *> sk;
    while (root != nullptr || !sk.empty()) {
      while (root != nullptr) {
        sk.push(root);
        root = root->left;
      }
      root = sk.top();
      sk.pop();
      res.push_back(root->val);
      root = root->right;
    }

    return res;
  }
};