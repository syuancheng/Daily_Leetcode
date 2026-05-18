# 912. Sort an Array - Shell Sort

## Labels

- Array
- Sorting

## Link

https://leetcode.com/problems/sort-an-array/

## Problem Description

Given an integer array `nums`, return the array sorted in ascending order.

## My Solution

See `shell_sort.cpp`.

## Standard Answer

```cpp
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
      for (int i = gap; i < n; ++i) {
        int current = nums[i];
        int j = i;
        while (j >= gap && nums[j - gap] > current) {
          nums[j] = nums[j - gap];
          j -= gap;
        }
        nums[j] = current;
      }
    }
    return nums;
  }
};
```

## Complexity

- Time: O(n^2) worst case with this gap sequence
- Space: O(1)
