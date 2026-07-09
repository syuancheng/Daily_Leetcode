#include "../problems/common/nodes.h"
#include <cstddef>

using namespace std;

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *dummyUniq = new ListNode(101);
    ListNode *dummyDedup = new ListNode(101);

    ListNode *pUniq = dummyUniq, *pDedup = dummyDedup;

    ListNode *cur = head;

    while (cur != nullptr) {
      if ((cur->next != nullptr && cur->val == cur->next->val) ||
          (cur->val == pDedup->val)) {
        pDedup->next = cur;
        pDedup = pDedup->next;
      } else {
        pUniq->next = cur;
        pUniq = pUniq->next;
      }
      cur = cur->next;

      pUniq->next = nullptr;

      pDedup->next = nullptr;
    }

    return dummyUniq->next;
  }
};

class Solution2 {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *dummy = new ListNode(-1);

    ListNode *p = dummy;
    ListNode *cur = head;

    while (cur != nullptr) {
      if (cur->next != nullptr && cur->val == cur->next->val) {
        while (cur->next != nullptr && cur->val == cur->next->val) {
          cur = cur->next;
        }
        cur = cur->next;
        if (cur == nullptr) {
          cur->next = nullptr;
        }
      } else {
        p->next = cur;
        p = p->next;
        cur = cur->next;
      }
    }
    return dummy->next;
  }
};