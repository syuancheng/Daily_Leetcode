#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    priority_queue<int> q;
    for (int i = 0; i < k; i++) {
      q.push(nums[i]);
    }

    for (int j = k; j < nums.size(); j++) {
      if (nums[j] > q.top()) {
        q.pop();
        q.push(nums[j]);
      }
    }

    return q.top();
  }
};
