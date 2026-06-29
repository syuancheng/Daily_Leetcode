# 112. Path Sum

## Labels

- Tree
- DFS

## Mastery

- Attempts: OOO
- Status: Proficient

## Link

https://leetcode.com/problems/path-sum/

## Problem Description

Determine whether a root-to-leaf path sums to targetSum.

## My Solution

```cpp
#include "../common/nodes.h"
#include <vector>

class Solution {
public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
      return false;
    }

    if (root->left == nullptr && root->right == nullptr) {
      return root->val == targetSum;
    }
    int remain = targetSum - root->val;

    return hasPathSum(root->left, remain) || hasPathSum(root->right, remain);
  }
};
```

## Complexity

- Time: O(n).
- Space: O(h).
