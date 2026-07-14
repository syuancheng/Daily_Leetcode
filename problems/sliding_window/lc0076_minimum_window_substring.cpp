#include <climits>
#include <string>
#include <unordered_map>

using namespace std;

/**
76. 最小覆盖子串
*/

class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) {
      need[c]++;
    }

    int left = 0, right = 0, valid = 0;
    int start = 0, len = INT_MAX;

    while (right < s.size()) {
      char c = s[right];
      right++;
      if (need.count(c)) {
        window[c]++;
        if (need[c] == window[c]) {
          valid++;
        }
      }

      while (valid == need.size()) {
        //[0,2) len=2, {0, 1}
        if (right - left < len) {
          start = left;
          len = right - left;
        }

        char d = s[left];
        left++;
        if (need.count(d)) {
          if (need[d] == window[d]) {
            valid--;
          }
          window[d]--;
        }
      }
    }
    return len == INT_MAX ? "" : s.substr(start, len);
  }
};