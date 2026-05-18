#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    // TODO: choose one sorting algorithm to call here
    return nums;
  }

  // 1. 冒泡排序
  void bubbleSort(vector<int> &nums) {
    // TODO: implement bubble sort
    int size = nums.size();
    for (int i = size - 1; i > 0; i--) {
      for (int j = 0; j < i; j++) {
        if (nums[j] > nums[j + 1]) {
          swap(nums[j], nums[j + 1]);
        }
      }
    }
  }

  // 2. 选择排序
  void selectionSort(vector<int> &nums) {
    // TODO: implement selection sort
    for (int i = 0; i < nums.size(); i++) {
      int k = i;
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[j] < nums[k]) {
          k = j;
        }
      }
      swap(nums[i], nums[k]);
    }
  }

  // 3. 插入排序
  vector<int> insertionSort(vector<int> &nums) {
    // TODO: implement insertion sort
    for (int i = 1; i < nums.size(); i++) {
      int base = nums[i], j = i - 1; // 这里要认为i以前都排好序了。
      while (j >= 0 && nums[j] > base) {
        nums[j + 1] = nums[j];
        j--;
      }
      nums[j + 1] = base;
    }
    return nums;
  }

  // 4. 希尔排序
  vector<int> shellSort(vector<int> &nums) {
    // TODO: implement shell sort
    return nums;
  }

  // 5. 归并排序
  vector<int> mergeSort(vector<int> &nums) {
    // TODO: implement merge sort
    return nums;
  }

  // 6. 快速排序
  vector<int> quickSort(vector<int> &nums) {
    // TODO: implement quick sort
    quickSort(nums, 0, nums.size() - 1);
    return nums;
  }

  // 7. 堆排序
  vector<int> heapSort(vector<int> &nums) {
    // TODO: implement heap sort
    return nums;
  }

  // 8. 计数排序
  vector<int> countingSort(vector<int> &nums) {
    // TODO: implement counting sort
    return nums;
  }

  // 9. 桶排序
  vector<int> bucketSort(vector<int> &nums) {
    // TODO: implement bucket sort
    return nums;
  }

  // 10. 基数排序
  vector<int> radixSort(vector<int> &nums) {
    // TODO: implement radix sort
    return nums;
  }

private:
  void mergeSort(vector<int> &nums, int left, int right) {
    // TODO: implement merge sort recursion
  }

  void merge(vector<int> &nums, int left, int mid, int right) {
    // TODO: implement merge helper
  }

  void quickSort(vector<int> &nums, int left, int right) {
    // TODO: implement quick sort recursion
    if (left >= right) {
      return;
    }
    int mid = partition(nums, left, right);
    quickSort(nums, left, mid - 1);
    quickSort(nums, mid + 1, right);
  }

  int partition(vector<int> &nums, int left, int right) {
    // TODO: implement partition helper
    int base = nums[left], l = left, r = right;
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
    swap(nums[left], nums[l]);

    return l;
  }

  void heapify(vector<int> &nums, int heapSize, int root) {
    // TODO: implement heapify helper
  }
};

int main() { return 0; }
