# 200. Number of Islands

## Labels

- Array
- DFS
- Matrix

## Mastery

- Mastery: Needs Review (不熟练)

## Link

https://leetcode.com/problems/number-of-islands/

## Problem Description

Given a 2D grid of `'1'` land and `'0'` water, count the number of islands. An island is formed by horizontally or vertically connected land cells.

## My Solution

```cpp
#include <vector>

using namespace std;

class Solution {
public:
  void dfs(vector<vector<char>> &grid, int r, int c) {
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() ||
        grid[r][c] == '0') {
      return;
    }
    grid[r][c] = '0';
    dfs(grid, r, c + 1);
    dfs(grid, r, c - 1);
    dfs(grid, r + 1, c);
    dfs(grid, r - 1, c);
  }
  int numIslands(vector<vector<char>> &grid) {
    int res = 0;
    for (int r = 0; r < grid.size(); r++) {
      for (int c = 0; c < grid[0].size(); c++) {
        if (grid[r][c] == '1') {
          res++;
          dfs(grid, r, c);
        }
      }
    }
    return res;
  }
};
```

## Complexity

- Time: O(m * n), where `m` and `n` are the grid dimensions.
- Space: O(m * n) in the worst case due to DFS recursion.
