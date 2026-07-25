#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int numDistinctIslands(vector<vector<int>> &grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }

    int rows = static_cast<int>(grid.size());
    int cols = static_cast<int>(grid[0].size());
    unordered_set<string> islands;

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (cell(grid, i, j) == 1) {
          string path;
          dfs(grid, i, j, path, 0);
          islands.insert(path);
        }
      }
    }

    return static_cast<int>(islands.size());
  }

private:
  void dfs(vector<vector<int>> &grid, int i, int j, string &path, int dir) {
    int rows = static_cast<int>(grid.size());
    int cols = static_cast<int>(grid[0].size());
    if (i < 0 || j < 0 || i >= rows || j >= cols || cell(grid, i, j) == 0) {
      return;
    }

    cell(grid, i, j) = 0;
    path += to_string(dir) + ",";

    dfs(grid, i - 1, j, path, 1);
    dfs(grid, i + 1, j, path, 2);
    dfs(grid, i, j - 1, path, 3);
    dfs(grid, i, j + 1, path, 4);

    path += to_string(-dir) + ",";
  }

  int &cell(vector<vector<int>> &grid, int i, int j) {
    return grid[static_cast<size_t>(i)][static_cast<size_t>(j)];
  }
};
