# 215. Kth Largest Element in an Array

## Labels

- Array
- Heap
- Quickselect

## Mastery

- Attempts: XX
- Status: Beginner

## Link

https://leetcode.com/problems/kth-largest-element-in-an-array/

## Problem Description

Given an integer array `nums` and an integer `k`, return the `k`th largest element in the array. The result is based on sorted order, not distinct values.

## My Solution

```cpp
#include <utility>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
  int partition(vector<int> &nums, int left, int right) {
    int l = left, r = right;
    int base = nums[left];
    while (l < r) {
      while (l < r && nums[r] <= base) {
        r--;
      }
      while (l < r && nums[l] >= base) {
        l++;
      }
      swap(nums[l], nums[r]);
    }
    swap(nums[left], nums[l]);
    return l;
  }

  int findKthLargest(vector<int> &nums, int k) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int mid = partition(nums, l, r);
      if (mid + 1 == k) {
        return nums[mid];
      }

      if (mid < k) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    return nums[k-1];
  }

  int findKthLargest2(vector<int> &nums, int k) {
    std::priority_queue<int, vector<int>, greater<int>> max_heap;
    for (int i = 0; i < k; i++) {
      max_heap.push(nums[i]);
    }

    for (int j = k; j < nums.size(); j++) {
      if (nums[j] > max_heap.top()) {
        max_heap.pop();
        max_heap.push(nums[j]);
      }
    }
    return max_heap.top();
  }
};
```

## Complexity

- Time: O(n) average for quickselect, or O(n log k) for the heap solution.
- Space: O(1) extra for quickselect, or O(k) for the heap solution.

## Notes

This problem can be solved with a min-heap that keeps the largest `k` elements seen so far. In C++, that heap is declared as:

```cpp
priority_queue<int, vector<int>, greater<int>> min_heap;
```

See also: [C++ `std::priority_queue` Notes](../data_structure_notes/priority_queue.md)
