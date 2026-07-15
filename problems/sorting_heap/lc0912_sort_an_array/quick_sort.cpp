#include <algorithm>
#include <cstdlib>
#include <locale>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    quickSort(nums, 0, nums.size() - 1);
  }

  void quickSort(vector<int> &nums, int l, int r) {
    if (l >= r) {
      return;
    }
    int mid = partition(nums, l, r);
    quickSort(nums, l, mid - 1);
    quickSort(nums, mid + 1, r);
  }

  int partition(vector<int> &nums, int left, int right) {
    int l = left, r = right;
    int base = nums[left];

    while (l < r) {
      while (l < r && nums[r] >= base) {
        r--;
      }
      while (l < r && nums[l] >= base) {
        l++;
      }
      if (l < r) {
        swap(nums[l], nums[r]);
      }
    }
    swap(nums[l], nums[left]);
    return l;
  }
};