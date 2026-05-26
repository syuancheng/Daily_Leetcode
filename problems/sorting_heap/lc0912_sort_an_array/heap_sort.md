# 912. Sort an Array - Heap Sort

## Labels

- Array
- Sorting
- Heap

## Mastery

- Attempts: XXH
- Status: Beginner

## Link

https://leetcode.com/problems/sort-an-array/

## Problem Description

Given an integer array `nums`, return the array sorted in ascending order.

## My Solution

See `heap_sort.cpp`.

## Standard Answer

```cpp
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();

    for (int i = n / 2 - 1; i >= 0; --i) {
      heapify(nums, n, i);
    }

    for (int i = n - 1; i > 0; --i) {
      swap(nums[0], nums[i]);
      heapify(nums, i, 0);
    }

    return nums;
  }

private:
  void heapify(vector<int> &nums, int heapSize, int root) {
    int largest = root;
    int left = root * 2 + 1;
    int right = root * 2 + 2;

    if (left < heapSize && nums[left] > nums[largest]) {
      largest = left;
    }
    if (right < heapSize && nums[right] > nums[largest]) {
      largest = right;
    }

    if (largest != root) {
      swap(nums[root], nums[largest]);
      heapify(nums, heapSize, largest);
    }
  }
};
```

## Complexity

- Time: O(n log n)
- Space: O(1)
