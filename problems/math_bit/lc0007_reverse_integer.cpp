#include <climits>
#include <iostream>

int reverse(int x) {
  long ans = 0;
  long y = x;

  int d, flag;
  flag = (x < 0 ? -1 : 1);

  if (x < 0) {
    y = -y;
  }
  // 321
  while (y != 0) {
    d = y % 10;
    y = y / 10;

    ans = ans * 10 + d;
  }
  ans = flag * ans;

  if (ans < INT_MIN || ans > INT_MAX) {
    return 0;
  }
  return ans;
}

int main() {
  int ret = reverse(312);

  std::cout << "result: " << ret << std::endl;

  return 0;
}