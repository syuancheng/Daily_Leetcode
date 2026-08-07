# 127. Word Ladder

## Labels

- BFS
- Hash Table
- String

## Mastery

- Attempts: OO
- Status: Proficient

## Practice Log

Result options: `一次性做对` / `修改后做对` / `参考答案后做对`.

- Date:
  Duration:
  Result:
  Notes:

## Link

https://leetcode.com/problems/word-ladder/

## Problem Description

Return the length of the shortest transformation sequence from beginWord to endWord.

## My Solution

```cpp
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> word_set = {wordList.begin(), wordList.end()};
    if (word_set.count(endWord) == 0) {
      return 0;
    }
    queue<string> q;
    unordered_set<string> visited;
    q.push(beginWord);
    visited.insert(beginWord);
    int steps = 1;

    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        string word = q.front();
        q.pop();

        if (word == endWord) {
          return steps;
        }

        for (int j = 0; j < word.size(); j++) {
          char original = word[j];

          for (char c = 'a'; c <= 'z'; c++) {
            word[j] = c;
            if (word_set.count(word) && !visited.count(word)) {
              q.push(word);
              visited.insert(word);
            }
          }
          word[j] = original;
        }
      }
      steps++;
    }

    return 0;
  }
};
```

## Complexity

- Time: O(n * L^2).
- Space: O(n * L^2).
