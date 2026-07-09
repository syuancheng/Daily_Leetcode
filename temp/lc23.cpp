#include "../problems/common/nodes.h"
#include <cstddef>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty()) {
      return nullptr;
    }
    ListNode *dummy = new ListNode(-1);
    ListNode *p = dummy;

    auto cmp = [](ListNode *a, ListNode *b) { return a->val > b->val; };
    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);

    for (const auto &head : lists) {
      if (head != nullptr) {
        pq.push(head);
      }
    }

    while (!pq.empty()) {
      ListNode *node = pq.top();
      pq.pop();

      p->next = node;
      if (node->next != nullptr) {
        pq.push(node->next);
      }
      p = p->next;
    }

    return dummy->next;
  }
};