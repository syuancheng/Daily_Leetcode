#include "type.h"
#include <queue>
#include <vector>

using namespace std;

class Solution {

public:
  vector<int> rightSideView(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }

    vector<int> result;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      int size = q.size();

      vector<int> level;

      for (int i = 0; i < size; ++i) {
        auto node = q.front();
        q.pop();

        level.push_back(node->val);

        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
      if (!level.empty()) {
        result.push_back(level.back());
      }
    }

    return result;
  }
};