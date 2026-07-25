#include <string>
#include <vector>

using namespace std;

class BinaryNumberGenerator {
public:
  vector<string> generate(int n) {
    result.clear();
    path.clear();
    backtrack(n, 0);
    return result;
  }

private:
  vector<string> result;
  string path;

  void backtrack(int n, int index) {
    if (index == n) {
      result.push_back(path);
      return;
    }

    for (char digit : {'0', '1'}) {
      path.push_back(digit);
      backtrack(n, index + 1);
      path.pop_back();
    }
  }
};
