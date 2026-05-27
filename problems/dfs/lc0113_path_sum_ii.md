# 113. Path Sum II

## Labels

- Tree
- DFS
- Backtracking

## Mastery

- Attempts: OO
- Status: Proficient

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

  int target{0};

public:
  void dfs(TreeNode *node, vector<int> nums) {
    nums.push_back(node->val);
    if (node->left == nullptr && node->right == nullptr) {
      int sum = 0;
      for (auto &num : nums) {
        sum += num;
      }
      if (sum == target) {
        result.push_back(nums);
      }
      return;
    }


    if (node->left) {
      dfs(node->left, nums);
    }

    if (node->right) {
      dfs(node->right, nums);
    }
  }
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    if (root == nullptr) {
      return result;
    }
    target = targetSum;

    vector<int> nums;
    dfs(root, nums);

    return result;
  }
};
```

## Complexity

- Time: O(n * h), where `n` is the number of nodes and `h` is the tree height, because each leaf path is summed by scanning the current path.
- Space: O(n * h) in the worst case for the returned paths and copied path vectors; the recursion depth is O(h).
