# 2667. Create Hello World Function

## Labels

- JavaScript
- Closure

## Mastery

- Attempts: OO
- Status: Proficient

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
