# 15. 3Sum

## Labels

- Array
- Two Pointers
- Sorting

## Link

https://leetcode.com/problems/3sum/

## Problem Description

Given an integer array `nums`, return all unique triplets `[nums[i], nums[j], nums[k]]` such that the three values sum to `0` and the indices are distinct.

## My Solution

```cpp
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    stable_sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int len = nums.size();
    for (int i = 0; i < nums.size(); i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int target = -nums[i];
      int l = i + 1, r = len - 1;
      while (l < r) {
        int sum = nums[l] + nums[r];
        if (sum == target) {
          res.push_back({nums[i], nums[l], nums[r]});
          l++;
          r--;
          
          //check same num should when find a sum meet condition
          while (l < r && nums[l] == nums[l - 1]) {
            l++;
          }

          while (l < r && nums[r] == nums[r + 1]) {
            r--;
          }

        } else if (sum < target) {
          l++;
        } else {
          r--;
        }
      }
    }
    return res;
  }
};
```

## Complexity

- Time: O(n^2), after sorting the array.
- Space: O(log n) to O(n), depending on the sorting implementation.
