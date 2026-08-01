#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void printTitle(const string &title) {
  cout << "\n========== " << title << " ==========\n";
}

void printMap(const unordered_map<string, int> &items) {
  cout << "{";
  bool first = true;
  for (const auto &[key, value] : items) {
    if (!first) {
      cout << ", ";
    }
    first = false;
    cout << key << ": " << value;
  }
  cout << "}\n";
}

void printCharMap(const unordered_map<char, int> &items) {
  cout << "{";
  bool first = true;
  for (const auto &[key, value] : items) {
    if (!first) {
      cout << ", ";
    }
    first = false;
    cout << key << ": " << value;
  }
  cout << "}\n";
}

void demoConstructionAndBasicInfo() {
  printTitle("construction / basic info");

  unordered_map<string, int> scores;
  unordered_map<string, int> initialScores = {{"alice", 90}, {"bob", 85}};

  // empty(): 判断哈希表是否为空。
  cout << "scores.empty(): " << scores.empty() << '\n';

  // size(): 返回 key/value 对的数量。
  cout << "initialScores.size(): " << initialScores.size() << '\n';

  // unordered_map 不按 key 排序，遍历顺序不固定。
  cout << "initialScores: ";
  printMap(initialScores);
}

void demoInsertAccessAndUpdate() {
  printTitle("insert / access / update");

  unordered_map<string, int> scores;

  // operator[]: 读取或写入 value；如果 key 不存在，会自动创建默认值。
  scores["alice"] = 90;
  scores["bob"] = 85;

  // insert({key, value}): key 不存在才插入；key 已存在时不会覆盖旧值。
  scores.insert({"alice", 100});
  scores.insert({"cindy", 92});

  // emplace(key, value): 原地构造 key/value；适合避免不必要的临时对象。
  scores.emplace("david", 88);

  cout << "after insert / emplace: ";
  printMap(scores);

  // at(key): 读取已存在的 key；key 不存在会抛异常，适合明确要求存在的场景。
  cout << "scores.at(\"alice\"): " << scores.at("alice") << '\n';

  // operator[] 也常用于更新 value。
  scores["bob"] = 89;
  cout << "after update bob: ";
  printMap(scores);
}

void demoFindCountAndErase() {
  printTitle("find / count / erase");

  unordered_map<string, int> scores = {{"alice", 90}, {"bob", 85}, {"cindy", 92}};

  // find(key): 查找 key，存在时返回迭代器，不存在时返回 end()。
  auto it = scores.find("bob");
  if (it != scores.end()) {
    cout << "find bob: " << it->second << '\n';
  }

  // count(key): 对 unordered_map 来说只会返回 0 或 1，常用于判断 key 是否存在。
  cout << "count eric: " << scores.count("eric") << '\n';

  // erase(key): 按 key 删除；返回实际删除的数量。
  cout << "erase alice removed: " << scores.erase("alice") << '\n';
  cout << "after erase: ";
  printMap(scores);

  // clear(): 清空所有 key/value。
  scores.clear();
  cout << "after clear, empty: " << scores.empty() << '\n';
}

void demoOperatorBracketTrap() {
  printTitle("operator[] creates missing keys");

  unordered_map<string, int> counter;
  cout << "initial size: " << counter.size() << '\n';

  // 注意：operator[] 查询不存在的 key 时，会把这个 key 插入并给 value 默认值 0。
  cout << "counter[\"missing\"]: " << counter["missing"] << '\n';
  cout << "size after operator[]: " << counter.size() << '\n';

  unordered_map<string, int> safer;
  // 只想判断是否存在时，用 find 或 count，不要用 operator[]。
  cout << "safer.find(\"missing\") exists: "
       << (safer.find("missing") != safer.end()) << '\n';
  cout << "size after find: " << safer.size() << '\n';
}

void demoFrequencyCount() {
  printTitle("frequency count");

  string text = "banana";
  unordered_map<char, int> freq;

  for (char ch : text) {
    // ++freq[ch]: 不存在的字符先默认插入为 0，再加 1。
    ++freq[ch];
  }

  cout << "frequency of banana: ";
  printCharMap(freq);
}

void demoCommonLeetCodeUsage() {
  printTitle("common LeetCode usage");

  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  unordered_map<int, size_t> indexByValue;

  for (size_t i = 0; i < nums.size(); ++i) {
    int need = target - nums[i];

    // 用 find 查 complement 是否已经出现过。
    auto it = indexByValue.find(need);
    if (it != indexByValue.end()) {
      cout << "two sum indices: " << it->second << ", " << i << '\n';
      break;
    }

    // value -> index 是两数之和里最常见的哈希表写法。
    indexByValue[nums[i]] = i;
  }
}

void demoReserveForHashTable() {
  printTitle("reserve / load factor");

  unordered_map<string, int> table;

  // reserve(n): 提前准备哈希桶，key 很多时可以减少扩容次数。
  table.reserve(100);

  // max_load_factor(): 查看或设置装载因子，影响哈希表扩容时机。
  cout << "max_load_factor: " << table.max_load_factor() << '\n';
  cout << "bucket_count after reserve(100): " << table.bucket_count() << '\n';
}

void practiceArea() {
  printTitle("practice area");

  // Practice 1: 统计字符串中每个字符出现的次数。
  // Practice 2: 找出数组中出现次数超过 1 的数字。
  // Practice 3: 用 unordered_map 实现 two sum。
  // Practice 4: 按单词长度统计 vector<string> 里有多少个单词。
  cout << "Edit practiceArea() or add your own functions, then rerun this file.\n";
}

int main() {
  cout << boolalpha;

  demoConstructionAndBasicInfo();
  demoInsertAccessAndUpdate();
  demoFindCountAndErase();
  demoOperatorBracketTrap();
  demoFrequencyCount();
  demoCommonLeetCodeUsage();
  demoReserveForHashTable();
  // practiceArea();

  return 0;
}
