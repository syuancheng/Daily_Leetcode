#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    result_.clear();
    path_.clear();
    backtrack(nums, 0);
    return result_;
  }

private:
  vector<vector<int>> result_;
  vector<int> path_;

  void backtrack(const vector<int> &nums, size_t start) {
    result_.push_back(path_);

    for (size_t i = start; i < nums.size(); ++i) {
      if (i > start && nums[i] == nums[i - 1]) {
        continue;
      }

      path_.push_back(nums[i]);
      backtrack(nums, i + 1);
      path_.pop_back();
    }
  }
};
