struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *insertionSortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *h = new ListNode(0, head);
    ListNode *p = h->next->next;
    h->next->next = nullptr;

    ListNode *q, *pre;
    while (p != nullptr) {
      q = p->next;
      pre = h;
      while (pre->next != nullptr && pre->next->val < p->val) {
        pre = pre->next;
      }
      p->next = pre->next;
      pre->next = p;

      p = q;
    }

    return h->next;
  }
};