#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <random>
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

void demoMinMaxAbs() {
  printTitle("min / max / abs / clamp");

  cout << "min(3, 7): " << min(3, 7) << '\n'; // 取两个数中的较小值。
  cout << "max(3, 7): " << max(3, 7) << '\n'; // 取两个数中的较大值。
  cout << "min initializer_list: " << min({9, 3, 7, 1})
       << '\n'; // 取一组数中的最小值。
  cout << "max initializer_list: " << max({9, 3, 7, 1})
       << '\n';                             // 取一组数中的最大值。
  cout << "abs(-42): " << abs(-42) << '\n'; // int 绝对值。
  cout << "llabs(-9000000000LL): " << llabs(-9000000000LL)
       << '\n'; // long long 绝对值。
  cout << "clamp(15, 0, 10): " << clamp(15, 0, 10)
       << '\n'; // 把值限制在闭区间 [0, 10] 内。
}

void demoPowerAndRoots() {
  printTitle("pow / sqrt / round");

  cout << "pow(2, 10): " << pow(2.0, 10.0) << '\n'; // 幂运算：2 的 10 次方。
  cout << "sqrt(49): " << sqrt(49.0) << '\n';       // 平方根。
  cout << "floor(3.8): " << floor(3.8) << '\n';     // 向下取整。
  cout << "ceil(3.2): " << ceil(3.2) << '\n';       // 向上取整。
  cout << "round(3.5): " << round(3.5) << '\n';     // 四舍五入到最近整数。
  cout << "trunc(-3.8): " << trunc(-3.8) << '\n';   // 去掉小数部分，向 0 靠近。
}

void demoGcdLcmModulo() {
  printTitle("gcd / lcm / modulo");

  cout << "gcd(24, 36): " << gcd(24, 36) << '\n'; // 最大公约数。
  cout << "lcm(6, 8): " << lcm(6, 8) << '\n';     // 最小公倍数。
  cout << "17 % 5: " << 17 % 5 << '\n';           // 取余数。
  cout << "-17 % 5: " << -17 % 5 << "  // C++ 余数符号跟被除数一致\n";

  int a = -17;
  int m = 5;
  // 标准化取模：把负余数转成 [0, m - 1] 范围内的非负余数。
  int normalized = (a % m + m) % m;
  cout << "normalized modulo for -17 mod 5: " << normalized << '\n';
}

void demoNumericAlgorithms() {
  printTitle("numeric algorithms");

  vector<int> nums = {1, 2, 3, 4, 5};
  cout << "nums: ";
  printVector(nums);

  // 累加求和：1 + 2 + 3 + 4 + 5。
  cout << "accumulate sum: " << accumulate(nums.begin(), nums.end(), 0) << '\n';

  // 累乘求积：1 * 2 * 3 * 4 * 5。
  cout << "accumulate product: "
       << accumulate(nums.begin(), nums.end(), 1, multiplies<int>()) << '\n';

  // 前缀和：prefix[i] = nums[0] + ... + nums[i]。
  vector<int> prefix(nums.size());
  partial_sum(nums.begin(), nums.end(), prefix.begin());
  cout << "partial_sum prefix: ";
  printVector(prefix);

  // 相邻差：第一个值不变，后面是 nums[i] - nums[i - 1]。
  vector<int> adjacent(nums.size());
  adjacent_difference(nums.begin(), nums.end(), adjacent.begin());
  cout << "adjacent_difference: ";
  printVector(adjacent);

  // 内积：nums[0]^2 + nums[1]^2 + ... + nums[n - 1]^2。
  cout << "inner_product(nums, nums): "
       << inner_product(nums.begin(), nums.end(), nums.begin(), 0) << '\n';
}

void demoLimitsAndPrecision() {
  printTitle("limits / precision");

  cout << "int min: " << numeric_limits<int>::min() << '\n'; // int 最小值。
  cout << "int max: " << numeric_limits<int>::max() << '\n'; // int 最大值。
  cout << "long long max: " << numeric_limits<long long>::max() << '\n';

  double x = 0.1 + 0.2;
  double y = 0.3;
  double eps = 1e-9;
  // 浮点数有精度误差，不能总是直接用 == 比较。
  cout << "0.1 + 0.2 == 0.3: " << boolalpha << (x == y) << '\n';

  // 常用做法：判断两个浮点数的差的绝对值是否小于一个很小的 eps。
  cout << "fabs(x - y) < eps: " << (fabs(x - y) < eps) << '\n';
}

void demoRandom() {
  printTitle("random");

  // 伪随机数引擎；固定种子 12345 会让每次运行得到同一串随机数，方便调试。
  mt19937 rng(12345);

  // 均匀整数分布：每次生成 1 到 6 之间的整数，模拟骰子。
  uniform_int_distribution<int> dice(1, 6);

  cout << "fixed-seed dice rolls: ";
  for (int i = 0; i < 5; ++i) {
    cout << dice(rng) << " ";
  }
  cout << '\n';
}

void practiceArea() {
  printTitle("practice area");

  // 练习 1：不使用 pow，自己实现整数快速幂或普通幂运算。
  // 练习 2：判断一个数是否为质数。
  // 练习 3：计算一个可能为负数的 int 的各位数字之和。
  // 练习 4：构造前缀和数组，并回答区间和查询。
  cout << "Edit practiceArea() or add your own functions, then rerun this "
          "file.\n";
}

int main() {
  cout << boolalpha;

  // demoMinMaxAbs();

  // demoPowerAndRoots();

  // demoGcdLcmModulo();

  // demoNumericAlgorithms();
  demoLimitsAndPrecision();
  // demoRandom();
  // practiceArea();

  return 0;
}
