# 912. Sort an Array - Insertion Sort

## Labels

- Array
- Sorting

## Link

https://leetcode.com/problems/sort-an-array/

## Problem Description

Given an integer array `nums`, return the array sorted in ascending order.

## My Solution

See `insertion_sort.cpp`.

## Standard Answer

```cpp
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
      int base = nums[i];
      int j = i - 1;
      while (j >= 0 && nums[j] > base) {
        nums[j + 1] = nums[j];
        --j;
      }
      nums[j + 1] = base;
    }
    return nums;
  }
};
```

## Complexity

- Time: O(n^2)
- Space: O(1)
