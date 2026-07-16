#include <cstddef>
#include <vector>

using namespace std;

class PermutationsWithRepetition {
public:
  vector<vector<int>> generate(const vector<int> &values, size_t length) {
    result_.clear();
    path_.clear();
    backtrack(values, length);
    return result_;
  }

private:
  vector<vector<int>> result_;
  vector<int> path_;

  void backtrack(const vector<int> &values, size_t length) {
    if (path_.size() == length) {
      result_.push_back(path_);
      return;
    }

    for (int value : values) {
      path_.push_back(value);
      backtrack(values, length);
      path_.pop_back();
    }
  }
};
