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

private:
  void quickSort(vector<int> &nums, int start, int end) {
    if (start >= end) {
      return;
    }
    int mid = prorition(nums, start, end);
    quickSort(nums, start, mid - 1);
    quickSort(nums, mid + 1, end);
  }

  int prorition(vector<int> &nums, int start, int end) {
    int l = start, r = end;
    int base = nums[start];

    while (l < r) {
      while (l < r && nums[r] >= base) {
        r--;
      }
      while (l < r && nums[l] <= base) {
        l++;
      }
      if (l < r) {
        swap(nums[l], nums[r]);
      }
    }
    swap(nums[l], base);
    return l
  }
};

int main() {}
