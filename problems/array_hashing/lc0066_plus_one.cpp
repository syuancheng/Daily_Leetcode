#include <cstdlib>
#include <iostream>

int *plusOne(int *digits, int digitsSize, int *returnSize) {
  int cnt = 0;
  for (int i = 0; i < digitsSize; i++) {
    if (digits[i] == 9) {
      cnt++;
    }
  }

  if (cnt == digitsSize) {
    int *ans = (int *)malloc((digitsSize + 1) * sizeof(int));
    ans[0] = 1;
    for (int j = 1; j < digitsSize + 1; j++) {
      ans[j] = 0;
    }
    *returnSize = digitsSize + 1;
    return ans;
  } else {
    int *ans = (int *)malloc((digitsSize) * sizeof(int));
    int c = 0;
    for (int i = digitsSize - 1; i >= 0; i--) {
      if (i == digitsSize - 1) {
        ans[i] = digits[i] + 1;
        c = ans[i] / 10;
        ans[i] = ans[i] % 10;
      } else {
        ans[i] = digits[i] + c;
        c = ans[i] / 10;
        ans[i] = ans[i] % 10;
      }
    }
    *returnSize = digitsSize;
    return ans;
  }
}

int main() { return 0; }