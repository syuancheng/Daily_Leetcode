#include "../problems/common/nodes.h"
#include <cstddef>
#include <stack>

using namespace std;

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

    ListNode *dummy = new ListNode(-1);

    stack<ListNode *> sk1;
    while (l1 != nullptr) {
      sk1.push(l1);
      l1 = l1->next;
    }

    stack<ListNode *> sk2;
    while (l2 != nullptr) {
      sk2.push(l2);
      l2 = l2->next;
    }

    int carry = 0;
    while (!sk1.empty() || !sk2.empty() || carry > 0) {
      int sum = carry;

      if (!sk1.empty()) {
        ListNode *node = sk1.top();
        sum += node->val;
        sk1.pop();
      }

      if (!sk2.empty()) {
        ListNode *node = sk2.top();
        sum += node->val;
        sk2.pop();
      }

      carry = sum / 10;

      sum = sum % 10;
      ListNode *tmp = new ListNode(sum );

      tmp->next = dummy->next;
      dummy->next = tmp;
    }
    
    return dummy->next;
  }
};