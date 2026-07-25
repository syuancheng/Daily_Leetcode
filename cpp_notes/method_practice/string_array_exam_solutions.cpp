#include <algorithm>
#include <climits>
#include <cstddef>
#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/*
  字符串、数字与数组基础练习题 - C++ 练习模板

  使用方式：
  1. 按照 cpp_notes/method_practice/string_array_exam.md 的题号，从 q01 开始逐个实现。
  2. 每个函数都先保留了返回值占位，保证文件可以编译。
  3. 做完一道题后，可以在 main() 里添加自己的测试代码。
  4. 建议不要一次写完全部题目，按 Markdown 的推荐顺序推进。

  编译：
  clang++ -std=c++17 -Wall -Wextra -Wpedantic -Wconversion \
    cpp_notes/method_practice/string_array_exam_solutions.cpp -o /private/tmp/string_array_exam
*/

// ========== 通用数据结构 ==========

struct CharStats {
  int uppercase = 0;
  int lowercase = 0;
  int digits = 0;
  int spaces = 0;
  int others = 0;
};

// ========== 第一组：字符与字符串基础 ==========

// 1. 判断字符串是否全部由数字组成
bool q01_isAllDigits(const string &s) {
  // TODO: 遍历字符串，判断是否全部是 '0' ~ '9'。
  // 注意：空字符串应该返回 false。
  for (const auto c : s) {
    if (c < '0' || c > '9') {
      return false;
    }
  }

  return true;
}

// 2. 统计不同类型字符的数量
CharStats q02_countCharacterTypes(const string &s) {
  // TODO: 统计大写字母、小写字母、数字、空格、其他字符。
  CharStats res;

  for (const auto c : s) {
    if (c >= 'A' && c <= 'Z') {
      res.uppercase++;
    } else if (c >= 'a' && c <= 'z') {
      res.lowercase++;
    } else if (c >= '0' && c <= '9') {
      res.digits++;
    } else if (c == ' ') {
      res.spaces++;
    } else {
      res.others++;
    }
  }

  return res;
}

// 3. 手动实现字符串转整数
optional<int> q03_stringToIntManual(const string &s) {
  // TODO: 不使用 stoi。非法输入或溢出时返回 nullopt
  // TODO: 先处理空字符串、正负号、非法字符。
  // TODO: 每次累积新 digit 之前，先判断这一步会不会溢出。
  if (s.empty()) {
    return nullopt;
  }

  bool negative = false;
  // REVIEW: 这里用 int 能工作，但会触发 int 和 size_t 比较的 warning；
  // 之后可以考虑把 index 改成和 s.size() 同类型的 size_t。
  int index = 0;
  if (s[0] == '-' || s[0] == '+') {
    negative = s[0] == '-';
    index = 1;
  }

  if (index == s.size()) {
    return nullopt;
  }

  int num = 0;

  for (; index < s.size(); index++) {
    if (s[index] < '0' || s[index] > '9') {
      return nullopt;
    }
    int digit = s[index] - '0';
    if (!negative) {
      if (num > (INT_MAX - digit) / 10) {
        return nullopt;
      }
      num = num * 10 + digit;
    } else {
      if (num < (INT_MIN + digit) / 10) {
        return nullopt;
      }
      num = num * 10 - digit;
    }
  }

  return num;
}

// 4. 手动实现整数转字符串
string q04_intToStringManual(int n) {
  // TODO: 不使用 to_string。注意 0、负数、INT_MIN
  if (n == 0) {
    return "0";
  }

  bool negative = n < 0;
  long long value = n;
  if (negative) {
    value = -value;
  }

  string s;

  while (value > 0) {

    int t = static_cast<int>(value % 10);
    value = value / 10;

    s += static_cast<char>('0' + t);
  }

  if (negative) {
    s += '-';
  }

  reverse(s.begin(), s.end());
  return s;
}

// 5. 反转字符串
string q05_reverseString(string s) {
  if (s.empty()) {
    return s;
  }

  int l = 0, r = s.size() - 1;
  while (l < r) {
    char tmp = s[l];
    s[l] = s[r];
    s[r] = tmp;

    l++;
    r--;
  }

  return s;
}

// 6. 判断回文字符串：基础版本
bool q06_isPalindromeBasic(const string &s) {
  // TODO: 使用双指针，逐个比较左右字符。
  if (s.empty()) {
    return false;
  }
  int l = 0, r = s.size() - 1;
  while (l < r) {
    if (s[l] != s[r]) {
      return false;
    }
    l++;
    r--;
  }

  return true;
}

// 6. 判断回文字符串：进阶版本
bool isAlphaNumeric(char c) {
  return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ||
         (c >= 'A' && c <= 'Z');
}

char toLowerChar(char c) {
  if (c >= 'A' && c <= 'Z') {
    return static_cast<char>('a' + c - 'A');
  }
  return c;
}

char toUpperChar(char c) {
  if (c >= 'a' && c <= 'z') {
    return static_cast<char>('A' + c - 'a');
  }
  return c;
}

bool q06_isPalindromeAdvanced(const string &s) {
  // TODO: 忽略大小写和非字母数字字符。
  // REVIEW: 主逻辑已经对了：跳过非字母数字，再统一大小写比较。
  // 还能再想一下空字符串是否应该算回文；LeetCode 常见定义里空串通常返回 true。
  // 另外 int r = s.size() - 1 会触发 size_t 到 int 的 warning。
  int l = 0, r = s.size() - 1;
  while (l < r) {
    while (l < r && !isAlphaNumeric(s[l])) {
      l++;
    }
    while (l < r && !isAlphaNumeric(s[r])) {
      r--;
    }
    if (toLowerChar(s[l]) != toLowerChar(s[r])) {
      return false;
    }
    l++;
    r--;
  }

  return true;
}

// ========== 第二组：数字操作 ==========

// 7. 反转整数
optional<int> q07_reverseInteger(int n) {
  // TODO: 用 % 10 和 / 10 取出每一位；溢出时返回 nullopt。
  if (n == 0) {
    return 0;
  }

  bool negative = n < 0;
  long long value = n;
  if (negative) {
    value = -value;
  }

  int num = 0;
  while (value > 0) { // 123
    int elem = value % 10;
    value = value / 10;

    if (negative) {
      if (num < (INT_MIN + elem) / 10) {
        return nullopt;
      }
      num = num * 10 - elem;
    } else {
      if (num > (INT_MAX - elem) / 10) {
        return nullopt;
      }
      num = num * 10 + elem;
    }
  }
  return num;
}

// 8. 判断整数是否为回文数：转字符串方案
bool q08_isPalindromeNumberByString(int n) {
  // TODO: 先转成字符串，再使用回文字符串判断。
  if (n < 0) {
    return false;
  }
  if (n == 0) {
    return true;
  }
  string s;
  while (n > 0) { // 123
    int digit = n % 10;
    n /= 10;

    s += static_cast<char>('0' + digit);
  }

  int l = 0, r = s.size() - 1;
  while (l < r) {
    if (s[l] != s[r]) {
      return false;
    }
    l++;
    r--;
  }

  return true;
}

// 8. 判断整数是否为回文数：纯数字方案
bool q08_isPalindromeNumberByDigits(int n) {
  // TODO: 不转字符串，直接操作数字。
  // REVIEW: 现在已经是 O(1) 空间了。可选进阶：只反转数字后一半，
  // 这样不需要处理“完整反转后可能超过 int 范围”的情况。
  if (n < 0) {
    return false;
  } else if (n == 0) {
    return true;
  }

  int num = 0;
  int m = n;

  while (m > 0) {
    int digit = m % 10;
    if (num > (INT_MAX - digit) / 10) {
      return false;
    }

    num = num * 10 + digit;

    m = m / 10;
  }
  return n == num;
}

bool q08_isPalindromeNumberByDigitsV2(int n) {
  if (n < 0) {
    return false;
  }
  if (n == 0) {
    return true;
  }
  if (n % 10 == 0) {
    return false;
  }

  int half = 0;

  while (n > half) {
    int digit = n % 10;
    half = half * 10 + digit;
    n /= 10;
  }

  return n == half || n == half / 10;
}

// 9. 统计一个整数有多少位
int q09_countDigits(int n) {
  // TODO: 注意 0 算 1 位，负数不统计负号。
  if (n == 0) {
    return 1;
  }
  bool negative = n < 0;
  long long value = n;
  if (negative) {
    value = -value;
  }
  int count = 0;

  while (value > 0) { // 123
    value /= 10;
    count++;
  }
  return count;
}

// 10. 计算各位数字之和
int q10_digitSum(int n) {
  // TODO: 负数按绝对值处理。
  if (n == 0) {
    return 0;
  }
  bool negative = n < 0;
  long long value = n;
  if (negative) {
    value = -value;
  }

  int sum = 0;
  while (value > 0) {
    int e = static_cast<int>(value % 10);
    value /= 10;
    sum += e;
  }
  return sum;
}

// 11. 找出整数中的最大数字
int q11_maxDigit(int n) {
  // TODO: 逐位取数字并维护最大值。
  bool negative = n < 0;
  long long value = n;
  if (negative) {
    value = -value;
  }

  int maxDigit = 0;
  while (value > 0) {
    int e = static_cast<int>(value % 10);
    value /= 10;
    maxDigit = e > maxDigit ? e : maxDigit;
  }
  return maxDigit;
}

// 12. 判断一个数是否为 Armstrong 数
bool q12_isArmstrongNumber(int) {
  // TODO: 支持任意位数；负数一般返回 false。
  
  return false;
}

// ========== 第三组：字符串分割与组合 ==========

// 13. 按指定字符分割字符串
vector<string> q13_split(const string &s, char c) {
  // TODO: 保留空字段，例如 "a,,c" -> ["a", "", "c"]。
  vector<string> res;
  size_t start = 0;

  while (true) {
    size_t pos = s.find(c, start);
    if (pos == string::npos) {
      res.push_back(s.substr(start));
      break;
    }
    res.push_back(s.substr(start, pos - start));

    start = pos + 1;
  }

  return res;
}

// 14. 统计字符串中的单词数量
int q14_countWords(const string &s) {
  // TODO: 支持多个连续空格。
  // REVIEW: q13_split 按空格分割后，连续空格产生的是空字符串 ""，不是 " "。
  // REVIEW: 例如 "  hello   world  " 会包含很多空字段；当前计数不会把它们扣掉。
  vector<string> res = q13_split(s, ' ');
  int sz = res.size();
  for (const auto &elem : res) {
    if (elem == " ") {
      sz--;
    }
  }
  return sz;
}

// 15. 反转句子中的单词顺序
string q15_reverseWords(const string &s) {
  // TODO: 进阶版要求删除多余空格。
  // REVIEW: q13_split 后的空字段是 ""，不是 " "；当前过滤条件抓不到多余空格。
  // REVIEW: slow 压缩后没有截断 vector，后面 reverse 的还是完整
  // res，会把旧元素一起反转。 REVIEW: reverse
  // 之后又从末尾往前拼，相当于方向被反了；建议先用简单例子 "I love C++" 手推。
  // REVIEW: 当前结果末尾会多一个空格，进阶版要求删除多余空格。
  vector<string> res = q13_split(s, ' ');
  int slow = 0, fast = 0;
  while (fast < res.size()) {
    if (res[fast] != " ") {
      res[slow] = res[fast];
      slow++;
    }
    fast++;
  }
  reverse(res.begin(), res.end());

  string str;
  for (int i = res.size() - 1; i >= 0; i--) {
    if (res[i] == " ") {
      continue;
    }
    str += res[i];
    str += " ";
  }

  return str;
}

// 16. 字符串压缩
string q16_compressString(const string &) {
  // TODO: 连续区间计数；压缩后不变短则返回原字符串。
  return "";
}

// ========== 第四组：字符串和数字结合 ==========

// 17. 验证 IPv4 地址：判断单段是否合法
bool q17_isValidSegment(const string &s) {
  // TODO: 非空、全数字、范围 0~255、不允许前导零
  int len = s.size();
  if (len == 0 || len > 3) {
    return false;
  }
  if (len > 1 && s[0] == '0') {
    return false;
  }
  int num = 0;
  for (const auto c : s) {
    if (c < '0' || c > '9') {
      return false;
    }
    num = num * 10 + (c - '0');
  }
  // REVIEW: 这里的返回条件写反了；合法范围内的数字应该通过，超出 255 才失败。
  return num < 0 || num > 255;
}

// 17. 验证 IPv4 地址：判断完整 IP
bool q17_isValidIPv4(const string &s) {
  // TODO: 必须正好 4 段，每段都合法。
  vector<string> arr = q13_split(s, '.');

  // REVIEW: 题目要求必须正好 4 段；当前没有检查 arr.size()。
  for (const auto a : arr) {
    if (!q17_isValidSegment(a)) {
      return false;
    }
  }
  return true;
}

// 18. 比较版本号
int q18_compareVersion(const string &, const string &) {
  // TODO: 返回 1 表示第一个更大，-1 表示第二个更大，0 表示相等。
  // 没理解题目

  return 0;
}

// 19. 字符串加法
string q19_addStrings(const string &s, const string t) {
  // TODO: 从后向前遍历，处理进位，不能直接转 long long。
  // REVIEW: 第二个参数建议用 const
  // string&，否则会复制一份字符串；这不是结果错误，但不必要。 REVIEW: while
  // 条件现在是 m >= 0 && n >= 0，长度不同的剩余高位不会处理。 REVIEW:
  // 循环结束后如果 carry 还大于 0，也需要考虑。
  string res;

  int carry = 0;
  int m = s.size() - 1, n = t.size() - 1;
  while (m >= 0 && n >= 0) {
    int a = m < 0 ? 0 : s[m] - '0';
    int b = n < 0 ? 0 : t[n] - '0';
    m--;
    n--;

    int sum = carry;

    sum = sum + a + b;

    char elem = '0' + (sum % 10);
    res += elem;
    carry = sum / 10;
  }

  reverse(res.begin(), res.end());

  return res;
}

// 20. 字符串乘法的简化版：大数字字符串乘以一位数字
string q20_multiplyStringByDigit(const string &s, int n) {
  // TODO: 从后向前遍历，处理进位。
  // REVIEW: 需要先确认 n 是否是一位数字，以及 n == 0 时应该返回什么。

  int l = s.size() - 1;
  string res;
  int carry = 0;
  while (l >= 0) {
    int val = (s[l] - '0') * n;

    // REVIEW: sum 变量没有参与后续计算；当前每一位没有把上一轮 carry 加进去。
    int sum = carry;

    char elem = '0' + val % 10;
    res.push_back(elem);

    carry = val / 10;

    l--;
  }

  // REVIEW: 所有数字处理完以后，如果 carry 还没用完，需要继续处理。
  reverse(res.begin(), res.end());

  return res;
}

// 21. 十进制字符串转二进制
string q21_decimalStringToBinary(const string &) {
  // TODO: 基础版可以先转普通整数；进阶版处理超大数字。
  return "";
}

// 22. 二进制字符串转十进制
optional<int> q22_binaryStringToDecimal(const string &) {
  // TODO: 非法输入或溢出时返回 nullopt。
  return nullopt;
}

// ========== 第五组：数组基础 ==========

// 23. 移动零
void q23_moveZeroes(vector<int> &nums) {
  // TODO: 原地修改，保持非零元素相对顺序。
  // REVIEW: 题目要求把 0 移到末尾，并保持数组长度不变；erase
  // 会直接删除尾部元素。
  int slow = 0, fast = 0;
  while (fast < nums.size()) {
    if (nums[fast] != 0) {
      nums[slow] = nums[fast];
      slow++;
    }
    fast++;
  }

  nums.erase(nums.begin() + slow, nums.end());
}

// 24. 删除有序数组中的重复元素
size_t q24_removeDuplicatesSorted(vector<int> &nums) {
  // TODO: 原地覆盖，返回有效长度。
  // REVIEW: 空数组时 slow = 0、fast = 1 的后续逻辑需要特别小心。
  // REVIEW: 题目要返回有效长度；当前最后固定返回 0。
  // REVIEW: erase
  // 会改短数组；有些刷题接口只要求返回长度，不要求真的删除尾部元素。

  int slow = 0, fast = 1;
  while (fast < nums.size()) {
    if (nums[fast] == nums[slow]) {
      fast++;
      continue;
    }
    nums[++slow] = nums[fast];
    fast++;
  }
  slow++;

  nums.erase(nums.begin() + slow, nums.end());

  return 0;
}

// 25. 合并两个有序数组
vector<int> q25_mergeSortedArrays(const vector<int> &s, const vector<int> &t) {
  // TODO: 双指针合并两个有序数组。
  // REVIEW: 这个实现能得到有序结果，但没有练到题目想要的“双指针同时移动”。
  // REVIEW: 用优先队列会多出额外的 log
  // 复杂度；这题可以利用两个输入本来已经有序。
  auto cmp = [](int a, int b) { return a > b; };
  priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

  for (auto n : s) {
    pq.push(n);
  }

  for (auto n : t) {
    pq.push(n);
  }

  vector<int> res;

  while (!pq.empty()) {
    int v = pq.top();
    pq.pop();
    res.push_back(v);
  }

  return res;
}

// 26. 数组中的第二大元素
optional<int> q26_secondLargest(const vector<int> &nums) {
  // TODO: 第二大元素必须严格小于最大值；不存在时返回 nullopt。
  // REVIEW: nums 为空或只有一个元素时，pq.pop()/pq.top() 会出问题。
  // REVIEW: 第二大必须严格小于最大值；如果输入是 [2, 2]，弹掉一个 2 后 top 仍是
  // 2，不符合题意。 REVIEW: 单独一行 pq.top();
  // 没有任何效果，可以删掉或改成真正需要的逻辑。

  auto cmp = [](int a, int b) { return a < b; };
  priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

  for (auto n : nums) {
    pq.push(n);
  }

  pq.pop();

  pq.top();

  return pq.top();
}

// 27. 数组循环右移：使用额外数组
vector<int> q27_rotateRightExtra(const vector<int> &, size_t) {
  // TODO: 使用一个新数组存放旋转结果。
  return {};
}

// 27. 数组循环右移：三次反转，原地完成
void q27_rotateRightInPlace(vector<int> &, size_t) {
  // TODO: reverse 全部、reverse 前 k 个、reverse 后半部分。
}

// 28. 合并连续区间
vector<pair<int, int>> q28_mergeIntervals(vector<pair<int, int>>) {
  // TODO: 先排序，再维护当前合并后的最后一个区间。
  return {};
}

// ========== 测试区 ==========

void printHeader(const string &title) {
  cout << "\n========== " << title << " ==========\n";
}

int main() {
  cout << boolalpha;

  printHeader("练习模板");
  cout << "这个文件只提供题号对应的函数骨架，不直接给出题解。\n";
  cout << "建议先按 Markdown 的第一阶段顺序实现：1, 3, 7, 13, 17。\n";

  /*
    做完一道题后，可以像下面这样添加测试：

    printHeader("Q01");
    cout << q01_isAllDigits("12345") << '\n';
    cout << q01_isAllDigits("12a45") << '\n';
    cout << q01_isAllDigits("") << '\n';

    printHeader("Q03");
    optional<int> value = q03_stringToIntManual("00123");
    if (value.has_value()) {
      cout << value.value() << '\n';
    } else {
      cout << "转换失败\n";
    }
  */

  return 0;
}
