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

  cout << "min(3, 7): " << min(3, 7) << '\n';
  cout << "max(3, 7): " << max(3, 7) << '\n';
  cout << "min initializer_list: " << min({9, 3, 7, 1}) << '\n';
  cout << "max initializer_list: " << max({9, 3, 7, 1}) << '\n';
  cout << "abs(-42): " << abs(-42) << '\n';
  cout << "llabs(-9000000000LL): " << llabs(-9000000000LL) << '\n';
  cout << "clamp(15, 0, 10): " << clamp(15, 0, 10) << '\n';
}

void demoPowerAndRoots() {
  printTitle("pow / sqrt / round");

  cout << "pow(2, 10): " << pow(2.0, 10.0) << '\n';
  cout << "sqrt(49): " << sqrt(49.0) << '\n';
  cout << "floor(3.8): " << floor(3.8) << '\n';
  cout << "ceil(3.2): " << ceil(3.2) << '\n';
  cout << "round(3.5): " << round(3.5) << '\n';
  cout << "trunc(-3.8): " << trunc(-3.8) << '\n';
}

void demoGcdLcmModulo() {
  printTitle("gcd / lcm / modulo");

  cout << "gcd(24, 36): " << gcd(24, 36) << '\n';
  cout << "lcm(6, 8): " << lcm(6, 8) << '\n';
  cout << "17 % 5: " << 17 % 5 << '\n';
  cout << "-17 % 5: " << -17 % 5 << "  // C++ remainder keeps dividend sign\n";

  int a = -17;
  int m = 5;
  int normalized = (a % m + m) % m;
  cout << "normalized modulo for -17 mod 5: " << normalized << '\n';
}

void demoNumericAlgorithms() {
  printTitle("numeric algorithms");

  vector<int> nums = {1, 2, 3, 4, 5};
  cout << "nums: ";
  printVector(nums);

  cout << "accumulate sum: " << accumulate(nums.begin(), nums.end(), 0) << '\n';
  cout << "accumulate product: "
       << accumulate(nums.begin(), nums.end(), 1, multiplies<int>()) << '\n';

  vector<int> prefix(nums.size());
  partial_sum(nums.begin(), nums.end(), prefix.begin());
  cout << "partial_sum prefix: ";
  printVector(prefix);

  vector<int> adjacent(nums.size());
  adjacent_difference(nums.begin(), nums.end(), adjacent.begin());
  cout << "adjacent_difference: ";
  printVector(adjacent);

  cout << "inner_product(nums, nums): "
       << inner_product(nums.begin(), nums.end(), nums.begin(), 0) << '\n';
}

void demoLimitsAndPrecision() {
  printTitle("limits / precision");

  cout << "int min: " << numeric_limits<int>::min() << '\n';
  cout << "int max: " << numeric_limits<int>::max() << '\n';
  cout << "long long max: " << numeric_limits<long long>::max() << '\n';

  double x = 0.1 + 0.2;
  double y = 0.3;
  double eps = 1e-9;
  cout << "0.1 + 0.2 == 0.3: " << boolalpha << (x == y) << '\n';
  cout << "fabs(x - y) < eps: " << (fabs(x - y) < eps) << '\n';
}

void demoRandom() {
  printTitle("random");

  mt19937 rng(12345);
  uniform_int_distribution<int> dice(1, 6);

  cout << "fixed-seed dice rolls: ";
  for (int i = 0; i < 5; ++i) {
    cout << dice(rng) << " ";
  }
  cout << '\n';
}

void practiceArea() {
  printTitle("practice area");

  // Practice 1: write an integer power function without using pow.
  // Practice 2: check whether a number is prime.
  // Practice 3: compute digit sum of a possibly negative int.
  // Practice 4: build prefix sums and answer range-sum queries.
  cout << "Edit practiceArea() or add your own functions, then rerun this file.\n";
}

int main() {
  cout << boolalpha;

  demoMinMaxAbs();
  demoPowerAndRoots();
  demoGcdLcmModulo();
  demoNumericAlgorithms();
  demoLimitsAndPrecision();
  demoRandom();
  practiceArea();

  return 0;
}
