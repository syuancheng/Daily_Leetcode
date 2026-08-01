#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void printTitle(const string &title) {
  cout << "\n========== " << title << " ==========\n";
}

void printStringVector(const vector<string> &items) {
  cout << "[";
  for (size_t i = 0; i < items.size(); ++i) {
    if (i > 0) {
      cout << ", ";
    }
    cout << '"' << items[i] << '"';
  }
  cout << "]\n";
}

vector<string> splitByChar(const string &text, char delimiter) {
  vector<string> parts;
  size_t start = 0;

  while (true) {
    // find(ch, start): 从 start 位置开始查找字符，找不到返回 string::npos。
    size_t pos = text.find(delimiter, start);
    if (pos == string::npos) {
      // substr(start): 截取从 start 到字符串末尾的部分。
      parts.push_back(text.substr(start));
      break;
    }

    // substr(start, len): 从 start 开始截取 len 个字符。
    parts.push_back(text.substr(start, pos - start));
    start = pos + 1;
  }

  return parts;
}

string joinWithChar(const vector<string> &parts, char delimiter) {
  string result;
  for (size_t i = 0; i < parts.size(); ++i) {
    if (i > 0) {
      // push_back(ch): 在字符串末尾追加一个字符。
      result.push_back(delimiter);
    }

    // operator+=: 在字符串末尾追加另一个字符串。
    result += parts[i];
  }
  return result;
}

void demoConstructionAndAccess() {
  printTitle("construction / access");

  string b = "hello";
  string c(5, 'x');

  // string(n, ch): 构造由 n 个相同字符组成的字符串。
  cout << "c string(5, 'x'): " << c << '\n';

  // at(index): 按下标访问字符，会做越界检查。
  cout << "b.at(1): " << b.at(1) << '\n';

  // front(): 访问第一个字符，调用前要保证字符串非空。
  cout << "b.front(): " << b.front() << '\n';

  // back(): 访问最后一个字符，调用前要保证字符串非空。
  cout << "b.back(): " << b.back() << '\n';
}

void demoModify() {
  printTitle("modify");

  string s = "abc";

  // push_back(ch): 在末尾追加单个字符。
  s.push_back('d');
  cout << "push_back: " << s << '\n';

  // pop_back(): 删除最后一个字符，调用前要保证字符串非空。
  s.pop_back();
  cout << "pop_back: " << s << '\n';

  // append(text): 在末尾追加一段字符串。
  s.append("ghi");
  cout << "append: " << s << '\n';

  // insert(index, text): 在指定下标前插入字符串。
  s.insert(3, "###");
  cout << "insert ### at index 3: " << s << '\n';

  // erase(index, len): 从 index 开始删除 len 个字符。
  s.erase(3, 3);
  cout << "erase index 3 length 3: " << s << '\n';

  // replace(index, len, text): 用 text 替换从 index 开始的 len 个字符。
  s.replace(0, 3, "ABC");
  cout << "replace first 3 chars: " << s << '\n';

  // reverse(begin, end): 反转字符串区间内的字符。
  reverse(s.begin(), s.end());
  cout << "reverse: " << s << '\n';

  // clear(): 清空字符串内容。
  s.clear();
  cout << "clear, empty: " << s.empty() << '\n';
}

void demoFindAndSubstr() {
  printTitle("find / substr / compare");

  string s = "one two two three";
  cout << "s: " << s << '\n';

  // substr(pos, len): 从 pos 开始截取 len 个字符。
  cout << "s.substr(4, 3): " << s.substr(4, 3) << '\n';

  // substr(pos): 从 pos 开始一直截取到字符串末尾。
  cout << "s.substr(8): " << s.substr(8) << '\n';

  // find(text): 查找子串第一次出现的位置。
  size_t firstTwo = s.find("two");

  // rfind(text): 从右往左查找子串最后一次出现的位置。
  size_t lastTwo = s.rfind("two");
  cout << "find(\"two\"): " << firstTwo << '\n';
  cout << "rfind(\"two\"): " << lastTwo << '\n';

  // string::npos: find / rfind 找不到时返回的特殊值。
  cout << "find(\"missing\") == npos: " << (s.find("missing") == string::npos) << '\n';

  // == 和 < 会按字典序比较字符串。
  cout << "\"abc\" == \"abc\": " << (string("abc") == string("abc")) << '\n';
  cout << "\"abc\" < \"abd\": " << (string("abc") < string("abd")) << '\n';

  // compare(other): 相等返回 0，小于返回负数，大于返回正数。
  cout << "compare: " << string("abc").compare("abd") << '\n';
}

void demoConversionAndChars() {
  printTitle("conversion / char helpers");

  // stoi(text): 把字符串转换成 int。
  int number = stoi("12345");

  // stoll(text): 把字符串转换成 long long。
  long long big = stoll("9876543210");

  // to_string(value): 把数字转换成字符串。
  string text = to_string(2026);

  cout << "stoi(\"12345\"): " << number << '\n';
  cout << "stoll(\"9876543210\"): " << big << '\n';
  cout << "to_string(2026): " << text << '\n';

  string s = "A1 b!";
  int letters = 0;
  int digits = 0;
  int spaces = 0;
  string lowered;

  for (char raw : s) {
    // cctype 函数建议先转成 unsigned char，避免负 char 带来的未定义行为。
    unsigned char ch = static_cast<unsigned char>(raw);

    // isalpha(ch): 判断是否是字母。
    if (isalpha(ch)) {
      ++letters;
    }

    // isdigit(ch): 判断是否是数字字符。
    if (isdigit(ch)) {
      ++digits;
    }

    // isspace(ch): 判断是否是空白字符，例如空格、换行、tab。
    if (isspace(ch)) {
      ++spaces;
    }

    // tolower(ch): 把字母转成小写；非字母通常保持不变。
    lowered.push_back(static_cast<char>(tolower(ch)));
  }

  cout << "letters: " << letters << ", digits: " << digits
       << ", spaces: " << spaces << '\n';
  cout << "tolower each char: " << lowered << '\n';
}

void demoSplitJoinAndStream() {
  printTitle("split / join / stringstream");

  // 自定义 split: 适合按指定分隔符拆分，并且这里会保留空字段。
  vector<string> parts = splitByChar("apple,banana,,orange", ',');
  cout << "split keeps empty fields: ";
  printStringVector(parts);

  // 自定义 join: 把多个字符串用指定分隔符拼回一个字符串。
  cout << "join with '|': " << joinWithChar(parts, '|') << '\n';

  string sentence = "hello   cpp world";

  // stringstream: 适合按空白字符拆分单词，也常用于格式转换。
  stringstream ss(sentence);
  string word;
  vector<string> words;

  // ss >> word: 每次读取一个被空白分隔的单词。
  while (ss >> word) {
    words.push_back(word);
  }

  cout << "stringstream words: ";
  printStringVector(words);
}

void practiceArea() {
  printTitle("practice area");

  // Practice 1: implement a function that returns true if text contains only digits.
  // Practice 2: count words in a string with multiple spaces.
  // Practice 3: reverse word order in "I love C++".
  // Practice 4: replace every space in a string with "%20".
  cout << "Edit practiceArea() or add your own functions, then rerun this file.\n";
}

int main() {
  cout << boolalpha;

  // demoConstructionAndAccess();
  // demoModify();
  // demoFindAndSubstr();
  // demoConversionAndChars();
  // demoSplitJoinAndStream();
  practiceArea();

  return 0;
}
