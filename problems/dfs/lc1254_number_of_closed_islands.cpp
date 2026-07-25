#include <vector>

using namespace std;

class Solution {
public:
  int closedIsland(vector<vector<int>> &grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }

    int rows = static_cast<int>(grid.size());
    int cols = static_cast<int>(grid[0].size());

    for (int i = 0; i < rows; i++) {
      dfs(grid, i, 0);
      dfs(grid, i, cols - 1);
    }

    for (int j = 0; j < cols; j++) {
      dfs(grid, 0, j);
      dfs(grid, rows - 1, j);
    }

    int result = 0;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (cell(grid, i, j) == 0) {
          result++;
          dfs(grid, i, j);
        }
      }
    }
    return result;
  }

private:
  void dfs(vector<vector<int>> &grid, int i, int j) {
    int rows = static_cast<int>(grid.size());
    int cols = static_cast<int>(grid[0].size());
    if (i < 0 || j < 0 || i >= rows || j >= cols || cell(grid, i, j) == 1) {
      return;
    }

    cell(grid, i, j) = 1;
    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
  }

  int &cell(vector<vector<int>> &grid, int i, int j) {
    return grid[static_cast<size_t>(i)][static_cast<size_t>(j)];
  }
};
