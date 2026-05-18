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
    // TODO: implement heap sort
  }

  void heapify(vector<int> &nums, int heapSize, int root) {
    // TODO: implement heapify helper
  }
};

int main() { return 0; }
