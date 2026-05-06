

/**
给你一个字符串 s，请你将 s 分割成一些 子串，使每个子串都是 回文串 。返回 s
所有可能的分割方案。

示例 1：
输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]

示例 2：
输入：s = "a"
输出：[["a"]]
提示：
1 <= s.length <= 16
s 仅由小写英文字母组成
*/

/**
abbab
*/
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  vector<vector<string>> result;
  vector<string> path;
  vector<vector<bool>> isPalindrome;

  void backtracking(const string &s, int startIndex) {
    // 如果起始位置大于等于字符串长度，说明找到了一组方案
    if (startIndex >= s.size()) {
      result.push_back(path);
      return;
    }

    for (int i = startIndex; i < s.size(); i++) {
      // 使用预处理好的 DP 数组判断回文
      if (isPalindrome[startIndex][i]) {
        string str = s.substr(startIndex, i - startIndex + 1);
        path.push_back(str);
        backtracking(s, i + 1); // 递归寻找剩余子串
        path.pop_back();        // 回溯，撤销处理结果
      }
    }
  }

public:
  vector<vector<string>> partition(string s) {
    int n = s.size();
    // 1. 预处理回文状态 DP 数组
    isPalindrome.assign(n, vector<bool>(n, false));
    for (int j = 0; j < n; j++) {
      for (int i = 0; i <= j; i++) {
        if (s[i] == s[j] && (j - i <= 2 || isPalindrome[i + 1][j - 1])) {
          isPalindrome[i][j] = true;
        }
      }
    }

    backtracking(s, 0);
    return result;
  }
};


void backTracking() {
  if (/**终止条件 */) {
    // 收集结果
    return;
  }
  // 单层搜索逻辑
  for (/**集合里的每一个元素，也可以是叶子节点的个数 */) {
    // 处理节点
    // 递归函数
    // 回溯操作，撤销梳理节点的情况
  }
  return;
}