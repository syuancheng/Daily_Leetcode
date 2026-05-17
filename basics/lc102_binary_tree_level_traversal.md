# 102. Binary Tree Level Order Traversal

## Labels

- Tree
- BFS
- DFS

## Mastery

- Attempts: XO
- Status: Familiar

## Link

https://leetcode.com/problems/binary-tree-level-order-traversal/

## Problem Description

Given the root of a binary tree, return its node values level by level from left to right.

## My Solution

```cpp
#include "type.h"
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    levelOrderHelp(ans, root, 0);
    return ans;
  }

  void levelOrderHelp(vector<vector<int>> &ans, TreeNode *root, int len) {
    if (root == nullptr) {
      return;
    }
    if (len >= ans.size()) {
      ans.push_back({});
    }
    ans[len].push_back(root->val);
    levelOrderHelp(ans, root->left, len + 1);
    levelOrderHelp(ans, root->right, len + 1);
  }
};
```

## Complexity

- Time: O(n), where `n` is the number of nodes.
- Space: O(n), for the output and recursion stack in the worst case.
