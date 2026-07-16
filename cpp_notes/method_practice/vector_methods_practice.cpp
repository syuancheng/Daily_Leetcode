#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

void printTitle(const string &title) {
  cout << "\n========== " << title << " ==========\n";
}

void printVector(const vector<int> &nums) {
  cout << "[";
  for (size_t i = 0; i < nums.size(); ++i) {
    if (i > 0) {
      cout << ", ";
    }
    cout << nums[i];
  }
  cout << "]\n";
}

void demoConstructionAndAccess() {
  printTitle("construction / access");

  vector<int> a;
  vector<int> b = {1, 2, 3};
  vector<int> c(5, 9);

  cout << "a.empty(): " << boolalpha << a.empty() << '\n';
  cout << "b: ";
  printVector(b);
  cout << "c vector<int>(5, 9): ";
  printVector(c);

  cout << "b.size(): " << b.size() << '\n';
  cout << "b[1]: " << b[1] << '\n';
  cout << "b.at(1): " << b.at(1) << '\n';
  cout << "b.front(): " << b.front() << '\n';
  cout << "b.back(): " << b.back() << '\n';
}

void demoCapacityAndModify() {
  printTitle("capacity / modify");

  vector<int> nums;
  nums.reserve(10);
  cout << "after reserve(10), capacity: " << nums.capacity() << '\n';

  nums.push_back(1);
  nums.push_back(2);
  nums.emplace_back(3);
  cout << "push_back / emplace_back: ";
  printVector(nums);

  nums.insert(nums.begin() + 1, 99);
  cout << "insert 99 at index 1: ";
  printVector(nums);

  nums.erase(nums.begin() + 1);
  cout << "erase index 1: ";
  printVector(nums);

  nums.pop_back();
  cout << "pop_back: ";
  printVector(nums);

  nums.resize(5, 7); // Change size to 5; new elements are filled with 7.
  cout << "resize(5, 7): ";
  printVector(nums);

  nums.clear();
  cout << "clear, size: " << nums.size() << ", capacity still: " << nums.capacity()
       << '\n';
}

void demoAlgorithms() {
  printTitle("algorithms");

  vector<int> nums = {5, 1, 4, 2, 2, 3};
  cout << "original: ";
  printVector(nums);

  sort(nums.begin(), nums.end());//默认是升序
  cout << "sort: ";
  printVector(nums);

  reverse(nums.begin(), nums.end());
  cout << "reverse: ";
  printVector(nums);

  sort(nums.begin(), nums.end());
  auto newEnd = unique(nums.begin(), nums.end());
  nums.erase(newEnd, nums.end());
  cout << "sort + unique + erase: ";
  printVector(nums);

  //lower_bound: 第一个 >= target
  //upper_bound: 第一个 > target
  auto it = lower_bound(nums.begin(), nums.end(), 3);
  cout << "lower_bound 3 index: " << distance(nums.begin(), it) << '\n';

  cout << "count 2: " << count(nums.begin(), nums.end(), 2) << '\n';
  cout << "find 4 exists: " << (find(nums.begin(), nums.end(), 4) != nums.end())
       << '\n';
  cout << "min: " << *min_element(nums.begin(), nums.end()) << '\n';
  cout << "max: " << *max_element(nums.begin(), nums.end()) << '\n';
  cout << "sum: " << accumulate(nums.begin(), nums.end(), 0) << '\n';
}

void demoRemoveAndFilter() {
  printTitle("remove / filter");

  vector<int> nums = {0, 1, 0, 3, 12};
  cout << "original: ";
  printVector(nums);

  auto newEnd = remove(nums.begin(), nums.end(), 0);
  nums.erase(newEnd, nums.end());
  cout << "remove zeros: ";
  printVector(nums);

  vector<int> filtered;
  for (int num : nums) {
    if (num % 2 == 1) {
      filtered.push_back(num);
    }
  }
  cout << "manual filter odd values: ";
  printVector(filtered);
}

void demoTwoDimensionalVector() {
  printTitle("2D vector");

  vector<vector<int>> grid(2, vector<int>(3, 0));
  grid[0][1] = 5;
  grid[1][2] = 9;

  for (size_t row = 0; row < grid.size(); ++row) {
    cout << "row " << row << ": ";
    printVector(grid[row]);
  }
}

void practiceArea() {
  printTitle("practice area");

  // Practice 1: move all zeros to the end without changing vector size.
  // Practice 2: remove duplicates from a sorted vector and return valid length.
  // Practice 3: merge two sorted vectors with two pointers.
  // Practice 4: rotate a vector right by k positions.
  cout << "Edit practiceArea() or add your own functions, then rerun this file.\n";
}

int main() {
  cout << boolalpha;

  // demoConstructionAndAccess();
  // demoCapacityAndModify();
  // demoAlgorithms();
  // demoRemoveAndFilter();
  demoTwoDimensionalVector();
  // practiceArea();

  return 0;
}
