# 46. Permutations

## Labels

- Array
- Backtracking
- DFS

## Mastery

- Attempts: H
- Status: Beginner

## Link

https://leetcode.com/problems/permutations/

## Problem Description

Given an array `nums` of distinct integers, return all possible permutations of the elements. The answer can be returned in any order.

## My Solution

```cpp
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> result;

public:
  void dfs(vector<int> &nums, vector<int> &remain) {
    if (remain.empty()) {
      result.push_back(nums);
      return;
    }

    for (int i = 0; i < remain.size(); ++i) {
      nums.push_back(remain[i]);
      remain.erase(remain.begin() + i);

      dfs(nums, remain);

      remain.insert(remain.begin() + i, nums.back());
      nums.pop_back();
    }
  }
  vector<vector<int>> permute(vector<int> &nums) {
    vector<int> remain = nums;
    vector<int> current;
    dfs(current, remain);
    return result;
  }
};
```

## Complexity

- Time: O(n * n!), where `n` is the length of `nums`. There are `n!` permutations and each result has length `n`.
- Space: O(n), excluding the output array, for the recursion stack and current permutation state. Including the output array, the space is O(n * n!).
