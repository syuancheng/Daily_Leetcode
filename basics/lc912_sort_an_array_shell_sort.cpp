#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    shellSort(nums);
    return nums;
  }

private:
  void shellSort(vector<int> &nums) {
    // TODO: implement shell sort
  }
};

int main() { return 0; }
