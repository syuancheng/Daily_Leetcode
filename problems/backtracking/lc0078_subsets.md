# 78. Subsets

## Labels

- Array
- Backtracking
- DFS

## Mastery

- Attempts: HHH
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

  vector<int> track;

public:
  vector<vector<int>> subsets(vector<int> &nums) {
    backtrack(nums, 0);
    return result;
  }

  void backtrack(vector<int> &nums, int start) {

    result.push_back(track); // 这里是节点的前序位置，每个节点的值都是一个子集。

    for (int i = start; i < nums.size(); i++) {
      track.push_back(nums[i]);
      backtrack(nums, i + 1);
      track.pop_back();
    }
  }
};
```

## Complexity

- Time: O(n * 2^n), where `n` is the length of `nums`, because there are `2^n` subsets and copying each subset can take up to `n`.
- Space: O(n) auxiliary space for the recursion path, excluding the output.
