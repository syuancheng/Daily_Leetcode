#include <vector>

using namespace std;
// 形式一、元素无重不可复选，即 nums
// 中的元素都是唯一的，每个元素最多只能被使用一次.

// 组合、子集
class Solution1 {
private:
  vector<int> track;

public:
  void backtrack(std::vector<int> &nums, int start) {
    for (int i = start; i < nums.size(); i++) {
      track.push_back(nums[i]);
      backtrack(nums, i + 1);
      track.pop_back();
    }
  }
};

// 排列
class Solution2 {
private:
  vector<int> track;

  vector<bool> used;

public:
  void backtrack(std::vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
      if (used[i]) {
        continue;
      }
      used[i] == true;
      track.push_back(nums[i]);
      backtrack(nums);
      track.pop_back();
      used[i] = false;
    }
  }
};

// 形式二、元素可重不可复选，即 nums
// 中的元素可以存在重复，每个元素最多只能被使用一次，其关键在于排序和剪枝
// 组合，子集
class Solution3 {
private:
  vector<int> track;

public:
  // sort nums at first
  void backtrack(vector<int> &nums, int start) {

    for (int i = start; i < nums.size(); i++) {
      if (i > start && nums[i - 1] == nums[i]) {
        continue;
      }

      track.push_back(nums[i]);
      backtrack(nums, i + 1);
      track.pop_back();
    }
  }
};

class Solution4 {
private:
  vector<int> track;

public:
  // sort nums at first
  void backtrack(vector<int> &nums, vector<bool> &used) {

    for (int i = 0; i < nums.size(); i++) {
      if (used[i]) {
        continue;
      }

      if (i > 0 && nums[i] == nums[i - 1] &&
          !used[i - 1]) { // 为了避免出现122' 12'2
                          // 这种情况，我们要限制，只有当2被使用后，才能使用2'
        continue;
      }

      used[i] = true;
      track.push_back(nums[i]);
      backtrack(nums, used);
      track.pop_back();
      used[i] = false;
    }
  }
};

// 形式三、元素无重可复选，即 nums
// 中的元素都是唯一的，每个元素可以被使用若干次，只要删掉去重逻辑即可
// 子集，组合
class Solution5 {
private:
  vector<int> track;

public:
  void backtrack(vector<int> &nums, int start) {
    for (int i = start; i < nums.size(); i++) {
      track.push_back(nums[i]);
      backtrack(nums, i);
      track.pop_back();
    }
  }
};
// 排列
class Solution6 {
private:
  vector<int> track;

public:
  void backtrack(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
      track.push_back(nums[i]);
      backtrack(nums);
      track.pop_back();
    }
  }
};
