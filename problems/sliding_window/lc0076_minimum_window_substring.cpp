#include <climits>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
76. 最小覆盖子串
*/

class Solution {
public:
  bool check(vector<int> &flag, vector<int> &test) {
    if (flag.size() != test.size()) {
      return false;
    }

    for (int i = 0; i < flag.size(); i++) {
      if (test[i] < flag[i]) {
        return false;
      }
    }
    return true;
  }

  // s = abc, t=a

  string minWindow(string s, string t) {
    vector<int> s_cnt(128), t_cnt(128);

    for (const auto &e : t) {
      t_cnt[e]++;
    }

    int len = INT_MAX, ansL = -1;
    for (int l = 0, r = 0; r < s.size(); r++) {
      auto &ch = s[r];
      s_cnt[ch]++;

      while (check(t_cnt, s_cnt) && l <= r) {
        if (r - l + 1 < len) {
          len = r - l + 1;
          ansL = l;
        }
        s_cnt[s[l]]--;
        l++;
      }
    }
    return ansL == -1 ? string() : s.substr(ansL, len);
  }
};