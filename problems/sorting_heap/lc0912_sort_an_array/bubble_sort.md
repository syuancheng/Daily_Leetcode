# 912. Sort an Array - Bubble Sort

## Labels

- Array
- Sorting

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/sort-an-array/

## Problem Description

Given an integer array `nums`, return the array sorted in ascending order.

## My Solution

See `bubble_sort.cpp`.

## Standard Answer

```cpp
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();
    for (int i = n - 1; i > 0; --i) {
      bool swapped = false;
      for (int j = 0; j < i; ++j) {
        if (nums[j] > nums[j + 1]) {
          swap(nums[j], nums[j + 1]);
          swapped = true;
        }
      }
      if (!swapped) {
        break;
      }
    }
    return nums;
  }
};
```

## Complexity

- Time: O(n^2)
- Space: O(1)
