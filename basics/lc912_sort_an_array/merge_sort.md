# 912. Sort an Array - Merge Sort

## Labels

- Array
- Sorting
- Divide and Conquer

## Link

https://leetcode.com/problems/sort-an-array/

## Problem Description

Given an integer array `nums`, return the array sorted in ascending order.

## My Solution

See `merge_sort.cpp`.

## Standard Answer

```cpp
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    if (!nums.empty()) {
      mergeSort(nums, 0, static_cast<int>(nums.size()) - 1);
    }
    return nums;
  }

private:
  void mergeSort(vector<int> &nums, int left, int right) {
    if (left >= right) {
      return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
  }

  void merge(vector<int> &nums, int left, int mid, int right) {
    vector<int> temp;
    temp.reserve(right - left + 1);

    int i = left;
    int j = mid + 1;
    while (i <= mid && j <= right) {
      if (nums[i] <= nums[j]) {
        temp.push_back(nums[i++]);
      } else {
        temp.push_back(nums[j++]);
      }
    }

    while (i <= mid) {
      temp.push_back(nums[i++]);
    }
    while (j <= right) {
      temp.push_back(nums[j++]);
    }

    for (int k = 0; k < temp.size(); ++k) {
      nums[left + k] = temp[k];
    }
  }
};
```

## Complexity

- Time: O(n log n)
- Space: O(n)
