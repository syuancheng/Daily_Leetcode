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
    if (l2 < l1) {
      return false;
    }

    vector<int> s1_count(26);
    vector<int> s2_count(26);

    for (int i = 0; i < l1; i++) {
      s1_count[s1[i] - 'a']++;
      s2_count[s2[i] - 'a']++;
    }

    if (s1_count == s2_count) {
      return true;
    }

    for (int i = 0; i < l2 - l1; i++) {
      s2_count[s2[i] - 'a']--;
      s2_count[s2[i + l1] - 'a']++;

      if (s1_count == s2_count) {
        return true;
      }
    }
    return false;
  }
};