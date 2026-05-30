#include <climits>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <string>

double myAtof(const std::string &s) {
  if (s.empty()) {
    return 0.0;
  }

  int dotIdx = INT_MAX;

  double result = 0.0, factor = 0.1;

  for (int i = 0; i < s.size(); ++i) {
    char n = s[i];
    if (n == '.') {
      dotIdx = i;
      continue;
    }

    if (i < dotIdx) {
      result = result * 10 + (n - '0');
    } else {
      result = result + (n - '0') * factor;
      factor *= 0.1;
    }
  }
  return result;
}

int main() {

  std::string s = "3.14001312";
  double res = myAtof(s);

  
  std::cout << std::setprecision(10) << res << std::endl;
}
