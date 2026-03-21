struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *oddEvenList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *h = new ListNode(0);

    ListNode *r = h, *pre = head, *ou = head->next, *tail, *q;

    while (ou != nullptr) {
      q = ou->next;
      if (q == nullptr) {
        tail = pre;
        r->next = ou;
        r = r->next;
        pre->next = nullptr;
        continue;
      }
      r->next = ou;
      r = r->next;
      ou->next = nullptr;

      pre->next = q;

      ou = q->next;
      pre = q;
      tail = q;
    }

    tail->next = h->next;

    return head;
  }
};