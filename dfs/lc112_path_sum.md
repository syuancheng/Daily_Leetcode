# 112. Path Sum

## Labels

- Tree
- DFS
- Binary Tree
- Recursion

## Mastery

- Attempts: H
- Status: Beginner

## Link

https://leetcode.com/problems/path-sum/

## Problem Description

Given the root of a binary tree and an integer `targetSum`, return whether the tree has a root-to-leaf path whose node values add up to `targetSum`. A leaf is a node with no left or right child.

## My Solution

```cpp
#include "type.h"
#include <vector>

class Solution {
  std::vector<int> s;

public:
  /**
  sum(root) += sum(root.left)
必须从上往下传
*/

  bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
      return false;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return root->val == targetSum;
    }
    int remaining = targetSum - root->val;

    return hasPathSum(root->left, remaining) ||
           hasPathSum(root->right, remaining);
  }
};
```

## Complexity

- Time: O(n), where `n` is the number of nodes in the tree.
- Space: O(h), where `h` is the height of the tree due to the recursion stack. This is O(n) in the worst case and O(log n) for a balanced tree.
