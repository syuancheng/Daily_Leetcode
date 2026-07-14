# 304. Range Sum Query 2D - Immutable

## Labels

- Array
- Design
- Matrix
- Prefix Sum

## Mastery

- Attempts: O
- Status: Familiar

## Link

https://leetcode.com/problems/range-sum-query-2d-immutable/

## Problem Description

Preprocess a matrix so that the sum of any inclusive rectangle can be queried
repeatedly.

## My Solution

Use a 2D prefix sum table with one extra row and column. `prefix_sums_[r][c]`
stores the sum of the rectangle before row `r` and before column `c`.

For query rectangle `(row1, col1)` to `(row2, col2)`, convert the bottom-right
corner to exclusive coordinates and use inclusion-exclusion:

```cpp
prefix_sums_[bottom][right] - prefix_sums_[top][right]
    - prefix_sums_[bottom][left] + prefix_sums_[top][left]
```

```cpp
#include <cstddef>
#include <vector>

using namespace std;

class NumMatrix {
  vector<vector<int>> prefix_sums_;

public:
  NumMatrix(vector<vector<int>> &matrix)
      : prefix_sums_(matrix.size() + 1,
                     vector<int>(matrix.empty() ? 1 : matrix[0].size() + 1,
                                 0)) {
    for (size_t row = 0; row < matrix.size(); ++row) {
      for (size_t col = 0; col < matrix[row].size(); ++col) {
        prefix_sums_[row + 1][col + 1] =
            prefix_sums_[row + 1][col] + prefix_sums_[row][col + 1] -
            prefix_sums_[row][col] + matrix[row][col];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    const size_t top = static_cast<size_t>(row1);
    const size_t left = static_cast<size_t>(col1);
    const size_t bottom = static_cast<size_t>(row2) + 1;
    const size_t right = static_cast<size_t>(col2) + 1;

    return prefix_sums_[bottom][right] - prefix_sums_[top][right] -
           prefix_sums_[bottom][left] + prefix_sums_[top][left];
  }
};
```

## Complexity

- Time: O(mn) construction, O(1) per query.
- Space: O(mn).
