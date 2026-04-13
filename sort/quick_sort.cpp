#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int Partition(vector<int> &nums, int s, int t) {
  int l = s, r = t;
  int base = nums[s];
  while (l < r) {
    while (r > l && nums[r] >= base) {
      r--;
    }
    if (r > l) {
      nums[l] = nums[r];
      l++;
    }
    while (l < r && nums[l] <= base) {
      l++;
    }
    if (l < r) {
      nums[r] = nums[l];
      r--;
    }
  }
  nums[l] = base;
  return l;
}

void quickSort(vector<int> &nums, int s, int t) {
  if (s < t) {
    int i = Partition(nums, s, t);
    quickSort(nums, s, i - 1);
    quickSort(nums, i + 1, t);
  }
}

vector<int> sortArray(vector<int> &nums) {
  quickSort(nums, 0, nums.size() - 1);
  return nums;
}

int main() {
  vector<int> test = {2, 3, 1, 5, 4};

  sortArray(test);

  for (const auto &val : test) {
    cout << val << endl;
  }

  return 0;
}