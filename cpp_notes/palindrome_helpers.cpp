#include <cstddef>
#include <string>

class PalindromeHelpers {
public:
  std::string expandAroundCenter(const std::string &s, int left, int right) {
    while (left >= 0 && right < static_cast<int>(s.size()) &&
           s[static_cast<size_t>(left)] == s[static_cast<size_t>(right)]) {
      left--;
      right++;
    }

    return s.substr(static_cast<std::size_t>(left + 1),
                    static_cast<std::size_t>(right - left - 1));
  }

  bool isPalindrome(const std::string &s) {
    int left = 0;
    int right = static_cast<int>(s.size()) - 1;

    while (left < right) {
      if (s[static_cast<size_t>(left)] != s[static_cast<size_t>(right)]) {
        return false;
      }
      left++;
      right--;
    }

    return true;
  }
};
