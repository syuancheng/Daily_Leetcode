---
name: leetcode-solution-doc
description: Create English Markdown documentation for a specified LeetCode algorithm problem in the Daily_Leetcode repository. Use when the user asks to document a LeetCode problem, generate a problem writeup, include the problem link, labels, statement, solution code, and time/space complexity in a Markdown file.
---

# LeetCode Solution Doc

## Workflow

1. Identify the requested LeetCode problem and the user's solution file.
   - Prefer a direct file path or problem number from the user.
   - If only a problem number is provided, search the repository with `rg --files | rg '(^|/)lc?<number>(_|\\.|$)|(^|/)<number>\\.'`.
   - If multiple plausible files exist, use the one closest to the user's requested topic or ask a concise clarification.

2. Gather problem facts.
   - Include the canonical LeetCode link: `https://leetcode.com/problems/<slug>/`.
   - If the slug or statement is not known from local context, browse or otherwise verify it before writing.
   - Do not invent constraints, examples, or problem text. If the exact public statement cannot be accessed, write a concise, clearly labeled paraphrase based on verified information.

3. Analyze the user's solution only enough to determine time and space complexity.
   - Do not include a written `Solution Review` section in the Markdown file.
   - Do not include correctness notes, style suggestions, or improvement comments unless the user explicitly asks for review.
   - If the implementation appears obviously wrong, briefly tell the user in the final response, but keep the Markdown format focused on the requested sections.

4. Create or update a Markdown file near the solution unless the user specifies another path.
   - For `path/to/lc1_two_sum.cpp`, prefer `path/to/lc1_two_sum.md`.
   - For `path/to/lc1.cpp`, prefer `path/to/lc1.md`.
   - Preserve existing user-authored content if updating; replace only sections that clearly belong to this generated writeup.

5. Reset the original solution file for future practice after the Markdown document has captured the answer.
   - Preserve includes, type definitions, class names, method signatures, and any required LeetCode boilerplate.
   - Remove the algorithm implementation and helper logic that reveals the answer.
   - Make the file look like the unsolved LeetCode starter template for that problem whenever possible.
   - Prefer an empty function body for C++ LeetCode methods, even if that means the local file would not compile until the user solves it again.
   - Keep only the includes that are needed for the starter signature and visible LeetCode types.
   - Do not clear the solution file if the user explicitly asks to keep the code.
   - If clearing safely is ambiguous, ask before editing the source file.

## Markdown Format

Write the document in English with this structure:

````markdown
# <Problem Number>. <Problem Title>

## Labels

- <Primary topic label>
- <Additional topic label>

## Mastery

- Attempts: <sequence of X/O attempts, e.g. XX, XO, OO>
- Status: <Beginner | Familiar | Proficient>

## Link

<canonical LeetCode URL>

## Problem Description

<concise problem statement in your own words, including inputs, output, key constraints, and any important examples if verified>

## My Solution

```<language>
<user's solution code>
```

## Complexity

- Time: O(...)
- Space: O(...)
```
````

Adapt headings only when the user asks for a different format.

## Quality Bar

- Use clear, natural English.
- Prefer concise problem descriptions over copying a long copyrighted statement verbatim.
- Include a `Labels` section with the problem's algorithm/data-structure topics, such as `Array`, `Hash Table`, `Two Pointers`, `Binary Search`, `Dynamic Programming`, `Linked List`, `Tree`, `Graph`, `BFS`, `DFS`, `Backtracking`, `Stack`, `Queue`, `Heap`, `Greedy`, or `Sliding Window`.
- Include a `Mastery` section after `Labels`. In `Attempts`, `X` means the attempt was incorrect and `O` means the attempt was fully correct. Use only these `Status` values: `Beginner`, `Familiar`, or `Proficient`.
- Preserve the user's code exactly in the Markdown `My Solution` section before clearing the source file.
- Include only time and space complexity after `My Solution`, unless the user explicitly asks for review or corrected code.
