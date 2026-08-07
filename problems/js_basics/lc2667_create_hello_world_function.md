# 2667. Create Hello World Function

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

https://leetcode.com/problems/create-hello-world-function/

## Problem Description

Create a function that always returns Hello World.

## My Solution

```javascript
/**
 * @return {Function}
 */
var createHelloWorld = function() {
    
    return function(...args) {
        return "Hello World"
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */
```

## Complexity

- Time: O(1).
- Space: O(1).
