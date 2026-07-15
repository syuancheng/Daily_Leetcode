#include <cstddef>
#include <string>
#include <vector>

class StringHelpers {
public:
  // Similar to Go strings.Split for a non-empty separator:
  // - split("a,b,c", ",") -> {"a", "b", "c"}
  // - split("a,,b", ",") -> {"a", "", "b"}
  // - split("", ",") -> {""}
  // - split("abc", "x") -> {"abc"}
  std::vector<std::string> split(const std::string &s,
                                 const std::string &separator) {
    std::vector<std::string> result;

    if (separator.empty()) {
      for (char c : s) {
        result.push_back(std::string(1, c));
      }
      return result;
    }

    size_t start = 0;
    while (true) {
      size_t pos = s.find(separator, start);
      if (pos == std::string::npos) {
        result.push_back(s.substr(start));
        break;
      }

      result.push_back(s.substr(start, pos - start));
      start = pos + separator.size();
    }

    return result;
  }

  std::vector<std::string> split(const std::string &s, char separator) {
    return split(s, std::string(1, separator));
  }
};
