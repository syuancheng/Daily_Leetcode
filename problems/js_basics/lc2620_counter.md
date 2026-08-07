# 2620. Counter

## Labels

- JavaScript
- Closure

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

https://leetcode.com/problems/counter/

## Problem Description

Create a function that returns incrementing values starting from n.

## My Solution

```javascript
/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    
    return function() {
      return n++;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */
```

## Complexity

- Time: O(1).
- Space: O(1).
