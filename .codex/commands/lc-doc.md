---
description: Generate a LeetCode Markdown writeup from a C++ solution file path.
argument-hint: <path-to-cpp>
---

Generate or update an English Markdown LeetCode writeup for this C++ solution file:

```text
$ARGUMENTS
```

Workflow:

1. Treat `$ARGUMENTS` as the solution file path.
   - It should be a `.cpp` file.
   - If the path is missing or ambiguous, ask one concise clarification.
   - Infer the LeetCode problem number from the filename, such as `lc0199_right_side_view.cpp`.

2. Gather problem facts.
   - Use the canonical LeetCode link: `https://leetcode.com/problems/<slug>/`.
   - If the slug/title/problem facts are not known from local context, verify them before writing.
   - Do not invent constraints, examples, or problem text. If exact public details are unavailable, write a concise paraphrase based on verified or clearly inferable facts.

3. Analyze the solution only enough to determine labels and complexity.
   - Do not add a review section.
   - If the implementation is obviously incomplete or wrong, do not generate a solved writeup. Instead, tell the user it appears unfinished and leave the `.cpp` as in progress.

4. Create or update the Markdown file next to the solution.
   - For `path/to/lc0199_right_side_view.cpp`, write `path/to/lc0199_right_side_view.md`.
   - Preserve the exact original source code in the Markdown `My Solution` section before modifying the `.cpp` file.
   - Preserve existing user-authored Markdown outside the generated writeup sections when updating.

5. Reset the original `.cpp` source file for future practice.
   - This is required by default after the Markdown writeup captures the answer.
   - Preserve includes, helper type definitions, class names, method signatures, and required LeetCode boilerplate.
   - Remove the algorithm implementation and helper logic that reveals the answer.
   - Make the file look like an unsolved LeetCode starter template whenever possible.
   - Prefer an empty function body for C++ LeetCode methods, even if the local file will not compile until solved again.
   - Keep only includes needed by the starter signature and visible LeetCode types.
   - If resetting safely is ambiguous, ask before editing the source file.

6. If the file is under `problems/<topic>/`, update `README.md`.
   - Add the problem under the matching topic section.
   - Keep the line format consistent with existing entries:
     `- [<number>. <title>](path/to/file.md) - [<source>.cpp](path/to/file.cpp)`
   - Verify README links exist after editing.

Markdown format:

````markdown
# <Problem Number>. <Problem Title>

## Labels

- <Primary topic label>
- <Additional topic label>

## Mastery

- Attempts: OO
- Status: Proficient

## Link

https://leetcode.com/problems/<slug>/

## Problem Description

<concise problem statement in your own words, including inputs, output, key constraints, and one important example if verified>

## My Solution

```cpp
<exact contents of the user's C++ solution file>
```

## Complexity

- Time: O(...)
- Space: O(...)
````

Quality bar:

- Use clear, natural English.
- Include labels such as `Array`, `Hash Table`, `Two Pointers`, `Binary Search`, `Dynamic Programming`, `Linked List`, `Tree`, `Graph`, `BFS`, `DFS`, `Backtracking`, `Stack`, `Queue`, `Heap`, `Greedy`, or `Sliding Window`.
- The Markdown must contain the complete original solution before the `.cpp` file is reset.
- Include only the sections above unless the user explicitly asks for review or corrected code.
- Keep edits limited to the Markdown writeup, README index, and resetting the requested `.cpp` file.
