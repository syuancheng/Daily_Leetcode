#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<int>> result;

public:
  void dfs(vector<int> &current, vector<int> &remain) {
    if (remain.empty()) {
      result.push_back(current);
      // 这里应该return
      return;
    }

    for (int i = 0; i < remain.size(); i++) {
      current.push_back(remain[i]);
      remain.erase(remain.begin() + i);

      dfs(current, remain);

      remain.insert(remain.begin() + i, current.back());
      current.pop_back();
    }
  }
  
  vector<vector<int>> permute(vector<int> &nums) {
    if (nums.empty()) {
      return {};
    }
    vector<int> current;
    dfs(current, nums);
    return result;
  }
};
