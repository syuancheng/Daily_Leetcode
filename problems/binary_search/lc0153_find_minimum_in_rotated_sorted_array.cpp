#include <vector>

using namespace std;

/**
153. 寻找旋转排序数组中的最小值
*/

class Solution {
public:
  int findMin(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = (r - l) / 2 + l;
      if (nums[l] <= nums[mid] && nums[mid] <= nums[r]) {
        return nums[l];
      }
      if (nums[l] <= nums[mid]) {
        l = mid+1;
      } else {
         r = mid;
      }
    }
    return 0;
  }
};