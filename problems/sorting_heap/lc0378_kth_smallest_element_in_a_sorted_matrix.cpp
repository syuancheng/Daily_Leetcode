#include <cstddef>
#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
  struct Cell {
    int value;
    size_t row;
    size_t col;
  };

public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    auto cmp = [](const Cell &a, const Cell &b) { return a.value > b.value; };
    priority_queue<Cell, vector<Cell>, decltype(cmp)> pq(cmp);

    for (size_t i = 0; i < matrix.size(); i++) {
      pq.push({matrix[i][0], i, 0});
    }

    int result = -1;

    while (!pq.empty() && k > 0) {
      Cell cur = pq.top();
      pq.pop();

      result = cur.value;
      k--;

      size_t nextCol = cur.col + 1;
      if (nextCol < matrix[cur.row].size()) {
        pq.push({matrix[cur.row][nextCol], cur.row, nextCol});
      }
    }

    return result;
  }
};
