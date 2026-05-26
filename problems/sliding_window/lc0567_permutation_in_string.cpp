#include <string>
#include <vector>

using namespace std;

/**
567. 字符串的排列
*/

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    int l1 = s1.size(), l2 = s2.size();
    if (l2 < l1) { // s2 include s1
      return false;
    }

    int count[26] = {0};

    for (int i = 0; i < l1; i++) {
      count[s2[i] - 'a']++;
      count[s1[i] - 'a']--;
    }

    int diff = 0;
    for (int i = 0; i < 26; i++) {
      if (count[i] != 0) {
        diff++;
      }
    }

    if (diff == 0) {
      return true;
    }

    for (int i = 0; i < l2 - l1; i++) {
      int l = s2[i] - 'a';
      if (count[l] == 1) {
        diff--;
      } else if (count[l] == 0) {
        diff++;
      }
      count[l]--;

      int r = s2[i + l1] - 'a';
      if (count[r] == -1) {
        diff--;
      } else if (count[r] == 0) {
        diff++;
      }
      count[r]++;

      if (diff == 0) {
        return true;
      }
    }
    return false;
  }
};