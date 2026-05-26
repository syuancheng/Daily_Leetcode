#include <cstdlib>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    if (!nums.empty()) {
      quickSort(nums, 0, static_cast<int>(nums.size()) - 1);
    }
    return nums;
  }

private:
  void quickSort(vector<int> &nums, int left, int right) {
    if (left >= right) {
      return;
    }

    int mid = partition(nums, left, right);
    quickSort(nums, left, mid - 1);
    quickSort(nums, mid + 1, right);
  }

  int partition(vector<int> &nums, int left, int right) {
    int randIdx = left + rand() % (right - left + 1);

    swap(nums[randIdx], nums[left]);
    int base = nums[left];
    int l = left, r = right;

    while (l < r) {
      while (l < r && nums[r] >= base) {
        --r;
      }
      while (l < r && nums[l] <= base) {
        ++l;
      }
      if (l < r) {
        swap(nums[l], nums[r]);
      }
    }
    swap(nums[left], nums[l]);
    return l;
  }
};

int main() { return 0; }
