#include <iostream>
#include <vector>

/**
34. 在排序数组中查找元素的第一个和最后一个位置
*/

using namespace std;

class Solution {
public:
  int binarySearch(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    int ans = -1;
    while (l <= r) {
      int mid = (r - l) / 2 + l;
      int n = nums[mid];
      if (n == target) {
        ans = mid;
        break;
      } else if (n < target) {
        l = mid + 1;
      } else if (n > target) {
        r = mid - 1;
      }
    }
    return ans;
  }

  int binarySearchLeft(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    int ans = -1;
    while (l <= r) {
      int mid = (r - l) / 2 + l;
      int n = nums[mid];
      if (n == target) {
        ans = mid;
        r = mid - 1;
      } else if (n < target) {
        l = mid + 1;
      } else if (n > target) {
        r = mid - 1;
      }
    }
    return ans;
  }

  int binarySearchRight(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    int ans = -1;
    while (l <= r) {
      int mid = (r - l) / 2 + l;
      int n = nums[mid];
      if (n == target) {
        ans = mid;
        l = mid + 1;
      } else if (n < target) {
        l = mid + 1;
      } else if (n > target) {
        r = mid - 1;
      }
    }
    return ans;
  }

  vector<int> searchRange(vector<int> &nums, int target) {
    int l = binarySearchLeft(nums, target);
    int r = binarySearchRight(nums, target);
    if (l >= 0 && r >= l && r < nums.size()) {
      return {l, r};
    }
    return {-1, -1};
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 2, 2, 3};
  int l = s.binarySearchLeft(nums, 2);
  int r = s.binarySearchRight(nums, 2);

  cout << "L: " << l << " ,R: " << r << endl;

  return 0;
}