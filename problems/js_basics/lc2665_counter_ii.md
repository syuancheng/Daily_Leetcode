# 2665. Counter II

## Labels

- JavaScript
- Closure

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/counter-ii/

## Problem Description

Create a counter object with increment, decrement, and reset methods.

## My Solution

```javascript
/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function (init) {
  let createCount = init;
  return {
    increment: () => ++createCount,
    reset:  () => {
      createCount = init;
      return createCount;
    },
    decrement:  function() {
      return --createCount;
    },
  };
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
```

## Complexity

- Time: O(1).
- Space: O(1).
