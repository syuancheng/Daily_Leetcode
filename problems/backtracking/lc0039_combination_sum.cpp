#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    result_.clear();
    path_.clear();
    backtrack(candidates, 0, target);
    return result_;
  }

private:
  vector<vector<int>> result_;
  vector<int> path_;

  void backtrack(const vector<int> &candidates, size_t start, int remaining) {
    if (remaining == 0) {
      result_.push_back(path_);
      return;
    }

    for (size_t i = start; i < candidates.size(); ++i) {
      if (candidates[i] > remaining) {
        break;
      }

      path_.push_back(candidates[i]);
      backtrack(candidates, i, remaining - candidates[i]);
      path_.pop_back();
    }
  }
};
