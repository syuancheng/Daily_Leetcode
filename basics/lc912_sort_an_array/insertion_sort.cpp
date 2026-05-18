#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    insertionSort(nums);
    return nums;
  }

private:
  void insertionSort(vector<int> &nums) {
    for (int i = 1; i < nums.size(); ++i) {
      int base = nums[i];
      int j = i - 1;
      while (j >= 0 && nums[j] > base) {
        nums[j + 1] = nums[j];
        --j;
      }
      nums[j + 1] = base;
    }
  }
};

int main() { return 0; }
