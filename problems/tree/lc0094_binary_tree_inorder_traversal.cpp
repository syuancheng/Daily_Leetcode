#include "tree.h"
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
  //递归
  void inorderOrder(TreeNode *node, vector<int> &res) {
    if (node == nullptr) {
      return;
    }
    inorderOrder(node->left, res);
    res.push_back(node->val);
    inorderOrder(node->right, res);
  }

  //迭代（stack)
  void inorderOrder2(TreeNode *node, vector<int> &res) {
    if (node == nullptr) {
      return;
    }

    stack<TreeNode *> sk;
    TreeNode *curr = node;

    while (curr || !sk.empty()) {
      // 尽可能往左走
      while (curr) {
        sk.push(curr);
        curr = curr->left;
      }

      // 弹出栈顶，当前节点的最左节点
      curr = sk.top();
      sk.pop();
      res.push_back(curr->val);

      // 转向右子树
      curr = curr->right;
    }

    return;
  }
};