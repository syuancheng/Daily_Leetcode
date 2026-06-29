# 111. Minimum Depth of Binary Tree

## Labels

- Tree
- BFS
- DFS

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/minimum-depth-of-binary-tree/

## Problem Description

Return the minimum depth from root to a leaf node.

## My Solution

```cpp
#include <cstddef>
#include <queue>
#include "../common/nodes.h"

class Solution {
public:
  int minDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    
    std::queue<TreeNode *> q;
    q.push(root);

    int depth = 1;

    while (!q.empty()) {
      int size = q.size();

      for (int i = 0; i < size; i++) {
        TreeNode *node = q.front();
        q.pop();

        // is target?
        if (node->left == nullptr && node->right == nullptr) {
          return depth;
        }

        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
      depth++;
    }
    return depth;
  }
};
```

## Complexity

- Time: O(n).
- Space: O(n).
