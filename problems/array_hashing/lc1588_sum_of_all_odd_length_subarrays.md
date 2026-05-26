# 1588. Sum of All Odd Length Subarrays

## Labels

- Array
- Prefix Sum
- Math

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/sum-of-all-odd-length-subarrays/

## Problem Description

Return the sum of all odd-length subarrays.

## My Solution

```cpp
#include <iostream>
#include <vector>


//O(n3)
int sumOddLengthSubarrays(std::vector<int> &arr) {

  int sum = 0;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = i; j < arr.size(); j++) {
      if ((j - i + 1) % 2 == 1) {
        for (int k = i; k <= j; k++) {
          sum += arr[k];
        }
      }
    }
  }
  return sum;
}

int sumOddLengthSubarraysV2(std::vector<int> &arr) {

  int sum = 0, tmp;
  for (int i = 0; i < arr.size(); i++) {
    tmp = 0;
    for (int j = i; j < arr.size(); j++) {
      tmp += arr[j];
      if ((j-i+1)%2 == 1) {
        sum += tmp;
      }
    }
  }
  return sum;
}

int main() {
  std::vector<int> test = {1, 4, 2, 5, 3};
  auto res = sumOddLengthSubarrays(test);

  std::cout << "res: " << res << std::endl;
}
```

## Complexity

- Time: O(n^2).
- Space: O(1).
