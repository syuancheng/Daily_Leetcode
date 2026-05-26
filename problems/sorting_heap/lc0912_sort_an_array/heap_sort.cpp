#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    heapSort(nums);
    return nums;
  }

private:
  void heapSort(vector<int> &nums) {
    int n = nums.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
      heapify(nums, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
      std::swap(nums[0], nums[i]);

      heapify(nums, i, 0);
    }
  }

  void heapify(vector<int> &nums, int heapSize, int root) {
    int largest = root;
    int leftChild = root * 2 + 1;
    int rightChind = root * 2 + 2;

    if (leftChild < heapSize && nums[leftChild] > nums[largest]) {
      largest = leftChild;
    }
    if (rightChind < heapSize && nums[rightChind] > nums[largest]) {
      largest = rightChind;
    }

    if (largest != root) {
      swap(nums[largest], nums[root]);
      heapify(nums, heapSize, largest);
    }
  }
};

int main() { return 0; }
