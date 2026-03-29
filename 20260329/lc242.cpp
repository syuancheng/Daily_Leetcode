#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }
    vector<int> nums(26, 0);
    for (auto &ch : s) {
      nums[ch - 'a']++;
    }

    for (auto &ch : t) {
      nums[ch - 'a']--;
      if (nums[ch - 'a'] < 0) {
        return false;
      }
    }
    return true;
  }
};