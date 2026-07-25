#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool validateIpV4(const string &ip) {
    vector<string> segments = splitByDot(ip);
    if (segments.size() != 4) {
      return false;
    }

    for (const string &segment : segments) {
      if (!isValidSegment(segment)) {
        return false;
      }
    }
    return true;
  }

private:
  vector<string> splitByDot(const string &str) {
    vector<string> result;
    size_t start = 0;

    while (true) {
      size_t pos = str.find('.', start);
      if (pos == string::npos) {
        result.push_back(str.substr(start));
        break;
      }

      result.push_back(str.substr(start, pos - start));
      start = pos + 1;
    }

    return result;
  }

  bool isValidSegment(const string &segment) {
    if (segment.empty() || segment.size() > 3) {
      return false;
    }
    if (segment.size() > 1 && segment[0] == '0') {
      return false;
    }

    int value = 0;
    for (char c : segment) {
      if (c < '0' || c > '9') {
        return false;
      }
      value = value * 10 + (c - '0');
    }

    return value <= 255;
  }
};
