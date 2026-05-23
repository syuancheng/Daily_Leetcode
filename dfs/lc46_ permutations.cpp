#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> result;

public:
  void dfs(vector<int> &nums, vector<int> &remain) {
    if (remain.empty()) {
      result.push_back(nums);
      return;
    }

    for (int i = 0; i < remain.size(); ++i) {
      nums.push_back(remain[i]);
      remain.erase(remain.begin() + i);

      dfs(nums, remain);

      remain.insert(remain.begin() + i, nums.back());
      nums.pop_back();
    }
  }
  vector<vector<int>> permute(vector<int> &nums) {
    vector<int> remain = nums;
    vector<int> current;
    dfs(current, remain);
    return result;
  }
};