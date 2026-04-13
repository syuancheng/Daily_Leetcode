#include <vector>

using namespace std;

vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();
    if (n < 2) {
      return nums;
    }

    for (int i = 0; i < n; ++i) {
      bool swapped = false;
      for (int j = 0; j + 1 < n - i; ++j) {
        if (nums[j] > nums[j + 1]) {
          swap(nums[j], nums[j + 1]);
          swapped = true;
        }
      }

      if (!swapped) {
        break;
      }
    }

    // for (int i = 0; i < n - 1; ++i) {
    //   bool swapped = false;

    //   for (int j = 0; j < n - 1 - i; ++j) {
    //     if (nums[j] > nums[j + 1]) {
    //       std::swap(nums[j], nums[j + 1]);
    //       swapped = true;
    //     }
    //   }

    //   if (!swapped)
    //     break;
    // }

    return nums;
  }