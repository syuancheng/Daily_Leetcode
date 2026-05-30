# 200. Number of Islands

## Labels

- Array
- Matrix
- DFS

## Mastery

- Attempts: H
- Status: Familiar

## Link

https://leetcode.com/problems/number-of-islands/

## Problem Description

Given an `m x n` grid of characters where `'1'` represents land and `'0'` represents water, return the number of islands.

An island is formed by horizontally or vertically adjacent land cells and is surrounded by water. You may assume all four edges of the grid are surrounded by water.

Example:

```text
Input:
grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
```

## My Solution

```cpp
#include <vector>

using namespace std;

class Solution {
private:
  int result = 0;

public:
  void dfs(vector<vector<char>> &grid, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
        grid[i][j] == '0') {
      return;
    }
    grid[i][j] = '0';

    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
  }
  int numIslands(vector<vector<char>> &grid) {
    if (grid.empty()) {
      return 0;
    }
    int rows = grid.size(), cols = grid[0].size();
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (grid[i][j] == '0') {
          continue;
        }
        result++;
        dfs(grid, i, j);
      }
    }
    return result;
  }
};
```

## Complexity

- Time: O(mn), where `m` is the number of rows and `n` is the number of columns.
- Space: O(mn) in the worst case for the recursion stack when the whole grid is land.
