#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;

    while (l <= r) {
      int mid = (r - l) / 2 + l;
      int num = nums[mid];

      if (num == target) {
        return mid;
      } else if (num < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return -1;
  }
};