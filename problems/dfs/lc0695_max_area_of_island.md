# 695. Max Area of Island

## Labels

- Array
- Matrix
- DFS

## Mastery

- Attempts: H
- Status: Familiar

## Link

https://leetcode.com/problems/max-area-of-island/

## Problem Description

Given an `m x n` binary matrix `grid`, return the maximum area of an island in the grid.

An island is a group of `1`s connected horizontally or vertically. The area of an island is the number of cells with value `1` in that connected component.

If there is no island, return `0`.

Example:

```text
Input: grid = [[0,0,1,0,0,0,1,1]]
Output: 2
```

## My Solution

```cpp
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
  int result = 0;

public:
  int dfs(vector<vector<int>> &grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
        grid[i][j] == 0) {
      return 0;
    }
    grid[i][j] = 0;

    return 1 + dfs(grid, i - 1, j) + dfs(grid, i + 1, j) + dfs(grid, i, j - 1) +
           dfs(grid, i, j + 1);
  }

  int maxAreaOfIsland(vector<vector<int>> &grid) {
    if (grid.empty()) {
      return 0;
    }

    int rows = grid.size(), cols = grid[0].size();

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] == 1) {

          result = max(result, dfs(grid, i, j));
        }
      }
    }
    return result;
  }
};
```

## Complexity

- Time: O(mn), where `m` is the number of rows and `n` is the number of columns.
- Space: O(mn) in the worst case for the recursion stack when the whole grid is land.
