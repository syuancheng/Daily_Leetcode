#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>

int main() {
  // 整数
  std::string s = "123";
  int num = 0;
  for (char c : s) {
    num = num * 10 + (c - '0');
  }
  std::cout << num << std::endl;

  // 小数
  std::string s1 = "3.14";
  double num1 = 0.0;
  int dotIdx = INT_MAX;
  double factor = 0.1;
  for (int i = 0; i < s1.size(); ++i) {
    char c = s1[i];
    if (c == '.') {
      dotIdx = i;
      continue;
    }

    if (i < dotIdx) {
      num1 = num1 * 10 + (c - '0');
    } else if (i > dotIdx) {
      num1 = num1 + (c - '0') * factor;
      factor *= 0.1;
    }
  }
  std::cout << num1 << std::endl;

  // 整数转string
  int n1 = 31415;
  std::string s2 = "";
  while (n1 > 0) {
    s2 += (char)('0' + n1 % 10);
    n1 /= 10;
  }
  std::reverse(s2.begin(), s2.end());
  std::cout << s2 << std::endl;

  return 0;
}