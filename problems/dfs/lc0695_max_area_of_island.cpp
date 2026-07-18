#include <vector>

using namespace std;

class Solution {
private:
  int area = 0;

  int maxArea = 0;

public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          dfs(grid, i, j);
          maxArea = maxArea > area ? maxArea : area;
          area = 0;
        }
      }
    }
    return maxArea;
  }

  void dfs(vector<vector<int>> &grid, int i, int j) {
    int m = grid.size(), n = grid[0].size();

    if (i < 0 || j < 0 || i >= m || j >= n) {
      return;
    }

    if (grid[i][j] == 0) {
      return;
    }

    grid[i][j] = 0;
    area++;
    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
  }
};
