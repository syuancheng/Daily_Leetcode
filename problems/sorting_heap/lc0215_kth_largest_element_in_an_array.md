# 215. Kth Largest Element in an Array

## Labels

- Array
- Heap
- Quickselect

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/kth-largest-element-in-an-array/

## Problem Description

Find the kth largest element in an unsorted array.

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

- Time: O(n) average, O(n^2) worst.
- Space: O(1).
