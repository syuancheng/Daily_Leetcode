# 912. Sort an Array

## Labels

- Array
- Sorting
- Divide and Conquer
- Heap

## Mastery

- Attempts: XX
- Status: Beginner

## Link

https://leetcode.com/problems/sort-an-array/

## Problem Description

Given an integer array `nums`, return the array sorted in ascending order.

For LeetCode submission, avoid using built-in sort functions. An `O(n log n)` algorithm such as merge sort, heap sort, or randomized quicksort is expected. Quadratic sorts are useful for learning, but they are too slow for the full constraint range.

## Solution Review

- `sortArray` now calls merge sort and returns the sorted array.
- `partition` is spelled correctly and the quicksort partition now swaps elements with `swap(nums[left], nums[l])`.
- The partition logic can degrade to `O(n^2)` on already sorted input if the leftmost element is always used as pivot. Use merge sort for stable worst-case behavior, or randomize the quicksort pivot.
- `selectionSort` is logically correct, but it is `O(n^2)` and will time out on large LeetCode tests.
- `mergeSort` and `merge` are the submitted implementation. They are correct in structure and are suitable for this problem.

## My Solution

```cpp
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <vector>

using namespace std;

void mergeSort(vector<int> &nums, int left, int right);

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    if (!nums.empty()) {
      mergeSort(nums, 0, nums.size() - 1);
    }
    return nums;
  }
};

// 1.快速排序
int partition(vector<int> &nums, int left, int right) {
  int l = left, r = right;
  int base = nums[left];
  while (l < r) {
    while (l < r && nums[r] >= base) {
      r--;
    }
    while (l < r && nums[l] <= base) {
      l++;
    }
    swap(nums[l], nums[r]);
  }
  swap(nums[left], nums[l]);
  return l;
}

void quickSort(vector<int> &nums, int s, int t) {
  if (s >= t) {
    return;
  }
  int mid = partition(nums, s, t);
  quickSort(nums, s, mid - 1);
  quickSort(nums, mid + 1, t);
}

// 2.选择排序，双指针。内循环选择最小的和外循环交换
void selectionSort(vector<int> &nums) {
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    int minIdx = i;
    for (int j = i+1; j < n; j++) {
      if (nums[j] < nums[minIdx]) {
        minIdx = j;
      }
    }
    swap(nums[i], nums[minIdx]);
  }
}

// 3. 归并排序
void merge(vector<int> &nums, int left, int mid, int right) {
  vector<int> tmp(right - left + 1);
  int i = left, j = mid + 1, k = 0;
  while (i <= mid && j <= right) {
    if (nums[i] <= nums[j]) {
      tmp[k++] = nums[i++];

    } else {
      tmp[k++] = nums[j++];
    }
  }
  while (i <= mid) {
    tmp[k++] = nums[i++];
  }
  while (j <= right) {
    tmp[k++] = nums[j++];
  }

  for (int idx = 0; idx < k; idx++) {
    nums[left + idx] = tmp[idx];
  }
}

void mergeSort(vector<int> &nums, int left, int right) {
  if (left >= right) {
    return;
  }
  int mid = left + (right - left) / 2;
  mergeSort(nums, left, mid);
  mergeSort(nums, mid + 1, right);

  // 合并阶段
  merge(nums, left, mid, right);
}

int main() { return 0; }
```

## Reference Implementation

This version uses merge sort as the submitted `sortArray` implementation because its worst-case time complexity is always `O(n log n)`.

```cpp
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    if (!nums.empty()) {
      mergeSort(nums, 0, nums.size() - 1);
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
    vector<int> tmp;
    tmp.reserve(right - left + 1);

    int i = left;
    int j = mid + 1;
    while (i <= mid && j <= right) {
      if (nums[i] <= nums[j]) {
        tmp.push_back(nums[i++]);
      } else {
        tmp.push_back(nums[j++]);
      }
    }

    while (i <= mid) {
      tmp.push_back(nums[i++]);
    }
    while (j <= right) {
      tmp.push_back(nums[j++]);
    }

    for (int k = 0; k < tmp.size(); ++k) {
      nums[left + k] = tmp[k];
    }
  }
};
```

## Common Sorting Methods

### Bubble Sort

Repeatedly swap adjacent inverted pairs. Each pass moves the largest remaining element to the end.

```cpp
void bubbleSort(vector<int> &nums) {
  int n = nums.size();
  for (int i = 0; i < n; ++i) {
    bool swapped = false;
    for (int j = 0; j + 1 < n - i; ++j) {
      if (nums[j] > nums[j + 1]) {
        swap(nums[j], nums[j + 1]);
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
  }
}
```

### Selection Sort

For each position, find the minimum element in the unsorted suffix and swap it into place.

```cpp
void selectionSort(vector<int> &nums) {
  int n = nums.size();
  for (int i = 0; i < n; ++i) {
    int minIdx = i;
    for (int j = i + 1; j < n; ++j) {
      if (nums[j] < nums[minIdx]) {
        minIdx = j;
      }
    }
    swap(nums[i], nums[minIdx]);
  }
}
```

### Insertion Sort

Maintain a sorted prefix. Insert each new element into the correct position inside that prefix.

```cpp
void insertionSort(vector<int> &nums) {
  int n = nums.size();
  for (int i = 1; i < n; ++i) {
    int cur = nums[i];
    int j = i - 1;
    while (j >= 0 && nums[j] > cur) {
      nums[j + 1] = nums[j];
      --j;
    }
    nums[j + 1] = cur;
  }
}
```

### Merge Sort

Recursively sort two halves, then merge the two sorted halves.

```cpp
void mergeSort(vector<int> &nums, int left, int right) {
  if (left >= right) {
    return;
  }
  int mid = left + (right - left) / 2;
  mergeSort(nums, left, mid);
  mergeSort(nums, mid + 1, right);
  merge(nums, left, mid, right);
}
```

### Quick Sort

Partition the array around a pivot, then recursively sort the two sides.

```cpp
int partition(vector<int> &nums, int left, int right) {
  int pivotIdx = left + rand() % (right - left + 1);
  swap(nums[left], nums[pivotIdx]);

  int l = left;
  int r = right;
  int pivot = nums[left];
  while (l < r) {
    while (l < r && nums[r] >= pivot) {
      --r;
    }
    while (l < r && nums[l] <= pivot) {
      ++l;
    }
    swap(nums[l], nums[r]);
  }

  swap(nums[left], nums[l]);
  return l;
}

void quickSort(vector<int> &nums, int left, int right) {
  if (left >= right) {
    return;
  }
  int mid = partition(nums, left, right);
  quickSort(nums, left, mid - 1);
  quickSort(nums, mid + 1, right);
}
```

### Heap Sort

Build a max heap, then repeatedly move the maximum element to the end.

```cpp
void heapSort(vector<int> &nums) {
  priority_queue<int> heap(nums.begin(), nums.end());
  for (int i = nums.size() - 1; i >= 0; --i) {
    nums[i] = heap.top();
    heap.pop();
  }
}
```

### Counting Sort

Count values by frequency, then write them back in ascending order. This works well here because the value range is bounded.

```cpp
void countingSort(vector<int> &nums) {
  const int offset = 50000;
  vector<int> count(100001);

  for (int num : nums) {
    ++count[num + offset];
  }

  int idx = 0;
  for (int value = -50000; value <= 50000; ++value) {
    while (count[value + offset] > 0) {
      nums[idx++] = value;
      --count[value + offset];
    }
  }
}
```

## Complexity

| Method | Time Complexity | Space Complexity | Stable | LeetCode 912 Suitable |
| --- | --- | --- | --- | --- |
| Bubble Sort | `O(n^2)` average/worst, `O(n)` best with early stop | `O(1)` | Yes | No |
| Selection Sort | `O(n^2)` | `O(1)` | No | No |
| Insertion Sort | `O(n^2)` average/worst, `O(n)` best | `O(1)` | Yes | No |
| Merge Sort | `O(n log n)` | `O(n)` | Yes | Yes |
| Quick Sort | `O(n log n)` average, `O(n^2)` worst | `O(log n)` average recursion | No | Yes, if randomized |
| Heap Sort | `O(n log n)` | `O(n)` with `priority_queue`, `O(1)` if in-place heap | No | Yes |
| Counting Sort | `O(n + k)`, where `k` is the value range | `O(k)` | Yes if written carefully | Yes |
