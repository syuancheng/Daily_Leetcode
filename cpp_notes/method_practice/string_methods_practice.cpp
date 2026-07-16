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
    size_t pos = text.find(delimiter, start);
    if (pos == string::npos) {
      parts.push_back(text.substr(start));
      break;
    }
    parts.push_back(text.substr(start, pos - start));
    start = pos + 1;
  }

  return parts;
}

string joinWithChar(const vector<string> &parts, char delimiter) {
  string result;
  for (size_t i = 0; i < parts.size(); ++i) {
    if (i > 0) {
      result.push_back(delimiter);
    }
    result += parts[i];
  }
  return result;
}

void demoConstructionAndAccess() {
  printTitle("construction / access");

  string b = "hello";
  string c(5, 'x');

  cout << "c string(5, 'x'): " << c << '\n';
  cout << "b.at(1): " << b.at(1) << '\n';
  cout << "b.front(): " << b.front() << '\n';
  cout << "b.back(): " << b.back() << '\n';
}

void demoModify() {
  printTitle("modify");

  string s = "abc";
  s.push_back('d');
  cout << "push_back: " << s << '\n';

  s.pop_back();
  cout << "pop_back: " << s << '\n';

  s.append("ghi");
  cout << "append: " << s << '\n';

  s.insert(3, "###");
  cout << "insert ### at index 3: " << s << '\n';

  s.erase(3, 3);
  cout << "erase index 3 length 3: " << s << '\n';

  s.replace(0, 3, "ABC");
  cout << "replace first 3 chars: " << s << '\n';

  reverse(s.begin(), s.end());
  cout << "reverse: " << s << '\n';

  s.clear();
  cout << "clear, empty: " << s.empty() << '\n';
}

void demoFindAndSubstr() {
  printTitle("find / substr / compare");

  string s = "one two two three";
  cout << "s: " << s << '\n';
  cout << "s.substr(4, 3): " << s.substr(4, 3) << '\n';
  cout << "s.substr(8): " << s.substr(8) << '\n';

  size_t firstTwo = s.find("two");
  size_t lastTwo = s.rfind("two");
  cout << "find(\"two\"): " << firstTwo << '\n';
  cout << "rfind(\"two\"): " << lastTwo << '\n';
  cout << "find(\"missing\") == npos: " << (s.find("missing") == string::npos) << '\n';

  cout << "\"abc\" == \"abc\": " << (string("abc") == string("abc")) << '\n';
  cout << "\"abc\" < \"abd\": " << (string("abc") < string("abd")) << '\n';
  cout << "compare: " << string("abc").compare("abd") << '\n';
}

void demoConversionAndChars() {
  printTitle("conversion / char helpers");

  int number = stoi("12345");
  long long big = stoll("9876543210");
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
    unsigned char ch = static_cast<unsigned char>(raw);
    if (isalpha(ch)) {
      ++letters;
    }
    if (isdigit(ch)) {
      ++digits;
    }
    if (isspace(ch)) {
      ++spaces;
    }
    lowered.push_back(static_cast<char>(tolower(ch)));
  }

  cout << "letters: " << letters << ", digits: " << digits
       << ", spaces: " << spaces << '\n';
  cout << "tolower each char: " << lowered << '\n';
}

void demoSplitJoinAndStream() {
  printTitle("split / join / stringstream");

  vector<string> parts = splitByChar("apple,banana,,orange", ',');
  cout << "split keeps empty fields: ";
  printStringVector(parts);

  cout << "join with '|': " << joinWithChar(parts, '|') << '\n';

  string sentence = "hello   cpp world";
  stringstream ss(sentence);
  string word;
  vector<string> words;
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
