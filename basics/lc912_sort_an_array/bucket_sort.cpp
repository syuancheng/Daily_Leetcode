#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    bucketSort(nums);
    return nums;
  }

private:
  void bucketSort(vector<int> &nums) {
    // TODO: implement bucket sort
  }
};

int main() { return 0; }
