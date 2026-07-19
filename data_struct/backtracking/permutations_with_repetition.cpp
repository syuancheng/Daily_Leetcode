#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> res;
  deque<int> track;

  vector<vector<int>> permuteRepeat(vector<int> &nums) {
    backtrack(nums);
    return res;
  }

  void backtrack(const vector<int> &nums) {
    if (track.size() == nums.size()) {
      res.push_back({track.begin(), track.end()});
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      track.push_back(nums[i]);
      backtrack(nums);
      track.pop_back();
    }
  }
};
