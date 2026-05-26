# 2704. To Be Or Not To Be

## Labels

- JavaScript

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/to-be-or-not-to-be/

## Problem Description

Create an assertion helper with toBe and notToBe methods.

## My Solution

```javascript
/**
 * @param {string} val
 * @return {Object}
 */
var expect = function (val) {
  return {
    toBe: (m) => {
      if (m === val) {
        return true;
      } else {
        throw new Error('Not Equal');
      }
    },
    notToBe: (m) => {
      if (m !== val) {
        return true;
      } else {
        throw new Error('Equal');
      }
    },
  };
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */
```

## Complexity

- Time: O(1).
- Space: O(1).
