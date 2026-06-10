# 78. Subsets

## Labels

- Array
- Backtracking
- DFS

## Mastery

- Attempts: HH
- Status: Familiar

## Link

https://leetcode.com/problems/subsets/

## Problem Description

Given an integer array `nums` containing distinct values, return all possible subsets of `nums`.

The solution set must not contain duplicate subsets. The subsets can be returned in any order.

Example:

```text
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```

## My Solution

```cpp
class Solution {
private:
  vector<vector<int>> result;

public:
  void dfs(vector<int> &current, vector<int> &remain, int start) {
    result.push_back(current);

    for (int i = start; i < remain.size(); ++i) {
      current.push_back(remain[i]);

      dfs(current, remain, i + 1);

      current.pop_back();
    }
  }
  vector<vector<int>> subsets(vector<int> &nums) {
    if (nums.empty()) {
      result.push_back({});
      return result;
    }
    vector<int> curr;
    dfs(curr, nums, 0);
    return result;
  }
};
```

## Complexity

- Time: O(n * 2^n), where `n` is the length of `nums`, because there are `2^n` subsets and copying each subset can take up to `n`.
- Space: O(n) auxiliary space for the recursion path, excluding the output.
