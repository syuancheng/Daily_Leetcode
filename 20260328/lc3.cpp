#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>
#include "math.h"

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

    int res = 0;
    for (int left = 0, right = 0; right < n; right++) {
      auto& ch = s.at(right);
      while (ch_set.count(ch) == 1) {
        ch_set.erase(s.at(left));
        left++;
      }
      ch_set.insert(ch);
      res = max(res, right-left+1);
    }
    return res;
  }
};