#include <cstddef>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  vector<string> result;

  vector<string> track;

public:
  vector<string> restoreIpAddresses(string s) {
    backtrack(s, 0);
    return result;
  }

  void backtrack(string s, int start) {
    if (start == s.size() && track.size() == 4) {
      result.push_back(joinWithChar(track, '.'));
      return;
    }

    for (int i = start; i < s.size(); i++) {
      if (!isValidSegment(s, start, i)) {
        continue;
      }
      if (track.size() > 4) {
        continue;
      }

      track.push_back(s.substr(start, i - start + 1));
      backtrack(s, i + 1);
      track.pop_back();
    }
  }

  bool isValidSegment(const string &s, int start, int end) {
    int length = end - start + 1;
    if (length == 0 || length > 3) {
      return false;
    }

    if (length == 1) {
      // 如果只有一位数字，肯定是合法的
      return true;
    }

    if (s[start] == '0') {
      // 多于一位数字，但开头是 0，肯定不合法
      return false;
    }

    if (length <= 2) {
      // 排除了开头是 0 的情况，那么如果是两位数，怎么着都是合法的
      return true;
    }

    // 现在输入的一定是三位数
    if (stoi(s.substr(start, length)) > 255) {
      // 不可能大于 255
      return false;
    } else {
      return true;
    }
  }

  string joinWithChar(const vector<string> &parts, char delimiter) {
    string result;
    for (size_t i = 0; i < parts.size(); i++) {
      if (i > 0) {
        result.push_back(delimiter);
      }
      result += parts[i];
    }
    return result;
  }
};
