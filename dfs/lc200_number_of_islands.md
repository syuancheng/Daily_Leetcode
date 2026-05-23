# 200. Number of Islands

## Labels

- Array
- Matrix
- DFS
- BFS

## Mastery

- Attempts: H
- Status: Beginner

## Link

https://leetcode.com/problems/number-of-islands/

## Problem Description

Given an `m x n` grid of characters where `'1'` represents land and `'0'` represents water, return the number of islands. An island is formed by connecting adjacent land cells horizontally or vertically. Cells outside the grid are treated as water.

## My Solution

```cpp
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  void flood(vector<vector<char>> &grid, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
      return;
    }
    if (grid[i][j] == '0') {
      return;
    }
    grid[i][j] = '0';
    flood(grid, i - 1, j);
    flood(grid, i + 1, j);
    flood(grid, i, j - 1);
    flood(grid, i, j + 1);
  }
  
  int numIslands(vector<vector<char>> &grid) {
    int count = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] != '1') {
          continue;
        }
        flood(grid, i, j);
        count++;
      }
    }
    return count;
  }
};
```

## Complexity

- Time: O(m * n), where `m` is the number of rows and `n` is the number of columns. Each cell is visited at most once.
- Space: O(m * n) in the worst case due to the recursion stack when the whole grid is land.
