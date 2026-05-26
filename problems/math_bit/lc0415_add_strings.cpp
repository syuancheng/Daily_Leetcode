#include <string>
#include <vector>

using namespace std;

/**
415. 字符串相加
示例 1：

输入：num1 = "11", num2 = "123"
输出："134"
示例 2：

输入：num1 = "456", num2 = "77"
输出："533"
示例 3：

输入：num1 = "0", num2 = "0"
输出："0"
*/

class Solution {
public:
  string addStrings(string num1, string num2) {
    string ans = "";
    int carry = 0;

    for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0;
         i--, j--) {

      int n1 = i >= 0 ? num1[i] - '0' : 0;
      int n2 = j >= 0 ? num2[j] - '0' : 0;

      int sum = n1 + n2 + carry;
      ans.push_back(sum % 10 + '0');
      carry = sum / 10;
    }

    if (carry > 0) {
      ans.push_back(carry + '0');
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};