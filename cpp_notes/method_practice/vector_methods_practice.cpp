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

  // empty(): 判断 vector 是否没有元素，常用于边界判断。
  cout << "a.empty(): " << boolalpha << a.empty() << '\n';
  cout << "b: ";
  printVector(b);
  cout << "c vector<int>(5, 9): ";
  printVector(c);

  // size(): 返回当前元素个数。
  cout << "b.size(): " << b.size() << '\n';

  // operator[]: 按下标访问元素，不做越界检查，LeetCode 中很常用。
  cout << "b[1]: " << b[1] << '\n';

  // at(index): 按下标访问元素，会做越界检查，越界时抛异常。
  cout << "b.at(1): " << b.at(1) << '\n';

  // front(): 访问第一个元素，调用前要保证 vector 非空。
  cout << "b.front(): " << b.front() << '\n';

  // back(): 访问最后一个元素，调用前要保证 vector 非空。
  cout << "b.back(): " << b.back() << '\n';
}

void demoCapacityAndModify() {
  printTitle("capacity / modify");

  vector<int> nums;

  // reserve(n): 预留容量，不改变 size，适合提前知道大概元素数量时减少扩容。
  nums.reserve(10);
  cout << "after reserve(10), capacity: " << nums.capacity() << '\n';

  // push_back(value): 在末尾添加一个已有值。
  nums.push_back(1);
  nums.push_back(2);

  // emplace_back(args...): 在末尾原地构造元素，复杂对象时可减少临时对象。
  nums.emplace_back(3);
  cout << "push_back / emplace_back: ";
  printVector(nums);

  // insert(pos, value): 在指定迭代器位置前插入元素，后面的元素会整体后移。
  nums.insert(nums.begin() + 1, 99);
  cout << "insert 99 at index 1: ";
  printVector(nums);

  // erase(pos): 删除指定迭代器位置的元素，后面的元素会整体前移。
  nums.erase(nums.begin() + 1);
  cout << "erase index 1: ";
  printVector(nums);

  // pop_back(): 删除最后一个元素，调用前要保证 vector 非空。
  nums.pop_back();
  cout << "pop_back: ";
  printVector(nums);

  // resize(n, value): 改变 size；变大时新元素用 value 填充。
  nums.resize(5, 7);
  cout << "resize(5, 7): ";
  printVector(nums);

  // clear(): 清空所有元素，但通常不会释放已经申请的 capacity。
  nums.clear();
  cout << "clear, size: " << nums.size() << ", capacity still: " << nums.capacity()
       << '\n';
}

void demoAlgorithms() {
  printTitle("algorithms");

  vector<int> nums = {5, 1, 4, 2, 2, 3};
  cout << "original: ";
  printVector(nums);

  // sort(begin, end): 对区间排序，默认从小到大。
  sort(nums.begin(), nums.end());
  cout << "sort: ";
  printVector(nums);

  // reverse(begin, end): 反转区间内元素顺序。
  reverse(nums.begin(), nums.end());
  cout << "reverse: ";
  printVector(nums);

  sort(nums.begin(), nums.end());

  // unique(begin, end): 把相邻重复元素移到后面，返回去重后逻辑结尾。
  auto newEnd = unique(nums.begin(), nums.end());

  // erase(newEnd, end): 真正删除 unique 后面残留的重复元素。
  nums.erase(newEnd, nums.end());
  cout << "sort + unique + erase: ";
  printVector(nums);

  // lower_bound(begin, end, target): 有序区间里第一个 >= target 的位置。
  // upper_bound(begin, end, target): 有序区间里第一个 > target 的位置。
  auto it = lower_bound(nums.begin(), nums.end(), 3);

  // distance(begin, it): 计算两个迭代器之间的距离，常用来得到下标。
  cout << "lower_bound 3 index: " << distance(nums.begin(), it) << '\n';

  // count(begin, end, value): 统计 value 在区间里出现的次数。
  cout << "count 2: " << count(nums.begin(), nums.end(), 2) << '\n';

  // find(begin, end, value): 查找 value，没找到会返回 end()。
  cout << "find 4 exists: " << (find(nums.begin(), nums.end(), 4) != nums.end())
       << '\n';

  // min_element / max_element: 返回最小值或最大值所在位置的迭代器。
  cout << "min: " << *min_element(nums.begin(), nums.end()) << '\n';
  cout << "max: " << *max_element(nums.begin(), nums.end()) << '\n';

  // accumulate(begin, end, init): 从 init 开始累加区间内所有元素。
  cout << "sum: " << accumulate(nums.begin(), nums.end(), 0) << '\n';
}

void demoRemoveAndFilter() {
  printTitle("remove / filter");

  vector<int> nums = {0, 1, 0, 3, 12};
  cout << "original: ";
  printVector(nums);

  // remove(begin, end, value): 把不等于 value 的元素前移，返回新的逻辑结尾。
  auto newEnd = remove(nums.begin(), nums.end(), 0);

  // remove 不会真的缩短 vector，所以通常要接 erase 删除尾部无效区间。
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

  // vector<vector<int>>(rows, vector<int>(cols, value)): 创建二维数组。
  vector<vector<int>> grid(2, vector<int>(3, 0));

  // grid[row][col]: 按行列访问二维 vector。
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
