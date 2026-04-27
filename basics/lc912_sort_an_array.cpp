#include <algorithm>
#include <cstdlib>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {}
};

// 1.快速排序
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
  if (left >= right) {
    return;
  }
  int mid = partition(nums, left, right);
  quickSort(nums, left, mid - 1);
  quickSort(nums, mid + 1, right);
}

// 2.选择排序，双指针。内循环选择最小的和外循环交换
void selectionSort(vector<int> &nums) {
  int n = nums.size();

  for (int i = 0; i < n - 1; i++) {
    int k = i;
    for (int j = i + 1; j < n; j++) {
      if (nums[j] < nums[k]) {
        k = j;
      }
    }
    swap(nums[i], nums[k]);
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

  for (k = 0; k < tmp.size(); k++) {
    nums[left + k] = tmp[k];
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