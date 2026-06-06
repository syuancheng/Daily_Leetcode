#include "type.h"
#include <cstddef>
#include <stack>
#include <vector>
using namespace std;

/**
94. 二叉树的中序遍历
中序遍历
左，中，右
*/
class Solution {
public:
  // 递归
  void inorderOrder(TreeNode *node, vector<int> &res) {
    if (node == nullptr) {
      return;
    }

    inorderOrder(node->left, res);
    res.push_back(node->val);
    inorderOrder(node->right, res);
  }

  // 迭代（stack)
  void inorderOrder2(TreeNode *node, vector<int> &res) {
    if (node == nullptr) {
      return;
    }
    stack<TreeNode *> st;
    TreeNode *cur = node;

    while (!cur || !st.empty()) {
      while (cur) {
        st.push(cur);
        cur = cur->left;
      }
      cur = st.top();
      st.pop();
      res.push_back(cur->val);
      cur = cur->right;
    }
    return;
  }
};