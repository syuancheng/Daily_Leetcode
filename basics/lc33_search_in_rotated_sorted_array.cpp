#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    if (nums.empty()) {
      return -1;
    }
    int size = nums.size();
    int l = 0, r = size - 1;
    while (l <= r) {
      int mid = (r - l) / 2 + l;
      if (nums[mid] == target) {
        return mid;
      }

      if (nums[0] <= nums[mid]) {
        if (nums[0] <= target && target < nums[mid]) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      } else {
        if (nums[mid] < target && target <= nums[size - 1]) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
    }
    return -1;
  }
};
