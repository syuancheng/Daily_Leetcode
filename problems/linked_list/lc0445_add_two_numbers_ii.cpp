#include "../common/nodes.h"
#include <stack>

using namespace std;

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    stack<int> digits1;
    stack<int> digits2;

    while (l1 != nullptr) {
      digits1.push(l1->val);
      l1 = l1->next;
    }
    while (l2 != nullptr) {
      digits2.push(l2->val);
      l2 = l2->next;
    }

    int carry = 0;
    ListNode *head = nullptr;

    while (!digits1.empty() || !digits2.empty() || carry > 0) {
      int sum = carry;
      if (!digits1.empty()) {
        sum += digits1.top();
        digits1.pop();
      }
      if (!digits2.empty()) {
        sum += digits2.top();
        digits2.pop();
      }

      carry = sum / 10;
      head = new ListNode(sum % 10, head);
    }

    return head;
  }
};
