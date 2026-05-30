# 113. Path Sum II

## Labels

- Tree
- DFS
- Backtracking

## Mastery

- Attempts: OOH
- Status: Beginner

## Link

https://leetcode.com/problems/path-sum-ii/

## Problem Description

Given the root of a binary tree and an integer `targetSum`, return all root-to-leaf paths where the sum of the node values in each path equals `targetSum`.

A leaf is a node with no children. Each returned path should list the node values from the root down to that leaf.

Example:

```text
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
```

## My Solution

```cpp
#include "type.h"
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> result;

public:
  void dfs(TreeNode *node, vector<int> &nums,
           int reamin) { // 如果这里是值拷贝的话，不需要pop_back也对。
    nums.push_back(node->val);
    reamin -= node->val;
    if (node->left == nullptr && node->right == nullptr) {
      if (reamin == 0) {
        result.push_back(nums);
      }
      nums.pop_back();

      return;
    }

    if (node->left) {
      dfs(node->left, nums, reamin);
    }
    if (node->right) {
      dfs(node->right, nums, reamin);
    }

    nums.pop_back();
  }

  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
      return result;
    }
    vector<int> nums;
    dfs(root, nums, targetSum);
    return result;
  }
};
```

## Complexity

- Time: O(n * h) in the worst case, where `n` is the number of nodes and `h` is the tree height, because each valid path copied into `result` can contain up to `h` values.
- Space: O(h) auxiliary space for the recursion stack and current path, excluding the output. Including the output, space is O(k * h), where `k` is the number of returned paths.
