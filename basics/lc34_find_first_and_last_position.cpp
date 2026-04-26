#include <vector>

using namespace std;

// no idea

class Solution {
public:
  int findLeftIndex(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    int res = -1;

    while (l <= r) {
      int mid = (r - l) / 2 + l;
      int n = nums[mid];

      if (n == target) {
        res = mid;
        r = mid - 1;
      } else if (n < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    return res;
  }

  int findRightIndex(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    int res = -1;

    while (l <= r) {
      int mid = (r - l) / 2 + l;
      int n = nums[mid];

      if (n == target) {
        res = mid;
        l = mid + 1;
      } else if (n < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    return res;
  }

  vector<int> searchRange(vector<int> &nums, int target) {
    int l = findLeftIndex(nums, target);
    int r = findRightIndex(nums, target);
    if (l >= 0 && l <= r && r < nums.size()) {
      return {l, r};
    }
    return {-1, -1};
  }
};