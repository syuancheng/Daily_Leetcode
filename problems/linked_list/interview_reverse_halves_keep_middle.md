# Interview. Reverse Halves and Keep Middle

## Labels

- Linked List
- Two Pointers

## Mastery

- Attempts: OO
- Status: Proficient

## Link

Custom interview problem.

## Problem Description

Given the head of a singly linked list, reverse the left half and reverse the right half. If the list length is odd, keep the middle node in its original position between the two reversed halves.

The node values must not be changed; the list should be transformed by relinking nodes.

Examples:

```text
Input:  1 -> 2 -> 3 -> 4
Output: 2 -> 1 -> 4 -> 3
```

```text
Input:  1 -> 2 -> 3 -> 4 -> 5
Output: 2 -> 1 -> 3 -> 5 -> 4
```

```text
Input:  1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
Output: 3 -> 2 -> 1 -> 4 -> 7 -> 6 -> 5
```

## My Solution

```cpp
#include "../common/nodes.h"
#include <cstddef>
#include <iostream>
#include <vector>

ListNode *reverseList(ListNode *head) {
  ListNode *prev = nullptr;
  ListNode *cur = head;

  while (cur) {
    ListNode *next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }

  return prev;
}

ListNode *reverseHalvesKeepMiddle(ListNode *head) {
  if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
    return head;
  }

  int length = 0;
  for (ListNode *node = head; node != nullptr; node = node->next) {
    ++length;
  }

  int leftLength = length / 2;

  ListNode *cur = head;
  ListNode *pre = nullptr;
  for (int i = 0; i < leftLength; ++i) {
    pre = cur;
    cur = cur->next;
  }
  pre->next = nullptr;

  ListNode *left = head;

  ListNode *right = cur;
  ListNode *middle = nullptr;
  if (length % 2 == 1) {
    middle = cur;
    right = cur->next;
    middle->next = nullptr;
  }

  ListNode *newLeft = reverseList(left);
  ListNode *newRight = reverseList(right);

  ListNode *tail = newLeft;
  while (tail != nullptr && tail->next != nullptr) {
    tail = tail->next;
  }
  if (middle) {
    tail->next = middle;
    tail = middle;
  }
  tail->next = newRight;
  return newLeft;
}

ListNode *buildList(const std::vector<int> &nums) {
  ListNode dummy;
  ListNode *tail = &dummy;

  for (int num : nums) {
    tail->next = new ListNode(num);
    tail = tail->next;
  }

  return dummy.next;
}

std::vector<int> toVector(ListNode *head) {
  std::vector<int> result;

  while (head != nullptr) {
    result.push_back(head->val);
    head = head->next;
  }

  return result;
}

void printVector(const std::vector<int> &nums) {
  std::cout << "[";
  for (std::size_t i = 0; i < nums.size(); ++i) {
    if (i > 0) {
      std::cout << ", ";
    }
    std::cout << nums[i];
  }
  std::cout << "]";
}

void runTest(const std::vector<int> &input, const std::vector<int> &expected) {
  ListNode *head = buildList(input);
  std::vector<int> actual = toVector(reverseHalvesKeepMiddle(head));

  printVector(input);
  std::cout << " -> ";
  printVector(actual);
  std::cout << " expected ";
  printVector(expected);
  std::cout << (actual == expected ? " [OK]" : " [FAIL]") << '\n';
}

int main() {
  runTest({}, {});
  runTest({1}, {1});
  runTest({1, 2}, {1, 2});
  runTest({1, 2, 3}, {1, 2, 3});
  runTest({1, 2, 3, 4}, {2, 1, 4, 3});
  runTest({1, 2, 3, 4, 5}, {2, 1, 3, 5, 4});
  runTest({1, 2, 3, 4, 5, 6, 7}, {3, 2, 1, 4, 7, 6, 5});

  return 0;
}
```

## Complexity

- Time: O(n), where `n` is the number of nodes in the linked list.
- Space: O(1), using only a constant number of pointers outside the test helper code.
