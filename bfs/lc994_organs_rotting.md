# 994. Rotting Oranges

## Labels

- Array
- Matrix
- BFS

## Mastery

- Attempts: XH
- Status: Familiar

## Link

https://leetcode.com/problems/rotting-oranges/

## Problem Description

Given a grid where `0` is an empty cell, `1` is a fresh orange, and `2` is a rotten orange, return the minimum number of minutes until no fresh orange remains. Each minute, fresh oranges adjacent vertically or horizontally to rotten oranges become rotten. Return `-1` if some fresh oranges can never rot.

## My Solution

```cpp
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    queue<pair<int, int>> q;
    int fresh = 0;

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] == 2) {
          q.push({i, j});
        } else if (grid[i][j] == 1) {
          fresh++;
        }
      }
    }

    if (fresh == 0) {
      return 0;
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int minutes = 0;

    while (!q.empty() && fresh > 0) {
      int size = q.size();

      for (int i = 0; i < size; i++) {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
          int nx = x + dx[k];
          int ny = y + dy[k];
          if (nx >= 0 && nx < rows && ny >= 0 && ny < cols &&
              grid[nx][ny] == 1) {
            grid[nx][ny] = 2;
            fresh--;
            q.push({nx, ny});
          }
        }
      }
      minutes++;
    }
    return fresh == 0 ? minutes : -1;
  }
};
```

## Complexity

- Time: O(m * n), where `m` and `n` are the grid dimensions.
- Space: O(m * n) in the worst case for the BFS queue.
