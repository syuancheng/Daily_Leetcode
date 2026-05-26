#include <string>
#include <unordered_set>
#include <vector>

/**
438. 找到字符串中所有字母异位词
*/

using namespace std;

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    int s_len = s.size(), p_len = p.size();
    if (s_len < p_len) {
      return {};
    }

    vector<int> ans;
    vector<int> s_count(26);
    vector<int> p_count(26);

    for (int i = 0; i < p_len; i++) {
      s_count[s[i] - 'a']++;
      p_count[p[i] - 'a']++;
    }

    if (s_count == p_count) {
      ans.push_back(0);
    }

    for (int i = 0; i < s_len - p_len; i++) {
      s_count[s[i] - 'a']--;
      s_count[s[i + p_len] - 'a']++;

      if (s_count == p_count) {
        ans.push_back(i+1);
      }
    }
    return ans;
  }
};