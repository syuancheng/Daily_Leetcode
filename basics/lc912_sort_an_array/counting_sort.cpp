#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    countingSort(nums);
    return nums;
  }

private:
  void countingSort(vector<int> &nums) {
    // TODO: implement counting sort
  }
};

int main() { return 0; }
