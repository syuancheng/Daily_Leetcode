# 46. Permutations

## Labels

- Array
- Backtracking

## Mastery

- Attempts: OOHHOO
- Status: Familiar

## Practice Log

Result options: `一次性做对` / `修改后做对` / `参考答案后做对`.

- Date:
  Duration:
  Result:
  Notes:

## Link

https://leetcode.com/problems/permutations/

## Problem Description

Return all permutations of a list of distinct integers.

## My Solution

```cpp
class Solution {
private:
  vector<vector<int>> result;

  vector<int> track;

public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<bool> used(nums.size(), false);
    backtrack(nums, used);
    return result;
  }

  void backtrack(const vector<int> &nums, vector<bool> &used) {
    if (track.size() == nums.size()) {
      result.push_back(track);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (used[i]) {
        continue;
      }

      track.push_back(nums[i]);
      used[i] = true;
      backtrack(nums, used);
      track.pop_back();
      used[i] = false;
    }
  }
};

```

## Complexity

- Time: O(n! * n).
- Space: O(n).
