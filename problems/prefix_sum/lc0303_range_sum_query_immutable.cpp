#include <cstddef>
#include <vector>

using namespace std;

class NumArray {
  vector<int> prefix_sums_;

public:
  NumArray(vector<int> &nums) : prefix_sums_(nums.size() + 1, 0) {
    for (size_t i = 0; i < nums.size(); ++i) {
      prefix_sums_[i + 1] = prefix_sums_[i] + nums[i];
    }
  }

  int sumRange(int left, int right) {
    return prefix_sums_[static_cast<size_t>(right) + 1] -
           prefix_sums_[static_cast<size_t>(left)];
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
