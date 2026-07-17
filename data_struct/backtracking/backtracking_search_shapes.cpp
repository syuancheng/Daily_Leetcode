#include <algorithm>
#include <cstddef>
#include <vector>

using namespace std;

namespace backtracking_search_shapes {

// Distinct values, each index can be chosen at most once.
// Typical problems: subsets and combinations without duplicate input values.
class DistinctChooseOnce {
public:
  vector<vector<int>> subsets(vector<int> nums) {
    result_.clear();
    path_.clear();
    backtrack(nums, 0);
    return result_;
  }

private:
  vector<vector<int>> result_;
  vector<int> path_;

  void backtrack(const vector<int> &nums, size_t start) {
    result_.push_back(path_);

    for (size_t i = start; i < nums.size(); ++i) {
      path_.push_back(nums[i]);
      backtrack(nums, i + 1);
      path_.pop_back();
    }
  }
};

// Distinct values, each index can be used once, and order matters.
// Typical problem: permutations.
class DistinctPermuteOnce {
public:
  vector<vector<int>> permute(vector<int> nums) {
    result_.clear();
    path_.clear();
    used_.assign(nums.size(), false);
    backtrack(nums);
    return result_;
  }

private:
  vector<vector<int>> result_;
  vector<int> path_;
  vector<bool> used_;

  void backtrack(const vector<int> &nums) {
    if (path_.size() == nums.size()) {
      result_.push_back(path_);
      return;
    }

    for (size_t i = 0; i < nums.size(); ++i) {
      if (used_[i]) {
        continue;
      }

      used_[i] = true;
      path_.push_back(nums[i]);
      backtrack(nums);
      path_.pop_back();
      used_[i] = false;
    }
  }
};

// Duplicate values, each index can be chosen at most once.
// Sort first, then skip duplicate choices on the same tree level.
// Typical problems: subsets II and combination sum II.
class DuplicateChooseOnce {
public:
  vector<vector<int>> subsetsWithDup(vector<int> nums) {
    sort(nums.begin(), nums.end());
    result_.clear();
    path_.clear();
    backtrack(nums, 0);
    return result_;
  }

private:
  vector<vector<int>> result_;
  vector<int> path_;

  void backtrack(const vector<int> &nums, size_t start) {
    result_.push_back(path_);

    for (size_t i = start; i < nums.size(); ++i) {
      if (i > start && nums[i] == nums[i - 1]) {
        continue;
      }

      path_.push_back(nums[i]);
      backtrack(nums, i + 1);
      path_.pop_back();
    }
  }
};

// Duplicate values, each index can be used once, and order matters.
// Sort first. If the previous equal value is unused in this branch, choosing
// the later equal value first would create duplicate permutations.
class DuplicatePermuteOnce {
public:
  vector<vector<int>> permuteUnique(vector<int> nums) {
    sort(nums.begin(), nums.end());
    result_.clear();
    path_.clear();
    used_.assign(nums.size(), false);
    backtrack(nums);
    return result_;
  }

private:
  vector<vector<int>> result_;
  vector<int> path_;
  vector<bool> used_;

  void backtrack(const vector<int> &nums) {
    if (path_.size() == nums.size()) {
      result_.push_back(path_);
      return;
    }

    for (size_t i = 0; i < nums.size(); ++i) {
      if (used_[i]) {
        continue;
      }
      if (i > 0 && nums[i] == nums[i - 1] && !used_[i - 1]) {
        continue;
      }

      used_[i] = true;
      path_.push_back(nums[i]);
      backtrack(nums);
      path_.pop_back();
      used_[i] = false;
    }
  }
};

// Distinct values, each value can be chosen repeatedly, and order does not
// matter. Typical problem: combination sum.
class DistinctChooseRepeat {
public:
  vector<vector<int>> combinationSum(vector<int> nums, int target) {
    sort(nums.begin(), nums.end());
    result_.clear();
    path_.clear();
    backtrack(nums, 0, target);
    return result_;
  }

private:
  vector<vector<int>> result_;
  vector<int> path_;

  void backtrack(const vector<int> &nums, size_t start, int remaining) {
    if (remaining == 0) {
      result_.push_back(path_);
      return;
    }

    for (size_t i = start; i < nums.size(); ++i) {
      if (nums[i] > remaining) {
        break;
      }

      path_.push_back(nums[i]);
      backtrack(nums, i, remaining - nums[i]);
      path_.pop_back();
    }
  }
};

// Distinct values, each value can be chosen repeatedly, and order matters.
// A length limit is required; otherwise recursion has no natural stop.
class DistinctPermuteRepeat {
public:
  vector<vector<int>> generate(vector<int> nums, size_t length) {
    result_.clear();
    path_.clear();
    backtrack(nums, length);
    return result_;
  }

private:
  vector<vector<int>> result_;
  vector<int> path_;

  void backtrack(const vector<int> &nums, size_t length) {
    if (path_.size() == length) {
      result_.push_back(path_);
      return;
    }

    for (int value : nums) {
      path_.push_back(value);
      backtrack(nums, length);
      path_.pop_back();
    }
  }
};

} // namespace backtracking_search_shapes
