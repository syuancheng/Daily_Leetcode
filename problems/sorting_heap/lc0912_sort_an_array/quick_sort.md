# 912. Sort an Array - Quick Sort

## Labels

- Array
- Sorting
- Divide and Conquer

## Mastery

- Attempts: XXH
- Status: Familiar

## Link

https://leetcode.com/problems/sort-an-array/

## Problem Description

Given an integer array `nums`, return the array sorted in ascending order.

## My Solution

这次写的是随机 pivot 的快速排序。

核心思路：

1. 每次在 `[left, right]` 里随机选一个 pivot，先交换到 `left`。
2. 用左右指针 `l`、`r` 做 partition：
   - 右指针先往左找 `< pivot` 的数。
   - 左指针再往右找 `> pivot` 的数。
   - 两边都找到后交换。
3. 当 `l == r` 时，说明 pivot 的最终位置找到了，把 `nums[left]` 和 `nums[l]` 交换。
4. 对 pivot 左右两边继续递归排序。

关键点是：`partition` 返回的是 pivot 的最终下标。快速排序递归时要跳过这个位置：

```cpp
quickSort(nums, left, mid - 1);
quickSort(nums, mid + 1, right);
```

```cpp
#include <cstdlib>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int partition(vector<int> &nums, int left, int right) {
    int randIdx = left + rand() % (right - left + 1);
    swap(nums[randIdx], nums[left]);

    int l = left;
    int r = right;
    int base = nums[left];

    while (l < r) {
      while (l < r && nums[r] >= base) {
        --r;
      }
      while (l < r && nums[l] <= base) {
        ++l;
      }
      if (l < r) {
        swap(nums[l], nums[r]);
      }
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

  vector<int> sortArray(vector<int> &nums) {
    if (!nums.empty()) {
      quickSort(nums, 0, static_cast<int>(nums.size()) - 1);
    }
    return nums;
  }
};
```

注意空数组边界。原代码里直接调用：

```cpp
quickSort(nums, 0, nums.size() - 1);
```

如果 `nums` 为空，`nums.size() - 1` 会先按无符号数计算，存在隐患。更稳的写法是先判断 `!nums.empty()`，再转成 `int`。

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
