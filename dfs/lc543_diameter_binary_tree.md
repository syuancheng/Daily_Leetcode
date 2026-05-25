# 543. Diameter of Binary Tree

## Labels

- Tree
- DFS
- Binary Tree
- Recursion

## Mastery

- Attempts: HO
- Status: Familiar

## Link

https://leetcode.com/problems/diameter-of-binary-tree/

## Problem Description

Given the root of a binary tree, return the length of the diameter of the tree. The diameter is the number of edges on the longest path between any two nodes in the tree. This path may or may not pass through the root.

## My Solution

### Solution 1: One DFS

```cpp
#include "type.h"
#include <algorithm>

class Solution {
public:
  int result = 0;

  // Return the height of the subtree in number of nodes.
  // While returning height, update the best diameter found so far.
  int dfs(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }

    int leftHeight = dfs(node->left);
    int rightHeight = dfs(node->right);

    // The path through this node uses leftHeight + rightHeight edges.
    result = std::max(result, leftHeight + rightHeight);

    return std::max(leftHeight, rightHeight) + 1;
  }

  int diameterOfBinaryTree(TreeNode *root) {
    dfs(root);
    return result;
  }
};
```

### Solution 2: Compute Diameter at Each Node

```cpp
#include "type.h"
#include <algorithm>

class Solution1 {
public:
  int result = 0;

  // Return the height of the subtree in number of nodes.
  int dfs(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }
    return std::max(dfs(node->left), dfs(node->right)) + 1;
  }

  // Try each node as the highest turning point of the longest path.
  void length(TreeNode *node) {
    if (!node) {
      return;
    }

    int current = 0;
    if (node->left) {
      current += dfs(node->left);
    }
    if (node->right) {
      current += dfs(node->right);
    }

    result = std::max(result, current);

    length(node->left);
    length(node->right);
  }

  int diameterOfBinaryTree(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    length(root);
    return result;
  }
};
```

## Complexity

- Solution 1 Time: O(n), where `n` is the number of nodes in the tree. Each node is visited once.
- Solution 1 Space: O(h), where `h` is the height of the tree due to the recursion stack.
- Solution 2 Time: O(n * h), because each node may recompute subtree heights. This is O(n^2) in the worst case for a skewed tree and O(n log n) for a balanced tree.
- Solution 2 Space: O(h), where `h` is the height of the tree due to the recursion stack.
