struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    ListNode *dummy = new ListNode(0);

    ListNode* cur = head;

    while (cur) {
      auto tmp = cur->next;
      cur->next = dummy->next;
      dummy->next = cur;
      cur = tmp;
    }
    return dummy->next;
  }
};