# Interview. Nested Bracket Rules

## Labels

- Stack
- String
- Simulation

## Mastery

- Attempts: HO
- Status: Proficient

## Problem Description

Validate a bracket string with extra nesting rules:

- `()` is valid by itself.
- `[]` must contain at least one completed `()`.
- `{}` must contain at least one completed `[]`.
- Brackets must still be normally balanced and matched.

Examples:

```text
()        -> true
[]        -> false
[()]      -> true
{}        -> false
{[]}      -> false
{[()]}    -> true
{[()]()}  -> true
```

## My Solution

Use a stack of `BracketInfo`. Each stack frame records its bracket type and
whether the content already contains a completed child `()` or `[]`. When a pair
closes, validate its own rule, then propagate its completed type to the parent.

## Complexity

- Time: O(n)
- Space: O(n)
