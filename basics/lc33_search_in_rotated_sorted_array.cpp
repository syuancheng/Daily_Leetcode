#include <vector>

using namespace std;


class Solution {
public:
  int search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1, s = nums.size();
    while (l <= r) {
      int mid = (r - l) / 2 + l;
      int val = nums[mid];
      if (val == target) {
        return mid;
      }
      if (nums[0] <= val) {
        if (nums[0] <= target && target < val) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      } else {
        if (val < target && target <= nums[s - 1]) {
          l = mid +1;
        } else {
          r = mid -1;
        }
      }
    }
    return -1;
  }
};