#include <cstdlib>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int minIdx = i;
      for (int j = i + 1; j < n; j++) {
        if (nums[j] < nums[minIdx]) {
          minIdx = j;
        }
      }
      swap(nums[i], nums[minIdx]);
    }

    return nums;
  }
};

int partition(vector<int> &nums, int left, int right) {
  int l = left, r = right;

  int randIdx = left + rand() % (right - left + 1);
  swap(nums[left], nums[randIdx]);
  int base = nums[left];
  while (l < r) {
    while (l < r && nums[r] >= base) {
      r--;
    }
    while (l < r && nums[l] <= base) {
      l++;
    }
    swap(nums[l], nums[r]);
  }
  swap(nums[l], nums[left]);
  return l;
}

void quickSort(vector<int> &nums, int left, int right) {
  if (left < right) {
    int mid = partition(nums, left, right);
    quickSort(nums, left, mid - 1);
    quickSort(nums, mid+1, right);
  }
}



int main() { return 0; }