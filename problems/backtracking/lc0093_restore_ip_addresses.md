# 93. Restore IP Addresses

## Labels

- String
- Backtracking
- DFS

## Link

https://leetcode.com/problems/restore-ip-addresses/

## Problem Description

Given a string `s` containing only digits, return all possible valid IPv4 addresses that can be formed by inserting three dots into `s`.

A valid IPv4 address has exactly four decimal parts. Each part must be between `0` and `255`, inclusive, and must not contain leading zeroes unless the part is exactly `"0"`.

Examples:

```text
Input: s = "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
```

```text
Input: s = "0000"
Output: ["0.0.0.0"]
```

```text
Input: s = "101023"
Output: ["1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3"]
```

## Notes

- You need to split the string into exactly four parts.
- Each part length can only be `1`, `2`, or `3`.
- A part like `"01"` or `"001"` is invalid.
- A part greater than `255` is invalid.
