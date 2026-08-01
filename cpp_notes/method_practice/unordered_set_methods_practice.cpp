#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

void printTitle(const string &title) {
  cout << "\n========== " << title << " ==========\n";
}

void printSet(const unordered_set<int> &items) {
  cout << "{";
  bool first = true;
  for (int item : items) {
    if (!first) {
      cout << ", ";
    }
    first = false;
    cout << item;
  }
  cout << "}\n";
}

void demoConstructionAndBasicInfo() {
  printTitle("construction / basic info");

  unordered_set<int> emptySet;
  unordered_set<int> nums = {3, 1, 4, 1, 5};

  // empty(): 判断集合是否为空，常用于循环或边界判断。
  cout << "emptySet.empty(): " << emptySet.empty() << '\n';

  // size(): 返回集合里不重复元素的数量。
  cout << "nums.size(): " << nums.size() << '\n';

  // unordered_set 自动去重，但不保证遍历顺序。
  cout << "nums after duplicate 1 removed: ";
  printSet(nums);
}

void demoInsertFindAndCount() {
  printTitle("insert / find / count");

  unordered_set<int> seen;

  // insert(value): 插入元素；如果元素已存在，不会重复插入。
  seen.insert(10);
  seen.insert(20);
  seen.insert(10);

  // emplace(value): 原地构造并插入元素；对简单 int 来说效果接近 insert。
  seen.emplace(30);
  cout << "after insert / emplace: ";
  printSet(seen);

  // find(value): 查找元素，存在时返回迭代器，不存在时返回 end()。
  cout << "find 20 exists: " << (seen.find(20) != seen.end()) << '\n';

  // count(value): 对 set 来说只会返回 0 或 1，常用于判断是否存在。
  cout << "count 99: " << seen.count(99) << '\n';
}

void demoEraseAndClear() {
  printTitle("erase / clear");

  unordered_set<int> nums = {1, 2, 3, 4};
  cout << "original: ";
  printSet(nums);

  // erase(value): 按值删除元素；返回实际删除的元素个数。
  cout << "erase(2) removed: " << nums.erase(2) << '\n';
  cout << "after erase value: ";
  printSet(nums);

  // erase(iterator): 已经 find 到元素时，可以直接按迭代器删除。
  auto it = nums.find(3);
  if (it != nums.end()) {
    nums.erase(it);
  }
  cout << "after erase iterator: ";
  printSet(nums);

  // clear(): 清空所有元素。
  nums.clear();
  cout << "after clear, empty: " << nums.empty() << '\n';
}

void demoReserveForHashTable() {
  printTitle("reserve / load factor");

  unordered_set<int> nums;

  // reserve(n): 提前准备哈希桶，元素很多时可以减少扩容次数。
  nums.reserve(100);

  // max_load_factor(): 查看或设置装载因子，影响哈希表扩容时机。
  cout << "max_load_factor: " << nums.max_load_factor() << '\n';
  cout << "bucket_count after reserve(100): " << nums.bucket_count() << '\n';
}

void demoCommonLeetCodeUsage() {
  printTitle("common LeetCode usage");

  vector<int> nums = {4, 1, 2, 1, 2};
  unordered_set<int> seen;

  for (int num : nums) {
    // 如果之前见过 num，find 会找到它；否则插入到 seen。
    if (seen.find(num) != seen.end()) {
      cout << "duplicate found: " << num << '\n';
    } else {
      seen.insert(num);
    }
  }

  unordered_set<int> a = {1, 2, 3, 4};
  vector<int> b = {3, 4, 4, 5};
  unordered_set<int> intersection;

  for (int num : b) {
    // 用 count 判断另一个集合是否包含当前元素。
    if (a.count(num) > 0) {
      intersection.insert(num);
    }
  }

  cout << "intersection: ";
  printSet(intersection);
}

void practiceArea() {
  printTitle("practice area");

  // Practice 1: 判断 vector<int> 里是否存在重复元素。
  // Practice 2: 求两个数组的去重交集。
  // Practice 3: 判断字符串里每个字符是否都只出现一次。
  // Practice 4: 找出第一个不在 banned 集合里的数字。
  cout << "Edit practiceArea() or add your own functions, then rerun this file.\n";
}

int main() {
  cout << boolalpha;

  demoConstructionAndBasicInfo();
  demoInsertFindAndCount();
  demoEraseAndClear();
  demoReserveForHashTable();
  demoCommonLeetCodeUsage();
  // practiceArea();

  return 0;
}
