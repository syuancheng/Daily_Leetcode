#include <cstddef>
#include <vector>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  bool isPalindrome(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return true;
    }
    std::vector<int> vals;

    while (head) {
      vals.push_back(head->val);
      head = head->next;
    }

    int i = 0, j = vals.size() - 1;
    while (i < j) {
      if (vals[i] != vals[j]) {
        return false;
      }
      i++;
      j--;
    }
    return true;
  }

  bool isPalindrome2(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return true;
    }

    auto *fast = head, *slow = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    auto *h1 = head;

    auto *cur = slow->next;
    slow->next = nullptr;
    while (cur) {
      auto tmp = cur->next;
      cur->next = slow->next;
      slow->next = cur;
      cur = tmp;
    }

    auto *h2 = slow->next;

    while (h1 && h2) {
      if (h1->val != h2->val) {
        return false;
      }
      h1 = h1->next;
      h2 = h2->next;
    }

    return true;
  }
};