#include <cstddef>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
  int val;

  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

/**
中序遍历
左，中，右
*/

class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};