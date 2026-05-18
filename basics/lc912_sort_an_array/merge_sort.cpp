#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    if (!nums.empty()) {
      mergeSort(nums, 0, static_cast<int>(nums.size()) - 1);
    }
    return nums;
  }

private:
  void mergeSort(vector<int> &nums, int left, int right) {
    // TODO: implement merge sort recursion
  }

  void merge(vector<int> &nums, int left, int mid, int right) {
    // TODO: implement merge helper
  }
};

int main() { return 0; }
