# 102. Binary Tree Level Order Traversal

## Labels

- Tree
- BFS
- Binary Tree

## Mastery

- Mastery: Needs Review (不熟练)

## Link

https://leetcode.com/problems/binary-tree-level-order-traversal/

## Problem Description

Given the root of a binary tree, return the values of its nodes level by level from left to right. If the tree is empty, return an empty list.

## My Solution

```cpp
#include <queue>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

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

- Time: O(n), where `n` is the number of nodes in the tree.
- Space: O(n), for the queue and output.
