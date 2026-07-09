#include "../common/nodes.h"
#include <cstddef>
#include <unordered_set>

using namespace std;

/**
160. 相交链表

*/

class Solution {
public:
  // get size
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *l1 = headA, *l2 = headB;

    while (l1 != l2) {
      l1 = (l1 == nullptr) ? headB : l1->next;
      l2 = (l2 == nullptr) ? headA : l2->next;
    }
    return l1;
  }
};