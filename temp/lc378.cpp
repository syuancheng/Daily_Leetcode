#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    auto cmp = [](vector<int> &a, vector<int> &b) { return a[0] > b[0]; };

    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

    for (int i = 0; i < matrix.size(); i++) {
      pq.push({matrix[i][0], i, 0}); // first elem, NO.1 list, index in list
    }

    int res = -1;

    while (!pq.empty() && k > 0) {
      vector<int> cur = pq.top();
      pq.pop();

      res = cur[0];
      k--;

      int i = cur[1], j = cur[2];
      if (j + 1 < matrix[i].size()) {
        pq.push({matrix[i][j + 1], i, j + 1});
      }
    }

    return res;
  }
};