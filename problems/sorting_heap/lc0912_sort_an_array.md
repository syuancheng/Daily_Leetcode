# 912. Sort an Array

## Labels

- Array
- Sorting

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/sort-an-array/

## Problem Description

Given an integer array, return the array sorted in ascending order. This directory keeps multiple completed sorting implementations for the same problem.

## My Solution

### Bubble Sort

```cpp
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    bubbleSort(nums);
    return nums;
  }

private:
  void bubbleSort(vector<int> &nums) {
    int n = nums.size();
    for (int i = n -1; i > 0; i--) {
      for (int j = 0; j < i; j++) {
        if (nums[j] > nums[j+1]) {
          swap(nums[j], nums[j+1]);
        }
      }
    }
  }
};
```

### Heap Sort

```cpp
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    heapSort(nums);
    return nums;
  }

private:
  void heapSort(vector<int> &nums) {
    int n = nums.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
      heapify(nums, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
      std::swap(nums[0], nums[i]);

      heapify(nums, i, 0);
    }
  }

  void heapify(vector<int> &nums, int heapSize, int root) {
    int largest = root;
    int leftChild = root * 2 + 1;
    int rightChind = root * 2 + 2;

    if (leftChild < heapSize && nums[leftChild] > nums[largest]) {
      largest = leftChild;
    }
    if (rightChind < heapSize && nums[rightChind] > nums[largest]) {
      largest = rightChind;
    }

    if (largest != root) {
      swap(nums[largest], nums[root]);
      heapify(nums, heapSize, largest);
    }
  }
};

int main() { return 0; }
```

### Insertion Sort

```cpp
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    insertionSort(nums);
    return nums;
  }

private:
  void insertionSort(vector<int> &nums) {
    for (int i = 1; i < nums.size(); ++i) {
      int base = nums[i];
      int j = i - 1;
      while (j >= 0 && nums[j] > base) {
        nums[j + 1] = nums[j];
        --j;
      }
      nums[j + 1] = base;
    }
  }
};

int main() { return 0; }
```

### Quick Sort

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

    int mid = partition(nums, left, right);
    quickSort(nums, left, mid - 1);
    quickSort(nums, mid + 1, right);
  }

  int partition(vector<int> &nums, int left, int right) {
    int randIdx = left + rand() % (right - left + 1);

    swap(nums[randIdx], nums[left]);
    int base = nums[left];
    int l = left, r = right;

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
};

int main() { return 0; }
```

### Selection Sort

```cpp
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    selectionSort(nums);
    return nums;
  }

private:
  void selectionSort(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
      int minIndex = i;
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[j] < nums[minIndex]) {
          minIndex = j;
        }
      }
      swap(nums[i], nums[minIndex]);
    }
  }
};

int main() { return 0; }
```

## Complexity

- Time: Depends on the selected sorting algorithm.
- Space: Depends on the selected sorting algorithm.
