# 40. Combination Sum II

## Labels

- Array
- Backtracking

## Mastery

- Attempts: H
- Status: Familiar

## Link

https://leetcode.com/problems/combination-sum-ii/

## Problem Description

Given a collection of candidate numbers and a target, return all unique
combinations where the chosen numbers sum to `target`.

Each candidate may be used at most once. The input can contain duplicate values,
but the output must not contain duplicate combinations.

## My Solution

```cpp
class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
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
      if (i > start && candidates[i] == candidates[i - 1]) {
        continue;
      }
      if (candidates[i] > remaining) {
        break;
      }

      path_.push_back(candidates[i]);
      backtrack(candidates, i + 1, remaining - candidates[i]);
      path_.pop_back();
    }
  }
};
```

## Review Notes

- The duplicate skip must be `i > start && candidates[i] == candidates[i - 1]`.
  That skips duplicate choices only inside the same tree level.
- Recursing with `i + 1` enforces "use each candidate at most once".
- Sorting supports both same-level deduplication and early pruning.

## Complexity

- Time: O(2^n * n) in the worst case, including copying valid paths.
- Space: O(n) recursion depth, excluding output.
