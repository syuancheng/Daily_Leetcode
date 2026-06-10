# 46. Permutations

## Labels

- Array
- Backtracking

## Mastery

- Attempts: OOHH
- Status: Familiar

## Link

https://leetcode.com/problems/permutations/

## Problem Description

Return all permutations of a list of distinct integers.

## My Solution

```cpp
class Solution {
private:
  vector<vector<int>> result;

public:
  void dfs(vector<int> &current, vector<int> &nums) {
    if (nums.empty()) {
      result.push_back(current);
      return;
    }

    for (int i = 0; i < nums.size(); ++i) {
      current.push_back(nums[i]);
      nums.erase(nums.begin() + i);

      dfs(current, nums);

      nums.insert(nums.begin() + i, current.back());
      current.pop_back();
    }
  }
  vector<vector<int>> permute(vector<int> &nums) {
    if (nums.empty()) {
      return {};
    }
    vector<int> current;
    dfs(current, nums);
    return result;
  }
};

```

## Complexity

- Time: O(n! * n).
- Space: O(n).
