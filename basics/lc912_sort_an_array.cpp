#include <algorithm>
#include <cstdlib>
#include <utility>
#include <vector>

using namespace std;

void mergeSort(vector<int> &nums, int left, int right);

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    if (!nums.empty()) {
      mergeSort(nums, 0, nums.size() - 1);
    }
    return nums;
  }
};

// 1.快速排序
int partition(vector<int> &nums, int left, int right) {
  int l = left, r = right;
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
  swap(nums[left], nums[l]);
  return l;
}

void quickSort(vector<int> &nums, int s, int t) {
  if (s >= t) {
    return;
  }
  int mid = partition(nums, s, t);
  quickSort(nums, s, mid - 1);
  quickSort(nums, mid + 1, t);
}

// 2.选择排序，双指针。内循环选择最小的和外循环交换
void selectionSort(vector<int> &nums) {
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    int minIdx = i;
    for (int j = i+1; j < n; j++) {
      if (nums[j] < nums[minIdx]) {
        minIdx = j;
      }
    }
    swap(nums[i], nums[minIdx]);
  }
}

// 3. 归并排序
void merge(vector<int> &nums, int left, int mid, int right) {
  vector<int> tmp(right - left + 1);
  int i = left, j = mid + 1, k = 0;
  while (i <= mid && j <= right) {
    if (nums[i] <= nums[j]) {
      tmp[k++] = nums[i++];

    } else {
      tmp[k++] = nums[j++];
    }
  }
  while (i <= mid) {
    tmp[k++] = nums[i++];
  }
  while (j <= right) {
    tmp[k++] = nums[j++];
  }

  for (int idx = 0; idx < k; idx++) {
    nums[left + idx] = tmp[idx];
  }
}

void mergeSort(vector<int> &nums, int left, int right) {
  if (left >= right) {
    return;
  }
  int mid = left + (right - left) / 2;
  mergeSort(nums, left, mid);
  mergeSort(nums, mid + 1, right);

  // 合并阶段
  merge(nums, left, mid, right);
}

int main() { return 0; }
