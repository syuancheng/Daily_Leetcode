# 53. Maximum Subarray

## Labels

- Array
- Dynamic Programming

## Mastery

- Mastery: Needs Review (不熟练)

## Link

https://leetcode.com/problems/maximum-subarray/

## Problem Description

Given an integer array `nums`, find the contiguous subarray with the largest sum and return that sum.

## My Solution

```cpp
#include <algorithm>
#include <vector>

using namespace std;



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
          return 0;
        }
        int pre = nums[0];
        int max = pre;
        for (int i = 1; i < nums.size(); i++) {
          if (pre > 0) {
            pre += nums[i];
          } else {
            pre = nums[i];
          }
          max = std::max(max, pre);
        }
        return max;
    }
};
```

## Complexity

- Time: O(n), where `n` is the length of `nums`.
- Space: O(1).
