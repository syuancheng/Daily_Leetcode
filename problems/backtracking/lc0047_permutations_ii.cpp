#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    result_.clear();
    path_.clear();
    used_.assign(nums.size(), false);
    backtrack(nums);
    return result_;
  }

private:
  vector<vector<int>> result_;
  vector<int> path_;
  vector<bool> used_;

  void backtrack(const vector<int> &nums) {
    if (path_.size() == nums.size()) {
      result_.push_back(path_);
      return;
    }

    for (size_t i = 0; i < nums.size(); ++i) {
      if (used_[i]) {
        continue;
      }
      if (i > 0 && nums[i] == nums[i - 1] && !used_[i - 1]) {
        continue;
      }

      used_[i] = true;
      path_.push_back(nums[i]);
      backtrack(nums);
      path_.pop_back();
      used_[i] = false;
    }
  }
};
