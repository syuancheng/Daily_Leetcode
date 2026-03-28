struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *h = new ListNode(0);

    ListNode *k = new ListNode(0, head);

    ListNode *p = k, *tail, *q, *r = h;

    while (p != nullptr) {
      tail = p;
      q = p->next;
      if (q != nullptr) {
        if (q->val >= x) {
          p->next = q->next;
          r->next = q;
          r = q;
        } else {
          p = q;
        }

      } else {
        break;
      }
    }

    r->next = nullptr;
    tail->next = h->next;
    return k->next;
  }
};