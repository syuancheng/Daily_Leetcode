#include <algorithm>
#include <vector>

using namespace std;



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) {
          return 0;
        }
        int pre = nums[0];
        int max = pre;
        for (int i = 1; i < nums.size(); i++) {
          if (pre > 0) {
            pre += nums[i];
          } else {
            pre = nums[i];
          }
          max = std::max(max, pre);
        }
        return max;
    }
};