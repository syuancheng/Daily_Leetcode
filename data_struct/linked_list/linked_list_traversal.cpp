#include "../../problems/common/nodes.h"
#include <vector>

void traverse(ListNode *head) {
  std::vector<int> result;
  for (ListNode *cur = head; cur != nullptr; cur = cur->next) {
    result.push_back(cur->val);
  }
}
