# 104. Maximum Depth of Binary Tree

## Labels

- Tree
- DFS
- BFS

## Mastery

- Attempts: OOO
- Status: Proficient

## Link

https://leetcode.com/problems/maximum-depth-of-binary-tree/

## Problem Description

Return the maximum depth of a binary tree.

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

- Time: O(n).
- Space: O(h).
