# 912. Sort an Array - Quick Sort

## Labels

- Array
- Sorting
- Divide and Conquer

## Mastery

- Attempts: XX
- Status: Beginner

## Link

https://leetcode.com/problems/sort-an-array/

## Problem Description

Given an integer array `nums`, return the array sorted in ascending order.

## My Solution

See `quick_sort.cpp`.

## Standard Answer

```cpp
#include <cstdlib>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    if (!nums.empty()) {
      quickSort(nums, 0, static_cast<int>(nums.size()) - 1);
    }
    return nums;
  }

private:
  void quickSort(vector<int> &nums, int left, int right) {
    if (left >= right) {
      return;
    }

    int pivotIndex = left + rand() % (right - left + 1);
    swap(nums[left], nums[pivotIndex]);

    int mid = partition(nums, left, right);
    quickSort(nums, left, mid - 1);
    quickSort(nums, mid + 1, right);
  }

  int partition(vector<int> &nums, int left, int right) {
    int pivot = nums[left];
    int l = left;
    int r = right;

    while (l < r) {
      while (l < r && nums[r] >= pivot) {
        --r;
      }
      nums[l] = nums[r];

      while (l < r && nums[l] <= pivot) {
        ++l;
      }
      nums[r] = nums[l];
    }

    nums[l] = pivot;
    return l;
  }
};
```

## Complexity

- Time: O(n log n) average, O(n^2) worst case
- Space: O(log n) average recursion depth
