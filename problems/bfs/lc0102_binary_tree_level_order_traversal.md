# 102. Binary Tree Level Order Traversal

## Labels

- Tree
- BFS
- Queue

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/binary-tree-level-order-traversal/

## Problem Description

Return the level-order traversal of a binary tree.

## My Solution

```cpp
#include <queue>
#include <vector>
#include "../common/nodes.h"

std::vector<std::vector<int>> levelOrder(TreeNode *root) {
  std::vector<std::vector<int>> result;
  if (!root)
    return result;

  std::queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    int size = q.size();
    std::vector<int> level;

    for (int i = 0; i < size; i++) {
      TreeNode *node = q.front();
      q.pop();
      level.push_back(node->val);
      if (node->left) {
        q.push(node->left);
      }
      if (node->right) {
        q.push(node->right);
      }
    }
    result.push_back(level);
  }

  return result;
}
```

## Complexity

- Time: O(n).
- Space: O(n).
