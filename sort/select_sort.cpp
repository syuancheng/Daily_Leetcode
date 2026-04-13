#include <iostream>
#include <utility>
#include <vector>

using namespace std;

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

int main() {
  vector<int> test = {2, 3, 1, 5, 4};

  sortArray(test);

  for (const auto &val : test) {
    cout << val << endl;
  }

  return 0;
}