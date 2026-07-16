# 90. Subsets II

## Labels

- Array
- Backtracking

## Mastery

- Attempts: H
- Status: Familiar

## Link

https://leetcode.com/problems/subsets-ii/

## Problem Description

Given an integer array `nums` that may contain duplicates, return all possible
subsets without duplicate subsets.

The solution set can be returned in any order.

## My Solution

```cpp
class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    result_.clear();
    path_.clear();
    backtrack(nums, 0);
    return result_;
  }

private:
  vector<vector<int>> result_;
  vector<int> path_;

  void backtrack(const vector<int> &nums, size_t start) {
    result_.push_back(path_);

    for (size_t i = start; i < nums.size(); ++i) {
      if (i > start && nums[i] == nums[i - 1]) {
        continue;
      }

      path_.push_back(nums[i]);
      backtrack(nums, i + 1);
      path_.pop_back();
    }
  }
};
```

## Review Notes

- Push `path_` at every node because every partial path is a valid subset.
- Sort first, then skip `nums[i] == nums[i - 1]` only when `i > start`.
- Recursing with `i + 1` keeps each element index used at most once.

## Complexity

- Time: O(n * 2^n), including copying subsets.
- Space: O(n) recursion depth, excluding output.
