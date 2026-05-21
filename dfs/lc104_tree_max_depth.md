# 104. Maximum Depth of Binary Tree

## Labels

- Tree
- DFS
- Binary Tree
- Recursion

## Mastery

- Attempts: H
- Status: Beginner

## Link

https://leetcode.com/problems/maximum-depth-of-binary-tree/

## Problem Description

Given the root of a binary tree, return its maximum depth. The maximum depth is the number of nodes on the longest path from the root node down to any leaf node. If the tree is empty, its depth is `0`.

## My Solution

```cpp
#include "type.h"
#include <algorithm>

/**
recursion formula： depth(root) = max(depth(root.left), depth(root.right)) + 1;
stop condition: root == 0 ? 0
*/
class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};

/**


*/
```

## Complexity

- Time: O(n), where `n` is the number of nodes in the tree.
- Space: O(h), where `h` is the height of the tree due to the recursion stack. This is O(n) in the worst case and O(log n) for a balanced tree.
