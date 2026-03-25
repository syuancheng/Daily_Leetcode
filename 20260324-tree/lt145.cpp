#include "tree.h"
#include <cstddef>
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
};