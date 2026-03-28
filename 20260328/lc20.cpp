#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> sk;
    for (char &c : s) {
      if (c == ')' && !sk.empty()) {
        if (sk.top() != '(') {
          return false;
        }
        sk.pop();
      } else if (c == ']' && !sk.empty()) {
        if (sk.top() != '[') {
          return false;
        }
        sk.pop();
      } else if (c == '}' && !sk.empty()) {
        if (sk.top() != '{') {
          return false;
        }
        sk.pop();
      } else {
        sk.push(c);
      }
    }

    if (!sk.empty()) {
      return false;
    }
    return true;
  }
};