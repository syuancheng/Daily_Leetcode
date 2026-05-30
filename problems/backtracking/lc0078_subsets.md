# 78. Subsets

## Labels

- Array
- Backtracking
- DFS

## Mastery

- Attempts: H
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
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> result;
public:
  void dfs(int start, vector<int> &remain, vector<int>& data) {
    result.push_back(data);

    for (int i = start; i < remain.size(); i++) {
      data.push_back(remain[i]);

      dfs(i + 1, remain, data);

      data.pop_back();
    }
  }
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<int> current;
    dfs(0, nums, current);
    return result;
  }
};
```

## Complexity

- Time: O(n * 2^n), where `n` is the length of `nums`, because there are `2^n` subsets and copying each subset can take up to `n`.
- Space: O(n) auxiliary space for the recursion path, excluding the output.
