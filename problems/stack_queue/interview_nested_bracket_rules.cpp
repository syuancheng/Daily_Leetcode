#include <stack>
#include <string>

using namespace std;

struct BracketInfo {
  char type = '\0';
  bool containsRound = false;
  bool containsSquare = false;
};

class Solution {
public:
  bool isValid(const string &s) {
    stack<BracketInfo> st;

    for (char c : s) {
      if (c == '(' || c == '[' || c == '{') {
        st.push({c});
        continue;
      }

      if (c != ')' && c != ']' && c != '}') {
        return false;
      }

      if (st.empty()) {
        return false;
      }

      BracketInfo current = st.top();
      st.pop();

      bool matched = (current.type == '(' && c == ')') ||
                     (current.type == '[' && c == ']') ||
                     (current.type == '{' && c == '}');
      if (!matched) {
        return false;
      }

      if (current.type == '[' && !current.containsRound) {
        return false;
      }
      if (current.type == '{' && !current.containsSquare) {
        return false;
      }

      if (!st.empty()) {
        if (current.type == '(') {
          st.top().containsRound = true;
        } else if (current.type == '[') {
          st.top().containsSquare = true;
        }
      }
    }

    return st.empty();
  }
};
