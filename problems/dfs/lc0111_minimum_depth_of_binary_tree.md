# 111. Minimum Depth of Binary Tree

## Labels

- Tree
- DFS

## Mastery

- Attempts: H
- Status: Familiar

## Practice Log

Result options: `一次性做对` / `修改后做对` / `参考答案后做对`.

- Date:
  Duration:
  Result:
  Notes:

## Link

https://leetcode.com/problems/minimum-depth-of-binary-tree/

## Problem Description

Return the minimum number of nodes along the shortest path from the root to any leaf node.

## My Solution

```cpp
#include "../common/nodes.h"
#include <algorithm>
#include <climits>

class Solution {
private:
  int minDepthValue = INT_MAX;
  int currentDepth = 0;

  void traverse(TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    currentDepth++;
    if (root->left == nullptr && root->right == nullptr) {
      minDepthValue = std::min(currentDepth, minDepthValue);
    }
    traverse(root->left);
    traverse(root->right);
    currentDepth--;
  }

public:
  int minDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    traverse(root);
    return minDepthValue;
  }
};
```

## Complexity

- Time: O(n).
- Space: O(h).
