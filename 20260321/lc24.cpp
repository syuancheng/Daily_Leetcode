struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *h = new ListNode(0, head);

    ListNode *r = h, *p = head, *q;

    while (p != nullptr) {
      q = p->next;
      if (q != nullptr) {
        p->next = q->next;
        q->next = p;
        r->next = q;
        r = p;
        p = p->next;
      } else {
        break;
      }
    }

    return h->next;
  }
};