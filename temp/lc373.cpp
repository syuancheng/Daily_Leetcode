#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                     int k) {

    vector<vector<int>> res;

    auto cmp = [](vector<int> &a, vector<int> &b) {
      return (a[0] + a[1]) > (b[0] + b[1]);
    };

    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

    for (int i = 0; i < nums1.size(); i++) {
      pq.push({nums1[i], nums2[0],
               0}); // push 0 in 2nd elem is for store the index of nums2
    }

    while (!pq.empty() && k > 0) {
      vector<int> cur = pq.top();
      pq.pop();
      k--;

      int next_index = cur[2] + 1;
      if (next_index < nums2.size()) {
        pq.push({cur[0], nums2[next_index], next_index});
      }

      res.push_back({cur[0], cur[1]});
    }
    return res;
  }
};