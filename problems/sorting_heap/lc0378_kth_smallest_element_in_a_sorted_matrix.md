# 378. Kth Smallest Element in a Sorted Matrix

## Labels

- Matrix
- Heap
- Binary Search

## Mastery

- Attempts: H
- Status: Familiar

## Link

https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

## Problem Description

Given an n by n matrix whose rows and columns are sorted in ascending order, return the kth smallest element in the matrix.

## My Solution

```cpp
#include <cstddef>
#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
  struct Cell {
    int value;
    size_t row;
    size_t col;
  };

public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    auto cmp = [](const Cell &a, const Cell &b) { return a.value > b.value; };
    priority_queue<Cell, vector<Cell>, decltype(cmp)> pq(cmp);

    for (size_t i = 0; i < matrix.size(); i++) {
      pq.push({matrix[i][0], i, 0});
    }

    int result = -1;

    while (!pq.empty() && k > 0) {
      Cell cur = pq.top();
      pq.pop();

      result = cur.value;
      k--;

      size_t nextCol = cur.col + 1;
      if (nextCol < matrix[cur.row].size()) {
        pq.push({matrix[cur.row][nextCol], cur.row, nextCol});
      }
    }

    return result;
  }
};
```

## Complexity

- Time: O((n+k) log n).
- Space: O(n).
