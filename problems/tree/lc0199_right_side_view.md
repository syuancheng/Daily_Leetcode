# 199. Binary Tree Right Side View

## Labels

- Tree
- BFS
- Queue

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/binary-tree-right-side-view/

## Problem Description

Given the root of a binary tree, return the values of the nodes visible when looking at the tree from the right side, ordered from top to bottom.

The right-side view contains one value per depth level: the rightmost node encountered at that level.

Example:

```text
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
```

## My Solution

```cpp
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
```

## Complexity

- Time: O(n), where `n` is the number of nodes in the tree.
- Space: O(w), where `w` is the maximum width of the tree. In the worst case, this is O(n).
