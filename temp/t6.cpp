#include <string>

class Soultion {
public:
  //寻找回文串的核心思想是从中心向两端扩展.
  std::string palindrome(std::string s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
      left--;
      right++;
    }
    return s.substr(left + 1, right - left - 1);
  };

  //判断一个字符串是不是回文串就简单很多，不需要考虑奇偶情况，只需要双指针技巧，从两端向中间逼近即可
  bool isPalindrome(std::string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
      if (s[left] != s[right]) {
        return false;
      }
      left++;
      right--;
    }
    return true;
  }

  
};