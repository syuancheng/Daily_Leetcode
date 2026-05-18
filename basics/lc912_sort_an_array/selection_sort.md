# 912. Sort an Array - Selection Sort

## Labels

- Array
- Sorting

## Mastery

- Attempts: XX
- Status: Beginner

## Link

https://leetcode.com/problems/sort-an-array/

## Problem Description

Given an integer array `nums`, return the array sorted in ascending order.

## My Solution

See `selection_sort.cpp`.

## Standard Answer

```cpp
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      int minIndex = i;
      for (int j = i + 1; j < n; ++j) {
        if (nums[j] < nums[minIndex]) {
          minIndex = j;
        }
      }
      swap(nums[i], nums[minIndex]);
    }
    return nums;
  }
};
```

## Complexity

- Time: O(n^2)
- Space: O(1)
