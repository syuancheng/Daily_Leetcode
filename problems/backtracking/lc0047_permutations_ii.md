# 47. Permutations II

## Labels

- Array
- Backtracking

## Mastery

- Attempts: H
- Status: Familiar

## Link

https://leetcode.com/problems/permutations-ii/

## Problem Description

Given a collection of numbers that may contain duplicates, return all unique
permutations in any order.

## My Solution

```cpp
class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    result_.clear();
    path_.clear();
    used_.assign(nums.size(), false);
    backtrack(nums);
    return result_;
  }

private:
  vector<vector<int>> result_;
  vector<int> path_;
  vector<bool> used_;

  void backtrack(const vector<int> &nums) {
    if (path_.size() == nums.size()) {
      result_.push_back(path_);
      return;
    }

    for (size_t i = 0; i < nums.size(); ++i) {
      if (used_[i]) {
        continue;
      }
      if (i > 0 && nums[i] == nums[i - 1] && !used_[i - 1]) {
        continue;
      }

      used_[i] = true;
      path_.push_back(nums[i]);
      backtrack(nums);
      path_.pop_back();
      used_[i] = false;
    }
  }
};
```

## Review Notes

- `sort` groups duplicate values so the deduplication rule can compare adjacent
  values.
- `used_[i]` prevents reusing the same index inside one permutation.
- `!used_[i - 1]` means the previous equal value was not selected in this tree
  branch, so choosing the later equal value first would duplicate work.

## Complexity

- Time: O(n! * n) in the worst case when all values are unique.
- Space: O(n) for recursion, `path_`, and `used_`, excluding output.
