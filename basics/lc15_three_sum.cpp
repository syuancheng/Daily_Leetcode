#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    stable_sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int len = nums.size();
    for (int i = 0; i < nums.size(); i++) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int target = -nums[i];
      int l = i + 1, r = len - 1;
      while (l < r) {
        int sum = nums[l] + nums[r];
        if (sum == target) {
          res.push_back({nums[i], nums[l], nums[r]});
          l++;
          r--;

          while (l < r && nums[l] == nums[l - 1]) {
            l++;
          }

          while (l < r && nums[r] == nums[r + 1]) {
            r--;
          }

        } else if (sum < target) {
          l++;
        } else {
          r--;
        }
      }
    }
    return res;
  }
};