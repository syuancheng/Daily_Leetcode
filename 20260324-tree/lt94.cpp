#include "tree.h"
#include <cstddef>
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
    res.emplace_back(node->val);
    inorderOrder(node->right, res);
  }
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> res;

      inorderOrder(root, res);
      return res;
    }
};