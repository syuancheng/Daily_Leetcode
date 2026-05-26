#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>
#include <cmath>

/**
3. 无重复字符的最长子串
*/

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    string tmp;

    int ans = 0;
    for (const char x : s) {
      int pos = tmp.find(x);
      if (pos != string::npos) {
        if (tmp.size() > ans) {
          ans = tmp.size();
        }
        tmp.erase(0, pos+1);
      }
      tmp.push_back(x);
    }

    if (tmp.size() > ans) {
      ans = tmp.size();
    }
    return ans;
  }

  int lengthOfLongestSubstringV2(string s) {
    unordered_set<char> ch_set;
    int n = s.size();
    int ans = 0;
    for (int l = 0, r = 0; r < n; r++) {
      const auto &ch = s.at(r);

      while (ch_set.count(ch) == 1) {
        ch_set.erase(s.at(l));
        l++;
      }

      ch_set.insert(ch);
      ans = max(ans, r - l +1);
    }

    return ans;
  }
};
