# Recursion Notes

## 1. What Recursion Is

Recursion means a function solves a problem by calling itself on smaller versions of the same problem.

Example:

You are sitting in a movie theater and want to know which row you are in. You do not know your own row number, so you ask the person in front of you. That person also asks the person in front, until the first row is reached. Then the answer is passed back row by row.

- The asking process is the recursive call.
- The passing-back process is the return.
- The first row is the base case.

For this example:

```text
f(n) = f(n - 1) + 1
f(1) = 1
```

`f(n)` means: the row number of the person sitting in row `n`.

## 2. When Recursion Works

A problem is suitable for recursion when it satisfies these conditions:

1. The original problem can be split into smaller subproblems.
2. The subproblems have the same structure as the original problem.
3. There is a clear base case that stops the recursion.

If any of these is missing, recursion is usually hard to write correctly or may never stop.

## 3. How To Write Recursive Code

Use this order:

1. Define the meaning of the function.
2. Write the base case.
3. Write the recursive relation.
4. Return the result from the smaller problem.

The most important step is defining the function meaning clearly.

Example:

```cpp
int depth(TreeNode* root)
```

Function meaning:

```text
Return the maximum depth of the tree rooted at root.
```

Once this meaning is clear, the recursive relation follows naturally:

```text
depth(root) = max(depth(root->left), depth(root->right)) + 1
depth(nullptr) = 0
```

Code:

```cpp
#include <algorithm>

int maxDepth(TreeNode* root) {
  if (root == nullptr) {
    return 0;
  }

  return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
```

## 4. Do Not Expand Every Call Manually

When writing recursion, do not try to simulate every function call in your head.

Instead, trust the function definition:

```text
If maxDepth(root) returns the maximum depth of root,
then maxDepth(root->left) returns the maximum depth of the left subtree,
and maxDepth(root->right) returns the maximum depth of the right subtree.
```

Then combine the two subproblem answers.

This is the core recursive thinking pattern:

```text
Assume the recursive function already works for smaller inputs.
Use those answers to solve the current input.
```

## 5. Binary Tree DFS Template

Binary tree recursion usually has this shape:

```cpp
ReturnType dfs(TreeNode* root) {
  if (root == nullptr) {
    return base_value;
  }

  ReturnType left = dfs(root->left);
  ReturnType right = dfs(root->right);

  return combine(root, left, right);
}
```

Common examples:

- Maximum depth: combine left and right depth with `max(left, right) + 1`.
- Minimum depth: handle missing children carefully, then combine.
- Path sum: pass the remaining target from parent to child.
- Validate BST: pass valid value ranges down the tree.

## 6. Top-Down vs Bottom-Up Recursion

There are two common recursion styles.

### Top-Down

Information is passed from parent to child.

Example: Path Sum.

```text
remaining = targetSum - root->val
```

Each child receives the remaining sum it still needs to match.

```cpp
bool hasPathSum(TreeNode* root, int targetSum) {
  if (root == nullptr) {
    return false;
  }

  if (root->left == nullptr && root->right == nullptr) {
    return root->val == targetSum;
  }

  int remaining = targetSum - root->val;
  return hasPathSum(root->left, remaining) ||
         hasPathSum(root->right, remaining);
}
```

### Bottom-Up

Children return answers to the parent.

Example: Maximum Depth.

```text
leftDepth = maxDepth(root->left)
rightDepth = maxDepth(root->right)
answer = max(leftDepth, rightDepth) + 1
```

Use bottom-up recursion when the parent needs information from its children.

## 7. Recursion vs Backtracking

Backtracking is a special kind of recursion.

Plain recursion usually returns one answer:

```text
What is the maximum depth?
Does this path exist?
How many nodes are there?
```

Backtracking usually searches all possible choices:

```text
Choose one option.
Go deeper.
Undo the choice.
Try the next option.
```

Backtracking template:

```cpp
void backtrack(State& state) {
  if (isTarget(state)) {
    saveAnswer(state);
    return;
  }

  for (Choice choice : choices) {
    makeChoice(state, choice);
    backtrack(state);
    undoChoice(state, choice);
  }
}
```

Key difference:

- Recursion focuses on subproblem answers.
- Backtracking focuses on exploring choices and restoring state.

## 8. Common Mistakes

- Missing base case: causes infinite recursion.
- Wrong base value: for example, returning `1` for an empty tree depth.
- Not shrinking the problem: the recursive call must move toward the base case.
- Mixing top-down and bottom-up state without a clear meaning.
- Forgetting to restore state in backtracking.
- Ignoring recursion stack space in complexity analysis.

## 9. Complexity

For recursion, time complexity usually depends on how many states or nodes are visited.

Examples:

- Binary tree DFS: O(n), because each node is visited once.
- Linked list recursion: O(n), because each node is visited once.
- Fibonacci without memoization: O(2^n), because many subproblems are repeated.

Space complexity includes the call stack.

Examples:

- Balanced binary tree recursion: O(log n) stack depth.
- Skewed binary tree recursion: O(n) stack depth.
- Linked list recursion: O(n) stack depth.

## 10. Review Summary

The original notes had the correct core idea:

- Recursion has a forward process and a return process.
- Recursive problems can be described by a recurrence relation.
- The key is finding the smaller subproblem and the base case.

The part that needed strengthening was the coding workflow. In practice, write recursion in this order:

```text
1. Define what the function returns.
2. Handle the base case.
3. Call the same function on smaller inputs.
4. Combine or pass down information.
```

The key sentence:

> Do not think through every recursive layer. Define the function meaning, trust the smaller subproblem, and combine its result.
