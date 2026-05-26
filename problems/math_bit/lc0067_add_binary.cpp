#include <algorithm>
#include <cstddef>
#include <iostream>
using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    string ans;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    size_t size_a = a.size();
    size_t size_b = b.size();

    int n = max(size_a, size_b), carry = 0;

    for (size_t i = 0; i < n; ++i) {
      carry += i < size_a ? (a.at(i) == '1') : 0;
      carry += i < size_b ? (b.at(i) == '1') : 0;
      ans.push_back((carry % 2) ? '1' : '0');
      carry/=2;

    }

    cout << carry << endl;
    cout << ans << endl;

    if (carry > 0) {
        ans.push_back('1');
    }

    reverse(ans.begin(), ans.end());

    cout << ans << endl;

    return ans;
  }
};

int main() {

  Solution s;
  s.addBinary("11", "1");

  return 0;
}