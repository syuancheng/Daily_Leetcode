#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string a, b;

  int dfs(int i, int j) {
    // a 的前 i 个字符 -> b 的前 j 个字符

    if (i == 0)
      return j; // 空串变成 b[0..j-1]，插入 j 次
    if (j == 0)
      return i; // a[0..i-1] 变成空串，删除 i 次

    if (a[i - 1] == b[j - 1]) {
      return dfs(i - 1, j - 1);
    }

    int insertOp = dfs(i, j - 1) + 1;
    int deleteOp = dfs(i - 1, j) + 1;
    int replaceOp = dfs(i - 1, j - 1) + 1;

    return min({insertOp, deleteOp, replaceOp});
  }

  int minDistance(string word1, string word2) {
    a = word1;
    b = word2;

    return dfs(a.size(), b.size());
  }
};

int main() {
  string s1 = "horse";
  string s2 = "ros";

  Solution s;

  cout << s.minDistance(s1, s2) << endl;
}