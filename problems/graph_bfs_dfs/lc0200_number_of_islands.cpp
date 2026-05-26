#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    if (grid.empty()) {
      return 0;
    }
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (grid[i][j] != '1') {
          continue;
        }

        count++;
        grid[i][j] = '0';

        queue<pair<int, int>> queue;
        queue.push({i, j});

        while (!queue.empty()) {
          auto [x, y] = queue.front();
          queue.pop();

          for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == '1') {
              grid[nx][ny] = '0';
              queue.push({nx, ny});
            }
          }
        }
      }
    }

    return count;
  }
};
