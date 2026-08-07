---
name: leetcode-review-prioritizer
description: Analyze Daily_Leetcode Markdown Practice Log entries to recommend the most valuable LeetCode problems to review next. Use when the user asks which LeetCode problems to revisit, wants weak-point analysis, wants review priorities based on duration, correctness result, recency, mastery, attempts, or asks to study from the project practice logs.
---

# LeetCode Review Prioritizer

## Quick Start

Use this skill inside a Daily_Leetcode-style repository where problem writeups live under `problems/**/lc*.md` and contain `## Mastery`, `## Practice Log`, and `## Link` sections.

Run the bundled analyzer from the repository root:

```bash
python3 .codex/skills/leetcode-review-prioritizer/scripts/analyze_practice_logs.py --root . --limit 12
```

Then give the user a concise Chinese recommendation list. Prioritize quality over quantity: usually return 6-12 problems unless the user asks for a broader report.

## Input Format

Expect each Markdown file to have one or more entries like:

```markdown
- Date: 2026-08-07
  Duration: 28m
  Result: 修改后做对
  Notes: 双指针去重边界没一次写对。
```

Supported result values are:

- `一次性做对`
- `修改后做对`
- `参考答案后做对`

Empty template entries should be ignored. Multiple `- Date:` blocks under the same `Practice Log` mean multiple attempts.

## Scoring Heuristics

Use the analyzer score as the starting point, then apply interview-prep judgment before answering.

Higher priority signals:

- Latest result is `参考答案后做对`
- Latest result is `修改后做对`
- Recent attempts still take a long time
- The problem has repeated non-ideal results
- The problem has no real practice log yet
- `Mastery` status is `Beginner` or `Familiar`
- The problem has not been practiced recently

Lower priority signals:

- Latest result is `一次性做对`
- Duration is short relative to typical interview constraints
- Several recent attempts are clean
- Mastery is already `Proficient`

For Alibaba-style written-test prep, bias toward core algorithm patterns: array/hash, two pointers, binary search, sliding window, linked list, DFS/BFS, backtracking, heap, and dynamic programming.

## Reporting Format

Answer in Chinese by default for this repository. Include:

1. `最值得复习` list with problem number/title/path/link when available.
2. The reason for each recommendation: result, duration, last practice date, mastery, and notes.
3. A short `复习顺序` grouped by urgency: today / next / optional.
4. Any parsing caveat, such as missing dates or empty logs.

Keep the list selective. Do not dump every problem unless requested.

## Manual Review Rules

When the script output looks thin because many logs are empty, combine it with `Mastery` and `Attempts`. Empty logs are not proof that a problem is weak, but they are useful reminders that there is no timing evidence yet.

If dates are missing, say so and rank primarily by result, duration, and mastery. If durations are missing, rank primarily by result, recency, notes, and mastery.

Do not modify problem files while using this skill unless the user explicitly asks to update records.
