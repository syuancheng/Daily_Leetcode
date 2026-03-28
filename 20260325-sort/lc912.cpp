#include <cstddef>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();
    for (size_t i = 0; i < n - 1; i++) {
      bool swapped = false;
      for (size_t j = 0; j < n - 1 - i; j++) {
        if (nums[j] > nums[j + 1]) {
          swap(nums[j], nums[j + 1]);
          swapped = true;
        }
      }
      if (!swapped) {
        return nums;
      }
    }

    return nums;
  }
  // 选择排序
  vector<int> sortArray2(vector<int> &nums) {
    int n = nums.size();
    for (size_t i = 0; i < n - 1; i++) {
      int minIdx = i;

      for (size_t j = i + 1; j < n; j++) {
        if (nums[j] < nums[minIdx]) {
          minIdx = j;
        }
      }
      swap(nums[i], nums[minIdx]);
    }

    return nums;
  }

  // 插入排序
  vector<int> sortArray3(vector<int> &nums) {
    int n = nums.size();
    for (size_t i = 1; i < n; i++) {
      int minIdx = i;

      for (size_t j = i + 1; j < n; j++) {
        if (nums[j] < nums[minIdx]) {
          minIdx = j;
        }
      }
      swap(nums[i], nums[minIdx]);
    }

    return nums;
  }

  int Partition(vector<int> &nums, int s, int t) {
    int i = s, j = t;
    int base = nums[s];
    while (i < j) {
      while (j > i && nums[j] >= base) {
        j--;
      }
      if (j > i) {
        nums[i] = nums[j];
        i++;
      }
      while (i < j && nums[i] <= base) {
        i++;
      }
      if (i < j) {
        nums[j] = nums[i];
        j--;
      }
    }
    nums[i] = base;
    return i;
  }

  void quickSort(vector<int> &nums, int s, int t) {
    if (s < t) {
      int i = Partition(nums, s, t);
      quickSort(nums, s, i - 1);
      quickSort(nums, i + 1, t);
    }
  }

  vector<int> sortArray4(vector<int> &nums) {
    quickSort(nums, 0, nums.size() - 1);
    return nums;
  }
};