# 127. Word Ladder

## Labels

- Hash Table
- String
- BFS

## Mastery

- Mastery: Needs Review (不熟练)

## Link

https://leetcode.com/problems/word-ladder/

## Problem Description

Given `beginWord`, `endWord`, and a word list, return the length of the shortest transformation sequence from `beginWord` to `endWord`. Each step changes exactly one letter, every intermediate word must be in the word list, and the final word must be `endWord`. Return `0` if no such sequence exists.

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

- Time: O(n * m * 26), where `n` is the number of words and `m` is the word length.
- Space: O(n * m), for the word set, visited set, and queue.
