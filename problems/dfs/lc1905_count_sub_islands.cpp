#include <vector>

using namespace std;

class Solution {
public:
  int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
    if (grid1.empty() || grid1[0].empty()) {
      return 0;
    }

    int rows = static_cast<int>(grid1.size());
    int cols = static_cast<int>(grid1[0].size());
    int result = 0;

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (cell(grid2, i, j) == 1 && dfs(grid1, grid2, i, j)) {
          result++;
        }
      }
    }

    return result;
  }

private:
  bool dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i,
           int j) {
    int rows = static_cast<int>(grid1.size());
    int cols = static_cast<int>(grid1[0].size());
    if (i < 0 || j < 0 || i >= rows || j >= cols || cell(grid2, i, j) == 0) {
      return true;
    }

    cell(grid2, i, j) = 0;

    bool isSubIsland = cell(grid1, i, j) == 1;
    isSubIsland &= dfs(grid1, grid2, i - 1, j);
    isSubIsland &= dfs(grid1, grid2, i + 1, j);
    isSubIsland &= dfs(grid1, grid2, i, j - 1);
    isSubIsland &= dfs(grid1, grid2, i, j + 1);

    return isSubIsland;
  }

  int &cell(vector<vector<int>> &grid, int i, int j) {
    return grid[static_cast<size_t>(i)][static_cast<size_t>(j)];
  }
};
