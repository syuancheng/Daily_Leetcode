struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    int count = 0;

    auto *tmp = head;
    while (tmp != nullptr) {
      count++;
      tmp = tmp->next;
    }

    int midIdx = count / 2 + 1;

    ListNode *h = new ListNode(0, head);

    auto *pre = h, *p = head;

    int i = 1;
    while (p != nullptr) {
      if (i == midIdx) {
        break;
      } else {
        pre = p;
        p = p->next;
      }
      i++;
    }

    return p;
  }
};