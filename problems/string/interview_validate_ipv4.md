# Interview. Validate IPv4

## Labels

- String
- Simulation

## Mastery

- Attempts: HO
- Status: Proficient

## Problem Description

Validate whether a string is a legal IPv4 address:

- It must have exactly four dot-separated segments.
- Every segment must contain only digits.
- Segment values must be from `0` to `255`.
- Leading zeroes are not allowed unless the segment is exactly `"0"`.

## Review Notes

The scratch version had the right split-and-check structure, but
`isValidSegment` returned `true` for values outside the range. The final
condition should accept values `<= 255`.

## Complexity

- Time: O(n)
- Space: O(n), for the split segments
