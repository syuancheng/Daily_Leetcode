#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    selectionSort(nums);
    return nums;
  }

private:
  void selectionSort(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
      int minIndex = i;
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[j] < nums[minIndex]) {
          minIndex = j;
        }
      }
      swap(nums[i], nums[minIndex]);
    }
  }
};

int main() { return 0; }
