# 39. Combination Sum

## Labels

- Array
- Backtracking

## Mastery

- Attempts: H
- Status: Familiar

## Link

https://leetcode.com/problems/combination-sum/

## Problem Description

Given distinct positive integers `candidates` and a target, return all unique
combinations where the chosen numbers sum to `target`.

The same candidate may be chosen more than once. Combinations can be returned in
any order.

## My Solution

```cpp
class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    result_.clear();
    path_.clear();
    backtrack(candidates, 0, target);
    return result_;
  }

private:
  vector<vector<int>> result_;
  vector<int> path_;

  void backtrack(const vector<int> &candidates, size_t start, int remaining) {
    if (remaining == 0) {
      result_.push_back(path_);
      return;
    }

    for (size_t i = start; i < candidates.size(); ++i) {
      if (candidates[i] > remaining) {
        break;
      }

      path_.push_back(candidates[i]);
      backtrack(candidates, i, remaining - candidates[i]);
      path_.pop_back();
    }
  }
};
```

## Review Notes

- Use `start` to keep combinations unordered and avoid duplicate permutations of
  the same combination.
- Recursing with `i` allows the current candidate to be reused.
- Sorting lets the loop stop once `candidates[i] > remaining`.

## Complexity

- Time: Exponential in the target and candidate set size.
- Space: O(target / min(candidates)) recursion depth, excluding output.
