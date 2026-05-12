# 371. Sum of Two Integers

## Labels

- Bit Manipulation

## Link

https://leetcode.com/problems/sum-of-two-integers/

## Problem Description

Given two integers `a` and `b`, return their sum without using the `+` or `-` operators.

## My Solution

```cpp


/**
给你两个整数 a 和 b ，不使用 运算符 + 和
-​​​​​​​，计算并返回两整数之和。
*/

class Solution {
public:
  int getSum(int a, int b) {
    while (b != 0) {                          // 1. 只要进位不为 0，就继续循环
      int no_carry_sum = a ^ b;               // 2. 异或运算：计算“无进位和”
      int carry = (unsigned int)(a & b) << 1; // 3. 与运算后左移：计算“进位”

      a = no_carry_sum; // 4. 将无进位和赋值给 a，作为下一轮加数
      b = carry;        // 5. 将进位赋值给 b，作为下一轮加数
    }
    return a; // 6. 进位为 0 时，a 就是最终结果
  }
};
```

## Complexity

- Time: O(1), because integers have a fixed bit width.
- Space: O(1).
